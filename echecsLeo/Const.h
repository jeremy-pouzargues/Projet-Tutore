/**
 *
 * \file    Const.h
 *
 * \authors  Laurent Vouriot
 *
 * \version  1.1
 *
 * \brief   les differentes constantes et typedefs
 *
 **/
#ifndef CONST_H
#define CONST_H
#include <iostream>

typedef std::pair<unsigned,unsigned> pairCoord;


/*
 *  ERREURS
 */

/**
 *@enum enumeration des erreurs
 */
enum Error{
    NOERR   = 0,
    BADMOVE = 1,
    NOPIECE = 2
};

// libelle des erreurs
// S pour string
const std::string SBADMOVE = " Mouvement illégal, vous ne pouvez pas faire ce déplacement pour cette pièce, voir les règles du jeu. ";
const std::string SNOPIECE = " Vous avez choisit la mauvaise pièce ";


/*
 * AFFICHAGE
 */

//constantes des pieces pour l'affichage
const char KVIDE  = '_';
//pion
const char KPAWNW = 'p';
const char KPAWNB = 'P';
//tour
const char KROOKW = 'r';
const char KROOKB = 'R';
//fous
const char KBISHOPW = 'b';
const char KBISHOPB = 'B';
//roi
const char KKINGW = 'k';
const char KKINGB = 'K';
//reine
const char KQUEENW = 'q';
const char KQUEENB = 'Q';
//cavalier
const char KKNIGHTW = 'c';
const char KKNIGHTB = 'C';

/*
 * COULEURS
 */

/**
 * @brief enumeration des couleurs
 */
enum Color {white, black, empty};
#endif // CONST_H
