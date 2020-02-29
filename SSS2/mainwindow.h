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

public slots:
    void calend_D();
    void lcd_N();
    void logo();

};

#endif // MAINWINDOW_H
