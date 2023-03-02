/*
 * File: Blinker_Box_final.h
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

#ifndef RTW_HEADER_Blinker_Box_final_h_
#define RTW_HEADER_Blinker_Box_final_h_
#include <stddef.h>
#include <string.h>
#ifndef Blinker_Box_final_COMMON_INCLUDES_
# define Blinker_Box_final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* Blinker_Box_final_COMMON_INCLUDES_ */

#include "Blinker_Box_final_types.h"

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
  uint32_T CANReceive2_o2;             /* '<S1>/CAN Receive2' */
  uint32_T CANReceive3_o2;             /* '<S1>/CAN Receive3' */
  uint32_T CANReceive4_o2;             /* '<S1>/CAN Receive4' */
  uint16_T CANReceive_o1;              /* '<S1>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<S1>/CAN Receive1' */
  uint16_T CANReceive2_o1;             /* '<S1>/CAN Receive2' */
  uint16_T CANReceive3_o1;             /* '<S1>/CAN Receive3' */
  uint16_T CANReceive3_o3;             /* '<S1>/CAN Receive3' */
  uint16_T CANReceive4_o1;             /* '<S1>/CAN Receive4' */
  uint8_T CANReceive_o3;               /* '<S1>/CAN Receive' */
  uint8_T CANReceive1_o3;              /* '<S1>/CAN Receive1' */
  uint8_T CANReceive2_o3;              /* '<S1>/CAN Receive2' */
  uint8_T CANReceive4_o3;              /* '<S1>/CAN Receive4' */
  boolean_T Compare_bf;                /* '<S19>/Compare' */
  boolean_T Rcklicht;                  /* '<S4>/Logical Operator' */
  boolean_T FEL_LED;                   /* '<S4>/Steuerung_Licht' */
  boolean_T ABL_LED;                   /* '<S4>/Steuerung_Licht' */
  boolean_T TFL_LED;                   /* '<S4>/Steuerung_Licht' */
  boolean_T BLL_LED;                   /* '<S4>/Steuerung_Blinker' */
  boolean_T BLR_LED;                   /* '<S4>/Steuerung_Blinker' */
} B_Blinker_Box_final_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T CountL;                       /* '<S4>/Steuerung_Blinker' */
  real_T CountR;                       /* '<S4>/Steuerung_Blinker' */
  real_T SchliessCount;                /* '<S4>/Steuerung_Blinker' */
  boolean_T DelayInput1_DSTATE;        /* '<S54>/Delay Input1' */
  uint8_T is_active_c4_Blinker_Box_final;/* '<S4>/Steuerung_Licht' */
  uint8_T is_c4_Blinker_Box_final;     /* '<S4>/Steuerung_Licht' */
  uint8_T is_Licht_Auto;               /* '<S4>/Steuerung_Licht' */
  uint8_T is_Dunkel;                   /* '<S4>/Steuerung_Licht' */
  uint8_T is_active_c2_Blinker_Box_final;/* '<S4>/Steuerung_Blinker' */
  uint8_T is_c2_Blinker_Box_final;     /* '<S4>/Steuerung_Blinker' */
  uint8_T temporalCounter_i1;          /* '<S4>/Steuerung_Blinker' */
} DW_Blinker_Box_final_T;

/* Real-time Model Data Structure */
struct tag_RTM_Blinker_Box_final_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_Blinker_Box_final_T Blinker_Box_final_B;

/* Block states (auto storage) */
extern DW_Blinker_Box_final_T Blinker_Box_final_DW;

/* Model entry point functions */
extern void Blinker_Box_final_initialize(void);
extern void Blinker_Box_final_step(void);
extern void Blinker_Box_final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Blinker_Box_final_T *const Blinker_Box_final_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Compare' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S5>/Display4' : Unused code path elimination
 * Block '<S18>/Compare' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S6>/Display4' : Unused code path elimination
 * Block '<S30>/Compare' : Unused code path elimination
 * Block '<S30>/Constant' : Unused code path elimination
 * Block '<S33>/Compare' : Unused code path elimination
 * Block '<S33>/Constant' : Unused code path elimination
 * Block '<S38>/Compare' : Unused code path elimination
 * Block '<S38>/Constant' : Unused code path elimination
 * Block '<S41>/Compare' : Unused code path elimination
 * Block '<S41>/Constant' : Unused code path elimination
 * Block '<S22>/Display1' : Unused code path elimination
 * Block '<S22>/Display3' : Unused code path elimination
 * Block '<S22>/Display4' : Unused code path elimination
 * Block '<S22>/Display5' : Unused code path elimination
 * Block '<S52>/Compare' : Unused code path elimination
 * Block '<S52>/Constant' : Unused code path elimination
 * Block '<S8>/Display4' : Unused code path elimination
 * Block '<S61>/Compare' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S9>/Display1' : Unused code path elimination
 * Block '<S9>/Display4' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Blinker_Box_final'
 * '<S1>'   : 'Blinker_Box_final/Input'
 * '<S2>'   : 'Blinker_Box_final/Output'
 * '<S3>'   : 'Blinker_Box_final/Setup'
 * '<S4>'   : 'Blinker_Box_final/Verarbeitung'
 * '<S5>'   : 'Blinker_Box_final/Input/CanDecoder_Alarm_1'
 * '<S6>'   : 'Blinker_Box_final/Input/CanDecoder_Bremse_1'
 * '<S7>'   : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1'
 * '<S8>'   : 'Blinker_Box_final/Input/CanDecoder_Schloss_1'
 * '<S9>'   : 'Blinker_Box_final/Input/CanDecoder_Sensor_1'
 * '<S10>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Bit Shift4'
 * '<S11>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Bit Shift5'
 * '<S12>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Compare To Constant11'
 * '<S13>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Compare To Constant12'
 * '<S14>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Bit Shift4/bit_shift'
 * '<S15>'  : 'Blinker_Box_final/Input/CanDecoder_Alarm_1/Bit Shift5/bit_shift'
 * '<S16>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Bit Shift4'
 * '<S17>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Bit Shift5'
 * '<S18>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Compare To Constant11'
 * '<S19>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Compare To Constant12'
 * '<S20>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Bit Shift4/bit_shift'
 * '<S21>'  : 'Blinker_Box_final/Input/CanDecoder_Bremse_1/Bit Shift5/bit_shift'
 * '<S22>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem'
 * '<S23>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift'
 * '<S24>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift1'
 * '<S25>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift2'
 * '<S26>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift3'
 * '<S27>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift4'
 * '<S28>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift5'
 * '<S29>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift6'
 * '<S30>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant'
 * '<S31>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant1'
 * '<S32>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant10'
 * '<S33>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant11'
 * '<S34>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant12'
 * '<S35>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant2'
 * '<S36>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant3'
 * '<S37>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant4'
 * '<S38>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant5'
 * '<S39>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant6'
 * '<S40>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant7'
 * '<S41>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant8'
 * '<S42>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Compare To Constant9'
 * '<S43>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift/bit_shift'
 * '<S44>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift1/bit_shift'
 * '<S45>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift2/bit_shift'
 * '<S46>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift3/bit_shift'
 * '<S47>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift4/bit_shift'
 * '<S48>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift5/bit_shift'
 * '<S49>'  : 'Blinker_Box_final/Input/CanDecoder_Cockpit_1/Subsystem/Bit Shift6/bit_shift'
 * '<S50>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Bit Shift4'
 * '<S51>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Bit Shift5'
 * '<S52>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Compare To Constant11'
 * '<S53>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Compare To Constant12'
 * '<S54>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Detect Change'
 * '<S55>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Bit Shift4/bit_shift'
 * '<S56>'  : 'Blinker_Box_final/Input/CanDecoder_Schloss_1/Bit Shift5/bit_shift'
 * '<S57>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift1'
 * '<S58>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift2'
 * '<S59>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift4'
 * '<S60>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift5'
 * '<S61>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Compare To Constant11'
 * '<S62>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Compare To Constant12'
 * '<S63>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift1/bit_shift'
 * '<S64>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift2/bit_shift'
 * '<S65>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift4/bit_shift'
 * '<S66>'  : 'Blinker_Box_final/Input/CanDecoder_Sensor_1/Bit Shift5/bit_shift'
 * '<S67>'  : 'Blinker_Box_final/Verarbeitung/Steuerung_Blinker'
 * '<S68>'  : 'Blinker_Box_final/Verarbeitung/Steuerung_Licht'
 */
#endif                                 /* RTW_HEADER_Blinker_Box_final_h_ */

/* [EOF] */
