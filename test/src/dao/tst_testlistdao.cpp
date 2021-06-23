#include "tst_testlistdao.h"

TestListDAO::TestListDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestListDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestListDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
