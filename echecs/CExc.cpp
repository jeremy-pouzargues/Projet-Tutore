#include "headers/CExc.h"

CException::CException (const unsigned & codeErr,
                        const std::string & libelle) noexcept : myLibelle(libelle),myCodeErr(codeErr) {}
CException::~CException                    (void) noexcept {}


const std::string & CException::getLibelle (void) const noexcept {return myLibelle;}
unsigned CException::getCodeErr            (void) const noexcept {return myCodeErr;}

void CException::display (void) const {
    std::cout <<  "\n"      << "Erreur "  << myCodeErr
              <<  myLibelle << std::endl;
}//display()

const char* CException::what               (void) const noexcept  {return myLibelle.c_str();}
