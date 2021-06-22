import QtQuick 2.0
import Felgo 3.0

EntityBase {

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
            if (otherEntityId.substring(0, 3) === "pla") {
                collidedEntity.takeDamage()
            }
        }
    }

    // animate the bullet along its x-axis
     SequentialAnimation  {
         id : movementAnimation
         running: false
         loops: Animation.Infinite
         NumberAnimation { target: monster; property: "x"; to: monster.x +20; duration: 1000 }
         NumberAnimation { target: monster; property: "x"; to: monster.x - 10; duration: 1000 }
     }



    function onDamageWithBullet()
    {
        life = life-50

        if(life < 0)
        {
            monster.monsterKilled()
            monster.destroy()
        }
    }
}
