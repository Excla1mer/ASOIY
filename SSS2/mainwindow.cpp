#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QTextStream>
#include <QMessageBox>
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

void MainWindow::newFile()
{
    ui->textEdit->setEnabled(true);
}

void MainWindow::saveFile()
{
    if(first_save)
    {
        first_save = false;
        file_name = QFileDialog::getSaveFileName(this, tr("SAve file"), "", tr("Text file (*.txt);;(*.doc)"));
        saveFile();
    }
    else {
        QFile *file = new QFile(file_name);
        if(!file->open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"), file->errorString());
            return;
        }
        QTextStream out(file);
        out <<ui->textEdit->toPlainText();
        ui->lineEdit->setText(file_name);
        ui->actionSave->setEnabled(1);
    }
}

void MainWindow::saveAsFile()
{

}

void MainWindow::openFile()
{
    ui->progressBar->setValue(0);
    ui->textEdit->setEnabled(true);
    file_name = QFileDialog::getOpenFileName(0, "Open File", "/home/ts317c8/1", tr("Text file(*.txt);;All files(*.*"));
    QFile file(file_name);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream readStream(&file);
    ui->textEdit->clear();
    while(!readStream.atEnd()) {
        ui->textEdit->setText(ui->textEdit->toPlainText()+readStream.readLine()+"\n");
    }
    file.close();
    ui->lineEdit->setText(file_name);
    ui->actionSave->setEnabled(1);

    for(int i = 0; i <= 100; i++)
    {
        ui->progressBar->setValue(i);
    }

}

void MainWindow::autosave()
{

}
