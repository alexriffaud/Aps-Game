import Felgo 3.0
import QtQuick 2.0

import "../common"

EntityBase {
    id: resetSensor
    entityType: "resetSensor"

    signal contact

// debug
//    Text {
//        anchors.centerIn: parent
//        text: "reset sensor"
//        color: Style.whiteColor
//        font.pixelSize: 9
//    }

    BoxCollider {
        anchors.fill: parent
        collisionTestingOnlyMode: true
        fixture.onBeginContact: {
            var otherEntity = other.getBody().target
            if(otherEntity.entityType === "player")
            {
                resetSensor.contact()
            }
        }
    }
}
