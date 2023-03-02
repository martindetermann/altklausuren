/*
 * File: stm32f4xx_it.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model SchlossBox.
 *
 * Model version                        : 1.15
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Sun Dec  3 17:35:44 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Sun Dec  3 17:35:45 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stm32f4xx_it_h_
#define RTW_HEADER_stm32f4xx_it_h_

/**
 ******************************************************************************
 * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.h
 * @author  MCD Application Team
 * @version V1.0.1
 * @date    13-April-2012
 * @brief   This file contains the headers of the interrupt handlers.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H
#ifdef __cplusplus

extern "C" {

#endif

  /* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

  /* Exported types ------------------------------------------------------------*/
  /* Exported constants --------------------------------------------------------*/
  /* Exported macro ------------------------------------------------------------*/
  /* Exported functions ------------------------------------------------------- */
  void NMI_Handler(void);
  void HardFault_Handler(void);
  void MemManage_Handler(void);
  void BusFault_Handler(void);
  void UsageFault_Handler(void);
  void SVC_Handler(void);
  void DebugMon_Handler(void);
  void PendSV_Handler(void);
  void SysTick_Handler(void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __STM32F4xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#endif                                 /* RTW_HEADER_stm32f4xx_it_h_ */

/* [EOF] */
