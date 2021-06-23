#include <QTest>
#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MainApplication.h"

#include "tst_testmain.h"
#include "tst_testmodel.h"
#include "tst_testscoredao.h"
#include "tst_testuserdao.h"
#include "TestTools.h"
#include "tst_database.h"

#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

int main(int argc, char *argv[])
{
    // qInstallMessageHandler(myMessageOutput);
    QApplication app(argc, argv);

    FelgoApplication felgo;

    QQmlApplicationEngine engine;
    MainApplication mainApplication(&engine);
    felgo.initialize(&engine);

    engine.rootContext()->setContextProperty("mainApp", &mainApplication);
    engine.rootContext()->setContextProperty("currentUser", mainApplication.modelApplication()->user());
    engine.rootContext()->setContextProperty("modelScores", mainApplication.modelApplication()->globalScoreList());

    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);
    felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));


    //Start tests
    TestMain testMain(&mainApplication);
    QTest::qExec(&testMain, argc, argv);

    //Test ModelApplication
    //---------------------
    TestModel testModel(&mainApplication);
    QTest::qExec(&testModel, argc, argv);

    //Test DAOs
    //---------
    TestScoreDAO testScoreDAO(&mainApplication);
    QTest::qExec(&testScoreDAO, argc, argv);

    TestUserDAO testUserDAO(&mainApplication);
    QTest::qExec(&testUserDAO, argc, argv);

    //Test Tools
    //----------
    TestTools testTools(&mainApplication);
    QTest::qExec(&testTools, argc, argv);

    //Test Database
    //----------
    TestDatabase testDatabase(&mainApplication);
    QTest::qExec(&testDatabase, argc, argv);


    return app.exec();
}
