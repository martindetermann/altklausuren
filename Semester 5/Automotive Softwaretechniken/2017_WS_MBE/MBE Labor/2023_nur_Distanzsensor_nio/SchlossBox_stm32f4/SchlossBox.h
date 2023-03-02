/*
 * File: SchlossBox.h
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

#ifndef RTW_HEADER_SchlossBox_h_
#define RTW_HEADER_SchlossBox_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef SchlossBox_COMMON_INCLUDES_
# define SchlossBox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* SchlossBox_COMMON_INCLUDES_ */

#include "SchlossBox_types.h"

/* Child system includes */
#include "SchlossBox_Debounce.h"
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
  real_T SchliessZustand;              /* '<Root>/Chart' */
  real_T AlarmZustand;                 /* '<Root>/Chart' */
  uint32_T CANReceive_o2;              /* '<Root>/CAN Receive' */
  uint32_T CANReceive1_o2;             /* '<Root>/CAN Receive1' */
  uint16_T CANReceive_o1;              /* '<Root>/CAN Receive' */
  uint16_T CANReceive1_o1;             /* '<Root>/CAN Receive1' */
  uint8_T CANReceive_o3;               /* '<Root>/CAN Receive' */
  uint8_T CANReceive1_o3;              /* '<Root>/CAN Receive1' */
  uint8_T Gain4;                       /* '<S3>/Gain4' */
  uint8_T Gain4_i;                     /* '<S4>/Gain4' */
  boolean_T DigitalInput_o1;           /* '<Root>/Digital Input' */
  boolean_T DigitalInput_o2;           /* '<Root>/Digital Input' */
  boolean_T AlarmLED;                  /* '<Root>/Chart' */
  B_Debounce_SchlossBox_T Debounce1;   /* '<Root>/Debounce1' */
  B_Debounce_SchlossBox_T Debounce;    /* '<Root>/Debounce' */
} B_SchlossBox_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S10>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S11>/Delay Input1' */
  uint8_T is_active_c2_SchlossBox;     /* '<Root>/Chart' */
  uint8_T is_Schliessanlage;           /* '<Root>/Chart' */
  uint8_T is_Alarmanlage;              /* '<Root>/Chart' */
  uint8_T is_ON;                       /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  DW_Debounce_SchlossBox_T Debounce1;  /* '<Root>/Debounce1' */
  DW_Debounce_SchlossBox_T Debounce;   /* '<Root>/Debounce' */
} DW_SchlossBox_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState CANTransmitSchloss_1_Trig_ZCE;/* '<Root>/CAN Transmit Schloss_1' */
  ZCSigState CANTransmitAlarm_1_Trig_ZCE;/* '<Root>/CAN Transmit Alarm_1' */
} PrevZCX_SchlossBox_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0; 1])
   * Referenced by:
   *   '<S3>/Direct Lookup Table (n-D)2'
   *   '<S4>/Direct Lookup Table (n-D)2'
   */
  real_T pooled3[2];
} ConstP_SchlossBox_T;

/* Real-time Model Data Structure */
struct tag_RTM_SchlossBox_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern B_SchlossBox_T SchlossBox_B;

/* Block states (auto storage) */
extern DW_SchlossBox_T SchlossBox_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_SchlossBox_T SchlossBox_PrevZCX;

/* Constant parameters (auto storage) */
extern const ConstP_SchlossBox_T SchlossBox_ConstP;

/* Model entry point functions */
extern void SchlossBox_initialize(void);
extern void SchlossBox_step(void);
extern void SchlossBox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SchlossBox_T *const SchlossBox_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Display4' : Unused code path elimination
 * Block '<S14>/Compare' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S6>/Display4' : Unused code path elimination
 * Block '<S24>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S29>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S32>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S35>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S44>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S48>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S51>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S54>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<Root>' : 'SchlossBox'
 * '<S1>'   : 'SchlossBox/CAN Transmit Alarm_1'
 * '<S2>'   : 'SchlossBox/CAN Transmit Schloss_1'
 * '<S3>'   : 'SchlossBox/CanCoder_Alarm_1'
 * '<S4>'   : 'SchlossBox/CanCoder_Schloss_1'
 * '<S5>'   : 'SchlossBox/CanDecoder_Bremse_2'
 * '<S6>'   : 'SchlossBox/CanDecoder_Cockpit_3'
 * '<S7>'   : 'SchlossBox/Chart'
 * '<S8>'   : 'SchlossBox/Debounce'
 * '<S9>'   : 'SchlossBox/Debounce1'
 * '<S10>'  : 'SchlossBox/CanCoder_Alarm_1/Detect Change4'
 * '<S11>'  : 'SchlossBox/CanCoder_Schloss_1/Detect Change4'
 * '<S12>'  : 'SchlossBox/CanDecoder_Cockpit_3/Bit Shift4'
 * '<S13>'  : 'SchlossBox/CanDecoder_Cockpit_3/Bit Shift5'
 * '<S14>'  : 'SchlossBox/CanDecoder_Cockpit_3/Compare To Constant11'
 * '<S15>'  : 'SchlossBox/CanDecoder_Cockpit_3/Compare To Constant12'
 * '<S16>'  : 'SchlossBox/CanDecoder_Cockpit_3/Bit Shift4/bit_shift'
 * '<S17>'  : 'SchlossBox/CanDecoder_Cockpit_3/Bit Shift5/bit_shift'
 * '<S18>'  : 'SchlossBox/Debounce/Compare To Zero'
 * '<S19>'  : 'SchlossBox/Debounce/Compare To Zero1'
 * '<S20>'  : 'SchlossBox/Debounce/Enabled Subsystem'
 * '<S21>'  : 'SchlossBox/Debounce/Enabled Subsystem1'
 * '<S22>'  : 'SchlossBox/Debounce/Enabled Subsystem4'
 * '<S23>'  : 'SchlossBox/Debounce/Enabled Subsystem5'
 * '<S24>'  : 'SchlossBox/Debounce/Enabled Subsystem/Counter Free-Running'
 * '<S25>'  : 'SchlossBox/Debounce/Enabled Subsystem/Counter Free-Running/Increment Real World'
 * '<S26>'  : 'SchlossBox/Debounce/Enabled Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S27>'  : 'SchlossBox/Debounce/Enabled Subsystem1/Compare To Zero'
 * '<S28>'  : 'SchlossBox/Debounce/Enabled Subsystem1/Counter Free-Running'
 * '<S29>'  : 'SchlossBox/Debounce/Enabled Subsystem1/Counter Free-Running/Increment Real World'
 * '<S30>'  : 'SchlossBox/Debounce/Enabled Subsystem1/Counter Free-Running/Wrap To Zero'
 * '<S31>'  : 'SchlossBox/Debounce/Enabled Subsystem4/Counter Free-Running'
 * '<S32>'  : 'SchlossBox/Debounce/Enabled Subsystem4/Counter Free-Running/Increment Real World'
 * '<S33>'  : 'SchlossBox/Debounce/Enabled Subsystem4/Counter Free-Running/Wrap To Zero'
 * '<S34>'  : 'SchlossBox/Debounce/Enabled Subsystem5/Counter Free-Running'
 * '<S35>'  : 'SchlossBox/Debounce/Enabled Subsystem5/Counter Free-Running/Increment Real World'
 * '<S36>'  : 'SchlossBox/Debounce/Enabled Subsystem5/Counter Free-Running/Wrap To Zero'
 * '<S37>'  : 'SchlossBox/Debounce1/Compare To Zero'
 * '<S38>'  : 'SchlossBox/Debounce1/Compare To Zero1'
 * '<S39>'  : 'SchlossBox/Debounce1/Enabled Subsystem'
 * '<S40>'  : 'SchlossBox/Debounce1/Enabled Subsystem1'
 * '<S41>'  : 'SchlossBox/Debounce1/Enabled Subsystem4'
 * '<S42>'  : 'SchlossBox/Debounce1/Enabled Subsystem5'
 * '<S43>'  : 'SchlossBox/Debounce1/Enabled Subsystem/Counter Free-Running'
 * '<S44>'  : 'SchlossBox/Debounce1/Enabled Subsystem/Counter Free-Running/Increment Real World'
 * '<S45>'  : 'SchlossBox/Debounce1/Enabled Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S46>'  : 'SchlossBox/Debounce1/Enabled Subsystem1/Compare To Zero'
 * '<S47>'  : 'SchlossBox/Debounce1/Enabled Subsystem1/Counter Free-Running'
 * '<S48>'  : 'SchlossBox/Debounce1/Enabled Subsystem1/Counter Free-Running/Increment Real World'
 * '<S49>'  : 'SchlossBox/Debounce1/Enabled Subsystem1/Counter Free-Running/Wrap To Zero'
 * '<S50>'  : 'SchlossBox/Debounce1/Enabled Subsystem4/Counter Free-Running'
 * '<S51>'  : 'SchlossBox/Debounce1/Enabled Subsystem4/Counter Free-Running/Increment Real World'
 * '<S52>'  : 'SchlossBox/Debounce1/Enabled Subsystem4/Counter Free-Running/Wrap To Zero'
 * '<S53>'  : 'SchlossBox/Debounce1/Enabled Subsystem5/Counter Free-Running'
 * '<S54>'  : 'SchlossBox/Debounce1/Enabled Subsystem5/Counter Free-Running/Increment Real World'
 * '<S55>'  : 'SchlossBox/Debounce1/Enabled Subsystem5/Counter Free-Running/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_SchlossBox_h_ */

/* [EOF] */
