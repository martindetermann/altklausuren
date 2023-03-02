/*
 * File: SchlossBox_Debounce.h
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

#ifndef RTW_HEADER_SchlossBox_Debounce_h_
#define RTW_HEADER_SchlossBox_Debounce_h_
#ifndef SchlossBox_COMMON_INCLUDES_
# define SchlossBox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* SchlossBox_COMMON_INCLUDES_ */

#include "SchlossBox_types.h"

/* Block states (auto storage) for system '<S8>/Enabled Subsystem' */
typedef struct {
  uint32_T Output_DSTATE;              /* '<S24>/Output' */
} DW_EnabledSubsystem_SchlossBo_T;

/* Block signals for system '<Root>/Debounce' */
typedef struct {
  uint32_T Output;                     /* '<S34>/Output' */
  uint32_T Output_j;                   /* '<S31>/Output' */
  uint32_T Output_ji;                  /* '<S24>/Output' */
  uint8_T Compare;                     /* '<S27>/Compare' */
} B_Debounce_SchlossBox_T;

/* Block states (auto storage) for system '<Root>/Debounce' */
typedef struct {
  uint32_T Output_DSTATE;              /* '<S28>/Output' */
  uint32_T Memory_PreviousInput;       /* '<S8>/Memory' */
  uint32_T Memory1_PreviousInput;      /* '<S8>/Memory1' */
  boolean_T Memory3_PreviousInput;     /* '<S8>/Memory3' */
  boolean_T Memory2_PreviousInput;     /* '<S8>/Memory2' */
  DW_EnabledSubsystem_SchlossBo_T EnabledSubsystem5;/* '<S8>/Enabled Subsystem5' */
  DW_EnabledSubsystem_SchlossBo_T EnabledSubsystem4;/* '<S8>/Enabled Subsystem4' */
  DW_EnabledSubsystem_SchlossBo_T EnabledSubsystem;/* '<S8>/Enabled Subsystem' */
} DW_Debounce_SchlossBox_T;

extern void SchlossBox_EnabledSubsystem(boolean_T rtu_Enable, uint32_T *rty_Out1,
  DW_EnabledSubsystem_SchlossBo_T *localDW);
extern boolean_T SchlossBox_Debounce(boolean_T rtu_In1, B_Debounce_SchlossBox_T *
  localB, DW_Debounce_SchlossBox_T *localDW, int32_T rtp_mode);

#endif                                 /* RTW_HEADER_SchlossBox_Debounce_h_ */

/* [EOF] */
