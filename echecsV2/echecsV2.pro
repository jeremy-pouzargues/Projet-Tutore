TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CExc.cpp \
        Piece.cpp \
        chessboard.cpp \
        main.cpp

HEADERS += \
    CExc.h \
    ChessBoard.h \
    Const.h \
    Piece.h
