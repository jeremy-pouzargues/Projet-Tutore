#ifndef CHOOSEPIECEWINDOW_H
#define CHOOSEPIECEWINDOW_H

#include <QMainWindow>

#include "Chessboard/Chessboard.h"

namespace Ui {
    class ChoosePieceWindow;
}

class ChoosePieceWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChoosePieceWindow(QWidget *parent,ChessBoard * hisChessBoard,const pairCoord coordMoveDD,const pairCoord coordPieceDD);
    ~ChoosePieceWindow();

private slots:
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
