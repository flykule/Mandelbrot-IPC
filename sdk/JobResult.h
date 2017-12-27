#ifndef JOBRESULT_H
#define JOBRESULT_H
#include <QDataStream>
#include <QPointF>
#include <QSize>
#include <QVector>

struct JobResult {

  JobResult(int valueCount = 1)
      : areaSize(0, 0), pixelPositionY(0), moveOffset(0, 0), scaleFactor(0.0),
        values(valueCount) {}

  int pixelPositionY;
  QPointF moveOffset;
  double scaleFactor;
  QSize areaSize;

  QVector<int> values;
};

inline QDataStream &operator<<(QDataStream &out, const JobResult &jobResult) {
  out << jobResult.pixelPositionY << jobResult.moveOffset
      << jobResult.scaleFactor << jobResult.areaSize << jobResult.values;
  return out;
}

inline QDataStream &operator>>(QDataStream &in, JobResult &jobResult) {
  in >> jobResult.pixelPositionY >> jobResult.moveOffset >>
      jobResult.scaleFactor >> jobResult.areaSize >> jobResult.values;
  return in;
}

Q_DECLARE_METATYPE(JobResult)

#endif
