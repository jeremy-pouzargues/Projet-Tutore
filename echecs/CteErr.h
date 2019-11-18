/**
 *
 * \file     CstCodErr.h
 *
 * \authors  M. Laporte, D. Mathieu, Laurent Vouriot
 *
 * \version  1.1
 *
 * \brief    Codes d'erreurs et libelles
 *
 **/
#ifndef CODEERR_H
#define CODEERR_H
#include <iostream>

enum {
    NOERR   = 0,
    BADMOVE = 1,
    NOPIECE = 2
};

// libelle des erreurs
// S pour string
const std::string SBADMOVE = " Mouvement illégal, vous ne pouvez pas faire ce déplacement pour cette pièce, voir les règles du jeu. ";
const std::string SNOPIECE = " Vous avez choisit la mauvaise pièce ";
#endif // CODEERR_H
