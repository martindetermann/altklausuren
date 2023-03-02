/*
 * File: Wischer_Sensorbox.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Wischer_Sensorbox.
 *
 * Model version                        : 1.3
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Sun Dec  3 20:04:08 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Sun Dec  3 20:04:08 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wischer_Sensorbox_h_
#define RTW_HEADER_Wischer_Sensorbox_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Wischer_Sensorbox_COMMON_INCLUDES_
# define Wischer_Sensorbox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* Wischer_Sensorbox_COMMON_INCLUDES_ */

#include "Wischer_Sensorbox_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  uint32_T CANReceive_o2;              /* '<Root>/CAN Receive' */
  uint32_T CANReceive1_o2;             /* '<Root>/CAN Receive1' */
  uint16_T CANReceive_o1;              /* '<Root>/CAN Receive' */
  uint16_T CANReceive_o3;              /* '<Root>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<Root>/CAN Receive1' */
  uint16_T RegularADC;                 /* '<Root>/Regular ADC' */
  uint16_T BitwiseOperator3;           /* '<S1>/Bitwise Operator3' */
  uint8_T CANReceive1_o3;              /* '<Root>/CAN Receive1' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T SM_A;                      /* '<Root>/WischerSteuerung' */
  boolean_T SM_B;                      /* '<Root>/WischerSteuerung' */
  boolean_T SM_C;                      /* '<Root>/WischerSteuerung' */
  boolean_T SM_D;                      /* '<Root>/WischerSteuerung' */
  boolean_T WW_LED;                    /* '<Root>/WischerSteuerung' */
  boolean_T SH_LED;                    /* '<Root>/ScheibenheizungsSteuerung' */
} B_Wischer_Sensorbox_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Steps;                        /* '<Root>/WischerSteuerung' */
  real_T StepTime;                     /* '<Root>/WischerSteuerung' */
  real_T Count;                        /* '<Root>/WischerSteuerung' */
  real_T BreakTime;                    /* '<Root>/WischerSteuerung' */
  uint32_T temporalCounter_i1;         /* '<Root>/WischerSteuerung' */
  uint16_T DelayInput1_DSTATE;         /* '<S7>/Delay Input1' */
  uint16_T temporalCounter_i1_f;       /* '<Root>/ScheibenheizungsSteuerung' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S8>/Delay Input1' */
  uint8_T is_active_c5_Wischer_Sensorbox;/* '<Root>/WischerSteuerung' */
  uint8_T is_c5_Wischer_Sensorbox;     /* '<Root>/WischerSteuerung' */
  uint8_T is_Wischer_Vor_WW;           /* '<Root>/WischerSteuerung' */
  uint8_T is_Wischer_Rueck_WW;         /* '<Root>/WischerSteuerung' */
  uint8_T is_Wischer1;                 /* '<Root>/WischerSteuerung' */
  uint8_T is_Wischer_Vor;              /* '<Root>/WischerSteuerung' */
  uint8_T is_Wischer_Rueck;            /* '<Root>/WischerSteuerung' */
  uint8_T WischWaschCount;             /* '<Root>/WischerSteuerung' */
  uint8_T is_active_c6_Wischer_Sensorbox;/* '<Root>/ScheibenheizungsSteuerung' */
  uint8_T is_c6_Wischer_Sensorbox;     /* '<Root>/ScheibenheizungsSteuerung' */
  uint8_T is_MANUELL;                  /* '<Root>/ScheibenheizungsSteuerung' */
  uint8_T is_AUTO;                     /* '<Root>/ScheibenheizungsSteuerung' */
} DW_Wischer_Sensorbox_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
} PrevZCX_Wischer_Sensorbox_T;

/* Real-time Model Data Structure */
struct tag_RTM_Wischer_Sensorbox_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_Wischer_Sensorbox_T Wischer_Sensorbox_B;

/* Block states (auto storage) */
extern DW_Wischer_Sensorbox_T Wischer_Sensorbox_DW;

/* Model entry point functions */
extern void Wischer_Sensorbox_initialize(void);
extern void Wischer_Sensorbox_step(void);
extern void Wischer_Sensorbox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Wischer_Sensorbox_T *const Wischer_Sensorbox_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S2>/Display4' : Unused code path elimination
 * Block '<S35>/Compare' : Unused code path elimination
 * Block '<S35>/Constant' : Unused code path elimination
 * Block '<S3>/Display4' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Wischer_Sensorbox'
 * '<S1>'   : 'Wischer_Sensorbox/CanCoder_Sensor_1'
 * '<S2>'   : 'Wischer_Sensorbox/CanDecoder_Cockpit_2'
 * '<S3>'   : 'Wischer_Sensorbox/CanDecoder_Schloss_1'
 * '<S4>'   : 'Wischer_Sensorbox/ScheibenheizungsSteuerung'
 * '<S5>'   : 'Wischer_Sensorbox/Triggered Subsystem'
 * '<S6>'   : 'Wischer_Sensorbox/WischerSteuerung'
 * '<S7>'   : 'Wischer_Sensorbox/CanCoder_Sensor_1/Detect Change3'
 * '<S8>'   : 'Wischer_Sensorbox/CanCoder_Sensor_1/Detect Change4'
 * '<S9>'   : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift1'
 * '<S10>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift2'
 * '<S11>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift3'
 * '<S12>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift4'
 * '<S13>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift5'
 * '<S14>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift6'
 * '<S15>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift7'
 * '<S16>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift8'
 * '<S17>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant1'
 * '<S18>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant11'
 * '<S19>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant12'
 * '<S20>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant2'
 * '<S21>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant3'
 * '<S22>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant4'
 * '<S23>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant5'
 * '<S24>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Compare To Constant6'
 * '<S25>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift1/bit_shift'
 * '<S26>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift2/bit_shift'
 * '<S27>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift3/bit_shift'
 * '<S28>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift4/bit_shift'
 * '<S29>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift5/bit_shift'
 * '<S30>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift6/bit_shift'
 * '<S31>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift7/bit_shift'
 * '<S32>'  : 'Wischer_Sensorbox/CanDecoder_Cockpit_2/Bit Shift8/bit_shift'
 * '<S33>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Bit Shift4'
 * '<S34>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Bit Shift5'
 * '<S35>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Compare To Constant11'
 * '<S36>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Compare To Constant12'
 * '<S37>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Bit Shift4/bit_shift'
 * '<S38>'  : 'Wischer_Sensorbox/CanDecoder_Schloss_1/Bit Shift5/bit_shift'
 */
#endif                                 /* RTW_HEADER_Wischer_Sensorbox_h_ */

/* [EOF] */
