#include "mainwindow.h"
#include <CBitmap.h>
#include <CImage.h>
#include <CLigne.h>
#include <CPixel.h>
#include <Carre.h>
#include <Cercle.h>
#include <Ligne.h>
#include <Point.h>
#include <Rectangle.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dessin* dessin = new Dessin( "/home/safae/Documents/CProjects/DessinVectoriel/description.txt", "Sortie.bmp" , 1);
    dessin->drawFormes();
    MainWindow w;
    w.show();
    return a.exec();
}
