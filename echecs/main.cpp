#include <iostream>
#include <vector>
#include <limits>
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
            unsigned x,y,u,v;

            vector<pairCoord> myMoves;

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


            // TEMPORAIRE TANT QUE L'ON A PAS L'IHM
            if(!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw CException(BADINPUT,SBADINPUT);
            }
            cout << "coord 2 : ";


            cin  >> y;
            if(!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw CException(BADINPUT,SBADINPUT);
            }


            pairCoord pieceChosen(x,y);

            // si le joueur se trompe de case ou choisit la une mauvaise piece
            if(chessboard.getChessboard()[x][y]->getColor() != color)
                throw CException(BADPIECE,SBADPIECE);





            cout << "joueur " << playerName << " choisissez une case " << endl;
            cout << "coord 1 : ";


            cin  >> u;
            if(!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw CException(BADINPUT,SBADINPUT);
            }
            cout << "coord 2 : ";
            cin  >> v;
            if(!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw CException(BADINPUT,SBADINPUT);
            }





            // Coordonnées de la pièce choisie
            pairCoord coordPiece (x,y);
            // Coordonnées de destination
            pairCoord coordMove (u,v);
            if (chessboard.find(chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard()), coordMove))
                chessboard.move(coordMove, coordPiece);
            else
                throw CException(BADMOVE,SBADMOVE);


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
