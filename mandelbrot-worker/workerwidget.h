#ifndef WORKERWIDGET_H
#define WORKERWIDGET_H

#include <QProgressBar>
#include <QThread>
#include <QTimer>
#include <QWidget>

#include "worker.h"

class WorkerWidget : public QWidget {
  Q_OBJECT

public:
  explicit WorkerWidget(QWidget *parent = 0);
  ~WorkerWidget();

private:
  QProgressBar mStatus;
  Worker mWorker;
  QThread mWorkerThread;
  QTimer mRefreshTimer;
};

#endif // WORKERWIDGET_H
