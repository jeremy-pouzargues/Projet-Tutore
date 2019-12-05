#ifndef MINMAX_H
#define MINMAX_H

#include <iostream>
#include <limits.h>
#include "Chessboard.h"


int evaluation(ChessBoard chessboard) {
   return 10;
}

int minmax(ChessBoard chessboard, int depth,bool maximizingPlayer)
{
    int maxEval;
    int minEval;

    // test
    std::vector<std::shared_ptr<Piece>> allPiece;
    std::vector<pairCoord> allLegalMoves;

    for(unsigned i(0); i < chessboard.getPiecesB().size() -1; ++i)
    {
        allPiece.push_back(chessboard.getPiecesB()[i]);
        allPiece.push_back(chessboard.getPiecesW()[i]);
    }




    if (depth == 0 /* ||  la partie n'est pas finie*/)
        return evaluation(chessboard);
    if (maximizingPlayer)
    {
        maxEval = INT_MIN;//pseudo -infini

        for(std::shared_ptr<Piece> piece : allPiece)
        {
            for (pairCoord paircoord : piece->legalMoves(chessboard.getChessboard()))
            {

                //test
                pairCoord tmp;
                chessboard.move(tmp,paircoord);
                int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                maxEval  = std::max(maxEval,eval);
            }
        }
        return maxEval;
    }
    else
    {
           minEval = INT_MAX; //pseudo +infini
//            for(pairCoord paircoord : allLegalMoves)
//            {
//                int eval = minmax(chessboard,depth-1,maximizingPlayer);
//                minEval  = std::min(minEval,eval);
//            }
            return minEval;
    }
}//minmax()

#endif // MINMAX_H
