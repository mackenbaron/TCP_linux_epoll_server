#ifndef MY_TCP_SERVER_H_
#define MY_TCP_SERVER_H_
#include "TCPServer.h"



class MyTCPServer : public TCPServer
{
public:
    MyTCPServer()  {};
    ~MyTCPServer() {};

protected:
    virtual void work(std::deque<char>& send_deque, std::deque<char>& recv_deque);
};

#endif