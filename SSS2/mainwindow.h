#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QLCDNumber>
#include <QSlider>
#include <dialog.h>
#include <authors.h>
#include <QTimer>
#include "dialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLCDNumber *Lcd;
    QSlider *VSlider;
    QString file_name;
    bool first_save;
    QString str;
    QTimer *timer = new QTimer(this);

public slots:
    void calend_D();
    void lcd_N();
    void logo();
    void newFile();
    void saveFile();
    void saveAsFile();
    void openFile();
    void autosave();
    void setTimeForAutosave();
    void on_pushButton_date_clicked();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
