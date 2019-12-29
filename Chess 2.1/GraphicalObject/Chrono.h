#ifndef CHRONO_H
#define CHRONO_H

#include <QLabel>
#include <QWidget>

#include <QThread>

#include <unistd.h>

#include <Chessboard/Chessboard.h>

//class initThread;

//#include "Thread/initThread.h"

class Chrono : public QWidget
{
    Q_OBJECT
public:
    Chrono(QWidget * where,ChessBoard * hisBoard/*,/*MainWindow * hisMainWindow*/);
    QLabel *getStopwatch() const;
    void setStopwatch(QLabel *value);
    void startInNewThread();
    bool getStatus() const;
    void setStatus(bool value);
    void reset();
//    initThread *getHisThread() const;
//    void setHisThread(initThread *value);

    bool getInterpretationSignal() const;
    void setInterpretationSignal(bool value);

    void setHisBoard(ChessBoard *value);

    ChessBoard *getHisBoard() const;

public slots:
    void onSignalReceive(QString timeToSend);
    void onSignalReceiveFromMainWindow();
signals:
//    void sendSignalToThread();
private:
    bool InterpretationSignal;

    ChessBoard * hisBoard;
    bool status;
    int seconds;
    int minute;
    QLabel * stopwatch;
//    QThread * hisThread;
//    MainWindow * hisMainWindow;
};

#endif // CHRONO_H
