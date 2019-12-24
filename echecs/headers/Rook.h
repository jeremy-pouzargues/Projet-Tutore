/**
* @author Laurent, Leo
* @file   Rook.h include "headers/Rook.h"
* @version 1.1
* @date 21/11/2019
*/
#ifndef ROOK_H
#define ROOK_H

#include "Const.h"
#include "Piece.h"

/**
 * @brief classe la tour
 * @class Rook : public Piece
 */
class Rook : public Piece {
public:
    Rook() {}
    Rook(const Color & color,const pairCoord & coord);

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // ROOK_H
