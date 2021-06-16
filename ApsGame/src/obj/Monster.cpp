#include "../../inc/obj/Monster.h"

Monster::Monster()
{

}

Monster::Monster(int id, int life, int attack, int armor, QString name, QObject *parent) :
    Character(id, life, attack, armor, name, parent)
{

}
