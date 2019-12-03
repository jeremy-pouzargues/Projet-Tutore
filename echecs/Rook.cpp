#include "headers/Rook.h"
#include "headers/CExc.h"

Rook::Rook(const Color & color,const pairCoord & coord) {
    myColor = color;
    myCoord = coord;

    color == white ? myCarac = KROOKW : myCarac = KROOKB;
}//Rook()


std::vector<pairCoord> Rook::legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix) {

    std::vector<pairCoord> VMoves;
    Color colorOpponent;
    this->getColor() == white ? colorOpponent = black : colorOpponent = white;


    unsigned column;
    unsigned line;

    column  = this->getCoord().second;

      //Si la tour est en haut elle ne pourra pas aller en haut
      if(this->getCoord().first != 0) {
          line = this->getCoord().first - 1;

          while(matrix[line][column]->getColor() != this->getColor()) {
              VMoves.push_back(pairCoord(line,column));
              if(line == 0)break;
              if (matrix[line][column]->getColor() == colorOpponent) break;
              --line;
          }
      }

      //Si la tour est en bas elle ne pourra pas aller en bas
      if(this->getCoord().first != 7) {
          line = this->getCoord().first + 1;

          //test de cases disponibles dans une colonne vers le bas
          while(matrix[line][column]->getColor() != this->getColor()) {
              VMoves.push_back(pairCoord(line,column));
              if( line == 7 )break;
              if (matrix[line][column]->getColor() == colorOpponent) break;
              ++line;
          }
      }

       line = this->getCoord().first;

      // tests horizontaux
      //Si la tour est à gauche elle ne pourra pas aller à gauche
      if(this->getCoord().second != 0) {
          column  = this->getCoord().second - 1;
          // vers la droite
            while(matrix[line][column]->getColor() != this->getColor()) {
              VMoves.push_back(pairCoord(line,column));
              if(column == 0 ) break;
              if (matrix[line][column]->getColor() == colorOpponent) break;
              --column;
          }
      }

      // collé à gauche
      if(this->getCoord().second != 7) {
          column  = this->getCoord().second + 1;
          //vers la gauche
          while(matrix[line][column]->getColor() != this->getColor()) {
              VMoves.push_back(pairCoord(line,column));
              if( column == 7 ) break;
              if (matrix[line][column]->getColor() == colorOpponent) break;
              ++column;
          }
      }

    return VMoves;
}//legalMove()
