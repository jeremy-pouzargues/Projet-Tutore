/**
 * @file Knight.h
 * @author Jérémy
 * @version 1.2
 */
#ifndef KNIGHT_H
#define KNIGHT_H


#include <iostream>
#include "Piece.h"

/**
* @brief  classe de la pièce Cavalier (Knight), fille de Piece
* @class Knight  include Pieces/Knight.h"
*/
class Knight : public Piece
{
private:
public:
    Knight() {}
    Knight(const Color & color,const pairCoord & coord);
    Knight(const Color & color,const pairCoord & coord, const pairCoord & initCoord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);

    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) {}
};

#endif // KNIGHT_H
