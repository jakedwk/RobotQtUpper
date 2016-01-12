#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ack = 'o';
    q_flg = false;
    s_flg = false;
    start_flg = false;
    connect_flg = false;
    conv = new Convey;
    label = new QLabel(this);
    timer = new QTimer(this);
    image = new cv::Mat(Size(640,480),CV_8UC3);
    mframe = new cv::Mat(Size(640,480),CV_8UC3);
    img = new QImage();
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer()));
}

MainWindow::~MainWindow()
{
    delete image;
    delete img;
    delete mframe;
    delete conv;
    delete ui;
}

void MainWindow::on_but_start_clicked()
{
    if(connect_flg)
    {
            if(!start_flg)
            {
                    timer->start(53);
                    ui->but_start->setText("pause");
                    start_flg = true;
                    ui->txt_lab1->setText("started!");
            }else
            {
                timer->stop();
                ui->but_start->setText("start");
                start_flg = false;
                ui->txt_lab1->setText("paused!");
            }
    }else ui->txt_lab1->setText("please connect first!");
}

void MainWindow::on_but_stop_clicked()
{
    s_flg = true;
    q_flg = true;
    start_flg = false;
    ui->but_start->setText("start");
    ui->but_con->setText("connect");
    ui->txt_lab1->setText("stoped the server!");
}

void MainWindow::on_but_con_clicked()
{
    if(!connect_flg)
    {
            QString str = ui->lineEdit_ip->text();
            if(str.length())
            {
                    QByteArray ba = str.toLatin1();
                    char *ip = ba.data();
                    if(conv->clientinit(clfd,ip) == -1){
                    ui->txt_lab1->setText("please strat the server!");
                    return;
                    }
            }else  if(conv->clientinit(clfd) == -1){
                    ui->txt_lab1->setText("please strat the server!");
                    return;
                    }
            connect_flg = true;
            ui->but_con->setText("disconct");
            ui->txt_lab1->setText("connect!");
    }else
    {
        if(!start_flg)
        {
            ack = 'q';
            send(clfd,&ack,1,0);
            connect_flg = false;
            ack = 'o';
            ui->but_con->setText("connect");
            ui->txt_lab1->setText("disconnected!");
        }else{
            q_flg = true;
            start_flg = false;
            ui->but_start->setText("start");
            ui->but_con->setText("connect");
            ui->txt_lab1->setText("disconnected!");
        }
    }
}

void MainWindow::slot_timer()
{
    if(connect_flg)
    {
        if(!q_flg){
        send(clfd,&ack,1,0);
        conv->recvimg(clfd,*mframe);
        conv->recvdata(clfd,data);
        ui->lab_dir->setText(QString::number(data[0]));
        ui->lab_width->setText(QString::number(data[1]));
        ui->lab_height->setText(QString::number(data[2]));
        cv::cvtColor(*mframe, *image, CV_RGB2RGBA);//图像在QT显示前，必须转化成QImage格式，将RGBA格式转化成RGB
        *img = QImage((const unsigned char*)(image->data), image->cols, image->rows, QImage::Format_RGB32);
        label->move(0,0);
        label->setPixmap(QPixmap::fromImage(*img));
        label->resize(label->pixmap()->size());
        label->show();
        }else{
            if(!s_flg) ack = 'q';
            else ack = 's';
            send(clfd,&ack,1,0);
            ack = 'o';
            q_flg = false;
            s_flg = false;
            connect_flg = false;
            ::close(clfd);
            timer->stop();
        }
    }else ui->txt_lab1->setText("please connect first");
}
