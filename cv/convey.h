#ifndef CONVEY_H
#define CONVEY_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVPORT 5788
#define BACKLOG 10
#define ADDRESS "127.0.0.1"

using namespace cv;
using namespace std;

class  Convey
{
    time_t now_time;
    struct tm *p;
    char fmt_time[100];
    int times;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    struct sockaddr_in their_addr;
    vector<int> param;
    unsigned int datasize;
    struct timeval tpstart,tpend; 
    float timeuse; 
    uint vsize;
    vector<uchar> vbuf;
    Mat frame;
    public:
        Convey();
        ~Convey();
        void socketinit(int &sockfd,int servport = SERVPORT);
        int accept_m(int sockfd);
        void sendimg(int sockfd,InputArray frame);
        void recvimg(int sockfd,OutputArray frame);
        int recvall(int sockfd,void *ptr,uint len);
        int clientinit(int &sockfd,const char* address = ADDRESS,int servport = SERVPORT);
};

#endif
