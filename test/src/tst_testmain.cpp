#include "tst_testmain.h"

TestMain::TestMain(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

TestMain::~TestMain()
{

}

void TestMain::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp);
}

void TestMain::isConnected()
{
    QCOMPARE(_mainApp->isConnected(), false);
}

void TestMain::isSignUp()
{
    QCOMPARE(_mainApp->isSignUp(), false);
}

void TestMain::loginState()
{
    QCOMPARE(_mainApp->loginState(), false);
}

void TestMain::accountChangeState()
{
    QCOMPARE(_mainApp->accountChangeState(), false);
}

void TestMain::getSaveScoreState()
{
    QCOMPARE(_mainApp->getSaveScoreState(), false);
}

void TestMain::getModelApp()
{
    QVERIFY(_mainApp->modelApplication());
}

void TestMain::getDatabaseApp()
{
    QVERIFY(_mainApp->databaseApplication());
}

void TestMain::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}
