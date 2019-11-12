#include "Rook.h"
#include <iostream>

using namespace std;

Rook::Rook(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;
}

pairCoord Rook::move(Piece & piece, const pairCoord & coord) {
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
