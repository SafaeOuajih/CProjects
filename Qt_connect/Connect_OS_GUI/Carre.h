//
// Created by Safae on 08/05/2020.
//

#ifndef PG208_CARRE_H
#define PG208_CARRE_H
#include "forme.h"

//#include "CBitmap.h"
class Ligne ;
class CImage;

class Carre : public Forme{
protected:
    int longueur_c;
    int hauteur_c;
    Ligne* ligne1;
    Ligne* ligne2;
    Ligne* ligne3;
    Ligne* ligne4;
public:
    Carre(int x1, int y1,int longueur_c, int hauteur_c, int color, string filename1, string filename2,int transp,int echelle_d);
    ~Carre();
    int get_longueur_c();
    int get_hauteur_c();
    void plot(CImage  *img);
};


#endif //PG208_CARRE_H
