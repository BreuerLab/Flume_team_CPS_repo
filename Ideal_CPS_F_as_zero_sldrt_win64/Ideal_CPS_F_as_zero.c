/*
 * Ideal_CPS_F_as_zero.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ideal_CPS_F_as_zero".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb 24 16:08:20 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ideal_CPS_F_as_zero.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Ideal_CPS_F_as_zero_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* Block signals (default storage) */
B_Ideal_CPS_F_as_zero_T Ideal_CPS_F_as_zero_B;

/* Block states (default storage) */
DW_Ideal_CPS_F_as_zero_T Ideal_CPS_F_as_zero_DW;

/* Real-time model */
static RT_MODEL_Ideal_CPS_F_as_zero_T Ideal_CPS_F_as_zero_M_;
RT_MODEL_Ideal_CPS_F_as_zero_T *const Ideal_CPS_F_as_zero_M =
  &Ideal_CPS_F_as_zero_M_;

/* Model output function */
void Ideal_CPS_F_as_zero_output(void)
{
  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Ideal_CPS_F_as_zero_B.Gain3 = 1.0 / Ideal_CPS_F_as_zero_P.M *
    (Ideal_CPS_F_as_zero_P.Constant_Value -
     Ideal_CPS_F_as_zero_DW.UnitDelay_DSTATE);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator =
    Ideal_CPS_F_as_zero_P.DiscreteTimeIntegrator_gainval *
    Ideal_CPS_F_as_zero_B.Gain3 +
    Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  if (Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator1 =
      Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_DSTATE;
  } else {
    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator1 =
      Ideal_CPS_F_as_zero_P.DiscreteTimeIntegrator1_gainval *
      Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator +
      Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Gain: '<Root>/Gain7' */
  Ideal_CPS_F_as_zero_B.CommandedPosition = Ideal_CPS_F_as_zero_P.Gain7_Gain *
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator1;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product1'
   */
  Ideal_CPS_F_as_zero_B.Sum1 = Ideal_CPS_F_as_zero_P.k *
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator1 + Ideal_CPS_F_as_zero_P.c *
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator;
}

/* Model update function */
void Ideal_CPS_F_as_zero_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  Ideal_CPS_F_as_zero_DW.UnitDelay_DSTATE = Ideal_CPS_F_as_zero_B.Sum1;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator_DSTATE =
    Ideal_CPS_F_as_zero_P.DiscreteTimeIntegrator_gainval *
    Ideal_CPS_F_as_zero_B.Gain3 + Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U;
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_DSTATE =
    Ideal_CPS_F_as_zero_P.DiscreteTimeIntegrator1_gainval *
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator +
    Ideal_CPS_F_as_zero_B.DiscreteTimeIntegrator1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Ideal_CPS_F_as_zero_M->Timing.clockTick0)) {
    ++Ideal_CPS_F_as_zero_M->Timing.clockTickH0;
  }

  Ideal_CPS_F_as_zero_M->Timing.t[0] = Ideal_CPS_F_as_zero_M->Timing.clockTick0 *
    Ideal_CPS_F_as_zero_M->Timing.stepSize0 +
    Ideal_CPS_F_as_zero_M->Timing.clockTickH0 *
    Ideal_CPS_F_as_zero_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Ideal_CPS_F_as_zero_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Ideal_CPS_F_as_zero_DW.UnitDelay_DSTATE =
    Ideal_CPS_F_as_zero_P.start_position_cm * Ideal_CPS_F_as_zero_P.k / 100.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator_DSTATE =
    Ideal_CPS_F_as_zero_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_DSTATE =
    Ideal_CPS_F_as_zero_P.start_position_cm / 100.0;

  /* Enable for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Ideal_CPS_F_as_zero_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE = 1U;
}

/* Model terminate function */
void Ideal_CPS_F_as_zero_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Ideal_CPS_F_as_zero_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Ideal_CPS_F_as_zero_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Ideal_CPS_F_as_zero_initialize();
}

void MdlTerminate(void)
{
  Ideal_CPS_F_as_zero_terminate();
}

/* Registration function */
RT_MODEL_Ideal_CPS_F_as_zero_T *Ideal_CPS_F_as_zero(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Ideal_CPS_F_as_zero_M, 0,
                sizeof(RT_MODEL_Ideal_CPS_F_as_zero_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Ideal_CPS_F_as_zero_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Ideal_CPS_F_as_zero_M points to
       static memory which is guaranteed to be non-NULL" */
    Ideal_CPS_F_as_zero_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Ideal_CPS_F_as_zero_M->Timing.sampleTimes =
      (&Ideal_CPS_F_as_zero_M->Timing.sampleTimesArray[0]);
    Ideal_CPS_F_as_zero_M->Timing.offsetTimes =
      (&Ideal_CPS_F_as_zero_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Ideal_CPS_F_as_zero_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Ideal_CPS_F_as_zero_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Ideal_CPS_F_as_zero_M, &Ideal_CPS_F_as_zero_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Ideal_CPS_F_as_zero_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Ideal_CPS_F_as_zero_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Ideal_CPS_F_as_zero_M, 10.0);
  Ideal_CPS_F_as_zero_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Ideal_CPS_F_as_zero_M->Sizes.checksums[0] = (2742939913U);
  Ideal_CPS_F_as_zero_M->Sizes.checksums[1] = (2069140539U);
  Ideal_CPS_F_as_zero_M->Sizes.checksums[2] = (863892516U);
  Ideal_CPS_F_as_zero_M->Sizes.checksums[3] = (4029030078U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Ideal_CPS_F_as_zero_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Ideal_CPS_F_as_zero_M->extModeInfo,
      &Ideal_CPS_F_as_zero_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Ideal_CPS_F_as_zero_M->extModeInfo,
                        Ideal_CPS_F_as_zero_M->Sizes.checksums);
    rteiSetTPtr(Ideal_CPS_F_as_zero_M->extModeInfo, rtmGetTPtr
                (Ideal_CPS_F_as_zero_M));
  }

  Ideal_CPS_F_as_zero_M->solverInfoPtr = (&Ideal_CPS_F_as_zero_M->solverInfo);
  Ideal_CPS_F_as_zero_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Ideal_CPS_F_as_zero_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Ideal_CPS_F_as_zero_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Ideal_CPS_F_as_zero_M->blockIO = ((void *) &Ideal_CPS_F_as_zero_B);
  (void) memset(((void *) &Ideal_CPS_F_as_zero_B), 0,
                sizeof(B_Ideal_CPS_F_as_zero_T));

  /* parameters */
  Ideal_CPS_F_as_zero_M->defaultParam = ((real_T *)&Ideal_CPS_F_as_zero_P);

  /* states (dwork) */
  Ideal_CPS_F_as_zero_M->dwork = ((void *) &Ideal_CPS_F_as_zero_DW);
  (void) memset((void *)&Ideal_CPS_F_as_zero_DW, 0,
                sizeof(DW_Ideal_CPS_F_as_zero_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Ideal_CPS_F_as_zero_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Ideal_CPS_F_as_zero_M->Sizes.numContStates = (0);/* Number of continuous states */
  Ideal_CPS_F_as_zero_M->Sizes.numY = (0);/* Number of model outputs */
  Ideal_CPS_F_as_zero_M->Sizes.numU = (0);/* Number of model inputs */
  Ideal_CPS_F_as_zero_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Ideal_CPS_F_as_zero_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Ideal_CPS_F_as_zero_M->Sizes.numBlocks = (16);/* Number of blocks */
  Ideal_CPS_F_as_zero_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Ideal_CPS_F_as_zero_M->Sizes.numBlockPrms = (9);/* Sum of parameter "widths" */
  return Ideal_CPS_F_as_zero_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
