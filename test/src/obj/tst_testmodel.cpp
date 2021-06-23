#include "tst_testmodel.h"

TestModel::TestModel(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestModel::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->modelApplication());
}

void TestModel::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestModel::user()
{
    QVERIFY(_mainApp->modelApplication()->user());
}

void TestModel::globalScoreList()
{
    QVERIFY(_mainApp->modelApplication()->globalScoreList());
}
