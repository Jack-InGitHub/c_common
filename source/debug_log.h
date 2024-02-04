/**
 * @file    debug.h
 * @author  PQ.liu(pq_liu@foxmail.com)
 * @brief   简单日志输出组件
 * @version 0.1.0
 * @date    2023-03-28
 * 
 * @section   History
 * <table>
 *     <tr><th>Version <th>Data        <th>Author  <th>Notes
 *     <tr><td>V0.0.1  <td>2021-10-26  <td>PQ      <td>First Version
 *     <tr><td>V0.0.2  <td>2023-03-24  <td>PQ.liu  <td>增加自动添加换行、增加日志所在行及所在文件显示
 *     <tr><td>V0.1.0  <td>2023-03-28  <td>PQ.liu  <td>增加DBG_LOG_E()等函数
 *     <tr><td>V0.2.0  <td>2024-02-04  <td>PQ.liu  <td>重构DBG_LOG()输出逻辑、将#ifdef更新为#if
 * </table>
 * @details 输出函数变更时，需要修改 _DBG_OUT_RAW 的重定向
 */
 /*
 __VA_ARGS__ 的可变参数不能为0
 ##__VA_ARGS__ 宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错。
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Redirect Includes ***************************/
#include <stdio.h>
#include <string.h>
#include <sys/times.h>          // 用于获取Ticks
/* Config --------------------------------------------------------------------*/
#define DEBUG_MAIN_OUT_EN                       1                   ///< DEBUG LOG MAIN EN  总开关

/* Config **************************************/
#define DEBUG_NEWLINE_EN                        0                   ///< 使能log换行
///< 指定行结束符 "\n" "\r\n" "\r" ...
#define DEBUG_NEWLINE_LINE_ENDINGS              "\n"

#define DEBUG_DISPLAY_FILE                      0                   ///< 日志输出当前 文件名
#define DEBUG_DISPLAY_LINE                      1                   ///< 日志输出当前 行号
#define DEBUG_DISPLAY_FUNC                      1                   ///< 日志输出当前 函数名
#define DEBUG_DISPLAY_TICKET                    1                   ///< 日志输出当前 系统时间

#define DBG_LOG_COLOR_EN                        1                   ///< 启用颜色支持

#define DBG_LOG_TIME_FUN_EN                     1                   ///< 启用 DBG_LOG_TIME() 的输出
#define DBG_LOG_RAW_FUN_EN                      1                   ///< 启用 DBG_LOG_RAW() 的输出
#define DBG_LOG_COL_FUN_EN                      1                   ///< 启用 DBG_LOG_COL() 的输出
#define DBG_LOG_FUN_EN                          1                   ///< 启用 DBG_LOG() 的输出
#define DBG_LOGx_FUN_EN                         1                   ///< 启用 DBG_LOGx() 的输出 e.g. DBG_LOGE() DBG_LOGF() ...

#define DBG_F                                   1                   ///< 1 启用 0关闭 FATAL    等级输出
#define DBG_E                                   2                   ///< 2 启用 0关闭 ERROR    等级输出
#define DBG_W                                   3                   ///< 3 启用 0关闭 WARNING  等级输出
#define DBG_I                                   4                   ///< 4 启用 0关闭 INFO     等级输出
#define DBG_D                                   5                   ///< 5 启用 0关闭 DEBUG    等级输出

/* tips
// 使用下面的定义在 x.c 文件内单独控制LOG的输出
// 关闭全部
#undef _DBG_OUT_RAW
#define _DBG_OUT_RAW(format, ...)               do{ }while(0)
// 关闭指定
#undef DBG_F
#define DBG_F                                   0
*/

/* Redirect ************************************/
#define _DBG_OUT_RAW(format, ...)               printf(format, ##__VA_ARGS__)  ///< 重定向DBG输出
#define _DBG_GET_TICKET()                       times(NULL)                    ///< 重定向 获取系统时间函数

/* DEFINE --------------------------------------------------------------------*/
#if DBG_LOG_COLOR_EN != 0
    /**Control sequences, based on ANSI.
     * Can be used to control color, and clear the screen
     */
    #define DBG_COL_RESET                       "\x1B[0m"           ///< Reset to default colors
    #define DBG_COL_CLEAR                       "\x1B[2J"           ///< Clear screen, reposition cursor to top left

    #define DBG_COL_TEXT_BLACK                  "\x1B[2;30m"
    #define DBG_COL_TEXT_RED                    "\x1B[2;31m"
    #define DBG_COL_TEXT_GREEN                  "\x1B[2;32m"
    #define DBG_COL_TEXT_YELLOW                 "\x1B[2;33m"
    #define DBG_COL_TEXT_BLUE                   "\x1B[2;34m"
    #define DBG_COL_TEXT_MAGENTA                "\x1B[2;35m"
    #define DBG_COL_TEXT_CYAN                   "\x1B[2;36m"
    #define DBG_COL_TEXT_WHITE                  "\x1B[2;37m"

    #define DBG_COL_TEXT_BRIGHT_BLACK           "\x1B[1;30m"
    #define DBG_COL_TEXT_BRIGHT_RED             "\x1B[1;31m"
    #define DBG_COL_TEXT_BRIGHT_GREEN           "\x1B[1;32m"
    #define DBG_COL_TEXT_BRIGHT_YELLOW          "\x1B[1;33m"
    #define DBG_COL_TEXT_BRIGHT_BLUE            "\x1B[1;34m"
    #define DBG_COL_TEXT_BRIGHT_MAGENTA         "\x1B[1;35m"
    #define DBG_COL_TEXT_BRIGHT_CYAN            "\x1B[1;36m"
    #define DBG_COL_TEXT_BRIGHT_WHITE           "\x1B[1;37m"

    #define DBG_COL_BG_BLACK                    "\x1B[24;40m"
    #define DBG_COL_BG_RED                      "\x1B[24;41m"
    #define DBG_COL_BG_GREEN                    "\x1B[24;42m"
    #define DBG_COL_BG_YELLOW                   "\x1B[24;43m"
    #define DBG_COL_BG_BLUE                     "\x1B[24;44m"
    #define DBG_COL_BG_MAGENTA                  "\x1B[24;45m"
    #define DBG_COL_BG_CYAN                     "\x1B[24;46m"
    #define DBG_COL_BG_WHITE                    "\x1B[24;47m"

    #define DBG_COL_BG_BRIGHT_BLACK             "\x1B[4;40m"
    #define DBG_COL_BG_BRIGHT_RED               "\x1B[4;41m"
    #define DBG_COL_BG_BRIGHT_GREEN             "\x1B[4;42m"
    #define DBG_COL_BG_BRIGHT_YELLOW            "\x1B[4;43m"
    #define DBG_COL_BG_BRIGHT_BLUE              "\x1B[4;44m"
    #define DBG_COL_BG_BRIGHT_MAGENTA           "\x1B[4;45m"
    #define DBG_COL_BG_BRIGHT_CYAN              "\x1B[4;46m"
    #define DBG_COL_BG_BRIGHT_WHITE             "\x1B[4;47m"

    #define DBG_COL(n)                          "\x1B[2;"#n"m"
    
    #define DBG_COL_DBG_F                       DBG_COL_BG_BRIGHT_RED DBG_COL_TEXT_BRIGHT_YELLOW
    #define DBG_COL_DBG_E                       DBG_COL_TEXT_RED
    #define DBG_COL_DBG_W                       DBG_COL_TEXT_YELLOW
    #define DBG_COL_DBG_I                       DBG_COL_TEXT_CYAN
    #define DBG_COL_DBG_D                       DBG_COL_TEXT_GREEN
#endif  /* end of DBG_LOG_COLOR_EN */

/* MACRO ---------------------------------------------------------------------*/
/**
 * @brief   自动换行配置
 */
#if DEBUG_NEWLINE_EN != 0
#define DEBUG_NEWLINE                           DEBUG_NEWLINE_LINE_ENDINGS
#else
#define DEBUG_NEWLINE
#endif

/**
 * @brief   指定日志参数
 */
#if DEBUG_DISPLAY_TICKET != 0
#define DEBUG_DISPLAY_TICKET_AVG                "[%u]"                          // "[%08u]" 指定宽度显示效果会好一些
#define DEBUG_DISPLAY_TICKET_STRING             ,_DBG_GET_TICKET()
#else
#define DEBUG_DISPLAY_TICKET_AVG                
#define DEBUG_DISPLAY_TICKET_STRING             
#endif

#if DEBUG_DISPLAY_FILE != 0
#define DEBUG_DISPLAY_FILE_AVG                  ":%s"
#define DEBUG_DISPLAY_FILE_STRING               ,__FILE__
#else
#define DEBUG_DISPLAY_FILE_AVG                  
#define DEBUG_DISPLAY_FILE_STRING               
#endif

#if DEBUG_DISPLAY_LINE != 0
#define DEBUG_DISPLAY_LINE_AVG                  ":%d"
#define DEBUG_DISPLAY_LINE_STRING               ,__LINE__
#else
#define DEBUG_DISPLAY_LINE_AVG                  
#define DEBUG_DISPLAY_LINE_STRING               
#endif

#if DEBUG_DISPLAY_FUNC != 0
#define DEBUG_DISPLAY_FUNC_AVG                  ":%s"
#define DEBUG_DISPLAY_FUNC_STRING               ,__func__
#else
#define DEBUG_DISPLAY_FUNC_AVG                  
#define DEBUG_DISPLAY_FUNC_STRING               
#endif


#if DEBUG_DISPLAY_FILE!=0 || DEBUG_DISPLAY_LINE!=0 || DEBUG_DISPLAY_FUNC!=0 
#define DEBUG_DISPLAY_PAR_AVG                   DEBUG_DISPLAY_TICKET_AVG "[" DEBUG_DISPLAY_FILE_AVG DEBUG_DISPLAY_LINE_AVG DEBUG_DISPLAY_FUNC_AVG "]:"
#define DEBUG_DISPLAY_PAR_STRING                DEBUG_DISPLAY_TICKET_STRING DEBUG_DISPLAY_FILE_STRING DEBUG_DISPLAY_LINE_STRING DEBUG_DISPLAY_FUNC_STRING
#elif DEBUG_DISPLAY_TICKET!=0
#define DEBUG_DISPLAY_PAR_AVG                   DEBUG_DISPLAY_TICKET_AVG
#define DEBUG_DISPLAY_PAR_STRING                DEBUG_DISPLAY_TICKET_STRING
#else
#define DEBUG_DISPLAY_PAR_AVG                   
#define DEBUG_DISPLAY_PAR_STRING                
#endif

/**
 * @brief   为日志添加换行的宏
 */
#define _DBG_OUT(format, ...)                   _DBG_OUT_RAW(format DEBUG_NEWLINE, ##__VA_ARGS__)

/**
 * @brief   为日志添加颜色的宏
 */
#if DBG_LOG_COLOR_EN != 0
// 这个很奇怪，必须要分开把这两个参数附加上去，如果只用一个宏把两个参数附加上去就会出错
#define __DBG_COL2(format, args...)             _DBG_OUT(format DBG_COL_RESET, ##args)
// DBG_COL_##level 是用来指定颜色的
#define _DBG_COL(level, format, args...)        __DBG_COL2(DBG_COL_##level format, ##args)
#endif

/**
 * @brief   DBG_LOG_RAW() 宏日志输出 
 * @details 无任何格式
 */
#if DBG_LOG_RAW_FUN_EN != 0
#define DBG_LOG_RAW(format, ...)                _DBG_OUT(format, ##__VA_ARGS__)
#else
#define DBG_LOG_RAW(format, ...)                do{}while(0)
#endif  /* end of DBG_LOG_RAW_FUN_EN */

/**
 * @brief   DBG_LOG_COL() 宏日志输出 
 * @details 输出带颜色的日志 
 * @param   color : 通过传入参数指定颜色
 */
#if DBG_LOG_COL_FUN_EN != 0
    #if DBG_LOG_COLOR_EN != 0
    #define DBG_LOG_COL(color, format, ...)     _DBG_OUT(color format DBG_COL_RESET, ##__VA_ARGS__)
    #else
    #define DBG_LOG_COL(color, format,...)      _DBG_OUT(format, ##__VA_ARGS__ )
    #endif  /* end of DBG_LOG_COLOR_EN */
#else
#define DBG_LOG_COL(color, format, ...)         do{}while(0)
#endif  /* end of DBG_LOG_COL_FUN_EN */

/**
 * @brief   DBG_LOG_TIME() 宏日志输出
 * @details 输出带时间的日志
 */
#if DBG_LOG_TIME_FUN_EN != 0
#define DBG_LOG_TIME(format, ...)               _DBG_OUT("[%u]" format, _DBG_GET_TICKET(), ##__VA_ARGS__)
#else
#define DBG_LOG_TIME(format, ...)               do{}while(0)
#endif // DBG_LOG_TIME_FUN_EN

/**
 * @brief   DBG_LOG() 宏日志输出
 * @details 按日志级别输出并格式化对应日志信息
 * @param   level 日志级别
 */
#if DBG_LOG_FUN_EN != 0
    #if DBG_LOG_COLOR_EN != 0
    #define DBG_LOG(level, format, ...)                                             \
    do {                                                                            \
        if (level != 0) {                                                           \
            if (level == DBG_F) {                                                   \
                _DBG_COL(DBG_F, "F:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
            } else if (level == DBG_E) {                                            \
                _DBG_COL(DBG_E, "E:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
            } else if (level == DBG_W) {                                            \
                _DBG_COL(DBG_W, "W:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
            } else if (level == DBG_I) {                                            \
                _DBG_COL(DBG_I, "I:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
            } else if (level == DBG_D) {                                            \
                _DBG_COL(DBG_D, "D:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
            }                                                                       \
        }                                                                           \
    }while(0)
    #else
    #define DBG_LOG(level, format, ...)         do{ if(level!=0){_DBG_OUT(#level ":" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__ );} }while(0)
    #endif  /* end of DBG_LOG_COLOR_EN */
#else
#define DBG_LOG(level, format, ...)             do{}while(0)
#endif /* end of DBG_LOG_FUN_EN */

/**
 * @brief   DBG_LOGx() 宏日志输出
 * @details 按日志级别输出并格式化对应日志信息
 */
#if DBG_F != 0 && DBG_LOGx_FUN_EN != 0
#if DBG_LOG_COLOR_EN != 0
#define DBG_LOGF(format,...)                    _DBG_COL(DBG_F, "Fatal:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOGF(format,...)                    _DBG_OUT("Fatal:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#endif
#else
#define DBG_LOGF(format,...)                    do{}while(0)
#endif

#if DBG_E != 0 && DBG_LOGx_FUN_EN != 0
#if DBG_LOG_COLOR_EN != 0
#define DBG_LOGE(format,...)                    _DBG_COL(DBG_E, "Error:"  DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOGE(format,...)                    _DBG_OUT("Error:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#endif
#else
#define DBG_LOGE(format,...)                    do{}while(0)
#endif

#if DBG_W != 0 && DBG_LOGx_FUN_EN != 0
#if DBG_LOG_COLOR_EN != 0
#define DBG_LOGW(format,...)                    _DBG_COL(DBG_W, "Waring:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOGW(format,...)                    _DBG_OUT("Waring:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#endif
#else
#define DBG_LOGW(format,...)                    do{}while(0)
#endif

#if DBG_I != 0 && DBG_LOGx_FUN_EN != 0
#if DBG_LOG_COLOR_EN != 0
#define DBG_LOGI(format,...)                    _DBG_COL(DBG_I, "Info:"   DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOGI(format,...)                    _DBG_OUT("Info:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#endif
#else
#define DBG_LOGI(format,...)                    do{}while(0)
#endif

#if DBG_D != 0 && DBG_LOGx_FUN_EN != 0
#if DBG_LOG_COLOR_EN != 0
#define DBG_LOGD(format,...)                    _DBG_COL(DBG_D, "Debug:"  DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOGD(format,...)                    _DBG_OUT("Debug:" DEBUG_DISPLAY_PAR_AVG format DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#endif
#else
#define DBG_LOGD(format,...)                    do{}while(0)
#endif


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* #ifndef _DEBUG_H_ */

#if 0
// log test functions
{
DBG_LOG_RAW("DBG_LOG_RAW() function test");
DBG_LOG_RAW("DBG_LOG_RAW() function test arguments %d %s", __LINE__, __DATE__);

DBG_LOG_COL( DBG_COL_TEXT_GREEN DBG_COL_BG_RED, "DBG_LOG_COL() function test");
DBG_LOG_COL( DBG_COL_TEXT_BLUE DBG_COL_BG_CYAN, "DBG_LOG_COL() function test arguments %d %s", __LINE__, __DATE__);

DBG_LOG_TIME("DBG_LOG_TIME() function test");
DBG_LOG_TIME("DBG_LOG_TIME() function test arguments %d %s", __LINE__, __DATE__);

DBG_LOG(DBG_F, "DBG_LOG(DBG_F) function test");
DBG_LOG(DBG_E, "DBG_LOG(DBG_E) function test");
DBG_LOG(DBG_W, "DBG_LOG(DBG_W) function test");
DBG_LOG(DBG_I, "DBG_LOG(DBG_I) function test");
DBG_LOG(DBG_D, "DBG_LOG(DBG_D) function test");
DBG_LOG(DBG_F, "DBG_LOG(DBG_F) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOG(DBG_E, "DBG_LOG(DBG_E) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOG(DBG_W, "DBG_LOG(DBG_W) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOG(DBG_I, "DBG_LOG(DBG_I) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOG(DBG_D, "DBG_LOG(DBG_D) function test arguments %d %s", __LINE__, __DATE__);


DBG_LOGF("DBG_LOG(DBG_F) function test");
DBG_LOGE("DBG_LOG(DBG_E) function test");
DBG_LOGW("DBG_LOG(DBG_W) function test");
DBG_LOGI("DBG_LOG(DBG_I) function test");
DBG_LOGD("DBG_LOG(DBG_D) function test");
DBG_LOGF("DBG_LOG(DBG_F) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOGE("DBG_LOG(DBG_E) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOGW("DBG_LOG(DBG_W) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOGI("DBG_LOG(DBG_I) function test arguments %d %s", __LINE__, __DATE__);
DBG_LOGD("DBG_LOG(DBG_D) function test arguments %d %s", __LINE__, __DATE__);
}
#endif
/* ------------------------------- END OF FILE ------------------------------- */
