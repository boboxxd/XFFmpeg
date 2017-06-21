#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H
#include<QtWidgets/qwidget.h>
#include<QOpenGLWidget>

class VideoWidget:public QOpenGLWidget
{
public:
    VideoWidget(QWidget *p=NULL);
    virtual ~VideoWidget();
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);
};

#endif // VIDEOWIDGET_H
