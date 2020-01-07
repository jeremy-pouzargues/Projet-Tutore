/********************************************************************************
** Form generated from reading UI file 'ChoosePieceWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPIECEWINDOW_H
#define UI_CHOOSEPIECEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoosePieceWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChoosePieceWindow)
    {
        if (ChoosePieceWindow->objectName().isEmpty())
            ChoosePieceWindow->setObjectName(QString::fromUtf8("ChoosePieceWindow"));
        ChoosePieceWindow->resize(200, 300);
        ChoosePieceWindow->setMinimumSize(QSize(200, 300));
        ChoosePieceWindow->setMaximumSize(QSize(200, 300));
        ChoosePieceWindow->setBaseSize(QSize(200, 300));
        centralwidget = new QWidget(ChoosePieceWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ChoosePieceWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChoosePieceWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 200, 22));
        ChoosePieceWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChoosePieceWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChoosePieceWindow->setStatusBar(statusbar);

        retranslateUi(ChoosePieceWindow);

        QMetaObject::connectSlotsByName(ChoosePieceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChoosePieceWindow)
    {
        ChoosePieceWindow->setWindowTitle(QCoreApplication::translate("ChoosePieceWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoosePieceWindow: public Ui_ChoosePieceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPIECEWINDOW_H
