/**
 * @file   ChoosePieceInterface.h
 * @author François
 * @brief  Interface graphique qui demande une pièce à l'utilisateur
 * @version 1.3
 **/

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
    explicit ChoosePieceInterface(ChessBoard * hisChessBoard,const pairCoord coordMoveDD,const pairCoord coordPieceDD);
    ~ChoosePieceInterface();
private:
    const pairCoord coordMove;
    const pairCoord coordPiece;

    ChessBoard * hisBoard;
};

#endif // CHOOSEPIECEINTERFACE_H
