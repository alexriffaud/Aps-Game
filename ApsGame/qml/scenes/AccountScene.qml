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
        source: Language.accountTitlePath
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
            text.text: Language.login
            text.width: dp(100)
            anchors.horizontalCenter: parent.horizontalCenter
            textEdit.placeholderText: Language.login
            textEdit.onEditingFinished:
            {
                loginChanged()
            }
        }


        AppText {
            id: message
            opacity: 0
            anchors.horizontalCenter: parent.horizontalCenter
            text: Language.loginUsed
            color:  Style.redColor
            fontSize: Style.textSize2
            font.family: Style.customFont
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

        Row
        {
            anchors{
                horizontalCenter: parent.horizontalCenter
            }
            spacing: 10
            ImageButton
            {
                id: okButton
                onClicked:
                {
                    okPressed()
                }
                source: Language.okPath
            }
            ImageButton
            {
                id: backButton
                onClicked:
                {
                    backPressed()
                }
                source: Language.backPath
            }
        }

        ImageButton {
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if(Language.languageState === 0)
                {
                    Language.isFrench();
                    Language.languageState = 1;
                }
                else
                {
                    Language.isEnglish();
                    Language.languageState = 0;
                }
            }
            source: Language.languagePath
        }
    }
}
