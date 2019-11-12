#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>

#include "Pawn.h"

/**
 * @author Laurent
 * @brief echiquier
 * @class Echiquier Echiquier.h "include Echiquier.h"
 **/

typedef std::vector<std::vector<char>> Matrix;

class ChessBoard
{
private:
    Matrix myChessBoard;
    std::vector<Piece> myPieces;
public:
     ChessBoard(Piece & piece);

     void show() const;

     void actualize(Piece & piece, const pairCoord & newCoord);
};//Echiquier


#endif // ECHIQUIER_H
