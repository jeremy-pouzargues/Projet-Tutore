#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <limits.h>
#include "headers/Chessboard.h"


int count(const std::vector<pairCoord> & vCoord, const pairCoord & coord)
{
    int cpt = 0;
    for (pairCoord coordTmp : vCoord)
    {
        if(coordTmp == coord) ++cpt;
    }
    return cpt;
}

int evaluation(const ChessBoard chessboard)
{
    int compteur = 0;
    ChessBoard actualChessboard(chessboard.getChessboard(), chessboard.getPiecesW(), chessboard.getPiecesB(), chessboard.getMyDeadPieceW(), chessboard.getMyDeadPieceB());
    std::vector<pairCoord> vEatW = actualChessboard.matrixToVector(actualChessboard.getVEatOpponent(actualChessboard.getPiecesW()));
    std::vector<pairCoord> vEatB = actualChessboard.matrixToVector(actualChessboard.getVEatOpponent(actualChessboard.getPiecesB()));
    for(std::shared_ptr<Piece> piece : actualChessboard.getPiecesB())
    {
        compteur += piece->getValue();
        if(piece->getCoord() != piece->getInitCoord())
            compteur += 40;
        if(piece->getName() != "King")
            compteur += 20 * piece->legalMoves(actualChessboard.getChessboard()).size();
        compteur -= 10 * count(vEatW,piece->getCoord());
    }
    for(std::shared_ptr<Piece> piece : actualChessboard.getPiecesW())
    {
        compteur -= piece->getValue();
        if(piece->getCoord() != piece->getInitCoord())
            compteur -= 40;
        if(piece->getName() != "King")
            compteur -= 20 * piece->legalMoves(actualChessboard.getChessboard()).size();
        compteur += 10 * count(vEatB,piece->getCoord());
    }

    //##############################Test######################################
        //Centre haut gauche
        if(chessboard.getChessboard()[3][3]->getColor() == white)
        {
            compteur -= 50;
            if(chessboard.getChessboard()[3][3]->getName() != "Pawn")
            {
                compteur -= 30;
            }
        }
        else if (chessboard.getChessboard()[3][3]->getColor() == black)
        {
            compteur += 50;
            if(chessboard.getChessboard()[3][3]->getName() != "Pawn")
            {
                compteur += 30;
            }
        }
        //Centre haut droit
        if(chessboard.getChessboard()[3][4]->getColor() == white)
        {
            compteur -= 50;
            if(chessboard.getChessboard()[3][4]->getName() != "Pawn")
            {
                compteur -= 30;
            }
        }
        else if (chessboard.getChessboard()[3][4]->getColor() == black)
        {
            compteur += 50;
            if(chessboard.getChessboard()[3][4]->getName() != "Pawn")
            {
                compteur += 30;
            }
        }
        //Centre bas gauche
        if(chessboard.getChessboard()[4][3]->getColor() == white)
        {
            compteur -= 50;
            if(chessboard.getChessboard()[4][3]->getName() != "Pawn")
            {
                compteur -= 30;
            }
        }
        else if (chessboard.getChessboard()[4][3]->getColor() == black)
        {
            compteur += 50;
            if(chessboard.getChessboard()[4][3]->getName() != "Pawn")
            {
                compteur += 30;
            }
        }
        //Centre bas droit
        if(chessboard.getChessboard()[4][4]->getColor() == white)
        {
            compteur -= 50;
            if(chessboard.getChessboard()[4][4]->getName() != "Pawn")
            {
                compteur -= 30;
            }
        }
        else if (chessboard.getChessboard()[4][4]->getColor() == black)
        {
            compteur += 50;
            if(chessboard.getChessboard()[4][4]->getName() != "Pawn")
            {
                compteur += 30;
            }
        }


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

    if(actualChessboard.find(actualChessboard.matrixToVector(actualChessboard.getVEatOpponent(vPiecesOpponenent)),vPieces[0]->getCoord()))
    {
        if(!maximizingPlayer)return INT_MIN;
        else return INT_MAX;
    }

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
                actualChessboard = bufChessboard;
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                if(eval > maxEval) maxEval = eval;
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
                actualChessboard = bufChessboard;
                // on regarde si le score est plus élevé que le score max actuelle
                // si oui ce coup est plus intéréssant
                if(eval < minEval) minEval = eval;
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
