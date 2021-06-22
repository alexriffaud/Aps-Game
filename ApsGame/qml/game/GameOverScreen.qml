import Felgo 3.0
import QtQuick 2.0
import "../scenes"
import "../common"

Item {
    width: parent.width
    height: parent.height
    y: -30
    opacity: 0
    visible: opacity === 0 ? false : true
    enabled: visible

    signal playPressed()
    signal menuPressed()

    property alias menuBackOver: menuBackOver

    MultiResolutionImage {
        id: image
        source: Language.gameOverPath
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 30
    }

    ImageButton {
        id: menuItem
        anchors.top: image.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            playPressed()
        }
        source: Language.playAgainPath
    }

    ImageButton {
        id: menuBackOver
        anchors.top: menuItem.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            menuPressed()
        }
        source: Language.menuPath
    }

}
