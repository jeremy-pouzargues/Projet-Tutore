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
public slots:
    void onSignalReceive(QString timeToSend);
private:
    ChessBoard * hisBoard;
    bool status;
    int seconds;
    int minute;
    QLabel * stopwatch;
};

#endif // CHRONO_H
