/**
 * @file    debug.h
 * @author  PQ.liu(pq_liu@foxmail.com)
 * @brief   简单日志输出组件
 * @version V1.0.1
 * @date    2023-03-28
 *
 * @section   History
 * <table>
 *     <tr><th>Version <th>Data        <th>Author  <th>Notes
 *     <tr><td>V0.0.1  <td>2021-10-26  <td>PQ      <td>First Version
 *     <tr><td>V0.0.2  <td>2023-03-24  <td>PQ.liu  <td>增加自动添加换行、增加日志所在行及所在文件显示
 *     <tr><td>V0.1.0  <td>2023-03-28  <td>PQ.liu  <td>增加DBG_LOG_E()等函数
 *     <tr><td>V0.2.0  <td>2024-02-04  <td>PQ.liu  <td>重构DBG_LOG()输出逻辑、将#ifdef更新为#if
 *     <tr><td>V1.0.0  <td>2024-07-21  <td>Oikiou  <td>重命名日志输出函数
 * </table>
 * @details 输出函数变更时，需要修改 _LOG_OUT_RAW 的重定向
 */
 /*
 __VA_ARGS__ 的可变参数不能为0
 ##__VA_ARGS__ 宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错。
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_LOG_H_
#define _DEBUG_LOG_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Redirect Includes ***************************/
#if defined(_WIN32)
#include <stdio.h>
#include <string.h>
#include <windows.h>
#elif defined(__linux__) || defined(__linux) || defined(linux)
#include <stdio.h>
#include <string.h>
#include <sys/times.h>
#else   // user defined

#endif

/* Config --------------------------------------------------------------------*/
#define LOG_MAIN_OUT_EN                             1                   ///< DEBUG LOG MAIN EN  总开关

/* Config **************************************/
#define LOG_NEWLINE_EN                              1                   ///< 使能log换行
///< 指定行结束符 "\n" "\r\n" "\r" ...
#if defined(_WIN32)
    #define LOG_NEWLINE_LINE_ENDINGS                "\r\n"
#else
    #define LOG_NEWLINE_LINE_ENDINGS                "\n"
#endif

#define LOG_DISPLAY_FILE                            0                   ///< 日志输出当前 文件名
#define LOG_DISPLAY_LINE                            1                   ///< 日志输出当前 行号
#define LOG_DISPLAY_FUNC                            0                   ///< 日志输出当前 函数名
#define LOG_DISPLAY_TICKET                          1                   ///< 日志输出当前 系统时间

#define LOG_COLOR_EN                                1                   ///< 启用颜色支持

#define LOG_TIME_FUN_EN                             1                   ///< 启用 LOG_TIME() 的输出
#define LOG_PRINTF_FUN_EN                           1                   ///< 启用 LOG_PRINTF() 的输出
#define LOG_RAW_FUN_EN                              1                   ///< 启用 LOG_RAW() 的输出
#define LOG_COL_FUN_EN                              1                   ///< 启用 LOG_COL() 的输出
#define LOG_FUN_EN                                  1                   ///< 启用 LOG() 的输出
#define LOGx_FUN_EN                                 1                   ///< 启用 LOGx() 的输出 e.g. LOG_E() LOG_F() ...

#define LOGF                                        0x5F                ///< 0x5F 启用 0关闭 FATAL    等级输出
#define LOGE                                        0x4F                ///< 0x4F 启用 0关闭 ERROR    等级输出
#define LOGW                                        0x3F                ///< 0x3F 启用 0关闭 WARNING  等级输出
#define LOGI                                        0x2F                ///< 0x2F 启用 0关闭 INFO     等级输出
#define LOGD                                        0x1F                ///< 0x1F 启用 0关闭 DEBUG    等级输出
#define LOGD3                                       0x13                ///< 0x13 启用 0关闭 DEBUG    等级输出
#define LOGD2                                       0x12                ///< 0x12 启用 0关闭 DEBUG    等级输出
#define LOGD1                                       0x11                ///< 0x11 启用 0关闭 DEBUG    等级输出
#define LOGD0                                       0x10                ///< 0x10 启用 0关闭 DEBUG    等级输出

/* tips
// 使用下面的定义在 x.c 文件内单独控制LOG的输出
// 关闭全部
#undef _LOG_OUT_RAW
#define _LOG_OUT_RAW(format, ...)               do{ }while(0)
// 关闭指定
#undef LOGF
#define LOGF                                    0
*/

/* Redirect ************************************/
#if LOG_MAIN_OUT_EN!=0
    #define _LOG_OUT_RAW(format, ...)               printf(format, ##__VA_ARGS__)   ///< 重定向DBG输出
#else
    #define _LOG_OUT_RAW(format, ...)
#endif

#if defined(_WIN32)
    #define _LOG_GET_TICKET_AVG                     "%lu"
    #define _LOG_GET_TICKET()                       GetTickCount()                  ///< 重定向 获取系统时间函数
#elif defined(__linux__) || defined(__linux) || defined(linux)
    #define _LOG_GET_TICKET_AVG                     "%lu"
    #define _LOG_GET_TICKET()                       times(NULL)                     ///< 重定向 获取系统时间函数
#else // user defined
    #define _LOG_GET_TICKET_AVG                     "%u"
    #define _LOG_GET_TICKET()                       xTaskGetTickCount(NULL)         ///< 重定向 获取系统时间函数
#endif

/* DEFINE --------------------------------------------------------------------*/
#if LOG_COLOR_EN != 0
    /**Control sequences, based on ANSI.
     * Can be used to control color, and clear the screen
     */
    #define LOG_COL_RESET                           "\x1B[0m"           ///< Reset to default colors
    #define LOG_COL_CLEAR                           "\x1B[2J"           ///< Clear screen, reposition cursor to top left

    #define LOG_COL_TEXT_BLACK                      "\x1B[2;30m"
    #define LOG_COL_TEXT_RED                        "\x1B[2;31m"
    #define LOG_COL_TEXT_GREEN                      "\x1B[2;32m"
    #define LOG_COL_TEXT_YELLOW                     "\x1B[2;33m"
    #define LOG_COL_TEXT_BLUE                       "\x1B[2;34m"
    #define LOG_COL_TEXT_MAGENTA                    "\x1B[2;35m"
    #define LOG_COL_TEXT_CYAN                       "\x1B[2;36m"
    #define LOG_COL_TEXT_WHITE                      "\x1B[2;37m"

    #define LOG_COL_TEXT_BRIGHT_BLACK               "\x1B[1;30m"
    #define LOG_COL_TEXT_BRIGHT_RED                 "\x1B[1;31m"
    #define LOG_COL_TEXT_BRIGHT_GREEN               "\x1B[1;32m"
    #define LOG_COL_TEXT_BRIGHT_YELLOW              "\x1B[1;33m"
    #define LOG_COL_TEXT_BRIGHT_BLUE                "\x1B[1;34m"
    #define LOG_COL_TEXT_BRIGHT_MAGENTA             "\x1B[1;35m"
    #define LOG_COL_TEXT_BRIGHT_CYAN                "\x1B[1;36m"
    #define LOG_COL_TEXT_BRIGHT_WHITE               "\x1B[1;37m"

    #define LOG_COL_BG_BLACK                        "\x1B[24;40m"
    #define LOG_COL_BG_RED                          "\x1B[24;41m"
    #define LOG_COL_BG_GREEN                        "\x1B[24;42m"
    #define LOG_COL_BG_YELLOW                       "\x1B[24;43m"
    #define LOG_COL_BG_BLUE                         "\x1B[24;44m"
    #define LOG_COL_BG_MAGENTA                      "\x1B[24;45m"
    #define LOG_COL_BG_CYAN                         "\x1B[24;46m"
    #define LOG_COL_BG_WHITE                        "\x1B[24;47m"

    #define LOG_COL_BG_BRIGHT_BLACK                 "\x1B[4;40m"
    #define LOG_COL_BG_BRIGHT_RED                   "\x1B[4;41m"
    #define LOG_COL_BG_BRIGHT_GREEN                 "\x1B[4;42m"
    #define LOG_COL_BG_BRIGHT_YELLOW                "\x1B[4;43m"
    #define LOG_COL_BG_BRIGHT_BLUE                  "\x1B[4;44m"
    #define LOG_COL_BG_BRIGHT_MAGENTA               "\x1B[4;45m"
    #define LOG_COL_BG_BRIGHT_CYAN                  "\x1B[4;46m"
    #define LOG_COL_BG_BRIGHT_WHITE                 "\x1B[4;47m"

    #define LOG_COL_N(n)                            "\x1B[2;"#n"m"

    #define LOG_COL_LOGF                            LOG_COL_BG_BRIGHT_RED LOG_COL_TEXT_BRIGHT_YELLOW
    #define LOG_COL_LOGE                            LOG_COL_TEXT_RED
    #define LOG_COL_LOGW                            LOG_COL_TEXT_YELLOW
    #define LOG_COL_LOGI                            LOG_COL_TEXT_CYAN
    #define LOG_COL_LOGD                            LOG_COL_TEXT_GREEN
    #define LOG_COL_LOGD3
    #define LOG_COL_LOGD2
    #define LOG_COL_LOGD1
#endif  /* end of LOG_COLOR_EN */

/* MACRO ---------------------------------------------------------------------*/
/**
 * @brief   自动换行配置
 */
#if LOG_NEWLINE_EN != 0
    #define LOG_NEWLINE                             LOG_NEWLINE_LINE_ENDINGS
#else
    #define LOG_NEWLINE
#endif

/**
 * @brief   指定日志参数
 */
#if LOG_DISPLAY_TICKET != 0
    #define LOG_DISPLAY_TICKET_AVG                  _LOG_GET_TICKET_AVG                   // "[%08u]" 指定宽度显示效果会好一些
    #define LOG_DISPLAY_TICKET_STRING               ,_LOG_GET_TICKET()
#else
    #define LOG_DISPLAY_TICKET_AVG
    #define LOG_DISPLAY_TICKET_STRING
#endif

#if LOG_DISPLAY_FILE != 0
    #define LOG_DISPLAY_FILE_AVG                    ":%s"
    #define LOG_DISPLAY_FILE_STRING                 ,__FILE__
#else
    #define LOG_DISPLAY_FILE_AVG
    #define LOG_DISPLAY_FILE_STRING
#endif

#if LOG_DISPLAY_LINE != 0
    #define LOG_DISPLAY_LINE_AVG                    ":%d"
    #define LOG_DISPLAY_LINE_STRING                 ,__LINE__
#else
    #define LOG_DISPLAY_LINE_AVG
    #define LOG_DISPLAY_LINE_STRING
#endif

#if LOG_DISPLAY_FUNC != 0
    #define LOG_DISPLAY_FUNC_AVG                    ":%s"
    #define LOG_DISPLAY_FUNC_STRING                 ,__func__
#else
    #define LOG_DISPLAY_FUNC_AVG
    #define LOG_DISPLAY_FUNC_STRING
#endif


#if LOG_DISPLAY_FILE!=0 || LOG_DISPLAY_LINE!=0 || LOG_DISPLAY_FUNC!=0
    #define LOG_DISPLAY_PAR_AVG                     "<" LOG_DISPLAY_TICKET_AVG ">" "[" LOG_DISPLAY_FILE_AVG LOG_DISPLAY_LINE_AVG LOG_DISPLAY_FUNC_AVG "]:"
    #define LOG_DISPLAY_PAR_STRING                  LOG_DISPLAY_TICKET_STRING LOG_DISPLAY_FILE_STRING LOG_DISPLAY_LINE_STRING LOG_DISPLAY_FUNC_STRING
#elif LOG_DISPLAY_TICKET!=0
    #define LOG_DISPLAY_PAR_AVG                     "<" LOG_DISPLAY_TICKET_AVG ">"
    #define LOG_DISPLAY_PAR_STRING                  LOG_DISPLAY_TICKET_STRING
#else
    #define LOG_DISPLAY_PAR_AVG
    #define LOG_DISPLAY_PAR_STRING
#endif

/**
 * @brief   为日志添加换行的宏
 */
#define _LOG_OUT_NEWLINE(format, ...)               _LOG_OUT_RAW(format LOG_NEWLINE, ##__VA_ARGS__)
#define _LOG_OUT(format, ...)                       _LOG_OUT_NEWLINE(format, ##__VA_ARGS__)

/**
 * @brief   为日志添加颜色的宏
 */
#if LOG_COLOR_EN != 0
    // 这个很奇怪，必须要分开把这两个参数附加上去，如果只用一个宏把两个参数附加上去就会出错
    #define __LOG_COL2(format, args...)             _LOG_OUT(format LOG_COL_RESET, ##args)
    // LOG_COL_##level 是用来指定颜色的
    #define _LOG_COL(level, format, args...)        __LOG_COL2(LOG_COL_##level format, ##args)
#endif

/**
 * @brief   LOG_RAW() 宏日志输出
 * @details 原样输出
 */
#if LOG_RAW_FUN_EN != 0
    #define LOG_RAW(format, ...)                    _LOG_OUT_RAW(format, ##__VA_ARGS__)
#else
    #define LOG_RAW(format, ...)                    do{}while(0)
#endif  /* end of LOG_RAW_FUN_EN */

/**
 * @brief   LOG_PRINTF() 宏日志输出
 * @details 仅带换行
 */
#if LOG_PRINTF_FUN_EN != 0
    #define LOG_PRINTF(format, ...)                 _LOG_OUT(format, ##__VA_ARGS__)
#else
    #define LOG_PRINTF(format, ...)                 do{}while(0)
#endif  /* end of LOG_RAW_FUN_EN */

/**
 * @brief   LOG_COL() 宏日志输出
 * @details 输出带颜色的日志
 * @param   color : 通过传入参数指定颜色
 */
#if LOG_COL_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_COL(color, format, ...)         _LOG_OUT(color format LOG_COL_RESET, ##__VA_ARGS__)
    #else
        #define LOG_COL(color, format,...)          _LOG_OUT(format, ##__VA_ARGS__ )
    #endif  /* end of LOG_COLOR_EN */
#else
    #define LOG_COL(color, format, ...)             do{}while(0)
#endif  /* end of LOG_COL_FUN_EN */

/**
 * @brief   LOG_TIME() 宏日志输出
 * @details 输出带时间的日志
 */
#if LOG_TIME_FUN_EN != 0
    #define LOG_TIME(format, ...)                   _LOG_OUT(_LOG_GET_TICKET_AVG format, _LOG_GET_TICKET(), ##__VA_ARGS__)
#else
    #define LOG_TIME(format, ...)                   do{}while(0)
#endif // LOG_TIME_FUN_EN

/**
 * @brief   LOG() 宏日志输出
 * @details 按日志级别输出并格式化对应日志信息
 * @param   level 日志级别
 */
#if LOG_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG(level, format, ...)                                             \
        do {                                                                            \
            if (level != 0) {                                                           \
                if (level == LOGF) {                                                   \
                    _LOG_COL(LOGF, "F:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
                } else if (level == LOGE) {                                            \
                    _LOG_COL(LOGE, "E:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
                } else if (level == LOGW) {                                            \
                    _LOG_COL(LOGW, "W:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
                } else if (level == LOGI) {                                            \
                    _LOG_COL(LOGI, "I:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
                } else if (level == LOGD || level == LOGD3 || level == LOGD2 ||  level == LOGD1) { \
                    _LOG_COL(LOGD, "D:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
                }                                                                       \
            }                                                                           \
        }while(0)
    #else
        #define LOG(level, format, ...)             do{ if(level!=0){_LOG_OUT(#level ":" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__ );} }while(0)
    #endif  /* end of LOG_COLOR_EN */
#else
    #define LOG(level, format, ...)                 do{}while(0)
#endif /* end of LOG_FUN_EN */

/**
 * @brief   LOGx() 宏日志输出
 * @details 按日志级别输出并格式化对应日志信息
 */
#if LOGF != 0 && LOGx_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_F(format,...)                   _LOG_COL(LOGF, "F:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #else
        #define LOG_F(format,...)                   _LOG_OUT("F:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #endif
#else
    #define LOG_F(format,...)                       do{}while(0)
#endif

#if LOGE != 0 && LOGx_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_E(format,...)                   _LOG_COL(LOGE, "E:"  LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #else
        #define LOG_E(format,...)                   _LOG_OUT("E:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #endif
#else
    #define LOG_E(format,...)                       do{}while(0)
#endif

#if LOGW != 0 && LOGx_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_W(format,...)                   _LOG_COL(LOGW, "W:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #else
        #define LOG_W(format,...)                   _LOG_OUT("W:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #endif
#else
    #define LOG_W(format,...)                       do{}while(0)
#endif

#if LOGI != 0 && LOGx_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_I(format,...)                   _LOG_COL(LOGI, "I:"   LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #else
        #define LOG_I(format,...)                   _LOG_OUT("I:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #endif
#else
    #define LOG_I(format,...)                       do{}while(0)
#endif

#if LOGD != 0 && LOGx_FUN_EN != 0
    #if LOG_COLOR_EN != 0
        #define LOG_D(format,...)                   _LOG_COL(LOGD, "D:"  LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #else
        #define LOG_D(format,...)                   _LOG_OUT("D:" LOG_DISPLAY_PAR_AVG format LOG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
    #endif
#else
    #define LOG_D(format,...)                       do{}while(0)
#endif


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* #ifndef _DEBUG_LOG_H_ */

#if 0
// log test functions
{
    LOG_RAW("LOG_RAW() function test");
    LOG_RAW("LOG_RAW() function test arguments %d %s", __LINE__, __DATE__);

    LOG_COL( LOG_COL_TEXT_GREEN LOG_COL_BG_RED, "LOG_COL() function test");
    LOG_COL( LOG_COL_TEXT_BLUE LOG_COL_BG_CYAN, "LOG_COL() function test arguments %d %s", __LINE__, __DATE__);

    LOG_TIME("LOG_TIME() function test");
    LOG_TIME("LOG_TIME() function test arguments %d %s", __LINE__, __DATE__);

    LOG(LOGF, "LOG(LOGF) function test");
    LOG(LOGE, "LOG(LOGE) function test");
    LOG(LOGW, "LOG(LOGW) function test");
    LOG(LOGI, "LOG(LOGI) function test");
    LOG(LOGD, "LOG(LOGD) function test");
    LOG(LOGF, "LOG(LOGF) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGE, "LOG(LOGE) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGW, "LOG(LOGW) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGI, "LOG(LOGI) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGD, "LOG(LOGD) function test arguments %d %s", __LINE__, __DATE__);


    LOG_F("LOG_F() function test");
    LOG_E("LOG_E() function test");
    LOG_W("LOG_W() function test");
    LOG_I("LOG_I() function test");
    LOG_D("LOG_D() function test");
    LOG_F("LOG_F() function test arguments %d %s", __LINE__, __DATE__);
    LOG_E("LOG_E() function test arguments %d %s", __LINE__, __DATE__);
    LOG_W("LOG_W() function test arguments %d %s", __LINE__, __DATE__);
    LOG_I("LOG_I() function test arguments %d %s", __LINE__, __DATE__);
    LOG_D("LOG_D() function test arguments %d %s", __LINE__, __DATE__);
}
#endif
/* ------------------------------- END OF FILE ------------------------------- */
