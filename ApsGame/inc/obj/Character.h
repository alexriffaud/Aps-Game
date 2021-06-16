#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = nullptr);
    explicit Character(int id, int life, int attack, int armor, QString name, QObject *parent = nullptr);

    int ID() const;
    QString name() const;
    int life() const;
    int armor() const;
    int attack() const;

protected:
    int         _ID;
    QString     _name;
    int         _life;
    int         _armor;
    int         _attack;

};

#endif // CHARACTER_H
