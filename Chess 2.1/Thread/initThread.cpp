#include "initThread.h"

initThread::initThread(ChessBoard * hisBoard,Chrono * hisChrono) : hisBoard(hisBoard),hisChrono(hisChrono)/*QObject *parent) : QThread(parent)*/ {}

void initThread::run()
{
    unsigned int seconds = 00;
    unsigned int minutes = 00;
    //        std::mutex mtx;
    //            mtx.lock();
    while(true)
    {
//        qDebug() << this->hisBoard->getEndSignal();
//        qDebug() << &this->hisBoard;
        this->hisBoard = hisChrono->getHisBoard();
        usleep(100);
        while(!this->hisBoard->getEndSignal())
        {
            if(hisChrono->getInterpretationSignal())
            {
                seconds = 00;
                minutes = 00;
                this->hisChrono->setInterpretationSignal(false);
    //            this->hisBoard->setEndSignal(false);
            }
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
}

//void initThread::onSignalReceiveFromMainWindow()
//{
//    this->InterpretationSignal = true;
//}

