QT += testlib

CONFIG += qt depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++11

#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
TEMPLATE = app

SOURCES += \
    $$PWD/src/dao/tst_testscoredao.cpp \
    $$PWD/src/tools/TestTools.cpp \
    $$PWD/src/main.cpp \
    $$PWD/src/dao/tst_testuserdao.cpp \
    $$PWD/src/tst_database.cpp \
    $$PWD/src/tst_testmain.cpp \
    $$PWD/src/obj/tst_testmodel.cpp \

HEADERS += \
    $$PWD/inc/dao/tst_testscoredao.h \
    $$PWD/inc/tools/TestTools.h \
    $$PWD/inc/dao/tst_testuserdao.h \
    $$PWD/inc/tst_database.h \
    $$PWD/inc/tst_testmain.h \
    $$PWD/inc/obj/tst_testmodel.h \

INCLUDEPATH += $${PWD}/inc

# includes from the main project
INCLUDEPATH += ../ApsGame/inc/ \
    ../ApsGame/inc/obj/ \
    ../ApsGame/inc/tools/ \
    ../ApsGame/inc/db/ \
    ../ApsGame/src/ \
    ../ApsGame/src/obj/ \
    ../ApsGame/src/tools/ \
    ../ApsGame/src/db/ \
    ../ApsGame/ \
    $${PWD}/inc/ \
    $${PWD}/src/ \
    $${PWD}/inc/dao/ \
    $${PWD}/inc/obj/ \
    $${PWD}/inc/tools/ \
    $${PWD}/src/dao/ \
    $${PWD}/src/obj/ \
    $${PWD}/src/tools/

include(../ApsGame/ApsGame.pro)
