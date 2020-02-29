#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionDisplay, SIGNAL(triggered(bool)), this, SLOT(lcd_N()));
    QObject::connect(ui->actionCalendar, SIGNAL(triggered(bool)), this, SLOT(calend_D()));
    QObject::connect(ui->actionAuthor, SIGNAL(triggered(bool)), this, SLOT(logo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calend_D()
{
    this->hide();
    Dialog* Calendar = new Dialog();
    Calendar->setWindowTitle("Calendar");
    Calendar->show();
}

void MainWindow::lcd_N()
{
    QLabel *lbl= new QLabel;
    QLabel *lab = new QLabel;
    QHBoxLayout *layout = new QHBoxLayout;
    Lcd = new QLCDNumber;
    Lcd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    VSlider = new QSlider;
    layout->addWidget(Lcd);
    layout->addWidget(VSlider);
    layout->addWidget(lab);
    lbl->setGeometry(600, 285,500,100);
    lab->setText(QString("<h1><u><i><font color=red>Otkritka</i></u></h1>"));
    lbl->setLayout(layout);
    lbl->show();
    connect(VSlider, SIGNAL(valueChanged(int)), Lcd, SLOT(display(int)));
}

void MainWindow::logo()
{
    this->hide();
    authors* Logo = new authors();
    Logo->setWindowTitle("Logo");
    Logo->show();
}
