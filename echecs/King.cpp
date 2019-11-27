#include "headers/King.h"
#include "headers/CExc.h"

using namespace std;

King::King(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myName = "King";

    color == white ? myCarac = KKINGW : myCarac = KKINGB;

}
vector<pairCoord> King::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix)
{
    vector<pairCoord> VMoves;
    Color colorOpponent;
    this->getColor() == white ? colorOpponent = black : colorOpponent = white;
    unsigned line = this->getCoord().first;
    unsigned column = this->getCoord().second;

    if(line != 0)
    {
        if(column != 0) VMoves.push_back(pairCoord(line-1,column-1));
    }
}
