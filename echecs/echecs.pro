TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Echiquier.cpp \
        King.cpp \
        Piece.cpp \
        Pion.cpp \
        Rook.cpp \
        main.cpp

HEADERS += \
    Echiquier.h \
    King.h \
    Piece.h \
    Pion.h \
    Rook.h
