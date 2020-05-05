#include "repass.h"
#include "ui_repass.h"
#include <QDebug>
#include <QMessageBox>
repass::repass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::repass)
{
    ui->setupUi(this);
}

repass::~repass()
{
    delete ui;
}



void repass::on_Repass_but_clicked()
{
    QString pass, Repass, login, test;
    QString msg = "ERROR";
    pass = ui->pass->text();
    Repass = ui->repass_2->text();
    login = ui->login->text();
    qDebug()<<pass<<Repass;
    if(pass == Repass){
        QSqlTableModel model;
        model.setTable("table1");
        int count = 0;
        model.setFilter("login=\'"+login+"\'");
        model.select();
        for (int i=0;i<model.rowCount();i++) {
            QSqlRecord record = model.record(i);
            test = record.value("login").toString();
            if(test == login){
                count++;
            }
        }
        if(count == 1){
           QSqlRecord record = model.record(0);
           record.setValue("password", pass);
           model.setRecord(0, record);
           model.submitAll();
        }
        if(count == 0) {
            QMessageBox::warning(this, "warning", msg);
        }
    }
}

