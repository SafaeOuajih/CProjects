//
// Created by Safae on 06/05/2020.
//

#include "dessin.h"
#include <string>
#include "Point.h"
#include "Ligne.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Cercle.h"
#include <fstream>
using namespace std;

Dessin::Dessin(string filename1, string filename2,int echelle_d) {
    // initialisation
    hauteur = 0;
    largeur = 0;
    echelle = echelle_d;
    draw_txt = filename1;
    picture = filename2;
    image = new CBitmap();

    ifstream fichier3(draw_txt);
    int nbLignes = 0;
    std::string lign;
    while(std::getline(fichier3, lign))
    {
        nbLignes++;
    }
    fichier3.close();
    ifstream fichier2(draw_txt);
    string typeForme2;
    int x1_dim2 =0;
    int y1_dim2=0;
    int x2_dim2=0;
    int y2_dim2=0;
    int couleur2=0;
    int trans2 = 0;
    int z = 0;
    int l = 0;
    for (int i = 0; i < nbLignes; ++i) {
        fichier2 >> typeForme2;
        if (typeForme2 == "point") {
            fichier2 >> x1_dim2;
            fichier2 >> y1_dim2;
            fichier2 >> couleur2;
            fichier2 >> trans2;
            l= max(l,max(x1_dim2,y1_dim2));
        } else if (typeForme2 == "ligne") {
            fichier2 >> x1_dim2;
            fichier2 >> y1_dim2;
            fichier2 >> x2_dim2;
            fichier2 >> y2_dim2;
            fichier2 >> couleur2;
            fichier2 >> trans2;
            l= max(l,max(max(x2_dim2,y2_dim2),max(x1_dim2,y1_dim2)));
        } else if (typeForme2 == "rectangle") {
            fichier2 >> x1_dim2;
            fichier2 >> y1_dim2;
            fichier2 >> x2_dim2;
            fichier2 >> y2_dim2;
            fichier2 >> couleur2;
            fichier2 >> trans2;
            l= max(l,max(x1_dim2+x2_dim2,y1_dim2+y2_dim2));
        } else if (typeForme2 == "carre") {
            fichier2 >> x1_dim2;
            fichier2 >> y1_dim2;
            fichier2 >> x2_dim2;
            fichier2 >> y2_dim2;
            fichier2 >> couleur2;
            fichier2 >> trans2;
            l= max(l,max(x1_dim2+x2_dim2,y1_dim2+y2_dim2));
        } else if (typeForme2 == "cercle") {
            fichier2 >> x1_dim2;
            fichier2 >> y1_dim2;
            fichier2 >> x2_dim2;
            fichier2 >> couleur2;
            fichier2 >> trans2;
            l= max(l,max(x1_dim2+x2_dim2,y1_dim2+x2_dim2));
        }
    }

    fichier2.close();
    if (l%4 == 0){
        l = l+4;
    } else if(l%4==1){
        l = l + 7 ;
    } else if(l%4==2){
        l = l +6;
    } else if(l%4==3){
        l= l +5;
    }
    hauteur = l*echelle ;
    largeur = hauteur ;
    img = new CImage(hauteur,largeur);
}

Dessin::~Dessin() {
    delete img;
    delete image;
    delete point;
    delete ligne;
    delete rectangle;
    delete carre;
    delete cercle;
}

void Dessin::drawFormes(){

    ifstream fichier2(draw_txt);
    int nbLignes = 0;
    std::string lign;
    while(std::getline(fichier2, lign))
    {
        nbLignes++;
    }
    fichier2.close();


    //img = new CImage(hauteur,largeur);
    // read formes
    ifstream fichier(draw_txt);
    if(fichier)
    {
        int position = fichier.tellg();
        fichier.seekg(position, ios::beg);
        position = fichier.tellg();
        cout << "Et maintenant" << position << endl;
        string typeForme;
        int x1_dim =0;
        int y1_dim=0;
        int x2_dim=0;
        int y2_dim=0;
        int couleur=0;
        int trans = 0;

        for (int i = 0; i < nbLignes; ++i) {
            fichier >> typeForme;
            cout << typeForme << endl;
            if (typeForme == "point") {
                fichier >> x1_dim;
                fichier >> y1_dim;
                fichier >> couleur;
                fichier >> trans;
                point = new Point(x1_dim, y1_dim, couleur, draw_txt, picture, trans,echelle);
                //forms.push_back(*point);
                cout << "push done point" << endl;
                point->plot(img);
                image->setImage(img);
                image->SaveBMP(picture);
                //delete point;
            } else if (typeForme == "ligne") {
                fichier >> x1_dim;
                fichier >> y1_dim;
                fichier >> x2_dim;
                fichier >> y2_dim;
                fichier >> couleur;
                fichier >> trans;
                ligne = new Ligne(x1_dim, y1_dim, x2_dim, y2_dim, couleur, draw_txt, picture, trans,echelle);
                //forms.push_back(*point);
                cout << "push done ligne" << endl;
                ligne->plot(img);
                image->setImage(img);
                image->SaveBMP(picture);
                //delete ligne;
            } else if (typeForme == "rectangle") {
                fichier >> x1_dim;
                fichier >> y1_dim;
                fichier >> x2_dim;
                fichier >> y2_dim;
                fichier >> couleur;
                fichier >> trans;
                rectangle = new Rectangle(x1_dim, y1_dim, x2_dim, y2_dim, couleur, draw_txt, picture,
                                          trans,echelle);
                cout << "push done rectangle" << endl;
                rectangle->plot(img);
                image->setImage(img);
                image->SaveBMP(picture);
                //delete rectangle;
            } else if (typeForme == "carre") {
                fichier >> x1_dim;
                fichier >> y1_dim;
                fichier >> x2_dim;
                fichier >> y2_dim;
                fichier >> couleur;
                fichier >> trans;
                carre = new Carre(x1_dim, y1_dim, x2_dim, y2_dim, couleur, draw_txt, picture, trans,echelle);
                cout << "push done carre" << endl;
                carre->plot(img);
                image->setImage(img);
                image->SaveBMP(picture);
                //delete carre;
            } else if (typeForme == "cercle") {
                fichier >> x1_dim;
                fichier >> y1_dim;
                fichier >> x2_dim;
                fichier >> couleur;
                fichier >> trans;
                cercle = new Cercle(x1_dim, y1_dim, x2_dim, couleur, draw_txt, picture, trans,echelle);
                cout << "push done cercle" << endl;
                cercle->plot(img);
                image->setImage(img);
                image->SaveBMP(picture);
                //delete cercle;
            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    fichier.close();
}

int Dessin::getHauteur(){
    return hauteur;
}

int Dessin::getLargeur(){
    return largeur;
}
int Dessin::getEchelle(){
    return echelle;
}
