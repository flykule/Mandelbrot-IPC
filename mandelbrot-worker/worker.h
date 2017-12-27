#ifndef WORKER_H
#define WORKER_H
#include <QDataStream>
#include <QObject>
#include <QTcpSocket>

#include "JobResult.h"
#include "Message.h"
#include "job.h"

class Worker : public QObject {
  Q_OBJECT
public:
  Worker(QObject *parent = 0);
  ~Worker();

  int receivedJobsCounter() const;

  int sentJobsCounter() const;

signals:
  void abortAllJobs();
private slots:
  void readMessages();

private:
  void handleJobRequest(Message &message);
  void handleAllJobsAbort(Message &message);
  void sendJobResult(JobResult jobResult);
  Job *createJob(const JobRequest &jobRequest);
  void sendRegister();
  void sendUnregister();

private:
  QTcpSocket mSocket;
  QDataStream mSocketReader;
  int mReceivedJobsCounter;
  int mSentJobsCounter;
};

#endif // WORKER_H
