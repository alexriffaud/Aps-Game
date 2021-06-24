#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDate>
#include <QString>
#include <QList>

#include "Score.h"
#include "ScoreList.h"

/**
 * @brief The User class
 */
class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString loginUser MEMBER _login)

public:
    /**
     * @brief User
     */
    User();
    /**
     * @brief User
     * @param login
     */
    User(QString login);

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
     * @brief login
     * @return
     */
    Q_INVOKABLE QString login() const;
    void setLogin(const QString &login);

    /**
     * @brief isLogged
     * @return
     */
    int isLogged() const;
    /**
     * @brief setIsLogged
     * @param isLogged
     */
    void setIsLogged(int isLogged);

    /**
     * @brief firstname
     * @return
     */
    Q_INVOKABLE QString firstname() const;
    /**
     * @brief setFirstname
     * @param firstname
     */
    void setFirstname(const QString &firstname);

    /**
     * @brief mail
     * @return
     */
    Q_INVOKABLE QString mail() const;
    /**
     * @brief setMail
     * @param mail
     */
    void setMail(const QString &mail);

    /**
     * @brief password
     * @return
     */
    Q_INVOKABLE QString password() const;
    /**
     * @brief setPassword
     * @param password
     */
    void setPassword(const QString &password);

    /**
     * @brief birthdate
     * @return
     */
    Q_INVOKABLE QDate birthdate() const;
    /**
     * @brief setBirthdate
     * @param birthdate
     */
    void setBirthdate(const QDate &birthdate);

private:
    int     _ID; /*!< ID */
    QString _login; /*!< Login */
    int     _isLogged; /*!< Login state */
    QString _firstname; /*!< First name */
    QString _mail; /*!< Mail */
    QString _password; /*!< Password */
    QDate _birthdate; /*!< Birth date */
};
#endif // USER_H
