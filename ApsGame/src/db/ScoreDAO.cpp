#include "../../inc/db/ScoreDAO.h"

ScoreDAO::ScoreDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address, Request *request) :
    _modelApplication(modelApplication),
    _manager(manager),
    _address(address),
    _requestNum(request)
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
        QJsonArray jsonArray = jsonDoc.array();

        foreach (const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();

            QString dateString = obj["date"].toString().split("T")[0];
            QDate date = QDate(dateString.split("-")[0].toInt(),dateString.split("-")[1].toInt(),dateString.split("-")[2].toInt());

            QJsonObject user = obj["user"].toObject();

            _modelApplication->globalScoreList()->insert(new Score(obj["id"].toInt(),
                                                         obj["score"].toInt(),
                                                         user["login"].toString(),
                                                         date.toString("dd/MM/yyyy")));

            qDebug() << "insert new score";

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

    QJsonObject scoreJSON;
    scoreJSON["id"] = _modelApplication->user()->ID();


    _request.setUrl(QUrl(_address + "/personalscore?id="+QString::number( _modelApplication->user()->ID())));

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
        QJsonValue projects = object.value("score");
        QJsonArray jsonArray = projects.toArray();

        foreach (const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();

            QString dateString = obj["date"].toString().split("T")[0];
            QDate date = QDate(dateString.split("-")[0].toInt(),dateString.split("-")[1].toInt(),dateString.split("-")[2].toInt());

            QJsonObject user = obj["user"].toObject();

            _modelApplication->globalScoreList()->insert(new Score(obj["id"].toInt(),
                                                         obj["score"].toInt(),
                                                         user["login"].toString(),
                                                         date.toString("dd/MM/yyyy")));

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

void ScoreDAO::saveScore(int score)
{
    *_requestNum = Request::SAVE_SCORE;

    const QByteArray basic_authorization = _token.toUtf8();
    _request.setRawHeader(QByteArrayLiteral("Authorization"), "Bearer "+basic_authorization);

    qDebug() << _token;

    _request.setUrl(QUrl(_address + "/savescore"));
    _request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    Tools::setSSLConfiguration(&_request);

    QJsonObject scoreJSON;
    scoreJSON["score"] = score;
    scoreJSON["date"] = QDate::currentDate().toString("yyyy-MM-dd")+"T00:00:08Z";
    QJsonObject user;
    user["id"] = _modelApplication->user()->ID();
    scoreJSON.insert("user", user);

    QJsonDocument doc(scoreJSON);
    QByteArray bytes = doc.toJson();
    _manager->post(_request, bytes);
}

bool ScoreDAO::parseSaveScore(QNetworkReply *reply)
{
    qDebug() << "ScoreDAO::parseSaveScore";

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
