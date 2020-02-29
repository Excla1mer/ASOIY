#ifndef LOGO_H
#define LOGO_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class logo;
}

class logo : public QDialog
{
    Q_OBJECT

public:
    explicit logo(QWidget *parent = nullptr);
    ~logo();

private slots:
    void on_logo_accepted();

    void on_logo_windowIconChanged(const QIcon &icon);

private:
    Ui::logo *ui;

};

#endif // LOGO_H
