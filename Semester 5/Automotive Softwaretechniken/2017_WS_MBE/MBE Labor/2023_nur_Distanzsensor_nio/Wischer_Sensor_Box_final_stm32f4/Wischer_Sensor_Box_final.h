/*
 * File: Wischer_Sensor_Box_final.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Wischer_Sensor_Box_final.
 *
 * Model version                        : 1.7
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Tue Dec  5 15:44:29 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Tue Dec  5 15:44:29 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wischer_Sensor_Box_final_h_
#define RTW_HEADER_Wischer_Sensor_Box_final_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Wischer_Sensor_Box_final_COMMON_INCLUDES_
# define Wischer_Sensor_Box_final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* Wischer_Sensor_Box_final_COMMON_INCLUDES_ */

#include "Wischer_Sensor_Box_final_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  uint32_T CANReceive_o2;              /* '<S1>/CAN Receive' */
  uint32_T CANReceive1_o2;             /* '<S1>/CAN Receive1' */
  uint16_T CANReceive_o1;              /* '<S1>/CAN Receive' */
  uint16_T CANReceive_o3;              /* '<S1>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<S1>/CAN Receive1' */
  uint16_T RegularADC;                 /* '<S1>/Regular ADC' */
  uint16_T BitwiseOperator3;           /* '<S5>/Bitwise Operator3' */
  uint8_T CANReceive1_o3;              /* '<S1>/CAN Receive1' */
  boolean_T DigitalInput1;             /* '<S1>/Digital Input1' */
  boolean_T SM_A;                      /* '<S4>/WischerSteuerung' */
  boolean_T SM_B;                      /* '<S4>/WischerSteuerung' */
  boolean_T SM_C;                      /* '<S4>/WischerSteuerung' */
  boolean_T SM_D;                      /* '<S4>/WischerSteuerung' */
  boolean_T WW_LED;                    /* '<S4>/WischerSteuerung' */
  boolean_T SH_LED;                    /* '<S4>/ScheibenheizungsSteuerung' */
} B_Wischer_Sensor_Box_final_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Steps;                        /* '<S4>/WischerSteuerung' */
  real_T StepTime;                     /* '<S4>/WischerSteuerung' */
  real_T Count;                        /* '<S4>/WischerSteuerung' */
  real_T BreakTime;                    /* '<S4>/WischerSteuerung' */
  uint32_T temporalCounter_i1;         /* '<S4>/WischerSteuerung' */
  uint16_T DelayInput1_DSTATE;         /* '<S10>/Delay Input1' */
  uint16_T temporalCounter_i1_j;       /* '<S4>/ScheibenheizungsSteuerung' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S11>/Delay Input1' */
  uint8_T is_active_c2_Wischer_Sensor_Box;/* '<S4>/WischerSteuerung' */
  uint8_T is_c2_Wischer_Sensor_Box_final;/* '<S4>/WischerSteuerung' */
  uint8_T is_Wischer1;                 /* '<S4>/WischerSteuerung' */
  uint8_T is_Wischer_Vor;              /* '<S4>/WischerSteuerung' */
  uint8_T is_Wischer_Rueck;            /* '<S4>/WischerSteuerung' */
  uint8_T is_Wischer_Vor_WW;           /* '<S4>/WischerSteuerung' */
  uint8_T is_Wischer_Rueck_WW;         /* '<S4>/WischerSteuerung' */
  uint8_T WischWaschCount;             /* '<S4>/WischerSteuerung' */
  uint8_T is_active_c1_Wischer_Sensor_Box;/* '<S4>/ScheibenheizungsSteuerung' */
  uint8_T is_c1_Wischer_Sensor_Box_final;/* '<S4>/ScheibenheizungsSteuerung' */
  uint8_T is_MANUELL;                  /* '<S4>/ScheibenheizungsSteuerung' */
  uint8_T is_AUTO;                     /* '<S4>/ScheibenheizungsSteuerung' */
} DW_Wischer_Sensor_Box_final_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S2>/Triggered Subsystem' */
} PrevZCX_Wischer_Sensor_Box_fi_T;

/* Real-time Model Data Structure */
struct tag_RTM_Wischer_Sensor_Box_fi_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_Wischer_Sensor_Box_final_T Wischer_Sensor_Box_final_B;

/* Block states (auto storage) */
extern DW_Wischer_Sensor_Box_final_T Wischer_Sensor_Box_final_DW;

/* Model entry point functions */
extern void Wischer_Sensor_Box_final_initialize(void);
extern void Wischer_Sensor_Box_final_step(void);
extern void Wischer_Sensor_Box_final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Wischer_Sensor_Box_f_T *const Wischer_Sensor_Box_final_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Display1' : Unused code path elimination
 * Block '<S6>/Display2' : Unused code path elimination
 * Block '<S6>/Display4' : Unused code path elimination
 * Block '<S40>/Compare' : Unused code path elimination
 * Block '<S40>/Constant' : Unused code path elimination
 * Block '<S7>/Display4' : Unused code path elimination
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Wischer_Sensor_Box_final'
 * '<S1>'   : 'Wischer_Sensor_Box_final/Input'
 * '<S2>'   : 'Wischer_Sensor_Box_final/Output'
 * '<S3>'   : 'Wischer_Sensor_Box_final/Setup'
 * '<S4>'   : 'Wischer_Sensor_Box_final/Verarbeitung'
 * '<S5>'   : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1'
 * '<S6>'   : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2'
 * '<S7>'   : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1'
 * '<S8>'   : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Bit Shift4'
 * '<S9>'   : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Bit Shift5'
 * '<S10>'  : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Detect Change3'
 * '<S11>'  : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Detect Change4'
 * '<S12>'  : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Bit Shift4/bit_shift'
 * '<S13>'  : 'Wischer_Sensor_Box_final/Input/CanCoder_Sensor_1/Bit Shift5/bit_shift'
 * '<S14>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift1'
 * '<S15>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift2'
 * '<S16>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift3'
 * '<S17>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift4'
 * '<S18>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift5'
 * '<S19>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift6'
 * '<S20>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift7'
 * '<S21>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift8'
 * '<S22>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant1'
 * '<S23>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant11'
 * '<S24>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant12'
 * '<S25>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant2'
 * '<S26>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant3'
 * '<S27>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant4'
 * '<S28>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant5'
 * '<S29>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Compare To Constant6'
 * '<S30>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift1/bit_shift'
 * '<S31>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift2/bit_shift'
 * '<S32>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift3/bit_shift'
 * '<S33>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift4/bit_shift'
 * '<S34>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift5/bit_shift'
 * '<S35>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift6/bit_shift'
 * '<S36>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift7/bit_shift'
 * '<S37>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Cockpit_2/Bit Shift8/bit_shift'
 * '<S38>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Bit Shift4'
 * '<S39>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Bit Shift5'
 * '<S40>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Compare To Constant11'
 * '<S41>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Compare To Constant12'
 * '<S42>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Bit Shift4/bit_shift'
 * '<S43>'  : 'Wischer_Sensor_Box_final/Input/CanDecoder_Schloss_1/Bit Shift5/bit_shift'
 * '<S44>'  : 'Wischer_Sensor_Box_final/Output/Triggered Subsystem'
 * '<S45>'  : 'Wischer_Sensor_Box_final/Verarbeitung/ScheibenheizungsSteuerung'
 * '<S46>'  : 'Wischer_Sensor_Box_final/Verarbeitung/WischerSteuerung'
 */
#endif                                 /* RTW_HEADER_Wischer_Sensor_Box_final_h_ */

/* [EOF] */
