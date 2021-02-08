//
// Created by Safae on 23/04/2020.
//

#ifndef PG208_LIGNE_H
#define PG208_LIGNE_H
#include "CBitmap.h"
#include "forme.h"


class Ligne:public Forme{
protected:
    int x2;
    int y2;
public:
    Ligne(int x1, int y1,int x22, int y22, int color, string filename1, string filename2,int transp,int echelle_d);
    ~Ligne();
    void plot(CImage  *img);
    int get_x2();
    int get_y2();
};


#endif //PG208_LIGNE_H
