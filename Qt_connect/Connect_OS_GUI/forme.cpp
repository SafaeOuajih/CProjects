//
// Created by Safae on 05/05/2020.
//

#include "forme.h"
#include <math.h>

using namespace std;
Forme::Forme(int x , int y , int color, string filename1, string filename2, int transp,int echelle_d) : Dessin(filename1,filename2,echelle_d){
    x1 = x;
    y1 = y;
    couleur = color ;
    transparence = transp;
    //z = zoom;
}

Forme::~Forme(){
}

int Forme::get_x1(){
    return x1;
}
int Forme::get_y1(){
    return y1;
}

int Forme::get_r(){
    int r;
    r = couleur / pow(16,4);
    return r;
}
int Forme::get_transp(){
    return transparence;
}

int Forme::get_g(){
    int color = couleur;
    color = color - (pow(16,4)* get_r());
    int g;
    g= color / pow(16,2);
    return g;
}

int Forme::get_b(){
    int color = couleur;
    color = color - (pow(16,4)* get_r()) - (pow(16,2)* get_g()) ;
    int b ;
    b= color ;
    return b;
}

void Forme::zoom(int zooming){

}