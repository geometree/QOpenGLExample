#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLWidget>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_2_Core {
  Q_OBJECT
public:
  MyGLWidget(QWidget *parent = NULL);
  ~MyGLWidget();

protected:
  // Qt OpenGL callbacks
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

private:
  void drawCursor();
};
