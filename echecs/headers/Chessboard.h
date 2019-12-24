/**
 * @file   ChessBoard.h include "incldue/ChessBoard.h"
 * @author Leo, Laurent
 * @version 1.2
 **/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Piece.h"

typedef std::vector<std::vector<std::shared_ptr<Piece>>> Matrix;
typedef std::vector<std::shared_ptr<Piece>> VPieces;

/**
 * @class ChessBoard
 * @brief classe de l'échiquier
 * classe qui va représenter notre echiquier, avec des vecteurs pour les pièces de chaque couleurs(vivantes ou mortes)
 * l'echiquier est représenté par une matrice  de Piece
 */
class ChessBoard {
private:
    Matrix  myChessBoard; // matrice de toutes les cases/pieces
    VPieces myPiecesW; //vecteur des pieces blanches
    VPieces myPiecesB; //vecteur des pieces noires
    VPieces myDeadPiecesW;
    VPieces myDeadPiecesB;

public:
     ChessBoard();


     //getters
     const Matrix  & getChessboard()    const;
     const VPieces & getMyDeadPieceB () const;
     const VPieces & getMyDeadPieceW () const;
     const VPieces & getPiecesW ()      const;
     const VPieces & getPiecesB ()      const;

     //setters
     void setChessboard (const Matrix & newChessboard);
     void setDeadPieceW (const VPieces & newVDeadPiece);
     void setDeadPieceB (const VPieces & newVDeadPiece);
     void setPiecesW    (const VPieces & newVPieceW);
     void setPiecesB    (const VPieces & newVPieceB);
     /**
      * @brief affiche la matrice avec les pieces selon leurs coordonnées, utile pour la version console de l'échiquier...
      */
     void show() const;
     /**
      * @brief fonction de déplacement de la pièce
      * @param coordMove  : coordonnées de déplacement de la pièce
      * @param coordPiece : coordonnées actuelles de la pièce
      */
     void move(const pairCoord & coordMove,const pairCoord & coordPiece);
     /**
      * @brief utilisé pour faire échanger de place un Piece et une case vide (objet empty)
      * @param coordMove : coordonnées de déplacement de la pièce
      * @param coordPiece : coordonnées actuelles de la pièce
      */
     void swap(const pairCoord & coordMove,const pairCoord & coordPiece);
     /**
      * @brief trouver une pièce
      * @param legalMoves : liste des possibles légaux d'une pièce
      * @param moveChosen : case déplacement choisit par le joueur
      * @return bool : true  si la pièce est trouvée, sinon false
      */
     bool find (const std::vector<pairCoord> & legalMoves, const pairCoord & moveChosen);
     /**
      * @brief getVEatOpponent
      * @param VPiecesOpponent : vecteur des pièces adverses
      * @return matrice de pairCoord
      */
     std::vector<std::vector<pairCoord>> getVEatOpponent(const VPieces & VPiecesOpponent);
     /**
      * @brief transforme la matrice en vecteur
      * @param matrixCoord
      * @return vecteur<pairCoord> : vecteur des paires de coordonnées
      */
     std::vector<pairCoord> matrixToVector (const std::vector<std::vector<pairCoord>> & matrixCoord);
};//Echiquier


#endif // ECHIQUIER_H
