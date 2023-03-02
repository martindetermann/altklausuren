/*
 * File: SchlossBox.c
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

#include "SchlossBox.h"
#include "SchlossBox_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SchlossBox_IN_Geschlossen      ((uint8_T)1U)
#define SchlossBox_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define SchlossBox_IN_OFF              ((uint8_T)1U)
#define SchlossBox_IN_OFFEN            ((uint8_T)2U)
#define SchlossBox_IN_ON               ((uint8_T)2U)
#define SchlossBox_IN_TRIGGER_OFF      ((uint8_T)1U)
#define SchlossBox_IN_TRIGGER_ON       ((uint8_T)2U)

/* Block signals (auto storage) */
B_SchlossBox_T SchlossBox_B;

/* Block states (auto storage) */
DW_SchlossBox_T SchlossBox_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SchlossBox_T SchlossBox_PrevZCX;

/* Real-time model */
RT_MODEL_SchlossBox_T SchlossBox_M_;
RT_MODEL_SchlossBox_T *const SchlossBox_M = &SchlossBox_M_;

/* Model step function */
void SchlossBox_step(void)
{
  boolean_T rtb_MultiportSwitch_o;
  boolean_T rtb_MultiportSwitch;
  real_T tmp;

  /* S-Function (stm32f4_digital_input): '<Root>/Digital Input' */
  SchlossBox_B.DigitalInput_o1 = *DigitalInput_C0;
  SchlossBox_B.DigitalInput_o2 = *DigitalInput_C1;

  /* Outputs for Atomic SubSystem: '<Root>/Debounce' */
  rtb_MultiportSwitch_o = SchlossBox_Debounce(SchlossBox_B.DigitalInput_o1,
    &SchlossBox_B.Debounce, &SchlossBox_DW.Debounce, 2);

  /* End of Outputs for SubSystem: '<Root>/Debounce' */

  /* Outputs for Atomic SubSystem: '<Root>/Debounce1' */
  rtb_MultiportSwitch = SchlossBox_Debounce(SchlossBox_B.DigitalInput_o2,
    &SchlossBox_B.Debounce1, &SchlossBox_DW.Debounce1, 2);

  /* End of Outputs for SubSystem: '<Root>/Debounce1' */

  /* S-Function (stm32f4_can): '<Root>/CAN Receive' */

  /* CANReceive: '<Root>/CAN Receive' */
  SchlossBox_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  SchlossBox_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  SchlossBox_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint8 */

  /* S-Function (stm32f4_can): '<Root>/CAN Receive1' */

  /* CANReceive1: '<Root>/CAN Receive1' */
  SchlossBox_B.CANReceive1_o1 = CANReceive1_GetMsg(&CANReceive1_Msg);/* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  SchlossBox_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  SchlossBox_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<S15>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLAB Function: '<S12>/bit_shift'
   *  MATLAB Function: '<S13>/bit_shift'
   *  RelationalOperator: '<S15>/Compare'
   */
  if (SchlossBox_DW.temporalCounter_i1 < 127U) {
    SchlossBox_DW.temporalCounter_i1++;
  }

  if (SchlossBox_DW.is_active_c2_SchlossBox == 0U) {
    SchlossBox_DW.is_active_c2_SchlossBox = 1U;
    SchlossBox_DW.is_Schliessanlage = SchlossBox_IN_Geschlossen;
    SchlossBox_B.SchliessZustand = 1.0;
    SchlossBox_DW.is_Alarmanlage = SchlossBox_IN_OFF;
    SchlossBox_B.AlarmLED = false;
  } else {
    if (SchlossBox_DW.is_Schliessanlage == SchlossBox_IN_Geschlossen) {
      if (rtb_MultiportSwitch_o) {
        SchlossBox_DW.is_Schliessanlage = SchlossBox_IN_OFFEN;
        SchlossBox_B.SchliessZustand = 0.0;
      }
    } else {
      if (rtb_MultiportSwitch_o) {
        SchlossBox_DW.is_Schliessanlage = SchlossBox_IN_Geschlossen;
        SchlossBox_B.SchliessZustand = 1.0;
      }
    }

    if (SchlossBox_DW.is_Alarmanlage == SchlossBox_IN_OFF) {
      if ((SchlossBox_B.SchliessZustand == 1.0) && (SchlossBox_B.CANReceive1_o3 ==
           0)) {
        SchlossBox_DW.is_Alarmanlage = SchlossBox_IN_ON;
        SchlossBox_DW.is_ON = SchlossBox_IN_TRIGGER_OFF;
        SchlossBox_B.AlarmZustand = 0.0;
        SchlossBox_DW.temporalCounter_i1 = 0U;
        SchlossBox_B.AlarmLED = !SchlossBox_B.AlarmLED;
      }
    } else if (SchlossBox_DW.is_ON == SchlossBox_IN_TRIGGER_OFF) {
      SchlossBox_B.AlarmZustand = 0.0;
      if (rtb_MultiportSwitch) {
        SchlossBox_DW.is_ON = SchlossBox_IN_TRIGGER_ON;
        SchlossBox_B.AlarmZustand = 1.0;
      } else if (SchlossBox_B.SchliessZustand == 0.0) {
        SchlossBox_DW.is_ON = SchlossBox_IN_NO_ACTIVE_CHILD;
        SchlossBox_DW.is_Alarmanlage = SchlossBox_IN_OFF;
        SchlossBox_B.AlarmLED = false;
      } else {
        if (SchlossBox_DW.temporalCounter_i1 >= 100U) {
          SchlossBox_DW.temporalCounter_i1 = 0U;
          SchlossBox_B.AlarmLED = !SchlossBox_B.AlarmLED;
        }
      }
    } else {
      SchlossBox_B.AlarmZustand = 1.0;

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift5' */
      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
      if ((SchlossBox_B.SchliessZustand == 0.0) && ((int32_T)((uint32_T)(uint8_T)
            (SchlossBox_B.CANReceive_o3 << 7) >> 7) == 1)) {
        SchlossBox_DW.is_ON = SchlossBox_IN_TRIGGER_OFF;
        SchlossBox_B.AlarmZustand = 0.0;
        SchlossBox_DW.temporalCounter_i1 = 0U;
        SchlossBox_B.AlarmLED = !SchlossBox_B.AlarmLED;
      }

      /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */
      /* End of Outputs for SubSystem: '<S6>/Bit Shift5' */
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* LookupNDDirect: '<S3>/Direct Lookup Table (n-D)2'
   *
   * About '<S3>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  if (SchlossBox_B.AlarmZustand > 1.0) {
    tmp = 1.0;
  } else if (SchlossBox_B.AlarmZustand < 0.0) {
    tmp = 0.0;
  } else {
    tmp = SchlossBox_B.AlarmZustand;
  }

  tmp = floor(SchlossBox_ConstP.pooled3[(int32_T)tmp]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Gain: '<S3>/Gain4' incorporates:
   *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)2'
   *
   * About '<S3>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  SchlossBox_B.Gain4 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
    -tmp : (int32_T)(uint8_T)tmp);

  /* RelationalOperator: '<S10>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_MultiportSwitch_o = (SchlossBox_B.AlarmZustand !=
    SchlossBox_DW.DelayInput1_DSTATE);

  /* Outputs for Triggered SubSystem: '<Root>/CAN Transmit Alarm_1' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  if (rtb_MultiportSwitch_o && (SchlossBox_PrevZCX.CANTransmitAlarm_1_Trig_ZCE
       != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S1>/CAN Transmit' */

    /* CANTransmit: '<S1>/CAN Transmit' */
    CANTransmitTxMsg.Data[0] = SchlossBox_B.Gain4;/* D0: uint8 */
    CANx_Transmit(CAN1, &CANTransmitTxMsg, 0, 0.005);/* Transmit message */
  }

  SchlossBox_PrevZCX.CANTransmitAlarm_1_Trig_ZCE = rtb_MultiportSwitch_o;

  /* End of Outputs for SubSystem: '<Root>/CAN Transmit Alarm_1' */

  /* LookupNDDirect: '<S4>/Direct Lookup Table (n-D)2'
   *
   * About '<S4>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  if (SchlossBox_B.SchliessZustand > 1.0) {
    tmp = 1.0;
  } else if (SchlossBox_B.SchliessZustand < 0.0) {
    tmp = 0.0;
  } else {
    tmp = SchlossBox_B.SchliessZustand;
  }

  tmp = floor(SchlossBox_ConstP.pooled3[(int32_T)tmp]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Gain: '<S4>/Gain4' incorporates:
   *  LookupNDDirect: '<S4>/Direct Lookup Table (n-D)2'
   *
   * About '<S4>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  SchlossBox_B.Gain4_i = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* RelationalOperator: '<S11>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_MultiportSwitch_o = (SchlossBox_B.SchliessZustand !=
    SchlossBox_DW.DelayInput1_DSTATE_e);

  /* Outputs for Triggered SubSystem: '<Root>/CAN Transmit Schloss_1' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (rtb_MultiportSwitch_o && (SchlossBox_PrevZCX.CANTransmitSchloss_1_Trig_ZCE
       != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S2>/CAN Transmit' */

    /* CANTransmit_b: '<S2>/CAN Transmit' */
    CANTransmit_bTxMsg.Data[0] = SchlossBox_B.Gain4_i;/* D0: uint8 */
    CANx_Transmit(CAN1, &CANTransmit_bTxMsg, 0, 0.005);/* Transmit message */
  }

  SchlossBox_PrevZCX.CANTransmitSchloss_1_Trig_ZCE = rtb_MultiportSwitch_o;

  /* End of Outputs for SubSystem: '<Root>/CAN Transmit Schloss_1' */

  /* S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* DigitalOutput */
  {
    *DigitalOutput_C2 = SchlossBox_B.AlarmLED;
    *DigitalOutput_C3 = (boolean_T) SchlossBox_B.SchliessZustand;
  }

  /* Update for UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SchlossBox_DW.DelayInput1_DSTATE = SchlossBox_B.AlarmZustand;

  /* Update for UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SchlossBox_DW.DelayInput1_DSTATE_e = SchlossBox_B.SchliessZustand;
}

/* Model initialize function */
void SchlossBox_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(SchlossBox_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SchlossBox_B), 0,
                sizeof(B_SchlossBox_T));

  /* states (dwork) */
  (void) memset((void *)&SchlossBox_DW, 0,
                sizeof(DW_SchlossBox_T));
  SchlossBox_PrevZCX.CANTransmitAlarm_1_Trig_ZCE = POS_ZCSIG;
  SchlossBox_PrevZCX.CANTransmitSchloss_1_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  SchlossBox_DW.is_Alarmanlage = SchlossBox_IN_NO_ACTIVE_CHILD;
  SchlossBox_DW.is_ON = SchlossBox_IN_NO_ACTIVE_CHILD;
  SchlossBox_DW.temporalCounter_i1 = 0U;
  SchlossBox_DW.is_Schliessanlage = SchlossBox_IN_NO_ACTIVE_CHILD;
  SchlossBox_DW.is_active_c2_SchlossBox = 0U;

  /* Enable for S-Function (stm32f4_usart): '<Root>/UART Setup' */
  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();

  /* Enable for S-Function (stm32f4_digital_input): '<Root>/Digital Input' */
  /* Level2 S-Function Block: '<Root>/Digital Input' (stm32f4_digital_input) */
  enable_DigitalInput();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive' */
  /* Level2 S-Function Block: '<Root>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive1' */
  /* Level2 S-Function Block: '<Root>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for Triggered SubSystem: '<Root>/CAN Transmit Alarm_1' */

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Transmit' */
  /* Level2 S-Function Block: '<S1>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit();

  /* End of Enable for SubSystem: '<Root>/CAN Transmit Alarm_1' */

  /* Enable for Triggered SubSystem: '<Root>/CAN Transmit Schloss_1' */

  /* Enable for S-Function (stm32f4_can): '<S2>/CAN Transmit' */
  /* Level2 S-Function Block: '<S2>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit_b();

  /* End of Enable for SubSystem: '<Root>/CAN Transmit Schloss_1' */

  /* Enable for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */
  /* Level2 S-Function Block: '<Root>/Digital Output' (stm32f4_digital_output) */
  enable_DigitalOutput();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Setup' */
  /* Level2 S-Function Block: '<Root>/CAN Setup' (stm32f4_can) */
  enable_CANSetup();
}

/* Model terminate function */
void SchlossBox_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_input): '<Root>/Digital Input' */

  /* terminate_DigitalInput(); */

  /* Terminate for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* terminate_DigitalOutput(); */
}

/* [EOF] */
