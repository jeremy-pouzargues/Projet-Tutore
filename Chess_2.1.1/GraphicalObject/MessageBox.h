/**
 * @file   MessageBox.h
 * @author François
 * @brief  Affiche une MessageBox avec un texte mis en paramètre ainsi qu'un titre (En Dev)
 * @version 1.1
 **/
#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QObject>
#include <QWidget>

#include <QMessageBox>
#include <QIcon>
#include <QMouseEvent>

#include "QCustomMessageBox.h"

class MessageBox : public QCustomMessageBox
{
public:
    MessageBox(std::string Name,std::string Text);
};

#endif // MESSAGEBOX_H
