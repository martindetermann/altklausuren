/*
 * File: Schloss_Box_final_Debounce.c
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

#include "Schloss_Box_final_Debounce.h"

/* Include model header file for global data */
#include "Schloss_Box_final.h"
#include "Schloss_Box_final_private.h"

/*
 * Output and update for enable system:
 *    '<S7>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem4'
 *    '<S7>/Enabled Subsystem5'
 *    '<S8>/Enabled Subsystem'
 *    '<S8>/Enabled Subsystem4'
 *    '<S8>/Enabled Subsystem5'
 */
void Schloss_Box_fi_EnabledSubsystem(boolean_T rtu_Enable, uint32_T *rty_Out1,
  DW_EnabledSubsystem_Schloss_B_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtu_Enable) {
    /* UnitDelay: '<S21>/Output' */
    *rty_Out1 = localDW->Output_DSTATE;

    /* Update for UnitDelay: '<S21>/Output' incorporates:
     *  Constant: '<S22>/FixPt Constant'
     *  Sum: '<S22>/FixPt Sum1'
     */
    localDW->Output_DSTATE = *rty_Out1 + 1U;
  }

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/Debounce'
 *    '<S1>/Debounce1'
 */
boolean_T Schloss_Box_final_Debounce(boolean_T rtu_In1,
  B_Debounce_Schloss_Box_final_T *localB, DW_Debounce_Schloss_Box_final_T
  *localDW, int32_T rtp_mode)
{
  boolean_T rtb_LogicalOperator4;
  uint8_T rtb_Compare_d;
  boolean_T rtb_LogicalOperator6;
  boolean_T rty_Out1_0;

  /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Memory: '<S7>/Memory'
   *  Memory: '<S7>/Memory1'
   *  Sum: '<S7>/Add'
   */
  rty_Out1_0 = ((int32_T)localDW->Memory1_PreviousInput - (int32_T)
                localDW->Memory_PreviousInput > 4);

  /* Logic: '<S7>/Logical Operator4' incorporates:
   *  Memory: '<S7>/Memory3'
   */
  rtb_LogicalOperator4 = (rty_Out1_0 || localDW->Memory3_PreviousInput);

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem5' */
  Schloss_Box_fi_EnabledSubsystem(rtb_LogicalOperator4, &localB->Output,
    &localDW->EnabledSubsystem5);

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem5' */

  /* RelationalOperator: '<S15>/Compare' */
  rtb_Compare_d = (uint8_T)!rtu_In1;

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' */

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Logic: '<S7>/Logical Operator2'
   *  Logic: '<S7>/Logical Operator3'
   *  Logic: '<S7>/Logical Operator5'
   *  Memory: '<S7>/Memory3'
   */
  Schloss_Box_fi_EnabledSubsystem((!(rtb_Compare_d != 0)) && (!rty_Out1_0) &&
    (!localDW->Memory3_PreviousInput), &localB->Output_ji,
    &localDW->EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */

  /* Logic: '<S7>/Logical Operator6' incorporates:
   *  Logic: '<S7>/Logical Operator7'
   *  Memory: '<S7>/Memory2'
   */
  rtb_LogicalOperator6 = (rtb_LogicalOperator4 &&
    (!localDW->Memory2_PreviousInput));

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (rtb_LogicalOperator6) {
    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator'
     *  UnitDelay: '<S25>/Output'
     */
    localB->Compare = (uint8_T)((localDW->Output_DSTATE & 1U) == 0U);

    /* Update for UnitDelay: '<S25>/Output' incorporates:
     *  Constant: '<S26>/FixPt Constant'
     *  Sum: '<S26>/FixPt Sum1'
     */
    localDW->Output_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem4' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Memory: '<S7>/Memory'
   *  Memory: '<S7>/Memory1'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  Schloss_Box_fi_EnabledSubsystem((localDW->Memory_PreviousInput <
    localDW->Memory1_PreviousInput) && (rtb_Compare_d != 0), &localB->Output_j,
    &localDW->EnabledSubsystem4);

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem4' */

  /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  switch (rtp_mode) {
   case 1:
    break;

   case 2:
    rty_Out1_0 = rtb_LogicalOperator6;
    break;

   default:
    rty_Out1_0 = (localB->Compare != 0);
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* Update for Memory: '<S7>/Memory' */
  localDW->Memory_PreviousInput = localB->Output_j;

  /* Update for Memory: '<S7>/Memory1' */
  localDW->Memory1_PreviousInput = localB->Output_ji;

  /* Update for Memory: '<S7>/Memory3' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S7>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  RelationalOperator: '<S16>/Compare'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator'
   */
  localDW->Memory3_PreviousInput = ((localB->Output & 4U) != 0U);

  /* Update for Memory: '<S7>/Memory2' */
  localDW->Memory2_PreviousInput = rtb_LogicalOperator4;
  return rty_Out1_0;
}

/* [EOF] */
