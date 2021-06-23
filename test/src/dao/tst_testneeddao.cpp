#include "tst_testneeddao.h"

TestNeedDAO::TestNeedDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestNeedDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestNeedDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
