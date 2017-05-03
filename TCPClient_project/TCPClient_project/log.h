#ifndef LOG_H_
#define LOG_H_

#define LOG_ERROR_LEVEL     1
#define LOG_NORMAL_LEVEL    2
#define LOG_DEBUG_LEVEL     4
#define LOGE(...)        _log1(LOG_ERROR_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define LOGN(...)        _log1(LOG_NORMAL_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define LOGD(...)        _log1(LOG_DEBUG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

//file_name_key日志文件名称的关键字，不允许有-减号字符， 否则清理日志功能会出错
//日志文件路径名称如下：每次根据程序启动时间生成新的日志文件，test即为file_name_key
//dir\test-2017-03-09-09-06-03.log
int open_log_file(const char* dir, const char* file_name_key, const int days = -1);
int close_log_file();

//清除超过指定天数的日志，open_log_file之后调用
int clear_log(const int days);
void set_log_level(int level = 1);
int get_log_level();

//基础log函数  输出： [年-月-日-时-分-秒]文件-行号-函数名称:
//系统错误描述
//用户描述
int _log1(int type, const char* file_name, int line, const char* func_name, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
