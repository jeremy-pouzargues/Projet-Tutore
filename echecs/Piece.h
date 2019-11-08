#ifndef PIECE_H
#define PIECE_H

#include <iomanip>

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
    Color      myColor = blanc;
    pairCoord  myCoord = std::pair<unsigned,unsigned> (0,0);
public:
//    Piece();
    virtual ~Piece() {}
    virtual pairCoord move(Piece & piece, const pairCoord & coord) = 0;

    Color     getColor() const {return myColor;}
    pairCoord getCoord() const {return myCoord;}

    void setCoord(const pairCoord & coord)
    {
        myCoord.first  = coord.first;
        myCoord.second = coord.second;
    }
};

#endif // PIECE_H
