#include "fly.h"
#include <QDebug>
#include <QRandomGenerator>

Fly::Fly(const QString &name, int max_age, int stupidity_)
  : name_(name)
  , age_(0) // TODO: Why init variables here instead of the body?
  , max_age_(max_age)
  , stupidity_(stupidity_)
{
  qDebug() << name_ << __func__;
  time_to_next_decision_ = 0;
}

Fly::Fly(Fly &&fly)
  : name_(std::move(fly.name_))
  , age_(std::exchange(fly.age_, 0))
  , max_age_(std::exchange(fly.max_age_, 0))
  , stupidity_(std::exchange(fly.stupidity_, 0)) // TODO: Or just assign/construct?
  , time_to_next_decision_(std::exchange(time_to_next_decision_, 0))
{}

const QString &Fly::name() const
{
  return name_;
}

int Fly::age() const
{
  return age_;
}

Fly::Action Fly::live()
{
  if (!isAlive()) {
    return DoNothing;
  }

  Action action = FlyAround;
  time_to_next_decision_--;
  if (time_to_next_decision_ <= 0) {
    action = static_cast<Action>(QRandomGenerator::global()->generate() % DoNothing);
    time_to_next_decision_ = (QRandomGenerator::global()->generate() % stupidity_);
  }

  age_++;
  return action;
}

bool Fly::isAlive() const
{
  return (age_ < max_age_);
}
