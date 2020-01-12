#include "Chrono.h"

#include <thread>
#include <mutex>

#include <mutex>          // std::mutex


Chrono::Chrono(QWidget * where,ChessBoard * hisBoard/*,MainWindow * hisMainWindow*/) : status(true),hisBoard(hisBoard),InterpretationSignal(false)/*,hisMainWindow(hisMainWindow)*/ /*: QThread(where)*/
{
    std::mutex mtx;

    QLabel *Chrono = new QLabel(where);
    this->stopwatch = Chrono;
    this->stopwatch->setText("00:00");
    this->stopwatch->move(400,65);
    this->stopwatch->setStyleSheet(
                "color:white;"
                "font-size:36px;"
                );
}

#include <QtDebug>
#include <iostream>

void Chrono::onSignalReceive(QString timeToSend) {
    if(this->status)
    {
        this->stopwatch->setText(timeToSend);
    }
}

void Chrono::onSignalReceiveFromMainWindow()
{
    qDebug() << "signal recu";
    qDebug() << this->InterpretationSignal;

    this->setInterpretationSignal(true);
    qDebug() << this->InterpretationSignal;
}

ChessBoard *Chrono::getHisBoard() const
{
    return hisBoard;
}

void Chrono::setHisBoard(ChessBoard *value)
{
    hisBoard = value;
}

bool Chrono::getInterpretationSignal() const
{
    return InterpretationSignal;
}

void Chrono::setInterpretationSignal(bool value)
{
    InterpretationSignal = value;
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
    initThread *anotherCore = new initThread(this->hisBoard,this);
    connect(anotherCore, &initThread::sendSignal,this, &Chrono::onSignalReceive);
    anotherCore->start();
}

QLabel *Chrono::getStopwatch() const
{
    return stopwatch;
}

void Chrono::setStopwatch(QLabel *value)
{
    stopwatch = value;
}
