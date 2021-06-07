#ifndef TOOLS_H
#define TOOLS_H

#include <QNetworkReply>
#include <QNetworkRequest>
#include "Enums.h"

class Tools : QObject
{
    Q_OBJECT
public:
    Tools();

    static void setSSLConfiguration(QNetworkRequest *request);
    static int parseStatus(QNetworkReply *reply);
    static bool redirection(QNetworkReply *reply, Request &request, QNetworkAccessManager *mgr);
    static bool showError(QNetworkReply *reply);
};

#endif // TOOLS_H
