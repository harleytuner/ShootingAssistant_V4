#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\lvgl\\src\\draw\\nxp\\pxp\\lv_gpu_nxp_pxp_osa.h"
/**
 * @file lv_gpu_nxp_pxp_osa.h
 *
 */

/**
 * MIT License
 *
 * Copyright 2020, 2022 NXP
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next paragraph)
 * shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef LV_GPU_NXP_PXP_OSA_H
#define LV_GPU_NXP_PXP_OSA_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../../../lv_conf_internal.h"

#if LV_USE_GPU_NXP_PXP && LV_USE_GPU_NXP_PXP_AUTO_INIT
#include "lv_gpu_nxp_pxp.h"

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
 * PXP device interrupt handler. Used to check PXP task completion status.
 */
void PXP_IRQHandler(void);

/**
 * Helper function to get the PXP default configuration.
 */
lv_nxp_pxp_cfg_t * lv_gpu_nxp_pxp_get_cfg(void);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_GPU_NXP_PXP && LV_USE_GPU_NXP_PXP_AUTO_INIT*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_GPU_NXP_PXP_OSA_H*/
