#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <QTimer>
#include "../serial_port/inc/serial_port.h"
#include "../start_up/inc/start_up.h"
#include "../init/inc/init.h"
#include "../socket/inc/server.h"
#include "../socket/inc/pack_unpack.h"
#include "../globalvar/inc/globalvar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerUpdate);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//distribute a thread for socket waiting client to connect
//when a client to connect, distribute another thread to communicate
void MainWindow::on_Init_clicked()
{
//    std::thread _thread_init(&MainWindow::init,this);
//    _thread_init.detach();
    init();
}

void MainWindow::on_Start_clicked()
{
    std::thread _thread_start_up(&MainWindow::start,this);
    _thread_start_up.detach();
}

void MainWindow::on_Data_collect_clicked()
{
    std::thread _thread_data_collect(&MainWindow::data_collect,this);
    _thread_data_collect.detach();
}

void MainWindow::init()
{
    init_sys();
}

void MainWindow::start()
{
    start_up();
}

void MainWindow::data_collect()
{
    INS_collect();
}

void MainWindow::timerUpdate()
{
    ui->lineEdit_1->setText(QString::number(DP_control[0]));
    ui->lineEdit_2->setText(QString::number(DP_control[1]));
    ui->lineEdit_3->setText(QString::number(DP_control[2]));
    ui->lineEdit_4->setText(QString::number(DP_control[3]));
    ui->lineEdit_5->setText(QString::number(DP_control[4]));
    ui->lineEdit_6->setText(QString::number(DP_control[5]));
    ui->lineEdit_7->setText(QString::number(server_sockfd_PLC));
    ui->lineEdit_8->setText(QString::number(server_sockfd_MONITOR));
    ui->DP_control_0->setText(QString::number(DP_control[0]));
    ui->DP_control_1->setText(QString::number(DP_control[1]));
    ui->DP_control_2->setText(QString::number(DP_control[2]));
    ui->DP_control_3->setText(QString::number(DP_control[3]));
    ui->DP_control_4->setText(QString::number(DP_control[4]));
    ui->DP_control_5->setText(QString::number(DP_control[5]));
    ui->DP_control_6->setText(QString::number(DP_control[6]));
    ui->DP_monitor_0->setText(QString::number(DP_monitor[0]));
    ui->DP_monitor_1->setText(QString::number(DP_monitor[1]));
    ui->DP_monitor_2->setText(QString::number(DP_monitor[2]));
    ui->DP_monitor_3->setText(QString::number(DP_monitor[3]));
    ui->DP_monitor_4->setText(QString::number(DP_monitor[4]));
    ui->DP_monitor_5->setText(QString::number(DP_monitor[5]));
    ui->DP_monitor_6->setText(QString::number(DP_monitor[6]));
//    ui->DP_monitor_6->setStyleSheet("color:black");
}

void MainWindow::on_Speed_up_clicked()
{
    DP_control[0] += 100;
    DP_control[2] += 100;
    DP_control[4] += 100;
}

void MainWindow::on_Speed_down_clicked()
{
    DP_control[0] -= 100;
    DP_control[2] -= 100;
    DP_control[4] -= 100;
}

void MainWindow::on_Epos_up_clicked()
{
    DP_control[1] += 30;
    DP_control[3] += 30;
    DP_control[5] += 30;
}

void MainWindow::on_Epos_down_clicked()
{
    DP_control[1] -= 30;
    DP_control[3] -= 30;
    DP_control[5] -= 30;
}
