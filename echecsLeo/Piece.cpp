#include "Piece.h"

//getters
char Piece::getCarac()      {return myCarac;}
pairCoord Piece::getCoord() {return myCoord;}
Color Piece::getColor()     {return myColor;}

//setters
void Piece::setCoord(const pairCoord &coord) {myCoord = coord;}
