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
    }

    BoxCollider {
        id: boxCollider
        anchors.fill: parent
        collisionTestingOnlyMode: true
        bodyType: Body.Dynamic
        fixedRotation: true
        bullet: true
        sleepingAllowed: false
//        bodyType: Body.Dynamic
//        density: 0
//        friction: 0
//        restitution: 0
//        body.fixedRotation: false // if set to true the physics engine will NOT apply rotation to it

        fixture.onBeginContact: {
            var collidedEntity = other.getBody().target;
            var otherEntityId = collidedEntity.entityId;
            var otherEntityParent = collidedEntity.parent;

            console.log("hit")
            console.log(otherEntityId)
            bulletEntity.destroy();
            if (otherEntityId.substring(0, 3) !== "lak" && otherEntityId.substring(0, 3) !== "pow") {

                console.log(otherEntityId.substring(0, 4))

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
                if (otherEntityId.substring(0, 4) === "mons") {
                    // call damage method on playerred/playerblue
                    collidedEntity.onDamageWithBullet();
                }

            }
        }
    }

    // animate the bullet along its x-axis
    MovementAnimation {
      target: bulletEntity
      property: "x"
      velocity: 120
      running: true
    }
}
