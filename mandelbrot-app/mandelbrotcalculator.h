#ifndef MANDELBROTCALCULATOR_H
#define MANDELBROTCALCULATOR_H

#include <memory>
#include <vector>

#include <QElapsedTimer>
#include <QList>
#include <QMap>
#include <QTcpServer>
#include <QThread>

#include "JobRequest.h"
#include "JobResult.h"
#include "workerclient.h"

class MandelbrotCalculator : public QTcpServer {
  Q_OBJECT
public:
  MandelbrotCalculator(QObject *parent = 0);
  ~MandelbrotCalculator();

signals:
  void pictureLinesGenerated(QList<JobResult> JobResults);
  void abortAllJobs();

public slots:
  void generatePicture(QSize areaSize, QPointF moveOffset, double scaleFactor,
                       int iterationMax);

private slots:
  void process(WorkerClient *workerClient, JobResult jobResult);

  void removeWorkerClient(WorkerClient *workerClient);

  // QTcpServer intface
protected:
  void incomingConnection(qintptr socketDescriptor) override;

private:
  std::unique_ptr<JobRequest> createJobRequest(int pixelPositionY);
  void sendJobRequests(WorkerClient &client, int jobRequestCount = 1);
  void clearJobs();

private:
  QPointF mMoveOffset;
  double mScaleFactor;
  QSize mAreaSize;
  int mIterationMax;
  int mReceivedJobResults;
  QList<JobResult> mJobResults;
  QMap<WorkerClient *, QThread *> mWorkerClients;
  std::vector<std::unique_ptr<JobRequest>> mJobRequests;
  QElapsedTimer mTimer;
};

#endif // MANDELBROTCALCULATOR_H
