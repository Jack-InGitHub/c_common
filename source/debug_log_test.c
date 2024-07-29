/*****************************************************************************
 *
 * @file:    debug_log_test.c
 * @brief:   debug_log module test function
 * @author:  oikiou (oikiou@outlook.com)
 * @date:    2024/07/21
 * @version: v0.0.1
 * @history: 
 * <author>      <time>      <version>      <desc> 
 * | oikiou | 2024/07/21 | v0.0.1 | First version |
 *
 ****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "debug_log.h"

/* Config --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/* Functions Prototypes ------------------------------------------------------*/

// log test functions
void DebugLogFunTest(void) {
    _LOG_OUT_RAW(LOG_NEWLINE_LINE_ENDINGS LOG_NEWLINE_LINE_ENDINGS LOG_NEWLINE_LINE_ENDINGS);
    
    LOG_RAW("LOG_RAW() function test");
    LOG_RAW("LOG_RAW() function test arguments %d %s", __LINE__, __DATE__);
    
    LOG_PRINTF("LOG_PRINTF() function test");
    LOG_PRINTF("LOG_PRINTF() function test arguments %d %s", __LINE__, __DATE__);

    LOG_COL( LOG_COL_TEXT_GREEN LOG_COL_BG_RED, "LOG_COL() function test");
    LOG_COL( LOG_COL_TEXT_BLUE LOG_COL_BG_CYAN, "LOG_COL() function test arguments %d %s", __LINE__, __DATE__);

    LOG_TIME("LOG_TIME() function test");
    LOG_TIME("LOG_TIME() function test arguments %d %s", __LINE__, __DATE__);

    LOG(LOGF, "LOG(LOGF) function test");
    LOG(LOGE, "LOG(LOGE) function test");
    LOG(LOGW, "LOG(LOGW) function test");
    LOG(LOGI, "LOG(LOGI) function test");
    LOG(LOGD, "LOG(LOGD) function test");
    LOG(LOGF, "LOG(LOGF) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGE, "LOG(LOGE) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGW, "LOG(LOGW) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGI, "LOG(LOGI) function test arguments %d %s", __LINE__, __DATE__);
    LOG(LOGD, "LOG(LOGD) function test arguments %d %s", __LINE__, __DATE__);


    LOG_F("LOG_F() function test");
    LOG_E("LOG_E() function test");
    LOG_W("LOG_W() function test");
    LOG_I("LOG_I() function test");
    LOG_D("LOG_D() function test");
    LOG_F("LOG_F() function test arguments %d %s", __LINE__, __DATE__);
    LOG_E("LOG_E() function test arguments %d %s", __LINE__, __DATE__);
    LOG_W("LOG_W() function test arguments %d %s", __LINE__, __DATE__);
    LOG_I("LOG_I() function test arguments %d %s", __LINE__, __DATE__);
    LOG_D("LOG_D() function test arguments %d %s", __LINE__, __DATE__);
}

/* --------------------------------END OF FILE------------------------------- */
