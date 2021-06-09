#ifndef USERDAO_H
#define USERDAO_H

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

class UserDAO : public QObject
{
    Q_OBJECT
public:
    UserDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address);

    void changeAccount(QByteArray bytes);
    bool parseChangeAccount(QNetworkReply *reply);

    void connect(QString name, QString password);
    bool parseConnect(QNetworkReply *reply);

    void signUp(QByteArray bytes);
    bool parseSignUp(QNetworkReply *reply);

    void checkLoginState(QByteArray bytes);
    bool parseLoginState(QNetworkReply *reply);

    void setToken(const QString &token);
    void setRequestNum(Request *requestNum);

    QString token() const;

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
    QString                 _password;
    QString                 _token;
};

#endif // USERDAO_H
