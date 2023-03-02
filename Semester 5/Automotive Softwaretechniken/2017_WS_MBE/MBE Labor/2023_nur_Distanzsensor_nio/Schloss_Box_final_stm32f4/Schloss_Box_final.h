/*
 * File: Schloss_Box_final.h
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

#ifndef RTW_HEADER_Schloss_Box_final_h_
#define RTW_HEADER_Schloss_Box_final_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Schloss_Box_final_COMMON_INCLUDES_
# define Schloss_Box_final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* Schloss_Box_final_COMMON_INCLUDES_ */

#include "Schloss_Box_final_types.h"

/* Child system includes */
#include "Schloss_Box_final_Debounce.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SchliessZustand;              /* '<S4>/Chart' */
  real_T AlarmZustand;                 /* '<S4>/Chart' */
  uint32_T CANReceive_o2;              /* '<S1>/CAN Receive' */
  uint32_T CANReceive1_o2;             /* '<S1>/CAN Receive1' */
  uint16_T CANReceive_o1;              /* '<S1>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<S1>/CAN Receive1' */
  uint8_T CANReceive_o3;               /* '<S1>/CAN Receive' */
  uint8_T CANReceive1_o3;              /* '<S1>/CAN Receive1' */
  uint8_T Gain4;                       /* '<S55>/Gain4' */
  uint8_T Gain4_m;                     /* '<S56>/Gain4' */
  boolean_T DigitalInput_o1;           /* '<S1>/Digital Input' */
  boolean_T DigitalInput_o2;           /* '<S1>/Digital Input' */
  boolean_T AlarmLED;                  /* '<S4>/Chart' */
  B_Debounce_Schloss_Box_final_T Debounce1;/* '<S1>/Debounce1' */
  B_Debounce_Schloss_Box_final_T Debounce;/* '<S1>/Debounce' */
} B_Schloss_Box_final_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S57>/Delay Input1' */
  real_T DelayInput1_DSTATE_o;         /* '<S58>/Delay Input1' */
  uint8_T is_active_c2_Schloss_Box_final;/* '<S4>/Chart' */
  uint8_T is_Schliessanlage;           /* '<S4>/Chart' */
  uint8_T is_Alarmanlage;              /* '<S4>/Chart' */
  uint8_T is_ON;                       /* '<S4>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S4>/Chart' */
  DW_Debounce_Schloss_Box_final_T Debounce1;/* '<S1>/Debounce1' */
  DW_Debounce_Schloss_Box_final_T Debounce;/* '<S1>/Debounce' */
} DW_Schloss_Box_final_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState CANTransmitSchloss_1_Trig_ZCE;/* '<S2>/CAN Transmit Schloss_1' */
  ZCSigState CANTransmitAlarm_1_Trig_ZCE;/* '<S2>/CAN Transmit Alarm_1' */
} PrevZCX_Schloss_Box_final_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0; 1])
   * Referenced by:
   *   '<S55>/Direct Lookup Table (n-D)2'
   *   '<S56>/Direct Lookup Table (n-D)2'
   */
  real_T pooled3[2];
} ConstP_Schloss_Box_final_T;

/* Real-time Model Data Structure */
struct tag_RTM_Schloss_Box_final_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_Schloss_Box_final_T Schloss_Box_final_B;

/* Block states (auto storage) */
extern DW_Schloss_Box_final_T Schloss_Box_final_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Schloss_Box_final_T Schloss_Box_final_PrevZCX;

/* Constant parameters (auto storage) */
extern const ConstP_Schloss_Box_final_T Schloss_Box_final_ConstP;

/* Model entry point functions */
extern void Schloss_Box_final_initialize(void);
extern void Schloss_Box_final_step(void);
extern void Schloss_Box_final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Schloss_Box_final_T *const Schloss_Box_final_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Display4' : Unused code path elimination
 * Block '<S11>/Compare' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S6>/Display4' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S29>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S32>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S40>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S41>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S44>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S45>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S48>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S51>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Schloss_Box_final'
 * '<S1>'   : 'Schloss_Box_final/Input'
 * '<S2>'   : 'Schloss_Box_final/Output'
 * '<S3>'   : 'Schloss_Box_final/Setup'
 * '<S4>'   : 'Schloss_Box_final/Verarbeitung'
 * '<S5>'   : 'Schloss_Box_final/Input/CanDecoder_Bremse_2'
 * '<S6>'   : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3'
 * '<S7>'   : 'Schloss_Box_final/Input/Debounce'
 * '<S8>'   : 'Schloss_Box_final/Input/Debounce1'
 * '<S9>'   : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Bit Shift4'
 * '<S10>'  : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Bit Shift5'
 * '<S11>'  : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Compare To Constant11'
 * '<S12>'  : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Compare To Constant12'
 * '<S13>'  : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Bit Shift4/bit_shift'
 * '<S14>'  : 'Schloss_Box_final/Input/CanDecoder_Cockpit_3/Bit Shift5/bit_shift'
 * '<S15>'  : 'Schloss_Box_final/Input/Debounce/Compare To Zero'
 * '<S16>'  : 'Schloss_Box_final/Input/Debounce/Compare To Zero1'
 * '<S17>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem'
 * '<S18>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem1'
 * '<S19>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem4'
 * '<S20>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem5'
 * '<S21>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem/Counter Free-Running'
 * '<S22>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem/Counter Free-Running/Increment Real World'
 * '<S23>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S24>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem1/Compare To Zero'
 * '<S25>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem1/Counter Free-Running'
 * '<S26>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem1/Counter Free-Running/Increment Real World'
 * '<S27>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem1/Counter Free-Running/Wrap To Zero'
 * '<S28>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem4/Counter Free-Running'
 * '<S29>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem4/Counter Free-Running/Increment Real World'
 * '<S30>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem4/Counter Free-Running/Wrap To Zero'
 * '<S31>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem5/Counter Free-Running'
 * '<S32>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem5/Counter Free-Running/Increment Real World'
 * '<S33>'  : 'Schloss_Box_final/Input/Debounce/Enabled Subsystem5/Counter Free-Running/Wrap To Zero'
 * '<S34>'  : 'Schloss_Box_final/Input/Debounce1/Compare To Zero'
 * '<S35>'  : 'Schloss_Box_final/Input/Debounce1/Compare To Zero1'
 * '<S36>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem'
 * '<S37>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem1'
 * '<S38>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem4'
 * '<S39>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem5'
 * '<S40>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem/Counter Free-Running'
 * '<S41>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem/Counter Free-Running/Increment Real World'
 * '<S42>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S43>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem1/Compare To Zero'
 * '<S44>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem1/Counter Free-Running'
 * '<S45>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem1/Counter Free-Running/Increment Real World'
 * '<S46>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem1/Counter Free-Running/Wrap To Zero'
 * '<S47>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem4/Counter Free-Running'
 * '<S48>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem4/Counter Free-Running/Increment Real World'
 * '<S49>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem4/Counter Free-Running/Wrap To Zero'
 * '<S50>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem5/Counter Free-Running'
 * '<S51>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem5/Counter Free-Running/Increment Real World'
 * '<S52>'  : 'Schloss_Box_final/Input/Debounce1/Enabled Subsystem5/Counter Free-Running/Wrap To Zero'
 * '<S53>'  : 'Schloss_Box_final/Output/CAN Transmit Alarm_1'
 * '<S54>'  : 'Schloss_Box_final/Output/CAN Transmit Schloss_1'
 * '<S55>'  : 'Schloss_Box_final/Output/CanCoder_Alarm_1'
 * '<S56>'  : 'Schloss_Box_final/Output/CanCoder_Schloss_1'
 * '<S57>'  : 'Schloss_Box_final/Output/CanCoder_Alarm_1/Detect Change4'
 * '<S58>'  : 'Schloss_Box_final/Output/CanCoder_Schloss_1/Detect Change4'
 * '<S59>'  : 'Schloss_Box_final/Verarbeitung/Chart'
 */
#endif                                 /* RTW_HEADER_Schloss_Box_final_h_ */

/* [EOF] */
