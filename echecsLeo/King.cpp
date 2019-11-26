#include "King.h"
#include "CExc.h"

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
    //à faire
}
