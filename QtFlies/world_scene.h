#ifndef WORLD_SCENE_H
#define WORLD_SCENE_H

#include <QGraphicsScene>

class WorldScene : public QGraphicsScene
{
  Q_OBJECT

public:
  explicit WorldScene(QObject *parent = nullptr);
  void setSideSize(int side_size);

protected:
  void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
  int side_size_;
};

#endif // WORLD_SCENE_H
