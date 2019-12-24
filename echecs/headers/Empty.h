/**
 * @author Leo
 * @file   Empty.h, include "headers/Empty.h"
 * @version 1.1
 */

#ifndef EMPTY_H
#define EMPTY_H

#include "Piece.h"


/**
 * @class Empty : public Piece
 * @brief classe pour une les cases vides
 * puisque que l'échiquier est une matrice de Pieces les cases vides doivent être des pièces elles aussi
 */
class Empty : public Piece
{
public:
    Empty(){}
    Empty(const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix ) {}

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // EMPTY_H
