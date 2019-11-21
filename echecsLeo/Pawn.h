/**
 * @author Jérémy
 * @file Pawn.h
 */
#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"
/**
 * @brief The Pawn class
 * @version 1.0
 * @date 20/11/2019
 */
class Pawn : public Piece
{
private:
public:
    Pawn() {}
    Pawn(const Color & color,const pairCoord & coord);
    virtual void move(const pairCoord & coord);
};

#endif // PAWN_H
