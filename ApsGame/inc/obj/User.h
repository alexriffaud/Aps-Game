#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDate>
#include <QString>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString loginUser MEMBER _login)

public:
    User();
    User(QString login);

    int ID() const;
    void setID(int ID);

    Q_INVOKABLE QString login() const;
    void setLogin(const QString &login);

    int isLogged() const;
    void setIsLogged(int isLogged);

    Q_INVOKABLE QString firstname() const;
    void setFirstname(const QString &firstname);

    Q_INVOKABLE QString mail() const;
    void setMail(const QString &mail);

    Q_INVOKABLE QString password() const;
    void setPassword(const QString &password);

    Q_INVOKABLE QDate birthdate() const;
    void setBirthdate(const QDate &birthdate);

private:
    int     _ID;
    QString _login;
    int     _isLogged;
    QString _firstname;
    QString _mail;
    QString _password;
    QDate _birthdate;
};
#endif // USER_H
