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
    void on_bt_to_PDF_clicked();

    void on_bt_to_ODF_clicked();

    void on_bt_reset_clicked();

    void on_bt_create_text_clicked();

    void on_bt_date_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
