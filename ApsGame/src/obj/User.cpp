#include "../../inc/obj/User.h"

User::User()
{

}

User::User(QString login)
{
    _login = login;
}

int User::ID() const
{
    return _ID;
}

void User::setID(int ID)
{
    _ID = ID;
}

QString User::login() const
{
    return _login;
}

void User::setLogin(const QString &login)
{
    _login = login;
}

int User::isLogged() const
{
    return _isLogged;
}

void User::setIsLogged(int isLogged)
{
    _isLogged = isLogged;
}

QString User::firstname() const
{
    return _firstname;
}

void User::setFirstname(const QString &firstname)
{
    _firstname = firstname;
}

QString User::mail() const
{
    return _mail;
}

void User::setMail(const QString &mail)
{
    _mail = mail;
}

QString User::password() const
{
    return _password;
}

void User::setPassword(const QString &password)
{
    _password = password;
}

QDate User::birthdate() const
{
    return _birthdate;
}

void User::setBirthdate(const QDate &birthdate)
{
    _birthdate = birthdate;
}

ScoreList *User::personalScoreList()
{
    return &_personalScoreList;
}
