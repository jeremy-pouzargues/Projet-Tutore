/**
 * @file   creditProfile.h
 * @author François
 * @brief  Crée un widget avec une image et un lien vers un git passé en paramètre
 * @version 1.0
 **/
#ifndef CREDITPROFILE_H
#define CREDITPROFILE_H


#include<QWidget>
#include<QLabel>
#include <QPixmap>

class creditProfile
{
public:
    creditProfile(int x,int y,QWidget * window,QString url,QString Name,QString RessourcePath);
};

#endif // CREDITPROFILE_H
