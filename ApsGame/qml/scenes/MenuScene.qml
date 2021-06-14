import QtQuick 2.0
import Felgo 3.0
import "../common"
import "../entities"

SceneBase {
    id: scene

    signal gamePressed()
    signal accountPressed()
    signal scoresPressed()
    signal creditsPressed()

    Background {
        anchors.horizontalCenter: scene.gameWindowAnchorItem.horizontalCenter
        anchors.bottom: scene.gameWindowAnchorItem.bottom
    }

    MultiResolutionImage {
        id: logo
        anchors.top: parent.top
//        anchors.topMargin: 60
        anchors.horizontalCenter: scene.gameWindowAnchorItem.horizontalCenter
        source: "../../assets/img/logo.png"
    }

    Menu {
        anchors.top: logo.bottom

        onCreditsPressed: parent.creditsPressed()
        onPlayPressed: gamePressed()
        onAccountPressed: parent.accountPressed()
        onScoresPressed: parent.scoresPressed()

    }

    onEnterPressed: {
        gamePressed()
    }
}
