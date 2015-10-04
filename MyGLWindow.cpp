#include "MyGLWindow.hpp"

MyGLWindow::MyGLWindow(QWindow *parent)
    : QWindow(parent) { // screen, QOpenGLWidget(parent) {

  QSurfaceFormat format;
  format.setVersion(3, 2);
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setDepthBufferSize(24);
  format.setStencilBufferSize(8);
  setFormat(format);

  setSurfaceType(OpenGLSurface);
  create();

  // Create an OpenGL context
  m_context = new QOpenGLContext;
  m_context->create();

  // Setup scene and render it
  initializeGL();
  paintGL();
}

MyGLWindow::~MyGLWindow() {}

void MyGLWindow::initializeGL() {
  m_context->makeCurrent(this);
  initializeOpenGLFunctions();
}

void MyGLWindow::resizeGL(int w, int h) {}

void MyGLWindow::paintGL() {
  m_context->makeCurrent(this);
  // glActiveTexture(GL_TEXTURE1);
  // glBindTexture(GL_TEXTURE_2D, textureId);
  //...
  // m_context->swapBuffers(this);
  m_context->doneCurrent();
}
