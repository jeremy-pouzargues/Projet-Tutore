#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"


class Pawn : public Piece
{

public:
    Pawn (const Color & color,const pairCoord & coord);
    virtual pairCoord move(const pairCoord & coord);
};

#endif // Pawn_H
