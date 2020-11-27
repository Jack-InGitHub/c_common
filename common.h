/**
  ******************************************************************************
  * @file    common.h    
  * @author  GREE/A10211
  * @version 1.0 
  * @date    2020.11.17
  * @brief   顶层头文件
  ******************************************************************************
  *
  * 版本更新
  * <table>
  *     <tr><th>Version     <th>Data        <th>Author      <th>Notes
  *     <tr><td>V1.0        <td>2020.11.27  <td>A10211      <td>First implementation
  * </table>
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "stm32f10x.h"

#include "rtconfig.h"                                   //RT配置文件
#include "rtthread.h"

//#include "bool.h"

/* Exported define -----------------------------------------------------------*/
#define DEBUG_CODE                                      ///< 启用DEBUG_LOG_CORE()输出
#define DEBUG_LOG_EN                                    ///< 启用DEBUG_LOG()输出

#define DEBUG_ERROR                         1           ///< 启用ERROR等级Log输出
#define DEBUG_WARNING                       1           ///< 启用WARNING等级Log输出
#define DEBUG_INFO                          1           ///< 启用INFO等级Log输出

//CPU 的位宽
#define ALIGN_SIZE                          (4u)        ///< CPU位宽定义

#define UINT32_MAX                          (0xFFFFFFFF)
#define UINT16_MAX                          (0xFFFF)
#define UINT8_MAX                           (0xFF)

/* Exported macro ------------------------------------------------------------*/
#ifdef DEBUG_CODE
#define DEBUG_LOG_CORE(format, ...)         rt_kprintf(format, ##__VA_ARGS__)
#else
#define DEBUG_LOG_CORE(format, ...)
#endif

#ifdef DEBUG_LOG_EN
#define DEBUG_LOG(type, format, ...)        do{ if(type!=0){rt_kprintf(#type ": " format, ##__VA_ARGS__ );} }while (0)
#else
#define DEBUG_LOG(type, format, ...)
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
    ERR_OK          =0,                                 ///< 没有错误
    ERR_ERROR       =1,                                 ///< 一般错误
    ERR_TIMEOUT     =2,                                 ///< 超时
    ERR_FULL        =3,                                 ///< 已满
    ERR_EMPTY       =3,                                 ///< 空
    ERR_INVAL_DATA  =5,                                 ///< 数据无效
    ERR_CHECK_FAIL  =6,                                 ///< 数据检查不通过
}eErrStatus_t;
/**
  * @enum   eFlag_t
  * @brief  状态的枚举、和类Bool型
  */
typedef enum 
{
    Reset=0,                                            ///< 复位/False
    Set=!Reset                                          ///< 置位/True
} eFlag_t, eBool_t;
/* Exported typedef ----------------------------------------------------------*/
typedef unsigned          char  byte;
typedef unsigned short     int  halfword;
typedef unsigned           int  word;

/* Exported functions ------------------------------------------------------- */


/* Includes ------------------------------------------------------------------*/


#endif

/************************************END OF FILE********************************/
