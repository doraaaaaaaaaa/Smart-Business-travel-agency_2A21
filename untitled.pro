QT       += core gui
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
QT += printsupport network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG +=console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    hebergement.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    picture.cpp \
    smtp.cpp \
    statistique.cpp

HEADERS += \
    connection.h \
    hebergement.h \
    mail.h \
    mainwindow.h \
    picture.h \
    smtp.h \
    statistique.h

FORMS += \
    mail.ui \
    mainwindow.ui \
    picture.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
