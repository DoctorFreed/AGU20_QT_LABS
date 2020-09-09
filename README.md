
# Лабораторные по предмету ПОАСНИ
____

Лабораторная 1 :white_check_mark:
-----------

**Написать приложение, которое выведет ваше «Имя Фамилия – студент 4 курса».**

![Лабораторная 1](img_labs/lab1.png)

Файл main.cpp
```c++
#include "mainwindow.h"
#include <QtWidgets/QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl("Роман Босенко - студент 4 курса");
    lbl.show();
    return a.exec();
}
```
____
Лабораторная 2 :white_check_mark:
-----------

**Задания для самостоятельной работы:**
- [X] Изменить пример таким образом, чтобы при нажатии на кнопку происходило уменьшение значения на 2. Если достигает -10, то выход из программы.
- [X] Добавить еще одну кнопку, которая увеличивает на 2, если достигло 10, то выход из программы.
- [X] Написать приложение с кнопкой и текстовым полем QLineEdit. При нажатии на кнопку текст, введенный в поле, должен появиться в заголовке программы.

![Лабораторная 2](img_labs/lab2.png)

Файл mainwindow.cpp
```c++
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

void MainWindow::on_pushButtonTitle_clicked()
{
    QString title = ui->lineEdit->text();
    this->setWindowTitle(title);
}
```
