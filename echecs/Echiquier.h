#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>


typedef std::vector<char /* pion */> VLine;
typedef std::vector<VLine> Matrice;
/**
 * @author Laurent
 * @brief echiquier
 * @class Echiquier Echiquier.h "include Echiquier.h"
 **/
class Echiquier
{
private:
    Matrice myEchiquier;
public:
     Echiquier();

     void show() const;
};//Echiquier


#endif // ECHIQUIER_H
