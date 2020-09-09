
# Лабораторные по предмету ПОАСНИ
[:white_check_mark: Лабораторная 1](#лабораторная-1-white_check_mark)
[:white_check_mark: Лабораторная 2](#лабораторная-2-white_check_mark)
[:white_check_mark: Лабораторная 3](#лабораторная-2-white_check_mark)
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
____
Лабораторная 3 :white_check_mark:
-----------

**Задания для самостоятельной работы:**
- [X] Создать надпись, которая содержит HTML-разметку с заголовком H2 «Имя Фамилия» заголовком H3 «Группа».
- [x] Создать надпись, которая отображает значение индикатора прогресса.
- [X] Создать два индикатора прогресса. Первый от 0 до 10, второй увеличивается после достижения первым значения 10 (максимум также 10).
- :raising_hand: Добавил от себя кнопку автошага, ибо кликать слишком много :see_no_evil:

![Лабораторная 3](img_labs/lab3.png)

Файл mainwindow.cpp
```c++
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

```