#include "TestTools.h"

TestTools::TestTools(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestTools::initTestCase()
{
    qInstallMessageHandler(output);
}

void TestTools::rowCount()
{
//    Score *score = new Score();
//    Score *score2 = new Score();
//    _mainApp->modelApplication()->globalScoreList()->insert(score);
//    _mainApp->modelApplication()->globalScoreList()->insert(score2);

//    QCOMPARE(_mainApp->modelApplication()->globalScoreList()->rowCount(QModelIndex()), 0);

//    _mainApp->modelApplication()->globalScoreList()->removeAll();

//    score= nullptr;
//    score2 = nullptr;
}

void TestTools::findObject()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    QVERIFY(_mainApp->modelApplication()->globalScoreList()->at(1));
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
}

void TestTools::data()
{
//    Score *score = new Score();
//    _mainApp->modelApplication()->globalScoreList()->insert(score);
//    QVERIFY(!_mainApp->modelApplication()->globalScoreList()->data(QModelIndex(), Qt:: DisplayRole).isNull());
//    _mainApp->modelApplication()->globalScoreList()->removeAll();
//    score = nullptr;
}

void TestTools::items()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    QVERIFY(_mainApp->modelApplication()->globalScoreList()->items());
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
}

void TestTools::insert()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    QVERIFY(_mainApp->modelApplication()->globalScoreList()->at(0));
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
}

void TestTools::remove()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    Score *score2 = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score2);
    _mainApp->modelApplication()->globalScoreList()->remove(score);
    score = nullptr;

    QCOMPARE(_mainApp->modelApplication()->globalScoreList()->at(1), score);

    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score2 = nullptr;
}

void TestTools::removeAll()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    QCOMPARE(_mainApp->modelApplication()->globalScoreList()->size(), 0);
    score = nullptr;
}

void TestTools::updateItem()
{
//    Score::Score(int id, int score, QString user, QString date) :
    Score *score = new Score(1, 100, "user", QDate::currentDate().toString());
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    Score *score2 = new Score(1, 100, "test", QDate::currentDate().toString());
    score->setUser("test");

    _mainApp->modelApplication()->globalScoreList()->updateItem(score2);

//    QCOMPARE("user", static_cast<Score*>(_mainApp->modelApplication()->globalScoreList()->findObject(0))->user());
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
    score2 = nullptr;
}

void TestTools::clear()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    _mainApp->modelApplication()->globalScoreList()->clear();
    QCOMPARE(_mainApp->modelApplication()->globalScoreList()->size(), 0);
    score = nullptr;
}

void TestTools::size()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);

    QCOMPARE(_mainApp->modelApplication()->globalScoreList()->size(), 1);

    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
}

void TestTools::at()
{
    Score *score = new Score();
    _mainApp->modelApplication()->globalScoreList()->insert(score);
    QVERIFY(_mainApp->modelApplication()->globalScoreList()->at(0));
    _mainApp->modelApplication()->globalScoreList()->removeAll();
    score = nullptr;
}

void TestTools::setSSLConfiguration()
{
    QUrl url("http://env-1021880.hidora.com/api/v1/apsgame/signup");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Tools::setSSLConfiguration(&request);

    QCOMPARE(request.sslConfiguration().protocol(), QSsl::AnyProtocol);
    QCOMPARE(request.sslConfiguration().peerVerifyMode(), QSslSocket::QueryPeer);
}

void TestTools::parseStatus()
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
    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply* st)
    {
        QCOMPARE(200, Tools::parseStatus(st));
    });

    manager.post(request, bytes);

}

void TestTools::redirection()
{

}

void TestTools::showError()
{

}

void TestTools::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}


