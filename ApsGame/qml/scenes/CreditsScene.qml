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
        source: "../../assets/img/credits-title.png"
    }

    AppText {
        id: creditsText
        width: parent.width
        anchors.top: creditsTitle.bottom
        text: "A video game or computer game is an electronic game that involves interaction with a user interface or input device – such as a joystick, controller, keyboard, or motion sensing device – to generate visual feedback. This feedback is shown on a video display device, such as a TV set, monitor, touchscreen, or virtual reality headset. Video games are often augmented with audio feedback delivered through speakers or headphones, and sometimes with other types of feedback, including haptic technology. "
        padding: dp(10)
        color:  "#FFFFFF"
        fontSize: 25
        font.family: "Helvetica"
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
