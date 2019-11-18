/**
 *
 * \file     CstCodErr.h
 *
 * \authors  M. Laporte, D. Mathieu, Laurent Vouriot
 *
 * \version  V1.1
 *
 * \brief    Codes d'erreurs et libelles
 *
 **/
#ifndef CODEERR_H
#define CODEERR_H
#include <iostream>

enum {
    //code no error..
    NOERR   = 0,
    BADMOVE = 1
};

// libelle des erreurs
std::string SBADMOVE = "movement illégale vous ne pouvez pas déplacer cette piece de la sorte, voir les règles du jeu";
#endif // CODEERR_H
