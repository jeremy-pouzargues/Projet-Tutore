#ifndef CHOOSEPIECEWINDOW_H
#define CHOOSEPIECEWINDOW_H

#include <QMainWindow>

#include "Chessboard/Chessboard.h"

////A RM SI CICLIQUE 19 DEC
//#include "Pieces/Pawn.h"
//#include "Pieces/Empty.h"
//#include "Pieces/Rook.h"
//#include "Pieces/Knight.h"
//#include "Pieces/Bishop.h"
//#include "Pieces/Queen.h"
//#include "Pieces/King.h"
////A RM SI CICLIQUE 19 dec

namespace Ui {
    class ChoosePieceWindow;
}

class ChoosePieceWindow : public QMainWindow
{
    Q_OBJECT
//const pairCoord & coordMove,const pairCoord & coordPiece
public:
//    explicit ChoosePieceWindow(QWidget *parent /*= nullptr*/ ,ChessBoard * hisChessBoard,const pairCoord coordMove,const pairCoord coordPiece);
    explicit ChoosePieceWindow(QWidget *parent,ChessBoard * hisChessBoard,const pairCoord coordMoveDD,const pairCoord coordPieceDD,GfxObject * GraphicalObject);
    ~ChoosePieceWindow();

//    const pairCoord *getCoordMove() const;
//    void setCoordMove(const pairCoord *value);

//    const pairCoord *getCoordPiece() const;
//    void setCoordPiece(const pairCoord *value);

private slots:
    //    void emitPiece(QString * pieceSelected);
    void emitKnight();
    void emitBishop();
    void emitQueen();
    void emitRook();

private:
    const pairCoord coordMove;
    const pairCoord coordPiece;

    ChessBoard * hisBoard;
    Ui::ChoosePieceWindow *ui;
    GfxObject * currentGraphicalObject;
};

#endif // CHOOSEPIECEWINDOW_H
