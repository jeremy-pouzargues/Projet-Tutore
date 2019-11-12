TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        King.cpp \
        ChessBoard.cpp \
        Rook.cpp \
        main.cpp

HEADERS += \
    King.h \ 
    Rook.h
    ChessBoard.h \
    Pawn.h \
    Piece.h

