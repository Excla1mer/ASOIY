#ifndef REPASS_H
#define REPASS_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class repass;
}

class repass : public QDialog
{
    Q_OBJECT

public:
    explicit repass(QWidget *parent = nullptr);
    ~repass();

private slots:
    void on_pushButton_clicked();

    void on_Repass_but_clicked();

private:
    Ui::repass *ui;
};

#endif // REPASS_H
