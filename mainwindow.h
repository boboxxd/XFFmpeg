#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerEvent(QTimerEvent *e);

public slots:
    void open();
    void sliderPress();
    void sliderRelease();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
