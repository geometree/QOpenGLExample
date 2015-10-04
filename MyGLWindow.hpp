//#include <QScreen>
#include <QWindow>

#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLContext>
#include <QOpenGLWindow>
//#include <QOpenGLWidget>

class MyGLWindow : public QWindow, protected QOpenGLFunctions_3_2_Core {
  Q_OBJECT
public:
  MyGLWindow(QWindow *parent = 0); // QScreen *screen = 0
  ~MyGLWindow();

protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  QOpenGLContext *m_context;
};
