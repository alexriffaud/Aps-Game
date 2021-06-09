#ifndef SCORE_H
#define SCORE_H

#include <QObject>

class Score :  public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id MEMBER _ID)
    Q_PROPERTY(int score MEMBER _score)
    Q_PROPERTY(QString user MEMBER _user)

public:
    Score();
    Score(int id, int score, QString user);

    int ID() const;
    void setID(int ID);

    int score() const;
    void setScore(int score);

    QString user() const;
    void setUser(const QString &user);

private:
    int     _ID;
    int     _score;
    QString _user;
};

#endif // SCORE_H
