#include "../../inc/obj/Player.h"

Player::Player()
{

}

Player::Player(int id, int life, int attack, int armor, QString name, Weapon *weapon, QObject *parent):
    Character(id, life, attack, armor, name, parent),
    _weapon(weapon)
{

}

Weapon *Player::weapon()
{
    return _weapon;
}

void Player::setWeapon(Weapon *weapon)
{
    _weapon = weapon;
}
