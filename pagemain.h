#ifndef PAGEMAIN_H
#define PAGEMAIN_H
#include <QFileDialog>
#include <QMainWindow>

namespace Ui {
class PageMain;
}

class PageMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit PageMain(QWidget *parent = nullptr);
    ~PageMain();

private slots:
    void on_pushButton_2_clicked();

    void on_Adde_clicked();

private:
    Ui::PageMain *ui;
};

#endif // PAGEMAIN_H
