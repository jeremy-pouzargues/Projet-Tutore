/**
 * @file   Chrono.h
 * @author François
 * @brief  Chronomètre de partie
 * @version 1.5
 **/
#ifndef CHRONO_H
#define CHRONO_H

#include <QLabel>
#include <QWidget>

#include <QThread>

#include <unistd.h>

#include <Chessboard/Chessboard.h>

class Chrono : public QWidget
{
    Q_OBJECT
public:
    Chrono(QWidget * where,ChessBoard * hisBoard);
    QLabel *getStopwatch() const;
    void setStopwatch(QLabel *value);
    void startInNewThread();
    bool getStatus() const;
    void setStatus(bool value);
    void reset();

    bool getInterpretationSignal() const;
    void setInterpretationSignal(bool value);

    void setHisBoard(ChessBoard *value);

    ChessBoard *getHisBoard() const;

public slots:
    void onSignalReceive(QString timeToSend);
    void onSignalReceiveFromMainWindow();
private:
    bool InterpretationSignal;

    ChessBoard * hisBoard;
    bool status;
    int seconds;
    int minute;
    QLabel * stopwatch;
};

#endif // CHRONO_H
