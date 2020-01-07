#include <iostream>
#include <vector>
#include <limits>
#include "Pieces/Piece.h"
#include "Chessboard/Chessboard.h"
#include "Utils/CExc.h"
#include "GraphicalObject/mainwindow.h" //FRANFRAN
#include <QApplication> //FRANFRAN

using namespace std;

#include "GraphicalObject/ChoosePieceInterface.h"

int main(int argc, char *argv[])
{
    QApplication TheApplication(argc, argv);
    MainWindow TheGame;
    TheGame.setFixedSize(600,800);
    TheGame.show();
    return TheApplication.exec();
}
