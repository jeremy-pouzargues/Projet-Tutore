#include "Knight.h"

#include "CExc.h"

using namespace std;

Knight::Knight(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myName = "Knight";

    color == white ? myCarac = KKNIGHTW : myCarac = KKNIGHTB;
}

vector<pairCoord> Knight::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix)
{
    //à faire
}
