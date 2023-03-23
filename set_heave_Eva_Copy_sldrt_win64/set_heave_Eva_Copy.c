/*
 * set_heave_Eva_Copy.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "set_heave_Eva_Copy".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sun Mar 19 20:35:04 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "set_heave_Eva_Copy.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "set_heave_Eva_Copy_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* Block signals (default storage) */
B_set_heave_Eva_Copy_T set_heave_Eva_Copy_B;

/* Block states (default storage) */
DW_set_heave_Eva_Copy_T set_heave_Eva_Copy_DW;

/* Real-time model */
static RT_MODEL_set_heave_Eva_Copy_T set_heave_Eva_Copy_M_;
RT_MODEL_set_heave_Eva_Copy_T *const set_heave_Eva_Copy_M =
  &set_heave_Eva_Copy_M_;

/* Model output function */
void set_heave_Eva_Copy_output(void)
{
  /* Constant: '<Root>/Constant1' */
  set_heave_Eva_Copy_B.Constant1 = set_heave_Eva_Copy_P.Constant1_Value;
}

/* Model update function */
void set_heave_Eva_Copy_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++set_heave_Eva_Copy_M->Timing.clockTick0)) {
    ++set_heave_Eva_Copy_M->Timing.clockTickH0;
  }

  set_heave_Eva_Copy_M->Timing.t[0] = set_heave_Eva_Copy_M->Timing.clockTick0 *
    set_heave_Eva_Copy_M->Timing.stepSize0 +
    set_heave_Eva_Copy_M->Timing.clockTickH0 *
    set_heave_Eva_Copy_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void set_heave_Eva_Copy_initialize(void)
{
}

/* Model terminate function */
void set_heave_Eva_Copy_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  set_heave_Eva_Copy_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  set_heave_Eva_Copy_update();
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
  set_heave_Eva_Copy_initialize();
}

void MdlTerminate(void)
{
  set_heave_Eva_Copy_terminate();
}

/* Registration function */
RT_MODEL_set_heave_Eva_Copy_T *set_heave_Eva_Copy(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)set_heave_Eva_Copy_M, 0,
                sizeof(RT_MODEL_set_heave_Eva_Copy_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = set_heave_Eva_Copy_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "set_heave_Eva_Copy_M points to
       static memory which is guaranteed to be non-NULL" */
    set_heave_Eva_Copy_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    set_heave_Eva_Copy_M->Timing.sampleTimes =
      (&set_heave_Eva_Copy_M->Timing.sampleTimesArray[0]);
    set_heave_Eva_Copy_M->Timing.offsetTimes =
      (&set_heave_Eva_Copy_M->Timing.offsetTimesArray[0]);

    /* task periods */
    set_heave_Eva_Copy_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    set_heave_Eva_Copy_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(set_heave_Eva_Copy_M, &set_heave_Eva_Copy_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = set_heave_Eva_Copy_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    set_heave_Eva_Copy_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(set_heave_Eva_Copy_M, 7.0);
  set_heave_Eva_Copy_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  set_heave_Eva_Copy_M->Sizes.checksums[0] = (2518340979U);
  set_heave_Eva_Copy_M->Sizes.checksums[1] = (1526885587U);
  set_heave_Eva_Copy_M->Sizes.checksums[2] = (1873854579U);
  set_heave_Eva_Copy_M->Sizes.checksums[3] = (4261878478U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    set_heave_Eva_Copy_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(set_heave_Eva_Copy_M->extModeInfo,
      &set_heave_Eva_Copy_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(set_heave_Eva_Copy_M->extModeInfo,
                        set_heave_Eva_Copy_M->Sizes.checksums);
    rteiSetTPtr(set_heave_Eva_Copy_M->extModeInfo, rtmGetTPtr
                (set_heave_Eva_Copy_M));
  }

  set_heave_Eva_Copy_M->solverInfoPtr = (&set_heave_Eva_Copy_M->solverInfo);
  set_heave_Eva_Copy_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&set_heave_Eva_Copy_M->solverInfo, 0.001);
  rtsiSetSolverMode(&set_heave_Eva_Copy_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  set_heave_Eva_Copy_M->blockIO = ((void *) &set_heave_Eva_Copy_B);
  (void) memset(((void *) &set_heave_Eva_Copy_B), 0,
                sizeof(B_set_heave_Eva_Copy_T));

  /* parameters */
  set_heave_Eva_Copy_M->defaultParam = ((real_T *)&set_heave_Eva_Copy_P);

  /* states (dwork) */
  set_heave_Eva_Copy_M->dwork = ((void *) &set_heave_Eva_Copy_DW);
  (void) memset((void *)&set_heave_Eva_Copy_DW, 0,
                sizeof(DW_set_heave_Eva_Copy_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    set_heave_Eva_Copy_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  set_heave_Eva_Copy_M->Sizes.numContStates = (0);/* Number of continuous states */
  set_heave_Eva_Copy_M->Sizes.numY = (0);/* Number of model outputs */
  set_heave_Eva_Copy_M->Sizes.numU = (0);/* Number of model inputs */
  set_heave_Eva_Copy_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  set_heave_Eva_Copy_M->Sizes.numSampTimes = (1);/* Number of sample times */
  set_heave_Eva_Copy_M->Sizes.numBlocks = (3);/* Number of blocks */
  set_heave_Eva_Copy_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  set_heave_Eva_Copy_M->Sizes.numBlockPrms = (1);/* Sum of parameter "widths" */
  return set_heave_Eva_Copy_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
