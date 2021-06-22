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
    property int timeScore: 100

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

            onGameOver: {
                gameScene.state = "gameOver"
            }

            onDamageTaken: {
                switch(player.life)
                {
                case 100:
                    lifebar.source = Style.life100
                    break
                case 80:
                    lifebar.source = Style.life80
                    break
                case 60:
                    lifebar.source = Style.life60
                    break
                case 40:
                    lifebar.source = Style.life40
                    break
                case 20:
                    lifebar.source = Style.life20
                    break
                case 0:
                    lifebar.source = Style.life0
                    gameScene.state = "gameOver"
                    break
                }
            }

            onMonsterTouched: {
                score = score - 5
            }
        }

        Monster {
            id: monster
            x: 60
            y: 100

            onMonsterKilled: {
                score = score + 15
            }
        }

        Capsule {
            id: capsule
            x: 150
            y: 50

            onItemTaken : {
                score = score + 10
            }
        }

        Flag {
            id: flag
            x: 1200
            y: 200

            onEndGame: {
                score = score + 100
                stopGame()
                gameScene.state = "win"
            }
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

    WinScreen {
        id: winScreen
        onPlayPressed: gameScene.state = "wait"
        onMenuPressed: parent.menuPressed()

        AppText {
            id: scoreTextWin
            text: score
            color:  Style.whiteColor
            fontSize: Style.textSize1
            font.family: Style.customFont
            anchors.top: winScreen.menuBack.bottom
            anchors.horizontalCenter: winScreen.horizontalCenter

        }
    }

    Rectangle {
        id: moveControl

        visible: !system.desktopPlatform
        enabled: visible
        anchors.right: gameScene.right
        anchors.bottom: viewPort.bottom
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
        anchors.left: gameScene.left
        anchors.bottom: viewPort.bottom
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
        anchors.left: gameScene.left
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
            onPressed:
            {
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
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

    }

    AppText {
        id: scoreText
        text: score
        color:  Style.whiteColor
        fontSize: Style.textSize1
        font.family: Style.customFont
        anchors.top: lifebar.bottom
        anchors.horizontalCenter: parent.horizontalCenter

    }

    ImageButton {
        id: pauseButton
        source: Language.pauseButtonPath
        onClicked: {
            pauseGame()
        }
        anchors.top: parent.top
        anchors.right: parent.right
    }

    MultiResolutionImage {
        id: lifebar
        source: Style.life100
        anchors.top: time.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ImageButton {
        id: backButton
        source: Language.backMenuButtonPath
        onClicked: {
            console.log("clicked")
            gameScene.state = "backMenu"

        }
        anchors.top: parent.top
        anchors.left: parent.left
    }

    GameOverScreen {
        id: gameOverStats

        AppText {
            id: scoreTextLose
            text: score
            color:  Style.whiteColor
            fontSize: Style.textSize1
            font.family: Style.customFont
            anchors.top: gameOverStats.menuBackOver.bottom
            anchors.horizontalCenter: gameOverStats.horizontalCenter

        }

        onPlayPressed: gameScene.state = "wait"
        onMenuPressed: parent.menuPressed()
    }

    BackScene {
        id: backScene
        opacity: 0

        onPlayPressed: {
            gameIsRunning = true
            backScene.opacity = 0
            startGame()
            gameScene.state = "isPlaying"
        }

        onMenuPressed: {
            stopGame()
            mainItem.state = "menu"
        }

        onSavePressed: {

        }
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
        player.life = 100
        lifebar.source = Style.life100
        lifebar.opacity = 1
        controller.enabled = true
        jumpControl.enabled = true
        moveControl.enabled = true
        timer.start()
        monster.movementAnimation.running = true
        scoreText.opacity = 1
        score = 0
    }

    function stopGame() {
        timeScore = timeScore - (timer.chrono * 0.75)
        controller.enabled = false
        jumpControl.enabled = false
        moveControl.enabled = false
        gameIsRunning = false
        lifebar.opacity = 0
        timer.stop()
        if(monster) {
            monster.movementAnimation.running = false
        }
        scoreText.opacity = 0

        if(score > 0)
        {
            gameScene.networkPressed()
        }
    }

    function pauseGame() {
        if(gameIsRunning)
        {
            timer.stop()
            pauseButton.source = Language.playButtonPath

            controller.enabled = false
            jumpControl.enabled = false
            moveControl.enabled = false

            gameIsRunning = false

            scoreText.opacity = 0
        }
        else
        {
            timer.start()
            pauseButton.source = Language.pauseButtonPath

            controller.enabled = true
            jumpControl.enabled = true
            moveControl.enabled = true

            gameIsRunning = true

            scoreText.opacity = 1
        }
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
            name: "win"
            PropertyChanges {target: winScreen; opacity: 1}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}
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
            name: "isPlaying"
            PropertyChanges {target: gameScene; gameIsRunning: true}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}
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
        },
        State {
            name: "backMenu"
            PropertyChanges {target: backScene; opacity: 1}
            PropertyChanges {target: physicsWorld; gravity: Qt.point(0, 25)}
            StateChangeScript {
                script: {
                    pauseGame()
                }
            }
        }
    ]
}
