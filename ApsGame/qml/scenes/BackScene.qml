import QtQuick 2.0
import Felgo 3.0

import "../common"
import "../entities"

Item {
    width: parent.width
    height: parent.height
    y: -30
    opacity: 0
    visible: opacity === 0 ? false : true
    enabled: visible

    signal playPressed()
    signal menuPressed()
    signal savePressed()

    Column {


        spacing: 18
        anchors.horizontalCenter: parent.horizontalCenter
        height: menuItem.height

        ImageButton {
            id: menuItem
            onClicked: {
                playPressed()
            }
            source: Language.playAgainPath
        }

        ImageButton {
            onClicked: {
                menuPressed()
            }
            source: Language.menuPath
        }

        ImageButton {
            onClicked: {
                savePressed()
            }
            source: Language.savePath
        }
    }
}
