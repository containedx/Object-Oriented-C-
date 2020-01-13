QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test1.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../fromlab11/release/ -lfromlab11
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../fromlab11/debug/ -lfromlab11
else:unix: LIBS += -L$$OUT_PWD/../../fromlab11/ -lfromlab11

INCLUDEPATH += $$PWD/../../fromlab11
DEPENDPATH += $$PWD/../../fromlab11
