#include "../../inc/db/ScoreDAO.h"

ScoreDAO::ScoreDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address) :
    _modelApplication(modelApplication),
    _manager(manager),
    _address(address)
{

}

void ScoreDAO::getGlobalScore()
{
    qDebug() << "ScoreDAO::getGlobalScore";

    *_requestNum = Request::GLOBAL_SCORE;

    Tools::setSSLConfiguration(&_request);

    const QByteArray basic_authorization = _token.toUtf8();

    _request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);
    _request.setUrl(QUrl(_address + "/globalscore"));

    _manager->get(_request);
}

bool ScoreDAO::parseGlobalScore(QNetworkReply *reply)
{
    qDebug() << "ScoreDAO::parseGlobalScore";

    _modelApplication->globalScoreList()->removeAll();
    bool result = false;

    int statusCode = Tools::parseStatus(reply);
    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = Tools::redirection(reply, *_requestNum, _manager);
    }
    else if((statusCode == 403) || (statusCode == 404))
    {
        result = Tools::showError(reply);
        emit letsDisconnect();
    }
    else if(statusCode == 200)
    {
        qDebug() << "Parse data " <<  data;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject object = jsonDoc.object();
        QJsonValue projects = object.value("features");
        QJsonArray jsonArray = projects.toArray();

        foreach (const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();

            _modelApplication->globalScoreList()->insert(new Score(obj["id"].toInt(),
                                                         obj["state"].toInt(),
                                                         obj["user"].toString()));

        }

        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();
    return result;
}

void ScoreDAO::getPersonalScore()
{
    qDebug() << "ScoreDAO::getGlobalScore";

    *_requestNum = Request::PERSONAL_SCORE;

    Tools::setSSLConfiguration(&_request);

    const QByteArray basic_authorization = _token.toUtf8();

    _request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);
    _request.setUrl(QUrl(_address + "/personalscore"));

    _manager->get(_request);
}

bool ScoreDAO::parsePersonalScore(QNetworkReply *reply)
{
    qDebug() << "ScoreDAO::parsePersonalScore";

    _modelApplication->user()->personalScoreList()->removeAll();
    bool result = false;

    int statusCode = Tools::parseStatus(reply);
    QString data = reply->readAll();

    if(statusCode == 302)
    {
        result = Tools::redirection(reply, *_requestNum, _manager);
    }
    else if((statusCode == 403) || (statusCode == 404))
    {
        result = Tools::showError(reply);
        emit letsDisconnect();
    }
    else if(statusCode == 200)
    {
        qDebug() << "Parse data " <<  data;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject object = jsonDoc.object();
        QJsonValue projects = object.value("features");
        QJsonArray jsonArray = projects.toArray();

        foreach (const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();

            _modelApplication->user()->personalScoreList()->insert(new Score(obj["id"].toInt(),
                                                     obj["state"].toInt(),
                                                     obj["user"].toString()));

        }

        result = true;
    }
    else
    {
        result = false;
    }

    reply->deleteLater();
    return result;
}

void ScoreDAO::setToken(const QString &token)
{
    _token = token;
}

void ScoreDAO::setRequestNum(Request *requestNum)
{
    _requestNum = requestNum;
}
