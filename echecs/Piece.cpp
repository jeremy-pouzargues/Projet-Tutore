#include "headers/Piece.h"
using namespace std;

//getters
const char        & Piece::getCarac()      const {return myCarac;}
const pairCoord   & Piece::getCoord()      const {return myCoord;}
const Color       & Piece::getColor()      const {return myColor;}
const std::string & Piece::getName()       const {return myName;}

//setters
void Piece::setCoord(const pairCoord &coord) {myCoord = coord;}


