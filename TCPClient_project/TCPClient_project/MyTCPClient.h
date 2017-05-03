#ifndef MY_TCP_CIENT_H_
#define MY_TCP_CIENT_H_

#include "TCPClient.h"


class MyTCPClient : public TCPClient
{
public:
    MyTCPClient()  {};
    ~MyTCPClient()  {};

protected:
    virtual void work(std::deque<char>& send_deque, std::deque<char>& recv_deque);
};

#endif
