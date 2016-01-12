#include "convey.h"



Convey::Convey(){
    param = vector<int>(2);
}


Convey::~Convey(){}

void Convey::socketinit(int &sockfd,int servport)
{
    //创建套接字
    if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        perror("socket create failed!");
        exit(1);
    }

    //绑定端口地址
    my_addr.sin_family      = AF_INET;
    my_addr.sin_port        = htons(servport);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero),8);
    if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("bind error!");
        exit(1);
    }

    //监听端口  
    if (listen(sockfd, BACKLOG) == -1)
    {
        perror("listen error");
        exit(1);
    }
}

int Convey::accept_m(int sockfd)
{
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int new_server_socket = accept(sockfd,(struct sockaddr*)&client_addr,&length);
    if ( new_server_socket < 0)
    {
        printf("Server Accept Failed!\n");
        exit(1);  
    }
    return new_server_socket;
}

int Convey::clientinit(int &sockfd,const char* address,int servport)
{
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET; /* host byte order */
    their_addr.sin_port = htons(servport); /* short, network byte order */
    their_addr.sin_addr.s_addr =inet_addr(address); 
    bzero(&(their_addr.sin_zero),8); /* zero the rest of the struct */
    return connect(sockfd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr));
}

void Convey::sendimg(int sockfd,InputArray frame)
{
    param[0]=CV_IMWRITE_JPEG_QUALITY;
    param[1]=95;
    imencode(".jpg",frame,vbuf,param);
    vsize = vbuf.size();
    uint pic,lst;
    uchar *dataptr = &vbuf[0];
    //发送
    lst = vsize%1920;
    pic = vsize/1920;
    send(sockfd,&vsize,4,0);
    for(uint i=0;i<pic;i++)
    {
        send(sockfd,dataptr,1920,0);
        dataptr+=1920;
    }
    if(lst)
        send(sockfd,dataptr,lst,0); 
}
void Convey::recvimg(int sockfd,OutputArray frame)
{
    uint num=0;
    int numbytes;
    uchar *dataptr = NULL;
    if ((numbytes=recv(sockfd,&vsize, 4, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    vbuf.resize(vsize);
    dataptr = &vbuf[0];
    while(1)
    {
        if ((numbytes=recv(sockfd,dataptr, vsize-num, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        dataptr+=numbytes;
        num+=numbytes;
        if(num==vsize) break;
    }
    imdecode(Mat(vbuf),CV_LOAD_IMAGE_COLOR).copyTo(frame);
}
int Convey::recvall(int sockfd,void *ptr,uint len)
{
    int numbytes;
    uchar *dataptr = (uchar *)ptr;
    while(len)
    {
        if ((numbytes=recv(sockfd,dataptr, len, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        if(numbytes == 0) {
            return 0;
        }
        dataptr+=numbytes;
        len-=numbytes;
    }
    return 1;
}

int Convey::senddata(int sockfd,vector<int> data,int len)
{
    send(sockfd,&len,4,0);
    return send(sockfd,&data[0],4*len,0);
}

int Convey::recvdata(int sockfd,vector<int> &data)
{
    int len;
    recvall(sockfd,&len,4);
    data.resize(len);
    return recvall(sockfd,&data[0],4*len);
}
