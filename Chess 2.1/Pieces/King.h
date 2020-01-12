/**
 * @author Leo
 * @file  Roi.h include "headers/King.h"
 * @version 1.2
 * @date 27/11/19
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"


/**
 * @brief classe du roi, dérive de Pièce
 * @class King : public Piece
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
