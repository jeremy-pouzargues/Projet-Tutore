#include <iostream>
#include "ChessBoard.h"
using namespace std;

int main()
{
    Pawn Pawn1(blanc, pair<unsigned,unsigned> (1,1));
    ChessBoard chessBoard(Pawn1);
    chessBoard.show();

    unsigned x;
    unsigned y;
    cout << "saisir movement 1 " << endl;
    cin  >> x;
    cout << "saisir mouvement 2" << endl;
    cin >> y;
    pairCoord move1(x,y);

    chessBoard.actualize(Pawn1,Pawn1.move(move1));

}
