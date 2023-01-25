/*
 * CPS_tare_forceandaccel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_tare_forceandaccel".
 *
 * Model version              : 1.61
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jan 20 15:18:56 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CPS_tare_forceandaccel.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "CPS_tare_forceandaccel_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6353", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_CPS_tare_forceandaccel_T CPS_tare_forceandaccel_B;

/* Block states (default storage) */
DW_CPS_tare_forceandaccel_T CPS_tare_forceandaccel_DW;

/* Real-time model */
static RT_MODEL_CPS_tare_forceandaccel_T CPS_tare_forceandaccel_M_;
RT_MODEL_CPS_tare_forceandaccel_T *const CPS_tare_forceandaccel_M =
  &CPS_tare_forceandaccel_M_;

/* Model output function */
void CPS_tare_forceandaccel_output(void)
{
  real_T rtb_AnalogInput1[7];
  int32_T i;
  int32_T index;

  /* S-Function (sldrtai): '<Root>/Analog Input1' */
  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) CPS_tare_forceandaccel_P.AnalogInput1_RangeMode;
    parm.rangeidx = CPS_tare_forceandaccel_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 7,
                   CPS_tare_forceandaccel_P.AnalogInput1_Channels,
                   &rtb_AnalogInput1[0], &parm);
  }

  /* S-Function (sdspstatfcns): '<Root>/Mean' */
  index = 0;
  CPS_tare_forceandaccel_DW.Mean_Iteration++;
  if (CPS_tare_forceandaccel_DW.Mean_Iteration > 1U) {
    for (i = 0; i < 7; i++) {
      CPS_tare_forceandaccel_DW.Mean_AccVal[i] += rtb_AnalogInput1[index];
      CPS_tare_forceandaccel_B.Mean[index] =
        CPS_tare_forceandaccel_DW.Mean_AccVal[i] / (real_T)
        CPS_tare_forceandaccel_DW.Mean_Iteration;
      index++;
    }
  } else {
    if (CPS_tare_forceandaccel_DW.Mean_Iteration == 0U) {
      CPS_tare_forceandaccel_DW.Mean_Iteration = 1U;
    }

    for (i = 0; i < 7; i++) {
      CPS_tare_forceandaccel_DW.Mean_AccVal[i] = rtb_AnalogInput1[index];
      index++;
      CPS_tare_forceandaccel_B.Mean[i] = rtb_AnalogInput1[i];
    }
  }

  /* End of S-Function (sdspstatfcns): '<Root>/Mean' */
}

/* Model update function */
void CPS_tare_forceandaccel_update(void)
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
  if (!(++CPS_tare_forceandaccel_M->Timing.clockTick0)) {
    ++CPS_tare_forceandaccel_M->Timing.clockTickH0;
  }

  CPS_tare_forceandaccel_M->Timing.t[0] =
    CPS_tare_forceandaccel_M->Timing.clockTick0 *
    CPS_tare_forceandaccel_M->Timing.stepSize0 +
    CPS_tare_forceandaccel_M->Timing.clockTickH0 *
    CPS_tare_forceandaccel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void CPS_tare_forceandaccel_initialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspstatfcns): '<Root>/Mean' */
    CPS_tare_forceandaccel_DW.Mean_Iteration = 0U;
    for (i = 0; i < 7; i++) {
      CPS_tare_forceandaccel_DW.Mean_AccVal[i] = 0.0;
    }

    /* End of InitializeConditions for S-Function (sdspstatfcns): '<Root>/Mean' */
  }
}

/* Model terminate function */
void CPS_tare_forceandaccel_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  CPS_tare_forceandaccel_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CPS_tare_forceandaccel_update();
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
  CPS_tare_forceandaccel_initialize();
}

void MdlTerminate(void)
{
  CPS_tare_forceandaccel_terminate();
}

/* Registration function */
RT_MODEL_CPS_tare_forceandaccel_T *CPS_tare_forceandaccel(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CPS_tare_forceandaccel_M, 0,
                sizeof(RT_MODEL_CPS_tare_forceandaccel_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CPS_tare_forceandaccel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "CPS_tare_forceandaccel_M points to
       static memory which is guaranteed to be non-NULL" */
    CPS_tare_forceandaccel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CPS_tare_forceandaccel_M->Timing.sampleTimes =
      (&CPS_tare_forceandaccel_M->Timing.sampleTimesArray[0]);
    CPS_tare_forceandaccel_M->Timing.offsetTimes =
      (&CPS_tare_forceandaccel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CPS_tare_forceandaccel_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    CPS_tare_forceandaccel_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(CPS_tare_forceandaccel_M, &CPS_tare_forceandaccel_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = CPS_tare_forceandaccel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    CPS_tare_forceandaccel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CPS_tare_forceandaccel_M, 5.0);
  CPS_tare_forceandaccel_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  CPS_tare_forceandaccel_M->Sizes.checksums[0] = (4262258124U);
  CPS_tare_forceandaccel_M->Sizes.checksums[1] = (3052245342U);
  CPS_tare_forceandaccel_M->Sizes.checksums[2] = (265981964U);
  CPS_tare_forceandaccel_M->Sizes.checksums[3] = (3835893639U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    CPS_tare_forceandaccel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CPS_tare_forceandaccel_M->extModeInfo,
      &CPS_tare_forceandaccel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CPS_tare_forceandaccel_M->extModeInfo,
                        CPS_tare_forceandaccel_M->Sizes.checksums);
    rteiSetTPtr(CPS_tare_forceandaccel_M->extModeInfo, rtmGetTPtr
                (CPS_tare_forceandaccel_M));
  }

  CPS_tare_forceandaccel_M->solverInfoPtr =
    (&CPS_tare_forceandaccel_M->solverInfo);
  CPS_tare_forceandaccel_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CPS_tare_forceandaccel_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CPS_tare_forceandaccel_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CPS_tare_forceandaccel_M->blockIO = ((void *) &CPS_tare_forceandaccel_B);
  (void) memset(((void *) &CPS_tare_forceandaccel_B), 0,
                sizeof(B_CPS_tare_forceandaccel_T));

  /* parameters */
  CPS_tare_forceandaccel_M->defaultParam = ((real_T *)&CPS_tare_forceandaccel_P);

  /* states (dwork) */
  CPS_tare_forceandaccel_M->dwork = ((void *) &CPS_tare_forceandaccel_DW);
  (void) memset((void *)&CPS_tare_forceandaccel_DW, 0,
                sizeof(DW_CPS_tare_forceandaccel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    CPS_tare_forceandaccel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  CPS_tare_forceandaccel_M->Sizes.numContStates = (0);/* Number of continuous states */
  CPS_tare_forceandaccel_M->Sizes.numY = (0);/* Number of model outputs */
  CPS_tare_forceandaccel_M->Sizes.numU = (0);/* Number of model inputs */
  CPS_tare_forceandaccel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CPS_tare_forceandaccel_M->Sizes.numSampTimes = (1);/* Number of sample times */
  CPS_tare_forceandaccel_M->Sizes.numBlocks = (4);/* Number of blocks */
  CPS_tare_forceandaccel_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  CPS_tare_forceandaccel_M->Sizes.numBlockPrms = (11);/* Sum of parameter "widths" */
  return CPS_tare_forceandaccel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
