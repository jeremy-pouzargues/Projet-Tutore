#include "ChoosePieceInterface.h"

ChoosePieceInterface::ChoosePieceInterface(ChessBoard * hisChessBoard, const pairCoord coordMoveDD, const pairCoord coordPieceDD/*,GfxObject * GraphicalObject*/) :
    coordMove(coordMoveDD),
    coordPiece(coordPieceDD),
    hisBoard(hisChessBoard)
{
    this->init();

    this->setWindowTitle("Chess");
    this->setText("Choisir une pièce");

    QPushButton *Knight = new QPushButton();
    QPushButton *Queen = new QPushButton();
    QPushButton *Rook = new QPushButton();
    QPushButton *Bishop = new QPushButton();

    QPixmap hisPic (":/Ressources/Pieces/KnightWhite.png");
    QIcon ButtonIcon(hisPic);
    Knight->setIcon(ButtonIcon);
    Knight->setIconSize(QSize(60,60));

    QPixmap hisPic2 (":/Ressources/Pieces/QueenWhite.png");
    QIcon ButtonIcon2(hisPic2);
    Queen->setIcon(ButtonIcon2);
    Queen->setIconSize(QSize(60,60));

    QPixmap hisPic3 (":/Ressources/Pieces/RookWhite.png");
    QIcon ButtonIcon3(hisPic3);
    Rook->setIcon(ButtonIcon3);
    Rook->setIconSize(QSize(60,60));

    QPixmap hisPic4 (":/Ressources/Pieces/BishopWhite.png");
    QIcon ButtonIcon4(hisPic4);
    Bishop->setIcon(ButtonIcon4);
    Bishop->setIconSize(QSize(60,60));

    this->addButton(Knight,QMessageBox::YesRole);
    this->addButton(Queen,QMessageBox::YesRole);
    this->addButton(Rook,QMessageBox::YesRole);
    this->addButton(Bishop,QMessageBox::YesRole);

    this->exec();

    if(this->clickedButton() == Knight)
    {
           hisBoard->setChoosedPiece("Knight");
           qDebug() << "Knight";
    }
    else if(this->clickedButton() == Queen)
    {
           hisBoard->setChoosedPiece("Queen");
           qDebug() << "Queen";
    }
    else if(this->clickedButton() == Rook)
    {
           hisBoard->setChoosedPiece("Rook");
           qDebug() << "Rook";
    }
    else if(this->clickedButton() == Bishop)
    {
           hisBoard->setChoosedPiece("Bishop");
           qDebug() << "Bishop";
    }

}

ChoosePieceInterface::~ChoosePieceInterface()
{
    delete this;
}
