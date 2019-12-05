#include "headers/King.h"
#include "headers/CExc.h"

using namespace std;

King::King(const Color & color,const pairCoord & coord)
{
    myColor = color;
    myCoord = coord;
    myName = "King";
    canCastling = true;

    color == white ? myCarac = KKINGW : myCarac = KKINGB;

}
vector<pairCoord> King::legalMoves(const vector<vector<shared_ptr<Piece>>> & matrix, const vector<shared_ptr<Piece>> & VPiecesOpponent)
{

    // on va récuếrer la liste de tous les coups possibles des adversaires et les mettres dans un vecteur
    vector<vector<pairCoord>> VMovesOpponent;
    // pour chaque piece adverse
    for (shared_ptr<Piece> piece : VPiecesOpponent)
    {
        // si c'est un roi traitement particulier pour eviter une boucle infinie
        // on va récupérer les coord de tous les mouvements qu'il pourrait hypothetiquement réaliser
        // et les ajouter dans la matrice VMovesOpponent
        if(piece->getName() == "King")
        {
            vector<pairCoord> VMovesKing;
            unsigned line   = piece->getCoord().first;
            unsigned column = piece->getCoord().second;
            Color colorPiece = piece->getColor();


            // si le roi n'est pas tout en haut
            if(line != 0)
            {
                if(column != 0 && matrix[line-1][column-1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column-1));
                if(matrix[line-1][column]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column));
                if(column != 7 && matrix[line-1][column+1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column+1));
            }

            // pas tout à droite et si le pion à sa droite n'est pas de la même couleur
            if(column !=7 && matrix[line][column+1]->getColor() != colorPiece )
                VMovesKing.push_back(pairCoord(line,column+1));

            //tout en bas
            if(line != 7)
            {
                if(column != 7 && matrix[line+1][column+1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1,column+1));
                if(matrix[line+1][column]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1,column));
                if(column != 0 && matrix[line+1][column-1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1, column-1));
            }

            // de même qu'à droite mais à gauche merci.
            if(column != 0 && matrix[line][column-1]->getColor() != colorPiece )
                VMovesKing.push_back(pairCoord(line,column-1));

            VMovesOpponent.push_back(VMovesKing);
        }

        // sinon on ajoute à la matrice les mouvements legaux de toutes les autres pieces
        else
        {
            VMovesOpponent.push_back(piece->legalMoves(matrix));
        }
    }




    vector<pairCoord> VMoves (0);
    Color colorPiece = this->getColor();
    unsigned line = this->getCoord().first;
    unsigned column = this->getCoord().second;

    if(line != 0)
    {
        if(column != 0 && matrix[line-1][column-1]->getColor() != colorPiece && ! find(pairCoord(line-1,column-1), VMovesOpponent))
            VMoves.push_back(pairCoord(line-1,column-1));
        if(matrix[line-1][column]->getColor() != colorPiece && ! find(pairCoord(line-1,column), VMovesOpponent))
            VMoves.push_back(pairCoord(line-1,column));
        if(column != 7 && matrix[line-1][column+1]->getColor() != colorPiece && ! find(pairCoord(line-1,column+1), VMovesOpponent))
            VMoves.push_back(pairCoord(line-1,column+1));
    }

    if(column !=7 && matrix[line][column+1]->getColor() != colorPiece && ! find(pairCoord(line,column+1), VMovesOpponent))
        VMoves.push_back(pairCoord(line,column+1));

    if(line != 7)
    {
        if(column != 7 && matrix[line+1][column+1]->getColor() != colorPiece && ! find(pairCoord(line+1,column+1), VMovesOpponent))
            VMoves.push_back(pairCoord(line+1,column+1));
        if(matrix[line+1][column]->getColor() != colorPiece && ! find(pairCoord(line+1,column), VMovesOpponent))
            VMoves.push_back(pairCoord(line+1,column));
        if(column != 0 && matrix[line+1][column-1]->getColor() != colorPiece && ! find(pairCoord(line+1,column-1), VMovesOpponent))
            VMoves.push_back(pairCoord(line+1, column-1));
    }

    if(column != 0 && matrix[line][column-1]->getColor() != colorPiece && ! find(pairCoord(line,column-1), VMovesOpponent))
        VMoves.push_back(pairCoord(line,column-1));
    if(this->canCastling)
    {
        if(matrix[this->getCoord().first][this->getCoord().second+1]->getName() == "Empty" &&
           matrix[this->getCoord().first][this->getCoord().second+2]->getName() == "Empty" &&
           matrix[this->getCoord().first][this->getCoord().second+3]->getName() == "Rook" &&
           matrix[this->getCoord().first][this->getCoord().second+3]->getCanCastling())
    }
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
