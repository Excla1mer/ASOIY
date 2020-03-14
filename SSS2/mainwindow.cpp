#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QString>
#include <QPalette>
#include <QColorDialog>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionDisplay, SIGNAL(triggered(bool)), this, SLOT(lcd_N()));
    QObject::connect(ui->actionCalendar, SIGNAL(triggered(bool)), this, SLOT(calend_D()));
    QObject::connect(ui->actionAuthor, SIGNAL(triggered(bool)), this, SLOT(logo()));
    QObject::connect(ui->actionCreate_File, SIGNAL(triggered(bool)), this, SLOT(newFile()));
    QObject::connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    QObject::connect(ui->actionOpen_File, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    QObject::connect(ui->spinBox, SIGNAL(valeChanged(int)), this, SLOT(setTimeForAutosave()));
    timer->start(ui->spinBox->value()*1000);
    QObject::connect(timer, SIGNAL(timeout()),this, SLOT(autosave()));
    ui->progressBar->setValue(0);
    QObject::connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)), ui->textEdit,SLOT(setCurrentFont(QFont)));

ui->pushButton->setToolTip("Sets current date");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calend_D()
{
    //this->hide();
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
    ui->actionSave->setEnabled(true);

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
    ui->progressBar->setValue(0);
    file_name=QFileDialog::getSaveFileName(this,tr("Save file ..."),"",tr("Text file(*.txt);; All files(*.*)"));
    QFile file(file_name);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    str=ui->textEdit->toPlainText();
    str=str+"\n\n";
    QTextStream writeStream(&file);
    writeStream<<str;
    file.close();
    ui->textEdit->setText(str);
    ui->lineEdit->setText(file_name);
    for (int i=0;i<=100;i++) {
        ui->progressBar->setValue(i);
    }
    ui->actionSave->setEnabled(1);
    ui->progressBar->setValue(0);
}

void MainWindow::openFile()
{
    ui->actionSave->setEnabled(true);
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
    ui->progressBar->setValue(0);
}

void MainWindow::autosave()
{
    QString _str = ui->textEdit->toPlainText();
    if(_str.size() == 0) { return; }
    ui->statusBar->clearMessage();

    QTemporaryFile tmpFile;
    tmpFile.setAutoRemove(true);
    tmpFile.open();
    QTextStream writeStream(&tmpFile);
    writeStream<<ui->textEdit->toPlainText();

    for (int i=0; i<=101; i++) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        ui->progressBar->setValue(i);
    }
    tmpFile.close();
    ui->statusBar->showMessage("Saving to tmpFile" + tmpFile.fileName() + " " + QString::number(ui->spinBox->value()) + "sec");
    ui->progressBar->reset();
}

void MainWindow::setTimeForAutosave()
{

    if(ui->spinBox->value() == 0) {
        timer->stop();
        return;
    }
    timer->start(ui->spinBox->value()*1000);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->setTextColor(QColorDialog::getColor());
    ui->spinBox->setToolTip("Sets text color");
}

void MainWindow::on_pushButton_clicked()
{
    Dialog gd;
    ui->textEdit->append(gd.sDate());


}
