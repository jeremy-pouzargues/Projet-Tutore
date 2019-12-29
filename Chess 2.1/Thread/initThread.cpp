#include "initThread.h"

initThread::initThread(ChessBoard * hisBoard) : hisBoard(hisBoard) /*QObject *parent) : QThread(parent)*/ {}

void initThread::run()
{
    unsigned int seconds = 00;
    unsigned int minutes = 00;
    //        std::mutex mtx;
            //            mtx.lock();

    while(!this->hisBoard->getEndSignal())
    {
        sleep(1);
        seconds += 1;
        if(seconds == 60)
        {
            minutes += 1;
            seconds -= 60;
        }
        if(minutes == 99)
        {
            minutes = 0;
            seconds = 0;
        }

        QString s;
        QString m;

        if(seconds < 10)
        {
            s = "0" + QString::number(seconds);
        }
        else
        {
            s = QString::number(seconds);
        }

        if(minutes < 10)
        {
            m = "0" + QString::number(minutes);
        }
        else
        {
            m = QString::number(minutes);
        }

        QString timeToSend = m + ":" + s;
        emit sendSignal(timeToSend);
    }
}

