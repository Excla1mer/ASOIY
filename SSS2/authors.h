#ifndef AUTHORS_H
#define AUTHORS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class authors;
}

class authors : public QDialog
{
    Q_OBJECT

public:
    explicit authors(QWidget *parent = nullptr);
    ~authors();

private:
    Ui::authors *ui;

protected:
    virtual void closeEvent(QCloseEvent *event);
};

#endif // AUTHORS_H
