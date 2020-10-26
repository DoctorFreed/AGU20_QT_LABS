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
    void on_bt_answer_clicked();

    void on_pushButton_clicked();

    void on_bt_sum_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_bt_num_clicked();

    void on_bt_addrow_tb1_clicked();

    void on_bt_addcol_tb1_clicked();

    void on_bt_delrow_tb1_clicked();

    void on_bt_delcol_tb1_clicked();

    void on_bt_addrow_tb2_clicked();

    void on_bt_addcol_tb2_clicked();

    void on_bt_delrow_tb2_clicked();

    void on_bt_delcol_tb1_2_clicked();

    void on_bt_random_tb1_clicked();

    void on_bt_random_tb2_clicked();

    void on_bt_sum_matrix_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
