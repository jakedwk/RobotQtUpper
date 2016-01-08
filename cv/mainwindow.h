#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <convey.h>
#include <qlabel.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void slot_timer();
    void on_but_start_clicked();

    void on_but_stop_clicked();

    void on_but_con_clicked();

private:
    QTimer *timer;    //定时器
    char ack;
    int clfd;
    Convey conv;
    bool start_flg,connect_flg;
    cv::Mat image;
    QImage img;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
