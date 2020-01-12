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
















//    this->setStyleSheet("QLabel{min-width:200 px; min-height:300px font-size: 24px;}");
//    this->setText("et merce");
//    qDebug() << hisBoard->getChoosedPiece();
//    hisBoard->setChoosedPiece("Queen");
//    qDebug() << hisBoard->getChoosedPiece();
//    this->exec();

//    this->setStandardButtons(QMessageBox::Ok | QMessageBox::Yes | QMessageBox::No | QMessageBox::Save);
//    this->exec();

//    int ret = this->exec();
//    switch (ret) {
//    case QMessageBox::Ok:
//        emitRook();
//        break;
//    case QMessageBox::Yes:
//        emitQueen();
//        break;
//    case QMessageBox::No:
//        emitBishop();
//        break;
//    case QMessageBox::Save:
//        emitKnight();
//        break;
//    default:
//        qDebug() << "no reach";
//        break;
//    }

    //    this->setMinimumSize(200,200);
    //    this->setMaximumSize(200,200);
//    this->setStyleSheet(
//                "background-color:brown;"
//                "color:white;"
//                "font-size:16px;"
//                );
    //    QLabel * text = new QLabel(this);

    //    QPushButton * firstChoice = new QPushButton(this);
    //    QPushButton * secondChoice = new QPushButton(this);
    //    QPushButton * thirdChoice = new QPushButton(this);
    //    QPushButton * fourthChoice = new QPushButton(this);

    //    text->setText("Choisissez une piece");
    //    text->setAlignment(Qt::AlignCenter);

    //    text->move(0,0);
    //    text->setMinimumSize(200,50);
    //    text->setMaximumSize(200,50);

    //    QSize * sizeBtnChoosed = new QSize(70,70);

    //    firstChoice->move(20,50);
    //    firstChoice->setMinimumSize(*sizeBtnChoosed);
    //    firstChoice->setMaximumSize(*sizeBtnChoosed);
    //    QPixmap hisPic (":/Ressources/Pieces/RookWhite.png");
    //    QIcon ButtonIcon(hisPic);
    //    firstChoice->setIcon(ButtonIcon);
    //    firstChoice->setIconSize(QSize(60,60));
    //    connect(firstChoice,SIGNAL(clicked()),this,SLOT(emitRook()));

    //    secondChoice->move(110,50);
    //    secondChoice->setMinimumSize(*sizeBtnChoosed);
    //    secondChoice->setMaximumSize(*sizeBtnChoosed);
    //    QPixmap hisPic2 (":/Ressources/Pieces/KnightWhite.png");
    //    QIcon ButtonIcon2(hisPic2);
    //    secondChoice->setIcon(ButtonIcon2);
    //    secondChoice->setIconSize(QSize(60,60));
    //    connect(secondChoice,SIGNAL(clicked()),this,SLOT(emitKnight()));

    //    thirdChoice->move(20,140);
    //    thirdChoice->setMinimumSize(*sizeBtnChoosed);
    //    thirdChoice->setMaximumSize(*sizeBtnChoosed);
    //    QPixmap hisPic3(":/Ressources/Pieces/BishopWhite.png");
    //    QIcon ButtonIcon3(hisPic3);
    //    thirdChoice->setIcon(ButtonIcon3);
    //    thirdChoice->setIconSize(QSize(60,60));
    //    connect(thirdChoice,SIGNAL(clicked()),this,SLOT(emitBishop()));

    //    fourthChoice->move(110,140);
    //    fourthChoice->setMinimumSize(*sizeBtnChoosed);
    //    fourthChoice->setMaximumSize(*sizeBtnChoosed);
    //    QPixmap hisPic4(":/Ressources/Pieces/QueenWhite.png");
    //    QIcon ButtonIcon4(hisPic4);
    //    fourthChoice->setIcon(ButtonIcon4);
    //    fourthChoice->setIconSize(QSize(60,60));
    //    connect(fourthChoice,SIGNAL(clicked()),this,SLOT(emitQueen()));

}

ChoosePieceInterface::~ChoosePieceInterface()
{
    delete this;
}
