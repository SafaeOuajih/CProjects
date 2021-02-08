#include <fstream>
#include <stdlib.h>
#include<cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "Point.h"
#include "dessin.h"
#include "CBitmap.h"

using namespace std;

int main(int argc, char * argv[]) {

    Dessin* dessin = new Dessin( "C:/Users/Safae/CLionProjects/PG208/description.txt", "Sortie.bmp" ,1);
    dessin->drawFormes();
    delete dessin;
    //  CImage*img ;
    //  img = new CImage(1025*2,1025*2);
    //  delete img;
    //  cout<<"not done"<< endl;
    return 1;

}