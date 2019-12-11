#include <iostream>
#include <limits.h>
#include "headers/minmax.h"


int minmax(ChessBoard & chessboard,const int & depth,const bool & maximizingPlayer)
{

    if (depth == 0 /* ||  la partie n'est pas finie*/)
        return evaluation(chessboard);


    int maxEval;
    int minEval;

    if (maximizingPlayer)
    {
        maxEval = INT_MIN;//pseudo -infini

        // pour chaque pieces blanches, pour l'instant le joueur maximisant est toujours le blanc
        for(std::shared_ptr<Piece> piece : chessboard.getPiecesW())
        {

            // pour chaque coup possible par pièce
            for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
            {

                // on garde les coordonées actuelles de la pîece
                pairCoord actualCoord = piece->getCoord();
                // on la deplace
                chessboard.move(possibleMove,actualCoord);
                // on réévalue l'echiquier après ce déplacement
                int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                maxEval  = std::max(maxEval,eval);
                // on remet la pièce à sa position d'origine
                chessboard.move(actualCoord,piece->getCoord());
            }
        }
        return maxEval;
    }
    else // joueur minimisant
    {
          // idem que pour le joueur maximisant, mais à l'inverse

          minEval = INT_MAX; //pseudo +infini

           // pour chaque pieces noires
           for(std::shared_ptr<Piece> piece : chessboard.getPiecesB())
           {


               for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
               {
                   pairCoord actualCoord = piece->getCoord();
                   chessboard.move(possibleMove,actualCoord);
                   int eval = minmax(chessboard,depth-1,maximizingPlayer);
                   minEval  = std::min(minEval,eval);
                   chessboard.move(actualCoord,piece->getCoord());
               }
           }
           return minEval;
    }
}//minmax()

