#include "QCustomMessageBox.h"

QCustomMessageBox::QCustomMessageBox()
{
    //    this->setWindowFlag()
}

void QCustomMessageBox::init()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet(
                "background-color:brown;"
                "color:white;"
                "font-size:24px;"
                );
}

void QCustomMessageBox::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void QCustomMessageBox::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

