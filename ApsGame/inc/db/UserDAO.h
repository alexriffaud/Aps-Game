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

/**
 * @brief The UserDAO class
 */
class UserDAO : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief UserDAO
     * @param modelApplication
     * @param manager
     * @param address
     * @param request
     */
    UserDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address, Request *request);

    /**
     * @brief changeAccount
     * @param bytes
     */
    void changeAccount(QByteArray bytes);
    /**
     * @brief parseChangeAccount
     * @param reply
     * @return
     */
    bool parseChangeAccount(QNetworkReply *reply);

    /**
     * @brief connect
     * @param name
     * @param password
     */
    void connect(QString name, QString password);
    /**
     * @brief parseConnect
     * @param reply
     * @return
     */
    bool parseConnect(QNetworkReply *reply);

    /**
     * @brief signUp
     * @param bytes
     */
    void signUp(QByteArray bytes);
    /**
     * @brief parseSignUp
     * @param reply
     * @return
     */
    bool parseSignUp(QNetworkReply *reply);

    /**
     * @brief checkLoginState
     * @param bytes
     */
    void checkLoginState(QByteArray bytes);
    /**
     * @brief parseLoginState
     * @param reply
     * @return
     */
    bool parseLoginState(QNetworkReply *reply);

    /**
     * @brief setToken
     * @param token
     */
    void setToken(const QString &token);
    /**
     * @brief setRequestNum
     * @param requestNum
     */
    void setRequestNum(Request *requestNum);

    /**
     * @brief token
     * @return
     */
    QString token() const;

signals:
    /**
     * @brief letsDisconnect
     */
    void letsDisconnect();

private:
    //App
    ModelApplication        *_modelApplication;  /*!< ModelApplication pointer */
    QNetworkAccessManager   *_manager;  /*!< Manager for send HTTP request */

    //Network
    QNetworkRequest         _request;  /*!< HTTP request */

    //API
    QString                 _address;  /*!< API address */
    Request                 *_requestNum;  /*!< Enum for handle the response of request */

    QString                 _username;  /*!< Login of current user */
    QString                 _token;  /*!< Token of current user */
    QString                 _password; /*!< Password of current user */
};

#endif // USERDAO_H
