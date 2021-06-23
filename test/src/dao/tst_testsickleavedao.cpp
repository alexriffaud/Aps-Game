#include "tst_testsickleavedao.h"

TestSickLeaveDAO::TestSickLeaveDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestSickLeaveDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestSickLeaveDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
