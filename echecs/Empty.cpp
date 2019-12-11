#include <iostream>
#include "headers/Empty.h"

using namespace std;

Empty::Empty(const pairCoord & coord)
{
    myCarac = KEMPTY;
    myCoord = coord;
    myColor = empty;
    myName = "Empty";
}

