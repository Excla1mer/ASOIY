#include "mainwindow.h"
#include "ui_mainwindow.h"
#define Path_to_DB "C:/Users/Darks/Desktop/mydatabase.sqlite"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo chFile(Path_to_DB);
    if(chFile.isFile())
    {
        if(myDB.open())
            ui->Result->setText("Connect yes");
        else
            ui->Result->setText("Connect not");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<"closing the connection";
    myDB.close();
}


void MainWindow::on_Clear_clicked()
{
    ui->Login->clear();
    ui->Password->clear();
    ui->Result->clear();
}


void MainWindow::on_Enter_clicked()
{
    QString UserName, Login, Password;
    Login=ui->Login->text();
    Password=ui->Password->text();

    if (!myDB.isOpen())
    {
        qDebug()<<"BD not open";
        return;
    }
    QSqlQuery query;
    query.exec("SELECT FIO,login, password, Role FROM table1");
    while(query.next()) {
        QString login = query.value(1).toString();
        QString password  = query.value(2).toString();
        QString Role = query.value(3).toString();
        QString FIO = query.value(0).toString();
        qDebug()<< "|"<<FIO<<"|"<<login<<"|"<<password<<"|"<<Role<<"|";
    }
    if(query.exec("SELECT FIO,login, password, Role FROM table1 WHERE login=\'"+Login+"\'AND password=\'"+Password+"\'")) {
        int count = 0;

        while(query.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->Result->setText("Success!!!");
            query.exec("SELECT FIO,login, password, Role FROM table1 WHERE login=\'"+Login+"\'AND password=\'"+Password+"\'");
            query.first();
            QString FIO = query.value(0).toString();
            QString str = "UserName="+FIO+"\n"+
                            "Login="+query.value(1).toString()+"\n"+
                            "Password="+query.value(2).toString()+"\n"+
                            "Role="+query.value(3).toString();
            enter* Enter = new  enter;
            Enter->setWindowTitle("Enter"); //  Вход в окно с отображнием бд
            Enter->show();
            this->hide();
        }
        if(count > 1) {
            ui->Result->setText("Duplicate!!!");
        }
        if(count == 0)
        {
            ui->Result->setText("Wrong  login or password");
        }
    }
}

void MainWindow::on_Sign_up_clicked()
{
    Sing_up* sing_up  =  new  Sing_up;
    sing_up->setWindowTitle("Sing up");
    sing_up->show();
}

void MainWindow::on_Kode_button_clicked()
{
    ui->Kode_edit->setEnabled(true);
    ui->label_3->setEnabled(true);
    Kode = true;
}

void MainWindow::on_Key_enter_clicked()
{
    int count = 0;
    if(Kode == true) {
        QString Kode = ui->Kode_edit->text();
        QString Login=ui->Login->text();
        qDebug()<<Kode << Login;
        QSqlQuery query;
        query.exec("SELECT login, Kode FROM table1 WHERE login=\'"+Login+"\'AND Kode=\'"+Kode+"\'");
        while(query.next()){
           count++;
        }
        if(count == 1){
            repass* Repass = new repass;
            Repass->setWindowTitle("Repass");
            Repass->show();
        }
    }
}
