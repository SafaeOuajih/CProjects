//
// Created by Safae on 23/04/2020.
//
#include<string>

#include "Point.h"
#include <math.h>

using namespace std;
Point::Point(int x1, int y1, int color, string filename1, string filename2,int transp,int echelle_d) : Forme(x1, y1, color,filename1,filename2,transp,echelle_d) {
}

Point::~Point() {
}

void Point::plot(CImage* img){
    int r = floor(((100 - get_transp()) * get_r() + get_transp() * 255)  /100);
    int g = floor(((100 - get_transp()) * get_g() + get_transp() * 255) /100) ;
    int b = floor(((100 - get_transp()) * get_b() + get_transp() * 255) /100) ;
    CPixel *p = img->getPixel(get_x1()*getEchelle(),get_y1()*getEchelle());
    p->RGB(r,g,b);
}