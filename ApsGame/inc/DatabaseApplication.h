#ifndef DATABASEAPPLICATION_H
#define DATABASEAPPLICATION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

#include "ModelApplication.h"
#include "Enums.h"
#include "Tools.h"

class DatabaseApplication : public QObject
{
    Q_OBJECT
public:
    DatabaseApplication(ModelApplication *modelApplication);
    ~DatabaseApplication();

    void connect(QString name, QString password);
    bool parseConnect(QNetworkReply *reply);

    void signUp(QByteArray bytes);
    bool parseSignUp(QNetworkReply *reply);

    void checkLoginState(QByteArray bytes);
    bool parseLoginState(QNetworkReply *reply);

    void changeAccount(QByteArray bytes);
    bool parseChangeAccount(QNetworkReply *reply);

private slots:
    QVariant onResult(QNetworkReply *reply);

signals:
    void changeLoginState(bool state);
    void changeSignUpState(bool state);
    void changeCheckLoginState(bool state);
    void changeAccountState(bool state);

private:
    ModelApplication    *_modelApplication;

    QNetworkAccessManager   _manager;

    //API
    QString                 _address;
    Request                 _requestNum;

    QString                 _username;
    QString                 _password;
    QString                 _token;

    //Network
    QNetworkRequest         _request;

    bool                    _connectionState;
    bool                    _firstRequest;
};

#endif // DATABASEAPPLICATION_H
