#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "ModelApplication.h"
#include "DatabaseApplication.h"

class MainApplication : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool _isConnected MEMBER _isConnected NOTIFY changeLoginState)
    Q_PROPERTY(bool _isSignUp MEMBER _isSignUp NOTIFY changeSignUpState)
    Q_PROPERTY(bool _loginState MEMBER _loginState NOTIFY changeCheckLoginState)
    Q_PROPERTY(bool _accountChangeState MEMBER _loginState NOTIFY changeAccountState)

public:
    MainApplication(QQmlApplicationEngine *engine);

    ModelApplication *modelApplication();
    DatabaseApplication *databaseApplication();

    Q_INVOKABLE void login(const QString &login, const QString &password);
    Q_INVOKABLE void signUp(const QString &login, const QString &mail, const QString &firstName, const QString &password, const QDate &birthdate);
    Q_INVOKABLE void checkLogin(const QString &login);
    Q_INVOKABLE void changeAccount(const QString &login, const QString &mail, const QString &firstName, const QString &password);
    Q_INVOKABLE void getGlobalScore();
    Q_INVOKABLE void getPersonalScore();

    Q_INVOKABLE bool isConnected() const;
    Q_INVOKABLE bool isSignUp() const;
    Q_INVOKABLE bool loginState() const;
    Q_INVOKABLE bool accountChangeState() const;

signals:
    void changeLoginState();
    void changeSignUpState();
    void changeCheckLoginState();
    void changeAccountState();

private slots:
    void setIsLogged(bool state);
    void setIsSignUp(bool isSignUp);
    void setLoginState(bool loginState);
    void setAccountChangeState(bool accountChangeState);

private:
    QQmlApplicationEngine   *_engine;
    ModelApplication        _modelApplication;
    DatabaseApplication     _databaseApplication;

    //State
    bool                    _isConnected = false;
    bool                    _isSignUp = false;
    bool                    _loginState = false;
    bool                    _accountChangeState = false;
};

#endif // MAINAPPLICATION_H
