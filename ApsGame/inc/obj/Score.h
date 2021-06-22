#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QDate>

class Score :  public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id MEMBER _ID)
    Q_PROPERTY(int score MEMBER _score)
    Q_PROPERTY(QString user MEMBER _user)
    Q_PROPERTY(QString date MEMBER _date)

public:
    Score();
    Score(int id, int score, QString user, QString date);

    int ID() const;
    void setID(int ID);

    int score() const;
    void setScore(int score);

    QString user() const;
    void setUser(const QString &user);

    QString date() const;
    void setDate(const QString &date);

private:
    int     _ID;
    int     _score;
    QString _user;
    QString   _date;
};

Q_DECLARE_METATYPE(Score *)

#endif // SCORE_H
