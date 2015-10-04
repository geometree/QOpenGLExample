#include "MyGLWidget.hpp"

MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

MyGLWidget::~MyGLWidget() {}

void MyGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
}

void MyGLWidget::resizeGL(int w, int h) {
  // Update projection matrix and other size related settings:
  // m_projection.setToIdentity();
  // m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
}

void MyGLWidget::paintGL() {
  // Draw the scene:
  // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawCursor();
}

/// Draw the 3D cursor
void MyGLWidget::drawCursor() {
  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, width(), 0, height(), 0, 1);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glColor3f(1, 1, 1);
  glPointSize(4.0);
  glBegin(GL_POINTS);
  glVertex3f(40.f, 40.f, 0.f);
  glEnd();

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopAttrib();

  glBindTexture(GL_TEXTURE_2D, 0);

  /*
  // Now draw a 2D overlay over the 3D scene to allow user to pinpoint the
  // cursor, even when when it's behind something.
  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, width(), 0, height(), 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);

  // Find position of cursor in screen space
  V3d screenP3 = relCursor * transState.modelViewMatrix * transState.projMatrix;
  // Position in ortho coord system
  V2f p2 =
    0.5f * V2f(width(), height()) * (V2f(screenP3.x, screenP3.y) + V2f(1.0f));
  float r1 = cursorRadius;
  float r2 = r1 + cursorRadius;
  glLineWidth(2);
  glColor3f(1, 1, 1);
  // Combined white and black crosshairs, so they can be seen on any
  // background.
  glTranslatef(p2.x, p2.y, 0);
  glBegin(GL_LINES);
  glVertex(V2f(r1, 0));
  glVertex(V2f(r2, 0));
  glVertex(-V2f(r1, 0));
  glVertex(-V2f(r2, 0));
  glVertex(V2f(0, r1));
  glVertex(V2f(0, r2));
  glVertex(-V2f(0, r1));
  glVertex(-V2f(0, r2));
  glEnd();
  glColor3f(0, 0, 0);
  glRotatef(45, 0, 0, 1);
  glBegin(GL_LINES);
  glVertex(V2f(r1, 0));
  glVertex(V2f(r2, 0));
  glVertex(-V2f(r1, 0));
  glVertex(-V2f(r2, 0));
  glVertex(V2f(0, r1));
  glVertex(V2f(0, r2));
  glVertex(-V2f(0, r1));
  glVertex(-V2f(0, r2));
  glEnd();

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopAttrib();
  */
}
