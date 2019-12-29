#ifndef GFXOBJECT_H
#define GFXOBJECT_H

#include <QPushButton>
#include <QDebug>

#include <vector>
//class Piece;
//class ChessBoard;


//#include "Const.h"



typedef std::pair<unsigned,unsigned> pairCoord;

//using namespace std;

#include <vector>

#include "Chessboard/Chessboard.h"
//#include "Pieces/Piece.h"

class ChessBoard; //A RM SI CICLIQUE AH1

#include "GraphicalObject/mainwindow.h" //A RMMMMMMMMMMMMMMMMM
class Chrono;
class MainWindow;

class GfxObject : public QObject
{
private:
    Q_OBJECT
    QPushButton*                button;
    bool                        Clicked;
    std::shared_ptr<Piece>      hisPiece;
    ChessBoard*                 hisBoard;
    bool                        legalMoves;

    QWidget *                   where;
    //    QPixmap*                    hisPicture;
    MainWindow *                hisMainWindow; //ICIIIIIIIIIIIIIIIIIIIIIII

public:
    GfxObject(QWidget*where,int x,int y,std::shared_ptr<Piece> SaPiece,QString name,ChessBoard * sonBoard,MainWindow * hisMainWindow);
    QPushButton *getButton();

    bool getClicked() const;
    void setClicked(bool value);

    std::shared_ptr<Piece> getHisPiece() const;

    bool getLegalMoves() const;
    void setLegalMoves(bool value);

    void setHisPiece(const std::shared_ptr<Piece> &value);

    void refreshGraphical();

private slots:
    void Select();
};

#endif // GFXOBJECT_H
