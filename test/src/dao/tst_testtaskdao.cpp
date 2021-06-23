#include "tst_testtaskdao.h"

TestTaskDAO::TestTaskDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestTaskDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestTaskDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
