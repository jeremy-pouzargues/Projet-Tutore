#include "headers/Bishop.h"

#include <iostream>
using namespace std;

Bishop::Bishop(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    color == white ? myCarac = KBISHOPW : myCarac = KBISHOPB;
    myName = "Bishop";
}

vector<pairCoord> Bishop::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix ){

    vector<pairCoord> VMoves;
    Color colorOpponent;
    this->getColor() == white ? colorOpponent = black : colorOpponent = white;

    //Test diagonale haut gauche
    //Impossible si le fou est situé tout en haut ou à gauche de l'échiquiuer
    if(this->myCoord.first != 0 || this->myCoord.second != 0)
    {
        unsigned line = this->myCoord.first;
        unsigned column = this->myCoord.second;
        //Tant qu'on est pas sur un allié
        while(matrix[line][column]->getColor() != this->getColor())
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
    if(this->myCoord.first != 0 || this->myCoord.second != 7)
    {
        unsigned line = this->myCoord.first;
        unsigned column = this->myCoord.second;

        while(matrix[line][column]->getColor() != this->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            --line;
            ++column;
        }
    }

    //Test diagonale bas droite
    //Impossible si le fou est situé tout en bas ou à droite de l'échiquiuer
    if(this->myCoord.first != 7 || this->myCoord.second != 7)
    {
        unsigned line = this->myCoord.first;
        unsigned column = this->myCoord.second;

        while(matrix[line][column]->getColor() != this->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line;
            ++column;
        }
    }

    //Test diagonale bas gauche
    //Impossible si le fou est situé tout en bas ou à gauche de l'échiquiuer
    if(this->myCoord.first != 7 || this->myCoord.second != 0)
    {
        unsigned line = this->myCoord.first;
        unsigned column = this->myCoord.second;

        while(matrix[line][column]->getColor() != this->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line += 1;
            --column;
        }
    }

    return VMoves;
}

