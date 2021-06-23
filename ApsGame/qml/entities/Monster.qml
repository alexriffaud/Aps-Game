import QtQuick 2.0
import Felgo 3.0

EntityBase {
    id: monsterEntity
    entityId: monster
    entityType: "monster"
    width: 50
    height: 50

    property alias collider: collider
    property alias movementAnimation: movementAnimation
    property alias horizontalVelocity: collider.linearVelocity.x
    property int contacts: 0
    property int life : 100
    property int armor : 20
    property int attack : 20

    signal monsterKilled()

    MultiResolutionImage {
        source: "../../assets/img/monster/monster.png"
    }

    BoxCollider {
        id: collider
        height: parent.height
        width: 30
        anchors.horizontalCenter: parent.horizontalCenterss
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
                collidedEntity.takeDamage()
            }
        }
    }

    // animate the bullet along its x-axis
     SequentialAnimation  {
         id : movementAnimation
         running: false
         loops: Animation.Infinite
         NumberAnimation { target: monsterEntity; property: "x"; to: monsterEntity.x +20 +Math.ceil(Math.random() * 5); duration: 1000 }
         NumberAnimation { target: monsterEntity; property: "x"; to: monsterEntity.x - 10-Math.ceil(Math.random() * 5); duration: 1000 }
     }



    function onDamageWithBullet(otherEntityId)
    {
        if(otherEntityId === monsterEntity.entityId)
        {
            life = life-50

            if(life < 0)
            {
                monsterEntity.monsterKilled()
                monsterEntity.destroy()
            }
        }
    }
}
