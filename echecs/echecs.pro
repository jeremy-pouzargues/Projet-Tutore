TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ChessBoard.cpp \
        Piece.cpp \
        Pion.cpp \
        main.cpp

HEADERS += \
    ChessBoard.h \
    Pawn.h \
    Piece.h
