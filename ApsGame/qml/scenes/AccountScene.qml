import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"

Scene {

    id: settingsScene
    signal backPressed()
    signal okPressed()
    signal loginChanged()

    property alias message: message
    property alias inputLogin: inputLogin
    property alias inputMail: inputMail
    property alias inputFirstName: inputFirstName
    property alias inputPassword: inputPassword

    Background
    {
      anchors.horizontalCenter: settingsScene.gameWindowAnchorItem.horizontalCenter
      anchors.bottom: settingsScene.gameWindowAnchorItem.bottom
    }

    ImageButton
    {
        id: creditsTitle
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked:
        {
            backPressed()
        }
        source: "../../assets/img/account-title.png"
    }

    Column
    {
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
            textEdit.onEditingFinished:
            {
                console.log("text changed")
                loginChanged()
            }
        }


        AppText {
            id: message
            opacity: 0
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Your login is already in use."
            color:  "#ff2929"
            fontSize: 14
            font.family: "Helvetica"
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

        Row
        {
            ImageButton
            {
                id: okButton
                onClicked:
                {
                    okPressed()
                }
                source: "../../assets/img/ok.png"
            }
            ImageButton
            {
                id: backButton
                onClicked:
                {
                    backPressed()
                }
                source: "../../assets/img/back.png"
            }
        }
    }
}
