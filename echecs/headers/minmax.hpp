#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <limits.h>
#include "headers/Chessboard.h"


int evaluation(const ChessBoard chessboard)
{
    std::cout << "dans evaluation" << std::endl;
    return 1;
}

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


            if(piece->getName() != "King")
            {
                // pour chaque coup possible par pièce
                for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
                {

                    std::cout << piece->getName() << " " << piece->getCoord().first  << " " << piece->getCoord().second << " "
                              << piece->getColor() <<" "  << possibleMove.first << " " << possibleMove.second <<  std::endl;



                    // on garde dans un tampon l'échiquier actuel
                    Matrix    actualChessboard  = chessboard.getChessboard();
                    Matrix    actualDeadPiece   = chessboard.getMyDeadPiece();
                    // on la deplace
                    chessboard.move(possibleMove,piece->getCoord());
                    // on réévalue l'echiquier après ce déplacement
                    int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                    // on regarde si le score est plus élevé que le score max actuelle
                    // si oui ce coup est plus intéréssant
                    maxEval  = std::max(maxEval,eval);
                    // on remet l'echiquier à sa position d'origine
                    chessboard.setChessboard(actualChessboard);
                    chessboard.setDeadPiece(actualDeadPiece);

                }
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

             if(piece->getName() != "King")
             {
               for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
               {
                   Matrix    actualChessboard  = chessboard.getChessboard();
                   Matrix    actualDeadPiece   = chessboard.getMyDeadPiece();
                   chessboard.move(possibleMove,piece->getCoord());
                   int eval = minmax(chessboard,depth-1,maximizingPlayer);
                   minEval  = std::min(minEval,eval);

                   chessboard.setChessboard(actualChessboard);
                   chessboard.setDeadPiece(actualDeadPiece);
               }
             }
           }
           return minEval;
    }
}//minmax()


#endif // MINMAX_HPP
