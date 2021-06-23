#ifndef TST_TESTCANDIDATEDAO_H
#define TST_TESTCANDIDATEDAO_H

#include <QtTest>

// Inlcudes from project to test
#include "MainApplication.h"


class TestScoreDAO: public QObject
{
    Q_OBJECT
public:
    TestScoreDAO(MainApplication *mainApp);

    static void output(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void initTestCase();
    void getGlobalScore();
    void getPersonalScore();
    void saveScore();

private:
    MainApplication     *_mainApp;
    int                 _idActivity;
    QString _token;
};

#endif // TST_TESTCANDIDATEDAO_H
