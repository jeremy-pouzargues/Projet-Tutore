#include <vector>
#include <iostream>
#include "headers/Chessboard.h"
#include "headers/Pawn.h"
#include "headers/Empty.h"

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<shared_ptr<Piece>>(8));

    for (unsigned i(0); i < 8;++i) {
        for(unsigned j(0); j < 8; ++j)
        {
            myChessBoard[i][j] = shared_ptr<Piece>(new Empty(pairCoord(i,j)));
        }
    }
    for (unsigned i(0); i < 8;++i) {
        myChessBoard[7][i] = shared_ptr<Piece>(new Pawn(white,pairCoord(7,i)));
    }


}//ChessBoard

void ChessBoard::show() const{

    cout << " a b c d e f g h"<< endl;
    for (unsigned i(0); i < 8; ++i) {
        for (unsigned j(0); j < 8; ++j) {
            if ( j == 0)
                cout << '|';
            cout << myChessBoard[i][j]->getCarac() << '|';
            if ( j == 7)
                cout << i+1;
        }
        cout << endl;
    }
}//show()

void ChessBoard::move(const pairCoord & coordMove,const pairCoord & coordPiece)
{

    if(this->myChessBoard[coordMove.first][coordMove.second]->getCarac() == KVIDE)
    {
        //On effectue un swap entre la pièce vide et la pièce vide
        shared_ptr<Piece> tmp = this->myChessBoard[coordMove.first][coordMove.second];
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        this->myChessBoard[coordPiece.first][coordPiece.second] = tmp;
        //On set les coordonées à leur nouvelle coordonée
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        this->myChessBoard[coordPiece.first][coordPiece.second]->setCoord(coordPiece);
    }
    else //Si on "mange" une pièce adverse
    {
        unsigned indiceColorOpponent;
        this->myChessBoard[coordMove.first][coordMove.second]->getColor() == white ? indiceColorOpponent = 0 : indiceColorOpponent = 1;
        //On la place dans lal iste des pièces mortes
        this->myDeadPiece[indiceColorOpponent].push_back(myChessBoard[coordMove.first][coordMove.second]);
        //On remplace la piece mangé par la pièce bougé
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        //On actualise ses coordonées
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        //On créer un objet vide à son ancienne place
        this->myChessBoard[coordPiece.first][coordPiece.second] = shared_ptr<Piece>(new Empty(coordPiece));
    }
}//move()



