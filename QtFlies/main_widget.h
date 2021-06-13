#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QGraphicRectItem;
class WorldScene;
QT_END_NAMESPACE

class FlyWorld;

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(FlyWorld &world, QWidget *parent = nullptr);
  ~Widget();

private:
  FlyWorld &world_;
  QVector<QGraphicRectItem *> rects_;
  WorldScene *scene_;
};
#endif // WIDGET_H
