pragma Singleton
import QtQuick 2.0

QtObject  {

    property var accountPath: "../../assets/img/language/english/account.png"
    property var accountTitlePath: "../../assets/img/language/english/account-title.png"
    property var connectPath: "../../assets/img/language/english/connect.png"
    property var backPath: "../../assets/img/language/english/back.png"
    property var creditsPath: "../../assets/img/language/english/credits.png"
    property var credtisTitlePath: "../../assets/img/language/english/credits-title.png"
    property var gameOverPath: "../../assets/img/language/english/gameOver.png"
    property var getReadyPath: "../../assets/img/language/english/getReady.png"
    property var menuPath: "../../assets/img/language/english/manu.png"
    property var okPath: "../../assets/img/language/english/ok.png"
    property var playAgainPath: "../../assets/img/language/english/playAgain.png"
    property var scoresPath: "../../assets/img/language/english/scores.png"
    property var scoresTitlePath: "../../assets/img/language/english/score-title.png"
    property var signUpPath: "../../assets/img/language/english/signup.png"
    property var signUpTitlePath: "../../assets/img/language/english/sign-up-title.png"
    property var languagePath: "../../assets/img/language/english/language.png"

    property var login: "Login"
    property var password: "Password"
    property var mail: "Mail"
    property var firstname: "First name"
    property var birthdate: "Birth date"
    property var loginUsed: "Your login is already in use."
    property var credits: "A video game or computer game is an electronic game that involves interaction with a user interface or input device – such as a joystick, controller, keyboard, or motion sensing device – to generate visual feedback. This feedback is shown on a video display device, such as a TV set, monitor, touchscreen, or virtual reality headset. Video games are often augmented with audio feedback delivered through speakers or headphones, and sometimes with other types of feedback, including haptic technology. "
    property var personalScore: "Personal scores"

    function isEnglish()
    {
        accountPath= "../../assets/img/language/english/account.png"
        accountTitlePath= "../../assets/img/language/english/account-title.png"
        backPath= "../../assets/img/language/english/back.png"
        connectPath = "../../assets/img/language/english/connect.png"
        creditsPath= "../../assets/img/language/english/credits.png"
        credtisTitlePath= "../../assets/img/language/english/credits-title.png"
        gameOverPath= "../../assets/img/language/english/gameOver.png"
        getReadyPath= "../../assets/img/language/english/getReady.png"
        menuPath= "../../assets/img/language/english/manu.png"
        okPath= "../../assets/img/language/english/ok.png"
        playAgainPath= "../../assets/img/language/english/playAgain.png"
        scoresPath= "../../assets/img/language/english/scores.png"
        scoresTitlePath= "../../assets/img/language/english/score-title.png"
        signUpPath= "../../assets/img/language/english/signup.png"
        signUpTitlePath= "../../assets/img/language/english/sign-up-title.png"
        languagePath= "../../assets/img/language/english/language.png"

        birthdate = "Birth date"
        personalScore = "Personal scores"
        login= "Login"
        password= "Password"
        mail = "Mail"
        firstname = "First name"
        loginUsed= "Your login is already in use."
        credits = "A video game or computer game is an electronic game that involves interaction with a user interface or input device – such as a joystick, controller, keyboard, or motion sensing device – to generate visual feedback. This feedback is shown on a video display device, such as a TV set, monitor, touchscreen, or virtual reality headset. Video games are often augmented with audio feedback delivered through speakers or headphones, and sometimes with other types of feedback, including haptic technology. "
    }

    function isFrench()
    {
        accountPath= "../../assets/img/language/french/account.png"
        accountTitlePath= "../../assets/img/language/french/account-title.png"
        backPath= "../../assets/img/language/french/back.png"
        connectPath = "../../assets/img/language/french/connect.png"
        creditsPath= "../../assets/img/language/french/credits.png"
        credtisTitlePath= "../../assets/img/language/french/credits-title.png"
        gameOverPath= "../../assets/img/language/french/gameOver.png"
        getReadyPath= "../../assets/img/language/french/getReady.png"
        menuPath= "../../assets/img/language/french/manu.png"
        okPath= "../../assets/img/language/french/ok.png"
        playAgainPath= "../../assets/img/language/french/playAgain.png"
        scoresPath= "../../assets/img/language/french/scores.png"
        scoresTitlePath= "../../assets/img/language/french/score-title.png"
        signUpPath= "../../assets/img/language/french/signup.png"
        signUpTitlePath= "../../assets/img/language/french/sign-up-title.png"
        languagePath= "../../assets/img/language/french/language.png"

        login= "Pseudo"
        personalScore =  "Mes scores"
        password= "Mot de passe"
        mail = "EMail"
        firstname = "Prénom"
        birthdate = "Date de naissance"
        loginUsed= "Le login est déjà utilisé"
        credits = "Un jeu vidéo est un jeu électronique doté d'une interface utilisateur permettant une interaction humaine ludique en générant un retour visuel sur un dispositif vidéo. Le joueur de jeu vidéo dispose de périphériques pour agir sur le jeu et percevoir les conséquences de ses actes sur un environnement virtuel. Le mot « vidéo » dans le jeu vidéo fait traditionnellement référence à un dispositif d'affichage de trame, mais, à la suite de la vulgarisation du terme, il implique désormais tout type de dispositif d'affichage. "
    }
}
