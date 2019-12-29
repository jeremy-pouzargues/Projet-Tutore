#include "MessageBox.h"

MessageBox::MessageBox(std::string Name,std::string Text)
{
    this->setWindowTitle(QString::fromStdString(Name));
    this->setText(QString::fromStdString(Text));
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet(
                "background-color: rgba(101,33,33,1);"
                "font-size:24px;"
                "color:white;"
                );
    this->exec();
}

void MessageBox::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MessageBox::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
