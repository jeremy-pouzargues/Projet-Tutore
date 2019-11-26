#include <vector>
#include <iostream>
#include "Chessboard.h"
#include "Pawn.h"
#include "Empty.h"

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<shared_ptr<Piece>>(8));

    for (unsigned i(0); i < 7;++i) {
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



