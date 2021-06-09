#include "../../inc/obj/Score.h"

Score::Score()
{

}

Score::Score(int id, int score, QString user) :
    _ID(id),
    _score(score),
    _user(user)
{

}

int Score::ID() const
{
    return _ID;
}

void Score::setID(int ID)
{
    _ID = ID;
}

int Score::score() const
{
    return _score;
}

void Score::setScore(int score)
{
    _score = score;
}

QString Score::user() const
{
    return _user;
}

void Score::setUser(const QString &user)
{
    _user = user;
}
