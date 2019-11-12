#ifndef PIECE_H
#define PIECE_H

#include <iomanip>

//constantes des pieces

const char KVIDE  = '_';

//pions
const char KPAWNB = 'p';
const char KPAWNN = '1';


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
    virtual pairCoord move(const pairCoord & coord) = 0;

    Color      getColor();
    pairCoord  getCoord();

    void setCoord(const pairCoord & coord);
    char getCarac ();
};

#endif // PIECE_H
