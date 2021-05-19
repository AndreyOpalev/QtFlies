#include "flyworld.h"
#include "main_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  //  Widget w;
  //  w.show();

  FlyWorld world(2);
  world.addFly();
  world.run();
  return a.exec();
}
