#include <iostream>
#include <vector>
#include "headers/Piece.h"
#include "headers/Chessboard.h"
#include "headers/CExc.h"

using namespace std;


void play(ChessBoard & chessboard)
{
    // le joueur en true et le joueurs en blanc
    bool player (true);
    bool end(false);

    // tant que la partie n'est pas finiee
    while(!end)
    {
       try {
            Color  color;
            Color  colorOpp; // couleur de l'adversaire
            string playerName;
            unsigned x,y;

            if (player)
            {
                color      = white;
                colorOpp   = black;
                playerName = "blanc";
            }
            else
            {
                color      = black;
                colorOpp   = white;
                playerName = "noir";
            }


            cout << "joueur " << playerName << " choisissez une pièce " << endl;
            cout << "coord 1 : ";
            cin  >> x;
            cout << "coord 2 : ";
            cin  >> y;


            // si le joueur se trompe de case ou choisit la une mauvaise piece
            if(chessboard.getChessboard()[x][y]->getColor() == empty || chessboard.getChessboard()[x][y]->getColor() == colorOpp)
                throw CException(BADPIECE,SBADPIECE);

            cout << "joueur " << playerName << " choisissez une case à bouger " << endl;
            cout << "coord 1 : ";
            cin  >> x;
            cout << "coord 2 : ";
            cin  >> y;


            cout << " TODO MOVE " << endl;

            player = !player;
        } catch(CException & cexc ) {
            cexc.display();
        }
    }
}//play()

int main()
{
    ChessBoard chessboard;
    chessboard.show();

    play(chessboard);

    return 0;
}
