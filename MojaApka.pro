QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += sql
QT += widgets
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += /usr/include
INCLUDEPATH += /usr/

LIBS += -L/usr/lib -lsqlite3
LIBS += -lcryptopp


SOURCES += \
    encryptiobyaes.cpp \
    encup.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationo.cpp \
    sklfun.cpp
HEADERS += \
    encrytpionbyaes.h \
    encup.h \
    mainwindow.h \
    registrationo.h \
    sklpog.h
FORMS += \
    encup.ui \
    mainwindow.ui \
    registrationo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    tabelki.db

