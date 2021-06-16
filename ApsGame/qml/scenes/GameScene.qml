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
        movementVelocity: player.x > offsetBeforeScrollingStarts ? Qt.point(-player.horizontalVelocity,0) : Qt.point(0,0)
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
            debugDrawVisible: true // enable this for physics debugging
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

            onGameOver: {
                gameScene.state = "gameOver"
            }
        }

        Monster {
            id: monster
            x: 50
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
        enabled : false
        onInputActionPressed: {

            if(actionName == "up") {
                player.jump()
            }
            if(actionName == "fire") {
                 var startX  = 0
                if(player.x > offsetBeforeScrollingStarts)
                {
                    startX = player.x  +player.width / 2 + 10
                }
                else
                {
                     startX = player.x + player.width / 2 + 10
                }
                var startY = player.y  + player.width / 2 +5

                entityManager.createEntityFromUrlWithProperties(Qt.resolvedUrl("../entities/Bullet.qml"), {
                                                                    "start" : Qt.point(startX, startY)});
            }
        }
    }


    // displaying the score
//    Numbers {
//        anchors.horizontalCenter: parent.horizontalCenter
//        y: 30
//        number: score
//    }

    Timer {
        id: timer
        property int chrono: 0
        interval: 1000; running: false; repeat: true
        onTriggered:
        {
            chrono++
            time.text =  "Time = "+chrono
        }
    }

    AppText {
        id: time
        color:  Style.whiteColor
        fontSize: Style.textSize3
        font.family: Style.customFont
    }

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
        controller.enabled = true
        jumpControl.enabled = true
        moveControl.enabled = true
        timer.start()
    }

    function stopGame() {
        controller.enabled = false
        jumpControl.enabled = false
        moveControl.enabled = false
        timer.stop()
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
