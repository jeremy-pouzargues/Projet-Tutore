#include "Piece.h"

//getters
std::string Piece::getName()  const {return myName;}
Color       Piece::getColor() const {return myColor;}
pairCoord   Piece::getCoord()          const {return myCoord;}

//setters
void        Piece::setCoord(const pairCoord & coord) {myCoord = coord;}
