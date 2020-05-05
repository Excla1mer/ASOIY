#include "enter.h"
#include "ui_enter.h"
#include "QTableView"
enter::enter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter)
{
    ui->setupUi(this);
}

enter::~enter()
{
    delete ui;
}

void enter::on_back_clicked() // Возврат в окно авторизации
{
    MainWindow* main = new MainWindow;
    main->setWindowTitle("Sing_in");
    main->show();
    this->hide();
}

void enter::on_search_clicked() // Нажатие на кнопку Search
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("table2");
    model->select();
    QString FIO = ui->FIO->text();
    QString position = ui->position->text();
    model->submitAll();
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("FIO"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Position"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ZP"));

    if(FIO != "by FIO") { // Проверка поля поиска по FIO
        model->setFilter("FIO=\'"+FIO+"\'");
        model->select();
    }
    if(position != "by position") { //Проверка поля поиска по position
        model->setFilter("Position=\'"+position+"\'");
        model->select();
    }
    ui->tableView->setModel(model);
}

void enter::on_cancel_clicked() // Нажатие на кнопку Cansel
{
    ui->tableView->clearMask();
    ui->FIO->setText("by FIO");
    ui->position->setText("by position");
}
