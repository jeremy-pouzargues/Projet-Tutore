/**
 * @file Bishop.h
 * @author Léo
 * @brief classe du fou fille de Piece
 * @class Bishop include "headers/Bishop.h"
 * @version 1.0
 */
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"


class Bishop : public Piece
{
public:
    Bishop(){}
    Bishop(const Color & color,const pairCoord & coord);
    Bishop(const Color & color, const pairCoord & coord, const pairCoord & initCoord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );


    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                               const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // BISHOP_H
