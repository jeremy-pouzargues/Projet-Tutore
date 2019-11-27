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
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );
};

#endif // BISHOP_H
