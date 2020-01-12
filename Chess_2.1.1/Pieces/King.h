/**
 * @author Leo
 * @file King.h
 * @version 1.0
 * @date 27/11/19
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

/**
 * @brief classe du roi, fille de Piece
 * @class King include "Pieces/Empty.h"
 */
class King : public Piece
{
private:
public:
    King() {}
    King(const Color & color,const pairCoord & coord);
    King(const Color & color, const pairCoord & coord, const pairCoord & initCoord, const bool & canCastling);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix) {}
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent);

    bool find(const pairCoord & coordPiece,const std::vector<std::vector<pairCoord>> & listMovesOpponent);


};

#endif // KING_H
