#include "flyworld.h"
#include "main_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  FlyWorld world;
  world.addFly();

  Widget w(world);
  w.show();

  return a.exec();
}
