#include "Pieces/Piece.h"
using namespace std;

//getters
const char        & Piece::getCarac()       const {return myCarac;}
const pairCoord   & Piece::getCoord()       const {return myCoord;}
const pairCoord   & Piece::getInitCoord()   const {return myInitCoord;}
const Color       & Piece::getColor()       const {return myColor;}
const std::string & Piece::getName()        const {return myName;}
const bool        & Piece::getCanCastling() const {return canCastling;}
const int         & Piece::getValue()       const {return myValue;}

//setters
void Piece::setCoord(const pairCoord &coord) {myCoord = coord;}
void Piece::turnOffCastling(){canCastling = false;}


