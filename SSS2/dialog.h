#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QString>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString sDate();

private:
    Ui::Dialog *ui;

protected:
    //virtual void closeEvent(QCloseEvent *event);

};

#endif // DIALOG_H
