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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    //, SIGNAL(valueChanged(int), ui->progressBar));

    QPixmap *pixmap_img = new QPixmap("Sortie.bmp");
/*    int w = pixmap_img->width();
    int h = pixmap_img->height();
    ui->label->setFixedHeight(h);
    ui->label->setFixedWidth(w);
    ui->scrollArea->setWidget(ui->label);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
;
}

void MainWindow::on_pushButton_2_clicked()
{
;
}
