#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{

public:
    Rook (const Color & color,const pairCoord & coord);
    virtual pairCoord move(Piece & piece, const pairCoord & coord);

};

#endif // ROOK_H
