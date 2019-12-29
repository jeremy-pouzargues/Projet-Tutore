#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QObject>
#include <QWidget>

#include <QMessageBox>
#include <QIcon>
#include <QMouseEvent>

class MessageBox : public QMessageBox
{
public:
    MessageBox(std::string Name,std::string Text);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // MESSAGEBOX_H
