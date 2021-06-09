#ifndef MODELAPPLICATION_H
#define MODELAPPLICATION_H

#include <QObject>

#include "User.h"
#include "Score.h"
#include "ScoreList.h"

class ModelApplication : public QObject
{
    Q_OBJECT
public:
    ModelApplication();

    User *user();
    ScoreList *globalScoreList();

private:
    User        _user;
    ScoreList   _globalScoreList;
};

#endif // MODELAPPLICATION_H
