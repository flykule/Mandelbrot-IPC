#ifndef JOB_H
#define JOB_H

#include "job.h"
#include <QAtomicInteger>
#include <QObject>
#include <QRunnable>

#include "JobRequest.h"
#include "JobResult.h"

class Job : public QObject, public QRunnable {
  Q_OBJECT
public:
  explicit Job(const JobRequest &jobRequest, QObject *parent = 0);
  void run() override;

signals:
  void jobCompleted(JobResult JobResult);

public slots:
  void abort();

private:
  QAtomicInteger<bool> mAbort;
  JobRequest mJobRequest;
};

#endif // JOB_H
