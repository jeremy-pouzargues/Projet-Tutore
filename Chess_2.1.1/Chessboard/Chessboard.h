/**
 * @file   ChessBoard.h
 * @author Leo, Laurent
 * @version 1.5
 **/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Pieces/Piece.h"

#include <QWidget>
#include "GraphicalObject/GfxObject.h"
class GfxObject;
class Piece;

typedef std::vector<std::vector<std::shared_ptr<Piece>>> Matrix;
typedef std::vector<std::shared_ptr<Piece>> VPieces;

class MainWindow;

/**
* @brief  classe echiquier avec un vecteur de vecteur de Piece, un matrice, qui represente l'echiquier
* @class  ChessBoard, include "Chessboard/ChessBoard.h"
**/
class ChessBoard {
private:
    Matrix myChessBoard;                                                        // matrice de toutes les cases/pieces
    VPieces myPiecesW;                                                          //vecteur des pieces blanches
    VPieces myPiecesB;                                                          //vecteur des pieces noires
    VPieces myDeadPiecesW;
    VPieces myDeadPiecesB;

    QString * selectedPiece;                                                    //Piece selectionné au clique de l'utilisateur
    QString   choosedPiece;                                                     //Piece choisi pour la transformation
    inline static std::vector<std::vector< GfxObject * >> hisGraphicalVector;   //Vecteur d'object graphique
    pairCoord                   CoordClicked;                                   //Paire de l'objet selectionné
    bool                        AnyoneClicked;                                  //Si une case est cliqué
    bool                        switchMove;                                     //FRANFRAN
    bool                        EndSignal;                                      //Signal de fin de partie

public:
     ChessBoard();
     ChessBoard(const Matrix & chessBoard, const VPieces & piecesW, const VPieces & PiecesB, const VPieces & deadPiecesW, const VPieces & deadPiecesB);
     ChessBoard & operator= (const ChessBoard & chessboard);

     /**
      * @brief affiche la matrice avec les pieces selon leurs coordonnées
      */
     void show() const;
     Matrix copyMatrix(const Matrix & matrixCopy);
     VPieces copyVPieces(const VPieces & VPiecesCopy);

     //getter
     const Matrix  & getChessboard() const;
     const VPieces & getMyDeadPieceB () const;
     const VPieces & getMyDeadPieceW () const;
     const VPieces & getPiecesW () const;
     const VPieces & getPiecesB () const;

     const ChessBoard getBuffChessboard (ChessBoard chessboard) const;

     const Matrix  getBuffChessboard (Matrix matrix)const;
     const VPieces getBuffDeadPieceB (VPieces vDeadPieceB) const;
     const VPieces getBuffDeadPieceW (VPieces vDeadPieceW) const;
     const VPieces getBuffPiecesW (VPieces vPiecesW) const;
     const VPieces getBuffPiecesB (VPieces vPiecesB) const;

     //setter
     void setChessboard (const Matrix & newChessboard);
     void setDeadPieceW (const VPieces & newVDeadPiece);
     void setDeadPieceB (const VPieces & newVDeadPiece);
     void setPiecesW (const VPieces & newVPieceW);
     void setPiecesB (const VPieces & newVPieceB);


     /**
      * @brief déplacement de la pièce
      * @param Coordonnées de déplacement de la pièce
      * @param Coordonnées actuels de la pièce
      */
     void move(const pairCoord & coordMove,const pairCoord & coordPiece);


     /**
      * @brief échange la position de 2 pièces (en l'occurence une case vide et une pièce)
      * @param Coordonnées de déplacement de la pièce
      * @param Coordonnées actuels de la pièce
      */
     void swap(const pairCoord & coordMove,const pairCoord & coordPiece);

     bool find (const std::vector<pairCoord> & legalMoves, const pairCoord & moveChosen);
     /**
      * @brief renvoie l'ensemble des pièces qui menaçent les pièces du joueur
      * @param VPiecesOpponent vecteur des pièces adverses
      * @return vecteur de vecteur de coordonnées
      */
     std::vector<std::vector<pairCoord>> getVEatOpponent(const VPieces & VPiecesOpponent);
     /**
      * @brief converti l'échiquier (matrice) en vecteur
      * @param matrixCoord vecteur de vecteur de paires  de coordonnées qui réprésente l'échiquier
      * @return un vecteur de paire de coordonnées
      */
     std::vector<pairCoord> matrixToVector (const std::vector<std::vector<pairCoord>> & matrixCoord);

     /**
      * @brief verifie si la pièce est en échec et mat
      * @param player : joueur en cours
      * @return true si en échec et mats false sinon
      */
     bool isCheckMate (const bool & player);




//===================================== IHM ================================================================

     void display(QWidget * currentPage,MainWindow * hisMainWindow); //ANCIENNEMENT SHOW //FRANFRAN

     void switchClickedSignal();  //FRANFRAN
     bool const & getSignal();  //FRANFRAN
     void getBoardClear();   //FRANFRAN
     void setGraphicalLegalMoves (std::vector<pairCoord> legalMoves);  //FRANFRAN

     pairCoord getCoordClicked() const;  //FRANFRAN
     void setCoordClicked(const pairCoord &value);  //FRANFRAN

     QString getChoosedPiece() const;  //FRANFRAN
     void setChoosedPiece(QString value);  //FRANFRAN
     bool getSwitchMove() const;  //FRANFRAN
     void setSwitchMove(bool value);  //FRANFRAN

     void refreshGraphicalVector();  //FRANFRAN

     bool getEndSignal() const; //FRANFRAN
     void setEndSignal(bool value); //FRANFRAN

//     static std::vector<std::vector<GfxObject *> > getHisGraphicalVector();
};//Echiquier


#endif // ECHIQUIER_H
