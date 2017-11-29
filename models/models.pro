TARGET = model
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += sql
QT -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += qml
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects mongoobjects
DEPENDPATH  += ../helpers sqlobjects mongoobjects
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/blogobject.h
HEADERS += blog.h
SOURCES += blog.cpp
HEADERS += sqlobjects/playerobject.h
HEADERS += player.h
SOURCES += player.cpp
HEADERS += sqlobjects/weaponobject.h
HEADERS += weapon.h
SOURCES += weapon.cpp
HEADERS += sqlobjects/monsterobject.h
HEADERS += monster.h
SOURCES += monster.cpp
