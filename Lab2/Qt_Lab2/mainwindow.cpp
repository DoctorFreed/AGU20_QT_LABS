#include "mainwindow.h"
#include "ui_mainwindow.h"
int count = 0;
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


void MainWindow::on_pushButtonAdd_clicked()
{
    count += 2;
    ui->label->setText(QString::number(count));
    if(count == 10)
    {
        exit(0);
    }


}

void MainWindow::on_pushButtonLess_clicked()
{
    count -= 2;
    ui->label->setText(QString::number(count));
    if(count == -10)
    {
        exit(0);
    }

}
