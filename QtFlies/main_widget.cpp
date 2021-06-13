#include "main_widget.h"
#include "fly_graphic_item.h"
#include "world_scene.h"
#include "world_view.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QHBoxLayout>

Widget::Widget(FlyWorld &world, QWidget *parent)
  : QWidget(parent)
  , world_(world)
  , scene_(new WorldScene(this))
{
  setMinimumSize(640, 480);

  View *view = new View(this);
  view->view()->setScene(scene_);

  qDebug() << scene_->sceneRect();

  QHBoxLayout *top_layout = new QHBoxLayout;
  top_layout->addWidget(view);
  setLayout(top_layout);

  FlyGraphicItem *item_ptr = new FlyGraphicItem();
  item_ptr->setPos(0, 0);
  scene_->addItem(item_ptr);
}

Widget::~Widget() {}
