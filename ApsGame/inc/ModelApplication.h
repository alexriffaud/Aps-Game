#ifndef MODELAPPLICATION_H
#define MODELAPPLICATION_H

#include <QObject>

#include "User.h"

class ModelApplication : public QObject
{
    Q_OBJECT
public:
    ModelApplication();

    User *user();

private:
    User    _user;
};

#endif // MODELAPPLICATION_H
