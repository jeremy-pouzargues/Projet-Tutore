/**
 * @file   QCustomMessageBox.h
 * @author François
 * @brief  Affiche une MessageBox borderless
 * @version 1.0
 **/
#ifndef QCUSTOMMESSAGEBOX_H
#define QCUSTOMMESSAGEBOX_H

#include <QMessageBox>

#include <QMouseEvent>
class QCustomMessageBox : public QMessageBox
{
public:
    explicit QCustomMessageBox();
protected:
    void init();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // QCUSTOMMESSAGEBOX_H
