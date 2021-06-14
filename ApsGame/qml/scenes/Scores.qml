import QtQuick 2.0
import Felgo 3.0

import "../common"

Column {
    id: scores
    anchors.horizontalCenter: parent.horizontalCenter

    Row {
        AppText {
            id: chooseScoreTab
            text: "Personal scores"
            color:  Style.whiteColor
            fontSize: Style.textSize2
            font.family: Style.customFont
        }

        AppSwitch {
            id: chooseSwitch
            checked: false
        }
    }

    ListView {
        id: scoreList
        anchors.topMargin: 50
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        spacing: 5
        clip: true

        model: modelScores
        delegate: Rectangle {
            height: 130
            width: parent.width
            color: Style.transparentColor
            border.width: 2
            border.color: Style.whiteColor
            Row {
                Text {
                    text: '<b>Name:</b> ' + model.item.user + " : "
                    color: Style.whiteColor
                }
                Text {
                    text: model.item.score
                    color: Style.whiteColor
                }
            }
        }
    }
}
