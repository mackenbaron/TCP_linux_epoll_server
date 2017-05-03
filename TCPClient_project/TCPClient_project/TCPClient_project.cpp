#include <stdio.h>
#include <unistd.h>
#include "MyTCPClient.h"
#include "log.h"
//https://github.com/lihaitao8233/TCP_linux_epoll_server.git  //转载请保留此地址
//linux epoll模型编写的高并发TCP网络服务端，配有相应的测试客户端代码，可以启动多个客户端进行调试
//https://github.com/lihaitao8233/TCPServer_windows_iocp,这个是windows下完成端口IOCP模型编写的高并发TCP网络服务端，
//linux 和 windows的接口完全一样。

int  main()
{
    open_log_file("/home/lht/server", "client", 1);  //打开日志文件，保留1天
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);


    MyTCPClient my_tcp_client;
    my_tcp_client.start("192.168.96.139", 5150);
    //getchar();//后台运行程序会被停止
    pause();
    my_tcp_client.stop();



    close_log_file();//关闭日志文件
    return 0;
}



