#include "../inc/MainApplication.h"

MainApplication::MainApplication(QQmlApplicationEngine *engine) :
    _engine(engine),
    _modelApplication(),
    _databaseApplication(&_modelApplication)
{
    connect(&_databaseApplication, SIGNAL(changeLoginState(bool)), this, SLOT(setIsLogged(bool)));
    connect(&_databaseApplication, SIGNAL(changeSignUpState(bool)), this, SLOT(setIsSignUp(bool)));
    connect(&_databaseApplication, SIGNAL(changeCheckLoginState(bool)), this, SLOT(setLoginState(bool)));
    connect(&_databaseApplication, SIGNAL(changeAccountState(bool)), this, SLOT(setAccountChangeState(bool)));
}

ModelApplication *MainApplication::modelApplication()
{
    return &_modelApplication;
}

DatabaseApplication *MainApplication::databaseApplication()
{
    return &_databaseApplication;
}

void MainApplication::setIsLogged(bool state)
{
    _isConnected = state;
    emit changeLoginState();
}

void MainApplication::setIsSignUp(bool isSignUp)
{
    _isSignUp = isSignUp;
    emit changeSignUpState();
}

void MainApplication::setLoginState(bool loginState)
{
    _loginState = loginState;
    emit changeCheckLoginState();
}

bool MainApplication::accountChangeState() const
{
    return _accountChangeState;
}

void MainApplication::setAccountChangeState(bool accountChangeState)
{
    _accountChangeState = accountChangeState;
    emit changeAccountState();
}


bool MainApplication::isSignUp() const
{
    return _isSignUp;
}

bool MainApplication::loginState() const
{
    return _loginState;
}

void MainApplication::login(const QString &login, const QString &password)
{
    _databaseApplication.userDAO()->connect(login, password);
}

void MainApplication::signUp(const QString &login, const QString &mail, const QString &firstName, const QString &password,const QDate &birthdate)
{
    QJsonObject user;
    user["login"] = login;
    user["mail"] = mail;
    user["firstname"] = firstName;
    user["password"] = password;
    user["birthdate"] = birthdate.toString("yyyy-MM-dd")+"T00:00:08Z";

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    _databaseApplication.userDAO()->signUp(bytes);
}

void MainApplication::checkLogin(const QString &login)
{
    qDebug() << "login " << login;
    QJsonObject user;
    user["login"] = login;

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    _databaseApplication.userDAO()->checkLoginState(bytes);
}

void MainApplication::changeAccount(const QString &login, const QString &mail, const QString &firstName, const QString &password)
{
    QJsonObject user;

    if(!login.isNull() && !login.isEmpty() && login.size() > 3)
    {
        user["login"] = login;
    }
    else
    {
        user["login"] = _modelApplication.user()->login();
    }
    if(!mail.isNull() && !mail.isEmpty() && mail.size() > 3)
    {
        user["mail"] = mail;
    }
    else
    {
        user["mail"] = _modelApplication.user()->mail();
    }
    if(!firstName.isNull() && !firstName.isEmpty() && firstName.size() > 3)
    {
        user["firstname"] = firstName;
    }
    else
    {
        user["firstname"] = _modelApplication.user()->firstname();
    }
    if(!password.isNull() && !password.isEmpty() && password.size() > 3)
    {
        user["password"] = password;
    }
    else
    {
        user["password"] = _modelApplication.user()->password();
    }
    user["id"] = _modelApplication.user()->ID();

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    _databaseApplication.userDAO()->changeAccount(bytes);
}

void MainApplication::getGlobalScore()
{
    _databaseApplication.scoreDAO()->getGlobalScore();
}

void MainApplication::getPersonalScore()
{
    _databaseApplication.scoreDAO()->getPersonalScore();
}

bool MainApplication::isConnected() const
{
    return _isConnected;
}
