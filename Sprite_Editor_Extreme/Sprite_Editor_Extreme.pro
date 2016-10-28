#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T10:26:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sprite_Editor_Extreme
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grid.cpp \
    controller.cpp \
    model.cpp \
    project.cpp \
    tool.cpp \
    createnew.cpp

HEADERS  += mainwindow.h \
    grid.h \
    controller.h \
    model.h \
    project.h \
    tool.h \
    createnew.h

FORMS    += mainwindow.ui \
    createnew.ui

RESOURCES += \
    resources.qrc
