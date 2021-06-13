#ifndef FLYGRAPHICITEM_H
#define FLYGRAPHICITEM_H

#include <QGraphicsItem>

class FlyGraphicItem : public QGraphicsItem
{
public:
  FlyGraphicItem();

  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
  QPixmap pixmap_;
};

#endif // FLYGRAPHICITEM_H
