//
// Created by Safae on 05/05/2020.
//

#include "CBitmap.h"
#include "CImage.h"

#ifndef PG208_FORME_H
#define PG208_FORME_H
#include "dessin.h"
class Dessin;

class Forme: public Dessin{

protected:
    int x1;
    int y1;
    //int z ;
    int couleur;
    int transparence;
public:
    Forme(int x1 , int y1 , int color, string filename1, string filename2 , int transp,int echelle_d);
    ~Forme();
    //void virtual plot(CImage* img)=0;
    void virtual zoom(int zooming);
    int get_x1();
    int get_y1();
    int get_r();
    int get_g();
    int get_b();
    int get_transp();
};


#endif // PG208_FORME_H
