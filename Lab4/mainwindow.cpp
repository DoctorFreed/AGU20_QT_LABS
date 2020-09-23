#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QTime>
#include <QDate>
#include <QTextStream>

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


void MainWindow::on_bt_to_PDF_clicked()
{

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Файл PDF"), "", tr("Файлы PDF (*.pdf)"));
    if (fileName.isEmpty()) return;
    printer.setOutputFileName(fileName);
    ui->text_print->print(&printer);
    QMessageBox::information(this, "Отлично!", "Экспорт прошел успешно, по пути : " + fileName);

}

void MainWindow::on_bt_to_ODF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Файл ODF"),"",tr("Файлы ODF (*.odf)"));
    if (fileName.isEmpty()) return;
    QTextDocumentWriter writer(fileName);
    bool success = writer.write(ui->text_print->document());
    if (success)
    {
      QMessageBox::information(this, "Отлично!", "Экспорт прошел успешно, по пути : " + fileName);
    }
    else
    {
      QMessageBox::critical(this, "Ошибка", "При сохранении файла произошла ошибка");
    }
}

void MainWindow::on_bt_reset_clicked()
{
    ui->text_print->setText("");
}

void MainWindow::on_bt_create_text_clicked()
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    ui->text_create->setHtml("<html>"
                             "<body>"
                             "<p>Сегодня: " + date.toString()+
                             "</p>"
                             "<p>Время: " + time.toString("hh")+
                             " часов " + time.toString("mm") +
                             " минуты</p>"
                             "<p>" + tr("<img src = C:\\IMG.PNG width=\"189\" height=\"255\">")+
                             "</p>"
                             "</body>"
                             "</html>");
}

void MainWindow::on_bt_date_clicked()
{
    QDate date = ui->dateTimeEdit->date();
    ui->sBox_day->setValue(date.day());
    ui->sBox_month->setValue(date.month());
    ui->sBox_year->setValue(date.year());

}
