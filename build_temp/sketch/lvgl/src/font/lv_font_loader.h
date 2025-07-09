#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\lvgl\\src\\font\\lv_font_loader.h"
/**
 * @file lv_font_loader.h
 *
 */

#ifndef LV_FONT_LOADER_H
#define LV_FONT_LOADER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_font_t * lv_font_load(const char * fontName);
void lv_font_free(lv_font_t * font);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_FONT_LOADER_H*/
