/**
 * @file minmax.h
 * @author Laurent
 * @brief algorithme du minmax avec fonction d'évaluation
 * @version 1.0
 */

#ifndef MINMAX_H
#define MINMAX_H


#include "Chessboard.h"

/**
 * @brief evaluation
 * @param chessboard
 * @return un score pour selon les pieces de l'echiquier
 */
int evaluation(ChessBoard chessboard) {
   return 0;
}

/**
 * @brief algorithme minmax
 * @param chessboard
 * @param depth
 * @param maximizingPlayer
 * @return le score d'une positions
 */
int minmax(ChessBoard & chessboard,const int & depth,const bool & maximizingPlayer);



#endif // MINMAX_H
