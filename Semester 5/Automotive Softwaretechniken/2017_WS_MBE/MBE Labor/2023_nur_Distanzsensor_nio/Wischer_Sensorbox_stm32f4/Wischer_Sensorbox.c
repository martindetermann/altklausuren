/*
 * File: Wischer_Sensorbox.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Wischer_Sensorbox.
 *
 * Model version                        : 1.3
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Sun Dec  3 20:04:08 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Sun Dec  3 20:04:08 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wischer_Sensorbox.h"
#include "Wischer_Sensorbox_private.h"

/* Named constants for Chart: '<Root>/ScheibenheizungsSteuerung' */
#define Wischer_Sens_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Wischer_Sensorbox_IN_AUTO      ((uint8_T)1U)
#define Wischer_Sensorbox_IN_MANUELL   ((uint8_T)2U)
#define Wischer_Sensorbox_IN_OFF       ((uint8_T)1U)
#define Wischer_Sensorbox_IN_ON        ((uint8_T)2U)

/* Named constants for Chart: '<Root>/WischerSteuerung' */
#define Wischer_S_IN_INTERVALL_LANGSAM1 ((uint8_T)2U)
#define Wischer_S_IN_INTERVALL_LANGSAM2 ((uint8_T)3U)
#define Wischer_S_IN_INTERVALL_LANGSAM3 ((uint8_T)4U)
#define Wischer_Se_IN_INTERVALL_LANGSAM ((uint8_T)1U)
#define Wischer_Se_IN_WEIL_ICH_DUMM_BIN ((uint8_T)7U)
#define Wischer_Sen_IN_Wischer_Rueck_WW ((uint8_T)2U)
#define Wischer_Senso_IN_Wischer_Vor_WW ((uint8_T)3U)
#define Wischer_Sensor_IN_Wischer_Rueck ((uint8_T)8U)
#define Wischer_Sensorbo_IN_Wischer_Vor ((uint8_T)9U)
#define Wischer_Sensorbox_IN_Phase1    ((uint8_T)1U)
#define Wischer_Sensorbox_IN_Phase2    ((uint8_T)2U)
#define Wischer_Sensorbox_IN_Phase3    ((uint8_T)3U)
#define Wischer_Sensorbox_IN_Phase4    ((uint8_T)4U)
#define Wischer_Sensorbox_IN_Spruehen  ((uint8_T)1U)
#define Wischer_Sensorbox_IN_Stufe_0_  ((uint8_T)5U)
#define Wischer_Sensorbox_IN_TIPP      ((uint8_T)6U)
#define Wischer_Sensorbox_IN_Wischer1  ((uint8_T)4U)

/* Block signals (auto storage) */
B_Wischer_Sensorbox_T Wischer_Sensorbox_B;

/* Block states (auto storage) */
DW_Wischer_Sensorbox_T Wischer_Sensorbox_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Wischer_Sensorbox_T Wischer_Sensorbox_PrevZCX;

/* Real-time model */
RT_MODEL_Wischer_Sensorbox_T Wischer_Sensorbox_M_;
RT_MODEL_Wischer_Sensorbox_T *const Wischer_Sensorbox_M = &Wischer_Sensorbox_M_;

/* Forward declaration for local functions */
static void Wischer_Sensorbox_Wischer_Rueck(void);
static void Wischer__exit_internal_Wischer1(void);
static void Wischer_Sensorbox_Wischer1(const uint8_T *Compare, const uint8_T
  *Compare_p, const uint8_T *Compare_a, uint8_T *Compare_m, uint8_T *Compare_n,
  boolean_T *LogicalOperator);

/* Function for Chart: '<Root>/WischerSteuerung' */
static void Wischer_Sensorbox_Wischer_Rueck(void)
{
  /* During 'Wischer_Rueck': '<S6>:520' */
  /* '<S6>:545:1' sf_internal_predicateOutput = ... */
  /* '<S6>:545:1' Steps==0; */
  if (Wischer_Sensorbox_DW.Steps == 0.0) {
    /* Transition: '<S6>:545' */
    /* Exit Internal 'Wischer_Rueck': '<S6>:520' */
    Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sens_IN_NO_ACTIVE_CHILD;
    Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Se_IN_WEIL_ICH_DUMM_BIN;
    Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;
  } else {
    switch (Wischer_Sensorbox_DW.is_Wischer_Rueck) {
     case Wischer_Sensorbox_IN_Phase1:
      Wischer_Sensorbox_B.SM_A = true;
      Wischer_Sensorbox_B.SM_B = false;
      Wischer_Sensorbox_B.SM_C = false;
      Wischer_Sensorbox_B.SM_D = false;

      /* During 'Phase1': '<S6>:594' */
      /* '<S6>:546:1' sf_internal_predicateOutput = ... */
      /* '<S6>:546:1' after(StepTime,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensorbox_DW.StepTime * 100.0)) {
        /* Transition: '<S6>:546' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sensorbox_IN_Phase4;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase4': '<S6>:580' */
        /* '<S6>:580:1' SM_A=false */
        Wischer_Sensorbox_B.SM_A = false;

        /* '<S6>:580:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:580:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:580:1' SM_D=true */
        Wischer_Sensorbox_B.SM_D = true;

        /* '<S6>:580:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:580:4' Steps = Steps - 1; */
        Wischer_Sensorbox_DW.Steps--;
      }
      break;

     case Wischer_Sensorbox_IN_Phase2:
      Wischer_Sensorbox_B.SM_A = false;
      Wischer_Sensorbox_B.SM_B = true;
      Wischer_Sensorbox_B.SM_C = false;
      Wischer_Sensorbox_B.SM_D = false;

      /* During 'Phase2': '<S6>:582' */
      /* '<S6>:560:1' sf_internal_predicateOutput = ... */
      /* '<S6>:560:1' after(StepTime,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensorbox_DW.StepTime * 100.0)) {
        /* Transition: '<S6>:560' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sensorbox_IN_Phase1;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S6>:594' */
        /* '<S6>:594:1' SM_A=true */
        Wischer_Sensorbox_B.SM_A = true;

        /* '<S6>:594:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:594:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:594:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:594:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:594:5' Steps = Steps -1; */
        Wischer_Sensorbox_DW.Steps--;
      }
      break;

     case Wischer_Sensorbox_IN_Phase3:
      Wischer_Sensorbox_B.SM_A = false;
      Wischer_Sensorbox_B.SM_B = false;
      Wischer_Sensorbox_B.SM_C = true;
      Wischer_Sensorbox_B.SM_D = false;

      /* During 'Phase3': '<S6>:547' */
      /* '<S6>:587:1' sf_internal_predicateOutput = ... */
      /* '<S6>:587:1' after(StepTime,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensorbox_DW.StepTime * 100.0)) {
        /* Transition: '<S6>:587' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sensorbox_IN_Phase2;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase2': '<S6>:582' */
        /* '<S6>:582:1' SM_A=false */
        Wischer_Sensorbox_B.SM_A = false;

        /* '<S6>:582:1' SM_B=true */
        Wischer_Sensorbox_B.SM_B = true;

        /* '<S6>:582:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:582:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:582:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:582:5' Steps = Steps - 1; */
        Wischer_Sensorbox_DW.Steps--;
      }
      break;

     default:
      Wischer_Sensorbox_B.SM_A = false;
      Wischer_Sensorbox_B.SM_B = false;
      Wischer_Sensorbox_B.SM_C = false;
      Wischer_Sensorbox_B.SM_D = true;

      /* During 'Phase4': '<S6>:580' */
      /* '<S6>:588:1' sf_internal_predicateOutput = ... */
      /* '<S6>:588:1' after(StepTime,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensorbox_DW.StepTime * 100.0)) {
        /* Transition: '<S6>:588' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sensorbox_IN_Phase3;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase3': '<S6>:547' */
        /* '<S6>:547:1' SM_A=false */
        Wischer_Sensorbox_B.SM_A = false;

        /* '<S6>:547:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:547:1' SM_C=true */
        Wischer_Sensorbox_B.SM_C = true;

        /* '<S6>:547:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:547:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:547:4' Steps = Steps - 1; */
        Wischer_Sensorbox_DW.Steps--;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/WischerSteuerung' */
static void Wischer__exit_internal_Wischer1(void)
{
  /* Exit Internal 'Wischer1': '<S6>:537' */
  /* Exit Internal 'Wischer_Rueck': '<S6>:520' */
  Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'Wischer_Vor': '<S6>:523' */
  Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sens_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<Root>/WischerSteuerung' */
static void Wischer_Sensorbox_Wischer1(const uint8_T *Compare, const uint8_T
  *Compare_p, const uint8_T *Compare_a, uint8_T *Compare_m, uint8_T *Compare_n,
  boolean_T *LogicalOperator)
{
  /* During 'Wischer1': '<S6>:537' */
  /* '<S6>:550:1' sf_internal_predicateOutput = ... */
  /* '<S6>:550:1' WischWasch==1 &&Steps==0; */
  if ((*LogicalOperator) && (Wischer_Sensorbox_DW.Steps == 0.0)) {
    /* Transition: '<S6>:550' */
    Wischer__exit_internal_Wischer1();
    Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox = Wischer_Sensorbox_IN_Spruehen;
    Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

    /* Entry 'Spruehen': '<S6>:543' */
    /* '<S6>:543:1' WW_LED=true */
    Wischer_Sensorbox_B.WW_LED = true;

    /* '<S6>:543:1' WischWaschCount=2 */
    Wischer_Sensorbox_DW.WischWaschCount = 2U;

    /* '<S6>:543:1' StepTime=1/33 */
    Wischer_Sensorbox_DW.StepTime = 0.030303030303030304;
  } else {
    switch (Wischer_Sensorbox_DW.is_Wischer1) {
     case Wischer_Se_IN_INTERVALL_LANGSAM:
      /* During 'INTERVALL_LANGSAM': '<S6>:522' */
      /* Transition: '<S6>:581' */
      Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbo_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S6>:523' */
      /* Transition: '<S6>:524' */
      Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
      Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S6>:530' */
      /* '<S6>:530:1' SM_A=true */
      Wischer_Sensorbox_B.SM_A = true;

      /* '<S6>:530:1' SM_B=false */
      Wischer_Sensorbox_B.SM_B = false;

      /* '<S6>:530:1' SM_C=false */
      Wischer_Sensorbox_B.SM_C = false;

      /* '<S6>:530:1' SM_D=false */
      Wischer_Sensorbox_B.SM_D = false;

      /* '<S6>:530:3' WW_LED=false */
      Wischer_Sensorbox_B.WW_LED = false;

      /* '<S6>:530:5' Steps = Steps + 1; */
      Wischer_Sensorbox_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM1:
      /* During 'INTERVALL_LANGSAM1': '<S6>:533' */
      /* Transition: '<S6>:559' */
      Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbo_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S6>:523' */
      /* Transition: '<S6>:524' */
      Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
      Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S6>:530' */
      /* '<S6>:530:1' SM_A=true */
      Wischer_Sensorbox_B.SM_A = true;

      /* '<S6>:530:1' SM_B=false */
      Wischer_Sensorbox_B.SM_B = false;

      /* '<S6>:530:1' SM_C=false */
      Wischer_Sensorbox_B.SM_C = false;

      /* '<S6>:530:1' SM_D=false */
      Wischer_Sensorbox_B.SM_D = false;

      /* '<S6>:530:3' WW_LED=false */
      Wischer_Sensorbox_B.WW_LED = false;

      /* '<S6>:530:5' Steps = Steps + 1; */
      Wischer_Sensorbox_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM2:
      /* During 'INTERVALL_LANGSAM2': '<S6>:538' */
      /* Transition: '<S6>:565' */
      Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbo_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S6>:523' */
      /* Transition: '<S6>:524' */
      Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
      Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S6>:530' */
      /* '<S6>:530:1' SM_A=true */
      Wischer_Sensorbox_B.SM_A = true;

      /* '<S6>:530:1' SM_B=false */
      Wischer_Sensorbox_B.SM_B = false;

      /* '<S6>:530:1' SM_C=false */
      Wischer_Sensorbox_B.SM_C = false;

      /* '<S6>:530:1' SM_D=false */
      Wischer_Sensorbox_B.SM_D = false;

      /* '<S6>:530:3' WW_LED=false */
      Wischer_Sensorbox_B.WW_LED = false;

      /* '<S6>:530:5' Steps = Steps + 1; */
      Wischer_Sensorbox_DW.Steps++;
      break;

     case Wischer_S_IN_INTERVALL_LANGSAM3:
      /* During 'INTERVALL_LANGSAM3': '<S6>:519' */
      /* Transition: '<S6>:593' */
      Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbo_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S6>:523' */
      /* Transition: '<S6>:524' */
      Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
      Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S6>:530' */
      /* '<S6>:530:1' SM_A=true */
      Wischer_Sensorbox_B.SM_A = true;

      /* '<S6>:530:1' SM_B=false */
      Wischer_Sensorbox_B.SM_B = false;

      /* '<S6>:530:1' SM_C=false */
      Wischer_Sensorbox_B.SM_C = false;

      /* '<S6>:530:1' SM_D=false */
      Wischer_Sensorbox_B.SM_D = false;

      /* '<S6>:530:3' WW_LED=false */
      Wischer_Sensorbox_B.WW_LED = false;

      /* '<S6>:530:5' Steps = Steps + 1; */
      Wischer_Sensorbox_DW.Steps++;
      break;

     case Wischer_Sensorbox_IN_Stufe_0_:
      Wischer_Sensorbox_B.SM_A = false;
      Wischer_Sensorbox_B.SM_B = false;
      Wischer_Sensorbox_B.SM_C = false;
      Wischer_Sensorbox_B.SM_D = false;

      /* During 'Stufe_0_': '<S6>:534' */
      /* '<S6>:549:1' sf_internal_predicateOutput = ... */
      /* '<S6>:549:1' Wischer_Tipp==1; */
      if (*Compare == 1) {
        /* Transition: '<S6>:549' */
        Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbox_IN_TIPP;

        /* Entry 'TIPP': '<S6>:536' */
        /* '<S6>:536:1' StepTime=0.0303; */
        Wischer_Sensorbox_DW.StepTime = 0.0303;

        /* '<S6>:536:1' StepTime1=1; */
        /* '<S6>:536:1' BreakTime=1; */
        Wischer_Sensorbox_DW.BreakTime = 1.0;
      } else {
        /* '<S6>:590:1' sf_internal_predicateOutput = ... */
        /* '<S6>:590:1' Wischer_Intervall_I==1; */
        if (*Compare_p == 1) {
          /* Transition: '<S6>:590' */
          Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Se_IN_INTERVALL_LANGSAM;

          /* Entry 'INTERVALL_LANGSAM': '<S6>:522' */
          /* '<S6>:522:1' StepTime=0.0303; */
          Wischer_Sensorbox_DW.StepTime = 0.0303;

          /* '<S6>:522:1' StepTime1=1; */
          /* '<S6>:522:1' BreakTime=4; */
          Wischer_Sensorbox_DW.BreakTime = 4.0;
        } else {
          /* '<S6>:584:1' sf_internal_predicateOutput = ... */
          /* '<S6>:584:1' Wischer_Dauer_I==1; */
          if (*Compare_m == 1) {
            /* Transition: '<S6>:584' */
            Wischer_Sensorbox_DW.is_Wischer1 = Wischer_S_IN_INTERVALL_LANGSAM2;

            /* Entry 'INTERVALL_LANGSAM2': '<S6>:538' */
            /* '<S6>:538:1' StepTime=0.0303; */
            Wischer_Sensorbox_DW.StepTime = 0.0303;

            /* '<S6>:538:1' StepTime1=1; */
            /* '<S6>:538:1' BreakTime=0; */
            Wischer_Sensorbox_DW.BreakTime = 0.0;
          } else {
            /* '<S6>:558:1' sf_internal_predicateOutput = ... */
            /* '<S6>:558:1' Wischer_Dauer_II==1; */
            if (*Compare_n == 1) {
              /* Transition: '<S6>:558' */
              Wischer_Sensorbox_DW.is_Wischer1 = Wischer_S_IN_INTERVALL_LANGSAM3;

              /* Entry 'INTERVALL_LANGSAM3': '<S6>:519' */
              /* '<S6>:519:1' StepTime=0.015015; */
              Wischer_Sensorbox_DW.StepTime = 0.015015;

              /* '<S6>:519:1' StepTime1=0.5; */
              /* '<S6>:519:2' BreakTime=0; */
              Wischer_Sensorbox_DW.BreakTime = 0.0;
            } else {
              /* '<S6>:583:1' sf_internal_predicateOutput = ... */
              /* '<S6>:583:1' Wischer_Intervall_II==1; */
              if (*Compare_a == 1) {
                /* Transition: '<S6>:583' */
                Wischer_Sensorbox_DW.is_Wischer1 =
                  Wischer_S_IN_INTERVALL_LANGSAM1;

                /* Entry 'INTERVALL_LANGSAM1': '<S6>:533' */
                /* '<S6>:533:1' StepTime=0.0303; */
                Wischer_Sensorbox_DW.StepTime = 0.0303;

                /* '<S6>:533:1' StepTime1=1; */
                /* '<S6>:533:1' BreakTime=2; */
                Wischer_Sensorbox_DW.BreakTime = 2.0;
              }
            }
          }
        }
      }
      break;

     case Wischer_Sensorbox_IN_TIPP:
      /* During 'TIPP': '<S6>:536' */
      /* Transition: '<S6>:553' */
      Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbo_IN_Wischer_Vor;

      /* Entry Internal 'Wischer_Vor': '<S6>:523' */
      /* Transition: '<S6>:524' */
      Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
      Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

      /* Entry 'Phase1': '<S6>:530' */
      /* '<S6>:530:1' SM_A=true */
      Wischer_Sensorbox_B.SM_A = true;

      /* '<S6>:530:1' SM_B=false */
      Wischer_Sensorbox_B.SM_B = false;

      /* '<S6>:530:1' SM_C=false */
      Wischer_Sensorbox_B.SM_C = false;

      /* '<S6>:530:1' SM_D=false */
      Wischer_Sensorbox_B.SM_D = false;

      /* '<S6>:530:3' WW_LED=false */
      Wischer_Sensorbox_B.WW_LED = false;

      /* '<S6>:530:5' Steps = Steps + 1; */
      Wischer_Sensorbox_DW.Steps++;
      break;

     case Wischer_Se_IN_WEIL_ICH_DUMM_BIN:
      /* During 'WEIL_ICH_DUMM_BIN': '<S6>:598' */
      /* '<S6>:554:1' sf_internal_predicateOutput = ... */
      /* '<S6>:554:1' after(BreakTime,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Wischer_Sensorbox_DW.BreakTime * 100.0)) {
        /* Transition: '<S6>:554' */
        Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbox_IN_Stufe_0_;

        /* Entry 'Stufe_0_': '<S6>:534' */
        /* '<S6>:534:1' SM_A=false */
        Wischer_Sensorbox_B.SM_A = false;

        /* '<S6>:534:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:534:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:534:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:534:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:534:5' Steps=0 */
        Wischer_Sensorbox_DW.Steps = 0.0;

        /* '<S6>:534:5' WischWaschCount=0 */
        Wischer_Sensorbox_DW.WischWaschCount = 0U;
      }
      break;

     case Wischer_Sensor_IN_Wischer_Rueck:
      Wischer_Sensorbox_Wischer_Rueck();
      break;

     default:
      /* During 'Wischer_Vor': '<S6>:523' */
      /* '<S6>:562:1' sf_internal_predicateOutput = ... */
      /* '<S6>:562:1' Steps==23; */
      if (Wischer_Sensorbox_DW.Steps == 23.0) {
        /* Transition: '<S6>:562' */
        /* Exit Internal 'Wischer_Vor': '<S6>:523' */
        Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensor_IN_Wischer_Rueck;

        /* Entry Internal 'Wischer_Rueck': '<S6>:520' */
        /* Transition: '<S6>:599' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sensorbox_IN_Phase4;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase4': '<S6>:580' */
        /* '<S6>:580:1' SM_A=false */
        Wischer_Sensorbox_B.SM_A = false;

        /* '<S6>:580:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:580:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:580:1' SM_D=true */
        Wischer_Sensorbox_B.SM_D = true;

        /* '<S6>:580:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:580:4' Steps = Steps - 1; */
        Wischer_Sensorbox_DW.Steps--;
      } else {
        switch (Wischer_Sensorbox_DW.is_Wischer_Vor) {
         case Wischer_Sensorbox_IN_Phase1:
          Wischer_Sensorbox_B.SM_A = true;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase1': '<S6>:530' */
          /* '<S6>:526:1' sf_internal_predicateOutput = ... */
          /* '<S6>:526:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:526' */
            Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase2;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase2': '<S6>:531' */
            /* '<S6>:531:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:531:1' SM_B=true */
            Wischer_Sensorbox_B.SM_B = true;

            /* '<S6>:531:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:531:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:531:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:531:5' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         case Wischer_Sensorbox_IN_Phase2:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = true;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase2': '<S6>:531' */
          /* '<S6>:528:1' sf_internal_predicateOutput = ... */
          /* '<S6>:528:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:528' */
            Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase3;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase3': '<S6>:532' */
            /* '<S6>:532:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:532:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:532:1' SM_C=true */
            Wischer_Sensorbox_B.SM_C = true;

            /* '<S6>:532:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:532:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:532:4' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         case Wischer_Sensorbox_IN_Phase3:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = true;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase3': '<S6>:532' */
          /* '<S6>:527:1' sf_internal_predicateOutput = ... */
          /* '<S6>:527:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:527' */
            Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase4;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase4': '<S6>:529' */
            /* '<S6>:529:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:529:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:529:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:529:1' SM_D=true */
            Wischer_Sensorbox_B.SM_D = true;

            /* '<S6>:529:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:529:4' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         default:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = true;

          /* During 'Phase4': '<S6>:529' */
          /* '<S6>:525:1' sf_internal_predicateOutput = ... */
          /* '<S6>:525:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:525' */
            Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sensorbox_IN_Phase1;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase1': '<S6>:530' */
            /* '<S6>:530:1' SM_A=true */
            Wischer_Sensorbox_B.SM_A = true;

            /* '<S6>:530:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:530:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:530:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:530:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:530:5' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;
        }
      }
      break;
    }
  }
}

/* Model step function */
void Wischer_Sensorbox_step(void)
{
  int16_T rtb_DataTypeConversion;
  int16_T rtb_y_a;
  uint8_T Compare;
  uint8_T Compare_p;
  uint8_T Compare_a;
  uint8_T Compare_m;
  uint8_T Compare_n;
  boolean_T LogicalOperator;
  uint32_T qY;

  /* S-Function (stm32f4_can): '<Root>/CAN Receive' */

  /* CANReceive: '<Root>/CAN Receive' */
  Wischer_Sensorbox_B.CANReceive_o1 = CANReceive_GetMsg(&CANReceive_Msg);/* Message and Pending count */
  CANReceive_data = (CANReceive_DATA_STRUCT*)&(CANReceive_Msg.Data[0]);
  Wischer_Sensorbox_B.CANReceive_o2 = CANReceive_Msg.StdId;/* Standard ID */
  Wischer_Sensorbox_B.CANReceive_o3 = CANReceive_data->d0;/* Data0: uint16 */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_DataTypeConversion = (int16_T)Wischer_Sensorbox_B.CANReceive_o3;

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift3' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift6' */
  /* MATLAB Function: '<S11>/bit_shift' incorporates:
   *  MATLAB Function: '<S14>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S30>:1' */
  /* '<S30>:1:4' switch mode */
  /* '<S30>:1:5' case 1 */
  /* '<S30>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S27>:1' */
  /* '<S27>:1:4' switch mode */
  /* '<S27>:1:7' case 2 */
  /* '<S27>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_y_a = (int16_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion << 13) >> 13);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift6' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift3' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   */
  Compare = (uint8_T)(rtb_y_a == 1);

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  Compare_p = (uint8_T)(rtb_y_a == 2);

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   */
  Compare_a = (uint8_T)(rtb_y_a == 3);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  Compare_m = (uint8_T)(rtb_y_a == 4);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   */
  Compare_n = (uint8_T)(rtb_y_a == 5);

  /* S-Function (stm32f4_can): '<Root>/CAN Receive1' */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S32>:1' */
  /* '<S32>:1:4' switch mode */
  /* '<S32>:1:5' case 1 */
  /* '<S32>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S31>:1' */
  /* '<S31>:1:4' switch mode */
  /* '<S31>:1:7' case 2 */
  /* '<S31>:1:8' y = bitsrl(cast_to_fi(u), N); */

  /* CANReceive1: '<Root>/CAN Receive1' */
  Wischer_Sensorbox_B.CANReceive1_o1 = CANReceive1_GetMsg(&CANReceive1_Msg);/* Message and Pending count */
  CANReceive1_data = (CANReceive1_DATA_STRUCT*)&(CANReceive1_Msg.Data[0]);
  Wischer_Sensorbox_B.CANReceive1_o2 = CANReceive1_Msg.StdId;/* Standard ID */
  Wischer_Sensorbox_B.CANReceive1_o3 = CANReceive1_data->d0;/* Data0: uint8 */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift7' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift8' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift4' */
  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S36>/Constant'
   *  MATLAB Function: '<S15>/bit_shift'
   *  MATLAB Function: '<S16>/bit_shift'
   *  MATLAB Function: '<S33>/bit_shift'
   *  MATLAB Function: '<S34>/bit_shift'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S36>/Compare'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S37>:1' */
  /* '<S37>:1:4' switch mode */
  /* '<S37>:1:5' case 1 */
  /* '<S37>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S38>:1' */
  /* '<S38>:1:4' switch mode */
  /* '<S38>:1:7' case 2 */
  /* '<S38>:1:8' y = bitsrl(cast_to_fi(u), N); */
  LogicalOperator = (((int32_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion <<
    12) >> 15) == 1) && ((int32_T)((uint32_T)(uint8_T)
    (Wischer_Sensorbox_B.CANReceive1_o3 << 7) >> 7) == 1));

  /* End of Outputs for SubSystem: '<S3>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift5' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift8' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift7' */

  /* Chart: '<Root>/WischerSteuerung' */
  if (Wischer_Sensorbox_DW.temporalCounter_i1 < MAX_uint32_T) {
    Wischer_Sensorbox_DW.temporalCounter_i1++;
  }

  /* Gateway: WischerSteuerung */
  /* During: WischerSteuerung */
  if (Wischer_Sensorbox_DW.is_active_c5_Wischer_Sensorbox == 0U) {
    /* Entry: WischerSteuerung */
    Wischer_Sensorbox_DW.is_active_c5_Wischer_Sensorbox = 1U;

    /* Entry Internal: WischerSteuerung */
    /* Transition: '<S6>:589' */
    Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox = Wischer_Sensorbox_IN_Wischer1;

    /* Entry Internal 'Wischer1': '<S6>:537' */
    /* Transition: '<S6>:548' */
    Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbox_IN_Stufe_0_;

    /* Entry 'Stufe_0_': '<S6>:534' */
    /* '<S6>:534:1' SM_A=false */
    Wischer_Sensorbox_B.SM_A = false;

    /* '<S6>:534:1' SM_B=false */
    Wischer_Sensorbox_B.SM_B = false;

    /* '<S6>:534:1' SM_C=false */
    Wischer_Sensorbox_B.SM_C = false;

    /* '<S6>:534:1' SM_D=false */
    Wischer_Sensorbox_B.SM_D = false;

    /* '<S6>:534:3' WW_LED=false */
    Wischer_Sensorbox_B.WW_LED = false;

    /* '<S6>:534:5' Steps=0 */
    Wischer_Sensorbox_DW.Steps = 0.0;

    /* '<S6>:534:5' WischWaschCount=0 */
    Wischer_Sensorbox_DW.WischWaschCount = 0U;
  } else {
    switch (Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox) {
     case Wischer_Sensorbox_IN_Spruehen:
      /* During 'Spruehen': '<S6>:543' */
      /* '<S6>:516:1' sf_internal_predicateOutput = ... */
      /* '<S6>:516:1' after(2,sec); */
      if (Wischer_Sensorbox_DW.temporalCounter_i1 >= 200U) {
        /* Transition: '<S6>:516' */
        /* Exit 'Spruehen': '<S6>:543' */
        /* '<S6>:543:2' WW_LED=false */
        Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox =
          Wischer_Senso_IN_Wischer_Vor_WW;

        /* Entry Internal 'Wischer_Vor_WW': '<S6>:569' */
        /* Transition: '<S6>:570' */
        Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase1;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S6>:576' */
        /* '<S6>:576:1' SM_A=true */
        Wischer_Sensorbox_B.SM_A = true;

        /* '<S6>:576:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:576:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:576:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:576:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:576:5' Steps = Steps + 1; */
        Wischer_Sensorbox_DW.Steps++;
      }
      break;

     case Wischer_Sen_IN_Wischer_Rueck_WW:
      /* During 'Wischer_Rueck_WW': '<S6>:544' */
      /* '<S6>:514:1' sf_internal_predicateOutput = ... */
      /* '<S6>:514:1' Steps==0&&WischWaschCount>0; */
      if ((Wischer_Sensorbox_DW.Steps == 0.0) &&
          (Wischer_Sensorbox_DW.WischWaschCount > 0)) {
        /* Transition: '<S6>:514' */
        /* '<S6>:514:1' WischWaschCount = WischWaschCount - 1 */
        qY = Wischer_Sensorbox_DW.WischWaschCount - /*MW:OvSatOk*/ 1U;
        if (qY > Wischer_Sensorbox_DW.WischWaschCount) {
          qY = 0U;
        }

        Wischer_Sensorbox_DW.WischWaschCount = (uint8_T)qY;

        /* Exit Internal 'Wischer_Rueck_WW': '<S6>:544' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
          Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox =
          Wischer_Senso_IN_Wischer_Vor_WW;

        /* Entry Internal 'Wischer_Vor_WW': '<S6>:569' */
        /* Transition: '<S6>:570' */
        Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase1;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S6>:576' */
        /* '<S6>:576:1' SM_A=true */
        Wischer_Sensorbox_B.SM_A = true;

        /* '<S6>:576:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:576:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:576:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:576:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:576:5' Steps = Steps + 1; */
        Wischer_Sensorbox_DW.Steps++;
      } else {
        /* '<S6>:518:1' sf_internal_predicateOutput = ... */
        /* '<S6>:518:1' WischWaschCount==0&&Steps==0; */
        if ((Wischer_Sensorbox_DW.WischWaschCount == 0) &&
            (Wischer_Sensorbox_DW.Steps == 0.0)) {
          /* Transition: '<S6>:518' */
          /* Exit Internal 'Wischer_Rueck_WW': '<S6>:544' */
          Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
            Wischer_Sens_IN_NO_ACTIVE_CHILD;
          Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox =
            Wischer_Sensorbox_IN_Wischer1;

          /* Entry Internal 'Wischer1': '<S6>:537' */
          /* Transition: '<S6>:548' */
          Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sensorbox_IN_Stufe_0_;

          /* Entry 'Stufe_0_': '<S6>:534' */
          /* '<S6>:534:1' SM_A=false */
          Wischer_Sensorbox_B.SM_A = false;

          /* '<S6>:534:1' SM_B=false */
          Wischer_Sensorbox_B.SM_B = false;

          /* '<S6>:534:1' SM_C=false */
          Wischer_Sensorbox_B.SM_C = false;

          /* '<S6>:534:1' SM_D=false */
          Wischer_Sensorbox_B.SM_D = false;

          /* '<S6>:534:3' WW_LED=false */
          Wischer_Sensorbox_B.WW_LED = false;

          /* '<S6>:534:5' Steps=0 */
          Wischer_Sensorbox_DW.Steps = 0.0;

          /* '<S6>:534:5' WischWaschCount=0 */
          Wischer_Sensorbox_DW.WischWaschCount = 0U;
        } else {
          switch (Wischer_Sensorbox_DW.is_Wischer_Rueck_WW) {
           case Wischer_Sensorbox_IN_Phase1:
            Wischer_Sensorbox_B.SM_A = true;
            Wischer_Sensorbox_B.SM_B = false;
            Wischer_Sensorbox_B.SM_C = false;
            Wischer_Sensorbox_B.SM_D = false;

            /* During 'Phase1': '<S6>:579' */
            /* '<S6>:509:1' sf_internal_predicateOutput = ... */
            /* '<S6>:509:1' after(StepTime,sec); */
            if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensorbox_DW.StepTime * 100.0)) {
              /* Transition: '<S6>:509' */
              Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
                Wischer_Sensorbox_IN_Phase4;
              Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase4': '<S6>:552' */
              /* '<S6>:552:1' SM_A=false */
              Wischer_Sensorbox_B.SM_A = false;

              /* '<S6>:552:1' SM_B=false */
              Wischer_Sensorbox_B.SM_B = false;

              /* '<S6>:552:1' SM_C=false */
              Wischer_Sensorbox_B.SM_C = false;

              /* '<S6>:552:1' SM_D=true */
              Wischer_Sensorbox_B.SM_D = true;

              /* '<S6>:552:3' WW_LED=false */
              Wischer_Sensorbox_B.WW_LED = false;

              /* '<S6>:552:4' Steps = Steps - 1; */
              Wischer_Sensorbox_DW.Steps--;
            }
            break;

           case Wischer_Sensorbox_IN_Phase2:
            Wischer_Sensorbox_B.SM_A = false;
            Wischer_Sensorbox_B.SM_B = true;
            Wischer_Sensorbox_B.SM_C = false;
            Wischer_Sensorbox_B.SM_D = false;

            /* During 'Phase2': '<S6>:556' */
            /* '<S6>:510:1' sf_internal_predicateOutput = ... */
            /* '<S6>:510:1' after(StepTime,sec); */
            if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensorbox_DW.StepTime * 100.0)) {
              /* Transition: '<S6>:510' */
              Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
                Wischer_Sensorbox_IN_Phase1;
              Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase1': '<S6>:579' */
              /* '<S6>:579:1' SM_A=true */
              Wischer_Sensorbox_B.SM_A = true;

              /* '<S6>:579:1' SM_B=false */
              Wischer_Sensorbox_B.SM_B = false;

              /* '<S6>:579:1' SM_C=false */
              Wischer_Sensorbox_B.SM_C = false;

              /* '<S6>:579:1' SM_D=false */
              Wischer_Sensorbox_B.SM_D = false;

              /* '<S6>:579:3' WW_LED=false */
              Wischer_Sensorbox_B.WW_LED = false;

              /* '<S6>:579:5' Steps = Steps -1; */
              Wischer_Sensorbox_DW.Steps--;
            }
            break;

           case Wischer_Sensorbox_IN_Phase3:
            Wischer_Sensorbox_B.SM_A = false;
            Wischer_Sensorbox_B.SM_B = false;
            Wischer_Sensorbox_B.SM_C = true;
            Wischer_Sensorbox_B.SM_D = false;

            /* During 'Phase3': '<S6>:557' */
            /* '<S6>:511:1' sf_internal_predicateOutput = ... */
            /* '<S6>:511:1' after(StepTime,sec); */
            if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensorbox_DW.StepTime * 100.0)) {
              /* Transition: '<S6>:511' */
              Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
                Wischer_Sensorbox_IN_Phase2;
              Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase2': '<S6>:556' */
              /* '<S6>:556:1' SM_A=false */
              Wischer_Sensorbox_B.SM_A = false;

              /* '<S6>:556:1' SM_B=true */
              Wischer_Sensorbox_B.SM_B = true;

              /* '<S6>:556:1' SM_C=false */
              Wischer_Sensorbox_B.SM_C = false;

              /* '<S6>:556:1' SM_D=false */
              Wischer_Sensorbox_B.SM_D = false;

              /* '<S6>:556:3' WW_LED=false */
              Wischer_Sensorbox_B.WW_LED = false;

              /* '<S6>:556:5' Steps = Steps - 1; */
              Wischer_Sensorbox_DW.Steps--;
            }
            break;

           default:
            Wischer_Sensorbox_B.SM_A = false;
            Wischer_Sensorbox_B.SM_B = false;
            Wischer_Sensorbox_B.SM_C = false;
            Wischer_Sensorbox_B.SM_D = true;

            /* During 'Phase4': '<S6>:552' */
            /* '<S6>:512:1' sf_internal_predicateOutput = ... */
            /* '<S6>:512:1' after(StepTime,sec); */
            if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
                (Wischer_Sensorbox_DW.StepTime * 100.0)) {
              /* Transition: '<S6>:512' */
              Wischer_Sensorbox_DW.is_Wischer_Rueck_WW =
                Wischer_Sensorbox_IN_Phase3;
              Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

              /* Entry 'Phase3': '<S6>:557' */
              /* '<S6>:557:1' SM_A=false */
              Wischer_Sensorbox_B.SM_A = false;

              /* '<S6>:557:1' SM_B=false */
              Wischer_Sensorbox_B.SM_B = false;

              /* '<S6>:557:1' SM_C=true */
              Wischer_Sensorbox_B.SM_C = true;

              /* '<S6>:557:1' SM_D=false */
              Wischer_Sensorbox_B.SM_D = false;

              /* '<S6>:557:3' WW_LED=false */
              Wischer_Sensorbox_B.WW_LED = false;

              /* '<S6>:557:4' Steps = Steps - 1; */
              Wischer_Sensorbox_DW.Steps--;
            }
            break;
          }
        }
      }
      break;

     case Wischer_Senso_IN_Wischer_Vor_WW:
      /* During 'Wischer_Vor_WW': '<S6>:569' */
      /* '<S6>:517:1' sf_internal_predicateOutput = ... */
      /* '<S6>:517:1' Steps==23; */
      if (Wischer_Sensorbox_DW.Steps == 23.0) {
        /* Transition: '<S6>:517' */
        /* Exit Internal 'Wischer_Vor_WW': '<S6>:569' */
        Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sens_IN_NO_ACTIVE_CHILD;
        Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox =
          Wischer_Sen_IN_Wischer_Rueck_WW;

        /* Entry Internal 'Wischer_Rueck_WW': '<S6>:544' */
        /* Transition: '<S6>:597' */
        Wischer_Sensorbox_DW.is_Wischer_Rueck_WW = Wischer_Sensorbox_IN_Phase1;
        Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

        /* Entry 'Phase1': '<S6>:579' */
        /* '<S6>:579:1' SM_A=true */
        Wischer_Sensorbox_B.SM_A = true;

        /* '<S6>:579:1' SM_B=false */
        Wischer_Sensorbox_B.SM_B = false;

        /* '<S6>:579:1' SM_C=false */
        Wischer_Sensorbox_B.SM_C = false;

        /* '<S6>:579:1' SM_D=false */
        Wischer_Sensorbox_B.SM_D = false;

        /* '<S6>:579:3' WW_LED=false */
        Wischer_Sensorbox_B.WW_LED = false;

        /* '<S6>:579:5' Steps = Steps -1; */
        Wischer_Sensorbox_DW.Steps--;
      } else {
        switch (Wischer_Sensorbox_DW.is_Wischer_Vor_WW) {
         case Wischer_Sensorbox_IN_Phase1:
          Wischer_Sensorbox_B.SM_A = true;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase1': '<S6>:576' */
          /* '<S6>:572:1' sf_internal_predicateOutput = ... */
          /* '<S6>:572:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:572' */
            Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase2;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase2': '<S6>:577' */
            /* '<S6>:577:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:577:1' SM_B=true */
            Wischer_Sensorbox_B.SM_B = true;

            /* '<S6>:577:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:577:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:577:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:577:5' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         case Wischer_Sensorbox_IN_Phase2:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = true;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase2': '<S6>:577' */
          /* '<S6>:574:1' sf_internal_predicateOutput = ... */
          /* '<S6>:574:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:574' */
            Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase3;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase3': '<S6>:578' */
            /* '<S6>:578:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:578:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:578:1' SM_C=true */
            Wischer_Sensorbox_B.SM_C = true;

            /* '<S6>:578:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:578:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:578:4' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         case Wischer_Sensorbox_IN_Phase3:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = true;
          Wischer_Sensorbox_B.SM_D = false;

          /* During 'Phase3': '<S6>:578' */
          /* '<S6>:573:1' sf_internal_predicateOutput = ... */
          /* '<S6>:573:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:573' */
            Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase4;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase4': '<S6>:575' */
            /* '<S6>:575:1' SM_A=false */
            Wischer_Sensorbox_B.SM_A = false;

            /* '<S6>:575:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:575:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:575:1' SM_D=true */
            Wischer_Sensorbox_B.SM_D = true;

            /* '<S6>:575:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:575:4' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;

         default:
          Wischer_Sensorbox_B.SM_A = false;
          Wischer_Sensorbox_B.SM_B = false;
          Wischer_Sensorbox_B.SM_C = false;
          Wischer_Sensorbox_B.SM_D = true;

          /* During 'Phase4': '<S6>:575' */
          /* '<S6>:571:1' sf_internal_predicateOutput = ... */
          /* '<S6>:571:1' after(StepTime,sec); */
          if (Wischer_Sensorbox_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Wischer_Sensorbox_DW.StepTime * 100.0)) {
            /* Transition: '<S6>:571' */
            Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sensorbox_IN_Phase1;
            Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;

            /* Entry 'Phase1': '<S6>:576' */
            /* '<S6>:576:1' SM_A=true */
            Wischer_Sensorbox_B.SM_A = true;

            /* '<S6>:576:1' SM_B=false */
            Wischer_Sensorbox_B.SM_B = false;

            /* '<S6>:576:1' SM_C=false */
            Wischer_Sensorbox_B.SM_C = false;

            /* '<S6>:576:1' SM_D=false */
            Wischer_Sensorbox_B.SM_D = false;

            /* '<S6>:576:3' WW_LED=false */
            Wischer_Sensorbox_B.WW_LED = false;

            /* '<S6>:576:5' Steps = Steps + 1; */
            Wischer_Sensorbox_DW.Steps++;
          }
          break;
        }
      }
      break;

     default:
      Wischer_Sensorbox_Wischer1(&Compare, &Compare_p, &Compare_a, &Compare_m,
        &Compare_n, &LogicalOperator);
      break;
    }
  }

  /* End of Chart: '<Root>/WischerSteuerung' */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift4' */
  /* MATLAB Function: '<S13>/bit_shift' incorporates:
   *  MATLAB Function: '<S12>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S28>:1' */
  /* '<S28>:1:4' switch mode */
  /* '<S28>:1:5' case 1 */
  /* '<S28>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S29>:1' */
  /* '<S29>:1:4' switch mode */
  /* '<S29>:1:7' case 2 */
  /* '<S29>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_y_a = (int16_T)((uint32_T)(uint16_T)(rtb_DataTypeConversion << 10) >> 14);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift5' */

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  Compare = (uint8_T)(rtb_y_a == 2);

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  Compare_p = (uint8_T)(rtb_y_a == 1);

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift1' */
  /* Bias: '<S2>/Bias' incorporates:
   *  MATLAB Function: '<S10>/bit_shift'
   *  MATLAB Function: '<S9>/bit_shift'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S25>:1' */
  /* '<S25>:1:4' switch mode */
  /* '<S25>:1:5' case 1 */
  /* '<S25>:1:6' y = bitsll(cast_to_fi(u), N); */
  /* MATLAB Function 'Logic and Bit Operations/Bit Shift/bit_shift': '<S26>:1' */
  /* '<S26>:1:4' switch mode */
  /* '<S26>:1:7' case 2 */
  /* '<S26>:1:8' y = bitsrl(cast_to_fi(u), N); */
  rtb_DataTypeConversion = (int16_T)((int32_T)((uint32_T)(uint16_T)
    (rtb_DataTypeConversion << 3) >> 9) - 40);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift1' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift2' */

  /* Chart: '<Root>/ScheibenheizungsSteuerung' */
  if (Wischer_Sensorbox_DW.temporalCounter_i1_f < 4095U) {
    Wischer_Sensorbox_DW.temporalCounter_i1_f++;
  }

  /* Gateway: ScheibenheizungsSteuerung */
  /* During: ScheibenheizungsSteuerung */
  if (Wischer_Sensorbox_DW.is_active_c6_Wischer_Sensorbox == 0U) {
    /* Entry: ScheibenheizungsSteuerung */
    Wischer_Sensorbox_DW.is_active_c6_Wischer_Sensorbox = 1U;

    /* Entry Internal: ScheibenheizungsSteuerung */
    /* Transition: '<S4>:25' */
    Wischer_Sensorbox_DW.is_c6_Wischer_Sensorbox = Wischer_Sensorbox_IN_MANUELL;

    /* Entry Internal 'MANUELL': '<S4>:24' */
    /* Transition: '<S4>:50' */
    Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sensorbox_IN_OFF;

    /* Entry 'OFF': '<S4>:39' */
    /* '<S4>:39:1' SH_LED=false */
    Wischer_Sensorbox_B.SH_LED = false;
  } else if (Wischer_Sensorbox_DW.is_c6_Wischer_Sensorbox ==
             Wischer_Sensorbox_IN_AUTO) {
    /* During 'AUTO': '<S4>:56' */
    /* '<S4>:58:1' sf_internal_predicateOutput = ... */
    /* '<S4>:58:1' Scheibenheizung_Auto==0; */
    if (Compare_p == 0) {
      /* Transition: '<S4>:58' */
      /* Exit Internal 'AUTO': '<S4>:56' */
      Wischer_Sensorbox_DW.is_AUTO = Wischer_Sens_IN_NO_ACTIVE_CHILD;
      Wischer_Sensorbox_DW.is_c6_Wischer_Sensorbox =
        Wischer_Sensorbox_IN_MANUELL;

      /* Entry Internal 'MANUELL': '<S4>:24' */
      /* Transition: '<S4>:50' */
      Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sensorbox_IN_OFF;

      /* Entry 'OFF': '<S4>:39' */
      /* '<S4>:39:1' SH_LED=false */
      Wischer_Sensorbox_B.SH_LED = false;
    } else if (Wischer_Sensorbox_DW.is_AUTO == Wischer_Sensorbox_IN_OFF) {
      Wischer_Sensorbox_B.SH_LED = false;

      /* During 'OFF': '<S4>:54' */
      /* '<S4>:53:1' sf_internal_predicateOutput = ... */
      /* '<S4>:53:1' Temperatur<2; */
      if (rtb_DataTypeConversion < 2) {
        /* Transition: '<S4>:53' */
        Wischer_Sensorbox_DW.is_AUTO = Wischer_Sensorbox_IN_ON;
        Wischer_Sensorbox_DW.temporalCounter_i1_f = 0U;

        /* Entry 'ON': '<S4>:55' */
        /* '<S4>:55:1' SH_LED=true */
        Wischer_Sensorbox_B.SH_LED = true;
      }
    } else {
      Wischer_Sensorbox_B.SH_LED = true;

      /* During 'ON': '<S4>:55' */
      /* '<S4>:51:1' sf_internal_predicateOutput = ... */
      /* '<S4>:51:1' after(30,sec) || Temperatur>=2; */
      if ((Wischer_Sensorbox_DW.temporalCounter_i1_f >= 3000U) ||
          (rtb_DataTypeConversion >= 2)) {
        /* Transition: '<S4>:51' */
        Wischer_Sensorbox_DW.is_AUTO = Wischer_Sensorbox_IN_OFF;

        /* Entry 'OFF': '<S4>:54' */
        /* '<S4>:54:1' SH_LED=false */
        Wischer_Sensorbox_B.SH_LED = false;
      }
    }
  } else {
    /* During 'MANUELL': '<S4>:24' */
    /* '<S4>:57:1' sf_internal_predicateOutput = ... */
    /* '<S4>:57:1' Scheibenheizung_Auto==1; */
    if (Compare_p == 1) {
      /* Transition: '<S4>:57' */
      /* Exit Internal 'MANUELL': '<S4>:24' */
      Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sens_IN_NO_ACTIVE_CHILD;
      Wischer_Sensorbox_DW.is_c6_Wischer_Sensorbox = Wischer_Sensorbox_IN_AUTO;

      /* Entry Internal 'AUTO': '<S4>:56' */
      /* Transition: '<S4>:52' */
      Wischer_Sensorbox_DW.is_AUTO = Wischer_Sensorbox_IN_OFF;

      /* Entry 'OFF': '<S4>:54' */
      /* '<S4>:54:1' SH_LED=false */
      Wischer_Sensorbox_B.SH_LED = false;
    } else if (Wischer_Sensorbox_DW.is_MANUELL == Wischer_Sensorbox_IN_OFF) {
      Wischer_Sensorbox_B.SH_LED = false;

      /* During 'OFF': '<S4>:39' */
      /* '<S4>:41:1' sf_internal_predicateOutput = ... */
      /* '<S4>:41:1' Scheibenheizung==1; */
      if (Compare == 1) {
        /* Transition: '<S4>:41' */
        Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sensorbox_IN_ON;
        Wischer_Sensorbox_DW.temporalCounter_i1_f = 0U;

        /* Entry 'ON': '<S4>:37' */
        /* '<S4>:37:1' SH_LED=true */
        Wischer_Sensorbox_B.SH_LED = true;
      }
    } else {
      Wischer_Sensorbox_B.SH_LED = true;

      /* During 'ON': '<S4>:37' */
      /* '<S4>:40:1' sf_internal_predicateOutput = ... */
      /* '<S4>:40:1' after(30,sec) || Scheibenheizung==0; */
      if ((Wischer_Sensorbox_DW.temporalCounter_i1_f >= 3000U) || (Compare == 0))
      {
        /* Transition: '<S4>:40' */
        Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sensorbox_IN_OFF;

        /* Entry 'OFF': '<S4>:39' */
        /* '<S4>:39:1' SH_LED=false */
        Wischer_Sensorbox_B.SH_LED = false;
      }
    }
  }

  /* End of Chart: '<Root>/ScheibenheizungsSteuerung' */

  /* S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* DigitalOutput */
  {
    *DigitalOutput_C0 = Wischer_Sensorbox_B.SM_A;
    *DigitalOutput_C1 = Wischer_Sensorbox_B.SM_B;
    *DigitalOutput_C2 = Wischer_Sensorbox_B.SM_C;
    *DigitalOutput_C3 = Wischer_Sensorbox_B.SM_D;
    *DigitalOutput_C4 = Wischer_Sensorbox_B.SH_LED;
    *DigitalOutput_C5 = Wischer_Sensorbox_B.WW_LED;
  }

  /* S-Function (stm32f4_digital_input): '<Root>/Digital Input1' */
  Wischer_Sensorbox_B.DigitalInput1 = *DigitalInput1_C6;

  /* S-Function (stm32f4_regular_adc): '<Root>/Regular ADC' */

  /* ADC Block */
  RegularADCStartConversion();
  Wischer_Sensorbox_B.RegularADC = (uint16_T)RegularADC_ConvertedValue[0];

  /* S-Function (sfix_bitop): '<S1>/Bitwise Operator3' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Gain: '<S1>/Gain9'
   */
  Wischer_Sensorbox_B.BitwiseOperator3 = (uint16_T)((uint16_T)
    (Wischer_Sensorbox_B.RegularADC << 1) | (uint16_T)
    Wischer_Sensorbox_B.DigitalInput1);

  /* S-Function (sfix_bitop): '<S1>/Bitwise Operator1' incorporates:
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  RelationalOperator: '<S8>/FixPt Relational Operator'
   *  UnitDelay: '<S7>/Delay Input1'
   *  UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LogicalOperator = ((Wischer_Sensorbox_B.DigitalInput1 !=
                      Wischer_Sensorbox_DW.DelayInput1_DSTATE_h) ||
                     (Wischer_Sensorbox_B.RegularADC !=
                      Wischer_Sensorbox_DW.DelayInput1_DSTATE));

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  if (LogicalOperator && (Wischer_Sensorbox_PrevZCX.TriggeredSubsystem_Trig_ZCE
                          != POS_ZCSIG)) {
    /* S-Function (stm32f4_can): '<S5>/CAN Transmit' */

    /* CANTransmit: '<S5>/CAN Transmit' */
    memcpy(&(CANTransmitTxMsg.Data[0]), &Wischer_Sensorbox_B.BitwiseOperator3, 2);/* D0: uint16 */
    CANx_Transmit(CAN1, &CANTransmitTxMsg, 0, 0.005);/* Transmit message */
  }

  Wischer_Sensorbox_PrevZCX.TriggeredSubsystem_Trig_ZCE = LogicalOperator;

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */
  /* Update for UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Wischer_Sensorbox_DW.DelayInput1_DSTATE_h = Wischer_Sensorbox_B.DigitalInput1;

  /* Update for UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Wischer_Sensorbox_DW.DelayInput1_DSTATE = Wischer_Sensorbox_B.RegularADC;
}

/* Model initialize function */
void Wischer_Sensorbox_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Wischer_Sensorbox_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Wischer_Sensorbox_B), 0,
                sizeof(B_Wischer_Sensorbox_T));

  /* states (dwork) */
  (void) memset((void *)&Wischer_Sensorbox_DW, 0,
                sizeof(DW_Wischer_Sensorbox_T));
  Wischer_Sensorbox_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/WischerSteuerung' */
  Wischer_Sensorbox_DW.is_Wischer_Rueck_WW = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_Wischer_Vor_WW = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_Wischer1 = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_Wischer_Rueck = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_Wischer_Vor = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.temporalCounter_i1 = 0U;
  Wischer_Sensorbox_DW.is_active_c5_Wischer_Sensorbox = 0U;
  Wischer_Sensorbox_DW.is_c5_Wischer_Sensorbox = Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/ScheibenheizungsSteuerung' */
  Wischer_Sensorbox_DW.is_AUTO = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.is_MANUELL = Wischer_Sens_IN_NO_ACTIVE_CHILD;
  Wischer_Sensorbox_DW.temporalCounter_i1_f = 0U;
  Wischer_Sensorbox_DW.is_active_c6_Wischer_Sensorbox = 0U;
  Wischer_Sensorbox_DW.is_c6_Wischer_Sensorbox = Wischer_Sens_IN_NO_ACTIVE_CHILD;

  /* Enable for S-Function (stm32f4_usart): '<Root>/UART Setup' */
  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive' */
  /* Level2 S-Function Block: '<Root>/CAN Receive' (stm32f4_can) */
  enable_CANReceive();

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Receive1' */
  /* Level2 S-Function Block: '<Root>/CAN Receive1' (stm32f4_can) */
  enable_CANReceive1();

  /* Enable for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */
  /* Level2 S-Function Block: '<Root>/Digital Output' (stm32f4_digital_output) */
  enable_DigitalOutput();

  /* Enable for S-Function (stm32f4_digital_input): '<Root>/Digital Input1' */
  /* Level2 S-Function Block: '<Root>/Digital Input1' (stm32f4_digital_input) */
  enable_DigitalInput1();

  /* Enable for S-Function (stm32f4_regular_adc): '<Root>/Regular ADC' */
  /* Level2 S-Function Block: '<Root>/Regular ADC' (stm32f4_regular_adc) */
  enable_RegularADC();

  /* Enable for Triggered SubSystem: '<Root>/Triggered Subsystem' */

  /* Enable for S-Function (stm32f4_can): '<S5>/CAN Transmit' */
  /* Level2 S-Function Block: '<S5>/CAN Transmit' (stm32f4_can) */
  enable_CANTransmit();

  /* End of Enable for SubSystem: '<Root>/Triggered Subsystem' */

  /* Enable for S-Function (stm32f4_can): '<Root>/CAN Setup' */
  /* Level2 S-Function Block: '<Root>/CAN Setup' (stm32f4_can) */
  enable_CANSetup();
}

/* Model terminate function */
void Wischer_Sensorbox_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* terminate_DigitalOutput(); */

  /* Terminate for S-Function (stm32f4_digital_input): '<Root>/Digital Input1' */

  /* terminate_DigitalInput1(); */

  /* Terminate for S-Function (stm32f4_regular_adc): '<Root>/Regular ADC' */

  /* terminate_RegularADC(); */
}

/* [EOF] */
