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
    //        if(chessboard.getChessboard()[4][3]->getName() != "Pawn")getPiecesB
    //        {2147483647
    //            compteur += 10;
    //        }getPiecesB
    //    }
    //    //Centre bas droitgetPiecesB
    //    if(chessboard.getChessboard()[4][4]->getColor() == white)
    //    {
    //        compteur -= 20;getPiecesB
    //        if(chessboard.getChessboard()[4][4]->getName() != "Pawn")getPiecesB
    //        {
    //            compteur -= 10;
    //        }getPiecesB
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
     ChessBoard actualChessboard(chessboard.getChessboard(),chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    if (depth == 0 /* ||  la partie n'est pas finie*/)
    {
        int tmp = evaluation(actualChessboard);
        std::cout << "Evaluation:              " << tmp << std::endl;
        return tmp;
    }


    int maxEval;
    int minEval;


    if (maximizingPlayer)
    {
        maxEval = INT_MIN;//pseudo -infini
        //On créer un chessboard actuel
//        ChessBoard actualChessboard(chessboard.getChessboard(),chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
        // pour chaque pieces noires, pour l'instant le joueur maximisant est toujours le noir
        for(std::shared_ptr<Piece> piece : actualChessboard.getPiecesB())
        {
            // pour chaque coup possible par pièce noires, l'IA
            std::vector<pairCoord> vLegalMoves;
            piece->getName() != "King" ? vLegalMoves = piece->legalMoves(actualChessboard.getChessboard()) :
                    vLegalMoves =  piece->legalMoves(actualChessboard.getChessboard(),actualChessboard.getVEatOpponent(actualChessboard.getPiecesW()));
            for (pairCoord possibleMove : vLegalMoves)
            {

                std::cout << piece->getName() << " " << piece->getCoord().first  << " " << piece->getCoord().second << " "
                          << possibleMove.first << " " << possibleMove.second <<  std::endl;

                // on garde dans un tampon l'échiquier actuel

                // on la deplace
                actualChessboard.move(possibleMove,piece->getCoord());
                // on réévalue l'echiquier après ce déplacement
                int eval = minmax(actualChessboard,depth-1,!maximizingPlayer);
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                maxEval  = std::max(maxEval,eval);
            }
        }
        return maxEval;
    }
    else // joueur minimisant
    {
        // idem que pour le joueur maximisant, mais à l'inverse

        minEval = INT_MIN; //pseudo +infini
//        ChessBoard actualChessboard(chessboard.getChessboard(),chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
               // pour chaque pieces blanches, joueur humain
        for(std::shared_ptr<Piece> piece : actualChessboard.getPiecesW())
        {
            // pour chaque coup possible par pièce noires, l'IA
            std::vector<pairCoord> vLegalMoves;
            piece->getName() != "King" ? vLegalMoves = piece->legalMoves(actualChessboard.getChessboard()) :
                    vLegalMoves =  piece->legalMoves(actualChessboard.getChessboard(),actualChessboard.getVEatOpponent(actualChessboard.getPiecesB()));
            for (pairCoord possibleMove : vLegalMoves)
            {

                std::cout << piece->getName() << " " << piece->getCoord().first  << " " << piece->getCoord().second << " "
                          << possibleMove.first << " " << possibleMove.second <<  std::endl;



                // on garde dans un tampon l'échiquier actuel

                // on la deplace
                actualChessboard.move(possibleMove,piece->getCoord());
                // on réévalue l'echiquier après ce déplacement
                int eval = minmax(actualChessboard,depth-1,!maximizingPlayer);
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                minEval  = std::max(minEval,eval);
            }

        }
        return minEval;
    }
}//minmax()


#endif // MINMAX_HPP
