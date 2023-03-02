/*
 * File: BlinkerCAN.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model BlinkerCAN.
 *
 * Model version                        : 1.8
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Sun Dec  3 17:46:43 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Sun Dec  3 17:46:43 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BlinkerCAN_h_
#define RTW_HEADER_BlinkerCAN_h_
#include <stddef.h>
#include <string.h>
#ifndef BlinkerCAN_COMMON_INCLUDES_
# define BlinkerCAN_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* BlinkerCAN_COMMON_INCLUDES_ */

#include "BlinkerCAN_types.h"

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
  uint32_T CANReceive2_o2;             /* '<Root>/CAN Receive2' */
  uint32_T CANReceive3_o2;             /* '<Root>/CAN Receive3' */
  uint32_T CANReceive4_o2;             /* '<Root>/CAN Receive4' */
  uint16_T CANReceive_o1;              /* '<Root>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<Root>/CAN Receive1' */
  uint16_T CANReceive2_o1;             /* '<Root>/CAN Receive2' */
  uint16_T CANReceive3_o1;             /* '<Root>/CAN Receive3' */
  uint16_T CANReceive3_o3;             /* '<Root>/CAN Receive3' */
  uint16_T CANReceive4_o1;             /* '<Root>/CAN Receive4' */
  uint8_T CANReceive_o3;               /* '<Root>/CAN Receive' */
  uint8_T CANReceive1_o3;              /* '<Root>/CAN Receive1' */
  uint8_T CANReceive2_o3;              /* '<Root>/CAN Receive2' */
  uint8_T CANReceive4_o3;              /* '<Root>/CAN Receive4' */
  boolean_T Compare_c;                 /* '<S51>/Compare' */
  boolean_T Compare_d2;                /* '<S17>/Compare' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
  boolean_T FEL_LED;                   /* '<Root>/Steuerung_Licht' */
  boolean_T ABL_LED;                   /* '<Root>/Steuerung_Licht' */
  boolean_T TFL_LED;                   /* '<Root>/Steuerung_Licht' */
  boolean_T BLL_LED;                   /* '<Root>/Steuerung_Blinker' */
  boolean_T BLR_LED;                   /* '<Root>/Steuerung_Blinker' */
} B_BlinkerCAN_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T CountL;                       /* '<Root>/Steuerung_Blinker' */
  real_T CountR;                       /* '<Root>/Steuerung_Blinker' */
  real_T SchliessCount;                /* '<Root>/Steuerung_Blinker' */
  boolean_T DelayInput1_DSTATE;        /* '<S52>/Delay Input1' */
  uint8_T is_active_c1_BlinkerCAN;     /* '<Root>/Steuerung_Licht' */
  uint8_T is_c1_BlinkerCAN;            /* '<Root>/Steuerung_Licht' */
  uint8_T is_Dunkel;                   /* '<Root>/Steuerung_Licht' */
  uint8_T is_active_c3_BlinkerCAN;     /* '<Root>/Steuerung_Blinker' */
  uint8_T is_c3_BlinkerCAN;            /* '<Root>/Steuerung_Blinker' */
  uint8_T temporalCounter_i1;          /* '<Root>/Steuerung_Blinker' */
} DW_BlinkerCAN_T;

/* Real-time Model Data Structure */
struct tag_RTM_BlinkerCAN_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_BlinkerCAN_T BlinkerCAN_B;

/* Block states (auto storage) */
extern DW_BlinkerCAN_T BlinkerCAN_DW;

/* Model entry point functions */
extern void BlinkerCAN_initialize(void);
extern void BlinkerCAN_step(void);
extern void BlinkerCAN_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BlinkerCAN_T *const BlinkerCAN_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Compare' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S1>/Display4' : Unused code path elimination
 * Block '<S16>/Compare' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S2>/Display4' : Unused code path elimination
 * Block '<S28>/Compare' : Unused code path elimination
 * Block '<S28>/Constant' : Unused code path elimination
 * Block '<S31>/Compare' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S36>/Compare' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S39>/Compare' : Unused code path elimination
 * Block '<S39>/Constant' : Unused code path elimination
 * Block '<S20>/Display1' : Unused code path elimination
 * Block '<S20>/Display3' : Unused code path elimination
 * Block '<S20>/Display4' : Unused code path elimination
 * Block '<S20>/Display5' : Unused code path elimination
 * Block '<S50>/Compare' : Unused code path elimination
 * Block '<S50>/Constant' : Unused code path elimination
 * Block '<S4>/Display4' : Unused code path elimination
 * Block '<S59>/Compare' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S5>/Display1' : Unused code path elimination
 * Block '<S5>/Display4' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'BlinkerCAN'
 * '<S1>'   : 'BlinkerCAN/CanDecoder_Alarm_1'
 * '<S2>'   : 'BlinkerCAN/CanDecoder_Bremse_1'
 * '<S3>'   : 'BlinkerCAN/CanDecoder_Cockpit_1'
 * '<S4>'   : 'BlinkerCAN/CanDecoder_Schloss_1'
 * '<S5>'   : 'BlinkerCAN/CanDecoder_Sensor_1'
 * '<S6>'   : 'BlinkerCAN/Steuerung_Blinker'
 * '<S7>'   : 'BlinkerCAN/Steuerung_Licht'
 * '<S8>'   : 'BlinkerCAN/CanDecoder_Alarm_1/Bit Shift4'
 * '<S9>'   : 'BlinkerCAN/CanDecoder_Alarm_1/Bit Shift5'
 * '<S10>'  : 'BlinkerCAN/CanDecoder_Alarm_1/Compare To Constant11'
 * '<S11>'  : 'BlinkerCAN/CanDecoder_Alarm_1/Compare To Constant12'
 * '<S12>'  : 'BlinkerCAN/CanDecoder_Alarm_1/Bit Shift4/bit_shift'
 * '<S13>'  : 'BlinkerCAN/CanDecoder_Alarm_1/Bit Shift5/bit_shift'
 * '<S14>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Bit Shift4'
 * '<S15>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Bit Shift5'
 * '<S16>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Compare To Constant11'
 * '<S17>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Compare To Constant12'
 * '<S18>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Bit Shift4/bit_shift'
 * '<S19>'  : 'BlinkerCAN/CanDecoder_Bremse_1/Bit Shift5/bit_shift'
 * '<S20>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem'
 * '<S21>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift'
 * '<S22>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift1'
 * '<S23>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift2'
 * '<S24>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift3'
 * '<S25>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift4'
 * '<S26>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift5'
 * '<S27>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift6'
 * '<S28>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant'
 * '<S29>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant1'
 * '<S30>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant10'
 * '<S31>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant11'
 * '<S32>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant12'
 * '<S33>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant2'
 * '<S34>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant3'
 * '<S35>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant4'
 * '<S36>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant5'
 * '<S37>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant6'
 * '<S38>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant7'
 * '<S39>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant8'
 * '<S40>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Compare To Constant9'
 * '<S41>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift/bit_shift'
 * '<S42>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift1/bit_shift'
 * '<S43>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift2/bit_shift'
 * '<S44>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift3/bit_shift'
 * '<S45>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift4/bit_shift'
 * '<S46>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift5/bit_shift'
 * '<S47>'  : 'BlinkerCAN/CanDecoder_Cockpit_1/Subsystem/Bit Shift6/bit_shift'
 * '<S48>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Bit Shift4'
 * '<S49>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Bit Shift5'
 * '<S50>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Compare To Constant11'
 * '<S51>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Compare To Constant12'
 * '<S52>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Detect Change'
 * '<S53>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Bit Shift4/bit_shift'
 * '<S54>'  : 'BlinkerCAN/CanDecoder_Schloss_1/Bit Shift5/bit_shift'
 * '<S55>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift1'
 * '<S56>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift2'
 * '<S57>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift4'
 * '<S58>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift5'
 * '<S59>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Compare To Constant11'
 * '<S60>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Compare To Constant12'
 * '<S61>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift1/bit_shift'
 * '<S62>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift2/bit_shift'
 * '<S63>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift4/bit_shift'
 * '<S64>'  : 'BlinkerCAN/CanDecoder_Sensor_1/Bit Shift5/bit_shift'
 */
#endif                                 /* RTW_HEADER_BlinkerCAN_h_ */

/* [EOF] */
