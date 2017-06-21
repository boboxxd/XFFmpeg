#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "xffmpeg.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openButton,SIGNAL(clicked()),this,SLOT(open()));
}

void MainWindow::open()
{
    QString name=QFileDialog::getOpenFileName(
                this,QString::fromLocal8Bit("选择视频文件"));
    if(name.isEmpty()) return;
    this->setWindowTitle(name);
    if(!XFFmpeg::Get()->Open(name.toLocal8Bit()))
    {
        QMessageBox::information(this,"error","file open failed!");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
