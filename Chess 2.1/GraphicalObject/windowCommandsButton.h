/**
 * @file windowCommandsButton.h include "GraphicalObject/windowCommandButton.h"
 * @author François
 * @version 1.0
 */
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
