#ifndef DATABASEAPPLICATION_H
#define DATABASEAPPLICATION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

#include "ModelApplication.h"
#include "Enums.h"
#include "Tools.h"
#include "ScoreDAO.h"
#include "UserDAO.h"

class DatabaseApplication : public QObject
{
    Q_OBJECT
public:
    DatabaseApplication(ModelApplication *modelApplication);
    ~DatabaseApplication();

    UserDAO *userDAO();
    ScoreDAO *scoreDAO();

private slots:
    QVariant onResult(QNetworkReply *reply);

signals:
    void changeLoginState(bool state);
    void changeSignUpState(bool state);
    void changeCheckLoginState(bool state);
    void changeAccountState(bool state);
    void changeGlobalScoreState(bool state);
    void changePersonalScoreState(bool state);

private:
    ModelApplication    *_modelApplication;

    QNetworkAccessManager   _manager;

    //API
    QString                 _address;
    Request                 _requestNum;

    QString                 _token;

    //Network
    QNetworkRequest         _request;

    bool                    _connectionState;
    bool                    _firstRequest;

    //DAOs
    UserDAO                 _userDAO;
    ScoreDAO                _scoreDAO;
};

#endif // DATABASEAPPLICATION_H
