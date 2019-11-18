#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>

#include "Pawn.h"

/**
 * @author Laurent
 * @brief  echiquier
 * @class  Echiquier Echiquier.h "include Echiquier.h"
 **/
typedef std::vector<std::vector<char>> Matrix;
typedef std::vector<Piece *> VPieces;

class ChessBoard {
private:
    Matrix myChessBoard;
    VPieces myPiecesW; //vecteur des pieces blanches
    VPieces myPiecesB; //vecteur des pieces noires

public:
     ChessBoard();

     void show() const;

     unsigned find(const pairCoord & coord, const VPieces & vpieces);

     void actualize(const pairCoord & oldCoord, const pairCoord & newCoord,const Color & color);

     VPieces getPieces(const Color & color);
     void    setPieces(const Color & color, const VPieces & newVPieces);
};//Echiquier


#endif // ECHIQUIER_H
