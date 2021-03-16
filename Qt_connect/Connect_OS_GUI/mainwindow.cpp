#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <CBitmap.h>
#include <CImage.h>
#include <CLigne.h>
#include <CPixel.h>
#include <Carre.h>
#include <Cercle.h>
#include <Ligne.h>
#include <Point.h>
#include <Rectangle.h>
#include "ui_secwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    //, SIGNAL(valueChanged(int), ui->progressBar));
    secwindow secw;
    secw.setModal(true); //it'll set the secwindow
    i=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // show picture
{
    //if(i){
        pixmap_img = new QPixmap("/home/safae/Connect_OS_GUI/Sortie.bmp");
        i=1;
        w = pixmap_img->width();
        h = pixmap_img->height();
        ui->label->setFixedHeight(h);
        ui->label->setFixedWidth(w);
        ui->scrollArea->setWidget(ui->label);
        ui->label->setPixmap(*pixmap_img);
    //}
}



void MainWindow::on_pushButton_3_clicked() // add forms
{
    secw.exec(); //shows secwindow when button is pressed

}
