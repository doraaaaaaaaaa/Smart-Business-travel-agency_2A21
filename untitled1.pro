QT += widgets
QT       += core gui
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer
QT       += core printsupport  gui sql network serialport axcontainer
QT += printsupport network
QT +=sql
QT += widgets
QT += printsupport
QT += core
QT += core gui charts
QT += charts
QT += network
QT += quick
QT += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer
QT += gui
QT+= sql
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Mail.cpp \
    arduino.cpp \
    arduino1.cpp \
    connexion1.cpp \
    dialog1.cpp \
    employe.cpp \
    exportexcel.cpp \
    hebergement.cpp \
    localisation.cpp \
    main1.cpp \
    mainwindow1.cpp \
    mission.cpp \
    partenaire.cpp \
    picture.cpp \
    smtp.cpp \
    stat1.cpp \
    statistique2.cpp \
    vol.cpp

HEADERS += \
    Mail.h \
    arduino.h \
    arduino1.h \
    connexion1.h \
    dialog1.h \
    employe.h \
    exportexcel.h \
    hebergement.h \
    localisation.h \
    mainwindow1.h \
    mapping.h \
    mission.h \
    partenaire.h \
    picture.h \
    smtp.h \
    stat1.h \
    statistique2.h \
    vol.h

FORMS += \
    Mail.ui \
    dialog1.ui \
    localisation.ui \
    mainwindow1.ui \
    picture.ui \
    stat1.ui \
    statistique2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc

