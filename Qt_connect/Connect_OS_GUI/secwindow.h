#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>

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

private:
    Ui::secwindow *ui;
};

#endif // SECWINDOW_H
