#include <vector>
#include <iostream>
#include "headers/Chessboard.h"
#include "headers/Pawn.h"
#include "headers/Empty.h"
#include "headers/Rook.h"
#include "headers/Knight.h"
#include "headers/Bishop.h"
#include "headers/Queen.h"
#include "headers/King.h" 

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<shared_ptr<Piece>>(8));
    myPiecesW.resize(0);
    myPiecesB.resize(0);

    for (unsigned i(0); i < 8;++i) {
        for(unsigned j(0); j < 8; ++j)
        {
            // cases vides
            myChessBoard[i][j] = shared_ptr<Piece>(new Empty(pairCoord(i,j)));
        }
    }

    //Roi Blanc
    myChessBoard[7][4] = shared_ptr<Piece>(new King(white,pairCoord(7,4)));
    myPiecesW.push_back(myChessBoard[7][4]);
    //Roi noir
    myChessBoard[0][4] = shared_ptr<Piece>(new King(black,pairCoord(0,4)));
    myPiecesB.push_back(myChessBoard[0][4]);


//    for (unsigned i(0); i < 8;++i)
//    {
//        // pions blancs
//        myChessBoard[6][i] = shared_ptr<Piece>(new Pawn(white,pairCoord(6,i)));
//        myPiecesW.push_back(myChessBoard[6][i]);
//        // pions noirs
//        myChessBoard[1][i] = shared_ptr<Piece>(new Pawn(black,pairCoord(1,i)));
//        myPiecesB.push_back(myChessBoard[1][i]);
//    }

    // tours blancs
    myChessBoard[7][0] = shared_ptr<Piece>(new Rook(white,pairCoord(7,0)));
    myPiecesW.push_back(myChessBoard[7][0]);
    myChessBoard[7][7] = shared_ptr<Piece>(new Rook(white,pairCoord(7,7)));
    myPiecesW.push_back(myChessBoard[7][7]);

    // tours noirs
    myChessBoard[0][0] = shared_ptr<Piece>(new Rook(black,pairCoord(0,0)));
    myPiecesB.push_back(myChessBoard[0][0]);
    myChessBoard[0][7] = shared_ptr<Piece>(new Rook(black,pairCoord(0,7)));
    myPiecesB.push_back(myChessBoard[0][7]);

    // cavaliers blancs
    myChessBoard[7][1] = shared_ptr<Piece>(new Knight(white,pairCoord(7,1)));
    myPiecesW.push_back(myChessBoard[7][1]);
    myChessBoard[7][6] = shared_ptr<Piece>(new Knight(white,pairCoord(7,6)));
    myPiecesW.push_back(myChessBoard[7][6]);
    // cavaliers noirs
    myChessBoard[0][1] = shared_ptr<Piece>(new Knight(black,pairCoord(0,1)));
    myPiecesB.push_back(myChessBoard[0][1]);
    myChessBoard[0][6] = shared_ptr<Piece>(new Knight(black,pairCoord(0,6)));
    myPiecesB.push_back(myChessBoard[0][6]);

    // fous blancs
    myChessBoard[7][2] = shared_ptr<Piece>(new Bishop(white,pairCoord(7,2)));
    myPiecesW.push_back(myChessBoard[7][2]);
    myChessBoard[7][5] = shared_ptr<Piece>(new Bishop(white,pairCoord(7,5)));
    myPiecesW.push_back(myChessBoard[7][5]);
    // fous noirs
    myChessBoard[0][2] = shared_ptr<Piece>(new Bishop(black,pairCoord(0,2)));
    myPiecesB.push_back(myChessBoard[0][2]);
    myChessBoard[0][5] = shared_ptr<Piece>(new Bishop(black,pairCoord(0,5)));
    myPiecesB.push_back(myChessBoard[0][5]);

    //Reine blanche
    myChessBoard[7][3] = shared_ptr<Piece>(new Queen(white,pairCoord(7,3)));
    myPiecesW.push_back(myChessBoard[7][3]);
    //Reine noire
    myChessBoard[0][3] = shared_ptr<Piece>(new Queen(black,pairCoord(0,3)));
    myPiecesB.push_back(myChessBoard[0][3]);



}//ChessBoard ()

void ChessBoard::show() const
{

    cout << " 0 1 2 3 4 5 6 7"<< endl;
    for (unsigned i(0); i < 8; ++i)
    {
        for (unsigned j(0); j < 8; ++j)
        {
            if ( j == 0)
                cout << '|';
            cout << myChessBoard[i][j]->getCarac() << '|';
            if ( j == 7)
                cout << i;
        }
        cout << endl;
    }
}//show()

void ChessBoard::swap(const pairCoord &coordMove, const pairCoord &coordPiece)
{
    //On effectue un swap entre la pièce vide et la pièce
    shared_ptr<Piece> tmp = this->myChessBoard[coordMove.first][coordMove.second];
    this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
    this->myChessBoard[coordPiece.first][coordPiece.second] = tmp;
    //On set les coordonées à leur nouvelle coordonée
    this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
    this->myChessBoard[coordPiece.first][coordPiece.second]->setCoord(coordPiece);
}

void ChessBoard::move(const pairCoord & coordMove,const pairCoord & coordPiece)
{
    if(getChessboard()[coordPiece.first][coordPiece.second]->getCanCastling() &&
            getChessboard()[coordPiece.first][coordPiece.second]->getName() == "King" &&
           abs(int(coordMove.second) - int(coordPiece.second)) > 1)
    {
        if(coordMove.second == 1)
        {
            swap(pairCoord(coordPiece.first,2),pairCoord(coordPiece.first,0));
            swap(pairCoord(coordPiece.first,1), coordPiece);
        }
        else
        {
            swap(pairCoord(coordPiece.first,5), pairCoord(coordPiece.first,7));
            swap(pairCoord(coordPiece.first,6), coordPiece);
        }
    }
    //Si la case est vide
    else if(this->myChessBoard[coordMove.first][coordMove.second]->getName() == "Empty")
    {
        swap(coordMove,coordPiece);
    }
    else //Si on "mange" une pièce adverse
    {
        //on l'enleve du vecteur de piece de sa couleur
        unsigned cpt = 0;
        if(this->getChessboard()[coordMove.first][coordMove.second]->getColor() == white)
        {
            while(coordMove != myPiecesW[cpt]->getCoord()) {++cpt;}
            myPiecesW.erase(myPiecesW.begin()+cpt);
        }
        else
        {
            while(coordMove != myPiecesB[cpt]->getCoord()) {++cpt;}
            myPiecesB.erase(myPiecesB.begin()+cpt);
        }

        //On la place dans la liste des pièces mortes
        if(myChessBoard[coordMove.first][coordMove.second]->getColor() == white)
        {
            this->myDeadPiecesW.push_back(myChessBoard[coordMove.first][coordMove.second]);
        }
        else
        {
            this->myDeadPiecesB.push_back(myChessBoard[coordMove.first][coordMove.second]);
        }

        //On remplace la piece mangé par la pièce bougé
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        //On actualise ses coordonées
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        //On créer un objet vide à son ancienne 
        this->myChessBoard[coordPiece.first][coordPiece.second] = shared_ptr<Piece>(new Empty(coordPiece));


    }


    //Un pion noir ne pourra jamais être à la ligne 0 et un pion blanc jamais à la ligne 7
    if(this->getChessboard()[coordMove.first][coordMove.second]->getName() == "Pawn" &&
            (this->getChessboard()[coordMove.first][coordMove.second]->getCoord().first == 0 ||
             this->getChessboard()[coordMove.first][coordMove.second]->getCoord().first == 7))
    {
        Color color;
        this->getChessboard()[coordMove.first][coordMove.second]->getColor() == white ? color = white : color = black;
        string pieceChosen;
        while(true)
        {
            cout << "Choisisser une pièce à faire revivre: Tour, Cavalier, Fou, Reine" << endl;
            getline(cin,pieceChosen);
            if("Reine" == pieceChosen)
            {
                myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Queen(color,pairCoord(coordMove.first,coordMove.second)));
                break;
            }
            else if("Tour" == pieceChosen)
            {
                myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Rook(color,pairCoord(coordMove.first,coordMove.second)));
                break;
            }
            else if("Cavalier" == pieceChosen)
            {
                myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Knight(color,pairCoord(coordMove.first,coordMove.second)));
                break;
            }
            else if("Fou" == pieceChosen)
            {
                myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Bishop(color,pairCoord(coordMove.first,coordMove.second)));
                break;
            }
            else
            {
                cout << "Rentrer une pièce valide!" << endl;
            }
        }
        unsigned cpt = 0;
        if(color == white)
        {
            while(coordMove != myPiecesW[cpt]->getCoord()) {++cpt;}
            myPiecesW[cpt] = myChessBoard[coordMove.first][coordMove.second];
        }
        else
        {
            while(coordMove != myPiecesB[cpt]->getCoord()) {++cpt;}
            myPiecesB[cpt] = myChessBoard[coordMove.first][coordMove.second];
        }

    }
    if(getChessboard()[coordMove.first][coordMove.second]->getName() == "King" || getChessboard()[coordMove.first][coordMove.second]->getName() == "Rook")
    {
        getChessboard()[coordMove.first][coordMove.second]->turnOffCastling();
    }
}//move()

bool ChessBoard::find(const std::vector<pairCoord> &legalMoves, const pairCoord &moveChosen)
{
    for(pairCoord pieceCoord : legalMoves)
    {
        if (pieceCoord == moveChosen)
            return true;
    }
    return false;
}


vector<vector<pairCoord>> ChessBoard::getVEatOpponent(const VPieces & VPiecesOpponent)
{
    // on va récuếrer la liste de tous les coups possibles des adversaires et les mettres dans un vecteur
    vector<vector<pairCoord>> VEatOpponent;
    // pour chaque piece adverse
    for (shared_ptr<Piece> piece : VPiecesOpponent)
    {
        // si c'est un roi traitement particulier pour eviter une boucle infinie
        // on va récupérer les coord de tous les mouvements qu'il pourrait hypothetiquement réaliser
        // et les ajouter dans la matrice VMovesOpponent
        if(piece->getName() == "King")
        {
            vector<pairCoord> VMovesKing;
            unsigned line   = piece->getCoord().first;
            unsigned column = piece->getCoord().second;
            Color colorPiece = piece->getColor();


            // si le roi n'est pas tout en haut
            if(line != 0)
            {
                if(column != 0 && this->getChessboard()[line-1][column-1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column-1));
                if(this->getChessboard()[line-1][column]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column));
                if(column != 7 && this->getChessboard()[line-1][column+1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line-1,column+1));
            }

            // pas tout à droite et si le pion à sa droite n'est pas de la même couleur
            if(column !=7 && this->getChessboard()[line][column+1]->getColor() != colorPiece )
                VMovesKing.push_back(pairCoord(line,column+1));

            //tout en bas
            if(line != 7)
            {
                if(column != 7 && this->getChessboard()[line+1][column+1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1,column+1));
                if(this->getChessboard()[line+1][column]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1,column));
                if(column != 0 && this->getChessboard()[line+1][column-1]->getColor() != colorPiece )
                    VMovesKing.push_back(pairCoord(line+1, column-1));
            }

            // de même qu'à droite mais à gauche merci.
            if(column != 0 && this->getChessboard()[line][column-1]->getColor() != colorPiece )
                VMovesKing.push_back(pairCoord(line,column-1));

            VEatOpponent.push_back(VMovesKing);
        }
        else if(piece->getName() == "Pawn")
        {
            vector<pairCoord> VEatPawn;
            unsigned line   = piece->getCoord().first;
            unsigned column = piece->getCoord().second;
            //newLine va etre égal la ligne de notre pion avec un déplacement vers le haut ou le bas selon la couleur
            unsigned newLine;
            Color colorOpponent;
            if (piece->getColor() == white)
            {
                newLine = line - 1;
                colorOpponent = black;
            }
            else
            {
                newLine = line + 1;
                colorOpponent = white;
            }
            //Ces deux conditions vont regarder si des pièces sont dans les diagonales directes de notre pion afin de pouvoir éventuellement les manger
            if (column != 7 && this->getChessboard()[newLine][column + 1]->getColor() == colorOpponent)
                VEatPawn.push_back(this->getChessboard()[newLine][column + 1]->getCoord());
            if (column != 0 && this->getChessboard()[newLine][column - 1]->getColor() == colorOpponent)
                VEatPawn.push_back(this->getChessboard()[newLine][column - 1]->getCoord());
            VEatOpponent.push_back(VEatPawn);
        }
        // sinon on ajoute à la matrice les mouvements legaux de toutes les autres pieces
        else
        {
            VEatOpponent.push_back(piece->legalMoves(this->getChessboard()));
        }
    }
    return VEatOpponent;
}//getVEatOpponent()

vector<pairCoord> ChessBoard::matrixToVector(const vector<vector<pairCoord>> & matrixCoord)
{
    vector<pairCoord> newVector;
    for (unsigned i (0); i < matrixCoord.size(); ++i)
    {
        for (unsigned j(0); j < matrixCoord[i].size(); ++j)
            newVector.push_back(matrixCoord[i][j]);
    }
    return newVector;
}

ChessBoard::ChessBoard(const Matrix & chessBoard, const VPieces & piecesW, const VPieces & PiecesB, const VPieces & deadPiecesW, const VPieces & deadPiecesB)
{
    this->myChessBoard = copyMatrix(chessBoard);
    this->myPiecesW = copyVPieces(piecesW);
    this->myPiecesB = copyVPieces(PiecesB);
    this->myDeadPiecesW = copyVPieces(deadPiecesW);
    this->myDeadPiecesB = copyVPieces(deadPiecesB);
}


Matrix ChessBoard::copyMatrix(const Matrix & matrixCopy)
{
    Matrix VFinalMatrix;
    for(vector<shared_ptr<Piece>> VP : matrixCopy)
    {
        VFinalMatrix.push_back(copyVPieces(VP));
    }
    return  VFinalMatrix;
}

VPieces ChessBoard::copyVPieces(const VPieces & VPiecesCopy)
{
    VPieces VPiecesFinal;
    for(shared_ptr<Piece> p : VPiecesCopy)
    {
        if(p->getName() == "Pawn")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Pawn(p->getColor(),p->getCoord(),p->getInitCoord())));
        else if (p->getName() == "Bishop")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Bishop(p->getColor(),p->getCoord(),p->getInitCoord())));
        else if (p->getName() == "Knight")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Knight(p->getColor(),p->getCoord(),p->getInitCoord())));
        else if (p->getName() == "Rook")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Rook(p->getColor(),p->getCoord(),p->getInitCoord(),p->getCanCastling())));
        else if(p->getName() == "King")
            VPiecesFinal.push_back(shared_ptr<Piece>(new King(p->getColor(),p->getCoord(),p->getInitCoord(),p->getCanCastling())));
        else if(p->getName() == "Queen")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Queen(p->getColor(),p->getCoord(),p->getInitCoord())));
        else if(p->getName() == "Empty")
            VPiecesFinal.push_back(shared_ptr<Piece>(new Empty(p->getCoord())));
    }
    return VPiecesFinal;
}


const Matrix & ChessBoard::getChessboard()    const {return myChessBoard;}
const VPieces & ChessBoard::getPiecesW()      const {return myPiecesW;}
const VPieces & ChessBoard::getPiecesB()      const {return myPiecesB;}
const VPieces & ChessBoard::getMyDeadPieceB() const { return myDeadPiecesB;}
const VPieces & ChessBoard::getMyDeadPieceW() const { return myDeadPiecesW;}

void ChessBoard::setChessboard (const Matrix & newChessboard) { this->myChessBoard = newChessboard; }
void ChessBoard::setPiecesW (const VPieces & newVPieceW)      { this->myPiecesW = newVPieceW; }
void ChessBoard::setPiecesB (const VPieces & newVPieceB)      { this->myPiecesB = newVPieceB; }
void ChessBoard::setDeadPieceW(const VPieces &newVDeadPiece)  { this->myDeadPiecesW = newVDeadPiece; }
void ChessBoard::setDeadPieceB(const VPieces&newVDeadPiece)   { this->myDeadPiecesB = newVDeadPiece; }

//setters
