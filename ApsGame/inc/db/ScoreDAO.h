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

/**
 * @brief The ScoreDAO class
 */
class ScoreDAO : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief ScoreDAO
     * @param modelApplication
     * @param manager
     * @param address
     * @param request
     */
    ScoreDAO(ModelApplication *modelApplication, QNetworkAccessManager *manager, QString &address, Request *request);

    /**
     * @brief getGlobalScore
     */
    void getGlobalScore();
    /**
     * @brief parseGlobalScore
     * @param reply
     * @return
     */
    bool parseGlobalScore(QNetworkReply *reply);

    /**
     * @brief getPersonalScore
     */
    void getPersonalScore();
    /**
     * @brief parsePersonalScore
     * @param reply
     * @return
     */
    bool parsePersonalScore(QNetworkReply *reply);

    /**
     * @brief saveScore
     * @param score
     */
    void saveScore(int score);
    /**
     * @brief parseSaveScore
     * @param reply
     * @return
     */
    bool parseSaveScore(QNetworkReply *reply);

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
};

#endif // SCOREDAO_H
