#include "MyTCPServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include "log.h"

//https://github.com/lihaitao8233/TCP_linux_epoll_server.git  //转载请保留此地址
//linux epoll模型编写的高并发TCP网络服务端，配有相应的测试客户端代码，可以启动多个客户端进行调试
//https://github.com/lihaitao8233/TCPServer_windows_iocp,这个是windows下完成端口IOCP模型编写的高并发TCP网络服务端，
//linux 和 windows的接口完全一样。


void MyTCPServer::work(std::deque<char>& send_deque, std::deque<char>& recv_deque)
{
    int size = recv_deque.size();
    for (int i = 0; i < size; i++)
    {
        if ((recv_deque.front() >= 'a') && (recv_deque.front() <= 'z'))
        {
            send_deque.push_back(recv_deque.front() - 32);
        }
        else
        {
            send_deque.push_back(recv_deque.front());
        }

        recv_deque.pop_front();
    }
}