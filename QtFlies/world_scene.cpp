#include "world_scene.h"
#include <QDebug>
#include <QPainter>

WorldScene::WorldScene(QObject *parent)
  : QGraphicsScene(parent)
  , side_size_(3)
{}

void WorldScene::setSideSize(int side_size)
{
  if (side_size > 0) {
    side_size_ = side_size;
  }
}

void WorldScene::drawBackground(QPainter *painter, const QRectF &rect)
{
  const auto h = rect.height();
  const auto w = rect.width();

  qreal vertical_line_x = rect.x();
  qreal horizontal_line_y = rect.y();
  for (int i = 0; i < side_size_ - 1; ++i) {
    vertical_line_x += w / side_size_;
    horizontal_line_y += h / side_size_;

    painter->drawLine(vertical_line_x, rect.y(), vertical_line_x, h);
    painter->drawLine(rect.x(), horizontal_line_y, w, horizontal_line_y);
  }
}
