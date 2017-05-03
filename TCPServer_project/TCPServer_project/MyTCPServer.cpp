#include "MyTCPServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include "log.h"


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