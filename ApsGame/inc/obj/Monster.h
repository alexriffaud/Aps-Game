#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character
{
public:
    Monster();
    explicit Monster(int id, int life, int attack, int armor, QString name, QObject *parent = nullptr);
};

#endif // MONSTER_H
