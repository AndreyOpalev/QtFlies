#ifndef FLY_H
#define FLY_H

#include <QString>

class Fly
{
public:
  enum Action { FlyAround, MoveLeft, MoveUp, MoveRight, MoveDown, DoNothing };

  Fly(const QString &name, int max_age, int stupidity_);
  Fly(Fly &&fly);
  const QString &name() const;
  int age() const;
  Action live();
  bool isAlive() const;

private:
private:
  QString name_;
  int age_;
  int max_age_;
  int stupidity_;
  int time_to_next_decision_; // TODO: Or make it local?
};

#endif // FLY_H
