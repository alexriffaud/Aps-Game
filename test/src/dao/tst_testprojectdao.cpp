#include "tst_testprojectdao.h"

TestProjectDAO::TestProjectDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestProjectDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestProjectDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
