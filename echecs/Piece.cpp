#include "Piece.h"



Color      Piece::getColor() {return myColor;}
pairCoord  Piece::getCoord() {return myCoord;}

void Piece::setCoord(const pairCoord & coord)
{
    myCoord.first  = coord.first;
    myCoord.second = coord.second;
} //setCoord()

char Piece::getCarac () {return myCarac;}



