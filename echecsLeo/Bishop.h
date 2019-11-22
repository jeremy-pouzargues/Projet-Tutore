#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "Piece.h"


class Bishop : public Piece
{
public:
    Bishop(){}
    Bishop(const Color & color,const pairCoord & coord);
    virtual void move(const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const pairCoord & coord,const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );
};

#endif // BISHOP_H
