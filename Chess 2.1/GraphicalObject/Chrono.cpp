#include "Chrono.h"

#include <thread>
#include <mutex>

#include <mutex>          // std::mutex

#include "Thread/initThread.h"

Chrono::Chrono(QWidget * where,ChessBoard * hisBoard) : status(true),hisBoard(hisBoard) /*: QThread(where)*/
{
    std::mutex mtx;
    //    mtx.lock();

    //    connect(this, SIGNAL(workFinished()), coreTwo, SLOT(quit()));

    // automatically delete thread and task object when work is done:
    //    connect(this, SIGNAL(workFinished()), this, SLOT(deleteLater()));
    //    connect(coreTwo, SIGNAL(finished()), coreTwo, SLOT(deleteLater()));

    ///////////////    initThread * coreTwo = new initThread();
//     ///////////////       connect(coreTwo, SIGNAL(iteratorChrn(int cpt)),SLOT(start(int cpt)));
//      ///////////////      coreTwo->start();

//    connect(coreTwo, SIGNAL((int cpt)), toAdd, SLOT((int cpt)));
//    toAdd->moveToThread(coreTwo);
//    Chrono * toAdd = new Chrono(where);
//    this->stopwatch = toAdd;


    QLabel *Chrono = new QLabel(where);
    this->stopwatch = Chrono;
    this->stopwatch->setText("00:00");
    this->stopwatch->move(400,65);
    this->stopwatch->setStyleSheet(
                "color:white;"
                "font-size:36px;"
                );

    //    while(true)
    //    {
    //        int cpt = 0;
    //        sleep(1);
    //        QString s = QString::number(cpt);
    //        this->stopwatch->setText(s);
    //        this->stopwatch->show();
    //    }


    //    coreTwo->start();


    //    mtx.unlock();

    //    std::chrono::time_point<std::chrono::system_clock> start, end;


    //    start = std::chrono::system_clock::now();
    //    std::cout << "f(42) = " << fibonacci(42) << '\n';
    //    end = std::chrono::system_clock::now();

    //    std::chrono::duration<double> elapsed_seconds = end - start;
    //    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    //    std::cout << "finished computation at " << std::ctime(&end_time)
    //              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    //    while(true)
    //    {
    //        int cpt = 0;
    //        sleep(1);
    //        QString s = QString::number(cpt);
    //        Chrono->setText(s);
    //        Chrono->show();
    //    }
}

#include <QtDebug>
#include <mutex>          // std::mutex
#include <iostream>

void Chrono::onSignalReceive(QString timeToSend) {
    if(this->status)
    {
        this->stopwatch->setText(timeToSend);
    }
}

bool Chrono::getStatus() const
{
    return status;
}

void Chrono::setStatus(bool value)
{
    status = value;
}

void Chrono::startInNewThread() {
    initThread *anotherCore = new initThread(this->hisBoard);
    connect(anotherCore, &initThread::sendSignal,this, &Chrono::onSignalReceive);
//    connect(anotherCore, SIGNAL(progressChanged(int)),
//                          SLOT(onProgressChanged(int)));
//    connect(workerThread, SIGNAL(ended()),
//            workerThread, SLOT(rmPointeur()));
    anotherCore->start();
}

//void Chrono::start(int itr)
//{
//    std::cout << itr;
////    qDebug() << itr;
////    QString s = QString::number(itr);
////    this->stopwatch->setText(s);
////    this->stopwatch->show();

//    //   {
//    //       std::this_thread::sleep_for(100); //faster than func_2
//    //       {
//    //           auto lk = g_lock(); //keep output locked up to }
//    //           std::cout << "func_1 - iteration " << i << std::endl;
//    //       }
//    //   }

//}

QLabel *Chrono::getStopwatch() const
{
    return stopwatch;
}

void Chrono::setStopwatch(QLabel *value)
{
    stopwatch = value;
}
