#include "creditProfile.h"

creditProfile::creditProfile(int x,int y,QWidget * window,QString url,QString Name,QString RessourcePath)
{
    const QSize PICSIZE = QSize(225,150);
    const QSize TEXTSIZE = QSize(225,50);

    QLabel * m_ImageLabel = new QLabel(window);
    QPixmap pixmap(RessourcePath);
    pixmap.scaledToWidth(50);
    m_ImageLabel->setPixmap(pixmap);
    m_ImageLabel->setMinimumSize(PICSIZE);
    m_ImageLabel->setMaximumSize(PICSIZE);
    m_ImageLabel->move(x,y);

    QLabel *label = new QLabel(window);

    label->setText("<a href=\"" + url + "\">" + Name +"</a>");

    label->setTextFormat(Qt::RichText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);

    label->setStyleSheet(
                "font-size:18px;"
                "color:white;"
//                "border: 1px solid black;"
//                "text-align: center;"
                  "background-color: brown;"
                );

    label->setMinimumSize(TEXTSIZE);
    label->setMaximumSize(TEXTSIZE);

    label->setAlignment(Qt::AlignCenter);

    label->move(x,y+150);

    //    m_ImageLabel->show();
    //    label->show();
}
