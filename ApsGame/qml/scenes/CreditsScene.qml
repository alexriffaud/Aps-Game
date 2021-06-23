import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

Scene {
    id: creditsScene
    signal backPressed()

    Background {
        anchors.horizontalCenter: creditsScene.gameWindowAnchorItem.horizontalCenter
        anchors.bottom: creditsScene.gameWindowAnchorItem.bottom
    }

    ImageButton {
        id: creditsTitle
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: Language.credtisTitlePath
    }

    AppText {
        id: creditsText
        width: parent.width
        anchors.top: creditsTitle.bottom
        anchors.bottom: backButton.top
        text: Language.credits
        padding: dp(10)
        color:  Style.whiteColor
        fontSize: Style.textSize1
        font.family: Style.customFont
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
