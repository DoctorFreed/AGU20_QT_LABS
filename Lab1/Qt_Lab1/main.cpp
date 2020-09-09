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
