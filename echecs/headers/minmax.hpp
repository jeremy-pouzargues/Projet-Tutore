#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <limits.h>
#include "headers/Chessboard.h"


int evaluation(const ChessBoard chessboard)
{
    if(chessboard.getPiecesB().size() < chessboard.getPiecesW().size())
        return 10;
    else return 1;
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

        // pour chaque pieces blanches, pour l'instant le joueur maximisant est toujours le noir
        for(std::shared_ptr<Piece> piece : chessboard.getPiecesB())
        {


            if(piece->getName() != "King")
            {
                // pour chaque coup possible par pièce noires, l'IA
                for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
                {

                    std::cout << piece->getName() << " " << piece->getCoord().first  << " " << piece->getCoord().second << " "
                              << possibleMove.first << " " << possibleMove.second <<  std::endl;



                    // on garde dans un tampon l'échiquier actuel
                    Matrix    actualChessboard  = chessboard.getChessboard();
                    VPieces    actualDeadPieceB   = chessboard.getMyDeadPieceB();
                    VPieces    actualDeadPieceW   = chessboard.getMyDeadPieceW();
                    VPieces actualPieceB = chessboard.getPiecesB();
                    VPieces actualPieceW = chessboard.getPiecesW();
                    pairCoord actualCoord = piece->getCoord();
                    // on la deplace
                    chessboard.move(possibleMove,piece->getCoord());
                    // on réévalue l'echiquier après ce déplacement
                    int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                    // on regarde si le score est plus élevé que le score max actuelle
                    // si oui ce coup est plus intéréssant
                    maxEval  = std::max(maxEval,eval);
                    // on remet l'echiquier à sa position d'origine
                    chessboard.setChessboard(actualChessboard);
                    chessboard.setDeadPieceB(actualDeadPieceB);
                    chessboard.setDeadPieceW(actualDeadPieceW);
                    chessboard.setPiecesB(actualPieceB);
                    chessboard.setPiecesW(actualPieceW);
                    piece->setCoord(actualCoord);

                }
           }
           /*
            * on doit faire un traitement different pour le roi car son legalMoves est different
            */
           else // roi noir
           {

                for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(chessboard.getPiecesW())))
                {

                    std::cout << piece->getName() << " coord init " << piece->getCoord().first  << " " << piece->getCoord().second << " possible move "
                              << possibleMove.first << " " << possibleMove.second <<  std::endl;

                    // on garde dans un tampon l'échiquier actuel
                    Matrix    actualChessboard  = chessboard.getChessboard();
                    VPieces   actualDeadPieceB  = chessboard.getMyDeadPieceB();
                    VPieces   actualDeadPieceW  = chessboard.getMyDeadPieceW();
                    VPieces   actualPieceB      = chessboard.getPiecesB();
                    VPieces   actualPieceW      = chessboard.getPiecesW();
                    pairCoord actualCoord       = piece->getCoord();
                    // on la deplace
                    chessboard.move(possibleMove,piece->getCoord());
                    // on réévalue l'echiquier après ce déplacement
                    int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                    // on regarde si le score est plus élevé que le score max actuelle
                    // si oui ce coup est plus intéréssant
                    maxEval  = std::max(maxEval,eval);
                    // on remet l'echiquier à sa position d'origine
                    chessboard.setChessboard(actualChessboard);
                    chessboard.setDeadPieceB(actualDeadPieceB);
                    chessboard.setDeadPieceW(actualDeadPieceW);
                    chessboard.setPiecesB(actualPieceB);
                    chessboard.setPiecesW(actualPieceW);
                    piece->setCoord(actualCoord);

                }
           }
        }
        return maxEval;
    }
    else // joueur minimisant
    {
          // idem que pour le joueur maximisant, mais à l'inverse

          minEval = INT_MAX; //pseudo +infini

           // pour chaque pieces blanches, joueur humain
           for(std::shared_ptr<Piece> piece : chessboard.getPiecesW())
           {

             if(piece->getName() != "King")
             {
               for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard()))
               {
                   std::cout << piece->getName() << " coord init " << piece->getCoord().first  << " " << piece->getCoord().second << " possible move "
                             << possibleMove.first << " " << possibleMove.second <<  std::endl;

                   Matrix    actualChessboard  = chessboard.getChessboard();
                   //Matrix    actualDeadPiece   = chessboard.getDeadPiece();
                   VPieces   actualDeadPieceB  = chessboard.getMyDeadPieceB();
                   VPieces   actualDeadPieceW  = chessboard.getMyDeadPieceW();
                   VPieces   actualPieceB      = chessboard.getPiecesB();
                   VPieces   actualPieceW      = chessboard.getPiecesW();
                   pairCoord actualCoord       = piece->getCoord();

                   chessboard.move(possibleMove,piece->getCoord());
                   int eval = minmax(chessboard,depth-1,maximizingPlayer);
                   minEval  = std::min(minEval,eval);

                   chessboard.setChessboard(actualChessboard);
                   chessboard.setDeadPieceB(actualDeadPieceB);
                   chessboard.setDeadPieceW(actualDeadPieceW);
                   chessboard.setPiecesB(actualPieceB);
                   chessboard.setPiecesW(actualPieceW);
                   piece->setCoord(actualCoord);
               }
             }
             else // roi noir
             {

                  for (pairCoord possibleMove : piece->legalMoves(chessboard.getChessboard(),chessboard.getVEatOpponent(chessboard.getPiecesB())))
                  {

                      std::cout << piece->getName() << " coord init " << piece->getCoord().first  << " " << piece->getCoord().second << " possible move "
                                << possibleMove.first << " " << possibleMove.second <<  std::endl;

                      // on garde dans un tampon l'échiquier actuel
                      Matrix    actualChessboard  = chessboard.getChessboard();
                      VPieces   actualDeadPieceB  = chessboard.getMyDeadPieceB();
                      VPieces   actualDeadPieceW  = chessboard.getMyDeadPieceW();
                      VPieces   actualPieceB      = chessboard.getPiecesB();
                      VPieces   actualPieceW      = chessboard.getPiecesW();
                      pairCoord actualCoord       = piece->getCoord();
                      // on la deplace
                      chessboard.move(possibleMove,piece->getCoord());
                      // on réévalue l'echiquier après ce déplacement
                      int eval = minmax(chessboard,depth-1,!maximizingPlayer);
                      // on regarde si le score est plus élevé que le score max actuelle
                      // si oui ce coup est plus intéréssant
                      maxEval  = std::max(maxEval,eval);
                      // on remet l'echiquier à sa position d'origine
                      chessboard.setChessboard(actualChessboard);
                      chessboard.setDeadPieceB(actualDeadPieceB);
                      chessboard.setDeadPieceW(actualDeadPieceW);
                      chessboard.setPiecesB(actualPieceB);
                      chessboard.setPiecesW(actualPieceW);
                      piece->setCoord(actualCoord);

                  }
             }

           }
        return minEval;
    }
}//minmax()


#endif // MINMAX_HPP
