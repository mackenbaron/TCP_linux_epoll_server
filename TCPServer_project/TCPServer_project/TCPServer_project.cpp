#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "log.h"
#include "MyTCPServer.h"
//https://github.com/lihaitao8233/TCP_linux_epoll_server.git  //转载请保留此地址
//linux epoll模型编写的高并发TCP网络服务端，配有相应的测试客户端代码，可以启动多个客户端进行调试
//https://github.com/lihaitao8233/TCPServer_windows_iocp,这个是windows下完成端口IOCP模型编写的高并发TCP网络服务端，
//linux 和 windows的接口完全一样。


int main(int argc, char *argv[])
{
    open_log_file("/home/lht/server", "server", 0);// 根据实际指定日志目录
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);

    MyTCPServer tcp_sever;
    tcp_sever.start(NULL, 5150, 30);//根据负载和机器配置调整线程池线程数目
    //getchar();//后台运行会被停止
    pause();
    tcp_sever.stop();


    close_log_file();//关闭日志文件
    return 0;
}