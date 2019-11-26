/**
 * @author Leo
 * @file Empty.h
 */
#ifndef EMPTY_H
#define EMPTY_H

#include "Piece.h"

class Empty : public Piece
{
public:
    Empty(){}
    Empty(const pairCoord & coord);
    virtual void move(const pairCoord & coord) ;
};

#endif // EMPTY_H
