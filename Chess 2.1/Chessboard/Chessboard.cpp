#include <vector>
#include <iostream>
#include "Chessboard/Chessboard.h"
#include "Pieces/Pawn.h"
#include "Pieces/Empty.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

#include "GraphicalObject/ChoosePieceWindow.h"
#include <GraphicalObject/GfxObject.h>

using namespace std;

pairCoord ChessBoard::getCoordClicked() const
{
    return CoordClicked;
}

void ChessBoard::setCoordClicked(const pairCoord &value)
{
    CoordClicked = value;
}

QString ChessBoard::getChoosedPiece() const
{
    return choosedPiece;
}

void ChessBoard::setChoosedPiece(QString value)
{
    this->choosedPiece = value;
}

bool ChessBoard::getSwitchMove() const
{
    return switchMove;
}

void ChessBoard::setSwitchMove(bool value)
{
    switchMove = value;
}

void ChessBoard::refreshGraphicalVector()
{
    for(int i=0 ; i<8 ; ++i)
    {
        for(int j=0 ; j<8;++j)
        {
            hisGraphicalVector[j][i] = nullptr;
        }
    }
}

void ChessBoard::display(QWidget * currentPage,MainWindow * hisMainWindow)
{
    bool color(true);
    //    bool theColor(true);
    hisGraphicalVector.resize(8,vector<GfxObject *>(8));
    for(int i=0 ; i<8 ; ++i)
    {
        if(!color)
        {
            color =true;
        }
        else
        {
            color =false;
        }
        for(int j=0 ; j<8;++j)
        {
            std::string str;
            str.push_back(this->myChessBoard[j][i]->getCarac());
            QString qstr = QString::fromStdString(str);

            qDebug() << (j+1)*(i+1);


//            if(i+j*i%2 == 0)
//            if(j+(i)%2 == 0)
            if(!color)
            {
                color =true;
            }
            else
            {
                color =false;
            }
//            if(j%2 == 0)
//            {
//                if((j+1)*(i+1)%2 == 0)
//                {
//                    color =true;
//                }
//                else
//                {
//                    color =false;
//                }
//            }
//            else
//            {
//                if((j+1)*(i+1)%2 == 1)
//                {
//                    color =true;
//                }
//                else
//                {
//                    color =false;
//                }
//            }


            //            if((j+1)*(i+1)%2 == 0)
            //            {
            //                color =true;
            //            }
            //            else
            //            {
            //                color =false;
            //            }

            GfxObject *Current = new GfxObject(currentPage,60+i*60,110+j*60,this->myChessBoard[j][i],qstr,this,hisMainWindow,color);
            hisGraphicalVector[j][i] = Current;
        }
    }
}//display()

void ChessBoard::switchClickedSignal()
{
    if(this->AnyoneClicked)
    {
        this->AnyoneClicked = false;
    }
    else
    {
        this->AnyoneClicked = true;
    }
}

bool const & ChessBoard::getSignal()
{
    return this->AnyoneClicked;
}


void ChessBoard::getBoardClear()
{
    bool color(true);


    this->setCoordClicked(pairCoord(0,0)); //rm la case select
    for (unsigned i(0);i<hisGraphicalVector.size();++i) {

        if(!color)
        {
            color =true;
        }
        else
        {
            color =false;
        }

        for (unsigned j(0);j<hisGraphicalVector.size();++j) {
            if(!color)
            {
                color =true;
                hisGraphicalVector[j][i]->getButton()->setStyleSheet(
                            "background-color: rgba(241, 217, 181, 1);"
                            "border:1px solid black;"
                            );
            }
            else
            {
                color =false;
                hisGraphicalVector[j][i]->getButton()->setStyleSheet(
                                "background-color: rgba(181, 136, 99, 1);"
                                "border:1px solid black;"
                                );
            }


            hisGraphicalVector[j][i]->setClicked(false);
            hisGraphicalVector[j][i]->setLegalMoves(false);
        }
    }

}

void ChessBoard::setGraphicalLegalMoves(std::vector<pairCoord> legalMoves)
{
    for(pairCoord pieceCoord : legalMoves)
    {
        switch(hisGraphicalVector[pieceCoord.first][pieceCoord.second]->getHisPiece()->getColor()) //SI QQUN FAIT CA EN ENTREPRISE IL SE FAIT VIRER CASH
        {
        case white:
            break;
        default:
            hisGraphicalVector[pieceCoord.first][pieceCoord.second]->getButton()->setStyleSheet(
                        "background:blue;"
                        "border:1px solid black;"
                        );
            hisGraphicalVector[pieceCoord.first][pieceCoord.second]->setLegalMoves(true);
            break;
        }
    }
}

bool ChessBoard::getEndSignal() const
{
    return EndSignal;
}

void ChessBoard::setEndSignal(bool value)
{
    EndSignal = value;
}

ChessBoard::ChessBoard() : switchMove(false) {
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


    for (unsigned i(0); i < 8;++i)
    {
        // pions blancs
        myChessBoard[6][i] = shared_ptr<Piece>(new Pawn(white,pairCoord(6,i)));
        myPiecesW.push_back(myChessBoard[6][i]);
        // pions noirs
        myChessBoard[1][i] = shared_ptr<Piece>(new Pawn(black,pairCoord(1,i)));
        myPiecesB.push_back(myChessBoard[1][i]);
    }

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
    else
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
        if(color == black)
        {
            myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Queen(black,pairCoord(coordMove.first,coordMove.second)));
        }
        else
        {

            string pieceChosen;
            while(true)
            {
                cout << "Choisisser une pièce à faire revivre: Tour, Cavalier, Fou, Reine" << endl;
                getline(cin,pieceChosen);
                if("Reine" == pieceChosen)
                {
                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Queen(white,pairCoord(coordMove.first,coordMove.second)));
                    break;
                }
                else if("Tour" == pieceChosen)
                {
                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Rook(white,pairCoord(coordMove.first,coordMove.second)));
                    break;
                }
                else if("Cavalier" == pieceChosen)
                {
                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Knight(white,pairCoord(coordMove.first,coordMove.second)));
                    break;
                }
                else if("Fou" == pieceChosen)
                {
                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Bishop(white,pairCoord(coordMove.first,coordMove.second)));
                    break;
                }
                else
                {
                    cout << "Rentrer une pièce valide!" << endl;
                }
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

bool ChessBoard::isCheckMate(const bool & player)
{

    ChessBoard tmpChessboard(this->getChessboard(), this->getPiecesW(), this->getPiecesB(), this->getMyDeadPieceW(), this->getMyDeadPieceB());

    ChessBoard bufChessboard(this->getChessboard(), this->getPiecesW(), this->getPiecesB(), this->getMyDeadPieceW(), this->getMyDeadPieceB());

    VPieces vPieces;
    VPieces vPiecesOpponent;
    shared_ptr<Piece> playerKing;
    VPieces newVPiecesOpponent;
    if (player)
    {
        vPieces = bufChessboard.getPiecesW();
        vPiecesOpponent = bufChessboard.getPiecesB();
    }
    else
    {
        vPieces = bufChessboard.getPiecesB();
        vPiecesOpponent = bufChessboard.getPiecesW();
    }

    for (shared_ptr<Piece> piece : vPieces)
    {
        if (piece->getName() == "King")
        {
            for (pairCoord tryCoord : piece->legalMoves(bufChessboard.getChessboard(), bufChessboard.getVEatOpponent(vPiecesOpponent)))
            {
                // tampon de sauvegarde
                //                ChessBoard tmpChessboard(this->getChessboard(), this->getPiecesW(), this->getPiecesB(), this->getMyDeadPieceW(), this->getMyDeadPieceB());
                tmpChessboard.move(tryCoord, piece->getCoord());
                if (player)
                {
                    playerKing = tmpChessboard.getPiecesW()[0];
                    newVPiecesOpponent = tmpChessboard.getPiecesB();
                }
                else
                {

                    playerKing = tmpChessboard.getPiecesB()[0];
                    newVPiecesOpponent = tmpChessboard.getPiecesW();

                }
                //                player ? newVPiecesOpponent = tmpChessboard.getPiecesB() : newVPiecesOpponent = tmpChessboard.getPiecesW();
                if (! find(tmpChessboard.matrixToVector(tmpChessboard.getVEatOpponent(newVPiecesOpponent)), playerKing->getCoord()))
                {
                    //                    cout << "Roi : " << playerKing->getCoord().first << playerKing->getCoord().second << " " << piece->getName() << " : " << piece->getCoord().first << piece->getCoord().second << "->" << tryCoord.first << tryCoord.second << endl;
                    return false;
                }

                tmpChessboard = bufChessboard;


            }
        }
        else
        {
            for (pairCoord tryCoord : piece->legalMoves(bufChessboard.getChessboard()))
            {
                // tampon de sauvegarde
                tmpChessboard.move(tryCoord, piece->getCoord());
                if (player)
                {
                    playerKing = tmpChessboard.getPiecesW()[0];
                    newVPiecesOpponent = tmpChessboard.getPiecesB();
                }
                else
                {
                    playerKing = tmpChessboard.getPiecesB()[0];
                    newVPiecesOpponent = tmpChessboard.getPiecesW();
                }
                //                player ? newVPiecesOpponent = this->getPiecesB() : newVPiecesOpponent = this->getPiecesW();
                if (! find(tmpChessboard.matrixToVector(tmpChessboard.getVEatOpponent(newVPiecesOpponent)), playerKing->getCoord()))
                {
                    //                    cout << "Roi : " << playerKing->getCoord().first << playerKing->getCoord().second << " " << piece->getName() << " : " << piece->getCoord().first << piece->getCoord().second << "->" << tryCoord.first << tryCoord.second << endl;
                    return false;
                }
                tmpChessboard = bufChessboard;
            }



        }
    }

    return true;
}





const ChessBoard ChessBoard::getBuffChessboard (ChessBoard chessboard) const
{
    return chessboard;
}

const Matrix  ChessBoard::getBuffChessboard (Matrix matrix)const {return matrix;}
const VPieces ChessBoard::getBuffDeadPieceB (VPieces vDeadPieceB) const {return vDeadPieceB;}
const VPieces ChessBoard::getBuffDeadPieceW (VPieces vDeadPieceW) const {return vDeadPieceW;}
const VPieces ChessBoard::getBuffPiecesW (VPieces vPiecesW) const {return vPiecesW;}
const VPieces ChessBoard::getBuffPiecesB (VPieces vPiecesB) const {return vPiecesB;}


ChessBoard::ChessBoard(const Matrix & chessBoard, const VPieces & piecesW, const VPieces & PiecesB, const VPieces & deadPiecesW, const VPieces & deadPiecesB)
{
    this->myChessBoard = copyMatrix(chessBoard);
    this->myPiecesW.resize(piecesW.size());
    this->myPiecesB.resize(PiecesB.size());

    unsigned cptW = 1;
    unsigned cptB = 1;
    for (vector<shared_ptr<Piece>> lineMatrix : this->myChessBoard)
    {
        for (shared_ptr<Piece> piece : lineMatrix)
        {
            if (piece->getColor() == white)
            {
                if (piece->getName() != "King")
                {
                    this->myPiecesW[cptW] = piece;
                    ++cptW;
                }
                else
                {
                    this->myPiecesW[0] = piece;
                }
            }
            else if (piece->getColor() == black)
            {
                if (piece->getName() != "King")
                {
                    this->myPiecesB[cptB] = piece;
                    ++cptB;
                }
                else
                {
                    this->myPiecesB[0] = piece;
                }
            }
        }
    }

    this->myDeadPiecesW = copyVPieces(deadPiecesW);
    this->myDeadPiecesB = copyVPieces(deadPiecesB);
}

ChessBoard & ChessBoard::operator= (const ChessBoard & chessboard)
{
    this->myChessBoard = copyMatrix(chessboard.getChessboard());
    this->myPiecesW.resize(chessboard.getPiecesW().size());
    this->myPiecesB.resize(chessboard.getPiecesB().size());

    unsigned cptW = 1;
    unsigned cptB = 1;
    for (vector<shared_ptr<Piece>> lineMatrix : this->myChessBoard)
    {
        for (shared_ptr<Piece> piece : lineMatrix)
        {
            if (piece->getColor() == white)
            {
                if (piece->getName() != "King")
                {
                    this->myPiecesW[cptW] = piece;
                    ++cptW;
                }
                else
                {
                    this->myPiecesW[0] = piece;
                }
            }
            else if (piece->getColor() == black)
            {
                if (piece->getName() != "King")
                {
                    this->myPiecesB[cptB] = piece;
                    ++cptB;
                }
                else
                {
                    this->myPiecesB[0] = piece;
                }
            }
        }
    }

    this->myDeadPiecesW = copyVPieces(chessboard.getMyDeadPieceW());
    this->myDeadPiecesB = copyVPieces(chessboard.getMyDeadPieceB());
    return *this;
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




