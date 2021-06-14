import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

Scene {
    id: settingsScene
    signal backPressed()

    Background {
        anchors.horizontalCenter: settingsScene.gameWindowAnchorItem.horizontalCenter
        anchors.bottom: settingsScene.gameWindowAnchorItem.bottom
    }

    ImageButton {
        id: creditsTitle
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: Language.credtisTitlePath
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
