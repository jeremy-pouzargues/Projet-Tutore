#include "ChessBoard.h"
#include <vector>
#include "Piece.h"

using namespace std;

ChessBoard::ChessBoard(Piece & piece) {



    myChessBoard.resize(8,vector<char>(8));

    //Pion pion1(blanc, pair<unsigned,unsigned> (0,0));
    // toutes les cases sont vides
    for (unsigned i (0); i < 8; ++i) {
        for(unsigned j(0); j < 8; ++j) {
          {
                myChessBoard[i][j] = KVIDE;
            }
        }
        myChessBoard[piece.getCoord().first][piece.getCoord().first] = piece.getCarac();
     }

} //ChessBoard

    //pieces blanches
//    myChessBoard[0][7]  = 'T'; // new tour(0,0);
//    myChessBoard[0][0]  = 'T';
//    myChessBoard[0][1]  = 'C'; // new Cavalier(0,1);
//    myChessBoard[0][6]  = 'C';
//    myChessBoard[0][2]  = 'F'; // new Fou ...
//    myChessBoard[0][5]  = 'F';
//    myChessBoard[0][3]  = 'R';
//    myChessBoard[0][4]  = 'r';
//    for (unsigned i(0); i < 8; ++i) {
//                myChessBoard[1][i] = 'p';
//        }

//    // pieces noires
//    myChessBoard[7][0] = '1'; // new tour(0,0);
//    myChessBoard[7][7] = '1';
//    myChessBoard[7][1] = '2'; // new Cavalier(0,1);
//    myChessBoard[7][6] = '2';
//    myChessBoard[7][2] = '3'; // new Fou ...
//    myChessBoard[7][5] = '3';
//    myChessBoard[7][3] = '4';
//    myChessBoard[7][4] = '5';

//    for (unsigned j(0); j < 8; ++j) {
//                myChessBoard[6][j] = '6';
//        }


//    for (unsigned i(2); i < 6; ++i){
//        for (unsigned j(0); j < 8; ++j) {
//            myChessBoard[i][j] = '_';
//        }
//     }


/**
 * @author Laurent
 * @brief afficher l'ChessBoard avec le contenu de ses cases
 * @class ChessBoard ChessBoard.h "include ChessBoard.h"
 **/
void  ChessBoard::show() const{
    cout << " a b c d e f g h"<<endl;
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

void ChessBoard::actualize(Piece & piece, const pairCoord & newCoord) {
    for (unsigned i (0); i < 8; ++i) {
        for(unsigned j(0); j < 8; ++j) {
          {
                myChessBoard[i][j] = KVIDE;
            }
        }
        myChessBoard[piece.getCoord().first][piece.getCoord().first] = piece.getCarac();
       }
    this->show();
}//actualiser




