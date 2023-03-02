/*
 * File: Schloss_Box_final_Debounce.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Schloss_Box_final.
 *
 * Model version                        : 1.19
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Tue Dec  5 14:31:04 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Tue Dec  5 14:31:04 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Schloss_Box_final_Debounce_h_
#define RTW_HEADER_Schloss_Box_final_Debounce_h_
#ifndef Schloss_Box_final_COMMON_INCLUDES_
# define Schloss_Box_final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* Schloss_Box_final_COMMON_INCLUDES_ */

#include "Schloss_Box_final_types.h"

/* Block states (auto storage) for system '<S7>/Enabled Subsystem' */
typedef struct {
  uint32_T Output_DSTATE;              /* '<S21>/Output' */
} DW_EnabledSubsystem_Schloss_B_T;

/* Block signals for system '<S1>/Debounce' */
typedef struct {
  uint32_T Output;                     /* '<S31>/Output' */
  uint32_T Output_j;                   /* '<S28>/Output' */
  uint32_T Output_ji;                  /* '<S21>/Output' */
  uint8_T Compare;                     /* '<S24>/Compare' */
} B_Debounce_Schloss_Box_final_T;

/* Block states (auto storage) for system '<S1>/Debounce' */
typedef struct {
  uint32_T Output_DSTATE;              /* '<S25>/Output' */
  uint32_T Memory_PreviousInput;       /* '<S7>/Memory' */
  uint32_T Memory1_PreviousInput;      /* '<S7>/Memory1' */
  boolean_T Memory3_PreviousInput;     /* '<S7>/Memory3' */
  boolean_T Memory2_PreviousInput;     /* '<S7>/Memory2' */
  DW_EnabledSubsystem_Schloss_B_T EnabledSubsystem5;/* '<S7>/Enabled Subsystem5' */
  DW_EnabledSubsystem_Schloss_B_T EnabledSubsystem4;/* '<S7>/Enabled Subsystem4' */
  DW_EnabledSubsystem_Schloss_B_T EnabledSubsystem;/* '<S7>/Enabled Subsystem' */
} DW_Debounce_Schloss_Box_final_T;

extern void Schloss_Box_fi_EnabledSubsystem(boolean_T rtu_Enable, uint32_T
  *rty_Out1, DW_EnabledSubsystem_Schloss_B_T *localDW);
extern boolean_T Schloss_Box_final_Debounce(boolean_T rtu_In1,
  B_Debounce_Schloss_Box_final_T *localB, DW_Debounce_Schloss_Box_final_T
  *localDW, int32_T rtp_mode);

#endif                                 /* RTW_HEADER_Schloss_Box_final_Debounce_h_ */

/* [EOF] */
