#pragma once

#include "fly.h"
#include <vector>
#include <QObject>
#include <QSize>

class FlyWorld : public QObject
{
  Q_OBJECT

public:
  explicit FlyWorld(QObject* parent = nullptr);
  FlyWorld(int side_size, QObject* parent = nullptr);
  void run();
  void pause();
  void addFly();
  void setSideSize(int side_size);

protected:
  void timerEvent(QTimerEvent* event) override;

private:
  const int TIMER_INTERVAL_MS = 10;
  int side_size_;
  int general_timer_id_;
  std::vector<Fly> flies_;
};
