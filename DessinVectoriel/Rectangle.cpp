//
// Created by Safae on 08/05/2020.
//

#include "Rectangle.h"
#include "Ligne.h"

using namespace std;

Rectangle::Rectangle(int x1, int y1,int longueur, int hauteur, int color, string filename1, string filename2,int transp,int echelle_d) : Forme(x1, y1, color,filename1,filename2,transp,echelle_d){
    longueur_r = longueur;
    hauteur_r = hauteur;
    ligne1 = new Ligne(x1,y1,x1+longueur, y1, color, filename1, filename2 , transp,echelle_d);
    ligne2 = new Ligne(x1+longueur,y1,x1+longueur, y1+ hauteur, color,filename1, filename2,transp,echelle_d);
    ligne3 = new Ligne(x1+longueur,y1+ hauteur,x1, y1+ hauteur, color,filename1, filename2,transp,echelle_d);
    ligne4 = new Ligne(x1,y1+ hauteur,x1, y1, color,filename1, filename2,transp,echelle_d);

}

Rectangle::~Rectangle(){
    delete ligne4;
    delete ligne3;
    delete ligne2;
    delete ligne1;
}

int Rectangle::get_longueur_r(){
    return longueur_r;
}


int Rectangle::get_hauteur_r(){
    return hauteur_r;
}

void Rectangle::plot(CImage  *img){
    ligne1->plot(img);
    ligne2->plot(img);
    ligne3->plot(img);
    ligne4->plot(img);
}