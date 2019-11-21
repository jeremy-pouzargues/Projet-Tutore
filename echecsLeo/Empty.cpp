#include <iostream>
#include "Empty.h"

using namespace std;

Empty::Empty(const pairCoord & coord)
{
    myCarac = KVIDE;
    myCoord = coord;
}

void Empty::move(const pairCoord & coord){}
