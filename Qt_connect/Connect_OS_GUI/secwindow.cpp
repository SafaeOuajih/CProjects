#include "secwindow.h"
#include "ui_secwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QSlider>
#define max 200

secwindow::secwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Drawing");
    dessin = new Dessin( "/home/safae/Documents/CProjects/DessinVectoriel/description.txt", "/home/safae/Connect_OS_GUI/Sortie.bmp" ,1);
    connect(ui->Done,SIGNAL(clicked()),dessin,SLOT(drawFormes()));
    i=0;
    h_layout =(QHBoxLayout**) malloc((max)*sizeof(QHBoxLayout*));
}

secwindow::~secwindow()
{
    delete ui;
    free(h_layout);
}

void secwindow::on_pushButton_clicked() //cercle
{
    h_layout[i] = new QHBoxLayout;
    QLabel *crcl = new QLabel;
    QVBoxLayout * v_layout1 = new QVBoxLayout;
    QSpinBox *spb1 = new QSpinBox;
    QLabel * xposition = new QLabel;
    QVBoxLayout * v_layout2 = new QVBoxLayout;
    QSpinBox *spb2 = new QSpinBox;
    QLabel * yposition = new QLabel;
    QVBoxLayout * v_layout3 = new QVBoxLayout;
    QSpinBox *spb3 = new QSpinBox;
    QLabel * rayon = new QLabel;
    QVBoxLayout * v_layout4 = new QVBoxLayout;
    QSpinBox *spb4 = new QSpinBox;
    QLabel * color = new QLabel;
    QVBoxLayout * v_layout5 = new QVBoxLayout;
    QSlider *spb5 = new QSlider(Qt :: Horizontal);
    QLabel *transparence = new QLabel;
//H1
    crcl->setText("Cercle");
    h_layout[i]->addWidget(crcl);
//H2
    //v_layout1->setSpacing(0);
    //v_layout1->setMargin(0);
    xposition->setText("xPosition for center");
    v_layout1->addWidget(xposition);
    v_layout1->addWidget(spb1);
    h_layout[i]->addLayout(v_layout1);
//H3
    yposition->setText("yPosition for center");
    v_layout2->addWidget(yposition);
    v_layout2->addWidget(spb2);
    h_layout[i]->addLayout(v_layout2);
//H4
    rayon->setText("Rayon");
    v_layout3->addWidget(rayon);
    v_layout3->addWidget(spb3);
    h_layout[i]->addLayout(v_layout3);
//H5
    color->setText("Couleur");
    v_layout4->addWidget(color);
    v_layout4->addWidget(spb4);
    h_layout[i]->addLayout(v_layout4);
//H6
    transparence->setText("Transparence");
    v_layout5->addWidget(transparence);
    v_layout5->addWidget(spb5);
    h_layout[i]->addLayout(v_layout5);
    ui->verticalLayout->addLayout(h_layout[i]);
    i++;

}

void secwindow::on_pushButton_2_clicked() //ligne
{
    h_layout[i] = new QHBoxLayout;
    QLabel *crcl = new QLabel;
    QVBoxLayout * v_layout1 = new QVBoxLayout;
    QSpinBox *spb1 = new QSpinBox;
    QLabel * xposition = new QLabel;
    QVBoxLayout * v_layout2 = new QVBoxLayout;
    QSpinBox *spb2 = new QSpinBox;
    QLabel * yposition = new QLabel;
    QVBoxLayout * v_layout3 = new QVBoxLayout;
    QSpinBox *spb3 = new QSpinBox;
    QLabel * rayon = new QLabel;
    QVBoxLayout * v_layout4 = new QVBoxLayout;
    QSpinBox *spb4 = new QSpinBox;
    QLabel * color = new QLabel;
    QVBoxLayout * v_layout5 = new QVBoxLayout;
    QSlider *spb5 = new QSlider(Qt :: Horizontal);
    QLabel *transparence = new QLabel;

//H1
    crcl->setText("Triangle");
    h_layout[i]->addWidget(crcl);
//H2
    xposition->setText("xPosition for center");
    v_layout1->addWidget(xposition);
    v_layout1->addWidget(spb1);
    h_layout[i]->addLayout(v_layout1);
//H3
    yposition->setText("yPosition for center");
    v_layout2->addWidget(yposition);
    v_layout2->addWidget(spb2);
    h_layout[i]->addLayout(v_layout2);
//H4
    rayon->setText("Rayon");
    v_layout3->addWidget(rayon);
    v_layout3->addWidget(spb3);
    h_layout[i]->addLayout(v_layout3);
//H5
    color->setText("Couleur");
    v_layout4->addWidget(color);
    v_layout4->addWidget(spb4);
    h_layout[i]->addLayout(v_layout4);
//H6
    transparence->setText("Transparence");
    v_layout5->addWidget(transparence);
    v_layout5->addWidget(spb5);
    h_layout[i]->addLayout(v_layout5);
    ui->verticalLayout->addLayout(h_layout[i]);
    i++;
}

void secwindow::on_pushButton_3_clicked() //ligne
{
    h_layout[i] = new QHBoxLayout;
    QLabel *crcl = new QLabel;
    QVBoxLayout * v_layout1 = new QVBoxLayout;
    QSpinBox *spb1 = new QSpinBox;
    QLabel * xposition = new QLabel;
    QVBoxLayout * v_layout2 = new QVBoxLayout;
    QSpinBox *spb2 = new QSpinBox;
    QLabel * yposition = new QLabel;
    QVBoxLayout * v_layout3 = new QVBoxLayout;
    QSpinBox *spb3 = new QSpinBox;
    QLabel * rayon = new QLabel;
    QVBoxLayout * v_layout4 = new QVBoxLayout;
    QSpinBox *spb4 = new QSpinBox;
    QLabel * color = new QLabel;
    QVBoxLayout * v_layout5 = new QVBoxLayout;
    QSlider *spb5 = new QSlider(Qt :: Horizontal);
    QLabel *transparence = new QLabel;

//H1
    crcl->setText("Ligne");
    h_layout[i]->addWidget(crcl);
//H2
    xposition->setText("xPosition for center");
    v_layout1->addWidget(xposition);
    v_layout1->addWidget(spb1);
    h_layout[i]->addLayout(v_layout1);
//H3
    yposition->setText("yPosition for center");
    v_layout2->addWidget(yposition);
    v_layout2->addWidget(spb2);
    h_layout[i]->addLayout(v_layout2);
//H4
    rayon->setText("Rayon");
    v_layout3->addWidget(rayon);
    v_layout3->addWidget(spb3);
    h_layout[i]->addLayout(v_layout3);
//H5
    color->setText("Couleur");
    v_layout4->addWidget(color);
    v_layout4->addWidget(spb4);
    h_layout[i]->addLayout(v_layout4);
//H6
    transparence->setText("Transparence");
    v_layout5->addWidget(transparence);
    v_layout5->addWidget(spb5);
    h_layout[i]->addLayout(v_layout5);
    ui->verticalLayout->addLayout(h_layout[i]);
    i++;
}

void secwindow::on_pushButton_4_clicked() //carre
{
    h_layout[i] = new QHBoxLayout;
    QLabel *crcl = new QLabel;
    QVBoxLayout * v_layout1 = new QVBoxLayout;
    QSpinBox *spb1 = new QSpinBox;
    QLabel * xposition = new QLabel;
    QVBoxLayout * v_layout2 = new QVBoxLayout;
    QSpinBox *spb2 = new QSpinBox;
    QLabel * yposition = new QLabel;
    QVBoxLayout * v_layout3 = new QVBoxLayout;
    QSpinBox *spb3 = new QSpinBox;
    QLabel * rayon = new QLabel;
    QVBoxLayout * v_layout4 = new QVBoxLayout;
    QSpinBox *spb4 = new QSpinBox;
    QLabel * color = new QLabel;
    QVBoxLayout * v_layout5 = new QVBoxLayout;
    QSlider *spb5 = new QSlider(Qt :: Horizontal);
    QLabel *transparence = new QLabel;

//H1
    crcl->setText("Carré");
    h_layout[i]->addWidget(crcl);
//H2
    xposition->setText("xPosition for center");
    v_layout1->addWidget(xposition);
    v_layout1->addWidget(spb1);
    h_layout[i]->addLayout(v_layout1);
//H3
    yposition->setText("yPosition for center");
    v_layout2->addWidget(yposition);
    v_layout2->addWidget(spb2);
    h_layout[i]->addLayout(v_layout2);
//H4
    rayon->setText("Rayon");
    v_layout3->addWidget(rayon);
    v_layout3->addWidget(spb3);
    h_layout[i]->addLayout(v_layout3);
//H5
    color->setText("Couleur");
    v_layout4->addWidget(color);
    v_layout4->addWidget(spb4);
    h_layout[i]->addLayout(v_layout4);
//H6
    transparence->setText("Transparence");
    v_layout5->addWidget(transparence);
    v_layout5->addWidget(spb5);
    h_layout[i]->addLayout(v_layout5);
    ui->verticalLayout->addLayout(h_layout[i]);
    i++;
}

void secwindow::on_pushButton_5_clicked()//point
{
    h_layout[i] = new QHBoxLayout;
    QLabel *crcl = new QLabel;
    QVBoxLayout * v_layout1 = new QVBoxLayout;
    QSpinBox *spb1 = new QSpinBox;
    QLabel * xposition = new QLabel;
    QVBoxLayout * v_layout2 = new QVBoxLayout;
    QSpinBox *spb2 = new QSpinBox;
    QLabel * yposition = new QLabel;
    QVBoxLayout * v_layout3 = new QVBoxLayout;
    QSpinBox *spb3 = new QSpinBox;
    QLabel * rayon = new QLabel;
    QVBoxLayout * v_layout4 = new QVBoxLayout;
    QSpinBox *spb4 = new QSpinBox;
    QLabel * color = new QLabel;
    QVBoxLayout * v_layout5 = new QVBoxLayout;
    QSlider *spb5 = new QSlider(Qt :: Horizontal);
    QLabel *transparence = new QLabel;

//H1
    crcl->setText("Point");
    h_layout[i]->addWidget(crcl);
//H2
    xposition->setText("xPosition for center");
    v_layout1->addWidget(xposition);
    v_layout1->addWidget(spb1);
    h_layout[i]->addLayout(v_layout1);
//H3
    yposition->setText("yPosition for center");
    v_layout2->addWidget(yposition);
    v_layout2->addWidget(spb2);
    h_layout[i]->addLayout(v_layout2);
//H4
    rayon->setText("Rayon");
    v_layout3->addWidget(rayon);
    v_layout3->addWidget(spb3);
    h_layout[i]->addLayout(v_layout3);
//H5
    color->setText("Couleur");
    v_layout4->addWidget(color);
    v_layout4->addWidget(spb4);
    h_layout[i]->addLayout(v_layout4);
//H6
    transparence->setText("Transparence");
    v_layout5->addWidget(transparence);
    v_layout5->addWidget(spb5);
    h_layout[i]->addLayout(v_layout5);
    ui->verticalLayout->addLayout(h_layout[i]);
    i++;
}
