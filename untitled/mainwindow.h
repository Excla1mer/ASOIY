#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QtSql>
#include <QSql>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QFileInfo>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "sing_up.h"
#include <qsqltablemodel.h>
#include "repass.h"
#include "enter.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Clear_clicked();

    void on_Enter_clicked();

    void on_Sign_up_clicked();

    void on_Kode_button_clicked();

    void on_Key_enter_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase myDB;
    bool Kode = false;
};
#endif // MAINWINDOW_H
