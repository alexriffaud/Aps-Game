#ifndef TESTUSERDAO_H
#define TESTUSERDAO_H

#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"

class TestUserDAO: public QObject
{
    Q_OBJECT
public:
    TestUserDAO(MainApplication *mainApp);
    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();
    void connect();
    void changeAccount();
    void signUp();
    void checkLoginState();

private:
    MainApplication     *_mainApp;
    QString _token;
};

#endif // TESTUSERDAO_H
