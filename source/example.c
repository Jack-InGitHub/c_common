/**
  ******************************************************************************
  * @file    .c
  * @author  pq_liu@foxmail.com
  * @version 1.0
  * @date    2021.
  * @brief   None
  ******************************************************************************
  * @attention None
  *
  * @section 版本更新
  * <table>
  *     <tr><th>Version     <th>Data        <th>Author      <th>Notes
  *     <tr><td>V1.0        <td>2021.00.00  <td>PQ          <td>初始版本
  * </table>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include ".h"
/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/
eErrStatus_t    eErrStatus  = ERR_OK;                       
AirData_t       gAir        = {0};                          //全局变量前面加 g
pAirData_t      pAir        = &gAir;

/* Functions -----------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

static inline  SwapValueU32(uint32_t *a, uint32_t *b) {
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

eErrStatus_t GetTemperature(pAirData_t pAirData) {
    pAirData->iTempVal = (pAirData->ADVal >> 2) -105;
}


int main(int argc, char **argv) {
    gAir.fGetTemperature(pAir);
}



/************************************END OF FILE********************************/
