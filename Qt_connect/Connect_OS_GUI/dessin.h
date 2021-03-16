//
// Created by Safae on 06/05/2020.
//

#ifndef PG208_DESSIN_H
#define PG208_DESSIN_H
#include <QWidget>
#include "CBitmap.h"
#include "CImage.h"
//#include "Point.h"
//#include "forme.h"
#include <vector>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
class Forme;
class Point;
class Ligne;
class Rectangle;
class Carre;
class Cercle ;

class Dessin: public QWidget{
    Q_OBJECT
protected:
    CImage  *img;
    CBitmap *image;
    long long int hauteur;
    long long int largeur;
    int echelle ;
    //vector<Forme> forms;
    string draw_txt;
    string picture;
    Point* point;
    Ligne* ligne;
    Rectangle* rectangle ;
    Carre * carre;
    Cercle * cercle;
private slots:
    void drawFormes();

public:
    Dessin( string filename1, string filename2 , int echelle_d );
    ~Dessin();
    int getHauteur();
    int getLargeur();
    int getEchelle();
    void drawFormes2(QHBoxLayout * h_layout);
    QHBoxLayout * layout ;
};


#endif //PG208_DESSIN_H
