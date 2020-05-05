#ifndef ENTER_H
#define ENTER_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class enter;
}

class enter : public QDialog
{
    Q_OBJECT

public:
    explicit enter(QWidget *parent = nullptr);
    ~enter();

private slots:
    void on_back_clicked();

    void on_search_clicked();

    void on_cancel_clicked();

private:
    Ui::enter *ui;
};

#endif // ENTER_H
