#ifndef PIECE_H
#define PIECE_H

#include <iomanip>

//constantes des pieces

const char KVIDE  = '_';
//pions
const char KPAWNW = 'p';
const char KPAWNB = '1';


// couleurs  des pieces
enum Color {white, black};

typedef std::pair<unsigned,unsigned> pairCoord;

/**
 * @author Laurent
 * @brief classe abstraite qui definit les pieces avec leur couleur postion et la fonction de mouvement 
 * @class Echiquier Echiquier.h "include Echiquier.h"
 */
class Piece {
protected:
    Color      myColor;
    pairCoord  myCoord;
    char       myCarac;
public:
    //Piece() {}
    virtual ~Piece() {}
    virtual pairCoord move(const pairCoord & coord) = 0;



    //getters
    Color      getColor();
    pairCoord  getCoord();
    char getCarac ();

    //setters
    void setCoord(const pairCoord & coord);

};

#endif // PIECE_H
