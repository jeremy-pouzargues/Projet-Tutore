#include "Pieces/Bishop.h"

#include <iostream>
using namespace std;

Bishop::Bishop(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = coord;
    color == white ? myCarac = KBISHOPW : myCarac = KBISHOPB;
    myName = "Bishop";
    canCastling = false;
    myValue = 300;
}

Bishop::Bishop(const Color & color, const pairCoord & coord, const pairCoord & initCoord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = initCoord;
    color == white ? myCarac = KBISHOPW : myCarac = KBISHOPB;
    myName = "Bishop";
    myValue = 300;
}

vector<pairCoord> Bishop::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix ){

    vector<pairCoord> VMoves;
    Color colorOpponent;
    this->getColor() == white ? colorOpponent = black : colorOpponent = white;

    //Test diagonale haut gauche
    //Impossible si le fou est situé tout en haut ou à gauche de l'échiquiuer
    if(this->myCoord.first != 0 && this->myCoord.second != 0)
    {
        unsigned line = this->myCoord.first - 1;
        unsigned column = this->myCoord.second - 1;
        //Tant qu'on est pas sur un allié
        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 0)break; //Si on est à la fin
            if (matrix[line][column]->getColor() == colorOpponent)break;//Si on est sur un pion adverse
            --line;
            --column;
        }
    }

    //Test diagonale haut droite
    //Impossible si le fou est situé tout en haut ou à droite de l'échiquiuer
    if(this->myCoord.first != 0 && this->myCoord.second != 7)
    {
        unsigned line = this->myCoord.first - 1;
        unsigned column = this->myCoord.second + 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 7)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            --line;
            ++column;
        }
    }

    //Test diagonale bas droite
    //Impossible si le fou est situé tout en bas ou à droite de l'échiquiuer
    if(this->myCoord.first != 7 && this->myCoord.second != 7)
    {
        unsigned line = this->myCoord.first + 1;
        unsigned column = this->myCoord.second + 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 7 || column == 7)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line;
            ++column;
        }
    }

    //Test diagonale bas gauche
    //Impossible si le fou est situé tout en bas ou à gauche de l'échiquiuer
    if(this->myCoord.first != 7 && this->myCoord.second != 0)
    {
        unsigned line = this->myCoord.first + 1;
        unsigned column = this->myCoord.second - 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 7 || column == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line;
            --column;
        }
    }

    return VMoves;
}

