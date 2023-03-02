/*
 * File: BlinkerCAN.c
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

#include "BlinkerCAN.h"
#include "BlinkerCAN_private.h"

/* Named constants for Chart: '<Root>/Steuerung_Blinker' */
#define BlinkerCAN_IN_AlarmBlinken     ((uint8_T)1U)
#define BlinkerCAN_IN_BlinkerL         ((uint8_T)2U)
#define BlinkerCAN_IN_BlinkerR         ((uint8_T)3U)
#define BlinkerCAN_IN_BlinkerTipL      ((uint8_T)4U)
#define BlinkerCAN_IN_BlinkerTipR      ((uint8_T)5U)
#define BlinkerCAN_IN_Dummy            ((uint8_T)6U)
#define BlinkerCAN_IN_EnableBlinkerTipL ((uint8_T)7U)
#define BlinkerCAN_IN_EnableBlinkerTipR ((uint8_T)8U)
#define BlinkerCAN_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define BlinkerCAN_IN_OeffnenBlinken   ((uint8_T)9U)
#define BlinkerCAN_IN_WarnBlinker      ((uint8_T)12U)
#define BlinkerCA_IN_SchliessenBlinken1 ((uint8_T)10U)
#define BlinkerCA_IN_SchliessenBlinken2 ((uint8_T)11U)

/* Named constants for Chart: '<Root>/Steuerung_Licht' */
#define BlinkerCAN_IN_Abblend_Licht    ((uint8_T)1U)
#define BlinkerCAN_IN_Automatik_Betrieb ((uint8_T)2U)
#define BlinkerCAN_IN_Default          ((uint8_T)3U)
#define BlinkerCAN_IN_Dunkel           ((uint8_T)4U)
#define BlinkerCAN_IN_Fern_Licht       ((uint8_T)5U)
#define BlinkerCAN_IN_Groesser         ((uint8_T)1U)
#define BlinkerCAN_IN_Hell             ((uint8_T)6U)
#define BlinkerCAN_IN_Kleiner          ((uint8_T)2U)
#define BlinkerCAN_IN_Tagfahr_Licht    ((uint8_T)7U)

/* Block signals (auto storage) */
B_BlinkerCAN_T BlinkerCAN_B;

/* Block states (auto storage) */
DW_BlinkerCAN_T BlinkerCAN_DW;

/* Real-time model */
RT_MODEL_BlinkerCAN_T BlinkerCAN_M_;
RT_MODEL_BlinkerCAN_T *const BlinkerCAN_M = &BlinkerCAN_M_;

/* Forward declaration for local functions */
static void BlinkerCAN_WarnBlinker(void);

/*
 * Output and update for atomic system:
 *    '<S1>/Bit Shift4'
 *    '<S4>/Bit Shift4'
 */
uint8_T BlinkerCAN_BitShift4(uint8_T rtu_u)
{
  /* MATLAB Function: '<S8>/bit_shift' */
  return (uint8_T)(rtu_u << 7);
}

/*
 * Output and update for atomic system:
 *    '<S1>/Bit Shift5'
 *    '<S20>/Bit Shift6'
 *    '<S4>/Bit Shift5'
 */
uint8_T BlinkerCAN_BitShift5(uint8_T rtu_u)
{
  /* MATLAB Function: '<S9>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S2>/Bit Shift4'
 *    '<S20>/Bit Shift'
 */
uint8_T BlinkerCAN_BitShift4_n(uint8_T rtu_u)
{
  /* MATLAB Function: '<S14>/bit_shift' */
  return (uint8_T)(rtu_u << 5);
}

/*
 * Output and update for atomic system:
 *    '<S2>/Bit Shift5'
 *    '<S20>/Bit Shift1'
 */
uint8_T BlinkerCAN_BitShift5_c(uint8_T rtu_u)
{
  /* MATLAB Function: '<S15>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S20>/Bit Shift3'
 *    '<S20>/Bit Shift5'
 */
uint8_T BlinkerCAN_BitShift3(uint8_T rtu_u)
{
  /* MATLAB Function: '<S24>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 6);
}

/* Function for Chart: '<Root>/Steuerung_Blinker' */
static void BlinkerCAN_WarnBlinker(void)
{
  if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
    BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
    BlinkerCAN_DW.temporalCounter_i1 = 0U;
    BlinkerCAN_B.BLL_LED = false;
    BlinkerCAN_B.BLR_LED = false;
    BlinkerCAN_DW.CountL = 1.0;
    BlinkerCAN_DW.CountR = 1.0;
    BlinkerCAN_DW.SchliessCount = 0.0;
  }
}

/* Model step function */
void BlinkerCAN_step(void)
{
  uint8_T rtb_y_ke;
  uint8_T rtb_y_e;
  uint16_T rtb_y_b;
  boolean_T Compare;
  boolean_T Compare_m;
  boolean_T Compare_f;
  boolean_T Compare_d;
  boolean_T Compare_a;
  boolean_T Compare_b;
  boolean_T FixPtRelationalOperator;

  /* S-Function (stm32f4_can): '<Root>/CAN Receive' */

  /* CANReceive: '<Root>/CAN Receive' */
  BlinkerCAN_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  BlinkerCAN_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  BlinkerCAN_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift3' */

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift2' */

  /* MATLAB Function: '<S23>/bit_shift' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift3((uint8_T)(BlinkerCAN_B.CANReceive_o3
    << 3));

  /* End of Outputs for SubSystem: '<S20>/Bit Shift2' */

  /* End of Outputs for SubSystem: '<S20>/Bit Shift3' */

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  Compare = (rtb_y_ke == 1);

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  Compare_m = (rtb_y_ke == 2);

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift5' */

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift4' */

  /* MATLAB Function: '<S25>/bit_shift' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift3((uint8_T)(BlinkerCAN_B.CANReceive_o3
    << 1));

  /* End of Outputs for SubSystem: '<S20>/Bit Shift4' */

  /* End of Outputs for SubSystem: '<S20>/Bit Shift5' */

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  Compare_f = (rtb_y_ke == 1);

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   */
  Compare_d = (rtb_y_ke == 2);

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift6' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift5(BlinkerCAN_B.CANReceive_o3);

  /* End of Outputs for SubSystem: '<S20>/Bit Shift6' */

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   */
  Compare_a = (rtb_y_ke == 1);

  /* S-Function (stm32f4_can): '<Root>/CAN Receive1' */

  /* CANReceive1: '<Root>/CAN Receive1' */
  BlinkerCAN_B.CANReceive1_o1 = CANReceive1_GetMsg(&CANReceive1_Msg);/* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  BlinkerCAN_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  BlinkerCAN_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S4>/Bit Shift4' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift4(BlinkerCAN_B.CANReceive1_o3);

  /* End of Outputs for SubSystem: '<S4>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S4>/Bit Shift5' */
  rtb_y_e = (uint8_T) BlinkerCAN_BitShift5(rtb_y_ke);

  /* End of Outputs for SubSystem: '<S4>/Bit Shift5' */

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   */
  BlinkerCAN_B.Compare_c = (rtb_y_e == 1);

  /* S-Function (stm32f4_can): '<Root>/CAN Receive2' */

  /* CANReceive2: '<Root>/CAN Receive2' */
  BlinkerCAN_B.CANReceive2_o1 = CANReceive2_GetMsg(&CANReceive2_Msg);/* Message and Pending count */
  CANReceive2_data = (CANReceive2_DATA_STRUCT*)&(CANReceive2_Msg.Data[0]);
  BlinkerCAN_B.CANReceive2_o2 = CANReceive2_Msg.StdId;/* Standard ID */
  BlinkerCAN_B.CANReceive2_o3 = CANReceive2_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S1>/Bit Shift4' */
  rtb_y_e = (uint8_T) BlinkerCAN_BitShift4(BlinkerCAN_B.CANReceive2_o3);

  /* End of Outputs for SubSystem: '<S1>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S1>/Bit Shift5' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift5(rtb_y_e);

  /* End of Outputs for SubSystem: '<S1>/Bit Shift5' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  Compare_b = (rtb_y_ke == 1);

  /* RelationalOperator: '<S52>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FixPtRelationalOperator = (BlinkerCAN_B.Compare_c !=
    BlinkerCAN_DW.DelayInput1_DSTATE);

  /* Chart: '<Root>/Steuerung_Blinker' */
  if (BlinkerCAN_DW.temporalCounter_i1 < 127U) {
    BlinkerCAN_DW.temporalCounter_i1++;
  }

  if (BlinkerCAN_DW.is_active_c3_BlinkerCAN == 0U) {
    BlinkerCAN_DW.is_active_c3_BlinkerCAN = 1U;
    BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
    BlinkerCAN_DW.temporalCounter_i1 = 0U;
    BlinkerCAN_B.BLL_LED = false;
    BlinkerCAN_B.BLR_LED = false;
    BlinkerCAN_DW.CountL = 1.0;
    BlinkerCAN_DW.CountR = 1.0;
    BlinkerCAN_DW.SchliessCount = 0.0;
  } else {
    switch (BlinkerCAN_DW.is_c3_BlinkerCAN) {
     case BlinkerCAN_IN_AlarmBlinken:
      if (!Compare_b) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      } else {
        if (BlinkerCAN_DW.temporalCounter_i1 >= 100U) {
          BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_AlarmBlinken;
          BlinkerCAN_DW.temporalCounter_i1 = 0U;
          BlinkerCAN_B.BLL_LED = !BlinkerCAN_B.BLL_LED;
          BlinkerCAN_B.BLR_LED = !BlinkerCAN_B.BLR_LED;
        }
      }
      break;

     case BlinkerCAN_IN_BlinkerL:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      }
      break;

     case BlinkerCAN_IN_BlinkerR:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      }
      break;

     case BlinkerCAN_IN_BlinkerTipL:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.CountL++;
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_EnableBlinkerTipL;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
      }
      break;

     case BlinkerCAN_IN_BlinkerTipR:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.CountR++;
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_EnableBlinkerTipR;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLR_LED = false;
      }
      break;

     case BlinkerCAN_IN_Dummy:
      if (Compare_a && (BlinkerCAN_DW.temporalCounter_i1 >= 50U)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_WarnBlinker;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = true;
        BlinkerCAN_B.BLR_LED = true;
      } else if (Compare_m && (BlinkerCAN_DW.temporalCounter_i1 >= 50U)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_BlinkerR;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLR_LED = true;
      } else if (Compare_b) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_AlarmBlinken;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = !BlinkerCAN_B.BLL_LED;
        BlinkerCAN_B.BLR_LED = !BlinkerCAN_B.BLR_LED;
      } else if (BlinkerCAN_B.Compare_c && FixPtRelationalOperator) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCA_IN_SchliessenBlinken1;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = true;
        BlinkerCAN_B.BLR_LED = true;
      } else if (Compare_d && (BlinkerCAN_DW.temporalCounter_i1 >= 50U)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_BlinkerL;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = true;
      } else if (Compare_f && (!Compare_a)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_EnableBlinkerTipL;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
      } else if (Compare && (!Compare_a)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_EnableBlinkerTipR;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLR_LED = false;
      } else {
        if ((!BlinkerCAN_B.Compare_c) && FixPtRelationalOperator) {
          BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_OeffnenBlinken;
          BlinkerCAN_DW.temporalCounter_i1 = 0U;
          BlinkerCAN_B.BLL_LED = true;
          BlinkerCAN_B.BLR_LED = true;
        }
      }
      break;

     case BlinkerCAN_IN_EnableBlinkerTipL:
      if (Compare_a || (BlinkerCAN_DW.CountL > 3.0) || Compare_m || Compare) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      } else {
        if ((BlinkerCAN_DW.CountL <= 3.0) && (BlinkerCAN_DW.temporalCounter_i1 >=
             50U)) {
          BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_BlinkerTipL;
          BlinkerCAN_DW.temporalCounter_i1 = 0U;
          BlinkerCAN_B.BLL_LED = true;
        }
      }
      break;

     case BlinkerCAN_IN_EnableBlinkerTipR:
      if (Compare_a || (BlinkerCAN_DW.CountR > 3.0) || Compare_d || Compare_f) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      } else {
        if ((BlinkerCAN_DW.CountR <= 3.0) && (BlinkerCAN_DW.temporalCounter_i1 >=
             50U)) {
          BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_BlinkerTipR;
          BlinkerCAN_DW.temporalCounter_i1 = 0U;
          BlinkerCAN_B.BLR_LED = true;
        }
      }
      break;

     case BlinkerCAN_IN_OeffnenBlinken:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      }
      break;

     case BlinkerCA_IN_SchliessenBlinken1:
      if ((BlinkerCAN_DW.SchliessCount == 1.0) &&
          (BlinkerCAN_DW.temporalCounter_i1 >= 50U)) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_Dummy;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = false;
        BlinkerCAN_B.BLR_LED = false;
        BlinkerCAN_DW.CountL = 1.0;
        BlinkerCAN_DW.CountR = 1.0;
        BlinkerCAN_DW.SchliessCount = 0.0;
      } else {
        if ((BlinkerCAN_DW.SchliessCount < 1.0) &&
            (BlinkerCAN_DW.temporalCounter_i1 >= 50U)) {
          BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCA_IN_SchliessenBlinken2;
          BlinkerCAN_DW.temporalCounter_i1 = 0U;
          BlinkerCAN_B.BLL_LED = false;
          BlinkerCAN_B.BLR_LED = false;
          BlinkerCAN_DW.SchliessCount++;
        }
      }
      break;

     case BlinkerCA_IN_SchliessenBlinken2:
      if (BlinkerCAN_DW.temporalCounter_i1 >= 50U) {
        BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCA_IN_SchliessenBlinken1;
        BlinkerCAN_DW.temporalCounter_i1 = 0U;
        BlinkerCAN_B.BLL_LED = true;
        BlinkerCAN_B.BLR_LED = true;
      }
      break;

     default:
      BlinkerCAN_WarnBlinker();
      break;
    }
  }

  /* End of Chart: '<Root>/Steuerung_Blinker' */

  /* S-Function (stm32f4_can): '<Root>/CAN Receive3' */

  /* CANReceive3: '<Root>/CAN Receive3' */
  BlinkerCAN_B.CANReceive3_o1 = CANReceive3_GetMsg(&CANReceive3_Msg);/* Message and Pending count */
  CANReceive3_data = (CANReceive3_DATA_STRUCT*)&(CANReceive3_Msg.Data[0]);
  BlinkerCAN_B.CANReceive3_o2 = CANReceive3_Msg.StdId;/* Standard ID */
  BlinkerCAN_B.CANReceive3_o3 = CANReceive3_data->d0;/* Data0: uint16 */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift4' */
  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Constant: '<S60>/Constant'
   *  MATLAB Function: '<S57>/bit_shift'
   *  MATLAB Function: '<S58>/bit_shift'
   */
  Compare = ((int32_T)((uint32_T)(uint16_T)(BlinkerCAN_B.CANReceive3_o3 << 15) >>
                       15) == 1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S5>/Bit Shift5' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift1' */
  /* MATLAB Function: '<S56>/bit_shift' incorporates:
   *  MATLAB Function: '<S55>/bit_shift'
   */
  rtb_y_b = (uint16_T)((uint32_T)(uint16_T)(BlinkerCAN_B.CANReceive3_o3 << 6) >>
                       7);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift1' */
  /* End of Outputs for SubSystem: '<S5>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift' */
  rtb_y_e = (uint8_T) BlinkerCAN_BitShift4_n(BlinkerCAN_B.CANReceive_o3);

  /* End of Outputs for SubSystem: '<S20>/Bit Shift' */

  /* Outputs for Atomic SubSystem: '<S20>/Bit Shift1' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift5_c(rtb_y_e);

  /* End of Outputs for SubSystem: '<S20>/Bit Shift1' */

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  Compare_m = (rtb_y_ke == 1);

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  Compare_f = (rtb_y_ke == 2);

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   */
  Compare_d = (rtb_y_ke == 3);

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   */
  Compare_a = (rtb_y_ke == 4);

  /* Chart: '<Root>/Steuerung_Licht' */
  if (BlinkerCAN_DW.is_active_c1_BlinkerCAN == 0U) {
    BlinkerCAN_DW.is_active_c1_BlinkerCAN = 1U;
    BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Default;
    BlinkerCAN_B.FEL_LED = false;
    BlinkerCAN_B.ABL_LED = false;
    BlinkerCAN_B.TFL_LED = false;
  } else {
    switch (BlinkerCAN_DW.is_c1_BlinkerCAN) {
     case BlinkerCAN_IN_Abblend_Licht:
      BlinkerCAN_B.ABL_LED = true;
      if (!Compare_d) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Default;
        BlinkerCAN_B.FEL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.TFL_LED = false;
      }
      break;

     case BlinkerCAN_IN_Automatik_Betrieb:
      BlinkerCAN_B.TFL_LED = false;
      BlinkerCAN_B.ABL_LED = false;
      BlinkerCAN_B.FEL_LED = false;
      if (!Compare_m) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Default;
        BlinkerCAN_B.FEL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.TFL_LED = false;
      } else if (Compare) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Hell;
        BlinkerCAN_B.TFL_LED = true;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = false;
      } else {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Dunkel;
        BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_Groesser;
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = true;
      }
      break;

     case BlinkerCAN_IN_Default:
      BlinkerCAN_B.FEL_LED = false;
      BlinkerCAN_B.ABL_LED = false;
      BlinkerCAN_B.TFL_LED = false;
      if (Compare_m) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Automatik_Betrieb;
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = false;
      } else if (Compare_a) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Fern_Licht;
        BlinkerCAN_B.FEL_LED = true;
      } else if (Compare_d) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Abblend_Licht;
        BlinkerCAN_B.ABL_LED = true;
      } else {
        if (Compare_f) {
          BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Tagfahr_Licht;
          BlinkerCAN_B.TFL_LED = true;
        }
      }
      break;

     case BlinkerCAN_IN_Dunkel:
      if (Compare) {
        BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_NO_ACTIVE_CHILD;
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Hell;
        BlinkerCAN_B.TFL_LED = true;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = false;
      } else if (!Compare_m) {
        BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_NO_ACTIVE_CHILD;
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Automatik_Betrieb;
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = false;
      } else if (BlinkerCAN_DW.is_Dunkel == BlinkerCAN_IN_Groesser) {
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = true;
        if (rtb_y_b < 250) {
          BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_Kleiner;
          BlinkerCAN_B.TFL_LED = false;
          BlinkerCAN_B.ABL_LED = true;
          BlinkerCAN_B.FEL_LED = false;
        }
      } else {
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = true;
        BlinkerCAN_B.FEL_LED = false;
        if (rtb_y_b > 250) {
          BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_Groesser;
          BlinkerCAN_B.TFL_LED = false;
          BlinkerCAN_B.ABL_LED = false;
          BlinkerCAN_B.FEL_LED = true;
        }
      }
      break;

     case BlinkerCAN_IN_Fern_Licht:
      BlinkerCAN_B.FEL_LED = true;
      if (!Compare_a) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Default;
        BlinkerCAN_B.FEL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.TFL_LED = false;
      }
      break;

     case BlinkerCAN_IN_Hell:
      BlinkerCAN_B.TFL_LED = true;
      BlinkerCAN_B.ABL_LED = false;
      BlinkerCAN_B.FEL_LED = false;
      if (!Compare_m) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Automatik_Betrieb;
        BlinkerCAN_B.TFL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.FEL_LED = false;
      } else {
        if (!Compare) {
          BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Dunkel;
          BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_Groesser;
          BlinkerCAN_B.TFL_LED = false;
          BlinkerCAN_B.ABL_LED = false;
          BlinkerCAN_B.FEL_LED = true;
        }
      }
      break;

     default:
      BlinkerCAN_B.TFL_LED = true;
      if (!Compare_f) {
        BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_Default;
        BlinkerCAN_B.FEL_LED = false;
        BlinkerCAN_B.ABL_LED = false;
        BlinkerCAN_B.TFL_LED = false;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Steuerung_Licht' */

  /* S-Function (stm32f4_can): '<Root>/CAN Receive4' */

  /* CANReceive4: '<Root>/CAN Receive4' */
  BlinkerCAN_B.CANReceive4_o1 = CANReceive4_GetMsg(&CANReceive4_Msg);/* Message and Pending count */
  CANReceive4_data = (CANReceive4_DATA_STRUCT*)&(CANReceive4_Msg.Data[0]);
  BlinkerCAN_B.CANReceive4_o2 = CANReceive4_Msg.StdId;/* Standard ID */
  BlinkerCAN_B.CANReceive4_o3 = CANReceive4_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift4' */
  rtb_y_e = (uint8_T) BlinkerCAN_BitShift4_n(BlinkerCAN_B.CANReceive4_o3);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift5' */
  rtb_y_ke = (uint8_T) BlinkerCAN_BitShift5_c(rtb_y_e);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift5' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   */
  BlinkerCAN_B.Compare_d2 = (rtb_y_ke >= 1);

  /* Logic: '<Root>/Logical Operator' */
  BlinkerCAN_B.LogicalOperator = (BlinkerCAN_B.ABL_LED || BlinkerCAN_B.FEL_LED);

  /* S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* DigitalOutput */
  {
    *DigitalOutput_C0 = BlinkerCAN_B.BLL_LED;
    *DigitalOutput_C1 = BlinkerCAN_B.BLR_LED;
    *DigitalOutput_C2 = BlinkerCAN_B.FEL_LED;
    *DigitalOutput_C3 = BlinkerCAN_B.ABL_LED;
    *DigitalOutput_C4 = BlinkerCAN_B.TFL_LED;
    *DigitalOutput_C5 = BlinkerCAN_B.Compare_d2;
    *DigitalOutput_C6 = BlinkerCAN_B.Compare_c;
    *DigitalOutput_C7 = false;
    *DigitalOutput_C8 = BlinkerCAN_B.LogicalOperator;
    *DigitalOutput_C9 = false;
  }

  /* Update for UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  BlinkerCAN_DW.DelayInput1_DSTATE = BlinkerCAN_B.Compare_c;
}

/* Model initialize function */
void BlinkerCAN_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BlinkerCAN_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &BlinkerCAN_B), 0,
                sizeof(B_BlinkerCAN_T));

  /* states (dwork) */
  (void) memset((void *)&BlinkerCAN_DW, 0,
                sizeof(DW_BlinkerCAN_T));

  /* SystemInitialize for Chart: '<Root>/Steuerung_Blinker' */
  BlinkerCAN_DW.temporalCounter_i1 = 0U;
  BlinkerCAN_DW.is_active_c3_BlinkerCAN = 0U;
  BlinkerCAN_DW.is_c3_BlinkerCAN = BlinkerCAN_IN_NO_ACTIVE_CHILD;
  BlinkerCAN_DW.CountL = 9.0;
  BlinkerCAN_DW.CountR = 9.0;

  /* SystemInitialize for Chart: '<Root>/Steuerung_Licht' */
  BlinkerCAN_DW.is_Dunkel = BlinkerCAN_IN_NO_ACTIVE_CHILD;
  BlinkerCAN_DW.is_active_c1_BlinkerCAN = 0U;
  BlinkerCAN_DW.is_c1_BlinkerCAN = BlinkerCAN_IN_NO_ACTIVE_CHILD;

  /* Enable for S-Function (stm32f4_usart): '<Root>/UART Setup' */
  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive' */
  /* Level2 S-Function Block: '<Root>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive1' */
  /* Level2 S-Function Block: '<Root>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive2' */
  /* Level2 S-Function Block: '<Root>/CAN Receive2' (stm32f4_can) */
  enable_CANReceive2();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive3' */
  /* Level2 S-Function Block: '<Root>/CAN Receive3' (stm32f4_can) */
  enable_CANReceive3();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive4' */
  /* Level2 S-Function Block: '<Root>/CAN Receive4' (stm32f4_can) */
  enable_CANReceive4();

  /* Enable for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */
  /* Level2 S-Function Block: '<Root>/Digital Output' (stm32f4_digital_output) */
  enable_DigitalOutput();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Setup' */
  /* Level2 S-Function Block: '<Root>/CAN Setup' (stm32f4_can) */
  enable_CANSetup();
}

/* Model terminate function */
void BlinkerCAN_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* terminate_DigitalOutput(); */
}

/* [EOF] */
