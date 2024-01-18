#include "encup.h"
#include "ui_encup.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <encrytpionbyaes.h>
std::vector<FileCryptor>instances;

encup::encup(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::encup)
{
    ui->setupUi(this);
}

encup::~encup()
{
    delete ui;
}

void encup::on_Add_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Choose a file",QDir::homePath());
    std::string stdpath= path.toStdString();
    FileCryptor nowa_instancja(stdpath);
    instances.push_back(nowa_instancja);
    ui->label->setText(path);
}


void encup::on_Add_2_clicked()
{
    int j = static_cast<int>(instances.size());
    if(j==0)
    {
        QMessageBox::warning(this,"AutoCrypt","add files pls");
    }
    else
    {
        for (int i = 0; i < j;i++)
        {
            instances[i].encrypt();
        }
        QMessageBox::warning(this,"AutoCrypt","encrypted succesfuly");
    }
}


void encup::on_dec_clicked()
{
    int j = static_cast<int>(instances.size());
    if(j==0)
    {
        QMessageBox::warning(this,"AutoCrypt","add files pls");
    }
    else
    {
        for (int i = 0; i < j;i++)
        {
            instances[i].decrypt();
        }
        QMessageBox::warning(this,"AutoCrypt","decrypted succesfuly");
    }
}

