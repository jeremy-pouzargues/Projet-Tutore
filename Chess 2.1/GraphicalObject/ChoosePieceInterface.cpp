#include "ChoosePieceInterface.h"

ChoosePieceInterface::ChoosePieceInterface(ChessBoard * hisChessBoard, const pairCoord coordMoveDD, const pairCoord coordPieceDD/*,GfxObject * GraphicalObject*/) :
    coordMove(coordMoveDD),
    coordPiece(coordPieceDD),
    hisBoard(hisChessBoard)
  //    currentGraphicalObject(GraphicalObject)
{
    this->setWindowTitle("title");
    this->setText("Question");
    this->setStandardButtons(QMessageBox::Yes);
    this->addButton(QMessageBox::No);
    this->setDefaultButton(QMessageBox::No);
    if(this->exec() == QMessageBox::Yes){
           hisBoard->setChoosedPiece("Knight");
    }else {
           hisBoard->setChoosedPiece("Queen");
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

void ChoosePieceInterface::emitKnight()
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

void ChoosePieceInterface::emitBishop()
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

void ChoosePieceInterface::emitQueen()
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

void ChoosePieceInterface::emitRook()
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
