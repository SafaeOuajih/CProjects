#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>
#include <QGridLayout>
#include<dessin.h>

namespace Ui {
class secwindow;
}

class secwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secwindow(QWidget *parent = nullptr);
    ~secwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::secwindow *ui;
    Dessin* dessin;
    int i;
    QHBoxLayout ** h_layout;
    //QGridLayout *gridLayout;

};

#endif // SECWINDOW_H
