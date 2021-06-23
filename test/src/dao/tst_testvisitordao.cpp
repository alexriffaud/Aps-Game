#include "tst_testvisitordao.h"

TestVisitorDAO::TestVisitorDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestVisitorDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestVisitorDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
