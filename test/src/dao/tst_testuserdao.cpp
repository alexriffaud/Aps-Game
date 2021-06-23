#include "tst_testuserdao.h"

TestUserDAO::TestUserDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestUserDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestUserDAO::initTestCase()
{
    qInstallMessageHandler(output);
        QVERIFY(_mainApp->databaseApplication()->userDAO());
}

void TestUserDAO::connect()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/login");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QJsonObject recordObject;
    recordObject.insert("login", QJsonValue::fromVariant("test"));
    recordObject.insert("password", QJsonValue::fromVariant("test"));

    QJsonDocument doc(recordObject);
    QByteArray bytes = doc.toJson();

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [this](QNetworkReply* st)
    {
        QString data = st->readAll();
        _token = data.split(";")[0];
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);
}

void TestUserDAO::changeAccount()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/updateAccount");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    const QByteArray basic_authorization = _token.toUtf8();
    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    QJsonObject user;
    QString login = "test";
    QString mail = "test";
    QString firstName = "test";
    QString password = "test";

    user["login"] = login;
    user["mail"] = mail;
    user["firstname"] = firstName;
    user["password"] = password;
    user["id"] = _mainApp->modelApplication()->user()->ID();

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);
}

void TestUserDAO::signUp()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/signup");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QJsonObject user;
    QString login = "test";
    QString mail = "test";
    QString firstName = "test";
    QString password = "test";

    user["login"] = login;
    user["mail"] = mail;
    user["firstname"] = firstName;
    user["password"] = password;

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);
}

void TestUserDAO::checkLoginState()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/signup");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    const QByteArray basic_authorization = _token.toUtf8();
    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    QJsonObject user;
    QString login = "test";
    user["login"] = login;

    QJsonDocument doc(user);
    QByteArray bytes = doc.toJson();

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);
}
