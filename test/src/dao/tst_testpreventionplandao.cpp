#include "tst_testpreventionplandao.h"

TestPreventionPlanDAO::TestPreventionPlanDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestPreventionPlanDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestPreventionPlanDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
