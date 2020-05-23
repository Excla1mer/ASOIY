#ifndef ENTER_H
#define ENTER_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class enter;
}

class enter : public QDialog
{
    Q_OBJECT

public:
    explicit enter(QWidget *parent = nullptr);
    ~enter();

private slots:
    void on_back_clicked();

    void on_search_clicked();

    void on_cancel_clicked();

    void on_picture_linkActivated(const QString &link);

    void on_picture_windowIconChanged(const QIcon &icon);

    void on_picture_destroyed();

    void on_tableView_clicked(const QModelIndex &index);

    void on_DB_clicked();

private:
    Ui::enter *ui;
    QSqlTableModel *model_1 = new QSqlTableModel;
};

#endif // ENTER_H
