#include "headers/Knight.h"
#include "headers/CExc.h"

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
    vector<pairCoord> VMoves;
    unsigned line = this->getCoord().first;
    unsigned column = this->getCoord().second;

    Color thisColor;

    this->getColor() == white ? thisColor = white : thisColor = black;

    if (line != 0)
    {
        if (line != 1)
        {
            if (column != 0 && matrix[line - 2][column - 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line - 2][column - 1]->getCoord());
            if (column != 7 && matrix[line - 2][column + 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line - 2][column + 1]->getCoord());
        }
        if (column != 0 && column != 1 && matrix[line - 1][column - 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line - 1][column - 2]->getCoord());
        if (column != 7 && column != 6 && matrix[line - 1][column + 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line - 1][column + 2]->getCoord());
    }
    if (line != 7)
    {
        if (line != 6)
        {
            if (column != 0 && matrix[line + 2][column - 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line + 2][column - 1]->getCoord());
            if (column != 7 && matrix[line + 2][column + 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line + 2][column + 1]->getCoord());
        }
        if (column != 0 && column != 1 && matrix[line + 1][column - 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line + 1][column - 2]->getCoord());
        if (column != 7 && column != 6 && matrix[line + 1][column + 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line + 1][column + 2]->getCoord());
    }
    return VMoves;
}// legalMoves()
