#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"

class TestMain : public QObject
{
    Q_OBJECT

public:
    TestMain(MainApplication *mainApp);
    ~TestMain();
    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();

    void isConnected();
    void isSignUp();
    void loginState();
    void accountChangeState();
    void getSaveScoreState();
    void getDatabaseApp();
    void getModelApp();

private:
    MainApplication     *_mainApp;
};
