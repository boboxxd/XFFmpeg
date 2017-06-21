#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "xffmpeg.h"
static bool isPressed=false;//只能在本文件查看
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openButton,SIGNAL(clicked()),this,SLOT(open()));
    connect(ui->playSlider,SIGNAL(sliderPressed()),this,SLOT(sliderPress()));
    connect(ui->playSlider,SIGNAL(sliderReleased()),this,SLOT(sliderRelease()));
    startTimer(40);
}

void MainWindow::open()
{
    QString name=QFileDialog::getOpenFileName(
                this,QString::fromLocal8Bit("选择视频文件"));
    if(name.isEmpty()) return;
    this->setWindowTitle(name);
    int totalMs=XFFmpeg::Get()->Open(name.toLocal8Bit());
    if(totalMs<=0)
    {
        QMessageBox::information(this,"error","file open failed!");
        return;
    }
    char buf[1024]={0};
    int hour=(totalMs/1000)/60/60;
    int min=(totalMs/1000)/60%60;
    int sec=(totalMs/1000)%60;

    sprintf(buf,"%02d:%02d:%02d",hour,min,sec);

    ui->totaltime->setText(buf);
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    int hour=(XFFmpeg::Get()->pts/1000)/60/60;
    int min=(XFFmpeg::Get()->pts/1000)/60%60;
    int sec=(XFFmpeg::Get()->pts/1000)%60;
    char buf[1024]={0};
    sprintf(buf,"%02d:%02d:%02d/",hour,min,sec);
    ui->playtime->setText(buf);
    if(XFFmpeg::Get()->totalMs>0)
    {
        float rate=(float)XFFmpeg::Get()->pts/(float)XFFmpeg::Get()->totalMs;
        if(!isPressed)
        ui->playSlider->setValue(rate*1000);
    }
}

void MainWindow::sliderPress()
{
    isPressed=true;
}
void MainWindow::sliderRelease()
{
    isPressed=false;
    float pos;//=0;
    pos=(float)ui->playSlider->value()/(float)(ui->playSlider->maximum()+1);
    qDebug()<<"pos"<<pos;
    bool flag=XFFmpeg::Get()->Seek(pos);
    qDebug()<<flag;
}

MainWindow::~MainWindow()
{
    delete ui;
}
