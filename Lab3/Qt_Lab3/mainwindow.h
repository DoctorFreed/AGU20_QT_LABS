#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btStep_clicked();

    void on_btResetSecond_clicked();

    void on_btResetFirst_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_bt_Auto_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H