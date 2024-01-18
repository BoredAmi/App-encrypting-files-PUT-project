#ifndef ENCUP_H
#define ENCUP_H

#include <QMainWindow>
#include <encrytpionbyaes.h>

namespace Ui {
class encup;
}

class encup : public QMainWindow
{
    Q_OBJECT

public:
    explicit encup(QWidget *parent = nullptr);
    ~encup();

private slots:
    void on_Add_clicked();

    void on_Add_2_clicked();

    void on_dec_clicked();

private:
    Ui::encup *ui;
};

#endif // ENCUP_H
