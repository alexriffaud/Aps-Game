#ifndef TST_TESTMODEL_H
#define TST_TESTMODEL_H

#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"
#include "tools/Enums.h"

class TestModel : public QObject
{
    Q_OBJECT
public:
    TestModel(MainApplication *mainApp);
    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();
    void user();
    void globalScoreList();

private:
    MainApplication     *_mainApp;
};

#endif // TST_TESTMODEL_H
