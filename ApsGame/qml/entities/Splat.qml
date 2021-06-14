import QtQuick 2.0
import Felgo 3.0
import ".."

EntityBase {
    id: splat
    entityType: "splat"
    entityId: "splat"

    property alias splatTimer: splatTimer

    Image {
        width: 15
        height: 25
        anchors.centerIn: parent
        source: "../../assets/img/splat.png"
    }

    onEntityCreated: splatTimer.running = true

    // show the image for a small period of time and remove it
    Timer {
        id: splatTimer
        interval: 300
        running: false
        repeat: false

        onTriggered:{
            splat.destroy();
        }
    }
}
