#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\lvgl\\src\\extra\\libs\\png\\lv_png.h"
/**
 * @file lv_png.h
 *
 */

#ifndef LV_PNG_H
#define LV_PNG_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../lv_conf_internal.h"
#if LV_USE_PNG

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Register the PNG decoder functions in LVGL
 */
void lv_png_init(void);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_PNG*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_PNG_H*/
