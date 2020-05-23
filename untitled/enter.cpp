#include "enter.h"
#include "ui_enter.h"
#include "QTableView"
#include "QStandardItemModel"
#include "QTableWidgetItem"
enter::enter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter)
{
    ui->setupUi(this);

    //QSqlTableModel *model_1= new QSqlTableModel();

    model_1->setTable("table2");
    model_1->select();
    int m=model_1->rowCount();
    qDebug()<<m;
    model_1->submitAll();
    model_1->setHeaderData(0, Qt::Horizontal, QObject::tr("Numb"));
    model_1->setHeaderData(1, Qt::Horizontal, QObject::tr("FIO"));
    model_1->setHeaderData(4, Qt::Horizontal, QObject::tr("Photo"));
    ui->tableView->setModel(model_1);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
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

    //QStandardItemModel *mod = new  QStandardItemModel;
    model->setTable("table2");
    model->select();
    QString FIO = ui->FIO->text();
    QString position = ui->position->text();
    model->submitAll();
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("FIO"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Position"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ZP"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Photo"));

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



void enter::on_tableView_clicked(const QModelIndex &index)
{
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData(model_1->data(model_1->index(index.row(),4)).toByteArray());
    //qDebug()<< model_1->data(model_1->index(index.row(),4));
    ui->picture->setPixmap(outPixmap);

}


void enter::on_DB_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM table2");
    QStandardItemModel *mod = new QStandardItemModel;
    QStandardItem *item;
    QStringList horizontalHeader;
    horizontalHeader.append("Numb");
    horizontalHeader.append("FIO");
    horizontalHeader.append("Position");
    horizontalHeader.append("ZP");
    horizontalHeader.append("Photo");
    mod->setHorizontalHeaderLabels(horizontalHeader);
    QStringList verticalHeader;
    QString st="";
    int i=0;
    while(query.next()) {
        st="";
        QString  NUM=query.value(0).toString();
        QString  FIO=query.value(1).toString();
        QString  Position=query.value(2).toString();
        QString  ZP=query.value(3).toString();
        QString  P_name=query.value(5).toString();
        item=new  QStandardItem(NUM);
        mod->setItem(i, 0, item);
        item=new  QStandardItem(FIO);
        mod->setItem(i, 1, item);
        item=new  QStandardItem(Position);
        mod->setItem(i, 2, item);
        item=new  QStandardItem(ZP);
        mod->setItem(i, 3, item);
        QModelIndex index=mod->index(i,4);
        mod->setData(index, "D:\\пикчи\\"+P_name+".jpg",  Qt::DisplayRole);
        mod->setData(index,QIcon("D:\\пикчи\\"+P_name+".jpg"), Qt::DecorationRole);
        i++;
    }
    QTableView *view= new QTableView;
    view->setModel(mod);
    view->setAlternatingRowColors(true);
    view->resizeRowsToContents();
    view->resizeColumnsToContents();
    view->setAlternatingRowColors(true);
    view->show();

}
