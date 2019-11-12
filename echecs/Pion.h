#ifndef PION_H
#define PION_H

#include "Piece.h"


class Pion : public Piece
{

public:
    Pion (const Color & color,const pairCoord & coord);
    virtual pairCoord move(Piece & piece, const pairCoord & coord);
};

#endif // PION_H
