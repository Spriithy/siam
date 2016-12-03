TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pion.cpp \
    grille.cpp \
    manager.cpp \
    partie.cpp

HEADERS += \
    pion.h \
    direction.h \
    grille.h \
    manager.h \
    partie.h
