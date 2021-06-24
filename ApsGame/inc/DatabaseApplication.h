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

/**
 * @brief The DatabaseApplication class
 */
class DatabaseApplication : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief DatabaseApplication
     * @param modelApplication
     */
    DatabaseApplication(ModelApplication *modelApplication);
    ~DatabaseApplication();

    /**
     * @brief userDAO
     * @return
     */
    UserDAO *userDAO();
    /**
     * @brief scoreDAO
     * @return
     */
    ScoreDAO *scoreDAO();

private slots:
    /**
     * @brief onResult
     * @param reply
     * @return
     */
    QVariant onResult(QNetworkReply *reply);

signals:
    /**
     * @brief changeLoginState
     * @param state
     */
    void changeLoginState(bool state);
    /**
     * @brief changeSignUpState
     * @param state
     */
    void changeSignUpState(bool state);
    /**
     * @brief changeCheckLoginState
     * @param state
     */
    void changeCheckLoginState(bool state);
    /**
     * @brief changeAccountState
     * @param state
     */
    void changeAccountState(bool state);
    /**
     * @brief changeGlobalScoreState
     * @param state
     */
    void changeGlobalScoreState(bool state);
    /**
     * @brief changePersonalScoreState
     * @param state
     */
    void changePersonalScoreState(bool state);
    /**
     * @brief changeSaveScoreState
     * @param state
     */
    void changeSaveScoreState(bool state);

private:
    ModelApplication    *_modelApplication; /*!< ModelApplication pointer */

    QNetworkAccessManager   _manager; /*!< Manager for send HTTP request */

    //API
    QString                 _address; /*!< API address */
    Request                 _requestNum; /*!< Enum for handle http response */

    QString                 _token; /*!< User's token */

    //Network
    QNetworkRequest         _request; /*!< HTTP request */

    //DAOs
    UserDAO                 _userDAO; /*!< User DAO */
    ScoreDAO                _scoreDAO; /*!< Score DAO */
};

#endif // DATABASEAPPLICATION_H
