/**
 * @author Leo
 * @file Queen.h
 * @brief  classe de la piece reine, fille de Piece
 * @class Queen include "headers/Queen.h"
 * @version 1.0
 */
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(){}
    Queen(const Color & color, const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix );

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::shared_ptr<Piece>> & VPiecesOpponent) {}
};

#endif // QUEEN_H
