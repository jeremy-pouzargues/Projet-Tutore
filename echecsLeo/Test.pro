TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Bishop.cpp \
        CExc.cpp \
        Chessboard.cpp \
        Empty.cpp \
        Pawn.cpp \
        Piece.cpp \
        Queen.cpp \
        Rook.cpp \
        main.cpp

HEADERS += \
    Bishop.h \
    CExc.h \
    Chessboard.h \
    Const.h \
    Empty.h \
    Pawn.h \
    Piece.h \
    Queen.h \
    Rook.h
