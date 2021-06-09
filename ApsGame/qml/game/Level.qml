import Felgo 3.0
import QtQuick 2.0
import "../entities"
import "../common"
import "." as Levels

Levels.LevelBase {
    id: level
    width: 42 * gameScene.gridSize

    Ground {
        row: 0
        column: 0
        size: 6
    }
    Ground {
        row: 8
        column: 0
        size: 2
    }
    Platform {
        row: 3
        column: 3
        size: 4
    }
    Platform {
        row: 7
        column: 6
        size: 4
    }
    Platform {
        row: 11
        column: 3
        size: 2
    }
    Ground {
        row: 12
        column: 0
        size: 30
    }
    Platform {
        row: 17
        column: 3
        size: 10
    }
}
