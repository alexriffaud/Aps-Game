import QtQuick 2.0
import Felgo 3.0

EntityBase {

    id: bulletEntity
    entityType: "bullet"
    x: start.x
    y: start.y

    property point start
    property point velocity
    property int bulletType // 0 normal bullet, 1 strong bullet

    MultiResolutionImage {
        id: shoot
        source: "../../assets/img/shoot.png"
    }

    BoxCollider {
        id: boxCollider
        width: 10
        height: 10
        anchors.fill: parent
        collisionTestingOnlyMode: true
        density: 0
        friction: 0
        restitution: 0
        body.bullet: true
        body.fixedRotation: false // if set to true the physics engine will NOT apply rotation to it

        fixture.onBeginContact: {
            var collidedEntity = other.getBody().target;
            var otherEntityId = collidedEntity.entityId;
            var otherEntityParent = collidedEntity.parent;

            if (otherEntityId.substring(0, 3) !== "lak" && otherEntityId.substring(0, 3) !== "pow") {
                bulletEntity.destroy();

                // show a splat image for a certain amount of time after removing the bullet
                entityManager.createEntityFromUrlWithProperties(
                            Qt.resolvedUrl("Splat.qml"), {
                                "z": 1,
                                "x": bulletEntity.x,
                                "y": bulletEntity.y,
                                "rotation": bulletEntity.rotation
                            }
                            );

//                // check if it hit a player
//                if (otherEntityId.substring(0, 4) === "tank") {
//                    // call damage method on playerred/playerblue
//                    otherEntityParent.onDamageWithBulletType(bulletType);
//                }

            }
        }
    }

    // animate the bullet along its x-axis
    MovementAnimation {
      target: bulletEntity
      property: "x"
      velocity: bulletEntity.velocity.x
      running: true
    }
}
