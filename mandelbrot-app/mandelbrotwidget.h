#ifndef MANDELBROTWIDGET_H
#define MANDELBROTWIDGET_H

#include <QList>
#include <QPoint>
#include <QThread>
#include <QWidget>
#include <memory>

#include <mandelbrotcalculator.h>

class QResizeEvent;

class MandelbrotWidget : public QWidget {
  Q_OBJECT
public:
  explicit MandelbrotWidget(QWidget *parent = 0);
  ~MandelbrotWidget();

public slots:
  void processJobResults(QList<JobResult> jobResults);

signals:
  void requestPicture(QSize areaSize, QPointF moveOffset, double scaleFactor,
                      int iterationMax);

private:
  QRgb generateColorFromIteration(int iteration);

private:
  MandelbrotCalculator mMandelbrotCalculator;
  QThread mThreadCalculator;
  double mScaleFactor;
  QPoint mLastMouseMovePosition;
  QPointF mMoveOffset;
  QSize mAreSize;
  int mIterationMax;
  std::unique_ptr<QImage> mImage;

  // QWidget interface
protected:
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;
};

#endif // MANDELBROTWIDGET_H
