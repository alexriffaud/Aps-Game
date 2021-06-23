#include "tst_testsoftwaredao.h"

TestSoftwareDAO::TestSoftwareDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestSoftwareDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestSoftwareDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
