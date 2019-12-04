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
vector<pairCoord> King::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix, const vector<vector<pairCoord>> & vEatOpponent)
{

    // on va récupếrer la liste de tous les coups possibles des adversaires et les mettres dans un vecteur
    


    vector<pairCoord> VMoves (0);
    Color colorPiece = this->getColor();
    unsigned line = this->getCoord().first;
    unsigned column = this->getCoord().second;

    if(line != 0)
    {
        if(column != 0 && matrix[line-1][column-1]->getColor() != colorPiece && ! find(pairCoord(line-1,column-1), vEatOpponent))
            VMoves.push_back(pairCoord(line-1,column-1));
        if(matrix[line-1][column]->getColor() != colorPiece && ! find(pairCoord(line-1,column), vEatOpponent))
            VMoves.push_back(pairCoord(line-1,column));
        if(column != 7 && matrix[line-1][column+1]->getColor() != colorPiece && ! find(pairCoord(line-1,column+1), vEatOpponent))
            VMoves.push_back(pairCoord(line-1,column+1));
    }

    if(column !=7 && matrix[line][column+1]->getColor() != colorPiece && ! find(pairCoord(line,column+1), vEatOpponent))
        VMoves.push_back(pairCoord(line,column+1));

    if(line != 7)
    {
        if(column != 7 && matrix[line+1][column+1]->getColor() != colorPiece && ! find(pairCoord(line+1,column+1), vEatOpponent))
            VMoves.push_back(pairCoord(line+1,column+1));
        if(matrix[line+1][column]->getColor() != colorPiece && ! find(pairCoord(line+1,column), vEatOpponent))
            VMoves.push_back(pairCoord(line+1,column));
        if(column != 0 && matrix[line+1][column-1]->getColor() != colorPiece && ! find(pairCoord(line+1,column-1), vEatOpponent))
            VMoves.push_back(pairCoord(line+1, column-1));
    }

    if(column != 0 && matrix[line][column-1]->getColor() != colorPiece && ! find(pairCoord(line,column-1), vEatOpponent))
        VMoves.push_back(pairCoord(line,column-1));

    return VMoves;

}//legalMoves()



bool King::find(const pairCoord & coordPiece, const vector<vector<pairCoord>> & listMovesOpponent)
{
    for (unsigned i(0); i < listMovesOpponent.size(); ++i)
    {
        for (unsigned j(0); j < listMovesOpponent[i].size(); ++j)
        {
            if(coordPiece == listMovesOpponent[i][j]) return true;
        }
    }
    return false;
}//find()
