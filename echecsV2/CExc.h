/**
 * @file CExc.h
 * @author Marc Laporte, D Mathieu, Laurent Vouriot
 * @version 1.1
 * @brief Classe d'exception des tp modifiée pour le jeu d'échecs
 **/

#ifndef CEXC_H
#define CEXC_H

#include <iostream>
#include <exception>
#include <string>

#include "Const.h" //constantes des codes d'erreurs

class CException : public std::exception
    {
        std::string myLibelle;
        unsigned  myCodeErr;

      public :
        CException (const unsigned    & codeErr     = NOERR,
                    const std::string & libelle = std::string())     noexcept;
        virtual ~CException (void)                                   noexcept;

        //getters
        const std::string & getLibelle (void) const                  noexcept;
        unsigned getCodeErr     (void) const                         noexcept;



        virtual const char* what       (void) const                  noexcept;
        /**
         * @brief affiche le code d'erreur et son libelle
         */
        void display (void) const;

    }; // CException
#endif // CEXC_H
