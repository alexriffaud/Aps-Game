import QtQuick 2.0
import Felgo 3.0

Column {
    signal connectionPressed()
    signal signupPressed()

    property alias inputLogin: inputLogin
    property alias inputPassword: inputPassword

    spacing: 18
    anchors.horizontalCenter: parent.horizontalCenter
    height: connectionItem.height

    InputLine
    {
        id: inputLogin
        text.text: "Login"
        text.width: dp(100)
        textEdit.placeholderText: "Login"
    }

    InputLine
    {
        id: inputPassword
        text.width: dp(100)
        text.text: "Password"
        textEdit.echoMode: TextInput.Password
        anchors.horizontalCenter: parent.horizontalCenter
        textEdit.placeholderText: "Password"
    }

    ImageButton {
        id: connectionItem
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            connectionPressed()
        }
        source: "../../assets/img/connect.png"
    }

    ImageButton {
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            signupPressed()
        }
        source: "../../assets/img/signup.png"
    }
}
