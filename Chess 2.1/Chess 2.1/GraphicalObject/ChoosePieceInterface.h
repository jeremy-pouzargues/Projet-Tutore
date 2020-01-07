#ifndef CHOOSEPIECEINTERFACE_H
#define CHOOSEPIECEINTERFACE_H

#include <QMessageBox>

#include <QMainWindow>

#include "Chessboard/Chessboard.h"

#include "GraphicalObject/QCustomMessageBox.h"

class ChoosePieceInterface : public QCustomMessageBox
{
    Q_OBJECT
public:
    explicit ChoosePieceInterface(ChessBoard * hisChessBoard,const pairCoord coordMoveDD,const pairCoord coordPieceDD/*,GfxObject * GraphicalObject*/);
    ~ChoosePieceInterface();
private:
    const pairCoord coordMove;
    const pairCoord coordPiece;

    ChessBoard * hisBoard;
//    GfxObject * currentGraphicalObject;
};

#endif // CHOOSEPIECEINTERFACE_H
