#include <iostream>
#include <vector>
#include <limits>
#include "Pieces/Piece.h"
#include "Chessboard/Chessboard.h"
#include "Utils/CExc.h"


//#include "IA/minmax.hpp"


#include "GraphicalObject/mainwindow.h" //FRANFRAN
#include <QApplication> //FRANFRAN

using namespace std;

//void play(ChessBoard & chessboard, bool player,bool end,int x,int y,unsigned u,unsigned v)
//{
//    // le joueur en true est le joueurs en blanc
//    player = true;
//    end = false;

//    // tant que la partie n'est pas finie
////    while(!end)
////    {
////        try {
//            Color  color;

//            string playerName;
//            vector<shared_ptr<Piece>> vPiecesPlayer;
//            vector<shared_ptr<Piece>> vPiecesOpponent;
////            unsigned x,y,u,v;

//            color           = white;

//            playerName      = "blanc";
//            vPiecesPlayer = chessboard.getPiecesW();
//            vPiecesOpponent = chessboard.getPiecesB();

//            //============================  Vérifier l'échec et mat si le roi est en echec =========================================


//            if (chessboard.find(chessboard.matrixToVector(chessboard.getVEatOpponent(vPiecesOpponent)),vPiecesPlayer[0]->getCoord()))
//            {
//                if (chessboard.isCheckMate(player))
//                    qDebug() << "is Check Mate";
//            }


//            //============================  Choix de la pièce que l'on veut déplacer  ==============================
//            if(player)
//            {
//                if(chessboard.getChessboard()[x][y]->getName() != "King")
//                {
//                    for (pairCoord coord : chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard()))
//                    {
//                        cout << coord.first << coord.second << "  ";
//                    }
//                    cout << endl;
//                }
//                else
//                {
//                    for (pairCoord coord : chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(vPiecesOpponent)))
//                    {
//                        cout << coord.first << coord.second << "  ";
//                    }
//                    cout << endl;
//                }




//                //============================  Choix de la case de sur laquelle on va déplacer la pièce ===============

//                // Coordonnées de la pièce choisie
//                pairCoord coordPiece (x,y);
//                // Coordonnées de destination
//                pairCoord coordMove (u,v);

//                //======================= A FINIR ===========================

//                VPieces tmpVPiecesW     = chessboard.getPiecesW();
//                VPieces tmpVPiecesB     = chessboard.getPiecesB();
//                VPieces tmpVDeadPiecesW = chessboard.getMyDeadPieceW();
//                VPieces tmpVDeadPiecesB = chessboard.getMyDeadPieceB();
//                Matrix  tmpChessboard   = chessboard.getChessboard();

//                // si le joueur déplace le roi le traitement est à part on prend un argument supplementaire
//                if(chessboard.getChessboard()[x][y]->getName() == "King")
//                {

//                    //On n'autorise le mouvement seulement si le roi ne se met pas en danger
//                    if(chessboard.find(chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(vPiecesOpponent)), coordMove))
//                        chessboard.move(coordMove, coordPiece);
//                    else
//                        throw CException(BADMOVE,SBADMOVE);
//                }

//                else if (chessboard.find(chessboard.getChessboard()[x][y]->legalMoves(chessboard.getChessboard()), coordMove))
//                {
//                    chessboard.move(coordMove, coordPiece);
//                }
//                else
//                    throw CException(BADMOVE,SBADMOVE);

//                if (player)
//                {
//                    vPiecesPlayer = chessboard.getPiecesW();
//                    vPiecesOpponent = chessboard.getPiecesB();
//                }
//                else
//                {
//                    vPiecesPlayer = chessboard.getPiecesB();
//                    vPiecesOpponent = chessboard.getPiecesW();
//                }

//                if (chessboard.find(chessboard.matrixToVector(chessboard.getVEatOpponent(vPiecesOpponent)),vPiecesPlayer[0]->getCoord()))
//                {
//                    chessboard.setPiecesB(tmpVPiecesB);
//                    chessboard.setPiecesW(tmpVPiecesW);
//                    chessboard.setDeadPieceB(tmpVDeadPiecesB);
//                    chessboard.setDeadPieceW(tmpVDeadPiecesW);
//                    chessboard.setChessboard(tmpChessboard);
//                    chessboard.getChessboard()[x][y]->setCoord(coordPiece);
//                    throw CException(CHECK,SCHECK);
//                }
//            }
//            else
//            {
//                vector<pairCoord> test = finalMinmax(chessboard,2,true);
//                chessboard.move(test[1],test[0]);
//            }

////            player = !player;
//            chessboard.refreshGraphicalVector();

////            chessboard.show();

////        } catch(CException & cexc ) {
////            cexc.display();
////        }
////    }
//    //    string colorPlayer;
//    //    player ? colorPlayer = "blanc" : "noir";
//    cout << "Le joueur " << " est echec et mat et a donc perdu !" << endl;
//}//play()



//int main()
//{
//    ChessBoard chessboard;
//    chessboard.show();

//    play(chessboard);

//    return 0;
//}


//#include <GraphicalObject/MessageBox.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MessageBox test("test","et merce");

    MainWindow w;
    w.setFixedSize(600,800);
    w.show();
    return a.exec();
}
