#include "tst_testmissiondao.h"

TestMissionDAO::TestMissionDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestMissionDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestMissionDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
