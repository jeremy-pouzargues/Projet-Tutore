/**
 * @author Leo
 * @file   Queen.h include "headers/Queen.h"
 * @version 1.1
 */
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

/**
 * @brief classe de la reine
 * @class Queen : public piece
 */
class Queen : public Piece
{
public:
    Queen(){}
    Queen(const Color & color, const pairCoord & coord);
    Queen(const Color & color,const pairCoord & coord, const pairCoord & initCoord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // QUEEN_H
