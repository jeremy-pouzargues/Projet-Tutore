/**
 * @file   gameMessageBox.h
 * @author François
 * @brief  Affiche une MessageBox avec un texte mis en paramètre (En Dev)
 * @version -1
 **/
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
