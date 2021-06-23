#include "tst_testskilldao.h"

TestSkillDAO::TestSkillDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}


void TestSkillDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestSkillDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}
