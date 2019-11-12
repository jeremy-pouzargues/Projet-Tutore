#include "Pion.h"
#include <iostream>

using namespace std;

Pion::Pion(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;

    if (color == blanc)
        myCarac = KPIONB;
    else
        myCarac = KPIONN;
}

pairCoord Pion::move(Piece & pion, const pairCoord & coord) {
    if (pion.getColor() == blanc)
    {
        if(coord.first != pion.getCoord().first + 1) {
            cout << "erreur de mouvement" << endl;
        }
        else {
            pion.setCoord(coord);
        }
    }

}// move()
