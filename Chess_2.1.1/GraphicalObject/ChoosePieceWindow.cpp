#include "ChoosePieceWindow.h"
#include "ui_ChoosePieceWindow.h"

#include <QPushButton>
#include <QLabel>

#include <QPixmap>

using namespace std;

ChoosePieceWindow::ChoosePieceWindow(QWidget *parent, ChessBoard * hisChessBoard, const pairCoord coordMoveDD, const pairCoord coordPieceDD) :
    QMainWindow(parent,Qt::FramelessWindowHint),
    coordMove(coordMoveDD),
    coordPiece(coordPieceDD),
    hisBoard(hisChessBoard),
    ui(new Ui::ChoosePieceWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(
                "background-color:brown;"
                "color:white;"
                "font-size:16px;"
                );
    QLabel * text = new QLabel(this);

    QPushButton * firstChoice = new QPushButton(this);
    QPushButton * secondChoice = new QPushButton(this);
    QPushButton * thirdChoice = new QPushButton(this);
    QPushButton * fourthChoice = new QPushButton(this);

    text->setText("Choisissez une piece");
    text->setAlignment(Qt::AlignCenter);

    text->move(0,0);
    text->setMinimumSize(200,50);
    text->setMaximumSize(200,50);

    QSize * sizeBtnChoosed = new QSize(70,70);

    firstChoice->move(20,50);
    firstChoice->setMinimumSize(*sizeBtnChoosed);
    firstChoice->setMaximumSize(*sizeBtnChoosed);
    QPixmap hisPic (":/Ressources/Pieces/RookWhite.png");
    QIcon ButtonIcon(hisPic);
    firstChoice->setIcon(ButtonIcon);
    firstChoice->setIconSize(QSize(60,60));
    connect(firstChoice,SIGNAL(clicked()),this,SLOT(emitRook()));

    secondChoice->move(110,50);
    secondChoice->setMinimumSize(*sizeBtnChoosed);
    secondChoice->setMaximumSize(*sizeBtnChoosed);
    QPixmap hisPic2 (":/Ressources/Pieces/KnightWhite.png");
    QIcon ButtonIcon2(hisPic2);
    secondChoice->setIcon(ButtonIcon2);
    secondChoice->setIconSize(QSize(60,60));
    connect(secondChoice,SIGNAL(clicked()),this,SLOT(emitKnight()));

    thirdChoice->move(20,140);
    thirdChoice->setMinimumSize(*sizeBtnChoosed);
    thirdChoice->setMaximumSize(*sizeBtnChoosed);
    QPixmap hisPic3(":/Ressources/Pieces/BishopWhite.png");
    QIcon ButtonIcon3(hisPic3);
    thirdChoice->setIcon(ButtonIcon3);
    thirdChoice->setIconSize(QSize(60,60));
    connect(thirdChoice,SIGNAL(clicked()),this,SLOT(emitBishop()));

    fourthChoice->move(110,140);
    fourthChoice->setMinimumSize(*sizeBtnChoosed);
    fourthChoice->setMaximumSize(*sizeBtnChoosed);
    QPixmap hisPic4(":/Ressources/Pieces/QueenWhite.png");
    QIcon ButtonIcon4(hisPic4);
    fourthChoice->setIcon(ButtonIcon4);
    fourthChoice->setIconSize(QSize(60,60));
    connect(fourthChoice,SIGNAL(clicked()),this,SLOT(emitQueen()));

    this->show();
}

ChoosePieceWindow::~ChoosePieceWindow()
{
    delete ui;
}

void ChoosePieceWindow::emitKnight()
{

    hisBoard->setChoosedPiece("Knight");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);

    hisBoard->setSwitchMove(false);

    Matrix newBoardToLoad = this->hisBoard->getChessboard();
    QDebug deb = qDebug().nospace();
    deb << " 0 1 2 3 4 5 6 7"<< endl;
    for (unsigned i(0); i < 8; ++i)
    {
        for (unsigned j(0); j < 8; ++j)
        {
            if ( j == 0)
                deb  << '|';
            deb  << newBoardToLoad[i][j]->getCarac() << '|';
            if ( j == 7)
                deb << i;
        }
        deb << endl;
    }

    this->close();
}

void ChoosePieceWindow::emitBishop()
{
    hisBoard->setChoosedPiece("Bishop");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();
}

void ChoosePieceWindow::emitQueen()
{
    hisBoard->setChoosedPiece("Queen");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();
}

void ChoosePieceWindow::emitRook()
{
    hisBoard->setChoosedPiece("Rook");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();
}
