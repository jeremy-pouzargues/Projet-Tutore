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

    // On va vérifier la position du cavalier par rapport aux limites de l'échiquier pour lui interdire certains mouvements selon ses coordoonées
    // On va aussi vérifier qu'il n'y a pas un allié sur la case où on veut se déplacer
    // Ici, on vérifie que le cavalier n'est pas sur la dernière ligne pour lui autoriser ou non les mouvements vers le bas
    if (line != 0)
    {
        // Ici on vérifie qu'une deuxième ligne sous le cavalier est disponible pour pouvoir lui autoriser les mouvements
        // où il se déplace de 2 lignes vers le bas et de 1 colonne vers la gauche ou la droite
        if (line != 1)
        {
            // Grâce à thisColor, on vérifie qu'il n'y a pas un allié sur la case où on veut se déplacer
            // car en cas de case  vide ou d'ennemi, on autorise le déplacement
            if (column != 0 && matrix[line - 2][column - 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line - 2][column - 1]->getCoord());
            if (column != 7 && matrix[line - 2][column + 1]->getColor() != thisColor)
                VMoves.push_back(matrix[line - 2][column + 1]->getCoord());
        }
        // Si 2 cases sont disponibles vers la gauche où la droite, on autorise les mouvements de 1 ligne vers le bas et de 2 colonnes vers la gauche ou la droite
        if (column != 0 && column != 1 && matrix[line - 1][column - 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line - 1][column - 2]->getCoord());
        if (column != 7 && column != 6 && matrix[line - 1][column + 2]->getColor() != thisColor)
            VMoves.push_back(matrix[line - 1][column + 2]->getCoord());
    }
    // Rebelote mais avec les lignes vers le haut
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
