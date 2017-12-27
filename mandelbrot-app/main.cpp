#include "mainwindow.h"
#include <QApplication>
#include <QList>

#include "JobRequest.h"
#include "JobResult.h"
#include "workerclient.h"

int main(int argc, char *argv[]) {
  //  qRegisterMetaType<JobResult>("JobResult");
  qRegisterMetaType<QList<JobResult>>();
  qRegisterMetaType<QList<JobRequest>>();
  qRegisterMetaType<WorkerClient *>();

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
