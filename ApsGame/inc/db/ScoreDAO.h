#ifndef SCOREDAO_H
#define SCOREDAO_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>

#include "ModelApplication.h"
#include "Enums.h"
#include "Tools.h"

class ScoreDAO : public QObject
{
    Q_OBJECT
public:
    ScoreDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address, Request *request);

    void getGlobalScore();
    bool parseGlobalScore(QNetworkReply *reply);

    void getPersonalScore();
    bool parsePersonalScore(QNetworkReply *reply);

    void saveScore(int score);
    bool parseSaveScore(QNetworkReply *reply);

    void setToken(const QString &token);
    void setRequestNum(Request *requestNum);

signals:
    void letsDisconnect();

private:
    //App
    ModelApplication        *_modelApplication;
    QNetworkAccessManager   *_manager;

    //Network
    QNetworkRequest         _request;

    //API
    QString                 _address;
    Request                 *_requestNum;

    QString                 _username;
    QString                 _token;
};

#endif // SCOREDAO_H
