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
#define C_SYSTEM_CORE_CLOCK                 96000000ul
#define C_SYSTEM_CORE_CLOCK_KHZ             (C_SYSTEM_CORE_CLOCK/1000)
#define C_SYSTEM_CORE_CLOCK_MHZ             (C_SYSTEM_CORE_CLOCK_KHZ/1000)

#define C_SEC(X)                            ((X)*C_SYSTEM_CORE_CLOCK)
#define C_MSEC(X)                           (C_SYSTEM_CORE_CLOCK/1000*(X))
#define C_USEC(X)                           (C_SYSTEM_CORE_CLOCK/1000000*(X))


/* Exported define -----------------------------------------------------------*/
/* CPU *************************************** */
#define C_LITTLE_ENDIAN                     76543210                ///< 小端
#define C_BIG_ENDIAN                        01234567                ///< 大端

/* CPU 的位宽 */
#define C_CPU_WIDTH                         (4u)                    ///< CPU位宽定义
#define C_BYTE_ORDER                        LITTLE_ENDIAN

/* C ***************************************** */
#define BITS_NO                             (0x00000000)
#define BITS_ALL                            (0xFFFFFFFF)
#define BIT_0                               (0x00000001)
#define BIT_1                               (0x00000002)
#define BIT_2                               (0x00000004)
#define BIT_3                               (0x00000008)
#define BIT_4                               (0x00000010)
#define BIT_5                               (0x00000020)
#define BIT_6                               (0x00000040)
#define BIT_7                               (0x00000080)
#define BIT_8                               (0x00000100)
#define BIT_9                               (0x00000200)
#define BIT_10                              (0x00000400)
#define BIT_11                              (0x00000800)
#define BIT_12                              (0x00001000)
#define BIT_13                              (0x00002000)
#define BIT_14                              (0x00004000)
#define BIT_15                              (0x00008000)
#define BIT_16                              (0x00010000)
#define BIT_17                              (0x00020000)
#define BIT_18                              (0x00040000)
#define BIT_19                              (0x00080000)
#define BIT_20                              (0x00100000)
#define BIT_21                              (0x00200000)
#define BIT_22                              (0x00400000)
#define BIT_23                              (0x00800000)
#define BIT_24                              (0x01000000)
#define BIT_25                              (0x02000000)
#define BIT_26                              (0x04000000)
#define BIT_27                              (0x08000000)
#define BIT_28                              (0x10000000)
#define BIT_29                              (0x20000000)
#define BIT_30                              (0x40000000)
#define BIT_31                              (0x80000000)

#define BYTE_0                              (BIT_7  | BIT_6  | BIT_5  | BIT_4  | BIT_3  | BIT_2  | BIT_1  | BIT_0  )
#define BYTE_1                              (BIT_15 | BIT_14 | BIT_13 | BIT_12 | BIT_11 | BIT_10 | BIT_9  | BIT_8  )
#define BYTE_2                              (BIT_23 | BIT_22 | BIT_21 | BIT_20 | BIT_19 | BIT_18 | BIT_17 | BIT_16 )
#define BYTE_3                              (BIT_31 | BIT_30 | BIT_29 | BIT_28 | BIT_27 | BIT_26 | BIT_25 | BIT_24 )


/* types */
#if 0
typedef signed   char                       int8_t;      /**<  8bit integer type */
typedef unsigned char                       uint8_t;     /**<  8bit unsigned integer type */
typedef signed   short                      int16_t;     /**< 16bit integer type */
typedef unsigned short                      uint16_t;    /**< 16bit unsigned integer type */
typedef signed   int                        int32_t;     /**< 32bit integer type */
typedef unsigned int                        uint32_t;    /**< 32bit unsigned integer type */
typedef signed   long long                  int64_t;     /**< 64bit integer type */
typedef unsigned long long                  uint64_t;    /**< 64bit unsigned integer type */

typedef          _Bool                      Bool;
typedef unsigned char                       Byte;
typedef unsigned short                      Word;
typedef unsigned int                        DWord;C_
#endif

#ifndef UINT8_MAX
    #define UINT8_MAX                       (0xFF)
#endif
#ifndef UINT16_MAX
    #define UINT16_MAX                      (0xFFFF)
#endif
#ifndef UINT32_MAX
    #define UINT32_MAX                      (0xFFFFFFFF)
#endif
#ifndef UINT64_MAX
    #define UINT64_MAX                      (0xFFFFFFFFFFFFFFFF)
#endif

/* Compiler Related Definitions ************** */
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

/* volatile ********************************** */
#if 0
#ifdef __cplusplus
  #define   __I     volatile                /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const          /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile                /*!< Defines 'write only' permissions                */
#define     __IO    volatile                /*!< Defines 'read / write' permissions              */
#endif

/* Exported macro ------------------------------------------------------------*/

/* Version */
#define C_VERSION_MAJOR                     (000)
#define C_VERSION_MINOR                     (000)
#define C_VERSION_PATCH                     (008)
#define C_GET_VERSION()                     (((C_VERSION_MAJOR<<16)|(C_VERSION_MINOR<<8)|(C_VERSION_PATCH))&0x00ffffff)

/* USEFUL ************************************ */
#define C_MEM_SET_ZERO(x)                   do{ memset((void*)&(x), 0l, (sizeof(x))); }while(0)
#define C_ARR_GET_LEN(x)                    (sizeof(x)/sizeof(x[0]))                        ///< 获取元素个数
#define C_ARR_GET_MAX(x)                    (sizeof(x)/sizeof(x[0])-1)                      ///< 获取数组元素最大的 index 

/* 编译日期相关 compile */
#define C_COMP_YEAR                         ((__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0'))
#define C_COMP_MONTH                        (__DATE__[2] == 'n' ? 1                                 \
                                                : __DATE__[2] == 'b' ? 2                            \
                                                : __DATE__[2] == 'r' ? (__DATE__[0] == 'M' ? 3 : 4) \
                                                : __DATE__[2] == 'y' ? 5                            \
                                                : __DATE__[2] == 'n' ? 6                            \
                                                : __DATE__[2] == 'l' ? 7                            \
                                                : __DATE__[2] == 'g' ? 8                            \
                                                : __DATE__[2] == 'p' ? 9                            \
                                                : __DATE__[2] == 't' ? 10                           \
                                                : __DATE__[2] == 'v' ? 11 : 12)
#define C_COMP_DAY                          ((__DATE__[4] == ' ' ? 0 : __DATE__[4] - '0') * 10 + (__DATE__[5] - '0'))
#define C_COMP_HOUR                         ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))
#define C_COMP_MINUTE                       ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))
#define C_COMP_SECOND                       ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))


/**
 * @def IS_ALIGN(size, align)
 * Return true(1) or false(0).
 *     IS_ALIGN(128, 4) is judging whether 128 aligns with 4.
 *     The result is 1, which means 128 aligns with 4.
 */
#define C_IS_ALIGN(size, align)             (!((uint32_t)(size) & (align - 1)))
#define C_NOT_ALIGN(size, align)            (!!((uint32_t)(size) & (align - 1)))
/**
 * @def ALIGN(size, align)
 * Return the most contiguous size aligned at specified width. RT_ALIGN(13, 4)
 * would return 16.
 */
#define C_ALIGN(size, align)                (((uint32_t)(size) + (align) - 1) & ~((align) - 1))
/**
 * @def ALIGN_DOWN(size, align)
 * Return the down number of aligned at specified width. RT_ALIGN_DOWN(13, 4)
 * would return 12.
 */
#define C_ALIGN_DOWN(size, align)           ((uint32_t)(size) & ~((align) - 1))


/* tools */
// use e.g.
// stop compiler warning about unused variables
#define C_UNUSED(x)                         ((void)x)

// use e.g.
// STATIC_ASSERT(test, sizeof(void *) == sizeof(long))
#define C_STATIC_ASSERT(name, expn)         typedef char _static_assert_##name[(expn)?1:-1]


/* 获取最大最小值 */
#define C_MAX(a,b)                          ((a>b)?(a):(b))
#define C_MIN(a,b)                          ((a<b)?(a):(b))

/* Swap */
#ifdef __GNUC__
    #define C_EXPECT(x, y)                      __builtin_expect((x), (y))
    #ifndef likely
        #define likely(x)                       __builtin_expect(!!(x),1)
    #endif
    #ifndef unlikely
        #define unlikely(x)                     __builtin_expect(!!(x),0)
    #endif

    #define C_SWAP32(x)                         __builtin_bswap32(x)
    #define C_SWAP64(x)                         __builtin_bswap64(x)
#else
    #define C_EXPECT(x, y)                      (x)
    #ifndef likely
        #define likely(x)                       (x)
    #endif
    #ifndef unlikely
        #define unlikely(x)                     (x)
    #endif
#endif

/* Exported types ------------------------------------------------------------*/
/**
  * @enum   eErrStatus_t
  * @brief  错误类型枚举
  */
typedef enum {
    ERR_NONE            =0,                         ///< 没有错误
    ERR_ERROR           ,                           ///< 一般错误
    ERR_TIMEOUT         ,                           ///< 超时
    ERR_FULL            ,                           ///< 已满
    ERR_EMPTY           ,                           ///< 空
    ERR_NOMEM           ,                           ///< no memory
    ERR_BUSY            ,                           ///< 忙碌中
    ERR_IO              ,                           ///< IO
    ERR_NOSPC           ,                           ///< No space left
    ERR_PERM            ,                           ///< Operation not permitted
    
    ERR_INVAL           ,                           ///< 参数无效
    ERR_DATA_OVERLONG   ,                           ///< 数据太长
    
    ERR_CHECK_FAIL      ,                           ///< 检查不通过
    ERR_BAD_ADDR        ,                           ///< bad address
} eErrStatus_t;

/**
  * @enum   eFlag_t
  * @brief  状态的枚举、类Bool型
  */
typedef enum {
    RESET=0,                                        ///< 复位/False
    SET=!RESET                                      ///< 置位/True
} eFlag_t, eBool_t;
/* Exported typedef ----------------------------------------------------------*/

/**
 * Double List structure
 */
typedef struct c_list_node {
    struct c_list_node *next;                      /**< point to next node. */
    struct c_list_node *prev;                      /**< point to prev node. */
} c_list_t;

/**
 * Single List structure
 */
typedef struct c_slist_node {
    struct c_slist_node *next;                     /**< point to next node. */
} c_slist_t;


/* Exported functions ------------------------------------------------------- */


/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* #ifndef __COMMON_H */
/* ------------------------------- END OF FILE ------------------------------- */
