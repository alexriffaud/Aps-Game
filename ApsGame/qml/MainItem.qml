import Felgo 3.0
import QtQuick 2.0
import QtQuick.Dialogs 1.1
import "scenes"
import "common"

Item {
    id: mainItem
    property alias audioManager: audioManager
    property alias entityManager: entityManager

    property int coins

    // Sound management
    AudioManager {
        id: audioManager
    }

    ConnectionScene {
        id: connexionScene

        function login(username, password)
        {
            mainApp.login(username,password)
        }

        onConnectionPressed: {
            login(connection.inputLogin.textEdit.text, connection.inputPassword.textEdit.text)
        }

        onSignupPressed: {
            mainItem.state = "signup"
        }

        Connections
        {
            target: mainApp
            function onChangeLoginState()
            {
                if(mainApp.isConnected() === true)
                {
                    mainItem.state = "menu"
                }
                else
                {
                    messageDialog.show(qsTr("Error when trying to login"))
                }
            }
        }

        MessageDialog {
            id: messageDialog
            title: qsTr("Error when trying to login")
            function show(message) {
                messageDialog.text = message;
                messageDialog.open();
            }
        }
    }

    MenuScene {
        id: menuScene
        onGamePressed: {
            mainItem.state = "game"
        }
        onAccountPressed: {
            mainItem.state = "account"
            accountScene.inputLogin.textEdit.text = currentUser.login();
            accountScene.inputFirstName.textEdit.text = currentUser.firstname();
            accountScene.inputMail.textEdit.text = currentUser.mail();
            accountScene.inputPassword.textEdit.text = currentUser.password();
        }
        onScoresPressed: {
            mainItem.state = "scores"
        }

        onCreditsPressed: {
            mainItem.state = "credits"
        }


        onBackButtonPressed: {
            nativeUtils.displayMessageBox("Really quit the game?", "", 2);
        }

        Connections {
            // nativeUtils should only be connected, when this is the active scene
            target: window.activeScene === menuScene ? nativeUtils : null
            onMessageBoxFinished: {
                if(accepted) {
                    Qt.quit()
                }
            }
        }
    }

    GameScene {
        id: gameScene

        onMenuPressed: {
            mainItem.state = "menu"
        }
        onNetworkPressed: {
            vplayGameNetworkScene.initialStateBeforeShow = "game"
            mainItem.state = "gameNetwork"
        }
        onUseCoinsPressed: {
        }
    }

    AccountScene
    {
        id: accountScene
        opacity: 0

        function checkLogin(login) {
            mainApp.checkLogin(login)
        }

        function changeAccount(login, mail, firstname, password, birthdate) {
            mainApp.changeAccount(login, mail, firstname, password)
        }

        onOkPressed: {
            changeAccount(inputLogin.textEdit.text, inputMail.textEdit.text, inputFirstName.textEdit.text, inputPassword.textEdit.text)
        }

        onBackPressed: {
            mainItem.state = "menu"
            accountScene.inputLogin.textEdit.text = currentUser.login();
            accountScene.inputFirstName.textEdit.text = currentUser.firstname();
            accountScene.inputMail.textEdit.text = currentUser.mail();
            accountScene.inputPassword.textEdit.text = currentUser.password();
        }

        onLoginChanged: {
            checkLogin(inputLogin.textEdit.text)
        }

        Connections
        {
            target: mainApp
            function onChangeCheckLoginState()
            {
                if(mainApp.loginState() === true)
                {
                    console.log(mainApp.loginState())
                    accountScene.message.opacity = 0
                }
                else
                {
                    console.log(mainApp.loginState())
                    accountScene.message.opacity = 1
                }
            }
        }

        Connections
        {
            target: mainApp
            function onChangeAccountState()
            {
                if(mainApp.accountChangeState() === true)
                {
                    mainItem.state = "menu"

                    messageDialog.show(qsTr("Your account has been update"))
                    accountScene.inputLogin.textEdit.text = currentUser.login();
                    accountScene.inputFirstName.textEdit.text = currentUser.firstname();
                    accountScene.inputMail.textEdit.text = currentUser.mail();
                    accountScene.inputPassword.textEdit.text = currentUser.password();
                }
                else
                {
                    messageDialog.show(qsTr("Error during the update"))
                }
            }
        }
    }

    ScoresScene {
        id: scoresScene
        opacity: 0

        onBackPressed: {
            mainItem.state = "menu"
            creditsScene.opacity = 0
        }
    }

    CreditsScene {
        id: creditsScene
        opacity: 0

        onBackPressed: {
            mainItem.state = "menu"
            creditsScene.opacity = 0
        }
    }

    SignUpScene {
        id: signupScene
        opacity: 0

        function signup(login, mail, firstname, password, birthdate) {
            mainApp.signUp(login, mail, firstname, password, birthdate)
        }

        onOkPressed: {
            signup(inputLogin.textEdit.text, inputMail.textEdit.text, inputFirstName.textEdit.text, inputPassword.textEdit.text, datePicker.selectedDate)
        }

        onBackPressed: {
            mainItem.state = "connexion"
            signupScene.opacity = 0
        }

        Connections
        {
            target: mainApp
            function onChangeSignUpState()
            {
                if(mainApp.isSignUp() === true)
                {
                    console.log("Ok")
                    mainItem.state = "connexion"
                    signupScene.opacity = 0
                }
                else
                {
                    messageDialog.show(qsTr("Error when trying to sign up"))
                }
            }
        }

        MessageDialog {
            id: messageDialogSignUp
            title: qsTr("Error when trying to sign up")
            function show(message) {
                messageDialogSignUp.text = message;
                messageDialogSignUp.open();
            }
        }
    }

    EntityManager {
        id: entityManager
        entityContainer: gameScene.entityContainer
    }

    state: "connexion"

    states: [
        State {
            name: "connexion"
            PropertyChanges {target: connexionScene; opacity: 1}
            PropertyChanges {target: window; activeScene: connexionScene}
        },
        State {
            name: "signup"
            PropertyChanges {target: signupScene; opacity: 1}
            PropertyChanges {target: window; activeScene: signupScene}
        },
        State {
            name: "menu"
            PropertyChanges {target: menuScene; opacity: 1}
            PropertyChanges {target: window; activeScene: menuScene}
            StateChangeScript {
                script: {
                    audioManager.play(audioManager.idSWOOSHING)
                }
            }
        },
        State {
            name: "account"
            PropertyChanges {target: accountScene; opacity: 1}
            PropertyChanges {target: window; activeScene: accountScene}
        },
        State {
            name: "scores"
            PropertyChanges {target: scoresScene; opacity: 1}
            PropertyChanges {target: window; activeScene: scoresScene}
        },
        State {
            name: "credits"
            PropertyChanges {target: creditsScene; opacity: 1}
            PropertyChanges {target: window; activeScene: creditsScene}
        },
        State {
            name: "game"
            PropertyChanges {target: gameScene; opacity: 1}
            PropertyChanges {target: window; activeScene: gameScene}
            StateChangeScript {
                script: {
                    gameScene.enterScene()
                    audioManager.play(audioManager.idSWOOSHING)
                }
            }
        }
    ]
}
