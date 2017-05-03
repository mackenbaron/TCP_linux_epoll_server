#include "MyTCPClient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <errno.h>
#include "log.h"



void MyTCPClient::work(std::deque<char>& send_deque, std::deque<char>& recv_deque)
{
    usleep(1000 * 200);
    char buf[1024];
    int len = sprintf(buf, "i am client %d\n", (unsigned int)getpid());
    for (int i = 0; i < len; i++)  send_deque.push_back(buf[i]);

    std::string str;
    if (find(recv_deque.begin(), recv_deque.end(), '\n') != recv_deque.end())
    {
        int len = recv_deque.size();
        for (int j = 0; j < len; j++)
        {
            str += recv_deque.front();
            if ('\n' == recv_deque.front())
            {
                recv_deque.pop_front();
                LOGN("%s", str.c_str());
                break;
            }
            else
            {
                recv_deque.pop_front();
            }
        }
    }

    return;
}