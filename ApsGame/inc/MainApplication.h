#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "ModelApplication.h"
#include "DatabaseApplication.h"

/**
 * @brief The MainApplication class
 */
class MainApplication : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool _isConnected MEMBER _isConnected NOTIFY changeLoginState)
    Q_PROPERTY(bool _isSignUp MEMBER _isSignUp NOTIFY changeSignUpState)
    Q_PROPERTY(bool _loginState MEMBER _loginState NOTIFY changeCheckLoginState)
    Q_PROPERTY(bool _accountChangeState MEMBER _loginState NOTIFY changeAccountState)
    Q_PROPERTY(bool _saveScoreState MEMBER _saveScoreState NOTIFY changeSaveScoreState)

public:
    /**
     * @brief MainApplication
     * @param engine
     */
    MainApplication(QQmlApplicationEngine *engine);

    /**
     * @brief modelApplication
     * @return
     */
    ModelApplication *modelApplication();
    /**
     * @brief databaseApplication
     * @return
     */
    DatabaseApplication *databaseApplication();

    /**
     * @brief login
     * @param login
     * @param password
     */
    Q_INVOKABLE void login(const QString &login, const QString &password);
    /**
     * @brief signUp
     * @param login
     * @param mail
     * @param firstName
     * @param password
     * @param birthdate
     */
    Q_INVOKABLE void signUp(const QString &login, const QString &mail, const QString &firstName, const QString &password, const QDate &birthdate);
    /**
     * @brief checkLogin
     * @param login
     */
    Q_INVOKABLE void checkLogin(const QString &login);
    /**
     * @brief changeAccount
     * @param login
     * @param mail
     * @param firstName
     * @param password
     */
    Q_INVOKABLE void changeAccount(const QString &login, const QString &mail, const QString &firstName, const QString &password);
    /**
     * @brief getGlobalScore
     */
    Q_INVOKABLE void getGlobalScore();
    /**
     * @brief getPersonalScore
     */
    Q_INVOKABLE void getPersonalScore();
    /**
     * @brief saveScore
     * @param score
     */
    Q_INVOKABLE void saveScore(int score);

    /**
     * @brief isConnected
     * @return
     */
    Q_INVOKABLE bool isConnected() const;
    /**
     * @brief isSignUp
     * @return
     */
    Q_INVOKABLE bool isSignUp() const;
    /**
     * @brief loginState
     * @return
     */
    Q_INVOKABLE bool loginState() const;
    /**
     * @brief accountChangeState
     * @return
     */
    Q_INVOKABLE bool accountChangeState() const;
    /**
     * @brief getSaveScoreState
     * @return
     */
    Q_INVOKABLE bool getSaveScoreState() const;

signals:
    /**
     * @brief changeLoginState
     */
    void changeLoginState();
    /**
     * @brief changeSignUpState
     */
    void changeSignUpState();
    /**
     * @brief changeCheckLoginState
     */
    void changeCheckLoginState();
    /**
     * @brief changeAccountState
     */
    void changeAccountState();
    /**
     * @brief changeSaveScoreState
     */
    void changeSaveScoreState();

private slots:
    /**
     * @brief setIsLogged
     * @param state
     */
    void setIsLogged(bool state);
    /**
     * @brief setIsSignUp
     * @param isSignUp
     */
    void setIsSignUp(bool isSignUp);
    /**
     * @brief setLoginState
     * @param loginState
     */
    void setLoginState(bool loginState);
    /**
     * @brief setAccountChangeState
     * @param accountChangeState
     */
    void setAccountChangeState(bool accountChangeState);
    /**
     * @brief setSaveScoreState
     * @param saveScoreState
     */
    void setSaveScoreState(bool saveScoreState);

private:
    QQmlApplicationEngine   *_engine; /*!< QML engine */
    ModelApplication        _modelApplication; /*!< ModelApplication instance */
    DatabaseApplication     _databaseApplication; /*!< DatabaseApplication instance */

    //State
    bool                    _isConnected = false; /*!< User connection state */
    bool                    _isSignUp = false; /*!< Sign up state */
    bool                    _loginState = false; /*!< Login state */
    bool                    _accountChangeState = false; /*!< Account change state */
    bool                    _saveScoreState = false; /*!< Save state */
};

#endif // MAINAPPLICATION_H
