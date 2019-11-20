/**
*@file Piece.h
*@author Laurent
*/

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "Const.h"

/**
 * @author Laurent
 * @brief The Piece class
 * @version 1.0
 * @date 20/11/2019
 */
class Piece {
private:
    std::string myName;
    Color      myColor;
    pairCoord  myCoord;
public:  
    virtual ~Piece() {}
    /**
     * @brief verifie si les deplacements de la piece sont légaux
     * @param pairCoord coord, coordonnées de déplacements
     */
    virtual void move(const pairCoord & coord);

    //getter
    std::string getName() const;
    Color getColor()      const;
    pairCoord getCoord()  const;

    //setters
    void setCoord(const pairCoord & coord);

};

#endif // PIECE_H
