#include "Pieces/Pawn.h"
#include "Utils/CExc.h"

using namespace std;

Pawn::Pawn(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = coord;
    myName = "Pawn";
    myValue = 100;
    canCastling = false;

    color == white ? myCarac = KPAWNW : myCarac = KPAWNB;
}//Pawn()

Pawn::Pawn(const Color & color, const pairCoord & coord, const pairCoord & initCoord)
{
    myColor = color;
    myCoord = coord;
    myInitCoord = initCoord;
    myName = "Pawn";
    myValue = 100;
    color == white ? myCarac = KPAWNW : myCarac = KPAWNB;
}//Pawn()

/*
void Pawn::move(const pairCoord & coord)
{
    int gameMove;
    this->getColor() == white ? gameMove = -1 : gameMove = 1;

    if (coord.first != this->getCoord().first + gameMove)
        throw (CException(BADMOVE, SBADMOVE));
    else
        this->setCoord(coord);
}//move()
*/
vector<pairCoord> Pawn::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix)
{
    unsigned line = this->getCoord().first;
    unsigned column = this->getCoord().second;
    //startLine va servir à vérifier que le pion est bien sur sa ligne de départ en foncion de sa couleur
    unsigned startLine;
    //newLine va etre égal la ligne de notre pion avec un déplacement vers le haut ou le bas selon la couleur
    unsigned newLine;
    //newJumpMove va etre égal la ligne de notre pion avec deux déplacement vers le haut ou le bas selon la couleur
    unsigned newJumpMove;

    Color colorOpponent;

    vector<pairCoord> VMoves;
    //condition qui va initialiser nos variables
    if (this->getColor() == white)
    {
        newLine = line - 1;
        newJumpMove = line - 2;
        startLine = 6;
        colorOpponent = black;
    }
    else
    {
        newLine = line + 1;
        newJumpMove = line + 2;
        startLine = 1;
        colorOpponent = white;
    }
    // On regarde si la case qui suit la notre est vide ou pas
    if (matrix[newLine][column]->getColor() == empty)
    {
        VMoves.push_back(matrix[newLine][column]->getCoord());
        //On regarde si le pion est sur sa ligne de départ et si on peut l'autoriser à faire un 2eme déplacement;
        if (line == startLine && matrix[newJumpMove][column]->getColor() == empty)
            VMoves.push_back(matrix[newJumpMove][column]->getCoord());
    }
    //Ces deux conditions vont regarder si des pièces sont dans les diagonales directes de notre pion afin de pouvoir éventuellement les manger
    if (column != 7 && matrix[newLine][column + 1]->getColor() == colorOpponent)
        VMoves.push_back(matrix[newLine][column + 1]->getCoord());
    if (column != 0 && matrix[newLine][column - 1]->getColor() == colorOpponent)
        VMoves.push_back(matrix[newLine][column - 1]->getCoord());

    return VMoves;
}

