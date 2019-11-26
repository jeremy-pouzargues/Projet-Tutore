#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

class King : public Piece
{
private:
public:
    King() {}
    King(const Color & color,const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);
};

#endif // KING_H
