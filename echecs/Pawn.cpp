#include <iostream>
#include "Pawn.h"
#include "CExc.h"

using namespace std;

Pawn::Pawn(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;

    if (color == white)
        myCarac = KPAWNW;
    else
        myCarac = KPAWNB;
}

pairCoord Pawn::move(const pairCoord & coord) {
    if (this->getColor() == white) {
        if(coord.first != this->getCoord().first - 1)
            throw(CException(BADMOVE , SBADMOVE));
        else
            this->setCoord(coord);
    }
    else {
        if(coord.first != this->getCoord().first + 1)
            throw(CException(BADMOVE, SBADMOVE));
        else
            this->setCoord(coord);
    }

}// move()


















