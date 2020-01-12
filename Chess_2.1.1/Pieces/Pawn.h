/**
 * @author Jérémy
 * @file Pawn.h
 * @version 1.1
 */
#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"
/**
 * @brief classe du pion, fille de Piece
 * @class Pawn include "Pieces/Pawn.h"
 */
class Pawn : public Piece
{
private:
public:
    Pawn() {}
    Pawn(const Color & color, const pairCoord & coord);
    Pawn(const Color & color, const pairCoord & coord, const pairCoord & initCoord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);


    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // PAWN_H
