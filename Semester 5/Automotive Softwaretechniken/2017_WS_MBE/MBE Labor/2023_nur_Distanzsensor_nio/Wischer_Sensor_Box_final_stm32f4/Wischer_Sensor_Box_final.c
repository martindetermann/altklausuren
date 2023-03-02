/*
 * File: Wischer_Sensor_Box_final.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Wischer_Sensor_Box_final.
 *
 * Model version                        : 1.7
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Tue Dec  5 15:44:29 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Tue Dec  5 15:44:29 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wischer_Sensor_Box_final.h"
#include "Wischer_Sensor_Box_final_private.h"

/* Named constants for Chart: '<S4>/ScheibenheizungsSteuerung' */
#define Wischer_Sens_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Wischer_Sensor_Box_f_IN_MANUELL ((uint8_T)2U)
#define Wischer_Sensor_Box_fina_IN_AUTO ((uint8_T)1U)
#define Wischer_Sensor_Box_final_IN_OFF ((uint8_T)1U)
#define Wischer_Sensor_Box_final_IN_ON ((uint8_T)2U)

/* Named constants for Chart: '<S4>/WischerSteuerung' */
#define Wischer_S_IN_INTERVALL_LANGSAM1 ((uint8_T)2U)
#define Wischer_S_IN_INTERVALL_LANGSAM2 ((uint8_T)3U)
#define Wischer_S_IN_INTERVALL_LANGSAM3 ((uint8_T)4U)
#define Wischer_Se_IN_INTERVALL_LANGSAM ((uint8_T)1U)
#define Wischer_Se_IN_WEIL_ICH_DUMM_BIN ((uint8_T)7U)
#define Wischer_Sen_IN_Wischer_Rueck_WW ((uint8_T)2U)
#define Wischer_Senso_IN_Wischer_Vor_WW ((uint8_T)3U)
#define Wischer_Sensor_B_IN_Wischer_Vor ((uint8_T)9U)
#define Wischer_Sensor_Box__IN_Spruehen ((uint8_T)1U)
#define Wischer_Sensor_Box__IN_Stufe_0_ ((uint8_T)5U)
#define Wischer_Sensor_Box__IN_Wischer1 ((uint8_T)4U)
#define Wischer_Sensor_Box_fi_IN_Phase1 ((uint8_T)1U)
#define Wischer_Sensor_Box_fi_IN_Phase2 ((uint8_T)2U)
#define Wischer_Sensor_Box_fi_IN_Phase3 ((uint8_T)3U)
#define Wischer_Sensor_Box_fi_IN_Phase4 ((uint8_T)4U)
#define Wischer_Sensor_Box_fina_IN_TIPP ((uint8_T)6U)
#define Wischer_Sensor_IN_Wischer_Rueck ((uint8_T)8U)

/* Block signals (auto storage) */
B_Wischer_Sensor_Box_final_T Wischer_Sensor_Box_final_B;

/* Block states (auto storage) */
DW_Wischer_Sensor_Box_final_T Wischer_Sensor_Box_final_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Wischer_Sensor_Box_fi_T Wischer_Sensor_Box_fina_PrevZCX;

/* Real-time model */
RT_MODEL_Wischer_Sensor_Box_f_T Wischer_Sensor_Box_final_M_;
RT_MODEL_Wischer_Sensor_Box_f_T *const Wischer_Sensor_Box_final_M =
  &Wischer_Sensor_Box_final_M_;

/* Forward declaration for local functions */
static void Wischer_Sensor_Bo_Wischer_Rueck(void);
static void Wischer__exit_internal_Wischer1(void);
static void Wischer_Sensor_Box_fin_Wischer1(const uint8_T *Compare, const
  uint8_T *Compare_h, const uint8_T *Compare_l, uint8_T *Compare_m, uint8_T
  *Compare_d, boolean_T *WischWasch);

/* Function for Chart: '<S4>/WischerSteuerung' */
static void Wischer_Sensor_Bo_Wischer_Rueck(void)
{
  /* During 'Wischer_Rueck': '<S46>:669' */
  /* '<S46>:642:1' sf_internal_predicateOutput = ... */
  /* '<S46>:642:1' Steps==0; */
  if (Wischer_Sensor_Box_final_DW.Steps == 0.0) {
    /* Transition: '<S46>:642' */
    /* Exit Internal 'Wischer_Rueck': '<S46>:669' */
    Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
      Wischer_Sens_IN_NO_ACTIVE_CHILD;
    Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Se_IN_WEIL_ICH_DUMM_BIN;
    Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;
  } else {
    switch (Wischer_Sensor_Box_final_DW.is_Wischer_Rueck) {
     case Wischer_Sensor_Box_fi_IN_Phase1:
      Wischer_Sensor_Box_final_B.SM_A = true;
      Wischer_Sensor_Box_final_B.SM_B = false;
      Wischer_Sensor_Box_final_B.SM_C = false;
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* During 'Phase1': '<S46>:612' */
      /* '<S46>:611:1' sf_internal_predicateOutput = ... */
      /* '<S46>:611:1' after(StepTime,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
        /* Transition: '<S46>:611' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
          Wischer_Sensor_Box_fi_IN_Phase4;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase4': '<S46>:610' */
        /* '<S46>:610:1' SM_A=false */
        Wischer_Sensor_Box_final_B.SM_A = false;

        /* '<S46>:610:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:610:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:610:2' SM_D=true */
        Wischer_Sensor_Box_final_B.SM_D = true;

        /* '<S46>:610:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:610:5' Steps = Steps - 1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      }
      break;

     case Wischer_Sensor_Box_fi_IN_Phase2:
      Wischer_Sensor_Box_final_B.SM_A = false;
      Wischer_Sensor_Box_final_B.SM_B = true;
      Wischer_Sensor_Box_final_B.SM_C = false;
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* During 'Phase2': '<S46>:604' */
      /* '<S46>:613:1' sf_internal_predicateOutput = ... */
      /* '<S46>:613:1' after(StepTime,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
        /* Transition: '<S46>:613' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
          Wischer_Sensor_Box_fi_IN_Phase1;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S46>:612' */
        /* '<S46>:612:1' SM_A=true */
        Wischer_Sensor_Box_final_B.SM_A = true;

        /* '<S46>:612:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:612:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:612:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:612:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:612:5' Steps = Steps -1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      }
      break;

     case Wischer_Sensor_Box_fi_IN_Phase3:
      Wischer_Sensor_Box_final_B.SM_A = false;
      Wischer_Sensor_Box_final_B.SM_B = false;
      Wischer_Sensor_Box_final_B.SM_C = true;
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* During 'Phase3': '<S46>:609' */
      /* '<S46>:603:1' sf_internal_predicateOutput = ... */
      /* '<S46>:603:1' after(StepTime,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
        /* Transition: '<S46>:603' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
          Wischer_Sensor_Box_fi_IN_Phase2;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase2': '<S46>:604' */
        /* '<S46>:604:1' SM_A=false */
        Wischer_Sensor_Box_final_B.SM_A = false;

        /* '<S46>:604:1' SM_B=true */
        Wischer_Sensor_Box_final_B.SM_B = true;

        /* '<S46>:604:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:604:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:604:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:604:5' Steps = Steps - 1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      }
      break;

     default:
      Wischer_Sensor_Box_final_B.SM_A = false;
      Wischer_Sensor_Box_final_B.SM_B = false;
      Wischer_Sensor_Box_final_B.SM_C = false;
      Wischer_Sensor_Box_final_B.SM_D = true;

      /* During 'Phase4': '<S46>:610' */
      /* '<S46>:614:1' sf_internal_predicateOutput = ... */
      /* '<S46>:614:1' after(StepTime,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
        /* Transition: '<S46>:614' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
          Wischer_Sensor_Box_fi_IN_Phase3;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase3': '<S46>:609' */
        /* '<S46>:609:1' SM_A=false */
        Wischer_Sensor_Box_final_B.SM_A = false;

        /* '<S46>:609:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:609:1' SM_C=true */
        Wischer_Sensor_Box_final_B.SM_C = true;

        /* '<S46>:609:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:609:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:609:5' Steps = Steps - 1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      }
      break;
    }
  }
}

/* Function for Chart: '<S4>/WischerSteuerung' */
static void Wischer__exit_internal_Wischer1(void)
{
  /* Exit Internal 'Wischer1': '<S46>:651' */
  /* Exit Internal 'Wischer_Rueck': '<S46>:669' */
  Wischer_Sensor_Box_final_DW.is_Wischer_Rueck = Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'Wischer_Vor': '<S46>:652' */
  Wischer_Sensor_Box_final_DW.is_Wischer_Vor = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sens_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S4>/WischerSteuerung' */
static void Wischer_Sensor_Box_fin_Wischer1(const uint8_T *Compare, const
  uint8_T *Compare_h, const uint8_T *Compare_l, uint8_T *Compare_m, uint8_T
  *Compare_d, boolean_T *WischWasch)
{
  /* During 'Wischer1': '<S46>:651' */
  /* '<S46>:650:1' sf_internal_predicateOutput = ... */
  /* '<S46>:650:1' WischWasch==1 &&Steps==0; */
  if ((*WischWasch) && (Wischer_Sensor_Box_final_DW.Steps == 0.0)) {
    /* Transition: '<S46>:650' */
    Wischer__exit_internal_Wischer1();
    Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
      Wischer_Sensor_Box__IN_Spruehen;
    Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

    /* Entry 'Spruehen': '<S46>:635' */
    /* '<S46>:635:1' WW_LED=true */
    Wischer_Sensor_Box_final_B.WW_LED = true;

    /* '<S46>:635:1' WischWaschCount=2 */
    Wischer_Sensor_Box_final_DW.WischWaschCount = 2U;

    /* '<S46>:635:1' StepTime=1/33 */
    Wischer_Sensor_Box_final_DW.StepTime = 0.030303030303030304;
  } else {
    switch (Wischer_Sensor_Box_final_DW.is_Wischer1) {
     case Wischer_Se_IN_INTERVALL_LANGSAM:
      /* During 'INTERVALL_LANGSAM': '<S46>:665' */
      /* Transition: '<S46>:607' */
      Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_B_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S46>:652' */
      /* Transition: '<S46>:653' */
      Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
        Wischer_Sensor_Box_fi_IN_Phase1;
      Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S46>:659' */
      /* '<S46>:659:1' SM_A=true */
      Wischer_Sensor_Box_final_B.SM_A = true;

      /* '<S46>:659:1' SM_B=false */
      Wischer_Sensor_Box_final_B.SM_B = false;

      /* '<S46>:659:1' SM_C=false */
      Wischer_Sensor_Box_final_B.SM_C = false;

      /* '<S46>:659:1' SM_D=false */
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* '<S46>:659:3' WW_LED=false */
      Wischer_Sensor_Box_final_B.WW_LED = false;

      /* '<S46>:659:5' Steps = Steps + 1; */
      Wischer_Sensor_Box_final_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM1:
      /* During 'INTERVALL_LANGSAM1': '<S46>:668' */
      /* Transition: '<S46>:602' */
      Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_B_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S46>:652' */
      /* Transition: '<S46>:653' */
      Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
        Wischer_Sensor_Box_fi_IN_Phase1;
      Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S46>:659' */
      /* '<S46>:659:1' SM_A=true */
      Wischer_Sensor_Box_final_B.SM_A = true;

      /* '<S46>:659:1' SM_B=false */
      Wischer_Sensor_Box_final_B.SM_B = false;

      /* '<S46>:659:1' SM_C=false */
      Wischer_Sensor_Box_final_B.SM_C = false;

      /* '<S46>:659:1' SM_D=false */
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* '<S46>:659:3' WW_LED=false */
      Wischer_Sensor_Box_final_B.WW_LED = false;

      /* '<S46>:659:5' Steps = Steps + 1; */
      Wischer_Sensor_Box_final_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM2:
      /* During 'INTERVALL_LANGSAM2': '<S46>:666' */
      /* Transition: '<S46>:640' */
      Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_B_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S46>:652' */
      /* Transition: '<S46>:653' */
      Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
        Wischer_Sensor_Box_fi_IN_Phase1;
      Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S46>:659' */
      /* '<S46>:659:1' SM_A=true */
      Wischer_Sensor_Box_final_B.SM_A = true;

      /* '<S46>:659:1' SM_B=false */
      Wischer_Sensor_Box_final_B.SM_B = false;

      /* '<S46>:659:1' SM_C=false */
      Wischer_Sensor_Box_final_B.SM_C = false;

      /* '<S46>:659:1' SM_D=false */
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* '<S46>:659:3' WW_LED=false */
      Wischer_Sensor_Box_final_B.WW_LED = false;

      /* '<S46>:659:5' Steps = Steps + 1; */
      Wischer_Sensor_Box_final_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM3:
      /* During 'INTERVALL_LANGSAM3': '<S46>:667' */
      /* Transition: '<S46>:618' */
      Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_B_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S46>:652' */
      /* Transition: '<S46>:653' */
      Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
        Wischer_Sensor_Box_fi_IN_Phase1;
      Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S46>:659' */
      /* '<S46>:659:1' SM_A=true */
      Wischer_Sensor_Box_final_B.SM_A = true;

      /* '<S46>:659:1' SM_B=false */
      Wischer_Sensor_Box_final_B.SM_B = false;

      /* '<S46>:659:1' SM_C=false */
      Wischer_Sensor_Box_final_B.SM_C = false;

      /* '<S46>:659:1' SM_D=false */
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* '<S46>:659:3' WW_LED=false */
      Wischer_Sensor_Box_final_B.WW_LED = false;

      /* '<S46>:659:5' Steps = Steps + 1; */
      Wischer_Sensor_Box_final_DW.Steps++;
      break;

     case Wischer_Sensor_Box__IN_Stufe_0_:
      Wischer_Sensor_Box_final_B.SM_A = false;
      Wischer_Sensor_Box_final_B.SM_B = false;
      Wischer_Sensor_Box_final_B.SM_C = false;
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* During 'Stufe_0_': '<S46>:663' */
      /* '<S46>:615:1' sf_internal_predicateOutput = ... */
      /* '<S46>:615:1' Wischer_Tipp==1; */
      if (*Compare == 1) {
        /* Transition: '<S46>:615' */
        Wischer_Sensor_Box_final_DW.is_Wischer1 =
          Wischer_Sensor_Box_fina_IN_TIPP;

        /* Entry 'TIPP': '<S46>:664' */
        /* '<S46>:664:1' StepTime=0.0303; */
        Wischer_Sensor_Box_final_DW.StepTime = 0.0303;

        /* '<S46>:664:1' StepTime1=1; */
        /* '<S46>:664:1' BreakTime=1; */
        Wischer_Sensor_Box_final_DW.BreakTime = 1.0;
      } else {
        /* '<S46>:601:1' sf_internal_predicateOutput = ... */
        /* '<S46>:601:1' Wischer_Intervall_I==1; */
        if (*Compare_h == 1) {
          /* Transition: '<S46>:601' */
          Wischer_Sensor_Box_final_DW.is_Wischer1 =
            Wischer_Se_IN_INTERVALL_LANGSAM;

          /* Entry 'INTERVALL_LANGSAM': '<S46>:665' */
          /* '<S46>:665:1' StepTime=0.0303; */
          Wischer_Sensor_Box_final_DW.StepTime = 0.0303;

          /* '<S46>:665:1' StepTime1=1; */
          /* '<S46>:665:1' BreakTime=4; */
          Wischer_Sensor_Box_final_DW.BreakTime = 4.0;
        } else {
          /* '<S46>:631:1' sf_internal_predicateOutput = ... */
          /* '<S46>:631:1' Wischer_Dauer_I==1; */
          if (*Compare_m == 1) {
            /* Transition: '<S46>:631' */
            Wischer_Sensor_Box_final_DW.is_Wischer1 =
              Wischer_S_IN_INTERVALL_LANGSAM2;

            /* Entry 'INTERVALL_LANGSAM2': '<S46>:666' */
            /* '<S46>:666:1' StepTime=0.0303; */
            Wischer_Sensor_Box_final_DW.StepTime = 0.0303;

            /* '<S46>:666:1' StepTime1=1; */
            /* '<S46>:666:1' BreakTime=0; */
            Wischer_Sensor_Box_final_DW.BreakTime = 0.0;
          } else {
            /* '<S46>:617:1' sf_internal_predicateOutput = ... */
            /* '<S46>:617:1' Wischer_Dauer_II==1; */
            if (*Compare_d == 1) {
              /* Transition: '<S46>:617' */
              Wischer_Sensor_Box_final_DW.is_Wischer1 =
                Wischer_S_IN_INTERVALL_LANGSAM3;

              /* Entry 'INTERVALL_LANGSAM3': '<S46>:667' */
              /* '<S46>:667:1' StepTime=0.015015; */
              Wischer_Sensor_Box_final_DW.StepTime = 0.015015;

              /* '<S46>:667:1' StepTime1=0.5; */
              /* '<S46>:667:2' BreakTime=0; */
              Wischer_Sensor_Box_final_DW.BreakTime = 0.0;
            } else {
              /* '<S46>:608:1' sf_internal_predicateOutput = ... */
              /* '<S46>:608:1' Wischer_Intervall_II==1; */
              if (*Compare_l == 1) {
                /* Transition: '<S46>:608' */
                Wischer_Sensor_Box_final_DW.is_Wischer1 =
                  Wischer_S_IN_INTERVALL_LANGSAM1;

                /* Entry 'INTERVALL_LANGSAM1': '<S46>:668' */
                /* '<S46>:668:1' StepTime=0.0303; */
                Wischer_Sensor_Box_final_DW.StepTime = 0.0303;

                /* '<S46>:668:1' StepTime1=1; */
                /* '<S46>:668:1' BreakTime=2; */
                Wischer_Sensor_Box_final_DW.BreakTime = 2.0;
              }
            }
          }
        }
      }
      break;

     case Wischer_Sensor_Box_fina_IN_TIPP:
      /* During 'TIPP': '<S46>:664' */
      /* Transition: '<S46>:616' */
      Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_B_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S46>:652' */
      /* Transition: '<S46>:653' */
      Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
        Wischer_Sensor_Box_fi_IN_Phase1;
      Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S46>:659' */
      /* '<S46>:659:1' SM_A=true */
      Wischer_Sensor_Box_final_B.SM_A = true;

      /* '<S46>:659:1' SM_B=false */
      Wischer_Sensor_Box_final_B.SM_B = false;

      /* '<S46>:659:1' SM_C=false */
      Wischer_Sensor_Box_final_B.SM_C = false;

      /* '<S46>:659:1' SM_D=false */
      Wischer_Sensor_Box_final_B.SM_D = false;

      /* '<S46>:659:3' WW_LED=false */
      Wischer_Sensor_Box_final_B.WW_LED = false;

      /* '<S46>:659:5' Steps = Steps + 1; */
      Wischer_Sensor_Box_final_DW.Steps++;
      break;

     case Wischer_Se_IN_WEIL_ICH_DUMM_BIN:
      /* During 'WEIL_ICH_DUMM_BIN': '<S46>:670' */
      /* '<S46>:647:1' sf_internal_predicateOutput = ... */
      /* '<S46>:647:1' after(BreakTime,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensor_Box_final_DW.BreakTime * 100.0)) {
        /* Transition: '<S46>:647' */
        Wischer_Sensor_Box_final_DW.is_Wischer1 =
          Wischer_Sensor_Box__IN_Stufe_0_;

        /* Entry 'Stufe_0_': '<S46>:663' */
        /* '<S46>:663:1' SM_A=false */
        Wischer_Sensor_Box_final_B.SM_A = false;

        /* '<S46>:663:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:663:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:663:2' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:663:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:663:5' Steps=0 */
        Wischer_Sensor_Box_final_DW.Steps = 0.0;

        /* '<S46>:663:5' WischWaschCount=0 */
        Wischer_Sensor_Box_final_DW.WischWaschCount = 0U;
      }
      break;

     case Wischer_Sensor_IN_Wischer_Rueck:
      Wischer_Sensor_Bo_Wischer_Rueck();
      break;

     default:
      /* During 'Wischer_Vor': '<S46>:652' */
      /* '<S46>:619:1' sf_internal_predicateOutput = ... */
      /* '<S46>:619:1' Steps==23; */
      if (Wischer_Sensor_Box_final_DW.Steps == 23.0) {
        /* Transition: '<S46>:619' */
        /* Exit Internal 'Wischer_Vor': '<S46>:652' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
          Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensor_Box_final_DW.is_Wischer1 =
          Wischer_Sensor_IN_Wischer_Rueck;

        /* Entry Internal 'Wischer_Rueck': '<S46>:669' */
        /* Transition: '<S46>:606' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck =
          Wischer_Sensor_Box_fi_IN_Phase4;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase4': '<S46>:610' */
        /* '<S46>:610:1' SM_A=false */
        Wischer_Sensor_Box_final_B.SM_A = false;

        /* '<S46>:610:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:610:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:610:2' SM_D=true */
        Wischer_Sensor_Box_final_B.SM_D = true;

        /* '<S46>:610:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:610:5' Steps = Steps - 1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      } else {
        switch (Wischer_Sensor_Box_final_DW.is_Wischer_Vor) {
         case Wischer_Sensor_Box_fi_IN_Phase1:
          Wischer_Sensor_Box_final_B.SM_A = true;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase1': '<S46>:659' */
          /* '<S46>:655:1' sf_internal_predicateOutput = ... */
          /* '<S46>:655:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:655' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
              Wischer_Sensor_Box_fi_IN_Phase2;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase2': '<S46>:660' */
            /* '<S46>:660:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:660:1' SM_B=true */
            Wischer_Sensor_Box_final_B.SM_B = true;

            /* '<S46>:660:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:660:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:660:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:660:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         case Wischer_Sensor_Box_fi_IN_Phase2:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = true;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase2': '<S46>:660' */
          /* '<S46>:657:1' sf_internal_predicateOutput = ... */
          /* '<S46>:657:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:657' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
              Wischer_Sensor_Box_fi_IN_Phase3;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase3': '<S46>:661' */
            /* '<S46>:661:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:661:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:661:1' SM_C=true */
            Wischer_Sensor_Box_final_B.SM_C = true;

            /* '<S46>:661:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:661:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:661:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         case Wischer_Sensor_Box_fi_IN_Phase3:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = true;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase3': '<S46>:661' */
          /* '<S46>:656:1' sf_internal_predicateOutput = ... */
          /* '<S46>:656:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:656' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
              Wischer_Sensor_Box_fi_IN_Phase4;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase4': '<S46>:658' */
            /* '<S46>:658:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:658:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:658:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:658:2' SM_D=true */
            Wischer_Sensor_Box_final_B.SM_D = true;

            /* '<S46>:658:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:658:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         default:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = true;

          /* During 'Phase4': '<S46>:658' */
          /* '<S46>:654:1' sf_internal_predicateOutput = ... */
          /* '<S46>:654:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:654' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor =
              Wischer_Sensor_Box_fi_IN_Phase1;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase1': '<S46>:659' */
            /* '<S46>:659:1' SM_A=true */
            Wischer_Sensor_Box_final_B.SM_A = true;

            /* '<S46>:659:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:659:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:659:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:659:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:659:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;
        }
      }
      break;
    }
  }
}

/* Model step function */
void Wischer_Sensor_Box_final_step(void)
{
  int16_T rtb_DataTypeConversion;
  int16_T rtb_y_bd;
  uint8_T Compare;
  uint8_T Compare_h;
  uint8_T Compare_l;
  uint8_T Compare_m;
  uint8_T Compare_d;
  boolean_T WischWasch;
  int32_T tmp;
  uint32_T qY;

  /* S-Function (stm32f4_can): '<S1>/CAN Receive' */

  /* CANReceive: '<S1>/CAN Receive' */
  Wischer_Sensor_Box_final_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  Wischer_Sensor_Box_final_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  Wischer_Sensor_Box_final_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint16 */

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  rtb_DataTypeConversion = (int16_T)Wischer_Sensor_Box_final_B.CANReceive_o3;

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift3' */
  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift6' */
  /* MATLAB Function: '<S16>/bit_shift' incorporates:
   *  MATLAB Function: '<S19>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S35>:1' */
  /* '<S35>:1:4' switch mode */
  /* '<S35>:1:5' case 1 */
  /* '<S35>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S32>:1' */
  /* '<S32>:1:4' switch mode */
  /* '<S32>:1:7' case 2 */
  /* '<S32>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_y_bd = (int16_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion << 13) >> 13);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift6' */
  /* End of Outputs for SubSystem: '<S6>/Bit Shift3' */

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  Compare = (uint8_T)(rtb_y_bd == 1);

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   */
  Compare_h = (uint8_T)(rtb_y_bd == 2);

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   */
  Compare_l = (uint8_T)(rtb_y_bd == 3);

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   */
  Compare_m = (uint8_T)(rtb_y_bd == 4);

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  Compare_d = (uint8_T)(rtb_y_bd == 5);

  /* S-Function (stm32f4_can): '<S1>/CAN Receive1' */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S37>:1' */
  /* '<S37>:1:4' switch mode */
  /* '<S37>:1:5' case 1 */
  /* '<S37>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S36>:1' */
  /* '<S36>:1:4' switch mode */
  /* '<S36>:1:7' case 2 */
  /* '<S36>:1:8' y = bitsrl(cast_to_fi(u), N); */

  /* CANReceive1: '<S1>/CAN Receive1' */
  Wischer_Sensor_Box_final_B.CANReceive1_o1 = CANReceive1_GetMsg
    (&CANReceive1_Msg);                /* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  Wischer_Sensor_Box_final_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  Wischer_Sensor_Box_final_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift7' */
  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift8' */
  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift4' */
  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S41>/Constant'
   *  MATLAB Function: '<S20>/bit_shift'
   *  MATLAB Function: '<S21>/bit_shift'
   *  MATLAB Function: '<S38>/bit_shift'
   *  MATLAB Function: '<S39>/bit_shift'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S41>/Compare'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S42>:1' */
  /* '<S42>:1:4' switch mode */
  /* '<S42>:1:5' case 1 */
  /* '<S42>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S43>:1' */
  /* '<S43>:1:4' switch mode */
  /* '<S43>:1:7' case 2 */
  /* '<S43>:1:8' y = bitsrl(cast_to_fi(u), N); */
  WischWasch = (((int32_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion << 12) >>
    15) == 1) && ((int32_T)((uint32_T)(uint8_T)
    (Wischer_Sensor_Box_final_B.CANReceive1_o3 << 7) >> 7) == 1));

  /* End of Outputs for SubSystem: '<S7>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S7>/Bit Shift5' */
  /* End of Outputs for SubSystem: '<S6>/Bit Shift8' */
  /* End of Outputs for SubSystem: '<S6>/Bit Shift7' */

  /* Chart: '<S4>/WischerSteuerung' */
  if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 < MAX_uint32_T) {
    Wischer_Sensor_Box_final_DW.temporalCounter_i1++;
  }

  /* Gateway: Verarbeitung/WischerSteuerung */
  /* During: Verarbeitung/WischerSteuerung */
  if (Wischer_Sensor_Box_final_DW.is_active_c2_Wischer_Sensor_Box == 0U) {
    /* Entry: Verarbeitung/WischerSteuerung */
    Wischer_Sensor_Box_final_DW.is_active_c2_Wischer_Sensor_Box = 1U;

    /* Entry Internal: Verarbeitung/WischerSteuerung */
    /* Transition: '<S46>:649' */
    Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
      Wischer_Sensor_Box__IN_Wischer1;

    /* Entry Internal 'Wischer1': '<S46>:651' */
    /* Transition: '<S46>:605' */
    Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sensor_Box__IN_Stufe_0_;

    /* Entry 'Stufe_0_': '<S46>:663' */
    /* '<S46>:663:1' SM_A=false */
    Wischer_Sensor_Box_final_B.SM_A = false;

    /* '<S46>:663:1' SM_B=false */
    Wischer_Sensor_Box_final_B.SM_B = false;

    /* '<S46>:663:1' SM_C=false */
    Wischer_Sensor_Box_final_B.SM_C = false;

    /* '<S46>:663:2' SM_D=false */
    Wischer_Sensor_Box_final_B.SM_D = false;

    /* '<S46>:663:3' WW_LED=false */
    Wischer_Sensor_Box_final_B.WW_LED = false;

    /* '<S46>:663:5' Steps=0 */
    Wischer_Sensor_Box_final_DW.Steps = 0.0;

    /* '<S46>:663:5' WischWaschCount=0 */
    Wischer_Sensor_Box_final_DW.WischWaschCount = 0U;
  } else {
    switch (Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final) {
     case Wischer_Sensor_Box__IN_Spruehen:
      /* During 'Spruehen': '<S46>:635' */
      /* '<S46>:643:1' sf_internal_predicateOutput = ... */
      /* '<S46>:643:1' after(2,sec); */
      if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= 200U) {
        /* Transition: '<S46>:643' */
        /* Exit 'Spruehen': '<S46>:635' */
        /* '<S46>:635:2' WW_LED=false */
        Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
          Wischer_Senso_IN_Wischer_Vor_WW;

        /* Entry Internal 'Wischer_Vor_WW': '<S46>:620' */
        /* Transition: '<S46>:621' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
          Wischer_Sensor_Box_fi_IN_Phase1;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S46>:627' */
        /* '<S46>:627:1' SM_A=true */
        Wischer_Sensor_Box_final_B.SM_A = true;

        /* '<S46>:627:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:627:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:627:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:627:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:627:5' Steps = Steps + 1; */
        Wischer_Sensor_Box_final_DW.Steps++;
      }
      break;

     case Wischer_Sen_IN_Wischer_Rueck_WW:
      /* During 'Wischer_Rueck_WW': '<S46>:641' */
      /* '<S46>:639:1' sf_internal_predicateOutput = ... */
      /* '<S46>:639:1' Steps==0&&WischWaschCount>0; */
      if ((Wischer_Sensor_Box_final_DW.Steps == 0.0) &&
          (Wischer_Sensor_Box_final_DW.WischWaschCount > 0)) {
        /* Transition: '<S46>:639' */
        /* '<S46>:639:1' WischWaschCount = WischWaschCount - 1 */
        qY = Wischer_Sensor_Box_final_DW.WischWaschCount - /*MW:OvSatOk*/ 1U;
        if (qY > Wischer_Sensor_Box_final_DW.WischWaschCount) {
          qY = 0U;
        }

        Wischer_Sensor_Box_final_DW.WischWaschCount = (uint8_T)qY;

        /* Exit Internal 'Wischer_Rueck_WW': '<S46>:641' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
          Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
          Wischer_Senso_IN_Wischer_Vor_WW;

        /* Entry Internal 'Wischer_Vor_WW': '<S46>:620' */
        /* Transition: '<S46>:621' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
          Wischer_Sensor_Box_fi_IN_Phase1;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S46>:627' */
        /* '<S46>:627:1' SM_A=true */
        Wischer_Sensor_Box_final_B.SM_A = true;

        /* '<S46>:627:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:627:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:627:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:627:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:627:5' Steps = Steps + 1; */
        Wischer_Sensor_Box_final_DW.Steps++;
      } else {
        /* '<S46>:648:1' sf_internal_predicateOutput = ... */
        /* '<S46>:648:1' WischWaschCount==0&&Steps==0; */
        if ((Wischer_Sensor_Box_final_DW.WischWaschCount == 0) &&
            (Wischer_Sensor_Box_final_DW.Steps == 0.0)) {
          /* Transition: '<S46>:648' */
          /* Exit Internal 'Wischer_Rueck_WW': '<S46>:641' */
          Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
            Wischer_Sens_IN_NO_ACTIVE_CHILD;
          Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
            Wischer_Sensor_Box__IN_Wischer1;

          /* Entry Internal 'Wischer1': '<S46>:651' */
          /* Transition: '<S46>:605' */
          Wischer_Sensor_Box_final_DW.is_Wischer1 =
            Wischer_Sensor_Box__IN_Stufe_0_;

          /* Entry 'Stufe_0_': '<S46>:663' */
          /* '<S46>:663:1' SM_A=false */
          Wischer_Sensor_Box_final_B.SM_A = false;

          /* '<S46>:663:1' SM_B=false */
          Wischer_Sensor_Box_final_B.SM_B = false;

          /* '<S46>:663:1' SM_C=false */
          Wischer_Sensor_Box_final_B.SM_C = false;

          /* '<S46>:663:2' SM_D=false */
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* '<S46>:663:3' WW_LED=false */
          Wischer_Sensor_Box_final_B.WW_LED = false;

          /* '<S46>:663:5' Steps=0 */
          Wischer_Sensor_Box_final_DW.Steps = 0.0;

          /* '<S46>:663:5' WischWaschCount=0 */
          Wischer_Sensor_Box_final_DW.WischWaschCount = 0U;
        } else {
          switch (Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW) {
           case Wischer_Sensor_Box_fi_IN_Phase1:
            Wischer_Sensor_Box_final_B.SM_A = true;
            Wischer_Sensor_Box_final_B.SM_B = false;
            Wischer_Sensor_Box_final_B.SM_C = false;
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* During 'Phase1': '<S46>:630' */
            /* '<S46>:645:1' sf_internal_predicateOutput = ... */
            /* '<S46>:645:1' after(StepTime,sec); */
            if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
              /* Transition: '<S46>:645' */
              Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
                Wischer_Sensor_Box_fi_IN_Phase4;
              Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase4': '<S46>:644' */
              /* '<S46>:644:1' SM_A=false */
              Wischer_Sensor_Box_final_B.SM_A = false;

              /* '<S46>:644:1' SM_B=false */
              Wischer_Sensor_Box_final_B.SM_B = false;

              /* '<S46>:644:1' SM_C=false */
              Wischer_Sensor_Box_final_B.SM_C = false;

              /* '<S46>:644:2' SM_D=true */
              Wischer_Sensor_Box_final_B.SM_D = true;

              /* '<S46>:644:3' WW_LED=false */
              Wischer_Sensor_Box_final_B.WW_LED = false;

              /* '<S46>:644:5' Steps = Steps - 1; */
              Wischer_Sensor_Box_final_DW.Steps--;
            }
            break;

           case Wischer_Sensor_Box_fi_IN_Phase2:
            Wischer_Sensor_Box_final_B.SM_A = false;
            Wischer_Sensor_Box_final_B.SM_B = true;
            Wischer_Sensor_Box_final_B.SM_C = false;
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* During 'Phase2': '<S46>:632' */
            /* '<S46>:637:1' sf_internal_predicateOutput = ... */
            /* '<S46>:637:1' after(StepTime,sec); */
            if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
              /* Transition: '<S46>:637' */
              Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
                Wischer_Sensor_Box_fi_IN_Phase1;
              Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase1': '<S46>:630' */
              /* '<S46>:630:1' SM_A=true */
              Wischer_Sensor_Box_final_B.SM_A = true;

              /* '<S46>:630:1' SM_B=false */
              Wischer_Sensor_Box_final_B.SM_B = false;

              /* '<S46>:630:1' SM_C=false */
              Wischer_Sensor_Box_final_B.SM_C = false;

              /* '<S46>:630:1' SM_D=false */
              Wischer_Sensor_Box_final_B.SM_D = false;

              /* '<S46>:630:3' WW_LED=false */
              Wischer_Sensor_Box_final_B.WW_LED = false;

              /* '<S46>:630:5' Steps = Steps -1; */
              Wischer_Sensor_Box_final_DW.Steps--;
            }
            break;

           case Wischer_Sensor_Box_fi_IN_Phase3:
            Wischer_Sensor_Box_final_B.SM_A = false;
            Wischer_Sensor_Box_final_B.SM_B = false;
            Wischer_Sensor_Box_final_B.SM_C = true;
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* During 'Phase3': '<S46>:633' */
            /* '<S46>:638:1' sf_internal_predicateOutput = ... */
            /* '<S46>:638:1' after(StepTime,sec); */
            if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
              /* Transition: '<S46>:638' */
              Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
                Wischer_Sensor_Box_fi_IN_Phase2;
              Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase2': '<S46>:632' */
              /* '<S46>:632:1' SM_A=false */
              Wischer_Sensor_Box_final_B.SM_A = false;

              /* '<S46>:632:1' SM_B=true */
              Wischer_Sensor_Box_final_B.SM_B = true;

              /* '<S46>:632:1' SM_C=false */
              Wischer_Sensor_Box_final_B.SM_C = false;

              /* '<S46>:632:1' SM_D=false */
              Wischer_Sensor_Box_final_B.SM_D = false;

              /* '<S46>:632:3' WW_LED=false */
              Wischer_Sensor_Box_final_B.WW_LED = false;

              /* '<S46>:632:5' Steps = Steps - 1; */
              Wischer_Sensor_Box_final_DW.Steps--;
            }
            break;

           default:
            Wischer_Sensor_Box_final_B.SM_A = false;
            Wischer_Sensor_Box_final_B.SM_B = false;
            Wischer_Sensor_Box_final_B.SM_C = false;
            Wischer_Sensor_Box_final_B.SM_D = true;

            /* During 'Phase4': '<S46>:644' */
            /* '<S46>:636:1' sf_internal_predicateOutput = ... */
            /* '<S46>:636:1' after(StepTime,sec); */
            if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
              /* Transition: '<S46>:636' */
              Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
                Wischer_Sensor_Box_fi_IN_Phase3;
              Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase3': '<S46>:633' */
              /* '<S46>:633:1' SM_A=false */
              Wischer_Sensor_Box_final_B.SM_A = false;

              /* '<S46>:633:1' SM_B=false */
              Wischer_Sensor_Box_final_B.SM_B = false;

              /* '<S46>:633:1' SM_C=true */
              Wischer_Sensor_Box_final_B.SM_C = true;

              /* '<S46>:633:1' SM_D=false */
              Wischer_Sensor_Box_final_B.SM_D = false;

              /* '<S46>:633:3' WW_LED=false */
              Wischer_Sensor_Box_final_B.WW_LED = false;

              /* '<S46>:633:5' Steps = Steps - 1; */
              Wischer_Sensor_Box_final_DW.Steps--;
            }
            break;
          }
        }
      }
      break;

     case Wischer_Senso_IN_Wischer_Vor_WW:
      /* During 'Wischer_Vor_WW': '<S46>:620' */
      /* '<S46>:646:1' sf_internal_predicateOutput = ... */
      /* '<S46>:646:1' Steps==23; */
      if (Wischer_Sensor_Box_final_DW.Steps == 23.0) {
        /* Transition: '<S46>:646' */
        /* Exit Internal 'Wischer_Vor_WW': '<S46>:620' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
          Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
          Wischer_Sen_IN_Wischer_Rueck_WW;

        /* Entry Internal 'Wischer_Rueck_WW': '<S46>:641' */
        /* Transition: '<S46>:634' */
        Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
          Wischer_Sensor_Box_fi_IN_Phase1;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S46>:630' */
        /* '<S46>:630:1' SM_A=true */
        Wischer_Sensor_Box_final_B.SM_A = true;

        /* '<S46>:630:1' SM_B=false */
        Wischer_Sensor_Box_final_B.SM_B = false;

        /* '<S46>:630:1' SM_C=false */
        Wischer_Sensor_Box_final_B.SM_C = false;

        /* '<S46>:630:1' SM_D=false */
        Wischer_Sensor_Box_final_B.SM_D = false;

        /* '<S46>:630:3' WW_LED=false */
        Wischer_Sensor_Box_final_B.WW_LED = false;

        /* '<S46>:630:5' Steps = Steps -1; */
        Wischer_Sensor_Box_final_DW.Steps--;
      } else {
        switch (Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW) {
         case Wischer_Sensor_Box_fi_IN_Phase1:
          Wischer_Sensor_Box_final_B.SM_A = true;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase1': '<S46>:627' */
          /* '<S46>:623:1' sf_internal_predicateOutput = ... */
          /* '<S46>:623:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:623' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
              Wischer_Sensor_Box_fi_IN_Phase2;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase2': '<S46>:628' */
            /* '<S46>:628:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:628:1' SM_B=true */
            Wischer_Sensor_Box_final_B.SM_B = true;

            /* '<S46>:628:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:628:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:628:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:628:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         case Wischer_Sensor_Box_fi_IN_Phase2:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = true;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase2': '<S46>:628' */
          /* '<S46>:625:1' sf_internal_predicateOutput = ... */
          /* '<S46>:625:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:625' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
              Wischer_Sensor_Box_fi_IN_Phase3;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase3': '<S46>:629' */
            /* '<S46>:629:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:629:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:629:1' SM_C=true */
            Wischer_Sensor_Box_final_B.SM_C = true;

            /* '<S46>:629:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:629:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:629:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         case Wischer_Sensor_Box_fi_IN_Phase3:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = true;
          Wischer_Sensor_Box_final_B.SM_D = false;

          /* During 'Phase3': '<S46>:629' */
          /* '<S46>:624:1' sf_internal_predicateOutput = ... */
          /* '<S46>:624:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:624' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
              Wischer_Sensor_Box_fi_IN_Phase4;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase4': '<S46>:626' */
            /* '<S46>:626:1' SM_A=false */
            Wischer_Sensor_Box_final_B.SM_A = false;

            /* '<S46>:626:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:626:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:626:2' SM_D=true */
            Wischer_Sensor_Box_final_B.SM_D = true;

            /* '<S46>:626:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:626:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;

         default:
          Wischer_Sensor_Box_final_B.SM_A = false;
          Wischer_Sensor_Box_final_B.SM_B = false;
          Wischer_Sensor_Box_final_B.SM_C = false;
          Wischer_Sensor_Box_final_B.SM_D = true;

          /* During 'Phase4': '<S46>:626' */
          /* '<S46>:622:1' sf_internal_predicateOutput = ... */
          /* '<S46>:622:1' after(StepTime,sec); */
          if (Wischer_Sensor_Box_final_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensor_Box_final_DW.StepTime * 100.0)) {
            /* Transition: '<S46>:622' */
            Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
              Wischer_Sensor_Box_fi_IN_Phase1;
            Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase1': '<S46>:627' */
            /* '<S46>:627:1' SM_A=true */
            Wischer_Sensor_Box_final_B.SM_A = true;

            /* '<S46>:627:1' SM_B=false */
            Wischer_Sensor_Box_final_B.SM_B = false;

            /* '<S46>:627:1' SM_C=false */
            Wischer_Sensor_Box_final_B.SM_C = false;

            /* '<S46>:627:1' SM_D=false */
            Wischer_Sensor_Box_final_B.SM_D = false;

            /* '<S46>:627:3' WW_LED=false */
            Wischer_Sensor_Box_final_B.WW_LED = false;

            /* '<S46>:627:5' Steps = Steps + 1; */
            Wischer_Sensor_Box_final_DW.Steps++;
          }
          break;
        }
      }
      break;

     default:
      Wischer_Sensor_Box_fin_Wischer1(&Compare, &Compare_h, &Compare_l,
        &Compare_m, &Compare_d, &WischWasch);
      break;
    }
  }

  /* End of Chart: '<S4>/WischerSteuerung' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
  /* MATLAB Function: '<S18>/bit_shift' incorporates:
   *  MATLAB Function: '<S17>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S33>:1' */
  /* '<S33>:1:4' switch mode */
  /* '<S33>:1:5' case 1 */
  /* '<S33>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S34>:1' */
  /* '<S34>:1:4' switch mode */
  /* '<S34>:1:7' case 2 */
  /* '<S34>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_y_bd = (int16_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion << 10) >> 14);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S6>/Bit Shift5' */

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   */
  Compare = (uint8_T)(rtb_y_bd == 2);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   */
  Compare_h = (uint8_T)(rtb_y_bd == 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift1' */
  /* Bias: '<S6>/Bias' incorporates:
   *  MATLAB Function: '<S14>/bit_shift'
   *  MATLAB Function: '<S15>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S30>:1' */
  /* '<S30>:1:4' switch mode */
  /* '<S30>:1:5' case 1 */
  /* '<S30>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S31>:1' */
  /* '<S31>:1:4' switch mode */
  /* '<S31>:1:7' case 2 */
  /* '<S31>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_DataTypeConversion = (int16_T)((int32_T)((uint32_T)(uint16_T)
    (rtb_DataTypeConversion << 3) >> 9) - 40);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift1' */
  /* End of Outputs for SubSystem: '<S6>/Bit Shift2' */

  /* Chart: '<S4>/ScheibenheizungsSteuerung' */
  if (Wischer_Sensor_Box_final_DW.temporalCounter_i1_j < 4095U) {
    Wischer_Sensor_Box_final_DW.temporalCounter_i1_j++;
  }

  /* Gateway: Verarbeitung/ScheibenheizungsSteuerung */
  /* During: Verarbeitung/ScheibenheizungsSteuerung */
  if (Wischer_Sensor_Box_final_DW.is_active_c1_Wischer_Sensor_Box == 0U) {
    /* Entry: Verarbeitung/ScheibenheizungsSteuerung */
    Wischer_Sensor_Box_final_DW.is_active_c1_Wischer_Sensor_Box = 1U;

    /* Entry Internal: Verarbeitung/ScheibenheizungsSteuerung */
    /* Transition: '<S45>:25' */
    Wischer_Sensor_Box_final_DW.is_c1_Wischer_Sensor_Box_final =
      Wischer_Sensor_Box_f_IN_MANUELL;

    /* Entry Internal 'MANUELL': '<S45>:24' */
    /* Transition: '<S45>:50' */
    Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sensor_Box_final_IN_OFF;

    /* Entry 'OFF': '<S45>:39' */
    /* '<S45>:39:1' SH_LED=false */
    Wischer_Sensor_Box_final_B.SH_LED = false;
  } else if (Wischer_Sensor_Box_final_DW.is_c1_Wischer_Sensor_Box_final ==
             Wischer_Sensor_Box_fina_IN_AUTO) {
    /* During 'AUTO': '<S45>:56' */
    /* '<S45>:58:1' sf_internal_predicateOutput = ... */
    /* '<S45>:58:1' Scheibenheizung_Auto==0; */
    if (Compare_h == 0) {
      /* Transition: '<S45>:58' */
      /* Exit Internal 'AUTO': '<S45>:56' */
      Wischer_Sensor_Box_final_DW.is_AUTO = Wischer_Sens_IN_NO_ACTIVE_CHILD;
      Wischer_Sensor_Box_final_DW.is_c1_Wischer_Sensor_Box_final =
        Wischer_Sensor_Box_f_IN_MANUELL;

      /* Entry Internal 'MANUELL': '<S45>:24' */
      /* Transition: '<S45>:50' */
      Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sensor_Box_final_IN_OFF;

      /* Entry 'OFF': '<S45>:39' */
      /* '<S45>:39:1' SH_LED=false */
      Wischer_Sensor_Box_final_B.SH_LED = false;
    } else if (Wischer_Sensor_Box_final_DW.is_AUTO ==
               Wischer_Sensor_Box_final_IN_OFF) {
      Wischer_Sensor_Box_final_B.SH_LED = false;

      /* During 'OFF': '<S45>:54' */
      /* '<S45>:53:1' sf_internal_predicateOutput = ... */
      /* '<S45>:53:1' Temperatur<2; */
      if (rtb_DataTypeConversion < 2) {
        /* Transition: '<S45>:53' */
        Wischer_Sensor_Box_final_DW.is_AUTO = Wischer_Sensor_Box_final_IN_ON;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1_j = 0U;

        /* Entry 'ON': '<S45>:55' */
        /* '<S45>:55:1' SH_LED=true */
        Wischer_Sensor_Box_final_B.SH_LED = true;
      }
    } else {
      Wischer_Sensor_Box_final_B.SH_LED = true;

      /* During 'ON': '<S45>:55' */
      /* '<S45>:51:1' sf_internal_predicateOutput = ... */
      /* '<S45>:51:1' after(30,sec) || Temperatur>=2; */
      if ((Wischer_Sensor_Box_final_DW.temporalCounter_i1_j >= 3000U) ||
          (rtb_DataTypeConversion >= 2)) {
        /* Transition: '<S45>:51' */
        Wischer_Sensor_Box_final_DW.is_AUTO = Wischer_Sensor_Box_final_IN_OFF;

        /* Entry 'OFF': '<S45>:54' */
        /* '<S45>:54:1' SH_LED=false */
        Wischer_Sensor_Box_final_B.SH_LED = false;
      }
    }
  } else {
    /* During 'MANUELL': '<S45>:24' */
    /* '<S45>:57:1' sf_internal_predicateOutput = ... */
    /* '<S45>:57:1' Scheibenheizung_Auto==1; */
    if (Compare_h == 1) {
      /* Transition: '<S45>:57' */
      /* Exit Internal 'MANUELL': '<S45>:24' */
      Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sens_IN_NO_ACTIVE_CHILD;
      Wischer_Sensor_Box_final_DW.is_c1_Wischer_Sensor_Box_final =
        Wischer_Sensor_Box_fina_IN_AUTO;

      /* Entry Internal 'AUTO': '<S45>:56' */
      /* Transition: '<S45>:52' */
      Wischer_Sensor_Box_final_DW.is_AUTO = Wischer_Sensor_Box_final_IN_OFF;

      /* Entry 'OFF': '<S45>:54' */
      /* '<S45>:54:1' SH_LED=false */
      Wischer_Sensor_Box_final_B.SH_LED = false;
    } else if (Wischer_Sensor_Box_final_DW.is_MANUELL ==
               Wischer_Sensor_Box_final_IN_OFF) {
      Wischer_Sensor_Box_final_B.SH_LED = false;

      /* During 'OFF': '<S45>:39' */
      /* '<S45>:41:1' sf_internal_predicateOutput = ... */
      /* '<S45>:41:1' Scheibenheizung==1; */
      if (Compare == 1) {
        /* Transition: '<S45>:41' */
        Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sensor_Box_final_IN_ON;
        Wischer_Sensor_Box_final_DW.temporalCounter_i1_j = 0U;

        /* Entry 'ON': '<S45>:37' */
        /* '<S45>:37:1' SH_LED=true */
        Wischer_Sensor_Box_final_B.SH_LED = true;
      }
    } else {
      Wischer_Sensor_Box_final_B.SH_LED = true;

      /* During 'ON': '<S45>:37' */
      /* '<S45>:40:1' sf_internal_predicateOutput = ... */
      /* '<S45>:40:1' after(30,sec) || Scheibenheizung==0; */
      if ((Wischer_Sensor_Box_final_DW.temporalCounter_i1_j >= 3000U) ||
          (Compare == 0)) {
        /* Transition: '<S45>:40' */
        Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sensor_Box_final_IN_OFF;

        /* Entry 'OFF': '<S45>:39' */
        /* '<S45>:39:1' SH_LED=false */
        Wischer_Sensor_Box_final_B.SH_LED = false;
      }
    }
  }

  /* End of Chart: '<S4>/ScheibenheizungsSteuerung' */

  /* S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* OutputDigitalOutput */
  {
    *OutputDigitalOutput_C0 = Wischer_Sensor_Box_final_B.SM_A;
    *OutputDigitalOutput_C1 = Wischer_Sensor_Box_final_B.SM_B;
    *OutputDigitalOutput_C2 = Wischer_Sensor_Box_final_B.SM_C;
    *OutputDigitalOutput_C3 = Wischer_Sensor_Box_final_B.SM_D;
    *OutputDigitalOutput_C4 = Wischer_Sensor_Box_final_B.SH_LED;
    *OutputDigitalOutput_C5 = Wischer_Sensor_Box_final_B.WW_LED;
  }

  /* S-Function (stm32f4_digital_input): '<S1>/Digital Input1' */
  Wischer_Sensor_Box_final_B.DigitalInput1 = *InputDigitalInput1_C6;

  /* S-Function (stm32f4_regular_adc): '<S1>/Regular ADC' */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S12>:1' */
  /* '<S12>:1:4' switch mode */
  /* '<S12>:1:5' case 1 */
  /* '<S12>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S13>:1' */
  /* '<S13>:1:4' switch mode */
  /* '<S13>:1:7' case 2 */
  /* '<S13>:1:8' y = bitsrl(cast_to_fi(u), N); */

  /* ADC Block */
  RegularADCStartConversion();
  Wischer_Sensor_Box_final_B.RegularADC = (uint16_T)RegularADC_ConvertedValue[0];

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  tmp = (int32_T)fmod((int32_T)floor(500.0 - (32776.0 * (real_T)
    Wischer_Sensor_Box_final_B.RegularADC * 7.4505805969238281E-9 - 0.06) * 2.98
    * 167.0), 65536.0);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift4' */
  /* S-Function (sfix_bitop): '<S5>/Bitwise Operator3' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion8'
   *  Gain: '<S5>/Gain9'
   *  MATLAB Function: '<S8>/bit_shift'
   *  MATLAB Function: '<S9>/bit_shift'
   */
  Wischer_Sensor_Box_final_B.BitwiseOperator3 = (uint16_T)((uint16_T)((uint32_T)
    (Wischer_Sensor_Box_final_B.DigitalInput1 << 7) >> 7) | (uint16_T)((uint16_T)
    (tmp < 0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-(real_T)tmp : (int32_T)
     (uint16_T)tmp) << 1));

  /* End of Outputs for SubSystem: '<S5>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S5>/Bit Shift5' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise Operator1' incorporates:
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  WischWasch = ((Wischer_Sensor_Box_final_B.DigitalInput1 !=
                 Wischer_Sensor_Box_final_DW.DelayInput1_DSTATE_j) ||
                (Wischer_Sensor_Box_final_B.RegularADC !=
                 Wischer_Sensor_Box_final_DW.DelayInput1_DSTATE));

  /* Outputs for Triggered SubSystem: '<S2>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S44>/Trigger'
   */
  if (WischWasch && (Wischer_Sensor_Box_fina_PrevZCX.TriggeredSubsystem_Trig_ZCE
                     != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S44>/CAN Transmit' */

    /* CANTransmit: '<S44>/CAN Transmit' */
    memcpy(&(CANTransmitTxMsg.Data[0]),
           &Wischer_Sensor_Box_final_B.BitwiseOperator3, 2);/* D0: uint16 */
    CANx_Transmit(CAN1, &CANTransmitTxMsg, 0, 0.005);/* Transmit message */
  }

  Wischer_Sensor_Box_fina_PrevZCX.TriggeredSubsystem_Trig_ZCE = WischWasch;

  /* End of Outputs for SubSystem: '<S2>/Triggered Subsystem' */
  /* Update for UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Wischer_Sensor_Box_final_DW.DelayInput1_DSTATE_j =
    Wischer_Sensor_Box_final_B.DigitalInput1;

  /* Update for UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Wischer_Sensor_Box_final_DW.DelayInput1_DSTATE =
    Wischer_Sensor_Box_final_B.RegularADC;
}

/* Model initialize function */
void Wischer_Sensor_Box_final_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Wischer_Sensor_Box_final_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Wischer_Sensor_Box_final_B), 0,
                sizeof(B_Wischer_Sensor_Box_final_T));

  /* states (dwork) */
  (void) memset((void *)&Wischer_Sensor_Box_final_DW, 0,
                sizeof(DW_Wischer_Sensor_Box_final_T));
  Wischer_Sensor_Box_fina_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<S4>/WischerSteuerung' */
  Wischer_Sensor_Box_final_DW.is_Wischer_Rueck_WW =
    Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_Wischer_Vor_WW =
    Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_Wischer1 = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_Wischer_Rueck = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_Wischer_Vor = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.temporalCounter_i1 = 0U;
  Wischer_Sensor_Box_final_DW.is_active_c2_Wischer_Sensor_Box = 0U;
  Wischer_Sensor_Box_final_DW.is_c2_Wischer_Sensor_Box_final =
    Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S4>/ScheibenheizungsSteuerung' */
  Wischer_Sensor_Box_final_DW.is_AUTO = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.is_MANUELL = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensor_Box_final_DW.temporalCounter_i1_j = 0U;
  Wischer_Sensor_Box_final_DW.is_active_c1_Wischer_Sensor_Box = 0U;
  Wischer_Sensor_Box_final_DW.is_c1_Wischer_Sensor_Box_final =
    Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive' */
  /* Level2 S-Function Block: '<S1>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<S1>/CAN Receive1' */
  /* Level2 S-Function Block: '<S1>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */
  /* Level2 S-Function Block: '<S2>/Digital Output' (stm32f4_digital_output) */
  enable_OutputDigitalOutput();

  /* Enable for S-Function (stm32f4_digital_input): '<S1>/Digital Input1' */
  /* Level2 S-Function Block: '<S1>/Digital Input1' (stm32f4_digital_input) */
  enable_InputDigitalInput1();

  /* Enable for S-Function (stm32f4_regular_adc): '<S1>/Regular ADC' */
  /* Level2 S-Function Block: '<S1>/Regular ADC' (stm32f4_regular_adc) */
  enable_RegularADC();

  /* Enable for Triggered SubSystem: '<S2>/Triggered Subsystem' */

  /* Enable for S-Function (stm32f4_can): '<S44>/CAN Transmit' */
  /* Level2 S-Function Block: '<S44>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit();

  /* End of Enable for SubSystem: '<S2>/Triggered Subsystem' */

  /* Enable for S-Function (stm32f4_usart): '<S3>/UART Setup' */
  /* Level2 S-Function Block: '<S3>/UART Setup' (stm32f4_usart) */
  enable_SetupUARTSetup();

  /* Enable for S-Function (stm32f4_can): '<S3>/CAN Setup' */
  /* Level2 S-Function Block: '<S3>/CAN Setup' (stm32f4_can) */
  enable_CANSetup();
}

/* Model terminate function */
void Wischer_Sensor_Box_final_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* terminate_OutputDigitalOutput(); */

  /* Terminate for S-Function (stm32f4_digital_input): '<S1>/Digital Input1' */

  /* terminate_InputDigitalInput1(); */

  /* Terminate for S-Function (stm32f4_regular_adc): '<S1>/Regular ADC' */

  /* terminate_RegularADC(); */
}

/* [EOF] */
