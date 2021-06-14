import Felgo 3.0
import QtQuick 2.0

EntityBase {
    id: player
    entityType: "player"
    width: 50
    height: 50

    signal gameOver()

    property alias collider: collider
    property alias horizontalVelocity: collider.linearVelocity.x
    property int contacts: 0

    state: contacts > 0 ? "walking" : "jumping"
    onStateChanged: console.debug("player.state " + state)

    MultiResolutionImage {
        source: "../../assets/img/player/run.png"
    }

    onGameOver: {

    }

    BoxCollider {
        id: collider
        height: parent.height
        width: 30
        anchors.horizontalCenter: parent.horizontalCenterss
        bodyType: Body.Dynamic
        fixedRotation: true
        bullet: true
        sleepingAllowed: false
        force: Qt.point(controller.xAxis*170*32,0)

        onLinearVelocityChanged: {
            if(linearVelocity.x > 170) linearVelocity.x = 170
            if(linearVelocity.x < -170) linearVelocity.x = -170
        }
    }

    Timer {
        id: updateTimer
        interval: 60
        running: true
        repeat: true
        onTriggered: {
            var xAxis = controller.xAxis;
            if(xAxis === 0) {
                if(Math.abs(player.horizontalVelocity) > 10) player.horizontalVelocity /= 1.5
                else player.horizontalVelocity = 0
            }
        }
    }

    function jump() {
        if(player.state == "walking") {
            collider.linearVelocity.y = -420
        }
    }

    function shoot() {


    }

}

