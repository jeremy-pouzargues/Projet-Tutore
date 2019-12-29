#ifndef INITTHREAD_H
#define INITTHREAD_H

#include <QThread>

#include <Chessboard/Chessboard.h>

class initThread : public QThread
{
    Q_OBJECT
public:
    initThread(ChessBoard * hisBoard/*QObject * parent*/);
    void run();
//    void stop();
private:
    ChessBoard * hisBoard;
signals:
    void sendSignal(QString timeToSend);
};

#endif // INITTHREAD_H
