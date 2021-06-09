import QtQuick 2.0
import Felgo 3.0

TileEntityBase {
    id: platform
    entityType: "platform"

    size: 2

    Row {
        id: tileRow
        Tile {
            pos: "left"
            image: "../../assets/img/platform/left.png"
        }
        Repeater {
            model: size-2
            Tile {
                pos: "mid"
                image: "../../assets/img/platform/mid" + index%2 + ".png"
            }
        }
        Tile {
            pos: "right"
            image: "../../assets/img/platform/right.png"
        }
    }

    BoxCollider {
        id: collider
        anchors.fill: parent
        bodyType: Body.Static

        fixture.onBeginContact: {
            var otherEntity = other.getBody().target
            if(otherEntity.entityType === "player") {
                console.debug("contact platform begin")


                player.contacts++
            }
        }

        fixture.onEndContact: {
            var otherEntity = other.getBody().target
            if(otherEntity.entityType === "player") {
                console.debug("contact platform end")

                player.contacts--
            }
        }
    }
}
