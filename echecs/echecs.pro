TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CExc.cpp \
        ChessBoard.cpp \
        Pawn.cpp \
        Piece.cpp \
        main.cpp

HEADERS += \
    CExc.h \
    ChessBoard.h \
    CteErr.h \
    Pawn.h \
    Piece.h
