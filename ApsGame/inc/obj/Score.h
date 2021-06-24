#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QDate>

/**
 * @brief The Score class
 */
class Score :  public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id MEMBER _ID)
    Q_PROPERTY(int score MEMBER _score)
    Q_PROPERTY(QString user MEMBER _user)
    Q_PROPERTY(QString date MEMBER _date)

public:
    /**
     * @brief Score
     */
    Score();
    /**
     * @brief Score
     * @param id
     * @param score
     * @param user
     * @param date
     */
    Score(int id, int score, QString user, QString date);

    /**
     * @brief ID
     * @return
     */
    int ID() const;
    /**
     * @brief setID
     * @param ID
     */
    void setID(int ID);

    /**
     * @brief score
     * @return
     */
    int score() const;
    /**
     * @brief setScore
     * @param score
     */
    void setScore(int score);

    /**
     * @brief user
     * @return
     */
    QString user() const;
    /**
     * @brief setUser
     * @param user
     */
    void setUser(const QString &user);

    /**
     * @brief date
     * @return
     */
    QString date() const;
    /**
     * @brief setDate
     * @param date
     */
    void setDate(const QString &date);

private:
    int     _ID; /*!< ID  */
    int     _score; /*!< Score */
    QString _user; /*!< User's login */
    QString   _date; /*!< Date */
};

Q_DECLARE_METATYPE(Score *)

#endif // SCORE_H
