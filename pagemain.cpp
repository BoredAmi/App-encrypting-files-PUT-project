#include "pagemain.h"
#include "ui_pagemain.h"
#include <QFileDialog>
#include <QMainWindow>

PageMain::PageMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PageMain)
{
    ui->setupUi(this);
}

PageMain::~PageMain()
{
    delete ui;
}
