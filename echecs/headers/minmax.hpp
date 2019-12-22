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
    ChessBoard actualChessboard(chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    ChessBoard bufChessboard(chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    VPieces vPiecesOpponenent;
    VPieces vPieces;
    if(!maximizingPlayer)
    {
        vPiecesOpponenent = actualChessboard.getPiecesW();
        vPieces = actualChessboard.getPiecesB();
    }
    else
    {
        vPiecesOpponenent = actualChessboard.getPiecesB();
        vPieces = actualChessboard.getPiecesW();
    }
    if(actualChessboard.find(actualChessboard.matrixToVector(actualChessboard.getVEatOpponent(vPiecesOpponenent)),vPieces[0]->getCoord()))return INT_MIN;

//    if (actualChessboard.isCheckMate(maximizingPlayer))
//    {
//        std::cout << "Salut mon pote t'as gagné " << std::endl;
//        if(maximizingPlayer)
//            return INT_MAX;
//        else
//            return INT_MIN;
//    }
    //    ChessBoard actualChessboard(chessboard.getChessboard(),chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    if (depth == 0 /* ||  la partie n'est pas finie*/)
    {
        int tmp = evaluation(actualChessboard);
        //        std::cout << "Evaluation:              " << tmp << std::endl;
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

                actualChessboard.move(possibleMove,piece->getCoord());
                // on réévalue l'echiquier après ce déplacement
                int eval = minmax(actualChessboard,depth-1,!maximizingPlayer);
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                if(eval > maxEval) maxEval = eval;
                actualChessboard = bufChessboard;
            }
        }
        return maxEval;
    }
    else // joueur minimisant
    {
        // idem que pour le joueur maximisant, mais à l'inverse

        minEval = INT_MAX; //pseudo +infini
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



//                if (actualChessboard.isCheckMate(!maximizingPlayer))
//                {
//                    std::cout << "Salut mon pote t'as perdu " << std::endl;
//                    return INT_MIN;
//                }

                actualChessboard.move(possibleMove,piece->getCoord());
                // on réévalue l'echiquier après ce déplacement
                int eval = minmax(actualChessboard,depth-1,!maximizingPlayer);
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                if(eval < minEval)minEval = eval;
                actualChessboard = bufChessboard;
            }

        }
        return minEval;
    }
}//minmax()


std::vector<pairCoord> finalMinmax(ChessBoard & chessboard, const int & depth, const bool & maximizingPlayer)
{
    ChessBoard actualChessboard(chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    ChessBoard bufChessboard(chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());

    int maxEval = INT_MIN;// pseudo -Infini

    std::vector<pairCoord> vMoveFinal(2);

    // pour chaque pieces noires, pour l'instant le joueur maximisant est toujours le noir
    for(std::shared_ptr<Piece> piece : actualChessboard.getPiecesB())
    {

        pairCoord pieceCoord = piece->getCoord();
        // pour chaque coup possible par pièce noires, l'IA
        std::vector<pairCoord> vLegalMoves;
        piece->getName() != "King" ? vLegalMoves = piece->legalMoves(actualChessboard.getChessboard()) :
                vLegalMoves =  piece->legalMoves(actualChessboard.getChessboard(),actualChessboard.getVEatOpponent(actualChessboard.getPiecesW()));
        for (pairCoord possibleMove : vLegalMoves)
        {

            pairCoord coordMove = possibleMove;
            actualChessboard.move(possibleMove,piece->getCoord());
            // on réévalue l'echiquier après ce déplacement
            int eval = minmax(actualChessboard,depth-1,!maximizingPlayer);
            // on regarde si le score est plus élevé que le score max actuelle
            // si oui ce coup est plus intéréssant
            if(eval > maxEval)
            {
                maxEval = eval;
                vMoveFinal[0] = pieceCoord;
                vMoveFinal[1] = coordMove;
            }
            std::cout << "Eval :" <<pieceCoord.first << pieceCoord.second <<  " -> " <<coordMove.first << coordMove.second << "  =  " << eval << std::endl;
            actualChessboard = bufChessboard;
        }
    }
    std::cout << "Evalauation final :" <<vMoveFinal[0].first << vMoveFinal[0].second <<  " -> " <<vMoveFinal[1].first << vMoveFinal[1].second << std::endl;
    return vMoveFinal;

}


#endif // MINMAX_HPP
