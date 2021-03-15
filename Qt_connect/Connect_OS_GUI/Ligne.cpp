//
// Created by Safae on 23/04/2020.
//

#include "Ligne.h"
#include <math.h>

using namespace std;
Ligne::Ligne(int x1, int y1, int x22, int y22, int color, string filename1, string filename2,int transp,int echelle_d) : Forme(x1, y1, color,filename1,filename2,transp,echelle_d) {
    x2 = x22;
    y2 = y22;
}
Ligne::~Ligne() {

}

int Ligne::get_x2(){
    return x2;
}

int Ligne::get_y2(){
    return y2;
}

void Ligne::plot(CImage *img) {
    int echelle = getEchelle();
    int largeur = getLargeur();
    int x1 = get_x1()*getEchelle();
    int x2 = get_x2()*getEchelle();
    int y1 = get_y1()*getEchelle();
    int y2 = get_y2()*getEchelle();
    double coef =0;
    int r = floor(((100 - get_transp()) * get_r() + get_transp() * 255)  /100);
    int g = floor(((100 - get_transp()) * get_g() + get_transp() * 255) /100) ;
    int b = floor(((100 - get_transp()) * get_b() + get_transp() * 255) /100) ;
    if((x2 - x1) != 0  ){ //and (y2 - y1) != 0
        coef = (y2 - y1)/(x2 - x1) ;
        if (x2 - x1 >= 0){
            for (int i = x1; i <x2 ; ++i) {
                CPixel *p = img->getPixel(i,floor(y1+coef*(i - x1)));
                p->RGB(r,g,b);
            }
        } else{
            for (int i = x2; i <x1 ; ++i) {
                CPixel *p = img->getPixel(i,floor(y1+coef*(i - x1)));
                p->RGB(r,g,b);
            }
        }
    }
    else{
        if (y2 - y1 >= 0){
            for (int i = y1; i <y2 ; ++i) {
                CPixel *p = img->getPixel(x1,i);
                p->RGB(r,g,b);
            }
        } else{
            for (int i = y2; i <y1 ; ++i) {
                CPixel *p = img->getPixel(x1,i);
                p->RGB(r,g,b);
            }
        }
    }



}