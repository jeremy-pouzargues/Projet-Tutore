#ifndef CHOOSEPIECEINTERFACE_H
#define CHOOSEPIECEINTERFACE_H

#include <QMessageBox>

#include <QMainWindow>

#include "Chessboard/Chessboard.h"

class ChoosePieceInterface : public QMessageBox
{
    Q_OBJECT
public:
    explicit ChoosePieceInterface(ChessBoard * hisChessBoard,const pairCoord coordMoveDD,const pairCoord coordPieceDD/*,GfxObject * GraphicalObject*/);
    ~ChoosePieceInterface();

private slots:
    void emitKnight();
    void emitBishop();
    void emitQueen();
    void emitRook();

private:
    const pairCoord coordMove;
    const pairCoord coordPiece;

    ChessBoard * hisBoard;
//    GfxObject * currentGraphicalObject;
};

#endif // CHOOSEPIECEINTERFACE_H
