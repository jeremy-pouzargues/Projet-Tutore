TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CExc.cpp \
        Chessboard.cpp \
        Empty.cpp \
        Pawn.cpp \
        Piece.cpp \
        Rook.cpp \
        main.cpp

HEADERS += \
    CExc.h \
    Chessboard.h \
    Const.h \
    Empty.h \
    Pawn.h \
    Piece.h \
    Rook.h
