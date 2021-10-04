/**
  ******************************************************************************
  * @file    common.h
  * @author  PQ(pq_liu@foxmail.com)
  * @version V0.1.2
  * @date    2021.10.04
  * @brief   top header file
  ******************************************************************************
  *
  * @section   History
  * <table>
  *     <tr><th>Version     <th>Data        <th>Author      <th>Notes
  *     <tr><td>V0.1.0      <td>2020.11.27  <td>A10211      <td>First implementation
  *     <tr><td>V0.1.1      <td>2021.10.02  <td>PQ          <td>add color_log
  *     <tr><td>V0.1.2      <td>2021.10.04  <td>PQ          <td>add DEBUG_MAIN_OUT_EN add cplusplus support
  * </table>
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
 extern "C" {
#endif

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
#define DEBUG_MAIN_OUT_EN                                           ///< DEBUG LOG MAIN EN  �ܿ���

#ifdef DEBUG_MAIN_OUT_EN
/* redirect dbg out */
#define _DBG_OUT(format, ...)                   SEGGER_RTT_printf(0,format, ##__VA_ARGS__)

#define DBG_PRINT_EN                                                ///< ����DBG_PRINT()���
#define DBG_LOG_EN                                                  ///< ����DBG_LOG()���
#define DBG_LOG_COLOR_EN                                            ///< ����DBG_LOG_COL()��ɫ���
#endif /* end of #ifdef DEBUG_MAIN_OUT_EN */

#define DBG_E                                   1                   ///< 1 ���� 0�ر� ERROR    �ȼ����
#define DBG_W                                   2                   ///< 2 ���� 0�ر� WARNING  �ȼ����
#define DBG_I                                   3                   ///< 3 ���� 0�ر� INFO     �ȼ����
#define DBG_L                                   4                   ///< 4 ���� 0�ر� LOG      �ȼ����


/* MCU ****************************************/
//CPU ��λ��
#define ALIGN_SIZE                              (4u)                ///< CPUλ����

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
  * @brief  ��������ö��
  */
typedef enum
{
        ERR_NONE            =0,                         ///< û�д���
#define ERR_NONE             0
        ERR_ERROR           =1,                         ///< һ�����
#define ERR_ERROR            1
        ERR_TIMEOUT         =2,                         ///< ��ʱ
#define ERR_TIMEOUT          2
        ERR_FULL            =3,                         ///< ����
#define ERR_FULL             3
        ERR_EMPTY           =4,                         ///< ��
#define ERR_EMPTY            4
        ERR_INVAL           =5,                         ///< ������Ч
#define ERR_INVAL            5
        ERR_DATA_OVERLONG   =6,                         ///< ����̫��
#define ERR_DATA_OVERLONG    6
        ERR_BUSY            =7,                         ///< æµ��
#define ERR_BUSY             7
        ERR_CHECK_FAIL      =8,                         ///< ���ݼ�鲻ͨ��
#define ERR_CHECK_FAIL       8
}eErrStatus_t;

/**
  * @enum   eFlag_t
  * @brief  ״̬��ö�١���Bool��
  */
typedef enum
{
    eRESET=0,                                             ///< ��λ/False
    eSET=!eRESET                                          ///< ��λ/True
} eFlag_t, eBool_t;
/* Exported typedef ----------------------------------------------------------*/
typedef                  _Bool      Bool;
typedef unsigned          char      Byte;
typedef unsigned short     int      Word;
typedef unsigned           int     DWord;

/* Exported functions ------------------------------------------------------- */


/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* #ifndef __COMMON_H */
/************************************END OF FILE********************************/
