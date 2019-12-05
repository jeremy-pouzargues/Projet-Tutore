TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Bishop.cpp \
        CExc.cpp \
        Chessboard.cpp \
        Empty.cpp \
        King.cpp \
        Knight.cpp \
        Pawn.cpp \
        Piece.cpp \
        Queen.cpp \
        Rook.cpp \
        main.cpp

DISTFILES += \
    echecsV1.mdj

HEADERS += \
    headers/Bishop.h \
    headers/CExc.h \
    headers/Chessboard.h \
    headers/Const.h \
    headers/Empty.h \
    headers/King.h \
    headers/Knight.h \
    headers/Pawn.h \
    headers/Piece.h \
    headers/Queen.h \
    headers/Rook.h \
    Bishop.h \
    CExc.h \
    Chessboard.h \
    Const.h \
    Empty.h \
    King.h \
    Knight.h \
    Pawn.h \
    Piece.h \
    Queen.h \
    Rook.h \
    headers/minmax.h
