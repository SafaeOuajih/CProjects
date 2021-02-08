//
// Created by Safae on 08/05/2020.
//

#ifndef PG208_CERCLE_H
#define PG208_CERCLE_H
#include "forme.h"
class CImage;

class Cercle : public Forme{
//protected:
public:
    int rayon_c;
public:
    Cercle(int x1, int y1,int rayon, int color, string filename1, string filename2,int transp,int echelle_d);
    ~Cercle();
    int get_rayon();
    void plot(CImage  *img);
};


#endif //PG208_CERCLE_H
