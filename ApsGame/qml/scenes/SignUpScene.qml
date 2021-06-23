import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

Scene {
    id: signupScene

    signal backPressed()
    signal okPressed()

    property alias inputLogin: inputLogin
    property alias inputMail: inputMail
    property alias inputFirstName: inputFirstName
    property alias inputPassword: inputPassword
    property alias datePicker: datePicker

    Background {
        anchors.horizontalCenter: signupScene.gameWindowAnchorItem.horizontalCenter
        anchors.bottom: signupScene.gameWindowAnchorItem.bottom
    }

    Column {
        anchors.top: signupScene.top
        spacing: 18
        anchors.horizontalCenter: parent.horizontalCenter
        height: okButton.height

        InputLine
        {
            id: inputLogin
            text.text: Language.login
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: Language.login
        }

        InputLine
        {
            id: inputMail
            text.text: Language.mail
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: Language.mail
        }
        InputLine
        {
            id: inputFirstName
            text.text: Language.firstname
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: Language.firstname
        }

        InputLine
        {
            id: inputPassword
            text.text: Language.password
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.echoMode: TextInput.Password
            textEdit.placeholderText: Language.password
        }

        AppText {
            id: name
            anchors.horizontalCenter: parent.horizontalCenter
            text: Language.birthdate
            color:  Style.whiteColor
            fontSize: Style.textSize1
            font.family: Style.customFont
        }

        DatePicker {
            id: datePicker
            anchors.horizontalCenter: parent.horizontalCenter
            width: inputFirstName.width
            datePickerMode: dateMode
        }
        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            ImageButton {
                id: okButton
                onClicked: {
                    okPressed()
                }
                source: Language.okPath
            }
            ImageButton {
                id: backButton
                onClicked: {
                    backPressed()
                }
                source: Language.backPath
            }
        }
    }





}
