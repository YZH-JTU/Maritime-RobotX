#include <QApplication>
#include "mainwindow.h"

int server_sockfd_PLC = -1;
int server_sockfd_MONITOR = -1;
unsigned int DP_control[7] = {};
int DP_monitor[7] = {};

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
