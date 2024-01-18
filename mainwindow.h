#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql>
#include <QFileInfo>
#include "encup.h"
#include "registrationo.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginB_clicked();

    void on_RegisterB_clicked();

    void on_StartB_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase myDB;
};
#endif // MAINWINDOW_H
