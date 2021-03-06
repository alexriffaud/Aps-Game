# allows to add DEPLOYMENTFOLDERS and links to the Felgo library and QtCreator auto-completion
CONFIG += felgo quick core

# uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
# for the remaining steps to build a custom Live Code Reload app see here: https://felgo.com/custom-code-reload-app/
# CONFIG += felgo-live

# Project identifier and version
# More information: https://felgo.com/doc/felgo-publishing/#project-configuration
PRODUCT_IDENTIFIER = com.esimed.wizardEVP.ApsGame
PRODUCT_VERSION_NAME = 1.0.1
PRODUCT_VERSION_CODE = 34

# Optionally set a license key that is used instead of the license key from
# main.qml file (App::licenseKey for your app or GameWindow::licenseKey for your game)
# Only used for local builds and Felgo Cloud Builds (https://felgo.com/cloud-builds)
# Not used if using Felgo Live
PRODUCT_LICENSE_KEY = ""

#qmlFolder.source = qml
#DEPLOYMENTFOLDERS += qmlFolder # comment for publishing

assetsFolder.source = $${PWD}/assets
DEPLOYMENTFOLDERS += assetsFolder

# Add more folders to ship with the application here

RESOURCES += $${PWD}/resources.qrc # uncomment for publishing

# NOTE: for PUBLISHING, perform the following steps:
# 1. comment the DEPLOYMENTFOLDERS += qmlFolder line above, to avoid shipping your qml files with the application (instead they get compiled to the app binary)
# 2. uncomment the resources.qrc file inclusion and add any qml subfolders to the .qrc file; this compiles your qml files and js files to the app binary and protects your source code
# 3. change the setMainQmlFile() call in main.cpp to the one starting with "qrc:/" - this loads the qml files from the resources
# for more details see the "Deployment Guides" in the Felgo Documentation

# during development, use the qmlFolder deployment because you then get shorter compilation times (the qml files do not need to be compiled to the binary but are just copied)
# also, for quickest deployment on Desktop disable the "Shadow Build" option in Projects/Builds - you can then select "Run Without Deployment" from the Build menu in Qt Creator if you only changed QML files; this speeds up application start, because your app is not copied & re-compiled but just re-interpreted


# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += $${PWD}/src/DatabaseApplication.cpp \
    $${PWD}/src/MainApplication.cpp \
    $${PWD}/src/ModelApplication.cpp \
    $${PWD}/src/db/ScoreDAO.cpp \
    $${PWD}/src/db/UserDAO.cpp \
    $${PWD}/src/obj/Score.cpp \
    $${PWD}/src/obj/User.cpp \
    $${PWD}/src/tools/ScoreList.cpp \
    $${PWD}/src/tools/Tools.cpp


android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += $${PWD}/android/AndroidManifest.xml       $${PWD}/android/build.gradle
}

ios {
    QMAKE_INFO_PLIST = $${PWD}/ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += $${PWD}/win/app_icon.rc
}
macx {
    ICON = $${PWD}/macx/app_icon.icns
}

#DISTFILES += \
#    qml/MainItem.qml \
#    qml/common/AudioManager.qml \
#    qml/common/Background.qml \
#    qml/common/Ground.qml \
#    qml/common/Language.qml \
#    qml/common/SceneBase.qml \
#    qml/common/Style.qml \
#    qml/entities/BorderElement.qml \
#    qml/entities/Bullet.qml \
#    qml/entities/Capsule.qml \
#    qml/entities/Flag.qml \
#    qml/entities/Monster.qml \
#    qml/entities/Platform.qml \
#    qml/entities/Player.qml \
#    qml/entities/ResetSensor.qml \
#    qml/entities/Splat.qml \
#    qml/entities/Tile.qml \
#    qml/entities/TileEntityBase.qml \
#    qml/game/GameOverScreen.qml \
#    qml/game/Level.qml \
#    qml/game/LevelBase.qml \
#    qml/game/Numbers.qml \
#    qml/game/WaitScreen.qml \
#    qml/game/WinScreen.qml \
#    qml/scenes/AccountScene.qml \
#    qml/scenes/BackScene.qml \
#    qml/scenes/Connection.qml \
#    qml/scenes/ConnectionScene.qml \
#    qml/scenes/CreditsScene.qml \
#    qml/scenes/GameScene.qml \
#    qml/scenes/ImageButton.qml \
#    qml/scenes/InputLine.qml \
#    qml/scenes/Menu.qml \
#    qml/scenes/MenuScene.qml \
#    qml/scenes/Scores.qml \
#    qml/scenes/ScoresScene.qml \
#    qml/scenes/SettingsScene.qml \
#    qml/scenes/SignUpScene.qml \
#    qml/scenes/SplashScreenScene.qml

HEADERS += \
    $${PWD}/inc/DatabaseApplication.h \
    $${PWD}/inc/MainApplication.h \
    $${PWD}/inc/ModelApplication.h \
    $${PWD}/inc/db/ScoreDAO.h \
    $${PWD}/inc/db/UserDAO.h \
    $${PWD}/inc/obj/Score.h \
    $${PWD}/inc/obj/User.h \
    $${PWD}/inc/tools/Enums.h \
    $${PWD}/inc/tools/ScoreList.h \
    $${PWD}/inc/tools/Tools.h

INCLUDEPATH += \
    $${PWD}/inc/obj/ \
    $${PWD}/inc/tools/ \
    $${PWD}/src/tools/ \
    $${PWD}/inc/db/ \
    $${PWD}/inc/ \
    $${PWD}/src/
android: include(C:/Users/ariffaud/AppData/Local/Android/Sdk/android_openssl/openssl.pri)
