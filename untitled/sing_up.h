#ifndef SING_UP_H
#define SING_UP_H

#include <QDialog>
#include "mainwindow.h"
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Sing_up;
}

class Sing_up : public QDialog
{
    Q_OBJECT

public:
    explicit Sing_up(QWidget *parent = nullptr);
    ~Sing_up();

private slots:
    void on_Close_clicked();

    void on_Input_clicked();

private:
    Ui::Sing_up *ui;

};

#endif // SING_UP_H
