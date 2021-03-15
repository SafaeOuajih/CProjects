//
// Created by Safae on 08/05/2020.
//

#ifndef PG208_RECTANGLE_H
#define PG208_RECTANGLE_H
#include "forme.h"

//#include "CBitmap.h"
class Ligne ;
class CImage;

class Rectangle: public Forme {
    protected:
        int longueur_r;
        int hauteur_r;
        Ligne* ligne1;
        Ligne* ligne2;
        Ligne* ligne3;
        Ligne* ligne4;
    public:
        Rectangle(int x1, int y1,int longueur_r, int hauteur_r, int color, string filename1, string filename2,int transp,int echelle_d);
        ~Rectangle();
        int get_longueur_r();
        int get_hauteur_r();
        void plot(CImage  *img);
};


#endif //PG208_RECTANGLE_H
