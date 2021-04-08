
QT       += core gui sql multimedia multimediawidgets charts
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuil.cpp \
    accident.cpp \
    chart.cpp \
    connection.cpp \
    envoie.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp \
    violence.cpp

HEADERS += \
    acceuil.h \
    accident.h \
    chart.h \
    connection.h \
    envoie.h \
    login.h \
    mainwindow.h \
    smtp.h \
    violence.h

FORMS += \
    acceuil.ui \
    chart.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    img/authentification.png \
    img/lock.png \
    img/monote.jpg \
    img/pdclogin.png \
    img/user.png
