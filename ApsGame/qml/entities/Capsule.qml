import QtQuick 2.0
import Felgo 3.0

EntityBase {
    id: capsuleEntity
    entityId: capsule
    entityType: "capsule"
    height: 30
    width: 30

    signal itemTaken()

    MultiResolutionImage {
        source: "../../assets/img/capsule.png"
    }

    BoxCollider {
        id: collider
        height: parent.height
        width: 30
        bodyType: Body.Dynamic
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
                capsuleEntity.itemTaken()
                capsuleEntity.destroy();
            }
        }
    }
}
