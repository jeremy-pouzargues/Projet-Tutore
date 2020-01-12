/**
 * @file   windowCommandsButton.h
 * @author François
 * @brief  Genère le bouton de fermeture de l'application sur une page et l'application de fond passé en paramètre
 * @version 1.2
 **/
#ifndef WINDOWCOMMANDSBUTTON_H
#define WINDOWCOMMANDSBUTTON_H

#include <QWidget>
#include <QPushButton>
class windowCommandsButton : QPushButton
{
    Q_OBJECT
public:
    windowCommandsButton(QWidget * parent,QWidget * grandpa);
};

#endif // WINDOWCOMMANDSBUTTON_H
