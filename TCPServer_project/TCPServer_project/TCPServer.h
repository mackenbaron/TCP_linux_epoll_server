#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_
#include <deque>
#include <map>
#include <pthread.h>

class TCPServer
{
public:
    typedef struct _SERVERTHREADPOOL
    {
        pthread_t thread_id;
        int fd[2];
        int epoll_fd;
    } SERVER_THREAD_POOL, *P_SERVER_THREAD_POOL;

    typedef struct _THREADARG
    {
        int thread_num; //0开头
        void* p_this;
    } THREAD_ARG, *P_THREAD_ARG;

    typedef struct _CLIENTDEQUE
    {
        std::deque<char>  send_deque;
        std::deque<char>  recv_deque;
    } CLIENT_DEQUE;

    TCPServer();
    ~TCPServer();

    //如果IP等于NULL，表示INADDR_ANY
    int start(const char* ip, const int port, int thread_cnt);
    int stop();

protected:
    //只能从recv_deque出数据
    //只能往send_deque压数据
    //用户自行定义这个函数，从recv_deque取到接收好的数据，把要发送的数据放入send_deque
    //用户只使用这个函数可以不用关心网络细节
    virtual void work(std::deque<char>& send_deque, std::deque<char>& recv_deque);

private:
    int read_from_client(int fd, std::deque<char>& recv_deque);
    int write_to_client(int fd, std::deque<char>& send_deque);
    int create_thread_pool(int thread_cnt);
    int get_listen_socket(const char* ip, const int port, const int backlog); //SOMAXCONN
    static void* client_thread(void*);
    static void* accept_thread(void*);
    P_SERVER_THREAD_POOL m_thread_pool;
    int m_thread_cnt;
    bool m_run_flag;
    pthread_t m_accept_thread_id;
    int m_listen_socket;
    int m_epoll_fd;
};

#endif