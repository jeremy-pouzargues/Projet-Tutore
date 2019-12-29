#include "ChoosePieceWindow.h"
#include "ui_ChoosePieceWindow.h"

#include <QPushButton>
#include <QLabel>

#include <QPixmap>

using namespace std;

ChoosePieceWindow::ChoosePieceWindow(QWidget *parent, ChessBoard * hisChessBoard, const pairCoord coordMoveDD, const pairCoord coordPieceDD,GfxObject * GraphicalObject) :
    QMainWindow(parent,Qt::FramelessWindowHint),
    coordMove(coordMoveDD),
    coordPiece(coordPieceDD),
    hisBoard(hisChessBoard),
    ui(new Ui::ChoosePieceWindow),
    currentGraphicalObject(GraphicalObject)
{
//    this->setCoordMove(*coordMoveDD);
//    this->setCoordPiece(*coordPieceDD);
//    this->coordMove = coordMoveDD;

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

//    QString * pieceOne = new QString("Rook");
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


//    Color color;
//    this->hisBoard->getChessboard()[coordMove.first][coordMove.second]->getColor() == white ? color = white : color = black;
//    //        string pieceChosen;




//    //        qDebug() << this->getChoosedPiece();

//    Matrix myChessBoard = this->hisBoard->getChessboard();

//    const VPieces myPiecesW = this->hisBoard->getPiecesW();

////        while(true)
////        {
//                QString ChoiceOfUser = this->hisBoard->getChoosedPiece();
//                if("Queen" == ChoiceOfUser)
//                {
//                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Queen(color,pairCoord(coordMove.first,coordMove.second)));
//                }
//                else if("Rook" == ChoiceOfUser)
//                {
//                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Rook(color,pairCoord(coordMove.first,coordMove.second)));
//                }
//                else if("Knight" == ChoiceOfUser)
//                {
//                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Knight(color,pairCoord(coordMove.first,coordMove.second)));
//                }
//                else if("Bishop" == ChoiceOfUser)
//                {
//                    myChessBoard[coordMove.first][coordMove.second] = shared_ptr<Piece>(new Bishop(color,pairCoord(coordMove.first,coordMove.second)));
//                }

//    unsigned cpt = 0;
//    if(color == white)
//    {
//        while(coordMove != myPiecesW[cpt]->getCoord()) {++cpt;}
//        myPiecesW[cpt] = myChessBoard[coordMove.first][coordMove.second];
//    }
//    else
//    {
//        while(coordMove != myPiecesB[cpt]->getCoord()) {++cpt;}
//        myPiecesB[cpt] = myChessBoard[coordMove.first][coordMove.second];
//    }



}

ChoosePieceWindow::~ChoosePieceWindow()
{
    delete ui;
}

void ChoosePieceWindow::emitKnight()
{
//    qDebug() << "Knight";

    hisBoard->setChoosedPiece("Knight");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);

    hisBoard->setSwitchMove(false);

//    this->hisBoard->move(coordPiece,coordPiece);

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

    this->close();

//    hisBoard->setChoosedPiece("Knight");

//    hisBoard->setSwitchMove(true);
//    qDebug() << this->coordMove;
//    qDebug() << this->coordPiece;
//    hisBoard->setSwitchMove(false);

//    qDebug() << hisBoard->getChoosedPiece();

//    this->hide();

//        this->close();

//    exit(1);
}

void ChoosePieceWindow::emitBishop()
{
//    qDebug() << "Bishop";
//    hisBoard->setChoosedPiece("Bishop");
//    qDebug() << hisBoard->getChoosedPiece();

    hisBoard->setChoosedPiece("Bishop");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();


//    hisBoard->setSwitchMove(true);
//    qDebug() << this->coordMove;
//    qDebug() << this->coordPiece;
//    hisBoard->move(this->coordMove,this->coordPiece);
//    hisBoard->setSwitchMove(false);


//    this->close();
    //    this->close();

//    exit(1);
}

void ChoosePieceWindow::emitQueen()
{
//    qDebug() << "Queen";
    hisBoard->setChoosedPiece("Queen");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();

    //    hisBoard->move(this->coordMove,this->coordPiece);
//    qDebug() << hisBoard->getChoosedPiece();
}

void ChoosePieceWindow::emitRook()
{
//    qDebug() << "Rook";
//    hisBoard->setChoosedPiece("Rook");
//    qDebug() << hisBoard->getChoosedPiece();

//    this->close();
    hisBoard->setChoosedPiece("Rook");
    hisBoard->setSwitchMove(true);
    qDebug() << this->coordMove;
    qDebug() << this->coordPiece;
    hisBoard->move(this->coordMove,this->coordPiece);
    hisBoard->setSwitchMove(false);

    hisBoard->getBoardClear();

    this->close();

}

//const pairCoord *ChoosePieceWindow::getCoordPiece() const
//{
//    return coordPiece;
//}

//void ChoosePieceWindow::setCoordPiece(const pairCoord *value)
//{
//    coordPiece = value;
//}

//const pairCoord *ChoosePieceWindow::getCoordMove() const
//{
//    return coordMove;
//}

//void ChoosePieceWindow::setCoordMove(const pairCoord *value)
//{
//    coordMove = value;
//}

//void ChoosePieceWindow::emitPiece(QString *pieceSelected)
//{
//    qDebug() << pieceSelected;

////    hisBoard->setChoosedPiece(pieceSelected);
////    this->close();
//}
