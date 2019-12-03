/**
 * @author Jérémy
 * @file Pawn.h
 * @version 1.1
 * @brief classe du pion, fille de Piece
 * @class Pawn include "headers/Pawn.h"
 */
#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"
/**
 * @brief The Pawn class
 * @version 1.0
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
                                              const std::vector<std::shared_ptr<Piece>> & VPiecesOpponent) {}
};

#endif // PAWN_H
