/**
* @author Laurent, Leo
* @file   Rook.h
* @version 1.0
* @date 21/11/2019
*/
#ifndef ROOK_H
#define ROOK_H

#include "Utils/Const.h"
#include "Piece.h"

/**
* @brief classe de la tour, fille de Piece
* @class Rook, include "Pieces/Rook.h"
**/
class Rook : public Piece {
public:
    Rook() {}
    Rook(const Color & color,const pairCoord & coord);
    Rook(const Color & color, const pairCoord & coord, const pairCoord & initCoord, const bool & canCastling);

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // ROOK_H
