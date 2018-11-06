#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void data_collect(void);

    void start(void);

    void init(void);

private slots:
    void on_Data_collect_clicked();

    void on_Start_clicked();

    void on_Init_clicked();

    void timerUpdate();

    void on_Speed_up_clicked();

    void on_Speed_down_clicked();

    void on_Epos_up_clicked();

    void on_Epos_down_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
