/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Data_collect;
    QPushButton *Start;
    QPushButton *Init;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Communication_PLC;
    QPushButton *Communication_MONITOR;
    QLineEdit *DP_control_0;
    QLineEdit *DP_control_1;
    QLineEdit *DP_control_2;
    QLineEdit *DP_control_3;
    QLineEdit *DP_control_4;
    QLineEdit *DP_control_5;
    QLineEdit *DP_control_6;
    QLineEdit *DP_monitor_3;
    QLineEdit *DP_monitor_6;
    QLineEdit *DP_monitor_1;
    QLineEdit *DP_monitor_4;
    QLineEdit *DP_monitor_5;
    QLineEdit *DP_monitor_0;
    QLineEdit *DP_monitor_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Speed_up;
    QPushButton *Speed_down;
    QPushButton *Epos_up;
    QPushButton *Epos_down;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(917, 646);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Data_collect = new QPushButton(centralWidget);
        Data_collect->setObjectName(QStringLiteral("Data_collect"));
        Data_collect->setGeometry(QRect(70, 210, 121, 31));
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(70, 260, 121, 31));
        Init = new QPushButton(centralWidget);
        Init->setObjectName(QStringLiteral("Init"));
        Init->setGeometry(QRect(70, 160, 121, 31));
        lineEdit_1 = new QLineEdit(centralWidget);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(690, 410, 70, 25));
        lineEdit_1->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(690, 440, 70, 25));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(590, 500, 70, 25));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(590, 530, 70, 25));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(800, 500, 70, 25));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(800, 530, 70, 25));
        lineEdit_6->setAlignment(Qt::AlignCenter);
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(410, 30, 70, 25));
        lineEdit_7->setAlignment(Qt::AlignCenter);
        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(410, 60, 70, 25));
        lineEdit_8->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 30, 91, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 60, 131, 25));
        Communication_PLC = new QPushButton(centralWidget);
        Communication_PLC->setObjectName(QStringLiteral("Communication_PLC"));
        Communication_PLC->setGeometry(QRect(510, 30, 151, 25));
        Communication_MONITOR = new QPushButton(centralWidget);
        Communication_MONITOR->setObjectName(QStringLiteral("Communication_MONITOR"));
        Communication_MONITOR->setGeometry(QRect(510, 60, 191, 25));
        DP_control_0 = new QLineEdit(centralWidget);
        DP_control_0->setObjectName(QStringLiteral("DP_control_0"));
        DP_control_0->setGeometry(QRect(270, 190, 70, 25));
        DP_control_0->setAlignment(Qt::AlignCenter);
        DP_control_1 = new QLineEdit(centralWidget);
        DP_control_1->setObjectName(QStringLiteral("DP_control_1"));
        DP_control_1->setGeometry(QRect(350, 190, 70, 25));
        DP_control_1->setAlignment(Qt::AlignCenter);
        DP_control_2 = new QLineEdit(centralWidget);
        DP_control_2->setObjectName(QStringLiteral("DP_control_2"));
        DP_control_2->setGeometry(QRect(430, 190, 70, 25));
        DP_control_2->setAlignment(Qt::AlignCenter);
        DP_control_3 = new QLineEdit(centralWidget);
        DP_control_3->setObjectName(QStringLiteral("DP_control_3"));
        DP_control_3->setGeometry(QRect(510, 190, 70, 25));
        DP_control_3->setAlignment(Qt::AlignCenter);
        DP_control_4 = new QLineEdit(centralWidget);
        DP_control_4->setObjectName(QStringLiteral("DP_control_4"));
        DP_control_4->setGeometry(QRect(590, 190, 70, 25));
        DP_control_4->setAlignment(Qt::AlignCenter);
        DP_control_5 = new QLineEdit(centralWidget);
        DP_control_5->setObjectName(QStringLiteral("DP_control_5"));
        DP_control_5->setGeometry(QRect(670, 190, 70, 25));
        DP_control_5->setAlignment(Qt::AlignCenter);
        DP_control_6 = new QLineEdit(centralWidget);
        DP_control_6->setObjectName(QStringLiteral("DP_control_6"));
        DP_control_6->setGeometry(QRect(750, 190, 70, 25));
        DP_control_6->setAlignment(Qt::AlignCenter);
        DP_monitor_3 = new QLineEdit(centralWidget);
        DP_monitor_3->setObjectName(QStringLiteral("DP_monitor_3"));
        DP_monitor_3->setGeometry(QRect(510, 260, 70, 25));
        DP_monitor_3->setAlignment(Qt::AlignCenter);
        DP_monitor_6 = new QLineEdit(centralWidget);
        DP_monitor_6->setObjectName(QStringLiteral("DP_monitor_6"));
        DP_monitor_6->setGeometry(QRect(750, 260, 70, 25));
        DP_monitor_6->setAlignment(Qt::AlignCenter);
        DP_monitor_1 = new QLineEdit(centralWidget);
        DP_monitor_1->setObjectName(QStringLiteral("DP_monitor_1"));
        DP_monitor_1->setGeometry(QRect(350, 260, 70, 25));
        DP_monitor_1->setAlignment(Qt::AlignCenter);
        DP_monitor_4 = new QLineEdit(centralWidget);
        DP_monitor_4->setObjectName(QStringLiteral("DP_monitor_4"));
        DP_monitor_4->setGeometry(QRect(590, 260, 70, 25));
        DP_monitor_4->setAlignment(Qt::AlignCenter);
        DP_monitor_5 = new QLineEdit(centralWidget);
        DP_monitor_5->setObjectName(QStringLiteral("DP_monitor_5"));
        DP_monitor_5->setGeometry(QRect(670, 260, 70, 25));
        DP_monitor_5->setAlignment(Qt::AlignCenter);
        DP_monitor_0 = new QLineEdit(centralWidget);
        DP_monitor_0->setObjectName(QStringLiteral("DP_monitor_0"));
        DP_monitor_0->setGeometry(QRect(270, 260, 70, 25));
        DP_monitor_0->setAlignment(Qt::AlignCenter);
        DP_monitor_2 = new QLineEdit(centralWidget);
        DP_monitor_2->setObjectName(QStringLiteral("DP_monitor_2"));
        DP_monitor_2->setGeometry(QRect(430, 260, 70, 25));
        DP_monitor_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 150, 91, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 230, 91, 25));
        Speed_up = new QPushButton(centralWidget);
        Speed_up->setObjectName(QStringLiteral("Speed_up"));
        Speed_up->setGeometry(QRect(80, 380, 121, 31));
        Speed_down = new QPushButton(centralWidget);
        Speed_down->setObjectName(QStringLiteral("Speed_down"));
        Speed_down->setGeometry(QRect(80, 420, 121, 31));
        Epos_up = new QPushButton(centralWidget);
        Epos_up->setObjectName(QStringLiteral("Epos_up"));
        Epos_up->setGeometry(QRect(250, 380, 121, 31));
        Epos_down = new QPushButton(centralWidget);
        Epos_down->setObjectName(QStringLiteral("Epos_down"));
        Epos_down->setGeometry(QRect(250, 420, 121, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Data_collect->setText(QApplication::translate("MainWindow", "Data_collect", nullptr));
        Start->setText(QApplication::translate("MainWindow", "Start_up", nullptr));
        Init->setText(QApplication::translate("MainWindow", "Initialization", nullptr));
        label->setText(QApplication::translate("MainWindow", "Sockfd_PLC", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Sockfd_MONITOR", nullptr));
        Communication_PLC->setText(QApplication::translate("MainWindow", "Communication_PLC", nullptr));
        Communication_MONITOR->setText(QApplication::translate("MainWindow", "Communication_MONITOR", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "DP_control", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "DP_monitor", nullptr));
        Speed_up->setText(QApplication::translate("MainWindow", "Speed_up", nullptr));
        Speed_down->setText(QApplication::translate("MainWindow", "Speed_down", nullptr));
        Epos_up->setText(QApplication::translate("MainWindow", "Epos_up", nullptr));
        Epos_down->setText(QApplication::translate("MainWindow", "Epos_down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
