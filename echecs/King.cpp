#include "King.h"
#include <iostream>

using namespace std;

King::King(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;
}

pairCoord King::move(Piece & piece, const pairCoord & coord) {
    if (piece.getColor() == blanc)
    {
        if(coord.first != piece.getCoord().first + 1) {
            cout << "erreur de mouvement" << endl;
        }
        else {
            piece.setCoord(coord);
        }
    }

}// move()
