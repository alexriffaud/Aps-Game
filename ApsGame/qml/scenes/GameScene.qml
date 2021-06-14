import Felgo 3.0
import QtQuick 2.0
import "../game"
import "../common"
import "../entities"

SceneBase {
    opacity: 0
    id: gameScene
    gridSize: 32

    property int offsetBeforeScrollingStarts: 240
    property int score: 0
    property bool gameIsRunning: false
    property alias entityContainer: level

    signal menuPressed()
    signal networkPressed()
    signal useCoinsPressed()

    EntityManager {
        id: entityManager
        entityContainer: gameScene

    }

    MultiResolutionImage {
         height: Screen.desktopAvailableHeight
         width: Screen.desktopAvailableWidth
        id: bg
        source: "../../assets/img/bg.png"
    }

    ParallaxScrollingBackground {
        sourceImage: "../../assets/img/background/layer2.png"
        anchors.bottom: gameScene.gameWindowAnchorItem.bottom
        anchors.horizontalCenter: gameScene.gameWindowAnchorItem.horizontalCenter
        // we move the parallax layers at the same speed as the player
        movementVelocity: player.x > offsetBeforeScrollingStarts ? Qt.point(-player.horizontalVelocity,0) : Qt.point(0,0)
        // the speed then gets multiplied by this ratio to create the parallax effect
        ratio: Qt.point(0.3,0)
    }
    ParallaxScrollingBackground {
        sourceImage: "../../assets/img/background/layer1.png"
        anchors.bottom: gameScene.gameWindowAnchorItem.bottom
        anchors.horizontalCenter: gameScene.gameWindowAnchorItem.horizontalCenter
        movementVelocity: player.x > offsetBeforeScrollingStarts ? Qt.point(-player.horizontalVelocity,0) : Qt.point(0,0)
        ratio: Qt.point(0.6,0)
    }

    Item {
        id: viewPort
        height: level.height
        width: level.width
        anchors.bottom: gameScene.gameWindowAnchorItem.bottom
        x: player.x > offsetBeforeScrollingStarts ? offsetBeforeScrollingStarts-player.x : 0

        PhysicsWorld {
            id: physicsWorld
            gravity: Qt.point(0, 25)
            debugDrawVisible: false // enable this for physics debugging
            z: 1000

            onPreSolve: {
                var entityA = contact.fixtureA.getBody().target
                var entityB = contact.fixtureB.getBody().target
                if(entityB.entityType === "platform" && entityA.entityType === "player" &&
                        entityA.y + entityA.height > entityB.y) {
                    contact.enabled = false
                }
            }
        }

        Level {
            id: level
        }

        Player {
            id: player
            x: 20
            y: 100
        }

        ResetSensor {
            width: player.width
            height: 10
            x: player.x
            anchors.bottom: viewPort.bottom

            onContact: {
                player.x = 20
                player.y = 100
                if(gameScene.state === "gameOver")
                    return
                coins+=score
                gameScene.state = "gameOver"
                audioManager.play(audioManager.idDIE)
                audioManager.play(audioManager.idHIT)
            }
//            Rectangle {
//                anchors.fill: parent
//                color: Style.yellowColor
//                opacity: 0.5
//            }
        }
    }

    WaitScreen {
        id: waitToPlay
        z : 1
        onClicked: {
            gameScene.state = "play"
            z = 99
        }
    }

    Rectangle {
        id: moveControl

        visible: !system.desktopPlatform
        enabled: visible
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 50
        width: 150
        color: Style.whiteColor
        opacity: 0.2

        Rectangle {
            anchors.centerIn: parent
            width: 1
            height: parent.height
            color: Style.whiteColor
        }
        MultiPointTouchArea {
            anchors.fill: parent
            onPressed: {
                if(touchPoints[0].x < width/2)
                    controller.xAxis = -1
                else
                    controller.xAxis = 1
            }
            onUpdated: {
                if(touchPoints[0].x < width/2)
                    controller.xAxis = -1
                else
                    controller.xAxis = 1
            }
            onReleased: controller.xAxis = 0
        }
    }

    Rectangle {
        id: jumpControl
        visible: !system.desktopPlatform
        enabled: visible
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: 100
        width: 100
        color: Style.whiteColor
        opacity: 0.2

        Text {
            anchors.centerIn: parent
            text: "jump"
            color: Style.whiteColor
            font.pixelSize: 9
        }
        MouseArea {
            anchors.fill: parent
            onPressed: player.jump()
        }
    }

    Rectangle {
        id: fireControl
        visible: !system.desktopPlatform
        enabled: visible
        anchors.left: jumpControl.left
        anchors.bottom: jumpControl.top
        height: 100
        width: 100
        color: Style.whiteColor
        opacity: 0.2

        Text {
            anchors.centerIn: parent
            text: "fire"
            color: Style.whiteColor
            font.pixelSize: 9
        }
        MouseArea {
            anchors.fill: parent
            onPressed: player.shoot()
        }
    }

    Keys.forwardTo: controller
    TwoAxisController {
        id: controller
        onInputActionPressed: {

            if(actionName == "up") {
                player.jump()
            }
            if(actionName == "fire") {
                player.shoot()
                // saves the last time a bullet was fired
                var lastTime = 0

                // calculate the time between the current tap and the last time a bullet was fired
                var currentTime = new Date().getTime()
                var timeDiff = currentTime - lastTime

                // if enough time has passed, create a new bullet

                lastTime = currentTime

                // TODO : play either the icicle or snowball sound depending on the current bullet type


                // pick a bullet speed depending on the current powerup
                var speed = 140

                // pick the calculation of the tankBody and add 90 because of the rotated image
                //            var rotation = tank.tankBody.rotation + 90

                // calculate a bullet movement vector with the rotation and the speed
                var xDirection = Math.cos(0 * Math.PI / 180.0) * speed
                var yDirection = Math.sin(0 * Math.PI / 180.0) * speed

                // calculate the bullet spawn point: start at the center of the tank translate it outside of the body towards the final direction
                var startX = player.x + player.width / 2 + 5
                var startY = player.y + player.height + 135

                // create and remove bullet entities at runtime
                entityManager.createEntityFromUrlWithProperties(Qt.resolvedUrl("../entities/Bullet.qml"), {
                                                                    "start" : Qt.point(startX, startY),
                                                                    "velocity" : Qt.point(xDirection, yDirection),
                                                                    "rotation" :  0,
                                                                    "bulletType" : 0});
            }
        }
    }


    // displaying the score
//    Numbers {
//        anchors.horizontalCenter: parent.horizontalCenter
//        y: 30
//        number: score
//    }

    GameOverScreen {
        id: gameOverStats

        onPlayPressed: gameScene.state = "wait"
        onMenuPressed: parent.menuPressed()
//        onNetworkPressed: parent.networkPressed()
//        onUseCoinsPressed: parent.useCoinsPressed()
    }

    onBackButtonPressed: {
        if(scene.state === "gameOver") mainItem.state = "menu"
        gameScene.state = "gameOver"
    }

    function enterScene() {
        state = "wait"
    }

    function exitScene() {
        menuPressed()
    }

    function initGame() {
        player.x = 20
        player.y = 100

        score = 0
    }

    function startGame() {
        jumpControl.enabled = true
        moveControl.enabled = true
    }

    function stopGame() {
        jumpControl.enabled = false
        moveControl.enabled = false
    }

    function gameOver() {
        stopGame()
        if(score > 0) {
//            gameNetwork.reportScore(score)
        }
    }

    state: "wait"

    states: [
        State {
            name: "wait"
            PropertyChanges {target: waitToPlay; opacity: 1}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}

            StateChangeScript {
                script: {
                    initGame()
                }
            }
        },
        State {
            name: "play"
            PropertyChanges {target: gameScene; gameIsRunning: true}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}
            StateChangeScript {
                script: {
                    startGame()
                }
            }
        },
        State {
            name: "gameOver"
            PropertyChanges {target: gameOverStats; opacity: 1}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}
            StateChangeScript {
                script: {
                    gameOver()
                }
            }
        }
    ]
}
