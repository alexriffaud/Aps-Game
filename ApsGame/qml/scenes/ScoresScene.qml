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
        id: scoresTitle
        anchors.horizontalCenter: parent.horizontalCenter
        source: Language.scoresTitlePath
    }

    Scores {
        anchors.top: scoresTitle.bottom
    }

    ImageButton {
        id: backButton
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: Language.backPath
    }

}
