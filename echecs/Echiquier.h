#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include <vector>

#include "Pion.h"
/**
 * @author Laurent
 * @brief echiquier
 * @class Echiquier Echiquier.h "include Echiquier.h"
 **/

typedef std::vector<std::vector<char>> Matrice;
class Echiquier
{
private:

    Matrice myEchiquier;
public:
     Echiquier();
     void show() const;
};//Echiquier


#endif // ECHIQUIER_H
