#include "mainwindow.h"
#include <QApplication>
#include"xffmpeg.h"
#include<QDebug>
int main(int argc, char *argv[])
{

//    char *path="/Users/xuxudong/CLionProjects/untitled/1.mp4";
//    if(XFFmpeg::Get()->Open(path))
//    {
//        printf("open success!\n");
//    }else
//    {
//        printf("open failed: %s\n",XFFmpeg::Get()->Geterror().c_str());
//    }
//    char *rgb=new char[800*600*4];
//    for(;;)
//    {
//        AVPacket pkt=XFFmpeg::Get()->Read();
//        if(pkt.size==0)   break;
//        printf("%lld\n",pkt.pts);
//        if(pkt.stream_index!=XFFmpeg::Get()->videostream)
//        {
//            av_packet_unref(&pkt);
//            continue;
//        }
//        AVFrame *yuv=XFFmpeg::Get()->Decode(&pkt);
//        if(yuv)
//        {
//            printf("[D]");
//            XFFmpeg::Get()->ToRGB(*yuv,rgb,800,600);
//        }

//    }




    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   return a.exec();
}
