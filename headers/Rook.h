/**
* @author Laurent
* @file   Rook.h
* @version 1.0
* @date 21/11/2019
*/
#ifndef ROOK_H
#define ROOK_H

#include "Const.h"
#include "Piece.h"


class Rook : public Piece {
public:
    Rook() {}
    Rook(const Color & color,const pairCoord & coord);
};

#endif // ROOK_H
