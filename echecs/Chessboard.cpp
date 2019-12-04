#include <vector>
#include <iostream>
#include "headers/Chessboard.h"
#include "headers/Pawn.h"
#include "headers/Empty.h"
#include "headers/Rook.h"
#include "headers/Knight.h"
#include "headers/Bishop.h"
#include "headers/Queen.h"
#include "headers/King.h"

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<shared_ptr<Piece>>(8));
    myDeadPiece.resize(30);
    myPiecesW.resize(0);
    myPiecesB.resize(0);

    for (unsigned i(0); i < 8;++i) {
        for(unsigned j(0); j < 8; ++j)
        {
            // cases vides
            myChessBoard[i][j] = shared_ptr<Piece>(new Empty(pairCoord(i,j)));
        }
    }
    for (unsigned i(0); i < 6;++i)
    {
        // pions blancs
        myChessBoard[6][i] = shared_ptr<Piece>(new Pawn(white,pairCoord(6,i)));
        myPiecesW.push_back(myChessBoard[6][i]);
        // pions noirs
        myChessBoard[1][i] = shared_ptr<Piece>(new Pawn(black,pairCoord(1,i)));
        myPiecesB.push_back(myChessBoard[1][i]);
    }

    // tours blancs
    myChessBoard[6][6] = shared_ptr<Piece>(new Rook(black,pairCoord(6,6)));
    myPiecesW.push_back(myChessBoard[6][6]);
    myChessBoard[7][7] = shared_ptr<Piece>(new Rook(white,pairCoord(7,7)));
    myPiecesW.push_back(myChessBoard[7][7]);
    // tours noirs
    myChessBoard[0][0] = shared_ptr<Piece>(new Rook(black,pairCoord(0,0)));
    myPiecesB.push_back(myChessBoard[0][0]);
//    myChessBoard[0][7] = shared_ptr<Piece>(new Rook(black,pairCoord(0,7)));
//    myPiecesB.push_back(myChessBoard[0][7]);
    myChessBoard[1][7] = shared_ptr<Piece>(new Pawn(white,pairCoord(1,7)));
    myPiecesW.push_back(myChessBoard[1][7]);

    // cavaliers blancs
    myChessBoard[7][1] = shared_ptr<Piece>(new Knight(white,pairCoord(7,1)));
    myPiecesW.push_back(myChessBoard[7][1]);
    myChessBoard[7][6] = shared_ptr<Piece>(new Knight(white,pairCoord(7,6)));
    myPiecesW.push_back(myChessBoard[7][6]);
    // cavaliers noirs
    myChessBoard[0][1] = shared_ptr<Piece>(new Knight(black,pairCoord(0,1)));
    myPiecesB.push_back(myChessBoard[0][1]);
    myChessBoard[0][6] = shared_ptr<Piece>(new Knight(black,pairCoord(0,6)));
    myPiecesB.push_back(myChessBoard[0][6]);

    // fous blancs
    myChessBoard[4][4] = shared_ptr<Piece>(new Bishop(white,pairCoord(4,4)));
    myPiecesW.push_back(myChessBoard[4][4]);
    myChessBoard[7][5] = shared_ptr<Piece>(new Bishop(white,pairCoord(7,5)));
    myPiecesW.push_back(myChessBoard[7][5]);
    // fous noirs
    myChessBoard[0][2] = shared_ptr<Piece>(new Bishop(black,pairCoord(0,2)));
    myPiecesB.push_back(myChessBoard[0][2]);
    myChessBoard[0][5] = shared_ptr<Piece>(new Bishop(black,pairCoord(0,5)));
    myPiecesB.push_back(myChessBoard[0][5]);

    //Reine blanche
    myChessBoard[7][3] = shared_ptr<Piece>(new Queen(white,pairCoord(7,3)));
    myPiecesW.push_back(myChessBoard[7][3]);
    //Reine noire
    myChessBoard[0][3] = shared_ptr<Piece>(new Queen(black,pairCoord(0,3)));
    myPiecesB.push_back(myChessBoard[0][3]);

//    //Roi Blanc
//    myChessBoard[7][4] = shared_ptr<Piece>(new King(white,pairCoord(7,4)));
//    myPiecesW.push_back(myChessBoard[7][4]);

    //Roi noir
    myChessBoard[0][4] = shared_ptr<Piece>(new King(black,pairCoord(0,4)));
    myPiecesB.push_back(myChessBoard[0][4]);


    //debug
    myChessBoard[4][4] = shared_ptr<Piece>(new King(white,pairCoord(4,4)));
    myPiecesW.push_back(myChessBoard[4][4]);


}//ChessBoard ()

void ChessBoard::show() const
{

    cout << " 0 1 2 3 4 5 6 7"<< endl;
    for (unsigned i(0); i < 8; ++i)
    {
        for (unsigned j(0); j < 8; ++j)
        {
            if ( j == 0)
                cout << '|';
            cout << myChessBoard[i][j]->getCarac() << '|';
            if ( j == 7)
                cout << i;
        }
        cout << endl;
    }
}//show()

void ChessBoard::move(const pairCoord & coordMove,const pairCoord & coordPiece)
{
    //Si la case est vide
    if(this->getChessboard()[coordMove.first][coordMove.second]->getName() == "Empty")
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
        //On la place dans la liste des pièces mortes
        this->myDeadPiece[indiceColorOpponent].push_back(myChessBoard[coordMove.first][coordMove.second]);
        //On remplace la piece mangé par la pièce bougé
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        //On actualise ses coordonées
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        //On créer un objet vide à son ancienne place
        this->myChessBoard[coordPiece.first][coordPiece.second] = shared_ptr<Piece>(new Empty(coordPiece));
    }



     //Un pion noir ne pourra jamais être à la ligne 0 et un pion blanc jamais à la ligne 7
    if(this->getChessboard()[coordMove.first][coordMove.second]->getName() == "Pawn" &&
       (this->getChessboard()[coordMove.first][coordMove.second]->getCoord().first == 0 ||
        this->getChessboard()[coordMove.first][coordMove.second]->getCoord().first == 7))
    {
        unsigned indiceColor;
        this->getChessboard()[coordMove.first][coordMove.second]->getColor() == white ? indiceColor = 0 : indiceColor = 1;
        cout << "Choisisser une pièce à faire revivre:" << endl;
        // Si il n'y a que des pions morts, alors il faudra sortir de la boucle
        unsigned cpt = 0;
        for(shared_ptr<Piece> piece : this->myDeadPiece[indiceColor])
        {
            if(piece->getName() != "Pawn")
            {
                cout << piece->getName() << "  ";
                ++cpt;
            }
            cout << endl << endl;
        }
        if(0 != cpt)
        {
            string pieceChosen;
            while(true)
            {
                cin >> pieceChosen;
                cpt = 0;
                while(cpt < getMyDeadPiece()[indiceColor].size() && getMyDeadPiece()[indiceColor][cpt]->getName() != pieceChosen)
                {
                    ++cpt;
                }
                if (getMyDeadPiece()[indiceColor][cpt]->getName() == pieceChosen && pieceChosen != "Pawn") break;
                else
                {
                    cout << "Pièce entrée incorrecte, veuillez réessayer" << endl;
                }
            }
            this->myChessBoard[coordMove.first][coordMove.second] = this->myDeadPiece[indiceColor][cpt];
            this->myDeadPiece[indiceColor].erase(this->myDeadPiece[indiceColor].begin()+cpt);
        }
        else cout << "Pas de pièce à faire revivre" << endl;
    }
}//move()

bool ChessBoard::find(const std::vector<pairCoord> &legalMoves, const pairCoord &moveChosen)
{
    for(pairCoord pieceCoord : legalMoves)
    {
        if (pieceCoord == moveChosen)
            return true;
    }
    return false;
}
Matrix ChessBoard::getChessboard() const {return myChessBoard;}

Matrix ChessBoard::getMyDeadPiece() const {return myDeadPiece;}

VPieces ChessBoard::getPiecesW() const {return myPiecesW;}

VPieces ChessBoard::getPiecesB() const {return myPiecesB;}
