import Felgo 3.0
import QtQuick 2.0

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
        source: "../../assets/img/playAgain.png"
    }

    ImageButton {
        onClicked: {
            scoresPressed()
        }
        source: "../../assets/img/scores.png"
    }

    ImageButton {
        onClicked: {
            accountPressed()
        }
        source: "../../assets/img/account.png"
    }

    ImageButton {
        onClicked: {
            creditsPressed()
        }
        source: "../../assets/img/credits.png"
    }
}
