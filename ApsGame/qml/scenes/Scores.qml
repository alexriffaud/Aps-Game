import QtQuick 2.0
import Felgo 3.0

// EMPTY SCENE

Column {
    id: scores
    anchors.horizontalCenter: parent.horizontalCenter

    Row {
        AppText {
            id: chooseScoreTab
            text: "Personal scores"
            color:  "#FFFFFF"
            fontSize: 14
            font.family: "Helvetica"
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
            color: "transparent"
            border.width: 2
            border.color: "white"
            Row {
                Text {
                    text: '<b>Name:</b> ' + model.item.user + " : "
                    color: "white"
                }
                Text {
                    text: model.item.score
                    color: "white"
                }
            }
        }
    }
}
