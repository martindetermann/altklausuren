/*
 * File: stm32f4xx_conf.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Blinker_Box_final.
 *
 * Model version                        : 1.10
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Tue Dec  5 14:24:08 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Tue Dec  5 14:24:09 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stm32f4xx_conf_h_
#define RTW_HEADER_stm32f4xx_conf_h_
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_pwr.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_dma.h"
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* If an external clock source is used, then the value of the following define
   should be set to the value of the external clock source, else, if no external
   clock is used, keep this define commented */
/*#define I2S_EXTERNAL_CLOCK_VAL   12288000 */
/* Value of the external clock in Hz */

/* Uncomment the line below to expanse the "assert_param" macro in the
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1 */

/* Exported macro ------------------------------------------------------------*/
#ifdef USE_FULL_ASSERT

/**
 * @brief  The assert_param macro is used for function's parameters check.
 * @param  expr: If expr is false, it calls assert_failed function
 *   which reports the name of the source file and the source
 *   line number of the call that failed.
 *   If expr is true, it returns no value.
 * @retval None
 */
#define assert_param(expr)             ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);

#else
#define assert_param(expr)             ((void)0)
#endif                                 /* USE_FULL_ASSERT */
#endif                                 /* RTW_HEADER_stm32f4xx_conf_h_ */

/* [EOF] */
