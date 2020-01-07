#include <iostream>
#include "Pieces/Empty.h"

using namespace std;

Empty::Empty(const pairCoord & coord)
{
    myCarac = KEMPTY;
    myCoord = coord;
    myColor = empty;
    myName  = "Empty";
    myValue = 0;
    myInitCoord = coord;
    canCastling = false;
}

