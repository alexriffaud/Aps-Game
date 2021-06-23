#include "tst_testcontributordao.h"
#include "TestTools.h"

TestContributorDAO::TestContributorDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

void TestContributorDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestContributorDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}

void TestContributorDAO::getContributorsRHTestCase()
{

}

void TestContributorDAO::getContributorsAdminTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::ADMINPROJECT);
    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getContributorsAdmin();

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);

}

void TestContributorDAO::getCurrentContributorPointingTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::POINTINGPROJECT);
    QString login = "ariffaud";
    Contributor *contributor = _mainApp->getDatabaseApp()->getContributorDAO()->getCurrentContributorPointing(login);

    if(contributor)
    {
        QVERIFY(contributor);
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }
}

void TestContributorDAO::getContributorsPointingTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::POINTINGPROJECT);
    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getContributorsPointing();

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);
}

void TestContributorDAO::getContributorsQualityTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::QUALITYPROJECT);
    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getContributorsQuality();

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);
}

void TestContributorDAO::getContributorsSkillTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::SKILLPROJECT);
    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getContributorsSkill();

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);
}

void TestContributorDAO::getContributorsPlatformTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::POINTINGPROJECT);
    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    QList<Contributor> platformList;
    platformList.append(c);

    QVERIFY(_mainApp->getDatabaseApp()->getContributorDAO()->savePlatform(&platformList));

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getContributorsPlatform();

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);
}

void TestContributorDAO::getProjectTeamTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::POINTINGPROJECT);

    //Insert d'un collaborateur
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    Contributor c(0, firstname,
                  lastname,
                  "CDD",
                  QDate::currentDate(),
                  "Homme");
    int idContributor = 0;
    if (_mainApp->getDatabaseApp()->getDatabase()->getMySQLDatabase()->isDbOpened())
    {
        idContributor = _mainApp->getDatabaseApp()->getContributorDAO()->insertCommonData(&c);
    }

    Project p("2020TEST", "testName", "testIA", "testDescrition", QDate::currentDate(), QDate::currentDate(), "testCustomer", "testLocalization",
              "ariffaud", 1, 10, 0, 0, 1, 1, "ariffaud");
    _mainApp->getDatabaseApp()->getProjectDAO()->insertProject(&p);

    Activity a(0, "TestActivity", Type::AT);
    _mainApp->getDatabaseApp()->getActivityDAO()->insertActivity(&a, p.primaryID());

    Task t(0, "TestTask", QDate::currentDate(), QDate::currentDate(), 10, 0, 10, "TestComment", Status::NOT_STARTED, false, "ariffaud",
           "", QDate::currentDate().weekNumber(), 0, QDate::currentDate().month());
    _mainApp->getDatabaseApp()->getTaskDAO()->insertTask(&t,p.primaryID(), a.ID());

    QList<Contributor> *list = _mainApp->getDatabaseApp()->getContributorDAO()->getProjectTeam(p.ID());

    if(list)
    {
        QVERIFY(!list->isEmpty());
    }
    else
    {
        QCOMPARE("Erreur lors de la récupération de la liste", "");
    }

    _mainApp->getDatabaseApp()->getTaskDAO()->deleteTask(&t,p.primaryID(), a.ID());
    _mainApp->getDatabaseApp()->getActivityDAO()->deleteActivity(&a, p.primaryID());
    _mainApp->getDatabaseApp()->getProjectDAO()->deleteProject(&p);
    _mainApp->getDatabaseApp()->getContributorDAO()->deleteContributor(idContributor);
}

void TestContributorDAO::getJobListTestCase()
{

    QMap<QString, QStringList> list = _mainApp->getDatabaseApp()->getContributorDAO()->getJobList();
    QVERIFY(!list.isEmpty());
}

void TestContributorDAO::getFilteredContributorsTestCase()
{

}

void TestContributorDAO::getJobProportionsTestCase()
{

}

void TestContributorDAO::findContributorTestCase()
{

}

void TestContributorDAO::findContributorByFullNameTestCase()
{

}

void TestContributorDAO::getCoeffTestCase()
{

}

void TestContributorDAO::getPositionTestCase()
{

}

void TestContributorDAO::getWorkforceAtYearEndTestCase()
{

}

void TestContributorDAO::getWorkforceAtYearEndOneTestCase()
{

}

void TestContributorDAO::getWorkforceAtYearEndTwoTestCase()
{

}

void TestContributorDAO::getSynthesisByYearTestCase()
{

}

void TestContributorDAO::getSynthesisByYearAgencyTestCase()
{

}

void TestContributorDAO::getSynthesisByYearContractTestCase()
{

}

void TestContributorDAO::deleteContributorByPointerTestCase()
{

}

void TestContributorDAO::deleteContributorByIDTestCase()
{

}

void TestContributorDAO::getContractCountTestCase()
{

}

void TestContributorDAO::updateTestCase()
{

}

void TestContributorDAO::updateCommonDataTestCase()
{

}

void TestContributorDAO::updateContactDataTestCase()
{

}

void TestContributorDAO::updateMutualDataTestCase()
{

}

void TestContributorDAO::updateInterviewsDataTestCase()
{

}

void TestContributorDAO::inserOrUpdateExtrasDataTestCase()
{

}

void TestContributorDAO::insertOrUpdateMedicalVisitsDataTestCase()
{

}

void TestContributorDAO::insertOrUpdateQualityDataTestCase()
{

}

void TestContributorDAO::insertOrUpdateTrialPeriodDataTestCase()
{

}

void TestContributorDAO::insertPreventionPlanTestCase()
{

}

void TestContributorDAO::updatePreventionPlanTestCase()
{

}

void TestContributorDAO::insertCommonDataTestCase()
{

}

void TestContributorDAO::insertContactDataTestCase()
{

}

void TestContributorDAO::insertMutualDataTestCase()
{

}

void TestContributorDAO::insertInterviewsDataTestCase()
{

}

void TestContributorDAO::insertMedicalVisitsDataTestCase()
{

}

void TestContributorDAO::insertQualityDataTestCase()
{

}

void TestContributorDAO::insertTrialPeriodDataTestCase()
{

}

void TestContributorDAO::getGenreCountTestCase()
{

}

void TestContributorDAO::getStatusCountTestCase()
{

}

void TestContributorDAO::getTurnOverTestCase()
{

}

void TestContributorDAO::findIAByNameTestCase()
{

}

void TestContributorDAO::setMissionDAOTestCase()
{

}

void TestContributorDAO::savePlatformTestCase()
{

}

void TestContributorDAO::getFormationsTestCase()
{

}
