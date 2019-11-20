/**
* @author Laurent
* @version 1.0
* @class Pion "Pion.h" derivée de Piece
* @brief Classe fille de la classe Piece qui surcharge la methode move
*/

#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"


class Pawn : public Piece
{

public:
    Pawn() {}
    Pawn(const Color & color,const pairCoord & coord);
    virtual pairCoord move(const pairCoord & coord);
};

#endif // Pawn_H
