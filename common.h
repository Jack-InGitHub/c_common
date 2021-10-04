/**
  ******************************************************************************
  * @file    common.h
  * @author  PQ(pq_liu@foxmail.com)
  * @version 1.0
  * @date    2020.11.17
  * @brief   ����ͷ�ļ�
  ******************************************************************************
  *
  * @section   History
  * <table>
  *     <tr><th>Version     <th>Data        <th>Author      <th>Notes
  *     <tr><td>V1.0        <td>2020.11.27  <td>A10211      <td>First implementation
  *     <tr><td>V1.0        <td>2021.09.30  <td>PQ          <td>
  * </table>
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

//#include "bool.h"

/* Board Support define ------------------------------------------------------*/

/* Exported define -----------------------------------------------------------*/
// #define DEBUG_CODE                                      ///< ����DEBUG_LOG_CORE()���
// #define DEBUG_LOG_EN                                    ///< ����DEBUG_LOG()���

#define DEBUG_ERROR                         1           ///< ����ERROR�ȼ�Log���
#define DEBUG_WARNING                       1           ///< ����WARNING�ȼ�Log���
#define DEBUG_INFO                          1           ///< ����INFO�ȼ�Log���

//CPU ��λ��
#define ALIGN_SIZE                          (4u)        ///< CPUλ����

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
  * @brief  ��������ö��
  */
typedef enum
{
    ERR_NONE          =0,                                 ///< û�д���
    ERR_ERROR         =1,                                 ///< һ�����
    ERR_TIMEOUT       =2,                                 ///< ��ʱ
    ERR_FULL          =3,                                 ///< ����
    ERR_EMPTY         =3,                                 ///< ��
    ERR_DATA_INVAL    =5,                                 ///< ������Ч
    ERR_DATA_OVERLONG =6,                                 ///< ����̫��
    ERR_BUSY          =7,                                 ///< æµ��
    ERR_CHECK_FAIL    =8,                                 ///< ���ݼ�鲻ͨ��
}eErrStatus_t;

/**
  * @enum   eFlag_t
  * @brief  ״̬��ö�١�����Bool��
  */
typedef enum
{
    Reset=0,                                            ///< ��λ/False
    Set=!Reset                                          ///< ��λ/True
} eFlag_t, eBool_t;
/* Exported typedef ----------------------------------------------------------*/
typedef                  _Bool  Bool;
typedef unsigned          char  Byte;
typedef unsigned short     int  Word;
typedef unsigned           int  DWord;

/* Exported functions ------------------------------------------------------- */


/* Includes ------------------------------------------------------------------*/


#endif

/************************************END OF FILE********************************/
