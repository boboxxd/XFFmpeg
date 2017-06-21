#include "xvideothread.h"
#include "xffmpeg.h"
#include <QDebug>
bool isexit=false;
XVideoThread::XVideoThread()
{

}


void XVideoThread::run()
{
    while(!isexit)
    {
        AVPacket pkt=XFFmpeg::Get()->Read();
        if(pkt.size<=0)
        {
            msleep(10);
            continue;
        }
        if(pkt.stream_index!=XFFmpeg::Get()->videostream)
        {
            av_packet_unref(&pkt);
            continue;
        }
        XFFmpeg::Get()->Decode(&pkt);
        av_packet_unref(&pkt);
        if(XFFmpeg::Get()->fps>0)
        msleep(1000/XFFmpeg::Get()->fps);

    }
}

 XVideoThread::~XVideoThread()
{

}
