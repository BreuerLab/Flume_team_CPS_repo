/*
 * CPS_tare_Eva.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_tare_Eva".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Feb 23 14:12:31 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CPS_tare_Eva.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "CPS_tare_Eva_dt.h"

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

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
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
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "National_Instruments/PCIe-6351", 4294967295U, 7, SLDRTBoardOptions0 },

  { "National_Instruments/PCIe-6353", 4294967295U, 7, SLDRTBoardOptions1 },
};

/* Block signals (default storage) */
B_CPS_tare_Eva_T CPS_tare_Eva_B;

/* Block states (default storage) */
DW_CPS_tare_Eva_T CPS_tare_Eva_DW;

/* Real-time model */
static RT_MODEL_CPS_tare_Eva_T CPS_tare_Eva_M_;
RT_MODEL_CPS_tare_Eva_T *const CPS_tare_Eva_M = &CPS_tare_Eva_M_;

/* Model output function */
void CPS_tare_Eva_output(void)
{
  real_T rtb_TmpSignalConversionAtMeanInport1[7];
  real_T rtb_AnalogInput[6];
  real_T rtb_AnalogInput1;
  int32_T i;
  int32_T index;

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) CPS_tare_Eva_P.AnalogInput_RangeMode;
    parm.rangeidx = CPS_tare_Eva_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 6,
                   CPS_tare_Eva_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                   &parm);
  }

  /* S-Function (sldrtai): '<Root>/Analog Input1' */
  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) CPS_tare_Eva_P.AnalogInput1_RangeMode;
    parm.rangeidx = CPS_tare_Eva_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(1, ANALOGINPUT, IOREAD, 1,
                   &CPS_tare_Eva_P.AnalogInput1_Channels, &rtb_AnalogInput1,
                   &parm);
  }

  /* SignalConversion generated from: '<Root>/Mean' */
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtMeanInport1[i] = rtb_AnalogInput[i];
  }

  rtb_TmpSignalConversionAtMeanInport1[6] = rtb_AnalogInput1;

  /* End of SignalConversion generated from: '<Root>/Mean' */

  /* S-Function (sdspstatfcns): '<Root>/Mean' */
  index = 0;
  CPS_tare_Eva_DW.Mean_Iteration++;
  if (CPS_tare_Eva_DW.Mean_Iteration > 1U) {
    for (i = 0; i < 7; i++) {
      CPS_tare_Eva_DW.Mean_AccVal[i] +=
        rtb_TmpSignalConversionAtMeanInport1[index];
      CPS_tare_Eva_B.Mean[index] = CPS_tare_Eva_DW.Mean_AccVal[i] / (real_T)
        CPS_tare_Eva_DW.Mean_Iteration;
      index++;
    }
  } else {
    if (CPS_tare_Eva_DW.Mean_Iteration == 0U) {
      CPS_tare_Eva_DW.Mean_Iteration = 1U;
    }

    for (i = 0; i < 7; i++) {
      CPS_tare_Eva_DW.Mean_AccVal[i] =
        rtb_TmpSignalConversionAtMeanInport1[index];
      index++;
      CPS_tare_Eva_B.Mean[i] = rtb_TmpSignalConversionAtMeanInport1[i];
    }
  }

  /* End of S-Function (sdspstatfcns): '<Root>/Mean' */
}

/* Model update function */
void CPS_tare_Eva_update(void)
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
  if (!(++CPS_tare_Eva_M->Timing.clockTick0)) {
    ++CPS_tare_Eva_M->Timing.clockTickH0;
  }

  CPS_tare_Eva_M->Timing.t[0] = CPS_tare_Eva_M->Timing.clockTick0 *
    CPS_tare_Eva_M->Timing.stepSize0 + CPS_tare_Eva_M->Timing.clockTickH0 *
    CPS_tare_Eva_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void CPS_tare_Eva_initialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspstatfcns): '<Root>/Mean' */
    CPS_tare_Eva_DW.Mean_Iteration = 0U;
    for (i = 0; i < 7; i++) {
      CPS_tare_Eva_DW.Mean_AccVal[i] = 0.0;
    }

    /* End of InitializeConditions for S-Function (sdspstatfcns): '<Root>/Mean' */
  }
}

/* Model terminate function */
void CPS_tare_Eva_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  CPS_tare_Eva_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CPS_tare_Eva_update();
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
  CPS_tare_Eva_initialize();
}

void MdlTerminate(void)
{
  CPS_tare_Eva_terminate();
}

/* Registration function */
RT_MODEL_CPS_tare_Eva_T *CPS_tare_Eva(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CPS_tare_Eva_M, 0,
                sizeof(RT_MODEL_CPS_tare_Eva_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CPS_tare_Eva_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "CPS_tare_Eva_M points to
       static memory which is guaranteed to be non-NULL" */
    CPS_tare_Eva_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CPS_tare_Eva_M->Timing.sampleTimes =
      (&CPS_tare_Eva_M->Timing.sampleTimesArray[0]);
    CPS_tare_Eva_M->Timing.offsetTimes =
      (&CPS_tare_Eva_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CPS_tare_Eva_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    CPS_tare_Eva_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(CPS_tare_Eva_M, &CPS_tare_Eva_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CPS_tare_Eva_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    CPS_tare_Eva_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CPS_tare_Eva_M, 10.0);
  CPS_tare_Eva_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  CPS_tare_Eva_M->Sizes.checksums[0] = (1142169477U);
  CPS_tare_Eva_M->Sizes.checksums[1] = (307325929U);
  CPS_tare_Eva_M->Sizes.checksums[2] = (3111788138U);
  CPS_tare_Eva_M->Sizes.checksums[3] = (2574208948U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    CPS_tare_Eva_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CPS_tare_Eva_M->extModeInfo,
      &CPS_tare_Eva_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CPS_tare_Eva_M->extModeInfo,
                        CPS_tare_Eva_M->Sizes.checksums);
    rteiSetTPtr(CPS_tare_Eva_M->extModeInfo, rtmGetTPtr(CPS_tare_Eva_M));
  }

  CPS_tare_Eva_M->solverInfoPtr = (&CPS_tare_Eva_M->solverInfo);
  CPS_tare_Eva_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CPS_tare_Eva_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CPS_tare_Eva_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CPS_tare_Eva_M->blockIO = ((void *) &CPS_tare_Eva_B);
  (void) memset(((void *) &CPS_tare_Eva_B), 0,
                sizeof(B_CPS_tare_Eva_T));

  /* parameters */
  CPS_tare_Eva_M->defaultParam = ((real_T *)&CPS_tare_Eva_P);

  /* states (dwork) */
  CPS_tare_Eva_M->dwork = ((void *) &CPS_tare_Eva_DW);
  (void) memset((void *)&CPS_tare_Eva_DW, 0,
                sizeof(DW_CPS_tare_Eva_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    CPS_tare_Eva_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  CPS_tare_Eva_M->Sizes.numContStates = (0);/* Number of continuous states */
  CPS_tare_Eva_M->Sizes.numY = (0);    /* Number of model outputs */
  CPS_tare_Eva_M->Sizes.numU = (0);    /* Number of model inputs */
  CPS_tare_Eva_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CPS_tare_Eva_M->Sizes.numSampTimes = (1);/* Number of sample times */
  CPS_tare_Eva_M->Sizes.numBlocks = (6);/* Number of blocks */
  CPS_tare_Eva_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  CPS_tare_Eva_M->Sizes.numBlockPrms = (15);/* Sum of parameter "widths" */
  return CPS_tare_Eva_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
