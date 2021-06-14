#include "../../inc/db/UserDAO.h"

UserDAO::UserDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address, Request *request) :
    _modelApplication(modelApplication),
    _manager(manager),
    _address(address),
    _requestNum(request)
{

}

void UserDAO::connect(QString name, QString password)
{
    qDebug() << "UserDAO::connect "+ _address + "/login";
    *_requestNum = Request::CONNECT;
    _username = name;
    _password = password;

    _request.setUrl(QUrl(_address + "/login"));
    _request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    Tools::setSSLConfiguration(&_request);

    QJsonObject recordObject;
    recordObject.insert("login", QJsonValue::fromVariant(name));
    recordObject.insert("password", QJsonValue::fromVariant(password));

    QJsonDocument doc(recordObject);
    QByteArray bytes = doc.toJson();

    _manager->post(_request, bytes);
}

bool UserDAO::parseConnect(QNetworkReply *reply)
{
    qDebug() << "UserDAO::connectParser";

    bool result = false;

    int statusCode = Tools::parseStatus(reply);

    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = Tools::redirection(reply, *_requestNum, _manager);
    }
    else if((statusCode == 403) || (statusCode == 404)|| (statusCode == 500))
    {
        result = Tools::showError(reply);
    }
    else if(data.size() > 1)
    {
        _token = data.split(";")[0];

        //Set token and requestNum in DAOs here
        _modelApplication->user()->setLogin(_username);
        _modelApplication->user()->setPassword(_password);
        _modelApplication->user()->setFirstname(data.split(";")[2]);
        _modelApplication->user()->setMail(data.split(";")[3]);
        QString dateString = data.split(";")[4].split("T")[0];
        QDate date = QDate(dateString.split("-")[0].toInt(),dateString.split("-")[1].toInt(),dateString.split("-")[2].toInt());
        _modelApplication->user()->setBirthdate(date);
        _modelApplication->user()->setID(data.split(";")[1].toInt());
        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();

    return result;
}

void UserDAO::signUp(QByteArray bytes)
{
    qDebug() << "UserDAO::signUp " << bytes;
    *_requestNum = Request::SIGNUP;

    QUrl url(_address + "/signup");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(onResult(QNetworkReply*)));

    manager->post(request, bytes);
}

bool UserDAO::parseSignUp(QNetworkReply *reply)
{
    bool result = false;

    int statusCode = Tools::parseStatus(reply);

    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = Tools::redirection(reply, *_requestNum, _manager);
    }
    else if((statusCode == 403) || (statusCode == 404)|| (statusCode == 500))
    {
        result = Tools::showError(reply);
    }
    else if(statusCode == 201)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();

    return result;
}

void UserDAO::checkLoginState(QByteArray bytes)
{
    qDebug() << "UserDAO::checkLoginState " << bytes;
    *_requestNum = Request::LOGIN_STATE;

    QUrl url(_address + "/checklogin");
    QNetworkRequest request(url);
    qDebug() << _token;
    const QByteArray basic_authorization = _token.toUtf8();

    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(onResult(QNetworkReply*)));

    manager->post(request, bytes);
}

bool UserDAO::parseLoginState(QNetworkReply *reply)
{
    bool result = false;

    int statusCode = Tools::parseStatus(reply);

    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = false;
    }
    else if((statusCode == 403) || (statusCode == 404)|| (statusCode == 500))
    {
        result = Tools::showError(reply);
    }
    else if(statusCode == 200)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();

    return result;
}

void UserDAO::changeAccount(QByteArray bytes)
{
    qDebug() << "UserDAO::changeAccount " << bytes;
    *_requestNum = Request::CHANGE_ACCOUNT;

    QUrl url(_address + "/updateAccount");
    QNetworkRequest request(url);
    const QByteArray basic_authorization = _token.toUtf8();

    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(onResult(QNetworkReply*)));

    manager->put(request, bytes);
}

bool UserDAO::parseChangeAccount(QNetworkReply *reply)
{
    bool result = false;

    int statusCode = Tools::parseStatus(reply);

    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = false;
    }
    else if((statusCode == 403) || (statusCode == 404)|| (statusCode == 500))
    {
        result = Tools::showError(reply);
    }
    else if(statusCode == 200)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();

    return result;
}

void UserDAO::setToken(const QString &token)
{
    _token = token;
}

void UserDAO::setRequestNum(Request *requestNum)
{
    _requestNum = requestNum;
}

QString UserDAO::token() const
{
    return _token;
}
