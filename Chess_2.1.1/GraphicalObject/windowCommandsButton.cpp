#include "windowCommandsButton.h"

windowCommandsButton::windowCommandsButton(QWidget * parent,QWidget * grandpa) : QPushButton(parent)
{
    const QSize BUTTONMENU_SIZE = QSize(30,30);
    this->setText("X");
    this->move(570,10);
    this->setMaximumSize(BUTTONMENU_SIZE);
    this->setStyleSheet(
                "border: 0px;"
                "background:none;"
                "background-color: rgba(255, 255, 255, 0);"
                "color:white;"
                "font-size:24px;"
                );
    connect(this,SIGNAL(clicked()),grandpa,SLOT(close()));
    this->show();
}
