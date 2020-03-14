#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

/*void Dialog::closeEvent(QCloseEvent *event)
{
    MainWindow *wg=new MainWindow;
    wg->show();
}*/
QString Dialog::sDate(){
    return ui->calendarWidget->selectedDate().toString();
}
