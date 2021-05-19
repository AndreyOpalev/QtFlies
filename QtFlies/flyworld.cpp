#include "flyworld.h"
#include <QDebug>
#include <QTimerEvent>

using namespace std;

QString generateName()
{
  static int id = 0;
  // TODO: Generate real name, not just a number.
  QString str = QString("Fly %d").arg(id);
  id++;
  return str;
}

FlyWorld::FlyWorld(QObject* parent)
  : FlyWorld(1, parent)
{
}

FlyWorld::FlyWorld(int side_size, QObject *parent)
  : QObject(parent)
  , side_size_(side_size)
  , general_timer_id_(0)
{
}

void FlyWorld::run()
{
  qDebug() << "World is running";

  if (general_timer_id_) {
    return;
  }

  general_timer_id_ = startTimer(TIMER_INTERVAL_MS);
}

void FlyWorld::pause()
{
  qDebug() << "World is stopped";

  if (general_timer_id_ == 0) {
    return;
  }

  killTimer(general_timer_id_);
  general_timer_id_ = 0;
}

void FlyWorld::addFly()
{
  flies_.push_back(Fly(generateName()));
}

void FlyWorld::setSideSize(int side_size)
{
  side_size_ = side_size;

  // TODO: Implement: shrinking/expanding
}

void FlyWorld::timerEvent(QTimerEvent* event)
{
  if (event->timerId() == general_timer_id_) {
    for (auto &fly : flies_) {
      Fly::Action action = fly.live();
      qDebug() << fly.name() << action;
    }
  }
}
