/**
  ******************************************************************************
  * @file    common.h
  * @author  PQ(pq_liu@foxmail.com)
  * @version 1.0
  * @date    2020.11.17
  * @brief   顶层头文件
  ******************************************************************************
  *
  * @section   History
  * <table>
  *     <tr><th>Version     <th>Data        <th>Author      <th>Notes
  *     <tr><td>V1.0        <td>2020.11.27  <td>A10211      <td>First implementation
  *     <tr><td>V1.1        <td>2021.10. 2  <td>PQ          <td>add color_log
  * </table>
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//#include "bool.h"

/* Board Support define ------------------------------------------------------*/
#define     SYSTEM_CORE_CLOCK       96000000ul

#define     SEC(X)                  ((X)*SYSTEM_CORE_CLOCK) //MAX 44.7s
#define     MSEC(X)                 (SYSTEM_CORE_CLOCK/1000*(X))
#define     USEC(X)                 (SYSTEM_CORE_CLOCK/1000000*(X))


/* Exported define -----------------------------------------------------------*/
/* DEBUG **************************************/
/* redirect dbg out */
#define _DBG_OUT(format, ...)                   SEGGER_RTT_printf(0,format, ##__VA_ARGS__)

// #define DBG_PRINT_EN                                                ///< 启用DBG_PRINT()输出
#define DBG_LOG_EN                                                  ///< 启用DBG_LOG()输出
#define DBG_LOG_COLOR_EN                                            ///< 启用DBG_LOG_COL()颜色输出

#define DBG_E                                   1                   ///< 1 启用 ERROR    等级输出
#define DBG_W                                   2                   ///< 2 启用 WARNING  等级输出
#define DBG_I                                   3                   ///< 3 启用 INFO     等级输出
#define DBG_L                                   4                   ///< 4 启用 LOG      等级输出


/* MCU ****************************************/
//CPU 的位宽
#define ALIGN_SIZE                              (4u)                ///< CPU位宽定义

/* C ******************************************/
#define UINT32_MAX                              (0xFFFFFFFF)
#define UINT16_MAX                              (0xFFFF)
#define UINT8_MAX                               (0xFF)


/* Exported macro ------------------------------------------------------------*/
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
            DBG_LOG_COL(DBG_COL_TEXT_BLUE,      "I:" format, ##__VA_ARGS__);    \
        }                                                                       \
        else if (type == DBG_L)                                                 \
        {                                                                       \
            DBG_LOG_COL(DBG_COL_RESET,          "L:" format, ##__VA_ARGS__);    \
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


/* Compiler Related Definitions */
#if defined(__CC_ARM) || defined(__CLANG_ARM)       /* ARM Compiler */
    #define C_SECTION(x)                            __attribute__((section(x)))
    #define C_UNUSED                                __attribute__((unused))
    #define C_USED                                  __attribute__((used))
    #define C_ALIGN(n)                              __attribute__((aligned(n)))
    #define C_WEAK                                  __attribute__((weak))
    #define C_INLINE                                static __inline

#elif defined (__IAR_SYSTEMS_ICC__)                 /* for IAR Compiler */
    #define C_SECTION(x)                            @ x
    #define C_UNUSED
    #define C_USED                                  __root
    #define C_ALIGN(n)                              PRAGMA(data_alignment=n)
    #define C_WEAK                                  __weak
    #define C_INLINE                                static inline

#elif defined (__GNUC__)                            /* GNU GCC Compiler */
    #define C_SECTION(x)                            __attribute__((section(x)))
    #define C_UNUSED                                __attribute__((unused))
    #define C_USED                                  __attribute__((used))
    #define C_ALIGN(n)                              __attribute__((aligned(n)))
    #define C_WEAK                                  __attribute__((weak))
    #define C_INLINE                                static __inline

#else
    #error not supported tool chain
#endif




#define MEM_ZERO_SET(x)                     do{ memset((void*)&(x), 0l, (sizeof(x))); }while(0)




#define MAX(a,b)                            ((a>b)?(a):(b))
#define MIN(a,b)                            ((a<b)?(a):(b))

/* Exported types ------------------------------------------------------------*/
/**
  * @enum   eErrStatus_t
  * @brief  错误类型枚举
  */
typedef enum
{
    ERR_NONE          =0,                                 ///< 没有错误
    ERR_ERROR         =1,                                 ///< 一般错误
    ERR_TIMEOUT       =2,                                 ///< 超时
    ERR_FULL          =3,                                 ///< 已满
    ERR_EMPTY         =3,                                 ///< 空
    ERR_INVAL         =5,                                 ///< 参数无效
    ERR_DATA_OVERLONG =6,                                 ///< 数据太长
    ERR_BUSY          =7,                                 ///< 忙碌中
    ERR_CHECK_FAIL    =8,                                 ///< 数据检查不通过
}eErrStatus_t;

/**
  * @enum   eFlag_t
  * @brief  状态的枚举、类Bool型
  */
typedef enum
{
    eRESET=0,                                             ///< 复位/False
    eSET=!eRESET                                          ///< 置位/True
} eFlag_t, eBool_t;
/* Exported typedef ----------------------------------------------------------*/
typedef                  _Bool      Bool;
typedef unsigned          char      Byte;
typedef unsigned short     int      Word;
typedef unsigned           int     DWord;

/* Exported functions ------------------------------------------------------- */


/* Includes ------------------------------------------------------------------*/


#endif /* #ifndef __COMMON_H */
/************************************END OF FILE********************************/
