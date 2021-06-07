import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

Scene {
    id: scoresScene
    signal backPressed()

    Background {
      anchors.horizontalCenter: scoresScene.gameWindowAnchorItem.horizontalCenter
      anchors.bottom: scoresScene.gameWindowAnchorItem.bottom
    }

    ImageButton {
        id: creditsTitle
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: "../../assets/img/score-title.png"
    }



    ImageButton {
        id: backButton
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: "../../assets/img/back.png"
    }

}
