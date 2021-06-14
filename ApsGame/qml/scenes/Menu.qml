import Felgo 3.0
import QtQuick 2.0

import "../common"

Column {
    signal playPressed()
    signal accountPressed()
    signal scoresPressed()
    signal creditsPressed()

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
            scoresPressed()
        }
        source: Language.scoresPath
    }

    ImageButton {
        onClicked: {
            accountPressed()
        }
        source: Language.accountPath
    }

    ImageButton {
        onClicked: {
            creditsPressed()
        }
        source: Language.creditsPath
    }
}
