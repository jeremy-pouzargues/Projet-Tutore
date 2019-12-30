#include "GfxObject.h"

bool GfxObject::getClicked() const
{
    return Clicked;
}

void GfxObject::setClicked(bool value)
{
    Clicked = value;
}

std::shared_ptr<Piece> GfxObject::getHisPiece() const
{
    return hisPiece;
}

bool GfxObject::getLegalMoves() const
{
    return legalMoves;
}

void GfxObject::setLegalMoves(bool value)
{
    legalMoves = value;
}

void GfxObject::setHisPiece(const std::shared_ptr<Piece> &value)
{
    hisPiece = value;
}

void GfxObject::refreshGraphical()
{
    std::string str = typeid (*hisPiece).name();
    str.replace(0,1,"");
    QString qstr = QString::fromStdString(str);
    std::string pathToAdd;
    switch(hisPiece->getColor())
    {
    case white:
        pathToAdd = "White";
        break;
    case black:
        pathToAdd = "Black";
        break;
    default:
        break;
    }
    QString qPathToAdd = QString::fromStdString(pathToAdd);
    QPixmap test (":/Ressources/Pieces/" + qstr + qPathToAdd + ".png");
    QIcon ButtonIcon(test);
    this->getButton()->setIcon(ButtonIcon);
    this->getButton()->setIconSize(QSize(60,60));
}


GfxObject::GfxObject(QWidget*where,int x,int y,std::shared_ptr<Piece> SaPiece,QString name,ChessBoard * sonBoard,MainWindow * hisMainWindow,bool color): Clicked(false),hisPiece(SaPiece),hisBoard(sonBoard),legalMoves(false),where(where),hisMainWindow(hisMainWindow)
{
    QPushButton * current = new QPushButton(where);
    std::string str = typeid (*hisPiece).name();
    str.replace(0,1,"");
    QString qstr = QString::fromStdString(str);

    std::string pathToAdd;
    switch(hisPiece->getColor())
    {
    case white:
        pathToAdd = "White";
        break;
    case black:
        pathToAdd = "Black";
        break;
    default:
        break;
    }


    QString qPathToAdd = QString::fromStdString(pathToAdd);

    QPixmap test (":/Ressources/Pieces/" + qstr + qPathToAdd + ".png");
    QIcon ButtonIcon(test);
    current->setIcon(ButtonIcon);
    current->setIconSize(QSize(60,60));


    if(color)
    {
    current->setStyleSheet(
                "background-color: rgba(241, 217, 181, 1);"
                "border:1px solid black;"
                );
    }
    else
    {
        current->setStyleSheet(
                    "background-color: rgba(181, 136, 99, 1);"
                    "border:1px solid black;"
                    );
    }
    current->move(x,y);
    const QSize sizeCase = QSize(60,60);
    current->setMinimumSize(sizeCase);
    current->setMaximumSize(sizeCase);
    this->button = current;
    connect(this->button,SIGNAL(clicked()),this,SLOT(Select()));
    this->button->show();
}

QPushButton* GfxObject::getButton()
{
    return this->button;
}

#include "IA/minmax.hpp"
#include <QMessageBox>
#include "GraphicalObject/MessageBox.h"

void GfxObject::Select()
{
    if(!this->hisBoard->getEndSignal())
    {
        if(this->getLegalMoves() == false)                                                                                                                              //Une piece qui n'est pas une piece LegalMoves
        {
            std::vector<std::pair<unsigned int,unsigned int>> thisLegalMoves;

            std::string str =  this->hisPiece->getName();
            QString qstr = QString::fromStdString(str);
            qDebug() << qstr;
            if(this->hisPiece->getName() != "Empty" && this->hisPiece->getColor() == 0)                                                                                 //Une piece !LegalMoves && !Empty && White
            {
                if(this->hisPiece->getName() == "King")
                {
                    thisLegalMoves = this->hisPiece->legalMoves(hisBoard->getChessboard(),this->hisBoard->getVEatOpponent(this->hisBoard->getPiecesB()));

                } else {
                    thisLegalMoves = this->hisPiece->legalMoves(hisBoard->getChessboard());
                }
                if(this->hisBoard->getSignal())   //UNE CASE DEJA CLIQUE                                                                                                                       //Si l'echiquier a deja une case de select
                {
                    if(this->Clicked == false)                                                                                                                          //Si cette case n'est pas deja cliqué
                    {
                        this->hisBoard->getBoardClear();
                        this->hisBoard->setCoordClicked(this->hisPiece->getCoord()); //met les coords de la piece en selection
                        this->hisBoard->setGraphicalLegalMoves(thisLegalMoves);
                        this->Clicked = true;
                        this->button->setStyleSheet(
                                    "background:red;"
                                    "border:1px solid black;"
                                    );
                    }
                    else                                                                                                                                                 //Si c'est déjà cliqué
                    {
                        this->hisBoard->getBoardClear();
                        this->hisBoard->setCoordClicked(pairCoord(9,9));
                        this->hisBoard->switchClickedSignal(); //deselect
                        this->Clicked = false; //fait la bascule de deselection
                        this->button->setStyleSheet(
                                    "background-color: rgba(241, 217, 181, 1);"
//                                    "background:white;"
                                    "border:1px solid black;"
                                    );
                    }
                    this->button->show(); //refresh l'ihm
                }
                else //AUCUNE CASE CLIQUE AVANT                                                                                                                                                    //cas ou y'a rien de select
                {
                    this->hisBoard->getBoardClear();
                    this->hisBoard->setCoordClicked(this->hisPiece->getCoord()); //met les coords de la piece en selection
                    this->hisBoard->setGraphicalLegalMoves(thisLegalMoves);
                    this->hisBoard->switchClickedSignal(); //passe a select
                    this->Clicked = true;
                    this->button->setStyleSheet(
                                "background:red;"
                                "border:1px solid black;"
                                );
                }
            }
        }
        else if(this->hisBoard->getCoordClicked() != pairCoord(9,9)) //clique d'une piece qui correspond aux legalMoves
        {
                std::string checkStatusOfTheGame = play(*this->hisBoard,true,hisBoard->getCoordClicked().first,hisBoard->getCoordClicked().second,this->hisPiece->getCoord().first,this->hisPiece->getCoord().second);
                if(checkStatusOfTheGame == "OK")
                {
                    play(*this->hisBoard,false,0,0,0,0);
                    pairCoord coordOfTheClickedPiece = this->hisPiece->getCoord(); //Recupere les coords de la case cliqué
                    qDebug() << endl;
                    qDebug() << "La piece qui va essayer de bouger :";
                    qDebug() << hisBoard->getCoordClicked();
                    qDebug() << "Vers cette case :";
                    qDebug() << coordOfTheClickedPiece;
                    qDebug() << endl;
                }
                else if(checkStatusOfTheGame.find("ERROR") == 0)
                {
                    this->hisBoard->getBoardClear();
                    MessageBox("Problème de déplacement",checkStatusOfTheGame.erase(0,5));
                }
                else if(checkStatusOfTheGame.find("ENDGAME") == 0)
                {
                    this->hisBoard->setEndSignal(true);
                    std::string colorOfthePlayer = "";
                    if(checkStatusOfTheGame.erase(0,7) == "white")
                    {
                        colorOfthePlayer = "blanc";
                    }
                    else
                    {
                        colorOfthePlayer = "noir";
                    }
                    std::string str = "Le joueur " + colorOfthePlayer + " à gagné";
                    MessageBox("Fin de partie",str);
                    this->hisMainWindow->addNewGameButton();
                }
                Matrix newBoardToLoad = this->hisBoard->getChessboard(); //DEBUG ONLY
                QDebug deb = qDebug().nospace();//DEBUG ONLY
                deb << " 0 1 2 3 4 5 6 7"<< endl;//DEBUG ONLY
                for (unsigned i(0); i < 8; ++i)//DEBUG ONLY
                {
                    for (unsigned j(0); j < 8; ++j)
                    {//DEBUG ONLY
                        if ( j == 0)
                            deb  << '|';
                        deb  << newBoardToLoad[i][j]->getCarac() << '|';//DEBUG ONLY
                        if ( j == 7)
                            deb << i;
                    }//DEBUG ONLY
                    deb << endl;
                    //fin bcl
                }
                this->hisBoard->display(this->where,this->hisMainWindow);
            }
        }
}
