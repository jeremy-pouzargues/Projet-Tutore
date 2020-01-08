#include <iostream>
#include <vector>
#include <limits>
#include "headers/Piece.h"
#include "headers/Chessboard.h"
#include "headers/CExc.h"

#include "headers/minmax.hpp"


using namespace std;

void play(ChessBoard & chessboard)
{
    // le joueur en true est le joueurs en blanc
    bool player (true);
    bool end(false);

    // tant que la partie n'est pas finie
    while(!end)
    {
        try {
            Color  color;

            string playerName;
            vector<shared_ptr<Piece>> vPiecesPlayer;
            vector<shared_ptr<Piece>> vPiecesOpponent;
            unsigned x,y,u,v;

            if (player)
            {
                color           = white;

                playerName      = "blanc";
                vPiecesPlayer = chessboard.getPiecesW();
                vPiecesOpponent = chessboard.getPiecesB();
            }
            else
            {
                color           = black;

                playerName      = "noir";
                vPiecesPlayer   = chessboard.getPiecesB();
                vPiecesOpponent = chessboard.getPiecesW();
            }

            //============================  Vérifier l'échec et mat si le roi est en echec =========================================


            if (chessboard.find(chessboard.matrixToVector(chessboard.getVEatOpponent(vPiecesOpponent)),vPiecesPlayer[0]->getCoord()))
            {
                if (chessboard.isCheckMate(player))
                    break;
            }


            //============================  Choix de la pièce que l'on veut déplacer  ==============================
            if (player)
            {


                cout << "joueur " << playerName << " choisissez une pièce " << endl;
                cout << "coord 1 : ";
                cin  >> x;


                // TEMPORAIRE TANT QUE L'ON A PAS L'IHM
                // on test si on entre des chiffres et pas autre chose dans le flux
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

                if( x > 7 || x < 0 || y > 7 || y < 0 )
                    throw CException(OUTOFRANGE,SOUTOFRANGE);

                // si le joueur se trompe de case ou choisit la une mauvaise piece
                if(chessboard.getChessboard()[x][y]->getColor() != color)
                    throw CException(BADPIECE,SBADPIECE);
                if(chessboard.getChessboard()[x][y]->getName() != "King")
                {
                    for (pairCoord coord : chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard()))
                    {
                        cout << coord.first << coord.second << "  ";
                    }
                    cout << endl;
                }
                else
                {
                    for (pairCoord coord : chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(vPiecesOpponent)))
                    {
                        cout << coord.first << coord.second << "  ";
                    }
                    cout << endl;
                }




                //============================  Choix de la case de sur laquelle on va déplacer la pièce ===============


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

                if( u > 7 || u < 0 || v > 7 || v < 0 )
                    throw CException(OUTOFRANGE,SOUTOFRANGE);


                // Coordonnées de la pièce choisie
                pairCoord coordPiece (x,y);
                // Coordonnées de destination
                pairCoord coordMove (u,v);


                //======================= TESTS MINMAX ======================


                //            cout << " =====MINMAX==== " << "\n" << minmax(chessboard,1,true) << endl;


                //======================= A FINIR ===========================

                ChessBoard tmpChessboard (chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());

                // si le joueur déplace le roi le traitement est à part on prend un argument supplementaire
                if(chessboard.getChessboard()[x][y]->getName() == "King")
                {

                    //On n'autorise le mouvement seulement si le roi ne se met pas en danger
                    if(chessboard.find(chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(vPiecesOpponent)), coordMove))
                        chessboard.move(coordMove, coordPiece);
                    else
                        throw CException(BADMOVE,SBADMOVE);
                }

                else if (chessboard.find(chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard()), coordMove))
                {
                    chessboard.move(coordMove, coordPiece);
                }
                else
                    throw CException(BADMOVE,SBADMOVE);

                vPiecesPlayer = chessboard.getPiecesW();
                vPiecesOpponent = chessboard.getPiecesB();


                if (chessboard.find(chessboard.matrixToVector(chessboard.getVEatOpponent(vPiecesOpponent)),vPiecesPlayer[0]->getCoord()))
                {
                    chessboard = tmpChessboard;
                    throw CException(CHECK,SCHECK);
                }
            }
            else
            {
                vector<pairCoord> resultEval = finalMinmax(chessboard,2,true);
                chessboard.move(resultEval[1],resultEval[0]);
            }

            player = !player;
            chessboard.show();
        } catch(CException & cexc ) {
            cexc.display();
        }
    }
    //    string colorPlayer;
    //    player ? colorPlayer = "blanc" : "noir";
    cout << "Le joueur " << " est echec et mat et a donc perdu !" << endl;
}//play()
int main()
{
    ChessBoard chessboard;
    chessboard.show();

    play(chessboard);

    return 0;
}
