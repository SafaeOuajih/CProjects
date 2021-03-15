//
// Created by Safae on 23/04/2020.
//
#ifndef PG208_POINT_H
#define PG208_POINT_H
#include "forme.h"
#include "CBitmap.h"
class Forme ;

class Point : public Forme{
public:
    Point(int x1, int y1, int color, string filename1, string filename2 ,int transp,int echelle_d);
    ~Point();
    void plot(CImage  *img);
};


#endif //PG208_POINT_H
