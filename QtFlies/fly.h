#ifndef FLY_H
#define FLY_H

#include <QString>

class Fly
{
public:
  enum Action {
    DoNothing,
    MoveLeft,
    MoveUp,
    MoveRight,
    MoveDown,
    Died,
  };

  explicit Fly(const QString &name);
  Fly(Fly &&fly);
  const QString &name() const;
  Action live();

private:
  QString name_;
};

#endif // FLY_H
