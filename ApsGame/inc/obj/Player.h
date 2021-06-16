#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Weapon.h"

class Player : public Character
{
public:
    Player();
    explicit Player(int id, int life, int attack, int armor, QString name, Weapon *weapon, QObject *parent = nullptr);

    Weapon *weapon();
    void setWeapon(Weapon *weapon);

private:
    Weapon  *_weapon;
};

#endif // PLAYER_H
