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
 * </table>
 * @details 输出函数变更时，需要修改 _DBG_OUT_RAW 的重定向
 */
 /*
 __VA_ARGS__   的可变参数不能为0
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
#define DEBUG_MAIN_OUT_EN                                           ///< DEBUG LOG MAIN EN  总开关

/* Config **************************************/
#ifdef  DEBUG_MAIN_OUT_EN

#define DEBGU_NEWLINE_EN                                            ///< 使能log换行

// #define DEBUG_DISPLAY_FILE                                          ///< 日志输出当前 文件名
#define DEBUG_DISPLAY_LINE                                          ///< 日志输出当前 行号
#define DEBUG_DISPLAY_FUNC                                          ///< 日志输出当前 函数名
#define DEBUG_DISPLAY_TICKET                                        ///< 日志输出当前 系统时间

#define DBG_LOG_COLOR_EN                                            ///< 启用颜色支持

#define DBG_TIME_FUN_EN                                             ///< 启用DBG_TIME() 宏 的输出
#define DBG_PRINT_FUN_EN                                            ///< 启用DBG_PRINT() 宏 的输出
#define DBG_LOG_COL_FUN_EN                                          ///< 启用DBG_LOG_COL() 宏 的输出
#define DBG_LOG_FUN_EN                                              ///< 启用DBG_LOG() 宏 的输出

#define DBG_F                                   1                   ///< 1 启用 0关闭 FATAL    等级输出
#define DBG_E                                   2                   ///< 2 启用 0关闭 ERROR    等级输出
#define DBG_W                                   3                   ///< 3 启用 0关闭 WARNING  等级输出
#define DBG_I                                   4                   ///< 4 启用 0关闭 INFO     等级输出
#define DBG_D                                   5                   ///< 5 启用 0关闭 DEBUG    等级输出
// // 使用下面的定义在 x.c 文件内单独控制LOG的输出
// #ifdef DBG_F
// #undef DBG_F
// #define DBG_F                                   0                   ///< 1 启用 0关闭 FATAL    等级输出
// #endif
#endif /* end of #ifdef DEBUG_MAIN_OUT_EN */

/* Redirect ************************************/
#define _DBG_OUT_RAW(format, ...)               printf(format, ##__VA_ARGS__)  ///< 重定向DBG输出
#define _DBG_GET_TICKET()                       times(NULL)                    ///< 重定向 获取系统时间函数

/* DEFINE --------------------------------------------------------------------*/
#ifdef DBG_LOG_COLOR_EN
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
#endif  /* end of DBG_LOG_COLOR_EN */

/* MACRO ---------------------------------------------------------------------*/
#ifdef  DEBUG_NEWLINE_EN
#define DEBUG_NEWLINE                           "\n"
#else
#define DEBUG_NEWLINE
#endif

#ifdef DEBUG_DISPLAY_TICKET
#define DEBUG_DISPLAY_TICKET_AVG                "[%lu]"                          //"[%08u]"
#define DEBUG_DISPLAY_TICKET_STRING             _DBG_GET_TICKET(),
#else
#define DEBUG_DISPLAY_TICKET_AVG                
#define DEBUG_DISPLAY_TICKET_STRING             
#endif

#ifdef DEBUG_DISPLAY_FILE
#define DEBUG_DISPLAY_FILE_AVG                  ":%s"
#define DEBUG_DISPLAY_FILE_STRING               __FILE__,
#else
#define DEBUG_DISPLAY_FILE_AVG                  
#define DEBUG_DISPLAY_FILE_STRING               
#endif

#ifdef DEBUG_DISPLAY_LINE
#define DEBUG_DISPLAY_LINE_AVG                  ":%d"
#define DEBUG_DISPLAY_LINE_STRING               __LINE__,
#else
#define DEBUG_DISPLAY_LINE_AVG                  
#define DEBUG_DISPLAY_LINE_STRING               
#endif

#ifdef DEBUG_DISPLAY_FUNC
#define DEBUG_DISPLAY_FUNC_AVG                  ":%s"
#define DEBUG_DISPLAY_FUNC_STRING               __func__            // TDB
#else
#define DEBUG_DISPLAY_FUNC_AVG                  
#define DEBUG_DISPLAY_FUNC_STRING               
#endif

#if defined(DEBUG_DISPLAY_FILE) || defined(DEBUG_DISPLAY_LINE) || defined(DEBUG_DISPLAY_FUNC) 
#define DEBUG_DISPLAY_PAR_AVG                   DEBUG_DISPLAY_TICKET_AVG "[" DEBUG_DISPLAY_FILE_AVG DEBUG_DISPLAY_LINE_AVG DEBUG_DISPLAY_FUNC_AVG "]:"
#define DEBUG_DISPLAY_PAR_STRING                DEBUG_DISPLAY_TICKET_STRING DEBUG_DISPLAY_FILE_STRING DEBUG_DISPLAY_LINE_STRING DEBUG_DISPLAY_FUNC_STRING
#else
#define DEBUG_DISPLAY_PAR_AVG                   DEBUG_DISPLAY_TICKET_AVG
#define DEBUG_DISPLAY_PAR_STRING                DEBUG_DISPLAY_TICKET_STRING
#endif

#ifdef  DEBGU_DISPLAY_FILE_AND_LINE_EN
#define _DBG_OUT(format, ...)                   _DBG_OUT_RAW("[%s:%d]" format DEBGU_NEWLINE, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define _DBG_OUT(format, ...)                   _DBG_OUT_RAW(format DEBGU_NEWLINE, ##__VA_ARGS__)
#endif

#ifdef DBG_PRINT_FUN_EN
#define DBG_PRINT(format, ...)                  _DBG_OUT(format, ##__VA_ARGS__)
#else
#define DBG_PRINT(format, ...)                  do{}while(0)
#endif  /* end of DBG_PRINT_FUN_EN */

#ifdef DBG_LOG_COL_FUN_EN
    #ifdef DBG_LOG_COLOR_EN
    #define DBG_LOG_COL(color, format, ...)     _DBG_OUT(color format DBG_COL_RESET, ##__VA_ARGS__ )
    #else
    #define DBG_LOG_COL(color, format,...)      _DBG_OUT(format, ##__VA_ARGS__ )
    #endif  /* end of DBG_LOG_COLOR_EN */
#else
#define DBG_LOG_COL(color, format, ...)         do{}while(0)
#endif  /* end of DBG_LOG_COL_FUN_EN */

#ifdef DBG_TIME_FUN_EN
#define DBG_TIME(format, ...)                   _DBG_OUT("[%lu]" format, _DBG_GET_TICKET(), ##__VA_ARGS__)
#else
#define DBG_TIME(format, ...)                   do{}while(0)
#endif // DBG_TIME_FUN_EN

#ifdef DBG_LOG_FUN_EN
    #ifdef DBG_LOG_COLOR_EN
    #define DBG_LOG(type, format, ...)                                              \
    do {                                                                            \
        if (type == 0) {                                                            \
            do{}while(0);                                                           \
        }                                                                           \
        else if (type == DBG_F) {                                                   \
            _DBG_OUT(DBG_COL_BG_BRIGHT_RED DBG_COL_TEXT_BRIGHT_YELLOW "F:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
        }                                                                           \
        else if (type == DBG_E) {                                                   \
            _DBG_OUT(DBG_COL_TEXT_RED    "E:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
        }                                                                           \
        else if (type == DBG_W) {                                                   \
            _DBG_OUT(DBG_COL_TEXT_YELLOW "W:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
        }                                                                           \
        else if (type == DBG_I) {                                                   \
            _DBG_OUT(DBG_COL_TEXT_CYAN   "I:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
        }                                                                           \
        else if (type == DBG_D) {                                                   \
            _DBG_OUT(DBG_COL_TEXT_GREEN  "D:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__); \
        }                                                                           \
    }while(0)
    #else
    #define DBG_LOG(type, format, ...)          do{ if(type!=0){_DBG_OUT(#type ":" DEBUG_DISPLAY_PAR_AVG format, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__ );} }while(0)
    #endif  /* end of DBG_LOG_COLOR_EN */
#else
#define DBG_LOG(type, format, ...)              do{}while(0)
#endif /* end of DBG_LOG_FUN_EN */

#if DBG_F != 0
#define DBG_LOG_F(format,...)                   _DBG_OUT(DBG_COL_BG_BRIGHT_RED DBG_COL_TEXT_BRIGHT_YELLOW "Fatal:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOG_F(format,...)                   do{}while(0)
#endif

#if DBG_E != 0
#define DBG_LOG_E(format,...)                   _DBG_OUT(DBG_COL_TEXT_RED    "Error:"  DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOG_E(format,...)                   do{}while(0)
#endif

#if DBG_W != 0
#define DBG_LOG_W(format,...)                   _DBG_OUT(DBG_COL_TEXT_YELLOW "Waring:" DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOG_W(format,...)                   do{}while(0)
#endif

#if DBG_I != 0
#define DBG_LOG_I(format,...)                   _DBG_OUT(DBG_COL_TEXT_CYAN   "Info:"   DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOG_I(format,...)                   do{}while(0)
#endif

#if DBG_D != 0
#define DBG_LOG_D(format,...)                   _DBG_OUT(DBG_COL_RESET       "Debug:"  DEBUG_DISPLAY_PAR_AVG format DBG_COL_RESET, DEBUG_DISPLAY_PAR_STRING, ##__VA_ARGS__)
#else
#define DBG_LOG_D(format,...)                   do{}while(0)
#endif



#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* #ifndef _DEBUG_H_ */
/* ------------------------------- END OF FILE ------------------------------- */
