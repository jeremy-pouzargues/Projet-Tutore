#ifndef PION_H
#define PION_H

#include "Piece.h"

enum Color {blanc, noir};

class Pion : public Piece
{
private:
    Color myColor;
    pairCoord myPosition;
public:
    Pion(const Color & color,const pairCoord & coord);
    virtual pairCoord move(const Piece & piece, const unsigned & x, const unsigned & y);
};

#endif // PION_H
