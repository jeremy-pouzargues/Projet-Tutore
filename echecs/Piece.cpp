#include "headers/Piece.h"
using namespace std;

//getters
char        Piece::getCarac()      const {return myCarac;}
pairCoord   Piece::getCoord()      const {return myCoord;}
Color       Piece::getColor()      const {return myColor;}
std::string Piece::getName()       const {return myName;}

//setters
void Piece::setCoord(const pairCoord &coord) {myCoord = coord;}


