#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//usage: start_client 客户端程序路径 启动个数

int main(int argc, char *argv[])
{
    char path[512];
    strcpy(path, argv[1]);
    strcat(path, "&");

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        system(path);
        //每隔1秒启动1个，保证1个客户端单独一个日志文件，当然也可以几个客户端同一个日志文件
        usleep(1000 * 1001);
        printf("%d start\n", i);
    }

	return 0;
}
