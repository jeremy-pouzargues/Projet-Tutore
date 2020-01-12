#include "gameMessageBox.h"

gameMessageBox::gameMessageBox(QString innerText) : signal(false)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setText(innerText);
    this->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    this->exec();
}
