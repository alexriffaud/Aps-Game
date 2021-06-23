#include "tst_testscoredao.h"
#include "TestTools.h"

TestScoreDAO::TestScoreDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestScoreDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestScoreDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->databaseApplication()->scoreDAO());

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

void TestScoreDAO::getGlobalScore()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/globalscore");
    QNetworkRequest request(url);

    Tools::setSSLConfiguration(&request);
    const QByteArray basic_authorization = _token.toUtf8();
    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.get(request);
}

void TestScoreDAO::getPersonalScore()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame//personalscore?id=1");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    const QByteArray basic_authorization = _token.toUtf8();
    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.get(request);
}

void TestScoreDAO::saveScore()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/savescore");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    const QByteArray basic_authorization = _token.toUtf8();
    request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    QJsonObject scoreJSON;
    scoreJSON["score"] = 100;
    scoreJSON["date"] = QDate::currentDate().toString("yyyy-MM-dd")+"T00:00:08Z";
    QJsonObject user;
    user["id"] = 1;
    scoreJSON.insert("user", user);

    QJsonDocument doc(scoreJSON);
    QByteArray bytes = doc.toJson();

    QNetworkAccessManager manager;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);
}
