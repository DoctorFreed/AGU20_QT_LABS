#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget"
#include <QRandomGenerator>
#include <QMessageBox>
QSize screenSize;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < ui->table_sum->rowCount();i++ )
    {
        for (int j = 0; j < ui->table_sum->columnCount(); j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem("0");
            ui->table_sum->setItem(i,j,itm);

        }
    }
    MainWindow::showFullScreen();
    screenSize = MainWindow::size();
    MainWindow::showNormal();
    //qsrand(QTime::currentTime().msecsSinceStartOfDay());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_answer_clicked()
{
    if(ui->list_answer->currentItem()->text() == "Земля")
    {
        ui->lb_correct->setText("Верно!");
    }
    else
    {
        ui->lb_correct->setText("Не верно!");
    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_bt_sum_clicked()
{
    int sum = 0;
    for (int i = 0; i < ui->table_sum->rowCount();i++ )
    {
        for (int j = 0; j < ui->table_sum->columnCount(); j++)
        {
           sum += ui->table_sum->item(i,j)->text().toInt();
        }
    }
    ui->label_sum->setText("Сумма = " + QString::number(sum));

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 0)
    {
        MainWindow::setWindowTitle("Задание 1");
        ui->centralwidget->setGeometry(0,0,558,294);
        MainWindow::setGeometry(screenSize.width()/2 - MainWindow::size().width()/2,screenSize.height()/2 - MainWindow::size().height()/2,558,294);
    }
    if (index == 1)
    {
        MainWindow::setWindowTitle("Задание 2");
        ui->centralwidget->setGeometry(0,0,558,294);
        MainWindow::setGeometry(screenSize.width()/2 - MainWindow::size().width()/2,screenSize.height()/2 - MainWindow::size().height()/2,558,294);
    }

    if(index == 2)
    {
        MainWindow::setWindowTitle("Задание 3");
        ui->centralwidget->setGeometry(0,0,355,196);
        MainWindow::setGeometry(screenSize.width()/2 - MainWindow::size().width()/2,screenSize.height()/2 - MainWindow::size().height()/2,355,196);
    }
    if(index == 3)
    {
        MainWindow::setWindowTitle("Задание 4");
        ui->centralwidget->setGeometry(0,0,777,736);
        MainWindow::setGeometry(screenSize.width()/2 - MainWindow::size().width()/2,screenSize.height()/2 - MainWindow::size().height()/2,777,736);
    }
}

void MainWindow::on_bt_num_clicked()
{
    if(ui->cb_num->currentIndex() == 0)
    {
        int k = 0;
        for (int i = 0; i < ui->tb_num->rowCount();i++)
        {
            for (int j = 0; j < ui->tb_num->columnCount();j++)
            {
                k++;
                QTableWidgetItem *itm = new QTableWidgetItem(QString::number(k*k));
                ui->tb_num->setItem(i,j,itm);

            }
        }
    }
    if(ui->cb_num->currentIndex() == 1)
    {
        int k = 0;
        for (int i = 0; i < ui->tb_num->rowCount();i++)
        {
            for (int j = 0; j < ui->tb_num->columnCount();j++)
            {
                k++;
                QTableWidgetItem *itm = new QTableWidgetItem(QString::number(k*k*k));
                ui->tb_num->setItem(i,j,itm);

            }
        }
    }
    if(ui->cb_num->currentIndex() == 2)
    {
        int k = 0;
        for (int i = 0; i < ui->tb_num->rowCount();i++)
        {
            for (int j = 0; j < ui->tb_num->columnCount();j++)
            {
                k++;
                QTableWidgetItem *itm = new QTableWidgetItem(QString::number(k));
                ui->tb_num->setItem(i,j,itm);

            }
        }
    }

}

void MainWindow::on_bt_addrow_tb1_clicked()
{
    ui->tb_sum_one->insertRow(ui->tb_sum_one->rowCount());
    on_bt_random_tb1_clicked();
}

void MainWindow::on_bt_addcol_tb1_clicked()
{
    ui->tb_sum_one->insertColumn(ui->tb_sum_one->columnCount());
    on_bt_random_tb1_clicked();
}

void MainWindow::on_bt_delrow_tb1_clicked()
{
    ui->tb_sum_one->setRowCount(ui->tb_sum_one->rowCount() - 1);
}

void MainWindow::on_bt_delcol_tb1_clicked()
{
    ui->tb_sum_one->setColumnCount(ui->tb_sum_one->columnCount() - 1);
}

void MainWindow::on_bt_addrow_tb2_clicked()
{
    ui->tb_sum_two->insertRow(ui->tb_sum_two->rowCount());
    on_bt_random_tb2_clicked();
}

void MainWindow::on_bt_addcol_tb2_clicked()
{
    ui->tb_sum_two->insertColumn(ui->tb_sum_two->columnCount());
    on_bt_random_tb2_clicked();
}

void MainWindow::on_bt_delrow_tb2_clicked()
{
    ui->tb_sum_two->setRowCount(ui->tb_sum_two->rowCount() - 1);
}

void MainWindow::on_bt_delcol_tb1_2_clicked()
{
    ui->tb_sum_two->setColumnCount(ui->tb_sum_two->columnCount() - 1);
}

void MainWindow::on_bt_random_tb1_clicked()
{
    for (int i = 0; i < ui->tb_sum_one->rowCount();i++)
    {
        for (int j = 0; j < ui->tb_sum_one->columnCount();j++)
        {

            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(QRandomGenerator::global()->generate()%100+1));
            ui->tb_sum_one->setItem(i,j,itm);

        }
    }
}

void MainWindow::on_bt_random_tb2_clicked()
{
    for (int i = 0; i < ui->tb_sum_two->rowCount();i++)
    {
        for (int j = 0; j < ui->tb_sum_two->columnCount();j++)
        {

            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(QRandomGenerator::global()->generate()%100+1));
            ui->tb_sum_two->setItem(i,j,itm);

        }
    }
}

void MainWindow::on_bt_sum_matrix_clicked()
{
    if(ui->tb_sum_one->columnCount() != ui->tb_sum_two->columnCount() || ui->tb_sum_one->rowCount() != ui->tb_sum_two->rowCount() )
    {
        QMessageBox::warning(this, "Внимание", "Мартицы должны быть одноразмерными!");
        return;
    }
    ui->tb_all->setColumnCount(ui->tb_sum_one->columnCount());
    ui->tb_all->setRowCount(ui->tb_sum_one->rowCount());

    for (int i = 0; i < ui->tb_all->rowCount();i++)
    {
        for (int j = 0; j < ui->tb_all->columnCount();j++)
        {

            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(ui->tb_sum_one->item(i,j)->text().toInt() + ui->tb_sum_two->item(i,j)->text().toInt()));
            ui->tb_all->setItem(i,j,itm);

        }
    }
}

