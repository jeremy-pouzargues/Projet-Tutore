QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11
CONFIG += console c++11
QT += widgets

SOURCES += \
        Chessboard/Chessboard.cpp \
        GraphicalObject/ChoosePieceWindow.cpp \
        GraphicalObject/Chrono.cpp \
        GraphicalObject/GfxObject.cpp \
        GraphicalObject/creditProfile.cpp \
        GraphicalObject/gameMessageBox.cpp \
        GraphicalObject/mainwindow.cpp \
        GraphicalObject/windowCommandsButton.cpp \
        Pieces/Bishop.cpp \
        Pieces/Empty.cpp \
        Pieces/King.cpp \
        Pieces/Knight.cpp \
        Pieces/Pawn.cpp \
        Pieces/Piece.cpp \
        Pieces/Queen.cpp \
        Pieces/Rook.cpp \
        Thread/initThread.cpp \
        Utils/CExc.cpp \
        main.cpp

DISTFILES += \
    Chess.pro.user \
    Chess/Chess.pro.user \
    Ressources/Pieces/Bishop.psd \
    Ressources/Pieces/BishopBlack.png \
    Ressources/Pieces/BishopWhite.png \
    Ressources/Pieces/King.psd \
    Ressources/Pieces/KingBlack.png \
    Ressources/Pieces/KingWhite.png \
    Ressources/Pieces/Knight.psd \
    Ressources/Pieces/KnightBlack.png \
    Ressources/Pieces/KnightWhite.png \
    Ressources/Pieces/PawnBlack.png \
    Ressources/Pieces/PawnWhite.png \
    Ressources/Pieces/PawnWhite.psd \
    Ressources/Pieces/Queen.psd \
    Ressources/Pieces/QueenBlack.png \
    Ressources/Pieces/QueenWhite.png \
    Ressources/Pieces/Rook.psd \
    Ressources/Pieces/RookBlack.png \
    Ressources/Pieces/RookWhite.png \
    Ressources/Users/2lo.jpg \
    Ressources/Users/fran.png \
    Ressources/Users/jerem.jpg \
    Ressources/Users/leo.jpg \
    Ressources/Window/arrow.png \
    Ressources/Window/arrow.psd \
    Ressources/Window/arrowWhite.png \
    Ressources/Window/background.png \
    Ressources/Window/background.psd \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/.qmake.stash \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/Makefile \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/Makefile.Debug \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/Makefile.Release \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Bishop.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/CExc.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Chess.exe \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Chessboard.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Empty.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/King.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Knight.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Pawn.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Piece.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Queen.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/Rook.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/debug/main.o \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/object_script.Chess.Debug \
    build-Chess-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/object_script.Chess.Release

HEADERS += \
    Chessboard/Chessboard.h \
    GraphicalObject/ChoosePieceWindow.h \
    GraphicalObject/Chrono.h \
    GraphicalObject/GfxObject.h \
    GraphicalObject/creditProfile.h \
    GraphicalObject/gameMessageBox.h \
    GraphicalObject/mainwindow.h \
    GraphicalObject/windowCommandsButton.h \
    IA/minmax.h \
    IA/minmax.hpp \
    Pieces/Bishop.h \
    Pieces/Empty.h \
    Pieces/King.h \
    Pieces/Knight.h \
    Pieces/Pawn.h \
    Pieces/Piece.h \
    Pieces/Queen.h \
    Pieces/Rook.h \
    Thread/initThread.h \
    Utils/CExc.h \
    Utils/Const.h

RESOURCES += \
    QtRessourcePath.qrc

FORMS += \
    GraphicalObject/ChoosePieceWindow.ui \
    GraphicalObject/mainwindow.ui
