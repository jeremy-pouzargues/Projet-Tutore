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
#include "Piece.h"

typedef std::vector<std::vector<std::shared_ptr<Piece>>> Matrix;
typedef std::vector<std::shared_ptr<Piece>> VPieces;

//typedef std::vector<Piece *> VPieces;

class ChessBoard {
private:
    Matrix myChessBoard; // matrice de toutes les cases/pieces
    Matrix myDeadPiece; //matrice des pieces mortes
    VPieces myPiecesW; //vecteur des pieces blanches
    VPieces myPiecesB; //vecteur des pieces noires

public:
     ChessBoard();

     /**
      * @brief affiche la matrice avec les pieces selon leurs coordonnées
      */
     void show() const;



     void move(const pairCoord & coordMove,const pairCoord & coordPiece);

     void swap(const pairCoord & coordMove,const pairCoord & coordPiece);
     bool find (const std::vector<pairCoord> & legalMoves, const pairCoord & moveChosen);
     std::vector<std::vector<pairCoord>> getVEatOpponent(const VPieces & VPiecesOpponent);

     std::vector<pairCoord> matrixToVector (const std::vector<std::vector<pairCoord>> & matrixCoord);

     //getters 	
     const Matrix  & getChessboard()     const;
     const Matrix  & getDeadPiece ()  const;
     const VPieces & getPiecesW ()      const;
     const VPieces & getPiecesB ()      const;
     //setters
     void setChessboard (const Matrix & newChessboard);
     void setDeadPiece (const Matrix & newVDeadPiece);
     void setPiecesW (const VPieces & newVPieceW);
     void setPiecesB (const VPieces & newVPieceB);

};//Echiquier


#endif // ECHIQUIER_H
