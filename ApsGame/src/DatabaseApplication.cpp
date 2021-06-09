#include "../inc/DatabaseApplication.h"

DatabaseApplication::DatabaseApplication(ModelApplication *modelApplication) :
    _modelApplication(modelApplication),
    _manager(),
    _address("https://127.0.0.1:8080/api/v1/apsgame"),
    _token(""),
    _connectionState(false),
    _userDAO(modelApplication, &_manager, _address),
    _scoreDAO(modelApplication, &_manager, _address)
{
    QObject::connect(&_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
    _firstRequest = true;
}

DatabaseApplication::~DatabaseApplication()
{
    _manager.deleteLater();
}

QVariant DatabaseApplication::onResult(QNetworkReply *reply)
{
    QVariant result;

    //Check request
    switch(_requestNum)
    {
    case Request::CONNECT:
    {
        result = _userDAO.parseConnect(reply);
        _token = _userDAO.token();
        _scoreDAO.setToken(_token);
        emit changeLoginState(result.toBool());
        break;
    }
    case Request::SIGNUP:
    {
        result = _userDAO.parseSignUp(reply);
        emit changeSignUpState(result.toBool());
        break;
    }
    case Request::LOGIN_STATE:
    {
        result = _userDAO.parseLoginState(reply);
        emit changeCheckLoginState(result.toBool());
        break;
    }
    case Request::CHANGE_ACCOUNT:
    {
        result = _userDAO.parseChangeAccount(reply);
        emit changeAccountState(result.toBool());
        break;
    }
    case Request::GLOBAL_SCORE:
    {
        result = _scoreDAO.parseGlobalScore(reply);
        emit changeGlobalScoreState(result.toBool());
        break;
    }
    case Request::PERSONAL_SCORE:
    {
        result = _scoreDAO.parsePersonalScore(reply);
        emit changePersonalScoreState(result.toBool());
        break;
    }
    default:
    {
        break;
    }
    }

    return result;
}

ScoreDAO *DatabaseApplication::scoreDAO()
{
    return &_scoreDAO;
}

UserDAO *DatabaseApplication::userDAO()
{
    return &_userDAO;
}
