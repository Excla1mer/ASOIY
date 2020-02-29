#include "authors.h"
#include "ui_authors.h"

authors::authors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authors)
{
    ui->setupUi(this);
}

authors::~authors()
{
    delete ui;
}

void authors::closeEvent(QCloseEvent *event)
{
    MainWindow *wg=new MainWindow;
    wg->show();
}
