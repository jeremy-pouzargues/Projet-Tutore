#include "Pawn.h"
#include "CExc.h"

using namespace std;

Pawn::Pawn(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myName = "Pawn";

    color == white ? myCarac = KPAWNW : myCarac = KPAWNB;
}//Pawn()

//vector<pairCoord> Pawn::legalMoves(const pairCoord & coord)
//{
//    int gameMove;
//    this->getColor() == white ? gameMove = -1 : gameMove = 1;

//    if (coord.first != this->getCoord().first + gameMove)
//        throw (CException(BADMOVE, SBADMOVE));
//    else
//        this->setCoord(coord);
//}//move()
















