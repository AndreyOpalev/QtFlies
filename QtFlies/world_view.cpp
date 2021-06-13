#include "world_view.h"
#include "flyworld.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

View::View(QWidget *parent)
  : QFrame(parent)
{
  graphics_view_ = new GraphicsView(this);
  graphics_view_->setDragMode(QGraphicsView::NoDrag);
  graphics_view_->setOptimizationFlags(QGraphicsView::DontSavePainterState);
  graphics_view_->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  graphics_view_->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

  start_button_ = new QPushButton("Start", this);
  pause_button_ = new QPushButton("Pause", this);

  QHBoxLayout *button_layout = new QHBoxLayout();
  button_layout->addWidget(start_button_);
  button_layout->addWidget(pause_button_);

  QVBoxLayout *top_layout = new QVBoxLayout();
  top_layout->addLayout(button_layout);
  top_layout->addWidget(graphics_view_);
  setLayout(top_layout);
}

QGraphicsView *View::view() const
{
  return graphics_view_;
}
