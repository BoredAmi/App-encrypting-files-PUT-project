#ifndef REGISTRATIONO_H
#define REGISTRATIONO_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class RegistrationO;
}

class RegistrationO : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistrationO(QWidget *parent = nullptr);
    ~RegistrationO();

private slots:
    void on_BackB_clicked();

    void on_RegisterB_clicked();

private:
    Ui::RegistrationO *ui;
};

#endif // REGISTRATIONO_H
