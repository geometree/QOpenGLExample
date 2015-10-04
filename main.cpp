
#include "MyGLWidget.hpp"
#include "MyGLWindow.hpp"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QSurfaceFormat format;
  // format.setDepthBufferSize(24);
  // format.setStencilBufferSize(8);
  format.setVersion(3, 2);
  format.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(format);

  // MyGLWidget widget;
  // widget.show();

  MyGLWindow window;
  window.setFormat(format);
  window.resize(640, 480);
  window.show();

  return app.exec();
}

/*
QOpenGLWidget *widget = new QOpenGLWidget(parent);
QSurfaceFormat format;
format.setDepthBufferSize(24);
format.setStencilBufferSize(8);
format.setVersion(3, 2);
format.setProfile(QSurfaceFormat::CoreProfile);
widget->setFormat(format); // must be called before the widget or its parent
window gets shown
*/
