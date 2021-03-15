//
// Created by Safae on 06/05/2020.
//

#ifndef PG208_DESSIN_H
#define PG208_DESSIN_H
#include "CBitmap.h"
#include "CImage.h"
//#include "Point.h"
//#include "forme.h"
#include <vector>
#include <string>
#include <iostream>
class Forme;
class Point;
class Ligne;
class Rectangle;
class Carre;
class Cercle ;

class Dessin{
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
public:
    Dessin( string filename1, string filename2 , int echelle_d );
    ~Dessin();
    void drawFormes();
    int getHauteur();
    int getLargeur();
    int getEchelle();
};


#endif //PG208_DESSIN_H
