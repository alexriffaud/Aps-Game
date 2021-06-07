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

    ImageButton {
        id: creditsTitle
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backPressed()
        }
        source: "../../assets/img/sign-up-title.png"
    }

    Column {
        anchors.top: creditsTitle.bottom
        spacing: 18
        anchors.horizontalCenter: parent.horizontalCenter
        height: okButton.height

        InputLine
        {
            id: inputLogin
            text.text: "Login"
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: "Login"
        }

        InputLine
        {
            id: inputMail
            text.text: "Mail"
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: "Mail"
        }
        InputLine
        {
            id: inputFirstName
            text.text: "FirstName"
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: "First name"
        }

        InputLine
        {
            id: inputPassword
            text.text: "Password"
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.echoMode: TextInput.Password
            textEdit.placeholderText: "Password"
        }

        AppText {
            id: name
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Birth date"
            color:  "#FFFFFF"
            fontSize: 25
            font.family: "Helvetica"
        }

        DatePicker {
          id: datePicker
          anchors.horizontalCenter: parent.horizontalCenter
          width: inputFirstName.width
          datePickerMode: dateMode
        }
        Row {
            ImageButton {
                id: okButton
                onClicked: {
                    okPressed()
                }
                source: "../../assets/img/ok.png"
            }
            ImageButton {
                id: backButton
                onClicked: {
                    backPressed()
                }
                source: "../../assets/img/back.png"
            }
        }
    }





}
