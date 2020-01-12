/**
 * @file     Const.h
 * @authors  Laurent
 * @version  1.2
 * @brief   les differentes constantes, typedefs et enums
 **/
#ifndef CONST_H
#define CONST_H
#include <iostream>
#include <vector>
#include <memory>


typedef std::pair<unsigned,unsigned> pairCoord;

/*
 *  ERREURS
 */

/**
 *@enum Error : enumeration des erreurs
 */
enum Error{
    NOERR       = 0,
    BADMOVE     = 1,
    BADPIECE    = 2,
    BADINPUT    = 3,
    OUTOFRANGE  = 4,
    CHECK       = 5
};

// libelle des erreurs
// S pour string
const std::string SBADMOVE      = " Mouvement illégal, vous ne pouvez pas faire ce déplacement pour cette pièce, voir les règles du jeu. ";
const std::string SBADPIECE     = " Vous avez choisi la mauvaise pièce ";
const std::string SBADINPUT     = " Veuillez entrer des chiffres pour les mouvements";
const std::string SOUTOFRANGE   = " Vous avez saisi des coordonnés qui ne sont pas sur l'echiquer";
const std::string SCHECK        = " Le roi est en échec, vous devez le protéger";


/*
 * CARACTERES D'AFFICHAGE
 */

//constantes des pieces pour l'affichage
const char KEMPTY = '_';
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
 * @brief Color  enumeration des couleurs
 */
enum Color {white, black, empty};

#endif // CONST_H
