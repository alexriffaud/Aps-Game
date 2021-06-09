#include "../inc/ModelApplication.h"

ModelApplication::ModelApplication()
{

}

User *ModelApplication::user()
{
    return &_user;
}

ScoreList *ModelApplication::globalScoreList()
{
    return &_globalScoreList;
}
