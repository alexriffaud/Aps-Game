import QtQuick 2.0
import Felgo 3.0

import "../common"

Column {
    signal connectionPressed()
    signal signupPressed()
    signal languagePressed()

    property alias inputLogin: inputLogin
    property alias inputPassword: inputPassword

    spacing: 18
    anchors.horizontalCenter: parent.horizontalCenter
    height: connectionItem.height

    InputLine
    {
        id: inputLogin
        text.text: Language.login
        text.width: dp(130)
        textEdit.placeholderText: Language.login
    }

    InputLine
    {
        id: inputPassword
        text.width: dp(130)
        text.text: Language.password
        textEdit.echoMode: TextInput.Password
        anchors.horizontalCenter: parent.horizontalCenter
        textEdit.placeholderText: Language.password
    }

    Row {
        anchors{
            horizontalCenter: parent.horizontalCenter
        }
        spacing: 10
        ImageButton {
            id: connectionItem
            onClicked: {
                connectionPressed()
            }
            source: Language.connectPath
        }

        ImageButton {
            onClicked: {
                signupPressed()
            }
            source: Language.signUpPath
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
