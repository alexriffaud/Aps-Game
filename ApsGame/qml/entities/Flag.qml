import QtQuick 2.0
import Felgo 3.0

EntityBase {
    entityId: flag
    entityType: "flag"
    height: 100
    width: 31

    signal endGame()

    MultiResolutionImage {
        source: "../../assets/img/flag.png"
    }

    BoxCollider {
        id: collider
        height: parent.height
        width: 30
        bodyType: Body.Static
        fixedRotation: true
        bullet: true
        sleepingAllowed: false

        fixture.onBeginContact: {
            var collidedEntity = other.getBody().target;
            var otherEntityId = collidedEntity.entityId;
            var otherEntityParent = collidedEntity.parent;



            // check if it hit a player
            if (otherEntityId.substring(0, 4) === "play") {
                collidedEntity.takeObject()
                flag.endGame()
            }
        }
    }

}
