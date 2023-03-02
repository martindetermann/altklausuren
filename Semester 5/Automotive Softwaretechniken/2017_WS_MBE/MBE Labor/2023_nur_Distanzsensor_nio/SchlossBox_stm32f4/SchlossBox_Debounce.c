/*
 * File: SchlossBox_Debounce.c
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

#include "SchlossBox_Debounce.h"

/* Include model header file for global data */
#include "SchlossBox.h"
#include "SchlossBox_private.h"

/*
 * Output and update for enable system:
 *    '<S8>/Enabled Subsystem'
 *    '<S8>/Enabled Subsystem4'
 *    '<S8>/Enabled Subsystem5'
 *    '<S9>/Enabled Subsystem'
 *    '<S9>/Enabled Subsystem4'
 *    '<S9>/Enabled Subsystem5'
 */
void SchlossBox_EnabledSubsystem(boolean_T rtu_Enable, uint32_T *rty_Out1,
  DW_EnabledSubsystem_SchlossBo_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (rtu_Enable) {
    /* UnitDelay: '<S24>/Output' */
    *rty_Out1 = localDW->Output_DSTATE;

    /* Update for UnitDelay: '<S24>/Output' incorporates:
     *  Constant: '<S25>/FixPt Constant'
     *  Sum: '<S25>/FixPt Sum1'
     */
    localDW->Output_DSTATE = *rty_Out1 + 1U;
  }

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<Root>/Debounce'
 *    '<Root>/Debounce1'
 */
boolean_T SchlossBox_Debounce(boolean_T rtu_In1, B_Debounce_SchlossBox_T *localB,
  DW_Debounce_SchlossBox_T *localDW, int32_T rtp_mode)
{
  boolean_T rtb_LogicalOperator4;
  uint8_T rtb_Compare_d;
  boolean_T rtb_LogicalOperator6;
  boolean_T rty_Out1_0;

  /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Memory: '<S8>/Memory'
   *  Memory: '<S8>/Memory1'
   *  Sum: '<S8>/Add'
   */
  rty_Out1_0 = ((int32_T)localDW->Memory1_PreviousInput - (int32_T)
                localDW->Memory_PreviousInput > 4);

  /* Logic: '<S8>/Logical Operator4' incorporates:
   *  Memory: '<S8>/Memory3'
   */
  rtb_LogicalOperator4 = (rty_Out1_0 || localDW->Memory3_PreviousInput);

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem5' */
  SchlossBox_EnabledSubsystem(rtb_LogicalOperator4, &localB->Output,
    &localDW->EnabledSubsystem5);

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem5' */

  /* RelationalOperator: '<S18>/Compare' */
  rtb_Compare_d = (uint8_T)!rtu_In1;

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' */

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator5'
   *  Memory: '<S8>/Memory3'
   */
  SchlossBox_EnabledSubsystem((!(rtb_Compare_d != 0)) && (!rty_Out1_0) &&
    (!localDW->Memory3_PreviousInput), &localB->Output_ji,
    &localDW->EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

  /* Logic: '<S8>/Logical Operator6' incorporates:
   *  Logic: '<S8>/Logical Operator7'
   *  Memory: '<S8>/Memory2'
   */
  rtb_LogicalOperator6 = (rtb_LogicalOperator4 &&
    (!localDW->Memory2_PreviousInput));

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (rtb_LogicalOperator6) {
    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  S-Function (sfix_bitop): '<S21>/Bitwise Operator'
     *  UnitDelay: '<S28>/Output'
     */
    localB->Compare = (uint8_T)((localDW->Output_DSTATE & 1U) == 0U);

    /* Update for UnitDelay: '<S28>/Output' incorporates:
     *  Constant: '<S29>/FixPt Constant'
     *  Sum: '<S29>/FixPt Sum1'
     */
    localDW->Output_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem4' */

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Memory: '<S8>/Memory'
   *  Memory: '<S8>/Memory1'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  SchlossBox_EnabledSubsystem((localDW->Memory_PreviousInput <
    localDW->Memory1_PreviousInput) && (rtb_Compare_d != 0), &localB->Output_j,
    &localDW->EnabledSubsystem4);

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem4' */

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Constant: '<S8>/Constant1'
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

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* Update for Memory: '<S8>/Memory' */
  localDW->Memory_PreviousInput = localB->Output_j;

  /* Update for Memory: '<S8>/Memory1' */
  localDW->Memory1_PreviousInput = localB->Output_ji;

  /* Update for Memory: '<S8>/Memory3' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  RelationalOperator: '<S19>/Compare'
   *  S-Function (sfix_bitop): '<S8>/Bitwise Operator'
   */
  localDW->Memory3_PreviousInput = ((localB->Output & 4U) != 0U);

  /* Update for Memory: '<S8>/Memory2' */
  localDW->Memory2_PreviousInput = rtb_LogicalOperator4;
  return rty_Out1_0;
}

/* [EOF] */
