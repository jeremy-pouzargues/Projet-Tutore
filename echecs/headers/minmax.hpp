#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <limits.h>
#include "headers/Chessboard.h"


int evaluation(const ChessBoard chessboard)
{
    int compteur = 0;
    for(std::shared_ptr<Piece> piece : chessboard.getPiecesB())
    {
        compteur += piece->getValue();
    }
    for(std::shared_ptr<Piece> piece : chessboard.getPiecesW())
    {
        compteur -= piece->getValue();
    }

//##############################Test######################################
//    //Centre haut gauche
//    if(chessboard.getChessboard()[3][3]->getColor() == white)
//    {
//        compteur -= 20;
//        if(chessboard.getChessboard()[3][3]->getName() != "Pawn")
//        {
//            compteur -= 10;
//        }
//    }
//    else if (chessboard.getChessboard()[3][3]->getColor() == black)
//    {
//        compteur += 20;
//        if(chessboard.getChessboard()[3][3]->getName() != "Pawn")
//        {
//            compteur += 10;
//        }
//    }
//    //Centre haut droit
//    if(chessboard.getChessboard()[3][4]->getColor() == white)
//    {
//        compteur -= 20;
//        if(chessboard.getChessboard()[3][4]->getName() != "Pawn")
//        {
//            compteur -= 10;
//        }
//    }
//    else if (chessboard.getChessboard()[3][4]->getColor() == black)
//    {
//        compteur += 20;
//        if(chessboard.getChessboard()[3][4]->getName() != "Pawn")
//        {
//            compteur += 10;
//        }
//    }
//    //Centre bas gauche
//    if(chessboard.getChessboard()[4][3]->getColor() == white)
//    {
//        compteur -= 20;
//        if(chessboard.getChessboard()[4][3]->getName() != "Pawn")
//        {
//            compteur -= 10;
//        }
//    }
//    else if (chessboard.getChessboard()[4][3]->getColor() == black)
//    {
//        compteur += 20;
//        if(chessboard.getChessboard()[4][3]->getName() != "Pawn")
//        {
//            compteur += 10;
//        }
//    }
//    //Centre bas droit
//    if(chessboard.getChessboard()[4][4]->getColor() == white)
//    {
//        compteur -= 20;
//        if(chessboard.getChessboard()[4][4]->getName() != "Pawn")
//        {
//            compteur -= 10;
//        }
//    }
//    else if (chessboard.getChessboard()[4][4]->getColor() == black)
//    {
//        compteur += 20;
//        if(chessboard.getChessboard()[4][4]->getName() != "Pawn")
//        {
//            compteur += 10;
//        }
//    }

//    //Pour toutes les pièces noires
//    for (std::shared_ptr<Piece> piece : chessboard.getPiecesB())
//    {
//        if (piece->getCoord() == piece->getInitCoord()){ compteur -= 10;}

//    }

    //###############################################################
    return compteur;
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
                   VPieces    actualDeadPieceB   = chessboard.getMyDeadPieceB();
                   VPieces    actualDeadPieceW   = chessboard.getMyDeadPieceW();
                   VPieces actualPieceB = chessboard.getPiecesB();
                   VPieces actualPieceW = chessboard.getPiecesW();
                   pairCoord actualCoord = piece->getCoord();

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
           }
           return minEval;
    }
}//minmax()


#endif // MINMAX_HPP
