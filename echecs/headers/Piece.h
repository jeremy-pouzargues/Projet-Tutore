/**
 * @author Jérémy, Laurent, Leo
 * @version 1.2
 * @file Piece.h include "header/Piece.h"
 */
#ifndef PIECE_H
#define PIECE_H

#include <iomanip>
#include "Const.h"
#include <vector>
#include <memory>

/**
 * @class Piece
 * @brief classe virtuelle Piece
 * Une pièce est définie par sa couleur, postion, caractère d'affichage.
 * La fonction virtuelle legalMoves constitue un vecteur de paires de coordonnées, qui représente toutes les cases accessibles par cette pièce
 * selon sa position.
 */
class Piece {
protected:
    Color           myColor;
    pairCoord       myCoord;
    pairCoord       myInitCoord;
    char            myCarac;
    std::string     myName;
    bool            canCastling;
    int             myValue;
public:
    virtual ~Piece() {}
    /**
     * @brief fonction abstraite de mouvement des pieces
     * @param pairCoord coord : coordonnées de déplacement
     * @return pairCoord
     * elle sera derivée dans chaque classe fille, chaque pièce à des mouvements differents
     */
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix ) = 0;


    typedef std::vector<std::shared_ptr<Piece>> VPieces;
    /**
     * @author Léo, Jérémy
     * @brief redefinition de legalMoves nécéssaire pour le roi uniquement
     * @param matrix, matrice qui represente l'échiquier
     * @param vEatOpponent matrice des mouvements létaux de l'adversaire
     * @return vecteur de pairCoord qui contient les coordonnées des mouvements possibles pour le roi
     *
     * Il est nécéssaire de rédéfinir legalMoves car le roi à un traitement différent des autres pièce,
     * il est interdit pour le roi de se mettre en échec on doit donc faire une double verification. Pour
     * ne pas rentrer dans une boucle infinie nous avons dû redefinir legalMoves() afin  que le roi adverse
     * ait un traitement spécial.
     *
     */
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> & vEatOpponent) = 0;


    //getters
    const Color       & getColor()       const;
    const pairCoord   & getCoord()       const;
    const pairCoord   & getInitCoord()   const;
    const char        & getCarac ()      const;
    const std::string & getName ()       const;
    const int         & getValue()       const;
    const bool        & getCanCastling() const;

    //setters
    void setCoord(const pairCoord & coord);
    void turnOffCastling();

};

#endif // PIECE_H
