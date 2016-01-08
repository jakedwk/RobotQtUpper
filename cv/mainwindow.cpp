#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start_flg = false;
    connect_flg = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_but_start_clicked()
{
    if(connect_flg)
    {
            if(!start_flg)
            {
                    timer->start(50);
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
        timer->stop();
        ::close(clfd);
        start_flg = false;
        connect_flg = false;
        ui->but_start->setText("start");
        ui->txt_lab1->setText("stoped!");
}

void MainWindow::on_but_con_clicked()
{
    if(!connect_flg)
    {
            ack = 'o';
            image.create(Size(640,480),CV_8UC3);
            QString str = ui->lineEdit_ip->text();
            if(str.length())
            {
                    QByteArray ba = str.toLatin1();
                    char *mm = ba.data();
                    if(conv.clientinit(clfd,mm) == -1){
                    ui->txt_lab1->setText("please strat the server!");
                    return;
                    }
            }else  if(conv.clientinit(clfd) == -1){
                    ui->txt_lab1->setText("please strat the server!");
                    return;
                    }
            connect_flg = true;
            ui->txt_lab1->setText("connect!");
    }else ui->txt_lab1->setText("opened already");
}

void MainWindow::slot_timer()
{
    if(connect_flg)
    {
        conv.recvimg(clfd,image);
        cv::cvtColor(image, image, CV_RGB2RGBA);//图像在QT显示前，必须转化成QImage格式，将RGBA格式转化成RGB
        img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB32);
        QLabel *label = new QLabel(this);
        label->move(0,0);
        label->setPixmap(QPixmap::fromImage(img));
        label->resize(label->pixmap()->size());
        label->show();
        send(clfd,&ack,1,0);
    }else ui->txt_lab1->setText("please connect first");
}
