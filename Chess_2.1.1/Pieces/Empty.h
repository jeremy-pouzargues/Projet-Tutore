/**
 * @author Leo
 * @file   Empty.h
 * @version 1.2
 */

#ifndef EMPTY_H
#define EMPTY_H

#include "Piece.h"

/**
 * @brief classe de la pièce vide, fille de Piece
 * @class Empty include "Pieces/Empty.h"
 */
class Empty : public Piece
{
public:
    Empty(){}
    Empty(const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix ) {}

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // EMPTY_H
