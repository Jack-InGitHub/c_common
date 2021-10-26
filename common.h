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

// #include "bool.h"

/* Board Support define ------------------------------------------------------*/
#define     SYSTEM_CORE_CLOCK       96000000ul

#define     SEC(X)                  ((X)*SYSTEM_CORE_CLOCK)             //MAX xS
#define     MSEC(X)                 (SYSTEM_CORE_CLOCK/1000*(X))
#define     USEC(X)                 (SYSTEM_CORE_CLOCK/1000000*(X))


/* Exported define -----------------------------------------------------------*/
/* MCU ****************************************/
//CPU 的位宽
#define ALIGN_SIZE                                  (4u)                ///< CPU位宽定义

/* C ******************************************/
#define UINT32_MAX                                  (0xFFFFFFFF)
#define UINT16_MAX                                  (0xFFFF)
#define UINT8_MAX                                   (0xFF)

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

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* #ifndef __COMMON_H */
/* ------------------------------- END OF FILE ------------------------------- */
