#include "fly_graphic_item.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

FlyGraphicItem::FlyGraphicItem()
  : QGraphicsItem()
  , pixmap_(":/icons/baby_fly.png")
{
}

QRectF FlyGraphicItem::boundingRect() const
{
  // TODO: Implement it
  return QRectF(pixmap_.rect());
}

void FlyGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  //  const QGraphicsScene *s = scene();
  //  qDebug() << __func__ << s->sceneRect() << s->width() << s->height() << s->views().at(0)->width();

  painter->drawPixmap(0, 0, pixmap_);
}
