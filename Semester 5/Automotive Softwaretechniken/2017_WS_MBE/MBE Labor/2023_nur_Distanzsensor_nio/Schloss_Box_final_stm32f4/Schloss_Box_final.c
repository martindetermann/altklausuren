/*
 * File: Schloss_Box_final.c
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

#include "Schloss_Box_final.h"
#include "Schloss_Box_final_private.h"

/* Named constants for Chart: '<S4>/Chart' */
#define Schloss_Box__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Schloss_Box_fina_IN_Geschlossen ((uint8_T)1U)
#define Schloss_Box_fina_IN_TRIGGER_OFF ((uint8_T)1U)
#define Schloss_Box_final_IN_OFF       ((uint8_T)1U)
#define Schloss_Box_final_IN_OFFEN     ((uint8_T)2U)
#define Schloss_Box_final_IN_ON        ((uint8_T)2U)
#define Schloss_Box_final_IN_TRIGGER_ON ((uint8_T)2U)

/* Block signals (auto storage) */
B_Schloss_Box_final_T Schloss_Box_final_B;

/* Block states (auto storage) */
DW_Schloss_Box_final_T Schloss_Box_final_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Schloss_Box_final_T Schloss_Box_final_PrevZCX;

/* Real-time model */
RT_MODEL_Schloss_Box_final_T Schloss_Box_final_M_;
RT_MODEL_Schloss_Box_final_T *const Schloss_Box_final_M = &Schloss_Box_final_M_;

/* Model step function */
void Schloss_Box_final_step(void)
{
  boolean_T rtb_MultiportSwitch_o;
  boolean_T rtb_MultiportSwitch;
  real_T tmp;

  /* S-Function (stm32f4_digital_input): '<S1>/Digital Input' */
  Schloss_Box_final_B.DigitalInput_o1 = *InputDigitalInput_C0;
  Schloss_Box_final_B.DigitalInput_o2 = *InputDigitalInput_C1;

  /* Outputs for Atomic SubSystem: '<S1>/Debounce' */
  rtb_MultiportSwitch_o = Schloss_Box_final_Debounce
    (Schloss_Box_final_B.DigitalInput_o1, &Schloss_Box_final_B.Debounce,
     &Schloss_Box_final_DW.Debounce, 2);

  /* End of Outputs for SubSystem: '<S1>/Debounce' */

  /* Outputs for Atomic SubSystem: '<S1>/Debounce1' */
  rtb_MultiportSwitch = Schloss_Box_final_Debounce
    (Schloss_Box_final_B.DigitalInput_o2, &Schloss_Box_final_B.Debounce1,
     &Schloss_Box_final_DW.Debounce1, 2);

  /* End of Outputs for SubSystem: '<S1>/Debounce1' */

  /* S-Function (stm32f4_can): '<S1>/CAN Receive' */

  /* CANReceive: '<S1>/CAN Receive' */
  Schloss_Box_final_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  Schloss_Box_final_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  Schloss_Box_final_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint8 */

  /* S-Function (stm32f4_can): '<S1>/CAN Receive1' */

  /* CANReceive1: '<S1>/CAN Receive1' */
  Schloss_Box_final_B.CANReceive1_o1 = CANReceive1_GetMsg(&CANReceive1_Msg);/* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  Schloss_Box_final_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  Schloss_Box_final_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Chart: '<S4>/Chart' incorporates:
   *  Constant: '<S12>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  MATLAB Function: '<S10>/bit_shift'
   *  MATLAB Function: '<S9>/bit_shift'
   *  RelationalOperator: '<S12>/Compare'
   */
  if (Schloss_Box_final_DW.temporalCounter_i1 < 127U) {
    Schloss_Box_final_DW.temporalCounter_i1++;
  }

  if (Schloss_Box_final_DW.is_active_c2_Schloss_Box_final == 0U) {
    Schloss_Box_final_DW.is_active_c2_Schloss_Box_final = 1U;
    Schloss_Box_final_DW.is_Schliessanlage = Schloss_Box_fina_IN_Geschlossen;
    Schloss_Box_final_B.SchliessZustand = 1.0;
    Schloss_Box_final_DW.is_Alarmanlage = Schloss_Box_final_IN_OFF;
    Schloss_Box_final_B.AlarmLED = false;
  } else {
    if (Schloss_Box_final_DW.is_Schliessanlage ==
        Schloss_Box_fina_IN_Geschlossen) {
      if (rtb_MultiportSwitch_o) {
        Schloss_Box_final_DW.is_Schliessanlage = Schloss_Box_final_IN_OFFEN;
        Schloss_Box_final_B.SchliessZustand = 0.0;
      }
    } else {
      if (rtb_MultiportSwitch_o) {
        Schloss_Box_final_DW.is_Schliessanlage = Schloss_Box_fina_IN_Geschlossen;
        Schloss_Box_final_B.SchliessZustand = 1.0;
      }
    }

    if (Schloss_Box_final_DW.is_Alarmanlage == Schloss_Box_final_IN_OFF) {
      if ((Schloss_Box_final_B.SchliessZustand == 1.0) &&
          (Schloss_Box_final_B.CANReceive1_o3 == 0)) {
        Schloss_Box_final_DW.is_Alarmanlage = Schloss_Box_final_IN_ON;
        Schloss_Box_final_DW.is_ON = Schloss_Box_fina_IN_TRIGGER_OFF;
        Schloss_Box_final_B.AlarmZustand = 0.0;
        Schloss_Box_final_DW.temporalCounter_i1 = 0U;
        Schloss_Box_final_B.AlarmLED = !Schloss_Box_final_B.AlarmLED;
      }
    } else if (Schloss_Box_final_DW.is_ON == Schloss_Box_fina_IN_TRIGGER_OFF) {
      Schloss_Box_final_B.AlarmZustand = 0.0;
      if (rtb_MultiportSwitch) {
        Schloss_Box_final_DW.is_ON = Schloss_Box_final_IN_TRIGGER_ON;
        Schloss_Box_final_B.AlarmZustand = 1.0;
      } else if (Schloss_Box_final_B.SchliessZustand == 0.0) {
        Schloss_Box_final_DW.is_ON = Schloss_Box__IN_NO_ACTIVE_CHILD;
        Schloss_Box_final_DW.is_Alarmanlage = Schloss_Box_final_IN_OFF;
        Schloss_Box_final_B.AlarmLED = false;
      } else {
        if (Schloss_Box_final_DW.temporalCounter_i1 >= 100U) {
          Schloss_Box_final_DW.temporalCounter_i1 = 0U;
          Schloss_Box_final_B.AlarmLED = !Schloss_Box_final_B.AlarmLED;
        }
      }
    } else {
      Schloss_Box_final_B.AlarmZustand = 1.0;

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift5' */
      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
      if ((Schloss_Box_final_B.SchliessZustand == 0.0) && ((int32_T)((uint32_T)
            (uint8_T)(Schloss_Box_final_B.CANReceive_o3 << 7) >> 7) == 1)) {
        Schloss_Box_final_DW.is_ON = Schloss_Box_fina_IN_TRIGGER_OFF;
        Schloss_Box_final_B.AlarmZustand = 0.0;
        Schloss_Box_final_DW.temporalCounter_i1 = 0U;
        Schloss_Box_final_B.AlarmLED = !Schloss_Box_final_B.AlarmLED;
      }

      /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */
      /* End of Outputs for SubSystem: '<S6>/Bit Shift5' */
    }
  }

  /* End of Chart: '<S4>/Chart' */

  /* LookupNDDirect: '<S55>/Direct Lookup Table (n-D)2'
   *
   * About '<S55>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  if (Schloss_Box_final_B.AlarmZustand > 1.0) {
    tmp = 1.0;
  } else if (Schloss_Box_final_B.AlarmZustand < 0.0) {
    tmp = 0.0;
  } else {
    tmp = Schloss_Box_final_B.AlarmZustand;
  }

  tmp = floor(Schloss_Box_final_ConstP.pooled3[(int32_T)tmp]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Gain: '<S55>/Gain4' incorporates:
   *  LookupNDDirect: '<S55>/Direct Lookup Table (n-D)2'
   *
   * About '<S55>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  Schloss_Box_final_B.Gain4 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* RelationalOperator: '<S57>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S57>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_MultiportSwitch_o = (Schloss_Box_final_B.AlarmZustand !=
    Schloss_Box_final_DW.DelayInput1_DSTATE);

  /* Outputs for Triggered SubSystem: '<S2>/CAN Transmit Alarm_1' incorporates:
   *  TriggerPort: '<S53>/Trigger'
   */
  if (rtb_MultiportSwitch_o &&
      (Schloss_Box_final_PrevZCX.CANTransmitAlarm_1_Trig_ZCE != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S53>/CAN Transmit' */

    /* CANTransmit: '<S53>/CAN Transmit' */
    CANTransmitTxMsg.Data[0] = Schloss_Box_final_B.Gain4;/* D0: uint8 */
    CANx_Transmit(CAN1, &CANTransmitTxMsg, 0, 0.005);/* Transmit message */
  }

  Schloss_Box_final_PrevZCX.CANTransmitAlarm_1_Trig_ZCE = rtb_MultiportSwitch_o;

  /* End of Outputs for SubSystem: '<S2>/CAN Transmit Alarm_1' */

  /* LookupNDDirect: '<S56>/Direct Lookup Table (n-D)2'
   *
   * About '<S56>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  if (Schloss_Box_final_B.SchliessZustand > 1.0) {
    tmp = 1.0;
  } else if (Schloss_Box_final_B.SchliessZustand < 0.0) {
    tmp = 0.0;
  } else {
    tmp = Schloss_Box_final_B.SchliessZustand;
  }

  tmp = floor(Schloss_Box_final_ConstP.pooled3[(int32_T)tmp]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Gain: '<S56>/Gain4' incorporates:
   *  LookupNDDirect: '<S56>/Direct Lookup Table (n-D)2'
   *
   * About '<S56>/Direct Lookup Table (n-D)2':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  Schloss_Box_final_B.Gain4_m = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* RelationalOperator: '<S58>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_MultiportSwitch_o = (Schloss_Box_final_B.SchliessZustand !=
    Schloss_Box_final_DW.DelayInput1_DSTATE_o);

  /* Outputs for Triggered SubSystem: '<S2>/CAN Transmit Schloss_1' incorporates:
   *  TriggerPort: '<S54>/Trigger'
   */
  if (rtb_MultiportSwitch_o &&
      (Schloss_Box_final_PrevZCX.CANTransmitSchloss_1_Trig_ZCE != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S54>/CAN Transmit' */

    /* CANTransmit_m: '<S54>/CAN Transmit' */
    CANTransmit_mTxMsg.Data[0] = Schloss_Box_final_B.Gain4_m;/* D0: uint8 */
    CANx_Transmit(CAN1, &CANTransmit_mTxMsg, 0, 0.005);/* Transmit message */
  }

  Schloss_Box_final_PrevZCX.CANTransmitSchloss_1_Trig_ZCE =
    rtb_MultiportSwitch_o;

  /* End of Outputs for SubSystem: '<S2>/CAN Transmit Schloss_1' */

  /* S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* OutputDigitalOutput */
  {
    *OutputDigitalOutput_C2 = Schloss_Box_final_B.AlarmLED;
    *OutputDigitalOutput_C3 = (boolean_T) Schloss_Box_final_B.SchliessZustand;
  }

  /* Update for UnitDelay: '<S57>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Schloss_Box_final_DW.DelayInput1_DSTATE = Schloss_Box_final_B.AlarmZustand;

  /* Update for UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Schloss_Box_final_DW.DelayInput1_DSTATE_o =
    Schloss_Box_final_B.SchliessZustand;
}

/* Model initialize function */
void Schloss_Box_final_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Schloss_Box_final_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Schloss_Box_final_B), 0,
                sizeof(B_Schloss_Box_final_T));

  /* states (dwork) */
  (void) memset((void *)&Schloss_Box_final_DW, 0,
                sizeof(DW_Schloss_Box_final_T));
  Schloss_Box_final_PrevZCX.CANTransmitAlarm_1_Trig_ZCE = POS_ZCSIG;
  Schloss_Box_final_PrevZCX.CANTransmitSchloss_1_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<S4>/Chart' */
  Schloss_Box_final_DW.is_Alarmanlage = Schloss_Box__IN_NO_ACTIVE_CHILD;
  Schloss_Box_final_DW.is_ON = Schloss_Box__IN_NO_ACTIVE_CHILD;
  Schloss_Box_final_DW.temporalCounter_i1 = 0U;
  Schloss_Box_final_DW.is_Schliessanlage = Schloss_Box__IN_NO_ACTIVE_CHILD;
  Schloss_Box_final_DW.is_active_c2_Schloss_Box_final = 0U;

  /* Enable for S-Function (stm32f4_digital_input): '<S1>/Digital Input' */
  /* Level2 S-Function Block: '<S1>/Digital Input' (stm32f4_digital_input) */
  enable_InputDigitalInput();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive' */
  /* Level2 S-Function Block: '<S1>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive1' */
  /* Level2 S-Function Block: '<S1>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for Triggered SubSystem: '<S2>/CAN Transmit Alarm_1' */

  /* Enable for S-Function (stm32f4_can): '<S53>/CAN Transmit' */
  /* Level2 S-Function Block: '<S53>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit();

  /* End of Enable for SubSystem: '<S2>/CAN Transmit Alarm_1' */

  /* Enable for Triggered SubSystem: '<S2>/CAN Transmit Schloss_1' */

  /* Enable for S-Function (stm32f4_can): '<S54>/CAN Transmit' */
  /* Level2 S-Function Block: '<S54>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit_m();

  /* End of Enable for SubSystem: '<S2>/CAN Transmit Schloss_1' */

  /* Enable for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */
  /* Level2 S-Function Block: '<S2>/Digital Output' (stm32f4_digital_output) */
  enable_OutputDigitalOutput();

  /* Enable for S-Function (stm32f4_usart): '<S3>/UART Setup' */
  /* Level2 S-Function Block: '<S3>/UART Setup' (stm32f4_usart) */
  enable_SetupUARTSetup();

  /* Enable for S-Function (stm32f4_can): '<S3>/CAN Setup' */
  /* Level2 S-Function Block: '<S3>/CAN Setup' (stm32f4_can) */
  enable_CANSetup();
}

/* Model terminate function */
void Schloss_Box_final_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_input): '<S1>/Digital Input' */

  /* terminate_InputDigitalInput(); */

  /* Terminate for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* terminate_OutputDigitalOutput(); */
}

/* [EOF] */
