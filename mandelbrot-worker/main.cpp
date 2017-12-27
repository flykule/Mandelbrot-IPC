#include <QApplication>

#include "JobResult.h"

#include "workerwidget.h"

int main(int argc, char *argv[]) {
  qRegisterMetaType<JobResult>();
  QApplication a(argc, argv);
  WorkerWidget workerWIdget;

  workerWIdget.show();
  return a.exec();
}
