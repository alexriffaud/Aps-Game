#ifndef TST_DATABASE_H
#define TST_DATABASE_H

#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"

class TestDatabase : public QObject
{
    Q_OBJECT
public:
    TestDatabase(MainApplication *mainApp);
    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();

    void userDAO();
    void scoreDAO();

private:
    MainApplication     *_mainApp;
};

#endif // TST_DATABASE_H
