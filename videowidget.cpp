#include "videowidget.h"
#include <QPainter>
#include <QImage>
#include<QPoint>
#include"xffmpeg.h"
#include <QDebug>
#include"xvideothread.h"
VideoWidget::VideoWidget(QWidget *p):QOpenGLWidget(p)
{
    XFFmpeg::Get()->Open("/Users/xuxudong/Downloads/1.mkv");
    startTimer(25);
    XVideoThread::Get()->start();
}

 VideoWidget::~VideoWidget()
{

}

void VideoWidget::paintEvent(QPaintEvent *e)
{
    static QImage *image=NULL;
    if(image==NULL)
    {
        uchar *buf=new uchar[width()*height()*4];
        image=new QImage(buf,width(),height(),QImage::Format_ARGB32);
    }
//    AVPacket pkt=XFFmpeg::Get()->Read();
//    if(pkt.stream_index!=XFFmpeg::Get()->videostream)
//    {
//        av_packet_unref(&pkt);
//        return;
//    }
//    if(pkt.size==0) return;
//    AVFrame *yuv=XFFmpeg::Get()->Decode(&pkt);
//    av_packet_unref(&pkt);
//    if(yuv==NULL) return;
//    XFFmpeg::Get()->ToRGB(*yuv,(char*)image->bits(),width(),height());

    XFFmpeg::Get()->ToRGB((char*)image->bits(),width(),height());
    QPainter painter;
    painter.begin(this);
    //painter.drawImage(QPoint(0,0),image);
    painter.drawImage(QPoint(0,0),*image);
    painter.end();
}

void VideoWidget::timerEvent(QTimerEvent *e)
{
    this->update();
}
