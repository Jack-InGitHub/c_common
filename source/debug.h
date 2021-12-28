/**
 * @file    debug.h
 * @author  PQ(pq_liu@foxmail.com)
 * @brief   
 * @version 0.1
 * @date    2021-10-26
 * 
 * @section   History
 * <table>
 *     <tr><th>Version <th>Data        <th>Author  <th>Notes
 *     <tr><td>V0.1    <td>2021-10-26  <td>PQ      <td>First Version
 * </table>
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "SEGGER_RTT.h"


/* Exported define -----------------------------------------------------------*/
#define DEBUG_MAIN_OUT_EN                                           ///< DEBUG LOG MAIN EN  总开关


/* DEBUG **************************************/
#ifdef DEBUG_MAIN_OUT_EN
#define _DBG_OUT(format, ...)                   SEGGER_RTT_printf(0,format, ##__VA_ARGS__) ///< redirect dbg out
#define DBG_PRINT_EN                                                ///< 启用DBG_PRINT()输出
#define DBG_LOG_EN                                                  ///< 启用DBG_LOG()输出
#define DBG_LOG_COLOR_EN                                            ///< 启用DBG_LOG_COL()颜色输出

#define DBG_E                                   1                   ///< 1 启用 0关闭 ERROR    等级输出
#define DBG_W                                   2                   ///< 2 启用 0关闭 WARNING  等级输出
#define DBG_I                                   3                   ///< 3 启用 0关闭 INFO     等级输出
#define DBG_D                                   4                   ///< 4 启用 0关闭 DEBUG    等级输出
#endif /* end of #ifdef DEBUG_MAIN_OUT_EN */

/* Exported macro ------------------------------------------------------------*/
/* DEBUG **************************************/
#ifdef DBG_LOG_COLOR_EN
/**Control sequences, based on ANSI.
 * Can be used to control color, and clear the screen
 */
#define DBG_COL_RESET                           "\x1B[0m"           ///< Reset to default colors
#define DBG_COL_CLEAR                           "\x1B[2J"           ///< Clear screen, reposition cursor to top left

#define DBG_COL_TEXT_BLACK                      "\x1B[2;30m"
#define DBG_COL_TEXT_RED                        "\x1B[2;31m"
#define DBG_COL_TEXT_GREEN                      "\x1B[2;32m"
#define DBG_COL_TEXT_YELLOW                     "\x1B[2;33m"
#define DBG_COL_TEXT_BLUE                       "\x1B[2;34m"
#define DBG_COL_TEXT_MAGENTA                    "\x1B[2;35m"
#define DBG_COL_TEXT_CYAN                       "\x1B[2;36m"
#define DBG_COL_TEXT_WHITE                      "\x1B[2;37m"

#define DBG_COL_TEXT_BRIGHT_BLACK               "\x1B[1;30m"
#define DBG_COL_TEXT_BRIGHT_RED                 "\x1B[1;31m"
#define DBG_COL_TEXT_BRIGHT_GREEN               "\x1B[1;32m"
#define DBG_COL_TEXT_BRIGHT_YELLOW              "\x1B[1;33m"
#define DBG_COL_TEXT_BRIGHT_BLUE                "\x1B[1;34m"
#define DBG_COL_TEXT_BRIGHT_MAGENTA             "\x1B[1;35m"
#define DBG_COL_TEXT_BRIGHT_CYAN                "\x1B[1;36m"
#define DBG_COL_TEXT_BRIGHT_WHITE               "\x1B[1;37m"

#define DBG_COL_BG_BLACK                        "\x1B[24;40m"
#define DBG_COL_BG_RED                          "\x1B[24;41m"
#define DBG_COL_BG_GREEN                        "\x1B[24;42m"
#define DBG_COL_BG_YELLOW                       "\x1B[24;43m"
#define DBG_COL_BG_BLUE                         "\x1B[24;44m"
#define DBG_COL_BG_MAGENTA                      "\x1B[24;45m"
#define DBG_COL_BG_CYAN                         "\x1B[24;46m"
#define DBG_COL_BG_WHITE                        "\x1B[24;47m"

#define DBG_COL_BG_BRIGHT_BLACK                 "\x1B[4;40m"
#define DBG_COL_BG_BRIGHT_RED                   "\x1B[4;41m"
#define DBG_COL_BG_BRIGHT_GREEN                 "\x1B[4;42m"
#define DBG_COL_BG_BRIGHT_YELLOW                "\x1B[4;43m"
#define DBG_COL_BG_BRIGHT_BLUE                  "\x1B[4;44m"
#define DBG_COL_BG_BRIGHT_MAGENTA               "\x1B[4;45m"
#define DBG_COL_BG_BRIGHT_CYAN                  "\x1B[4;46m"
#define DBG_COL_BG_BRIGHT_WHITE                 "\x1B[4;47m"

#define DBG_COL(n)                              "\x1B[2;"#n"m"
#endif  /* end of DBG_LOG_COLOR_EN */

#ifdef DBG_PRINT_EN
#define DBG_PRINT(format, ...)                  _DBG_OUT(format, ##__VA_ARGS__)
#else
#define DBG_PRINT(format, ...)
#endif  /* end of DBG_PRINT_EN */

#ifdef DBG_LOG_COLOR_EN
#define DBG_LOG_COL(color, format, ...)         _DBG_OUT(color format DBG_COL_RESET, ##__VA_ARGS__ );
#else
#define DBG_LOG_COL(color, format, ...)
#endif  /* end of DBG_LOG_COLOR_EN */

#ifdef DBG_LOG_COLOR_EN
    #ifdef DBG_LOG_EN
    #define DBG_LOG(type, format, ...)                                          \
    do{                                                                         \
    if(type != 0)                                                               \
    {                                                                           \
        if      (type == DBG_E)                                                 \
        {                                                                       \
            DBG_LOG_COL(DBG_COL_TEXT_RED,       "E:" format, ##__VA_ARGS__);    \
        }                                                                       \
        else if (type == DBG_W)                                                 \
        {                                                                       \
            DBG_LOG_COL(DBG_COL_TEXT_YELLOW,    "W:" format, ##__VA_ARGS__);    \
        }                                                                       \
        else if (type == DBG_I)                                                 \
        {                                                                       \
            DBG_LOG_COL(DBG_COL_TEXT_CYAN,      "I:" format, ##__VA_ARGS__);    \
        }                                                                       \
        else if (type == DBG_D)                                                 \
        {                                                                       \
            DBG_LOG_COL(DBG_COL_RESET,          "D:" format, ##__VA_ARGS__);    \
        }                                                                       \
    }                                                                           \
    }while(0);
    #else
    #define DBG_LOG(type, format, ...)
    #endif
#else
    #ifdef DBG_LOG_EN
    #define DBG_LOG(type, format, ...)        do{ if(type!=0){_DBG_OUT(#type ":" format, ##__VA_ARGS__ );} }while (0)
    #else
    #define DBG_LOG(type, format, ...)
    #endif
#endif  /* End of #ifdef DBG_LOG_COLOR_EN */




#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* #ifndef __COMMON_H */
/* ------------------------------- END OF FILE ------------------------------- */
