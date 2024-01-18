#include "registrationo.h"
#include "ui_registrationo.h"
#include "sklpog.h"
#include <QMessageBox>
#include <regex>
#include <httplib.h>


RegistrationO::RegistrationO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegistrationO)
{
    ui->setupUi(this);
}

RegistrationO::~RegistrationO()
{
    delete ui;
}

void RegistrationO::on_BackB_clicked()
{
    this->hide();
    MainWindow *maini =new MainWindow();
    maini->show();
}


void RegistrationO::on_RegisterB_clicked()
{
    QString Email = ui->email->text();
    QString Login = ui->login->text();
    QString Password = ui->passw->text();
    std::string tableName = "Loginy";
    std::string dbPath = "/home/ami/coding/Bruh/MojaApka/tabelki.db";
    std::string stdEmail = Email.toStdString();
    std::string stdLogin = Login.toStdString();
    std::string stdPassword = Password.toStdString();
    std::regex emailPattern("^[\\w\\.-]+@[a-zA-Z\\d\\.-]+\\.[a-zA-Z]{2,}$");
    if(std::regex_match(stdEmail, emailPattern))
    {
        if(Login.length()>3 && Login.length()<15)
        {
            if(checkPassword(stdPassword))
            {
                if (createAccount(tableName,stdEmail, stdLogin, stdPassword, dbPath)) {
                    QMessageBox::information(this,"AutoCrypt","Account created succesfully");
                } else {
                    QMessageBox::warning(this,"AutoCrypt","Error creating account");
                }
            }
            else
            {
                QMessageBox::warning(this,"AutoCrypt","Password have to conatin at least one: uppercase letter, lowercase letter, number and special symbol");
            }
        }
        else
        {
            QMessageBox::warning(this,"AutoCrypt","Logins must be between 3 and 15 characters");
        }
    }
    else
    {
        QMessageBox::warning(this,"AutoCrypt","Wrong email");
    }
}

