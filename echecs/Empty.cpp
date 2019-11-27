#include <iostream>
#include "headers/Empty.h"

using namespace std;

Empty::Empty(const pairCoord & coord)
{
    myCarac = KVIDE;
    myCoord = coord;
    myColor = empty;
}

