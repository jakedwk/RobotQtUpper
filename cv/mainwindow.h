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
    char ack;
    int clfd;
    vector<int> data;
    bool start_flg,connect_flg,q_flg,s_flg;
    Convey *conv;
    QTimer *timer;    //定时器
    QLabel *label;
    cv::Mat *image,*mframe;
    QImage *img;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
