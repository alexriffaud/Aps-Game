import QtQuick 2.0
import Felgo 3.0

import "../entities"

TileEntityBase {
    id: ground
    entityType: "ground"

    size: 2

    Row {
        id: tileRow
        Tile {
            pos: "left"
            image: "../../assets/img/ground/left.png"
        }
        Repeater {
            model: size-2
            Tile {
                pos: "mid"
                image: "../../assets/img/ground/mid.png"
            }
        }
        Tile {
            pos: "right"
            image: "../../assets/img/ground/right.png"
        }
    }

    BoxCollider {
        anchors.fill: parent
        bodyType: Body.Static
        fixture.onBeginContact: {
            var otherEntity = other.getBody().target
            if(otherEntity.entityType === "player") player.contacts++
        }
        fixture.onEndContact: {
            var otherEntity = other.getBody().target
            if(otherEntity.entityType === "player") player.contacts--
        }
    }
}
