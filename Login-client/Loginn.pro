QT       += core gui sql

QT += printsupport
QT       += core gui sql network multimedia charts serialport

QT       += core gui sql multimedia multimediawidgets charts
QT += charts
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    arduino.cpp \
    arduinoclient.cpp \
    client.cpp \
    client_workspace.cpp \
    connexion.cpp \
    employee.cpp \
    exportexcelobject.cpp \
    gest_employee.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mydialog.cpp \
    pie.cpp \
    piechartwidget.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    stat_combo.cpp \
    statistique.cpp

HEADERS += \
    arduino.h \
    arduinoclient.h \
    client.h \
    client_workspace.h \
    connexion.h \
    date.h \
    employee.h \
    exportexcelobject.h \
    gest_employee.h \
    login.h \
    mainwindow.h \
    mydialog.h \
    pie.h \
    piechartwidget.h \
    qcustomplot.h \
    smtp.h \
    stat_combo.h \
    statistique.h

FORMS += \
    client_workspace.ui \
    gest_employee.ui \
    mainwindow.ui \
    mydialog.ui \
    pie.ui \
    piechartwidget.ui \
    stat_combo.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
