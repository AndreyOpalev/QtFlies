QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fly.cpp \
    fly_graphic_item.cpp \
    flyworld.cpp \
    main.cpp \
    main_widget.cpp \
    world_scene.cpp \
    world_view.cpp

HEADERS += \
    fly.h \
    fly_graphic_item.h \
    flyworld.h \
    main_widget.h \
    world_scene.h \
    world_view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  images.qrc
