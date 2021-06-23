#include "../inc/tst_database.h"

TestDatabase::TestDatabase(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestDatabase::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->databaseApplication());
}

void TestDatabase::userDAO()
{
    QVERIFY(_mainApp->databaseApplication()->userDAO());
}

void TestDatabase::scoreDAO()
{
    QVERIFY(_mainApp->databaseApplication()->scoreDAO());
}

void TestDatabase::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}
