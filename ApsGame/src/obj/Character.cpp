#include "../../inc/obj/Character.h"

Character::Character(QObject *parent) : QObject(parent)
{

}

Character::Character(int id, int life, int attack, int armor, QString name, QObject *parent) : QObject(parent),
    _ID(id),
    _name(name),
    _life(life),
    _armor(armor),
    _attack(attack)
{
}

int Character::ID() const
{
    return _ID;
}

QString Character::name() const
{
    return _name;
}

int Character::life() const
{
    return _life;
}

int Character::armor() const
{
    return _armor;
}

int Character::attack() const
{
    return _attack;
}
