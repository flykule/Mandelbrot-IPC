#ifndef JOBREQUEST_H
#define JOBREQUEST_H

#include <QDataStream>
#include <QPointF>
#include <QSize>

struct JobRequest {
  int pixelPositionY;
  QPointF moveOffset;
  double scaleFactor;
  QSize areaSize;
  int iterationMax;
};

inline QDataStream &operator<<(QDataStream &out, const JobRequest &jobRequest) {
  out << jobRequest.pixelPositionY << jobRequest.moveOffset
      << jobRequest.scaleFactor << jobRequest.areaSize
      << jobRequest.iterationMax;
  return out;
}

inline QDataStream &operator>>(QDataStream &in, JobRequest &jobRequest) {
  in >> jobRequest.pixelPositionY >> jobRequest.moveOffset >>
      jobRequest.scaleFactor >> jobRequest.areaSize >> jobRequest.iterationMax;
  return in;
}

Q_DECLARE_METATYPE(JobRequest)

#endif
