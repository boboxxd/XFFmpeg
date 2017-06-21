#ifndef XFFMPEG_H
#define XFFMPEG_H
#include<string>
#include<QMutex>

extern "C"{
#include<libavformat/avformat.h>
#include<libswscale/swscale.h>
}

class XFFmpeg
{

public:
    static XFFmpeg *Get()
    {
        static XFFmpeg ff;
        return &ff;
    }

    ///////////////////////////////////////////////////////
    /// \brief Open打开视频，如果上次打开会先关闭
    /// \param path 视频文件路径
    /// \return 成功失败，失败错误信息通过GetError 获取
    ///
    bool Open(const char *path);

    void Close();
    ////////////////////////////////////////////////////
    /// \brief Read 返回时，空间需用户自己清理
    /// \return
    ///
    AVPacket Read();

    AVFrame *Decode(const AVPacket *pkt);

    bool ToRGB(const AVFrame,char *out,int outwidth,int outheight);
    std::string Geterror();
    virtual ~XFFmpeg();
    int totalMs=0;
    int videostream=0;
protected:
    char errorbuf[1024];
    AVFormatContext *ic= nullptr;
    AVFrame *yuv=nullptr;
    SwsContext *cCtx=nullptr;
    QMutex mutex;
    XFFmpeg();
};

#endif // XFFMPEG_H
