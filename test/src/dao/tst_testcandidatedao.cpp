#include "tst_testcandidatedao.h"
#include "TestTools.h"
#include <QDebug>

TestUserDAO::TestUserDAO(MainApplication *mainApp) :
    _mainApp(mainApp)
{

}

TestUserDAO::~TestUserDAO()
{

}

void TestUserDAO::output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}

void TestUserDAO::initTestCase()
{
    qInstallMessageHandler(output);
    QVERIFY(_mainApp->getDatabaseApp()->isConnected());
}

void TestUserDAO::insertCandidateTestCase()
{
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());
    _login = "login"+QString::number(TestTools::getRandomNumber());

    Candidate *candidate = new Candidate(lastname, firstname, QDate::currentDate());
    candidate->setMobility("Autre");
    candidate->setHr(_login);
    candidate->setAvailableDate(QDate::currentDate());
    candidate->setEmail("test");
    candidate->setSource("Apec");
    candidate->setContract(Candidate::Contract::CDD);
    candidate->setSkill("A++");
    candidate->setResult(Candidate::Result::NONE);
    candidate->setStatus(Candidate::Status::NO_GO);
    candidate->setCountry("France");
    candidate->setNationality("Française");
    candidate->setSex("Homme");
    candidate->setCreationDate(QDate::currentDate());

    //Insert in database
    _mainApp->getDatabaseApp()->getCandidateDAO()->insert(candidate);

    //Reset data in memory
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    bool state = false;

    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(it->getFirstname() == firstname && it->getLastname() == lastname)
        {
            state = true;
            _idCandidate = it->getID();
        }
    }

    QCOMPARE(state, true);
}

void TestUserDAO::getCandidatesTestCase()
{
    bool state = false;

    if(!_mainApp->getDatabaseApp()->getCandidateDAO()->getCandidates(_login)->isEmpty())
    {
        state = true;
    }

    QCOMPARE(state, true);
}

void TestUserDAO::findCandidateTestCase()
{
    bool state = false;

    if(_mainApp->getDatabaseApp()->getCandidateDAO()->findCandidate(_idCandidate))
    {
        state = true;
    }
    QCOMPARE(state, true);
}

void TestUserDAO::updateCandidateTestCase()
{
    QString firstname = "testF"+QString::number(TestTools::getRandomNumber());
    QString lastname = "TestL"+QString::number(TestTools::getRandomNumber());

    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(it->getFirstname() == firstname && it->getLastname() == lastname)
        {
            it->setFirstName(firstname);
            it->setLastName(lastname);
            _mainApp->getDatabaseApp()->getCandidateDAO()->update(&*it);
        }
    }

    //Reload data
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    QString firstname2 = "";
    QString lastname2 = "";


    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            firstname2 = it->getFirstname();
            lastname2 = it->getLastname();
        }
    }

    QCOMPARE(firstname, firstname2);
    QCOMPARE(lastname, firstname2);
}

void TestUserDAO::insertFileCandidateTestCase()
{
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            _mainApp->getDatabaseApp()->getCandidateDAO()->insertFile(it->getID(), "CV", "test");
            break;
        }
    }

    //Reload data
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    bool state = false;
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            const QList<QPair<unsigned int, QString>> *list = it->getFiles();
            for (int ii=0;ii<list->size();++ii)
            {
                if(list->at(ii).second == "CV;test")
                {
                    state = true;
                }
            }
            break;
        }
    }
    QCOMPARE(state, true);
}

void TestUserDAO::removeFileCandidateTestCase()
{
    _mainApp->getDatabaseApp()->getCandidateDAO()->removeFile(_fileID, "test");

    //Reload data
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    bool state = false;
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            const QList<QPair<unsigned int, QString>> *list = it->getFiles();
            for (int ii=0;ii<list->size();++ii)
            {
                if(list->at(ii).first == static_cast<unsigned int>(_fileID))
                {
                    state = true;
                }
            }
            break;
        }
    }
    QCOMPARE(state, false);
}

void TestUserDAO::updateCandidateStatusTestCase()
{
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            it->setStatus(Candidate::Status::GO);
            _mainApp->getDatabaseApp()->getCandidateDAO()->updateCandidateStatus(&*it);
            break;
        }
    }

    //Reload data
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    bool state = false;
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID() && it->getStatus() == Candidate::Status::GO)
        {
            state = true;
            break;
        }
    }

    QCOMPARE(state, true);
}

void TestUserDAO::addCandidateActionTestCase()
{
    QString txt = "TestA"+QString::number(TestTools::getRandomNumber());

    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            it->addAction(QDateTime::currentDateTime(), QDateTime::currentDateTime(), Action::Type::A_RAPPELER, txt);
            _mainApp->getDatabaseApp()->getCandidateDAO()->addCandidateAction(&*it);
            break;
        }
    }

    //Reload data
    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    bool state = false;
    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID() && it->getLastAction()->getText() == txt)
        {
            state = true;
            break;
        }
    }

    QCOMPARE(state, true);
}

void TestUserDAO::getSourcesCountTestCase()
{
    QVERIFY(_mainApp->getDatabaseApp()->getCandidateDAO()->getSourcesCount().isEmpty());
}

void TestUserDAO::removeCandidateTestCase()
{
    Candidate *candidate = nullptr;

    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            candidate = &*it;
            break;
        }
    }

    if(candidate)
    {
        _mainApp->getDatabaseApp()->getCandidateDAO()->remove(candidate->getID());
    }

    _mainApp->getModelApp()->reset();
    _mainApp->getViewApp()->setData(Softs::RHPROJECT);

    QString name = "";

    for(QList<Candidate>::iterator it = _mainApp->getModelApp()->getCandidates()->begin(); it != _mainApp->getModelApp()->getCandidates()->end(); it++)
    {
        if(_idCandidate == it->getID())
        {
            name = it->getFirstname();
        }
    }

    QCOMPARE("", name);
}
