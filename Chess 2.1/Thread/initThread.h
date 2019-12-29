#ifndef INITTHREAD_H
#define INITTHREAD_H

#include <QThread>

#include <Chessboard/Chessboard.h>

class Chrono;

class initThread : public QThread
{
    Q_OBJECT
public:
    initThread(ChessBoard * hisBoard,Chrono * hisChrono/*QObject * parent*/);
    void run();
//    void stop();
private:
    ChessBoard * hisBoard;
    Chrono * hisChrono;
public slots:
signals:
//    void onSignalReceiveFromMainWindow();
    void sendSignal(QString timeToSend);
};

#endif // INITTHREAD_H
