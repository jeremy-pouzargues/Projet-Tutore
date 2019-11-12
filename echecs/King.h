#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{

public:
    King (const Color & color,const pairCoord & coord);
    virtual pairCoord move(Piece & piece, const pairCoord & coord);
};

#endif // KING_H
