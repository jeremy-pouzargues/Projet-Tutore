#include "Pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;

    if (color == blanc)
        myCarac = KPAWNB;
    else
        myCarac = KPAWNN;
}

pairCoord Pawn::move(const pairCoord & coord) {
//    if (this->getColor() == blanc)
//    {
//        if(coord.first != this->getCoord().first + 1) {
//            cout << "erreur de mouvement" << endl;
//        }
//        else {
//            this->setCoord(coord);
//        }
//    }

    this->setCoord(coord);
}// move()


















