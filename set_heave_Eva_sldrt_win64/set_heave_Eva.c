/*
 * set_heave_Eva.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "set_heave_Eva".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Feb  2 16:57:23 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "set_heave_Eva.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "set_heave_Eva_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  2.0,
  2.0,
  2.0,
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
B_set_heave_Eva_T set_heave_Eva_B;

/* Block states (default storage) */
DW_set_heave_Eva_T set_heave_Eva_DW;

/* Real-time model */
static RT_MODEL_set_heave_Eva_T set_heave_Eva_M_;
RT_MODEL_set_heave_Eva_T *const set_heave_Eva_M = &set_heave_Eva_M_;

/* Model output function */
void set_heave_Eva_output(void)
{
  real_T rtb_EncoderInput;
  real_T rtb_Sum;

  /* Sin: '<Root>/Sine Wave1' */
  if (set_heave_Eva_DW.systemEnable != 0) {
    rtb_EncoderInput = 1.0 / (2.0 * set_heave_Eva_P.duration) * 6.28 *
      set_heave_Eva_M->Timing.t[0];
    set_heave_Eva_DW.lastSin = sin(rtb_EncoderInput);
    set_heave_Eva_DW.lastCos = cos(rtb_EncoderInput);
    set_heave_Eva_DW.systemEnable = 0;
  }

  rtb_EncoderInput = ((set_heave_Eva_DW.lastSin * set_heave_Eva_P.SineWave1_PCos
                       + set_heave_Eva_DW.lastCos *
                       set_heave_Eva_P.SineWave1_PSin) *
                      set_heave_Eva_P.SineWave1_HCos + (set_heave_Eva_DW.lastCos
    * set_heave_Eva_P.SineWave1_PCos - set_heave_Eva_DW.lastSin *
    set_heave_Eva_P.SineWave1_PSin) * set_heave_Eva_P.SineWave1_Hsin) *
    set_heave_Eva_P.SineWave1_Amp + set_heave_Eva_P.SineWave1_Bias;

  /* End of Sin: '<Root>/Sine Wave1' */

  /* Constant: '<Root>/Constant1' */
  set_heave_Eva_B.Constant1 = set_heave_Eva_P.Constant1_Value;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Sum: '<Root>/Sum1'
   */
  rtb_Sum = (set_heave_Eva_B.Constant1 - set_heave_Eva_P.start_position_cm) *
    set_heave_Eva_P.Gain1_Gain;

  /* Sum: '<Root>/Sum' incorporates:
   *  Bias: '<Root>/Bias'
   *  Product: '<Root>/Product'
   */
  rtb_Sum += rtb_EncoderInput * rtb_Sum + set_heave_Eva_P.start_position_cm /
    -3.0;

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) set_heave_Eva_P.AnalogOutput_RangeMode;
      parm.rangeidx = set_heave_Eva_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &set_heave_Eva_P.AnalogOutput_Channels, ((real_T*)
        (&rtb_Sum)), &parm);
    }
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = set_heave_Eva_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &set_heave_Eva_P.EncoderInput_Channels, &rtb_EncoderInput,
                   &parm);
  }

  /* Bias: '<Root>/Bias3' incorporates:
   *  Gain: '<Root>/Gain8'
   */
  set_heave_Eva_B.MeasuredPosition = set_heave_Eva_P.Gain8_Gain *
    rtb_EncoderInput + set_heave_Eva_P.start_position_cm;

  /* Gain: '<Root>/Gain7' */
  set_heave_Eva_B.CommandedPosition = set_heave_Eva_P.Gain7_Gain * rtb_Sum;
}

/* Model update function */
void set_heave_Eva_update(void)
{
  real_T HoldSine;

  /* Update for Sin: '<Root>/Sine Wave1' */
  HoldSine = set_heave_Eva_DW.lastSin;
  set_heave_Eva_DW.lastSin = set_heave_Eva_DW.lastSin *
    set_heave_Eva_P.SineWave1_HCos + set_heave_Eva_DW.lastCos *
    set_heave_Eva_P.SineWave1_Hsin;
  set_heave_Eva_DW.lastCos = set_heave_Eva_DW.lastCos *
    set_heave_Eva_P.SineWave1_HCos - HoldSine * set_heave_Eva_P.SineWave1_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++set_heave_Eva_M->Timing.clockTick0)) {
    ++set_heave_Eva_M->Timing.clockTickH0;
  }

  set_heave_Eva_M->Timing.t[0] = set_heave_Eva_M->Timing.clockTick0 *
    set_heave_Eva_M->Timing.stepSize0 + set_heave_Eva_M->Timing.clockTickH0 *
    set_heave_Eva_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void set_heave_Eva_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */

  /* no initial value should be set */

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = set_heave_Eva_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &set_heave_Eva_P.EncoderInput_Channels, NULL, &parm);
  }

  /* Enable for Sin: '<Root>/Sine Wave1' */
  set_heave_Eva_DW.systemEnable = 1;
}

/* Model terminate function */
void set_heave_Eva_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  set_heave_Eva_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  set_heave_Eva_update();
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
  set_heave_Eva_initialize();
}

void MdlTerminate(void)
{
  set_heave_Eva_terminate();
}

/* Registration function */
RT_MODEL_set_heave_Eva_T *set_heave_Eva(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  set_heave_Eva_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)set_heave_Eva_M, 0,
                sizeof(RT_MODEL_set_heave_Eva_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = set_heave_Eva_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "set_heave_Eva_M points to
       static memory which is guaranteed to be non-NULL" */
    set_heave_Eva_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    set_heave_Eva_M->Timing.sampleTimes =
      (&set_heave_Eva_M->Timing.sampleTimesArray[0]);
    set_heave_Eva_M->Timing.offsetTimes =
      (&set_heave_Eva_M->Timing.offsetTimesArray[0]);

    /* task periods */
    set_heave_Eva_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    set_heave_Eva_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(set_heave_Eva_M, &set_heave_Eva_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = set_heave_Eva_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    set_heave_Eva_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(set_heave_Eva_M, 10.0);
  set_heave_Eva_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  set_heave_Eva_M->Sizes.checksums[0] = (3525131322U);
  set_heave_Eva_M->Sizes.checksums[1] = (774694463U);
  set_heave_Eva_M->Sizes.checksums[2] = (72691472U);
  set_heave_Eva_M->Sizes.checksums[3] = (638309872U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    set_heave_Eva_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(set_heave_Eva_M->extModeInfo,
      &set_heave_Eva_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(set_heave_Eva_M->extModeInfo,
                        set_heave_Eva_M->Sizes.checksums);
    rteiSetTPtr(set_heave_Eva_M->extModeInfo, rtmGetTPtr(set_heave_Eva_M));
  }

  set_heave_Eva_M->solverInfoPtr = (&set_heave_Eva_M->solverInfo);
  set_heave_Eva_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&set_heave_Eva_M->solverInfo, 0.001);
  rtsiSetSolverMode(&set_heave_Eva_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  set_heave_Eva_M->blockIO = ((void *) &set_heave_Eva_B);
  (void) memset(((void *) &set_heave_Eva_B), 0,
                sizeof(B_set_heave_Eva_T));

  /* parameters */
  set_heave_Eva_M->defaultParam = ((real_T *)&set_heave_Eva_P);

  /* states (dwork) */
  set_heave_Eva_M->dwork = ((void *) &set_heave_Eva_DW);
  (void) memset((void *)&set_heave_Eva_DW, 0,
                sizeof(DW_set_heave_Eva_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    set_heave_Eva_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  set_heave_Eva_M->Sizes.numContStates = (0);/* Number of continuous states */
  set_heave_Eva_M->Sizes.numY = (0);   /* Number of model outputs */
  set_heave_Eva_M->Sizes.numU = (0);   /* Number of model inputs */
  set_heave_Eva_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  set_heave_Eva_M->Sizes.numSampTimes = (1);/* Number of sample times */
  set_heave_Eva_M->Sizes.numBlocks = (16);/* Number of blocks */
  set_heave_Eva_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  set_heave_Eva_M->Sizes.numBlockPrms = (21);/* Sum of parameter "widths" */
  return set_heave_Eva_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
