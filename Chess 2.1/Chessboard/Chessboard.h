/**
 * @file   ChessBoard.h
 * @author Leo, Laurent
 * @brief  classe echiquier avec un vecteur de vecteur de Piece, un matrice, qui represente l'echiquier
 * @class  Echiquier Echiquier.h "include Echiquier.h"
 * @version 1.0
 **/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Pieces/Piece.h"

#include <QWidget>                          //FRANFRAN
#include "GraphicalObject/GfxObject.h"      //A RM SI CYCLIQUE AH1
class GfxObject;                            //A RM SI CICLIQUE AH1
class Piece;                                //A RM SI CICLIQUE AH2

typedef std::vector<std::vector<std::shared_ptr<Piece>>> Matrix;
typedef std::vector<std::shared_ptr<Piece>> VPieces;

class MainWindow;  // A RMMMMMMMMMMMMMMMMMMM

class ChessBoard {
private:
    Matrix myChessBoard; // matrice de toutes les cases/pieces
    VPieces myPiecesW; //vecteur des pieces blanches
    VPieces myPiecesB; //vecteur des pieces noires
    VPieces myDeadPiecesW;
    VPieces myDeadPiecesB;

    QString * selectedPiece;                                                    //FRANFRAN //Piece selectionné au clique
    QString   choosedPiece;                                                     //FRANFRAN //Piece choisi pour la transformation
    inline static std::vector<std::vector< GfxObject * >> hisGraphicalVector;   //FRANFRAN
    pairCoord                   CoordClicked; //Pair de l'object cliquer        //FRANFRAN
    bool                        AnyoneClicked;                                  //FRANFRAN
    bool                        switchMove;                                     //FRANFRAN

    bool                        EndSignal;                                      //FRANFRAN

public:
     ChessBoard();
     ChessBoard(const Matrix & chessBoard, const VPieces & piecesW, const VPieces & PiecesB, const VPieces & deadPiecesW, const VPieces & deadPiecesB);
     ChessBoard & operator= (const ChessBoard & chessboard);

     /**
      * @brief affiche la matrice avec les pieces selon leurs coordonnées
      */
     void show() const;
     Matrix copyMatrix(const Matrix & matrixCopy);
     VPieces copyVPieces(const VPieces & VPiecesCopy);

     //getter
     const Matrix  & getChessboard() const;
     const VPieces & getMyDeadPieceB () const;
     const VPieces & getMyDeadPieceW () const;
     const VPieces & getPiecesW () const;
     const VPieces & getPiecesB () const;

     const ChessBoard getBuffChessboard (ChessBoard chessboard) const;

     const Matrix  getBuffChessboard (Matrix matrix)const;
     const VPieces getBuffDeadPieceB (VPieces vDeadPieceB) const;
     const VPieces getBuffDeadPieceW (VPieces vDeadPieceW) const;
     const VPieces getBuffPiecesW (VPieces vPiecesW) const;
     const VPieces getBuffPiecesB (VPieces vPiecesB) const;

     //setter
     void setChessboard (const Matrix & newChessboard);
     void setDeadPieceW (const VPieces & newVDeadPiece);
     void setDeadPieceB (const VPieces & newVDeadPiece);
     void setPiecesW (const VPieces & newVPieceW);
     void setPiecesB (const VPieces & newVPieceB);

     void move(const pairCoord & coordMove,const pairCoord & coordPiece);

     void swap(const pairCoord & coordMove,const pairCoord & coordPiece);
     bool find (const std::vector<pairCoord> & legalMoves, const pairCoord & moveChosen);
     std::vector<std::vector<pairCoord>> getVEatOpponent(const VPieces & VPiecesOpponent);

     std::vector<pairCoord> matrixToVector (const std::vector<std::vector<pairCoord>> & matrixCoord);

     bool isCheckMate (const bool & player);




     void display(QWidget * currentPage,MainWindow * hisMainWindow); //ANCIENNEMENT SHOW //FRANFRAN

     void switchClickedSignal();  //FRANFRAN
     bool const & getSignal();  //FRANFRAN
     void getBoardClear();   //FRANFRAN
     void setGraphicalLegalMoves (std::vector<pairCoord> legalMoves);  //FRANFRAN

     pairCoord getCoordClicked() const;  //FRANFRAN
     void setCoordClicked(const pairCoord &value);  //FRANFRAN

     QString getChoosedPiece() const;  //FRANFRAN
     void setChoosedPiece(QString value);  //FRANFRAN
     bool getSwitchMove() const;  //FRANFRAN
     void setSwitchMove(bool value);  //FRANFRAN

     void refreshGraphicalVector();  //FRANFRAN


     bool getEndSignal() const; //FRANFRAN
     void setEndSignal(bool value); //FRANFRAN

//     static std::vector<std::vector<GfxObject *> > getHisGraphicalVector();
};//Echiquier


#endif // ECHIQUIER_H
