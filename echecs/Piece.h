#ifndef PIECE_H
#define PIECE_H

#include <iomanip>

//constantes des pieces

const char KVIDE  = '_';

//pions
const char KPIONB = 'p';
const char KPIONN = '1';


// couleurs  des pieces
enum Color {blanc, noir};

typedef std::pair<unsigned,unsigned> pairCoord;
/**
 * @author Laurent
 * @brief classe abstraite qui definit les pieces avec leur couleur postion et la fonction de mouvement 
 * @class Echiquier Echiquier.h "include Echiquier.h"
 */
class Piece
{
protected:
    Color      myColor;
    pairCoord  myCoord;
    char       myCarac;
public:

    virtual ~Piece() {}
    virtual pairCoord move(Piece & piece, const pairCoord & coord) = 0;

    Color     getColor() const {return myColor;}
    pairCoord getCoord() const {return myCoord;}

    void setCoord(const pairCoord & coord);
    char getCarac ();
};

#endif // PIECE_H
