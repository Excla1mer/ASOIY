#include "sing_up.h"
#include "ui_sing_up.h"
#include <QMessageBox>
#include  "QFileDialog"
Sing_up::Sing_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sing_up)
{
    ui->setupUi(this);

}

Sing_up::~Sing_up()
{
    delete ui;
}

void Sing_up::on_Close_clicked()
{
    this->close();
}

void Sing_up::on_Input_clicked()
{
    QString FIO, login, password, re_password, role, kode, Photo;
    QString test;
    QString DATA =  "4.18.2020";
    QString msg =  "Invalid pass  or login :(";
    int count = 0;
    bool Flag = false;
    FIO = ui->FIO->text();
    login = ui->Login->text();
    password = ui->password->text();
    re_password = ui->re_password->text();
    role = ui->role->currentText();
    kode = ui->key_word->text();
    Photo = ui->upload_photo->text();
    QSqlTableModel model;
    QSqlTableModel model1;
    model.setTable("table1");
    model.select();
    if(password ==  re_password)
        Flag  = true;
    for (int i = 0;i <  model.rowCount();i++) {
        QSqlRecord record = model.record(i);
        test = record.value("login").toString();
        if(test == login){
            count++;
        }
    }
    if(count == 0 and Flag == true){
        model.insertRows(0, 1);
        model.setData(model.index(0, 1), FIO);
        model.setData(model.index(0, 2), DATA);
        model.setData(model.index(0, 3), login);
        model.setData(model.index(0, 4), password);
        model.setData(model.index(0, 5), kode);
        model.setData(model.index(0, 6), role);
        model.submitAll();
    }
    if(count > 0) {
        QMessageBox::warning(this, "warning", msg);
    }
    qDebug()<<"count="<<count;


}

void Sing_up::on_upload_button_clicked()
{
    QString foto;
    foto=QFileDialog::getOpenFileName(0,"ВЫбор фото ...", QDir::homePath(), tr("*.png;; *.jpg;;*.gif;;*.bmp"));
        if (foto.isEmpty())
        {
            return; //  выйти из метода
        }
        else{
        ui->upload_photo->setPixmap(QPixmap::fromImage(QImage(foto)).scaled(300,200));
        }
    //    ui->lblFoto->setPixmap(QPixmap::fromImage(QImage("../Project/xx.png")));

}
