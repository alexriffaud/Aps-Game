#include "../inc/DatabaseApplication.h"

DatabaseApplication::DatabaseApplication(ModelApplication *modelApplication) :
    _modelApplication(modelApplication),
    _manager(),
    _address("http://env-1021880.hidora.com/api/v1/apsgame"),
    _token(""),
    _userDAO(modelApplication, &_manager, _address, &_requestNum),
    _scoreDAO(modelApplication, &_manager, _address, &_requestNum)
{
    QObject::connect(&_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
}

DatabaseApplication::~DatabaseApplication()
{
    _manager.deleteLater();
}

QVariant DatabaseApplication::onResult(QNetworkReply *reply)
{
    qDebug() << "DatabaseApplication::onResult:";
    QVariant result;

    //Check request
    switch(_requestNum)
    {
    case Request::CONNECT:
    {
        result = _userDAO.parseConnect(reply);
        _token = _userDAO.token();
        _scoreDAO.setToken(_userDAO.token());
        emit changeLoginState(result.toBool());
        qDebug() << "Request::CONNECT:";
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
    case Request::SAVE_SCORE:
    {
        result = _scoreDAO.parseSaveScore(reply);
        emit changeSaveScoreState(result.toBool());
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
