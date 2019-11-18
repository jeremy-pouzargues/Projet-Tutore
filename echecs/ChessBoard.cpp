#include <vector>
#include "ChessBoard.h"
#include "Pawn.h"
#include "CExc.h"

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<char>(8));
    myPiecesW.resize(16);
    myPiecesB.resize(16);

    //on met toutes les cases vides
    for (unsigned i (0); i < 8; ++i) {
        for(unsigned j(0); j < 8; ++j) {
            myChessBoard[i][j] = KVIDE;
        }
    }

    // création des pions blancs et noirs et stockage dans leurs vecteurs propres
    for (unsigned i(0); i < myPiecesW.size(); ++i) {
        myPiecesW[i] = new Pawn(white,pairCoord(6,i));
        myPiecesB[i] = new Pawn(black,pairCoord(1,i));
    }

    // on dispose chaque piece sur l'echiquier
    for (unsigned k(0); k < myPiecesW.size(); ++k) {
        myChessBoard[myPiecesW[k]->getCoord().first][myPiecesW[k]->getCoord().second] = myPiecesW[k]->getCarac();
        myChessBoard[myPiecesB[k]->getCoord().first][myPiecesB[k]->getCoord().second] = myPiecesB[k]->getCarac();
    }
}//ChessBoard


// GETTERS / SETTERS
unsigned ChessBoard::find(const pairCoord & coord, const VPieces & vpieces) {
    for(unsigned i(0); i < vpieces.size()-1; ++i) {
        if (vpieces[i]->getCoord() == coord)
            return i;
    }
    throw(CException (NOPIECE,SNOPIECE));
}//find()


VPieces ChessBoard::getPieces(const Color & color) {
    if (color == white)
        return myPiecesW;
    else
        return myPiecesB;
}//getPieces

void ChessBoard::setPieces(const Color & color, const VPieces & newVPieces) {
    if (color == white)
        myPiecesW = newVPieces;
    else
        myPiecesB = newVPieces;
}//setPieces()


void  ChessBoard::show() const{
    cout << " a b c d e f g h"<< endl;
    for (unsigned i(0); i < 8; ++i) {
        for (unsigned j(0); j < 8; ++j) {
            if ( j == 0)
                cout << '|';
            cout << myChessBoard[i][j] << '|';
            if ( j == 7)
                cout << i+1;
        }
    cout << endl;
    }
}//show()




void ChessBoard::actualize(const pairCoord & oldCoord, const pairCoord & newCoord, const Color & color) {


    VPieces vpiece = getPieces(color);
    unsigned pieceChosen = find(oldCoord,vpiece);

    // on met à jour la position de la piece, si le movement est illegal on recommence.
    vpiece[pieceChosen]->setCoord(vpiece[pieceChosen]->move(newCoord));

    // on change l'affichage de la matrice
    myChessBoard[oldCoord.first][oldCoord.second] = KVIDE;
    myChessBoard[newCoord.first][newCoord.second] = vpiece[pieceChosen]->getCarac();
    this->show();


    /*if(playerTurn) {
        unsigned i = find(oldCoord,myPiecesW);
        myPiecesW[i]->setCoord(newCoord);
        myChessBoard[oldCoord.first][oldCoord.second] = KVIDE;
        myChessBoard[newCoord.first][newCoord.second] = myPiecesW[i]->getCarac();
        this->show();

    }
    else {
        unsigned i = find(oldCoord,myPiecesB);
        myPiecesB[i]->setCoord(newCoord);
        myChessBoard[oldCoord.first][oldCoord.second] = KVIDE;
        myChessBoard[newCoord.first][newCoord.second] = myPiecesB[i]->getCarac();
        this->show();
    }*/
}//actualize



