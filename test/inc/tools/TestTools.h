#ifndef TESTTOOLS_H
#define TESTTOOLS_H

#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"
#include "tools/Enums.h"

class TestTools : public QObject
{
    Q_OBJECT
public:
    TestTools(MainApplication *mainApp);
    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();

    // ScoreList
    //----------
    void rowCount();
    void findObject();
    void data();
    void items();
    void insert();
    void remove();
    void removeAll();
    void updateItem();
    void clear();
    void size();
    void at();

    // Tools
    //------
    void setSSLConfiguration();
    void parseStatus();
    void redirection();
    void showError();

private:
    MainApplication     *_mainApp;
};

#endif // TESTTOOLS_H
