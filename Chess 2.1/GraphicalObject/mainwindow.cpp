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
    //    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    const QPixmap returnPixMap (":/Ressources/Window/arrowWhite.png");
    const QIcon returnQIcon(returnPixMap);

    const QPixmap bkgnd(":/Ressources/Window/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //    this->setStyleSheet("{background-image: url(:/QtRessources/Pieces/background.png;}");

    QIcon iconMainWindow (":/Ressources/Pieces/PawnBlack.png"); //useless avec la frame disparu
    this->setWindowIcon(iconMainWindow); //useless avec la frame disparu

    this->setWindowTitle("Jeu d'echecs");


    //    QPushButton *btnClose = new QPushButton(this);
    //    btnClose->setText("X");
    //    btnClose->move(570,0);
    //    btnClose->setMaximumSize(BUTTONMENU_SIZE);


    //    btnClose->setStyleSheet(
    //                "border:none;"
    //                "background:none;"
    //                "color:white;"
    //                "font-size:24px;"
    //                );

    //    connect(btnClose,SIGNAL(clicked()),this,SLOT(endWindow()));
    //    btnClose->show();

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
                //                "background-color: rgba(255, 255, 255, 0);"
                "font-size:32px;"
                "color:white;"
                );

    btnPage1->show();

    QPushButton *btn2Page1 = new QPushButton(chessMenuWindow);
    btn2Page1->setText("Aide");
    btn2Page1->move(230,200);

    //    btn2Page1->move(250,500);
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
    //    btn3Page1->move(250,600);
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

    //    const QSize BUTTONMENU_SIZE = QSize(30,30);
    //    QPushButton *btnClose = new QPushButton(chessMenuWindow);
    //    btnClose->setText("X");
    //    btnClose->move(570,0);
    //    btnClose->setMaximumSize(BUTTONMENU_SIZE);
    //    btnClose->setStyleSheet(
    //                "border:none;"
    //                "background:none;"
    //                "color:white;"
    //                "font-size:24px;"
    //                );
    //    connect(btnClose,SIGNAL(clicked()),this,SLOT(endWindow()));
    //    btnClose->show();

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
    //    returnBtn->setText("Retour");
    returnBtn->show();



    //    QThread * coreTwo = new QThread();
    //    Chrono * toAdd = new Chrono(chessGameWidget);
    //    connect(coreTwo, SIGNAL(started()), toAdd, SLOT(start()));
    //    toAdd->moveToThread(coreTwo);
    //    coreTwo->start();


    this->chessGameWindow = chessGameWidget;

    ChessBoard * MainGame = new ChessBoard();

    this->hisChessBoard = MainGame;

    if(!this->chronoAlreadyStart)
    {
        Chrono * theChrono = new Chrono(chessGameWidget,MainGame); //ICI
        this->stopwatch = theChrono;
        connect(this, &MainWindow::sendSignalToChrono,theChrono, &Chrono::onSignalReceiveFromMainWindow);
//        connect(this,sendSignalToChrono(),theChrono,SLOT(onSignalReceiveFromMainWindow()));
    }

//    QPushButton * test = new QPushButton(chessGameWidget);
//    test->setText("Nouvelle partie");
//    test->move(200,600);
//    test->setMinimumWidth(100);
//    test->setMaximumWidth(100);
//    test->setMinimumHeight(50);
//    test->setMaximumHeight(50);

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
    //    returnBtnHelp->setText("Retour");
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
    //    std::thread x (start());
    //    _beginthread(this->stopwatch->start());
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
//        gameMessageBox test("Voulez-vous vraiment quitter ?");
//        if(test.getChoice())
//        {
//            event->accept();
//        }
//        else
//        {
//            event->ignore();
//        }


        QMessageBox messageBox(QMessageBox::Question,
                    tr("Attention"),
                    tr("Voulez-vous quitter ?"),
                    QMessageBox::Yes | QMessageBox::No,
                    this);
            messageBox.setButtonText(QMessageBox::Yes, tr("Oui"));
//            messageBox->
            messageBox.setButtonText(QMessageBox::No, tr("Non"));
            messageBox.setWindowFlag(Qt::FramelessWindowHint);
        messageBox.exec();
        if(messageBox.No == true)
        {
            event->ignore();
        }

//        QMessageBox box = QMessageBox();
////        box.setIcon(QtGui.QMessageBox.Question)
//        box.setWindowTitle("test");
//        box.setText("Voulez-vous quitter ?");
//        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
//        QPushbuttonY = box.button(QtGui.QMessageBox.Yes)
//        buttonY.setText('Evet')
//        buttonN = box.button(QtGui.QMessageBox.No)
//        buttonN.setText('Iptal')
//        box.exec_()

//        if box.clickedButton() == buttonY:
//            # YES pressed
//        elif box.clickedButton() == buttonN:
//            # NO pressed
//        QMessageBox::StandardButton resBtn =
//                QMessageBox::question( this, "APP_NAME",tr("You sure?\n"),
//                                       QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
//                                       QMessageBox::Yes);


        //        if (resBtn != QMessageBox::Yes)
//        {
//            event->ignore();
//        }
//        else
//        {
//            event->accept();
//        }
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

//    this->stopwatch->set

//    this->newGameBtn = nullptr;

//    connect(this,sendSignalToChrono(),this->stopwatch->getHisThread(),this->stopwatch->getHisThread()->onSignalReceiveFromMainWindow());

//    connect(this,sendSignalToChrono(),this->stopwatch->getHisThread(),onSignalReceiveFromMainWindow());

//    Chrono * chrn = new Chrono(this->widgetStacked->currentWidget(),this->hisChessBoard);
//    chrn->startInNewThread();

//    delete this->stopwatch;

    emit sendSignalToChrono();
    qDebug("signal emit");

    //    this->stopwatch = chrn;
//    this->stopwatch->move(0,0);
//    this->stopwatch->startInNewThread();
//    this->stopwatch->show();

//    this->stopwatch->startInNewThread();
}

