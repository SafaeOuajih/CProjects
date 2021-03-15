//
// Created by Safae on 08/05/2020.
//

#include "Cercle.h"
#include <math.h>

Cercle::Cercle(int x1, int y1,int rayon, int color, string filename1, string filename2,int transp,int echelle_d) : Forme(x1, y1, color,filename1,filename2,transp,echelle_d){
    rayon_c = rayon;
}
int Cercle::get_rayon(){
    return rayon_c;
}
Cercle::~Cercle(){

}

void Cercle::plot(CImage  *img){
int echelle = getEchelle();
rayon_c = rayon_c * echelle;
int x1 = get_x1() * echelle;
int y1 = get_y1() * echelle;
int d = x1 - rayon_c;
int f = x1 + rayon_c ;
int d2 = y1 - rayon_c;
int f2 = y1 + rayon_c ;
int r = floor(((100 - get_transp()) * get_r() + get_transp() * 255)  /100);
int g = floor(((100 - get_transp()) * get_g() + get_transp() * 255) /100) ;
int b = floor(((100 - get_transp()) * get_b() + get_transp() * 255) /100) ;

    for (int i = d; i <f ; ++i) {
        int y = floor(pow(   pow(rayon_c,2 ) - pow(i-x1,2)    ,      0.5  )) + y1;
        CPixel *p = img->getPixel(i,y);
        p->RGB(r,g,b);

        int y2 = floor(pow(  pow(rayon_c,2 ) - pow(i-x1,2), 0.5  ) - 2 * pow( pow(rayon_c,2 ) - pow(i-x1,2) , 0.5  )) + y1;
        CPixel *p2 = img->getPixel(i,y2);
        p2->RGB(r,g,b);

    }
    for (int i = d2; i <f2; ++i) {
        int x = floor(pow(   pow(rayon_c,2 ) - pow(i-y1,2)    ,      0.5  )) + x1;
        CPixel *p3 = img->getPixel(x,i);
        p3->RGB(r,g,b);

        int x2 = floor(pow(  pow(rayon_c,2 ) - pow(i-y1,2), 0.5  ) - 2 * pow( pow(rayon_c,2 ) - pow(i-y1,2) , 0.5  )) + x1;
        CPixel *p4 = img->getPixel(x2,i);
        p4->RGB(r,g,b);

    }

}