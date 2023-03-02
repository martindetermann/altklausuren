/*
 * File: main.c
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

#include "waijung_hwdrvlib.h"
#include "Blinker_Box_final.h"
#include "rtwtypes.h"                  /* MathWorks types */

/*
 * rt_Onestep is called from a timer ISR at the base sample time of 0.01 sec.
 * The ISR is void SysTick_Handler(void) and is defined in stm32f4xx_it.c
 */
void rt_OneStep(void);
volatile unsigned int systick_count = 1;
static volatile unsigned int systick_active = 0;

/* Main program */
int_T main(void)
{
  /* Initialize model */
  Blinker_Box_final_initialize();

  /* Continue indefinitely */
  if (SysTick_Config(SYSTICKRELOADVALUE)) {
    /* Capture error */
    while (1) ;
  }

  while (1) {
    if (systick_active != systick_count) {
      systick_active ++;
      Blinker_Box_final_step();

      /* Get model outputs here */

      /* Profiler update */
    }
  }
}

void rt_OneStep(void)
{
  /* Tick counter */
  systick_count++;
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void)
{
  rt_OneStep();
}

/* [EOF] */
