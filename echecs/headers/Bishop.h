/**
 * @file Bishop.h include "headers/Bishop.h"
 * @author Léo
 * @brief classe du fou fille de Piece
 * @version 1.1
 */
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

/**
 * @brief classe du fou
 * @class Bishop : public Piece
 */
class Bishop : public Piece
{
public:
    Bishop(){}
    Bishop(const Color & color,const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );


    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                               const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // BISHOP_H
