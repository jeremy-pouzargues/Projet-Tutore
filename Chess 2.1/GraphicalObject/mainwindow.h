#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QLayout>
#include "Chrono.h"
#include "creditProfile.h"

#include <QMouseEvent>

#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void GamePage();
    void HelpPage();
    void CreditPage();
    void endWindow();
    void BackMenu();
private:
    Ui::MainWindow *ui;
    QWidget *chessMenu;
    QWidget *chessGameWindow;
    QWidget *gameHelp;
    QWidget *gameCredit;
    QStackedWidget *widgetStacked;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    bool chronoAlreadyStart;

    Chrono * stopwatch;

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
