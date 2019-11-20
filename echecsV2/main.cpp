#include <iostream>
#include "ChessBoard.h"
#include "CExc.h"

using namespace std;
/**
 * @brief play
 * @param chessBoard
 */
void play(ChessBoard & chessBoard) {

    bool player (true);
    bool perdu (false);

    while(!perdu) {

        // selection de la piece à bouger
        unsigned oldX,oldY,newX,newY;
        cout << "saisir coord piece" << endl;
        cin  >> oldX;
        cout << "saisir coord piece 2" << endl;
        cin >> oldY;
        pairCoord oldCoord(oldX,oldY);

        // on fait le mvt de cette piece, on testera si ce mouvement est legal dans actualize
        cout << "saisir move 1" << endl;
        cin  >> newX;
        cout << "saisir move 2" << endl;
        cin  >> newY;
        pairCoord newCoord(newX,newY);


        // TODO ChessBoard actualize

        player = !player;

        //pas  de conditions de victoire encore
    }
}//play()

int main() {

    ChessBoard chessBoard;
//    chessBoard.show();

    try {
        play(chessBoard);
    } catch (CException & exception) {
        exception.display();
//        chessBoard.show();
        play(chessBoard);
    } catch (...) {
        cout << "erreur pas encore implementée" << endl;
    }

    cout << "partie finie " << endl;
}//main()
