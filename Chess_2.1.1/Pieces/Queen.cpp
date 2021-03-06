#include "Pieces/Queen.h"

//#include <iostream>
using namespace std;


Queen::Queen(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = coord;
    color == white ? myCarac = KQUEENW : myCarac = KQUEENB;
    myName = "Queen";
    myValue = 900;
    canCastling = false;
}

Queen::Queen(const Color & color,const pairCoord & coord, const pairCoord & initCoord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = initCoord;
    color == white ? myCarac = KQUEENW : myCarac = KQUEENB;
    myName = "Queen";
    myValue = 900;
}

vector <pairCoord> Queen::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix )
{

    vector<pairCoord> VMoves;
    Color colorOpponent;
    this->getColor() == white ? colorOpponent = black : colorOpponent = white;
    unsigned line;
    unsigned column;


    //Test diagonale haut gauche
    //Impossible si la reine est situé tout en haut ou à gauche de l'échiquiuer
    if(this->myCoord.first != 0 && this->myCoord.second != 0)
    {
        line = this->myCoord.first - 1;
        column = this->myCoord.second - 1;
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

    //    //Test diagonale haut droite
    //    //Impossible si la reine est situé tout en haut ou à droite de l'échiquiuer
    if(this->myCoord.first != 0 && this->myCoord.second != 7)
    {
        line = this->myCoord.first - 1;
        column = this->myCoord.second + 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0 || column == 7)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            --line;
            ++column;
        }
    }

    //    //Test diagonale bas droite
    //    //Impossible si la reine est situé tout en bas ou à droite de l'échiquiuer
    if(this->myCoord.first != 7 && this->myCoord.second != 7)
    {
        line = this->myCoord.first + 1;
        column = this->myCoord.second + 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 7 || column == 7)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line;
            ++column;
        }
    }

    //    //Test diagonale bas gauche
    //    //Impossible si la reine est situé tout en bas ou à gauche de l'échiquiuer
    if(this->myCoord.first != 7 && this->myCoord.second != 0)
    {
        line = this->myCoord.first + 1;
        column = this->myCoord.second - 1;

        while(this->getColor() != matrix[line][column]->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(line == 7 || column == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent)break;
            ++line;
            --column;
        }
    }

    column  = this->getCoord().second;

          //Si la reine est en haut elle ne pourra pas aller en haut
    if(this->getCoord().first != 0) {
        line = this->getCoord().first - 1;

        while(matrix[line][column]->getColor() != this->getColor()) {
            VMoves.push_back(pairCoord(line,column));
            if(line == 0)break;
            if (matrix[line][column]->getColor() == colorOpponent) break;
            --line;
        }
    }

          //Si la reine est en bas elle ne pourra pas aller en bas
    if(this->getCoord().first != 7) {
        line = this->getCoord().first + 1;

        //test de cases disponibles dans une colonne vers le bas
        while(matrix[line][column]->getColor() != this->getColor()) {
            VMoves.push_back(pairCoord(line,column));
            if( line == 7 )break;
            if (matrix[line][column]->getColor() == colorOpponent) break;
            ++line;
        }
    }

    line = this->getCoord().first;

          // tests horizontaux
          //Si la reine est à gauche elle ne pourra pas aller à gauche
    if(this->getCoord().second != 0) {
        column  = this->getCoord().second - 1;
        // vers la droite
        while(matrix[line][column]->getColor() != this->getColor())
        {
            VMoves.push_back(pairCoord(line,column));
            if(column == 0 ) break;
            if (matrix[line][column]->getColor() == colorOpponent) break;
            --column;
        }
    }

    //      // collé à gauche
    if(this->getCoord().second != 7) {
        column  = this->getCoord().second + 1;
        //vers la gauche
        while(matrix[line][column]->getColor() != this->getColor()) {
            VMoves.push_back(pairCoord(line,column));
            if( column == 7 ) break;
            if (matrix[line][column]->getColor() == colorOpponent) break;
            ++column;
        }
    }
    return VMoves;
}
