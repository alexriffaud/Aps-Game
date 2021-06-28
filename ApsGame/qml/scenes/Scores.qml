import QtQuick 2.0
import Felgo 3.0

import "../common"

Column {
    id: scores
    anchors.horizontalCenter: parent.horizontalCenter
    height: 500
    width: parent.width
    property alias scoreList: scoreList
    clip: true

    signal personalScore()
    signal globalScore()

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
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

            onCheckedChanged: {
                if(checked)
                {
                    scores.personalScore()
                }
                else
                {
                    scores.globalScore()
                }
            }
        }
    }

    ListView {
        anchors.top: chooseScoreTab.bottom
        id: scoreList
        anchors.topMargin: 75
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.bottomMargin: 200

        spacing: 5
        clip: true

        model: modelScores
        delegate: Rectangle {
            height: 30
            width: parent.width
            color: Style.transparentColor
            border.width: 2
            border.color: Style.whiteColor
            Row {
                anchors.topMargin: 10
                anchors.leftMargin: 10
                anchors.bottomMargin: 10
                Text {
                    x: 5
                    y: 5
                    text: '<b>Name:</b>   ' + model.item.user + " :       "
                    color: Style.whiteColor
                }
                Text {
                    y : 5
                    text: "   "+model.item.score
                    color: Style.whiteColor
                }

                Text {
                    y : 5
                    text: "   "+model.item.date
                    color: Style.whiteColor
                }
            }
        }
    }
}
