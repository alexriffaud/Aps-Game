import QtQuick 2.0
import Felgo 3.0

EntityBase {

    id: bulletEntity
    entityType: "bullet"
    x: start.x
    y: start.y
    width: 17
    height: 17

    property point start
    property point velocity
    property int bulletType // 0 normal bullet, 1 strong bullet

    MultiResolutionImage {
        source: "../../assets/img/shoot.png"
        width: parent.width
        height: parent.height
        x: boxCollider.x
        y: boxCollider.y
    }

    BoxCollider {
        id: boxCollider
        width: parent.width
        height: parent.height
        collisionTestingOnlyMode: true
        bodyType: Body.Dynamic
        fixedRotation: true
        bullet: true
        sleepingAllowed: false
        density: 0
        friction: 0
        restitution: 0

        fixture.onBeginContact: {
            var collidedEntity = other.getBody().target;
            var otherEntityId = collidedEntity.entityId;
            var otherEntityParent = collidedEntity.parent;
            console.log(collidedEntity)
            bulletEntity.destroy();
            if (otherEntityId.substring(0, 3) !== "lak" && otherEntityId.substring(0, 3) !== "pow") {

                // show a splat image for a certain amount of time after removing the bullet
                entityManager.createEntityFromUrlWithProperties(
                            Qt.resolvedUrl("Splat.qml"), {
                                "z": 1,
                                "x": bulletEntity.x,
                                "y": bulletEntity.y,
                                "rotation": bulletEntity.rotation
                            }
                            );

                // check if it hit a monster
                if (otherEntityId.substring(0, 4) === "mons") {
                    // call damage method on playerred/playerblue
                    collidedEntity.onDamageWithBullet(otherEntityId);
                }

            }
        }
    }

    // animate the bullet along its x-axis
    MovementAnimation {
      target: bulletEntity
      property: "x"
      velocity: 160
      running: true
    }
}
