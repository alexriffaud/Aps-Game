#include "tst_testinterviewdao.h"

TestInterviewDAO::TestInterviewDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestInterviewDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestInterviewDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
