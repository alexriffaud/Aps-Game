#ifndef TOOLS_H
#define TOOLS_H

#include <QNetworkReply>
#include <QNetworkRequest>
#include "Enums.h"

/**
 * @brief The Tools class
 */
class Tools : QObject
{
    Q_OBJECT
public:
    /**
     * @brief Tools
     */
    Tools();

    /**
     * @brief setSSLConfiguration
     * @param request
     */
    static void setSSLConfiguration(QNetworkRequest *request);
    /**
     * @brief parseStatus
     * @param reply
     * @return
     */
    static int parseStatus(QNetworkReply *reply);
    /**
     * @brief redirection
     * @param reply
     * @param request
     * @param mgr
     * @return
     */
    static bool redirection(QNetworkReply *reply, Request &request, QNetworkAccessManager *mgr);
    /**
     * @brief showError
     * @param reply
     * @return
     */
    static bool showError(QNetworkReply *reply);
};

#endif // TOOLS_H
