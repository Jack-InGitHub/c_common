/**
  ******************************************************************************
  * @file    .h    
  * @author  pq_liu@foxmail.com
  * @version 1.0 
  * @date    2021.    
  * @brief   None   
  ******************************************************************************
  * @attention None
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XXX_H                                             // XXX文件名
#define __XXX_H

#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
//#include "xxx.h"

/* Exported define -----------------------------------------------------------*/
#define TEMP_MAX                     (8u)                   //全大写加下划线

/* Exported macro ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef   signed          char int8_t;                      //Typedef 后缀加 _t
typedef   signed short     int int16_t;                     //Typedef 后缀加 _t
typedef   signed           int int32_t;
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;


typedef enum _eErrStatus
{
        ERR_NONE            =0,                             ///< 没有错误
#define ERR_NONE             0
        ERR_ERROR           =1,                             ///< 一般错误
#define ERR_ERROR            1
        ERR_TIMEOUT         =2,                             ///< 超时
#define ERR_TIMEOUT          2
///< etc.
}eErrStatus_t;


union _uUnionXx {
    uint8_t                 Arr[4];
    uint32_t                Data;
};
typedef union _uUnionXx uUnionXx_t;


/**
 * @brief   这里不要直接使用 typedef 照大多数书籍说明是为了“显式地声明结构体” 
 *          看很多优秀代码是分开定义的，这里就按分开定义去做吧。
 *          
 *          我倒是觉得直接 typedef 简单明了，
 *          struct _AirData 也不建议使用，把 AirData_t 当作一种数据类型就好了，类似于int等等的数据类型。
 */
struct _AirData {
    eErrStatus_t    eErr;                                       //enum 变量 前面加 e
    uint16_t        ADVal;
    int16_t         iTempVal;                                   //有符号变量 前面加 i
    eErrStatus_t    (*fGetTemperature)(pAirData_t pAirData);    //可选 函数指针 前面加 f
};
typedef struct _AirData AirData_t;
typedef AirData_t *pAirData_t;                                  //指针加 前面加 p

/* Exported Variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
eErrStatus_t GetTemperature(pAirData_t pAirData);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* end of ifndef */

/* --------------------------------END OF FILE------------------------------- */
