#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sklpog.h"
#include <QMessageBox>
#include <QString>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginB_clicked()
{
    QString Login = ui->login->text();
    QString Password = ui->passw->text();
    std::string tableName = "Loginy";
    QString file="tabelki.db";
    std::string dbPath = "/home/ami/coding/Bruh/MojaApka/tabelki.db";
    std::string stdLogin = Login.toStdString();
    std::string stdPassword = Password.toStdString();

    if (checkLoginAndPassword(tableName, stdLogin, stdPassword, dbPath)) {
        QMessageBox::information(this,"AutoCrypt","Succes");
        this->hide();
        encup *encix =new encup();
        encix->show();
    } else {
        QMessageBox::warning(this,"AutoCrypt","Invalid login or password");
    }

}


void MainWindow::on_RegisterB_clicked()
{
    this->hide();
    RegistrationO *regi =new RegistrationO();
    regi->show();
}


void MainWindow::on_StartB_clicked()
{


}

