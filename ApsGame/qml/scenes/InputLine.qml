import QtQuick 2.0
import Felgo 3.0
import "../common"

Row {

    id: inputLine

    property alias text: name
    property alias rectangle: rectangle
    property alias textEdit: textEdit

    spacing: 18

    AppText {
        id: name
        text: Language.login
        color:  Style.whiteColor
        fontSize: Style.textSize1
        font.family: Style.customFont
    }

    Rectangle {
        id: rectangle
        width: dp(200)
        height: dp(50)
        anchors.margins: -dp(8)
        color: Style.lightGreyColor

        AppTextInput {
            id: textEdit
            anchors.fill: parent
            placeholderText: ""
        }
    }
}
