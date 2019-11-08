#include "Echiquier.h"
#include <vector>
using namespace std;

Echiquier::Echiquier() {

    myEchiquier.resize(8,vector<char>(8));
    Pion pion1(blanc, pair<unsigned,unsigned> (0,0));
    // toutes les cases sont vides
    for (unsigned i (0); i < 8; ++i) {
        for(unsigned j(0); j < 8; ++j) {
          {
                myEchiquier[i][j] = 'o';
            }
        }
        Pion pion1(blanc, pair<unsigned,unsigned> (0,0));
        myEchiquier[pion1.getCoord().first][pion1.getCoord().second] = 'p';
     }

} //echiquier

    //pieces blanches
//    myEchiquier[0][7]  = 'T'; // new tour(0,0);
//    myEchiquier[0][0]  = 'T';
//    myEchiquier[0][1]  = 'C'; // new Cavalier(0,1);
//    myEchiquier[0][6]  = 'C';
//    myEchiquier[0][2]  = 'F'; // new Fou ...
//    myEchiquier[0][5]  = 'F';
//    myEchiquier[0][3]  = 'R';
//    myEchiquier[0][4]  = 'r';
//    for (unsigned i(0); i < 8; ++i) {
//                myEchiquier[1][i] = 'p';
//        }

//    // pieces noires
//    myEchiquier[7][0] = '1'; // new tour(0,0);
//    myEchiquier[7][7] = '1';
//    myEchiquier[7][1] = '2'; // new Cavalier(0,1);
//    myEchiquier[7][6] = '2';
//    myEchiquier[7][2] = '3'; // new Fou ...
//    myEchiquier[7][5] = '3';
//    myEchiquier[7][3] = '4';
//    myEchiquier[7][4] = '5';

//    for (unsigned j(0); j < 8; ++j) {
//                myEchiquier[6][j] = '6';
//        }


//    for (unsigned i(2); i < 6; ++i){
//        for (unsigned j(0); j < 8; ++j) {
//            myEchiquier[i][j] = '_';
//        }
//     }


/**
 * @author Laurent
 * @brief afficher l'echiquier avec le contenu de ses cases
 * @class Echiquier Echiquier.h "include Echiquier.h"
 **/
void  Echiquier::show() const{
    cout << " a b c d e f g h"<<endl;
    for (unsigned i(0); i < 8; ++i) {
        for (unsigned j(0); j < 8; ++j) {
            if ( j == 0)
                cout << '|';
            cout << myEchiquier[i][j] << '|';
            if ( j == 7)
                cout << i+1;
        }
    cout << endl;
    }
}//show()
