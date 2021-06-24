import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

SceneBase {
    id: sceneConnection

    signal connectionPressed()
    signal signupPressed()

    property alias connection: connection

    Background {
        anchors.horizontalCenter: sceneConnection.gameWindowAnchorItem.horizontalCenter
        anchors.bottom: sceneConnection.gameWindowAnchorItem.bottom
    }

    MultiResolutionImage {
        id: logo
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.horizontalCenter: sceneConnection.gameWindowAnchorItem.horizontalCenter
        source: "../../assets/img/logo.png"
    }

    Connection {
        id: connection
        anchors.top: logo.bottom

        onConnectionPressed: parent.connectionPressed()
        onSignupPressed: parent.signupPressed()
    }
}
