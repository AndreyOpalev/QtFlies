#include "fly.h"
#include <QDebug>

Fly::Fly(const QString &name)
  : name_(name)
{
  qDebug() << name_ << __func__;
}

Fly::Fly(Fly &&fly)
  : name_(std::move(fly.name_))
{}

const QString &Fly::name() const
{
  return name_;
}

Fly::Action Fly::live()
{
  qDebug() << name_ << __func__;
  return DoNothing;
}
