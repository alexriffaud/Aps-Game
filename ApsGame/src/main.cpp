#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "MainApplication.h"

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
#include <FelgoLiveClient>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FelgoApplication felgo;

    QQmlApplicationEngine engine;
        MainApplication mainApplication(&engine);
//    QQmlContext *context = new QQmlContext(engine.rootContext());
//    context->setContextProperty("mainApp", &mainApplication);
    felgo.initialize(&engine);


    engine.rootContext()->setContextProperty("mainApp", &mainApplication);
    engine.rootContext()->setContextProperty("currentUser", mainApplication.modelApplication()->user());
    engine.rootContext()->setContextProperty("modelScores", mainApplication.modelApplication()->globalScoreList());

    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
//    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    // use this during development
    // for PUBLISHING, use the entry point below
//    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));



    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    //felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

//    engine.load(QUrl(felgo.mainQmlFileName()));
     FelgoLiveClient liveClient(&engine);

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);

    return app.exec();
}
