#include "tst_testfiledao.h"

TestFileDAO::TestFileDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestFileDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestFileDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
