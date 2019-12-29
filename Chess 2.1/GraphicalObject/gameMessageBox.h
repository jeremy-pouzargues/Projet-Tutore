#ifndef GAMEMESSAGEBOX_H
#define GAMEMESSAGEBOX_H

#include <QMessageBox>

class gameMessageBox : public QMessageBox
{
public:
    gameMessageBox(QString innerText);
private:
    bool signal;
};

#endif // GAMEMESSAGEBOX_H
