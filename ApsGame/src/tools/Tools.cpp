#include "../../inc/tools/Tools.h"

Tools::Tools()
{

}

void Tools::setSSLConfiguration(QNetworkRequest *request)
{
    QSslConfiguration sslConfiguration = request->sslConfiguration();
    sslConfiguration.setProtocol(QSsl::AnyProtocol);
    sslConfiguration.setPeerVerifyMode(QSslSocket::QueryPeer);
    request->setSslConfiguration(sslConfiguration);
}

int Tools::parseStatus(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QString statusName = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    qDebug() << statusCode << statusName;

    return statusCode;
}

bool Tools::redirection(QNetworkReply *reply, Request &request, QNetworkAccessManager *mgr)
{
    QUrl newUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
    QNetworkRequest newReq(newUrl);
    request = Request::CONNECT;
    mgr->get(newReq);

    return false;
}

bool Tools::showError(QNetworkReply *reply)
{
    qDebug() << reply->url().toString();
    qDebug() << reply->error();
    qDebug() << reply->errorString();

    return false;
}
