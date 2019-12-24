/**
 * @author Jérémy
 * @file Pawn.h include "headers/Pawn.h"
 * @version 1.3
 */
#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"
/**
 * @brief classe du pion dérive de Piece
 * @version 1.3
 * @class Pawn : public Piece
 * @date 20/11/2019
 */
class Pawn : public Piece
{
private:
public:
    Pawn() {}
    Pawn(const Color & color,const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);


    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // PAWN_H
