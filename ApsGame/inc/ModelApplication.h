#ifndef MODELAPPLICATION_H
#define MODELAPPLICATION_H

#include <QObject>

#include "User.h"
#include "Score.h"
#include "ScoreList.h"

/**
 * @brief The ModelApplication class
 */
class ModelApplication : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief ModelApplication
     */
    ModelApplication();

    /**
     * @brief user
     * @return
     */
    User *user();
    /**
     * @brief globalScoreList
     * @return
     */
    ScoreList *globalScoreList();

private:
    User        _user; /*!< Current user */
    ScoreList   _globalScoreList; /*!< Score list for current user */
};

#endif // MODELAPPLICATION_H
