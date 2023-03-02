/*
 * File: Blinker_Box_final.c
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

#include "Blinker_Box_final.h"
#include "Blinker_Box_final_private.h"

/* Named constants for Chart: '<S4>/Steuerung_Blinker' */
#define Blinker_B_IN_SchliessenBlinken1 ((uint8_T)10U)
#define Blinker_B_IN_SchliessenBlinken2 ((uint8_T)11U)
#define Blinker_Bo_IN_EnableBlinkerTipL ((uint8_T)7U)
#define Blinker_Bo_IN_EnableBlinkerTipR ((uint8_T)8U)
#define Blinker_Box__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Blinker_Box_f_IN_OeffnenBlinken ((uint8_T)9U)
#define Blinker_Box_fin_IN_AlarmBlinken ((uint8_T)1U)
#define Blinker_Box_fina_IN_BlinkerTipL ((uint8_T)4U)
#define Blinker_Box_fina_IN_BlinkerTipR ((uint8_T)5U)
#define Blinker_Box_fina_IN_WarnBlinker ((uint8_T)12U)
#define Blinker_Box_final_IN_BlinkerL  ((uint8_T)2U)
#define Blinker_Box_final_IN_BlinkerR  ((uint8_T)3U)
#define Blinker_Box_final_IN_Dummy     ((uint8_T)6U)

/* Named constants for Chart: '<S4>/Steuerung_Licht' */
#define Blinker_Box_fi_IN_Abblend_Licht ((uint8_T)1U)
#define Blinker_Box_fi_IN_Tagfahr_Licht ((uint8_T)5U)
#define Blinker_Box_final_IN_Default   ((uint8_T)2U)
#define Blinker_Box_final_IN_Dunkel    ((uint8_T)1U)
#define Blinker_Box_final_IN_Einstieg  ((uint8_T)2U)
#define Blinker_Box_final_IN_Fern_Licht ((uint8_T)3U)
#define Blinker_Box_final_IN_Groesser  ((uint8_T)1U)
#define Blinker_Box_final_IN_Hell      ((uint8_T)3U)
#define Blinker_Box_final_IN_Kleiner   ((uint8_T)2U)
#define Blinker_Box_final_IN_Licht_Auto ((uint8_T)4U)

/* Block signals (auto storage) */
B_Blinker_Box_final_T Blinker_Box_final_B;

/* Block states (auto storage) */
DW_Blinker_Box_final_T Blinker_Box_final_DW;

/* Real-time model */
RT_MODEL_Blinker_Box_final_T Blinker_Box_final_M_;
RT_MODEL_Blinker_Box_final_T *const Blinker_Box_final_M = &Blinker_Box_final_M_;

/* Forward declaration for local functions */
static void Blinker_Box_final_WarnBlinker(void);

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift4'
 *    '<S8>/Bit Shift4'
 */
uint8_T Blinker_Box_final_BitShift4(uint8_T rtu_u)
{
  /* MATLAB Function: '<S10>/bit_shift' */
  return (uint8_T)(rtu_u << 7);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift5'
 *    '<S22>/Bit Shift6'
 *    '<S8>/Bit Shift5'
 */
uint8_T Blinker_Box_final_BitShift5(uint8_T rtu_u)
{
  /* MATLAB Function: '<S11>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift4'
 *    '<S22>/Bit Shift'
 */
uint8_T Blinker_Box_final_BitShift4_h(uint8_T rtu_u)
{
  /* MATLAB Function: '<S16>/bit_shift' */
  return (uint8_T)(rtu_u << 5);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift5'
 *    '<S22>/Bit Shift1'
 */
uint8_T Blinker_Box_final_BitShift5_b(uint8_T rtu_u)
{
  /* MATLAB Function: '<S17>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S22>/Bit Shift3'
 *    '<S22>/Bit Shift5'
 */
uint8_T Blinker_Box_final_BitShift3(uint8_T rtu_u)
{
  /* MATLAB Function: '<S26>/bit_shift' */
  return (uint8_T)((uint32_T)rtu_u >> 6);
}

/* Function for Chart: '<S4>/Steuerung_Blinker' */
static void Blinker_Box_final_WarnBlinker(void)
{
  if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
    Blinker_Box_final_DW.is_c2_Blinker_Box_final = Blinker_Box_final_IN_Dummy;
    Blinker_Box_final_DW.temporalCounter_i1 = 0U;
    Blinker_Box_final_B.BLL_LED = false;
    Blinker_Box_final_B.BLR_LED = false;
    Blinker_Box_final_DW.CountL = 1.0;
    Blinker_Box_final_DW.CountR = 1.0;
    Blinker_Box_final_DW.SchliessCount = 0.0;
  }
}

/* Model step function */
void Blinker_Box_final_step(void)
{
  uint8_T rtb_y_kh;
  uint8_T rtb_y_bv;
  uint16_T rtb_y_d;
  boolean_T Compare;
  boolean_T Compare_g;
  boolean_T Compare_c;
  boolean_T Compare_h;
  boolean_T Compare_cw;
  boolean_T Compare_b;
  boolean_T Compare_p;
  boolean_T FixPtRelationalOperator;

  /* S-Function (stm32f4_can): '<S1>/CAN Receive' */

  /* CANReceive: '<S1>/CAN Receive' */
  Blinker_Box_final_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  Blinker_Box_final_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  Blinker_Box_final_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift3' */

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift2' */

  /* MATLAB Function: '<S25>/bit_shift' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift3((uint8_T)
    (Blinker_Box_final_B.CANReceive_o3 << 3));

  /* End of Outputs for SubSystem: '<S22>/Bit Shift2' */

  /* End of Outputs for SubSystem: '<S22>/Bit Shift3' */

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  Compare = (rtb_y_kh == 1);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  Compare_g = (rtb_y_kh == 2);

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift5' */

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift4' */

  /* MATLAB Function: '<S27>/bit_shift' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift3((uint8_T)
    (Blinker_Box_final_B.CANReceive_o3 << 1));

  /* End of Outputs for SubSystem: '<S22>/Bit Shift4' */

  /* End of Outputs for SubSystem: '<S22>/Bit Shift5' */

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   */
  Compare_c = (rtb_y_kh == 1);

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   */
  Compare_h = (rtb_y_kh == 2);

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift6' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift5
    (Blinker_Box_final_B.CANReceive_o3);

  /* End of Outputs for SubSystem: '<S22>/Bit Shift6' */

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   */
  Compare_cw = (rtb_y_kh == 1);

  /* S-Function (stm32f4_can): '<S1>/CAN Receive1' */

  /* CANReceive1: '<S1>/CAN Receive1' */
  Blinker_Box_final_B.CANReceive1_o1 = CANReceive1_GetMsg(&CANReceive1_Msg);/* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  Blinker_Box_final_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  Blinker_Box_final_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S8>/Bit Shift4' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift4
    (Blinker_Box_final_B.CANReceive1_o3);

  /* End of Outputs for SubSystem: '<S8>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S8>/Bit Shift5' */
  rtb_y_bv = (uint8_T) Blinker_Box_final_BitShift5(rtb_y_kh);

  /* End of Outputs for SubSystem: '<S8>/Bit Shift5' */

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  Compare_b = (rtb_y_bv == 1);

  /* S-Function (stm32f4_can): '<S1>/CAN Receive2' */

  /* CANReceive2: '<S1>/CAN Receive2' */
  Blinker_Box_final_B.CANReceive2_o1 = CANReceive2_GetMsg(&CANReceive2_Msg);/* Message and Pending count */
  CANReceive2_data = (CANReceive2_DATA_STRUCT*)&(CANReceive2_Msg.Data[0]);
  Blinker_Box_final_B.CANReceive2_o2 = CANReceive2_Msg.StdId;/* Standard ID */
  Blinker_Box_final_B.CANReceive2_o3 = CANReceive2_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift4' */
  rtb_y_bv = (uint8_T) Blinker_Box_final_BitShift4
    (Blinker_Box_final_B.CANReceive2_o3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift5' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift5(rtb_y_bv);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift5' */

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  Compare_p = (rtb_y_kh == 1);

  /* RelationalOperator: '<S54>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S54>/Delay Input1'
   *
   * Block description for '<S54>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FixPtRelationalOperator = (Compare_b !=
    Blinker_Box_final_DW.DelayInput1_DSTATE);

  /* Chart: '<S4>/Steuerung_Blinker' */
  if (Blinker_Box_final_DW.temporalCounter_i1 < 127U) {
    Blinker_Box_final_DW.temporalCounter_i1++;
  }

  if (Blinker_Box_final_DW.is_active_c2_Blinker_Box_final == 0U) {
    Blinker_Box_final_DW.is_active_c2_Blinker_Box_final = 1U;
    Blinker_Box_final_DW.is_c2_Blinker_Box_final = Blinker_Box_final_IN_Dummy;
    Blinker_Box_final_DW.temporalCounter_i1 = 0U;
    Blinker_Box_final_B.BLL_LED = false;
    Blinker_Box_final_B.BLR_LED = false;
    Blinker_Box_final_DW.CountL = 1.0;
    Blinker_Box_final_DW.CountR = 1.0;
    Blinker_Box_final_DW.SchliessCount = 0.0;
  } else {
    switch (Blinker_Box_final_DW.is_c2_Blinker_Box_final) {
     case Blinker_Box_fin_IN_AlarmBlinken:
      if (!Compare_p) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      } else {
        if (Blinker_Box_final_DW.temporalCounter_i1 >= 100U) {
          Blinker_Box_final_DW.is_c2_Blinker_Box_final =
            Blinker_Box_fin_IN_AlarmBlinken;
          Blinker_Box_final_DW.temporalCounter_i1 = 0U;
          Blinker_Box_final_B.BLL_LED = !Blinker_Box_final_B.BLL_LED;
          Blinker_Box_final_B.BLR_LED = !Blinker_Box_final_B.BLR_LED;
        }
      }
      break;

     case Blinker_Box_final_IN_BlinkerL:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      }
      break;

     case Blinker_Box_final_IN_BlinkerR:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      }
      break;

     case Blinker_Box_fina_IN_BlinkerTipL:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.CountL++;
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Bo_IN_EnableBlinkerTipL;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
      }
      break;

     case Blinker_Box_fina_IN_BlinkerTipR:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.CountR++;
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Bo_IN_EnableBlinkerTipR;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLR_LED = false;
      }
      break;

     case Blinker_Box_final_IN_Dummy:
      if (Compare_cw && (Blinker_Box_final_DW.temporalCounter_i1 >= 50U)) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_fina_IN_WarnBlinker;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = true;
        Blinker_Box_final_B.BLR_LED = true;
      } else if (Compare_g && (Blinker_Box_final_DW.temporalCounter_i1 >= 50U))
      {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_BlinkerR;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLR_LED = true;
      } else if (Compare_p) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_fin_IN_AlarmBlinken;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = !Blinker_Box_final_B.BLL_LED;
        Blinker_Box_final_B.BLR_LED = !Blinker_Box_final_B.BLR_LED;
      } else if (Compare_b && FixPtRelationalOperator) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_B_IN_SchliessenBlinken1;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = true;
        Blinker_Box_final_B.BLR_LED = true;
      } else if (Compare_h && (Blinker_Box_final_DW.temporalCounter_i1 >= 50U))
      {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_BlinkerL;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = true;
      } else if (Compare_c && (!Compare_cw)) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Bo_IN_EnableBlinkerTipL;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
      } else if (Compare && (!Compare_cw)) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Bo_IN_EnableBlinkerTipR;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLR_LED = false;
      } else {
        if ((!Compare_b) && FixPtRelationalOperator) {
          Blinker_Box_final_DW.is_c2_Blinker_Box_final =
            Blinker_Box_f_IN_OeffnenBlinken;
          Blinker_Box_final_DW.temporalCounter_i1 = 0U;
          Blinker_Box_final_B.BLL_LED = true;
          Blinker_Box_final_B.BLR_LED = true;
        }
      }
      break;

     case Blinker_Bo_IN_EnableBlinkerTipL:
      if (Compare_cw || (Blinker_Box_final_DW.CountL > 3.0) || Compare_g ||
          Compare) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      } else {
        if ((Blinker_Box_final_DW.CountL <= 3.0) &&
            (Blinker_Box_final_DW.temporalCounter_i1 >= 50U)) {
          Blinker_Box_final_DW.is_c2_Blinker_Box_final =
            Blinker_Box_fina_IN_BlinkerTipL;
          Blinker_Box_final_DW.temporalCounter_i1 = 0U;
          Blinker_Box_final_B.BLL_LED = true;
        }
      }
      break;

     case Blinker_Bo_IN_EnableBlinkerTipR:
      if (Compare_cw || (Blinker_Box_final_DW.CountR > 3.0) || Compare_h ||
          Compare_c) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      } else {
        if ((Blinker_Box_final_DW.CountR <= 3.0) &&
            (Blinker_Box_final_DW.temporalCounter_i1 >= 50U)) {
          Blinker_Box_final_DW.is_c2_Blinker_Box_final =
            Blinker_Box_fina_IN_BlinkerTipR;
          Blinker_Box_final_DW.temporalCounter_i1 = 0U;
          Blinker_Box_final_B.BLR_LED = true;
        }
      }
      break;

     case Blinker_Box_f_IN_OeffnenBlinken:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      }
      break;

     case Blinker_B_IN_SchliessenBlinken1:
      if ((Blinker_Box_final_DW.SchliessCount == 1.0) &&
          (Blinker_Box_final_DW.temporalCounter_i1 >= 50U)) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_Box_final_IN_Dummy;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = false;
        Blinker_Box_final_B.BLR_LED = false;
        Blinker_Box_final_DW.CountL = 1.0;
        Blinker_Box_final_DW.CountR = 1.0;
        Blinker_Box_final_DW.SchliessCount = 0.0;
      } else {
        if ((Blinker_Box_final_DW.SchliessCount < 1.0) &&
            (Blinker_Box_final_DW.temporalCounter_i1 >= 50U)) {
          Blinker_Box_final_DW.is_c2_Blinker_Box_final =
            Blinker_B_IN_SchliessenBlinken2;
          Blinker_Box_final_DW.temporalCounter_i1 = 0U;
          Blinker_Box_final_B.BLL_LED = false;
          Blinker_Box_final_B.BLR_LED = false;
          Blinker_Box_final_DW.SchliessCount++;
        }
      }
      break;

     case Blinker_B_IN_SchliessenBlinken2:
      if (Blinker_Box_final_DW.temporalCounter_i1 >= 50U) {
        Blinker_Box_final_DW.is_c2_Blinker_Box_final =
          Blinker_B_IN_SchliessenBlinken1;
        Blinker_Box_final_DW.temporalCounter_i1 = 0U;
        Blinker_Box_final_B.BLL_LED = true;
        Blinker_Box_final_B.BLR_LED = true;
      }
      break;

     default:
      Blinker_Box_final_WarnBlinker();
      break;
    }
  }

  /* End of Chart: '<S4>/Steuerung_Blinker' */

  /* S-Function (stm32f4_can): '<S1>/CAN Receive3' */

  /* CANReceive3: '<S1>/CAN Receive3' */
  Blinker_Box_final_B.CANReceive3_o1 = CANReceive3_GetMsg(&CANReceive3_Msg);/* Message and Pending count */
  CANReceive3_data = (CANReceive3_DATA_STRUCT*)&(CANReceive3_Msg.Data[0]);
  Blinker_Box_final_B.CANReceive3_o2 = CANReceive3_Msg.StdId;/* Standard ID */
  Blinker_Box_final_B.CANReceive3_o3 = CANReceive3_data->d0;/* Data0: uint16 */

  /* Outputs for Atomic SubSystem: '<S9>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S9>/Bit Shift4' */
  /* RelationalOperator: '<S62>/Compare' incorporates:
   *  Constant: '<S62>/Constant'
   *  MATLAB Function: '<S59>/bit_shift'
   *  MATLAB Function: '<S60>/bit_shift'
   */
  Compare = ((int32_T)((uint32_T)(uint16_T)(Blinker_Box_final_B.CANReceive3_o3 <<
    15) >> 15) == 1);

  /* End of Outputs for SubSystem: '<S9>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S9>/Bit Shift5' */

  /* Outputs for Atomic SubSystem: '<S9>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S9>/Bit Shift1' */
  /* MATLAB Function: '<S58>/bit_shift' incorporates:
   *  MATLAB Function: '<S57>/bit_shift'
   */
  rtb_y_d = (uint16_T)((uint32_T)(uint16_T)(Blinker_Box_final_B.CANReceive3_o3 <<
    6) >> 7);

  /* End of Outputs for SubSystem: '<S9>/Bit Shift1' */
  /* End of Outputs for SubSystem: '<S9>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift' */
  rtb_y_bv = (uint8_T) Blinker_Box_final_BitShift4_h
    (Blinker_Box_final_B.CANReceive_o3);

  /* End of Outputs for SubSystem: '<S22>/Bit Shift' */

  /* Outputs for Atomic SubSystem: '<S22>/Bit Shift1' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift5_b(rtb_y_bv);

  /* End of Outputs for SubSystem: '<S22>/Bit Shift1' */

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  Compare_g = (rtb_y_kh == 1);

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   */
  Compare_c = (rtb_y_kh == 2);

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   */
  Compare_h = (rtb_y_kh == 3);

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  Compare_cw = (rtb_y_kh == 4);

  /* Chart: '<S4>/Steuerung_Licht' */
  if (Blinker_Box_final_DW.is_active_c4_Blinker_Box_final == 0U) {
    Blinker_Box_final_DW.is_active_c4_Blinker_Box_final = 1U;
    Blinker_Box_final_DW.is_c4_Blinker_Box_final = Blinker_Box_final_IN_Default;
    Blinker_Box_final_B.FEL_LED = false;
    Blinker_Box_final_B.ABL_LED = false;
    Blinker_Box_final_B.TFL_LED = false;
  } else {
    switch (Blinker_Box_final_DW.is_c4_Blinker_Box_final) {
     case Blinker_Box_fi_IN_Abblend_Licht:
      Blinker_Box_final_B.ABL_LED = true;
      if (!Compare_h) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Default;
        Blinker_Box_final_B.FEL_LED = false;
        Blinker_Box_final_B.ABL_LED = false;
        Blinker_Box_final_B.TFL_LED = false;
      }
      break;

     case Blinker_Box_final_IN_Default:
      Blinker_Box_final_B.FEL_LED = false;
      Blinker_Box_final_B.ABL_LED = false;
      Blinker_Box_final_B.TFL_LED = false;
      if (Compare_g) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Licht_Auto;
        Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box_final_IN_Einstieg;
      } else if (Compare_cw) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Fern_Licht;
        Blinker_Box_final_B.FEL_LED = true;
      } else if (Compare_h) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_fi_IN_Abblend_Licht;
        Blinker_Box_final_B.ABL_LED = true;
      } else {
        if (Compare_c) {
          Blinker_Box_final_DW.is_c4_Blinker_Box_final =
            Blinker_Box_fi_IN_Tagfahr_Licht;
          Blinker_Box_final_B.TFL_LED = true;
        }
      }
      break;

     case Blinker_Box_final_IN_Fern_Licht:
      Blinker_Box_final_B.FEL_LED = true;
      if (!Compare_cw) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Default;
        Blinker_Box_final_B.FEL_LED = false;
        Blinker_Box_final_B.ABL_LED = false;
        Blinker_Box_final_B.TFL_LED = false;
      }
      break;

     case Blinker_Box_final_IN_Licht_Auto:
      if (!Compare_g) {
        Blinker_Box_final_DW.is_Dunkel = Blinker_Box__IN_NO_ACTIVE_CHILD;
        Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box__IN_NO_ACTIVE_CHILD;
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Default;
        Blinker_Box_final_B.FEL_LED = false;
        Blinker_Box_final_B.ABL_LED = false;
        Blinker_Box_final_B.TFL_LED = false;
      } else {
        switch (Blinker_Box_final_DW.is_Licht_Auto) {
         case Blinker_Box_final_IN_Dunkel:
          if (Compare) {
            Blinker_Box_final_DW.is_Dunkel = Blinker_Box__IN_NO_ACTIVE_CHILD;
            Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box_final_IN_Hell;
            Blinker_Box_final_B.TFL_LED = true;
            Blinker_Box_final_B.ABL_LED = false;
            Blinker_Box_final_B.FEL_LED = false;
          } else if (Blinker_Box_final_DW.is_Dunkel ==
                     Blinker_Box_final_IN_Groesser) {
            Blinker_Box_final_B.TFL_LED = false;
            Blinker_Box_final_B.ABL_LED = false;
            Blinker_Box_final_B.FEL_LED = true;
            if (rtb_y_d < 250) {
              Blinker_Box_final_DW.is_Dunkel = Blinker_Box_final_IN_Kleiner;
              Blinker_Box_final_B.TFL_LED = false;
              Blinker_Box_final_B.ABL_LED = true;
              Blinker_Box_final_B.FEL_LED = false;
            }
          } else {
            Blinker_Box_final_B.TFL_LED = false;
            Blinker_Box_final_B.ABL_LED = true;
            Blinker_Box_final_B.FEL_LED = false;
            if (rtb_y_d > 250) {
              Blinker_Box_final_DW.is_Dunkel = Blinker_Box_final_IN_Groesser;
              Blinker_Box_final_B.TFL_LED = false;
              Blinker_Box_final_B.ABL_LED = false;
              Blinker_Box_final_B.FEL_LED = true;
            }
          }
          break;

         case Blinker_Box_final_IN_Einstieg:
          if (!Compare) {
            Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box_final_IN_Dunkel;
            Blinker_Box_final_DW.is_Dunkel = Blinker_Box_final_IN_Groesser;
            Blinker_Box_final_B.TFL_LED = false;
            Blinker_Box_final_B.ABL_LED = false;
            Blinker_Box_final_B.FEL_LED = true;
          } else {
            Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box_final_IN_Hell;
            Blinker_Box_final_B.TFL_LED = true;
            Blinker_Box_final_B.ABL_LED = false;
            Blinker_Box_final_B.FEL_LED = false;
          }
          break;

         default:
          Blinker_Box_final_B.TFL_LED = true;
          Blinker_Box_final_B.ABL_LED = false;
          Blinker_Box_final_B.FEL_LED = false;
          if (!Compare) {
            Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box_final_IN_Dunkel;
            Blinker_Box_final_DW.is_Dunkel = Blinker_Box_final_IN_Groesser;
            Blinker_Box_final_B.TFL_LED = false;
            Blinker_Box_final_B.ABL_LED = false;
            Blinker_Box_final_B.FEL_LED = true;
          }
          break;
        }
      }
      break;

     default:
      Blinker_Box_final_B.TFL_LED = true;
      if (!Compare_c) {
        Blinker_Box_final_DW.is_c4_Blinker_Box_final =
          Blinker_Box_final_IN_Default;
        Blinker_Box_final_B.FEL_LED = false;
        Blinker_Box_final_B.ABL_LED = false;
        Blinker_Box_final_B.TFL_LED = false;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Steuerung_Licht' */

  /* S-Function (stm32f4_can): '<S1>/CAN Receive4' */

  /* CANReceive4: '<S1>/CAN Receive4' */
  Blinker_Box_final_B.CANReceive4_o1 = CANReceive4_GetMsg(&CANReceive4_Msg);/* Message and Pending count */
  CANReceive4_data = (CANReceive4_DATA_STRUCT*)&(CANReceive4_Msg.Data[0]);
  Blinker_Box_final_B.CANReceive4_o2 = CANReceive4_Msg.StdId;/* Standard ID */
  Blinker_Box_final_B.CANReceive4_o3 = CANReceive4_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
  rtb_y_bv = (uint8_T) Blinker_Box_final_BitShift4_h
    (Blinker_Box_final_B.CANReceive4_o3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift5' */
  rtb_y_kh = (uint8_T) Blinker_Box_final_BitShift5_b(rtb_y_bv);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift5' */

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  Blinker_Box_final_B.Compare_bf = (rtb_y_kh >= 1);

  /* Logic: '<S4>/Logical Operator' */
  Blinker_Box_final_B.Rcklicht = (Blinker_Box_final_B.ABL_LED ||
    Blinker_Box_final_B.FEL_LED);

  /* S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* OutputDigitalOutput */
  {
    *OutputDigitalOutput_C0 = Blinker_Box_final_B.BLL_LED;
    *OutputDigitalOutput_C1 = Blinker_Box_final_B.BLR_LED;
    *OutputDigitalOutput_C2 = Blinker_Box_final_B.FEL_LED;
    *OutputDigitalOutput_C3 = Blinker_Box_final_B.ABL_LED;
    *OutputDigitalOutput_C4 = Blinker_Box_final_B.TFL_LED;
    *OutputDigitalOutput_C5 = Blinker_Box_final_B.Compare_bf;
    *OutputDigitalOutput_C6 = false;
    *OutputDigitalOutput_C7 = false;
    *OutputDigitalOutput_C8 = Blinker_Box_final_B.Rcklicht;
    *OutputDigitalOutput_C9 = false;
  }

  /* Update for UnitDelay: '<S54>/Delay Input1'
   *
   * Block description for '<S54>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Blinker_Box_final_DW.DelayInput1_DSTATE = Compare_b;
}

/* Model initialize function */
void Blinker_Box_final_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Blinker_Box_final_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Blinker_Box_final_B), 0,
                sizeof(B_Blinker_Box_final_T));

  /* states (dwork) */
  (void) memset((void *)&Blinker_Box_final_DW, 0,
                sizeof(DW_Blinker_Box_final_T));

  /* SystemInitialize for Chart: '<S4>/Steuerung_Blinker' */
  Blinker_Box_final_DW.temporalCounter_i1 = 0U;
  Blinker_Box_final_DW.is_active_c2_Blinker_Box_final = 0U;
  Blinker_Box_final_DW.is_c2_Blinker_Box_final = Blinker_Box__IN_NO_ACTIVE_CHILD;
  Blinker_Box_final_DW.CountL = 9.0;
  Blinker_Box_final_DW.CountR = 9.0;

  /* SystemInitialize for Chart: '<S4>/Steuerung_Licht' */
  Blinker_Box_final_DW.is_Licht_Auto = Blinker_Box__IN_NO_ACTIVE_CHILD;
  Blinker_Box_final_DW.is_Dunkel = Blinker_Box__IN_NO_ACTIVE_CHILD;
  Blinker_Box_final_DW.is_active_c4_Blinker_Box_final = 0U;
  Blinker_Box_final_DW.is_c4_Blinker_Box_final = Blinker_Box__IN_NO_ACTIVE_CHILD;

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive' */
  /* Level2 S-Function Block: '<S1>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive1' */
  /* Level2 S-Function Block: '<S1>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive2' */
  /* Level2 S-Function Block: '<S1>/CAN Receive2' (stm32f4_can) */
  enable_CANReceive2();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive3' */
  /* Level2 S-Function Block: '<S1>/CAN Receive3' (stm32f4_can) */
  enable_CANReceive3();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive4' */
  /* Level2 S-Function Block: '<S1>/CAN Receive4' (stm32f4_can) */
  enable_CANReceive4();

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
void Blinker_Box_final_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* terminate_OutputDigitalOutput(); */
}

/* [EOF] */
