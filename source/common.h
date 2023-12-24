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

#include "debug_log.h"

/* Board Support define ------------------------------------------------------*/
#define     SYSTEM_CORE_CLOCK       96000000ul
#define     SYSTEM_CORE_CLOCK_KHZ   (SYSTEM_CORE_CLOCK/1000)
#define     SYSTEM_CORE_CLOCK_MHZ   (SYSTEM_CORE_CLOCK_KHZ/1000)

#define     SEC(X)                  ((X)*SYSTEM_CORE_CLOCK)
#define     MSEC(X)                 (SYSTEM_CORE_CLOCK/1000*(X))
#define     USEC(X)                 (SYSTEM_CORE_CLOCK/1000000*(X))


/* Exported define -----------------------------------------------------------*/
/* MCU ****************************************/
//CPU 的位宽
#define ALIGN_SIZE                  (4u)                ///< CPU位宽定义

/* C ******************************************/
#define BITS_NO                     (0x00000000)
#define BITS_ALL                    (0xFFFFFFFF)
#define BIT_0                       (0x00000001)
#define BIT_1                       (0x00000002)
#define BIT_2                       (0x00000004)
#define BIT_3                       (0x00000008)
#define BIT_4                       (0x00000010)
#define BIT_5                       (0x00000020)
#define BIT_6                       (0x00000040)
#define BIT_7                       (0x00000080)
#define BIT_8                       (0x00000100)
#define BIT_9                       (0x00000200)
#define BIT_10                      (0x00000400)
#define BIT_11                      (0x00000800)
#define BIT_12                      (0x00001000)
#define BIT_13                      (0x00002000)
#define BIT_14                      (0x00004000)
#define BIT_15                      (0x00008000)
#define BIT_16                      (0x00010000)
#define BIT_17                      (0x00020000)
#define BIT_18                      (0x00040000)
#define BIT_19                      (0x00080000)
#define BIT_20                      (0x00100000)
#define BIT_21                      (0x00200000)
#define BIT_22                      (0x00400000)
#define BIT_23                      (0x00800000)
#define BIT_24                      (0x01000000)
#define BIT_25                      (0x02000000)
#define BIT_26                      (0x04000000)
#define BIT_27                      (0x08000000)
#define BIT_28                      (0x10000000)
#define BIT_29                      (0x20000000)
#define BIT_30                      (0x40000000)
#define BIT_31                      (0x80000000)

#define BYTE_0                      (BIT_7  | BIT_6  | BIT_5  | BIT_4  | BIT_3  | BIT_2  | BIT_1  | BIT_0  )
#define BYTE_1                      (BIT_15 | BIT_14 | BIT_13 | BIT_12 | BIT_11 | BIT_10 | BIT_9  | BIT_8  )
#define BYTE_2                      (BIT_23 | BIT_22 | BIT_21 | BIT_20 | BIT_19 | BIT_18 | BIT_17 | BIT_16 )
#define BYTE_3                      (BIT_31 | BIT_30 | BIT_29 | BIT_28 | BIT_27 | BIT_26 | BIT_25 | BIT_24 )

#define UINT32_MAX                  (0xFFFFFFFF)
#define UINT16_MAX                  (0xFFFF)
#define UINT8_MAX                   (0xFF)

/* Compiler Related Definitions ***************/
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

/* volatile ***********************************/
#if 0
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif

/* Exported macro ------------------------------------------------------------*/


/* USEFUL *************************************/
#define MEM_ZERO_SET(x)                     do{ memset((void*)&(x), 0l, (sizeof(x))); }while(0)
#define ARR_GET_LEN(x)                      (sizeof(x)/sizeof(x[0]))                        ///< 获取元素个数
#define ARR_GET_MAX(x)                      (sizeof(x)/sizeof(x[0])-1)                      ///< 获取数组元素最大的 index 

// 编译日期相关 compile
#define COMP_YEAR                           ((__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0'))
#define COMP_MONTH                          (__DATE__[2] == 'n' ? 1                             \
                                            : __DATE__[2] == 'b' ? 2                            \
                                            : __DATE__[2] == 'r' ? (__DATE__[0] == 'M' ? 3 : 4) \
                                            : __DATE__[2] == 'y' ? 5                            \
                                            : __DATE__[2] == 'n' ? 6                            \
                                            : __DATE__[2] == 'l' ? 7                            \
                                            : __DATE__[2] == 'g' ? 8                            \
                                            : __DATE__[2] == 'p' ? 9                            \
                                            : __DATE__[2] == 't' ? 10                           \
                                            : __DATE__[2] == 'v' ? 11 : 12)
#define COMP_DAY                            ((__DATE__[4] == ' ' ? 0 : __DATE__[4] - '0') * 10 + (__DATE__[5] - '0'))
#define COMP_HOUR                           ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))
#define COMP_MINUTE                         ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))
#define COMP_SECOND                         ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))

// 获取最大最小值
#define MAX(a,b)                            ((a>b)?(a):(b))
#define MIN(a,b)                            ((a<b)?(a):(b))

/* Exported types ------------------------------------------------------------*/
/**
  * @enum   eErrStatus_t
  * @brief  错误类型枚举
  */
typedef enum
{
        ERR_NONE            =0,                         ///< 没有错误
#define ERR_NONE             0
        ERR_ERROR           =1,                         ///< 一般错误
#define ERR_ERROR            1
        ERR_TIMEOUT         =2,                         ///< 超时
#define ERR_TIMEOUT          2
        ERR_FULL            =3,                         ///< 已满
#define ERR_FULL             3
        ERR_EMPTY           =4,                         ///< 空
#define ERR_EMPTY            4
        ERR_INVAL           =5,                         ///< 参数无效
#define ERR_INVAL            5
        ERR_DATA_OVERLONG   =6,                         ///< 数据太长
#define ERR_DATA_OVERLONG    6
        ERR_BUSY            =7,                         ///< 忙碌中
#define ERR_BUSY             7
        ERR_CHECK_FAIL      =8,                         ///< 数据检查不通过
#define ERR_CHECK_FAIL       8
}eErrStatus_t;

/**
  * @enum   eFlag_t
  * @brief  状态的枚举、类Bool型
  */
typedef enum
{
    RESET=0,                                             ///< 复位/False
    SET=!RESET                                           ///< 置位/True
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
/* ------------------------------- END OF FILE ------------------------------- */
