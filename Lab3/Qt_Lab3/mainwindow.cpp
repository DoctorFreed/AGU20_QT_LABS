#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lbName->setText("<h2>Босенко Роман</h2> <h3>Группа 4ИВТ</h3>");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btStep_clicked()
{
    ui->pB_Second->setValue(ui->pB_Second->value() + 1);
    if(ui->pB_Second->value() == 10)
    {
        ui->pb_First->setValue(ui->pb_First->value() + 1);
        ui->pB_Second->setValue(0);
    }
    if(ui->pb_First->value() == 10)
    {
        ui->pb_First->setValue(0);
        ui->lcdInc->display(ui->lcdInc->value() + 1);
    }

}

void MainWindow::on_btResetSecond_clicked()
{
    ui->pB_Second->setValue(0);
}

void MainWindow::on_btResetFirst_clicked()
{
    ui->pb_First->setValue(0);
}


void MainWindow::on_bt_Auto_clicked()
{
    for (int i = 0;i < 100;i++ ) {
        on_btStep_clicked();
    }
}
