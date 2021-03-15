//
// Created by Safae on 08/05/2020.
//

#include "Carre.h"
#include "Ligne.h"

using namespace std;

Carre::Carre(int x1, int y1,int longueur, int hauteur, int color, string filename1, string filename2,int transp,int echelle_d) : Forme(x1, y1, color,filename1,filename2, transp,echelle_d){
    longueur_c = longueur;
    hauteur_c = longueur;
    ligne1 = new Ligne(x1,y1,x1+longueur_c, y1, color,filename1, filename2,transp,echelle_d);
    ligne2 = new Ligne(x1+longueur_c,y1,x1+longueur_c, y1+ hauteur_c, color,filename1, filename2,transp,echelle_d);
    ligne3 = new Ligne(x1+longueur_c,y1+ hauteur_c,x1, y1+ hauteur_c, color,filename1, filename2,transp,echelle_d);
    ligne4 = new Ligne(x1,y1+ hauteur_c,x1, y1, color, filename1, filename2,transp,echelle_d);

}

Carre::~Carre() {
    delete ligne4;
    delete ligne3;
    delete ligne2;
    delete ligne1;
}
int Carre::get_longueur_c(){
    return longueur_c;
}


int Carre::get_hauteur_c(){
    return hauteur_c;
}

void Carre::plot(CImage  *img){
    ligne1->plot(img);
    ligne2->plot(img);
    ligne3->plot(img);
    ligne4->plot(img);
}