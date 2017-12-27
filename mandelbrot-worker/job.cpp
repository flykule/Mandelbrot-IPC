#include "job.h"

Job::Job(const JobRequest &jobRequest, QObject *parent)
    : QObject(parent), mJobRequest(jobRequest), mAbort(false) {}

void Job::run() {
  auto mAreaSize = mJobRequest.areaSize;
  auto mScaleFactor = mJobRequest.scaleFactor;
  auto mIterationMax = mJobRequest.iterationMax;
  auto mPixelPositionY = mJobRequest.pixelPositionY;
  auto mMoveOffset = mJobRequest.moveOffset;

  JobResult jobResult(mAreaSize.width());
  jobResult.areaSize = mAreaSize;
  jobResult.pixelPositionY = mPixelPositionY;
  jobResult.moveOffset = mMoveOffset;
  jobResult.scaleFactor = mScaleFactor;

  double imageHalfWidth = mAreaSize.width() / 2.0;
  double imageHalfHeight = mAreaSize.height() / 2.0;

  for (int imageX = 0; imageX < mAreaSize.width(); ++imageX) {
    if (mAbort.load()) {
      return;
    }

    int iteration = 0;
    double x0 = (imageX - imageHalfWidth) * mScaleFactor + mMoveOffset.x();
    double y0 =
        (mPixelPositionY - imageHalfHeight) * mScaleFactor - mMoveOffset.y();
    double x = 0.0;
    double y = 0.0;
    do {
      double nextX = (x * x) - (y * y) + x0;
      y = 2.0 * x * y + y0;
      x = nextX;
      iteration++;

    } while (iteration < mIterationMax && (x * x) + (y * y) < 4.0);

    jobResult.values[imageX] = iteration;
  }

  emit jobCompleted(jobResult);
}

void Job::abort() { mAbort.store(true); }
