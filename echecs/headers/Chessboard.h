/**
 * @file   ChessBoard.h
 * @author Laurent
 * @brief  classe echiquier avec un vecteur de vecteur de char qui represente l'echiquier, un vecteur de pieces pour chaque couleurs
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
//typedef std::vector<Piece *> VPieces;

class ChessBoard {
private:
    Matrix myChessBoard;
    //VPieces myPiecesW; //vecteur des pieces blanches
    //VPieces myPiecesB; //vecteur des pieces noires

public:
     ChessBoard();

     // getters/setters
     //VPieces getPieces(const Color & color);
     //void    setPieces(const Color & color, const VPieces & newVPieces);

     /**
      * @brief affiche la matrice avec les pieces selon leurs coordonnées
      */
     void show() const;

     /**
      * @brief trouve une piece par ses coordonnées dans un vecteur de pieces
      * @param pairCoord coord
      * @param VPieces vpieces
      * @return l'indice de la piece si trouvée sinon throw une exception
      */
    // unsigned find(const pairCoord & coord, const VPieces & vpieces);

     /**
      * @brief met à jour la matrice selon le déplacement d'une piece par un joueur
      * @param pairCoord oldCoord : coordonnées de la piece à bouger, qui vont être remplacés par une case "vide"
      * @param pairCoord newCoord : coordonnées de la piece après le mouvement, on va verifier si le mouvement est légal à
      * l'aide de la fonction surchargée move() de la piece concernée.
      * @param Color color : permet de savoir quel vecteur de pieces on manipule
      */
     void actualize(const pairCoord & oldCoord, const pairCoord & newCoord,const Color & color);

     //getter
     Matrix getChessboard() const;

};//Echiquier


#endif // ECHIQUIER_H
