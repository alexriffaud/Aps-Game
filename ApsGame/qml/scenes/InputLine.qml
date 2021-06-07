import QtQuick 2.0
import Felgo 3.0

Row {

    id: inputLine

    property alias text: name
    property alias rectangle: rectangle
    property alias textEdit: textEdit

    spacing: 18

    AppText {
        id: name
        text: "Login"
        color:  "#FFFFFF"
        fontSize: 25
        font.family: "Helvetica"
    }

    Rectangle {
        id: rectangle
        width: dp(200)
        height: dp(50)
        anchors.margins: -dp(8)
        color: "lightgrey"

        AppTextInput {
            id: textEdit
            anchors.fill: parent
            placeholderText: "What's your name?"
        }
    }
}
