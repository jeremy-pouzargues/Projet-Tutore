#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QStackedWidget>

#include <unistd.h>

#include <Chessboard/Chessboard.h>

#include "windowCommandsButton.h"

#include "Chrono.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent,Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(600,800));
    const QPixmap returnPixMap (":/Ressources/Window/arrowWhite.png");
    const QIcon returnQIcon(returnPixMap);

    const QPixmap bkgnd(":/Ressources/Window/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QIcon iconMainWindow (":/Ressources/Pieces/PawnBlack.png"); //useless avec la frame disparu
    this->setWindowIcon(iconMainWindow); //useless avec la frame disparu

    this->setWindowTitle("Jeu d'echecs");

    //===========================================//

    QWidget *chessMenuWindow = new QWidget();

    const QSize BUTTON_SIZE = QSize(140,60);

    QPushButton *btnPage1 = new QPushButton(chessMenuWindow);
    btnPage1->setText("Jouer");
    btnPage1->move(45,200);

    //    btnPage1->move(250,400);
    btnPage1->setMinimumSize(BUTTON_SIZE);
    btnPage1->setMaximumSize(BUTTON_SIZE);

    btnPage1->setStyleSheet(
                "border: 0px;"
                "font-size:32px;"
                "color:white;"
                );

    btnPage1->show();

    QPushButton *btn2Page1 = new QPushButton(chessMenuWindow);
    btn2Page1->setText("Aide");
    btn2Page1->move(230,200);

    btn2Page1->setMinimumSize(BUTTON_SIZE);
    btn2Page1->setMaximumSize(BUTTON_SIZE);
    btn2Page1->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(255, 255, 255, 0);"
                "font-size:32px;"
                "color:white;"
                );

    btn2Page1->show();

    QPushButton *btn3Page1 = new QPushButton(chessMenuWindow);
    btn3Page1->setText("Credit");
    btn3Page1->move(415,200);
    btn3Page1->setMinimumSize(BUTTON_SIZE);
    btn3Page1->setMaximumSize(BUTTON_SIZE);
    btn3Page1->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(255, 255, 255, 0);"
                "font-size:32px;"
                "color:white;"
                );
    btn3Page1->show();

    QLabel * mainText = new QLabel(chessMenuWindow);
    mainText->setText("Chess");
    mainText->setMinimumSize(200,100);
    mainText->setMaximumSize(200,100);
    mainText->move(20,30);
    mainText->setStyleSheet(
                "color:white;"
                "font-size:72px;"
                );

    this->chessMenu = chessMenuWindow;

    //===========================================//

    QWidget *chessGameWidget = new QWidget();

    QPushButton *returnBtn = new QPushButton(chessGameWidget);

    returnBtn->setIcon(returnQIcon);
    returnBtn->setIconSize(QSize(30,30));
    returnBtn->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(255, 255, 255, 0);"
                );
    returnBtn->show();

    this->chessGameWindow = chessGameWidget;

    ChessBoard * MainGame = new ChessBoard();

    this->hisChessBoard = MainGame;

    if(!this->chronoAlreadyStart)
    {
        Chrono * theChrono = new Chrono(chessGameWidget,MainGame); //ICI
        this->stopwatch = theChrono;
        connect(this, &MainWindow::sendSignalToChrono,theChrono, &Chrono::onSignalReceiveFromMainWindow);
    }

    MainGame->display(this->chessGameWindow,this);  ////////ICIIIIIIIIIIIIIIIIIIIIII
    //===========================================//

    QWidget *gameHelp = new QWidget();

    QPushButton *returnBtnHelp = new QPushButton(gameHelp);

    returnBtnHelp->setIcon(returnQIcon);
    returnBtnHelp->setIconSize(QSize(30,30));
    returnBtnHelp->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(255, 255, 255, 0);"
                );
    returnBtnHelp->show();

    this->gameHelp = gameHelp;

    //===========================================//

    QWidget *gameCredit = new QWidget();

    QPushButton *returnBtnCredit = new QPushButton(gameCredit);

    returnBtnCredit->setIcon(returnQIcon);
    returnBtnCredit->setIconSize(QSize(30,30));
    returnBtnCredit->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(255, 255, 255, 0);"
                );

    returnBtnCredit->show();

    creditProfile(50,100,gameCredit,"https://github.com/leo-dalloz","Leo Dalloz",":/Ressources/Users/leo.jpg");
    creditProfile(325,100,gameCredit,"https://github.com/jeremy-pouzargues","Jeremy Pouzargues",":/Ressources/Users/jerem.jpg");
    creditProfile(325,400,gameCredit,"https://github.com/laurent-vouriot","Laurent Vouriot",":/Ressources/Users/2lo.jpg");
    creditProfile(50,400,gameCredit,"https://github.com/FrancoisAlHaddad","François Al Haddad",":/Ressources/Users/fran.png");

    this->gameCredit = gameCredit;

    //===========================================//

    new windowCommandsButton(chessMenuWindow,this);
    new windowCommandsButton(chessGameWidget,this);
    new windowCommandsButton(gameHelp,this);
    new windowCommandsButton(gameCredit,this);

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(chessMenuWindow);
    stackedWidget->addWidget(chessGameWidget);
    stackedWidget->addWidget(gameHelp);
    stackedWidget->addWidget(gameCredit);

    this->widgetStacked = stackedWidget;

    stackedWidget->setCurrentIndex(0);

    connect(btnPage1,SIGNAL(clicked()),this,SLOT(GamePage()));
    connect(btn2Page1,SIGNAL(clicked()),this,SLOT(HelpPage()));
    connect(btn3Page1,SIGNAL(clicked()),this,SLOT(CreditPage()));

    connect(returnBtn,SIGNAL(clicked()),this,SLOT(BackMenu()));
    connect(returnBtnCredit,SIGNAL(clicked()),this,SLOT(BackMenu()));
    connect(returnBtnHelp,SIGNAL(clicked()),this,SLOT(BackMenu()));

    this->setCentralWidget(this->widgetStacked);
}


#include <thread>
//#include <process>

void MainWindow::GamePage()
{
    this->widgetStacked->setCurrentIndex(1);
    if(chronoAlreadyStart == false)
    {
        this->chronoAlreadyStart = true;
        this->stopwatch->startInNewThread();
    }
}

void MainWindow::HelpPage()
{
    this->widgetStacked->setCurrentIndex(2);
}

void MainWindow::CreditPage()
{
    this->widgetStacked->setCurrentIndex(3);
}

#include <QDebug>

void MainWindow::endWindow()
{
    this->close();
}

void MainWindow::BackMenu()
{
    this->widgetStacked->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

#include "GraphicalObject/gameMessageBox.h"

void MainWindow::closeEvent (QCloseEvent *event)
{
    if(widgetStacked->currentIndex() == 1) //Si on est dans le widget de jeu
    {
        QMessageBox messageBox(QMessageBox::Question,
                    tr("Attention"),
                    tr("Voulez-vous quitter ?"),
                    QMessageBox::Yes | QMessageBox::No,
                    this);
            messageBox.setButtonText(QMessageBox::Yes, tr("Oui"));
            messageBox.setButtonText(QMessageBox::No, tr("Non"));
            messageBox.setWindowFlag(Qt::FramelessWindowHint);
        messageBox.exec();
        if(messageBox.No == true)
        {
            event->ignore();
        }
    }
}

void MainWindow::addNewGameButton()
{
    QPushButton * newGame = new QPushButton(this);
    newGame->setText("Nouvelle partie");
    newGame->move(200,600);
    newGame->setStyleSheet(
                "border: 0px;"
                "background-color: rgba(162, 82, 45, 1);"
                "color:white;"
                "font-size:24px;"
                           );
    newGame->setMinimumSize(QSize(200,50));
    newGame->setMaximumSize(QSize(200,50));

    newGame->show();
    this->newGameBtn = newGame;
    connect(this->newGameBtn,SIGNAL(clicked()),this,SLOT(NewGame()));
}

void MainWindow::NewGame()
{
    ChessBoard * nnew = new ChessBoard;
    nnew->display(this->widgetStacked->currentWidget(),this);
    hisChessBoard = nnew;

    this->stopwatch->setHisBoard(nnew);

    this->newGameBtn->hide();
    delete this->newGameBtn;

    emit sendSignalToChrono();
    qDebug("signal emit");

}

