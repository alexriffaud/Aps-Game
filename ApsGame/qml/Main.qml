import Felgo 3.0
import QtQuick 2.0
import "scenes"
import "common"

GameWindow {
    id: window
    screenWidth: 1080
    screenHeight: 1920

    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    property alias window: window
    activeScene: splash

    //Show splash screen
    Component.onCompleted: {
        splash.opacity = 1
        mainItemDelay.start()
    }

    // Timer for game's load
    Timer {
        id: mainItemDelay
        interval: 500
        onTriggered: {
            mainItemLoader.source = "MainItem.qml"
        }
    }

    // Load the game
    Loader {
        id: mainItemLoader
        onLoaded: {
            if(item) {
                hideSplashDelay.start()
            }
        }
    }

    // Splash screen timer
    Timer {
        id: hideSplashDelay
        interval: 200
        onTriggered: {
            splash.opacity = 0
        }
    }

    SplashScreenScene {
        id: splash
    }
}
