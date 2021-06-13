#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include <QFrame>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class FlyWorld;
class QPushButton;
QT_END_NAMESPACE

class View;

class GraphicsView : public QGraphicsView
{
  Q_OBJECT
public:
  GraphicsView(View *v)
    : QGraphicsView()
    , view_(v)
  {}

private:
  View *view_;
};

class View : public QFrame
{
  Q_OBJECT
public:
  explicit View(QWidget *parent = nullptr);
  View(const FlyWorld &world, QWidget *parent = nullptr);

  QGraphicsView *view() const;

private:
  GraphicsView *graphics_view_;
  QPushButton *start_button_;
  QPushButton *pause_button_;
};

#endif // WORLDVIEW_H
