/*
 * CPS_Eva.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_Eva".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Feb 23 14:37:36 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CPS_Eva.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "CPS_Eva_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "CPS_Eva_dt.h"

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
  { "National_Instruments/PCIe-6353", 4294967295U, 7, SLDRTBoardOptions0 },

  { "National_Instruments/PCIe-6351", 4294967295U, 7, SLDRTBoardOptions1 },
};

/* Block signals (default storage) */
B_CPS_Eva_T CPS_Eva_B;

/* Continuous states */
X_CPS_Eva_T CPS_Eva_X;

/* Block states (default storage) */
DW_CPS_Eva_T CPS_Eva_DW;

/* Real-time model */
static RT_MODEL_CPS_Eva_T CPS_Eva_M_;
RT_MODEL_CPS_Eva_T *const CPS_Eva_M = &CPS_Eva_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CPS_Eva_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  CPS_Eva_output();
  CPS_Eva_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  CPS_Eva_output();
  CPS_Eva_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  CPS_Eva_output();
  CPS_Eva_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  CPS_Eva_output();
  CPS_Eva_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  CPS_Eva_output();
  CPS_Eva_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void CPS_Eva_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  real_T tmp[36];
  real_T rtb_Bias[6];
  real_T rtb_Bias_0[6];
  real_T rtb_AnalogInput1[4];
  real_T rtb_CPSorReference;
  real_T rtb_EncoderInput;
  int32_T i;
  int32_T i_0;
  uint32_T ri;
  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    /* set solver stop time */
    if (!(CPS_Eva_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&CPS_Eva_M->solverInfo,
                            ((CPS_Eva_M->Timing.clockTickH0 + 1) *
        CPS_Eva_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&CPS_Eva_M->solverInfo,
                            ((CPS_Eva_M->Timing.clockTick0 + 1) *
        CPS_Eva_M->Timing.stepSize0 + CPS_Eva_M->Timing.clockTickH0 *
        CPS_Eva_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CPS_Eva_M)) {
    CPS_Eva_M->Timing.t[0] = rtsiGetT(&CPS_Eva_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    /* UnitDelay: '<Root>/Unit Delay' */
    CPS_Eva_B.UnitDelay = CPS_Eva_DW.UnitDelay_DSTATE;
  }

  /* StateSpace: '<Root>/Analog Filter Design' */
  CPS_Eva_B.AnalogFilterDesign = 0.0;

  /* StateSpace: '<Root>/Analog Filter Design' */
  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[0U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[1U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.AnalogFilterDesign += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[0U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[1U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[2U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.AnalogFilterDesign += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[1U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[2U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[3U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.AnalogFilterDesign += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[2U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[3U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[4U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.AnalogFilterDesign += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[3U];
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_CPSorReference = 1.0 / CPS_Eva_P.M * (CPS_Eva_B.AnalogFilterDesign -
    CPS_Eva_B.UnitDelay);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_CPSorReference > CPS_Eva_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = CPS_Eva_P.Saturation_UpperSat;
  } else if (rtb_CPSorReference < CPS_Eva_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = CPS_Eva_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = rtb_CPSorReference;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    CPS_Eva_B.DiscreteTimeIntegrator = CPS_Eva_P.DiscreteTimeIntegrator_gainval *
      CPS_Eva_B.Saturation + CPS_Eva_DW.DiscreteTimeIntegrator_DSTATE;

    /* Saturate: '<Root>/Saturation1' */
    if (CPS_Eva_B.DiscreteTimeIntegrator > CPS_Eva_P.Saturation1_UpperSat) {
      /* Saturate: '<Root>/Saturation1' */
      CPS_Eva_B.Saturation1 = CPS_Eva_P.Saturation1_UpperSat;
    } else if (CPS_Eva_B.DiscreteTimeIntegrator < CPS_Eva_P.Saturation1_LowerSat)
    {
      /* Saturate: '<Root>/Saturation1' */
      CPS_Eva_B.Saturation1 = CPS_Eva_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation1' */
      CPS_Eva_B.Saturation1 = CPS_Eva_B.DiscreteTimeIntegrator;
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    if (CPS_Eva_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
      CPS_Eva_B.DiscreteTimeIntegrator1 =
        CPS_Eva_DW.DiscreteTimeIntegrator1_DSTATE;
    } else {
      /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
      CPS_Eva_B.DiscreteTimeIntegrator1 =
        CPS_Eva_P.DiscreteTimeIntegrator1_gainval * CPS_Eva_B.Saturation1 +
        CPS_Eva_DW.DiscreteTimeIntegrator1_DSTATE;
    }

    /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

    /* Saturate: '<Root>/Saturation2' */
    if (CPS_Eva_B.DiscreteTimeIntegrator1 > CPS_Eva_P.Saturation2_UpperSat) {
      /* Saturate: '<Root>/Saturation2' */
      CPS_Eva_B.Saturation2 = CPS_Eva_P.Saturation2_UpperSat;
    } else if (CPS_Eva_B.DiscreteTimeIntegrator1 <
               CPS_Eva_P.Saturation2_LowerSat) {
      /* Saturate: '<Root>/Saturation2' */
      CPS_Eva_B.Saturation2 = CPS_Eva_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation2' */
      CPS_Eva_B.Saturation2 = CPS_Eva_B.DiscreteTimeIntegrator1;
    }

    /* End of Saturate: '<Root>/Saturation2' */
  }

  /* FromWorkspace: '<S1>/FromWs' */
  {
    real_T *pDataValues = (real_T *) CPS_Eva_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) CPS_Eva_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = CPS_Eva_DW.FromWs_IWORK.PrevIndex;
    real_T t = CPS_Eva_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[2994]) {
      currTimeIndex = 2993;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    CPS_Eva_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWs = pDataValues[currTimeIndex];
        } else {
          rtb_FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 2995;
      }
    }
  }

  /* ManualSwitch: '<Root>/CPS or Reference' incorporates:
   *  ManualSwitch: '<Root>/Signal or zero'
   */
  if (CPS_Eva_P.CPSorReference_CurrentSetting == 1) {
    rtb_CPSorReference = CPS_Eva_B.Saturation2;
  } else if (CPS_Eva_P.Signalorzero_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Sine or custom trajectory' incorporates:
     *  ManualSwitch: '<Root>/Signal or zero'
     *  Sin: '<Root>/Sine Wave'
     */
    if (CPS_Eva_P.Sineorcustomtrajectory_CurrentSetting == 1) {
      rtb_CPSorReference = sin(CPS_Eva_P.SineWave_Freq * CPS_Eva_M->Timing.t[0]
        + CPS_Eva_P.SineWave_Phase) * CPS_Eva_P.SineWave_Amp +
        CPS_Eva_P.SineWave_Bias;
    } else {
      rtb_CPSorReference = rtb_FromWs;
    }

    /* End of ManualSwitch: '<Root>/Sine or custom trajectory' */
  } else {
    /* ManualSwitch: '<Root>/Signal or zero' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    rtb_CPSorReference = CPS_Eva_P.Constant3_Value;
  }

  /* End of ManualSwitch: '<Root>/CPS or Reference' */

  /* Gain: '<Root>/Gain6' */
  CPS_Eva_B.Gain6 = CPS_Eva_P.Gain6_Gain * rtb_CPSorReference;
  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    /* ManualSwitch: '<Root>/zero pitch or constant' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Constant: '<Root>/Constant4'
     *  Gain: '<Root>/Gain9'
     */
    if (CPS_Eva_P.zeropitchorconstant_CurrentSetting == 1) {
      rtb_CPSorReference = CPS_Eva_P.Constant3_Value;
    } else {
      rtb_CPSorReference = CPS_Eva_P.Gain9_Gain * CPS_Eva_P.Constant4_Value;
    }

    /* End of ManualSwitch: '<Root>/zero pitch or constant' */

    /* Gain: '<Root>/Gain10' */
    rtb_CPSorReference *= CPS_Eva_P.Gain10_Gain;

    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) CPS_Eva_P.AnalogOutput_RangeMode;
        parm.rangeidx = CPS_Eva_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &CPS_Eva_P.AnalogOutput_Channels, ((real_T*)
          (&CPS_Eva_B.Gain6)), &parm);
      }
    }

    /* S-Function (sldrtao): '<Root>/Analog Output1' */
    /* S-Function Block: <Root>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) CPS_Eva_P.AnalogOutput1_RangeMode;
        parm.rangeidx = CPS_Eva_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &CPS_Eva_P.AnalogOutput1_Channels, ((real_T*)
          (&rtb_CPSorReference)), &parm);
      }
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) CPS_Eva_P.AnalogInput_RangeMode;
      parm.rangeidx = CPS_Eva_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 6, CPS_Eva_P.AnalogInput_Channels,
                     &rtb_Bias[0], &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input2' */
    /* S-Function Block: <Root>/Analog Input2 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) CPS_Eva_P.AnalogInput2_RangeMode;
      parm.rangeidx = CPS_Eva_P.AnalogInput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &CPS_Eva_P.AnalogInput2_Channels,
                     &rtb_CPSorReference, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input1' */
    /* S-Function Block: <Root>/Analog Input1 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) CPS_Eva_P.AnalogInput1_RangeMode;
      parm.rangeidx = CPS_Eva_P.AnalogInput1_VoltRange;
      RTBIO_DriverIO(1, ANALOGINPUT, IOREAD, 4, CPS_Eva_P.AnalogInput1_Channels,
                     &rtb_AnalogInput1[0], &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = CPS_Eva_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &CPS_Eva_P.EncoderInput_Channels, &rtb_EncoderInput, &parm);
    }

    for (i = 0; i <= 4; i += 2) {
      __m128d tmp_0;

      /* Bias: '<Root>/Bias' */
      tmp_0 = _mm_loadu_pd(&rtb_Bias[i]);
      _mm_storeu_pd(&rtb_Bias_0[i], _mm_add_pd(tmp_0, _mm_loadu_pd
        (&CPS_Eva_P.Bias_Bias[i])));
    }

    for (i = 0; i <= 34; i += 2) {
      /* Gain: '<Root>/Gain' */
      _mm_storeu_pd(&tmp[i], _mm_mul_pd(_mm_loadu_pd
        (&CPS_Eva_P.Gromit_Cal_tranp[i]), _mm_set1_pd(-1.0)));
    }

    for (i = 0; i < 6; i++) {
      /* Gain: '<Root>/Gain' */
      CPS_Eva_B.Gain[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        CPS_Eva_B.Gain[i] += tmp[6 * i + i_0] * rtb_Bias_0[i_0];
      }

      /* End of Gain: '<Root>/Gain' */
    }

    /* Gain: '<Root>/Gain11' */
    CPS_Eva_B.Gain11 = CPS_Eva_P.Gain11_Gain * CPS_Eva_B.Gain[5];

    /* Gain: '<Root>/Gain5' */
    CPS_Eva_B.Gain5 = CPS_Eva_P.Gain5_Gain * CPS_Eva_B.Gain[1];

    /* Gain: '<Root>/Gain2' incorporates:
     *  Bias: '<Root>/Bias1'
     *  Gain: '<Root>/Gain1'
     */
    CPS_Eva_B.Gain2 = (rtb_CPSorReference + CPS_Eva_P.Bias1_Bias) *
      CPS_Eva_P.Gain1_Gain * (CPS_Eva_P.mass_of_cylinder + 0.6);

    /* SignalConversion generated from: '<Root>/To Workspace1' */
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[0] = CPS_Eva_B.Gain5;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[1] = CPS_Eva_B.Gain[0];
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[2] = CPS_Eva_B.Gain2;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[3] =
      CPS_Eva_B.AnalogFilterDesign;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[4] = CPS_Eva_B.Gain11;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product1'
     */
    CPS_Eva_B.Sum1 = CPS_Eva_P.k * CPS_Eva_B.Saturation2 + CPS_Eva_P.c *
      CPS_Eva_B.Saturation1;

    /* Gain: '<Root>/Gain4' incorporates:
     *  Bias: '<Root>/Bias2'
     */
    CPS_Eva_B.Gain4[0] = (rtb_AnalogInput1[0] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[1] = (rtb_AnalogInput1[1] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[2] = (rtb_AnalogInput1[2] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[3] = (rtb_AnalogInput1[3] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;

    /* Bias: '<Root>/Bias3' incorporates:
     *  Gain: '<Root>/Gain8'
     */
    CPS_Eva_B.MeasuredPosition = CPS_Eva_P.Gain8_Gain * rtb_EncoderInput +
      CPS_Eva_P.start_position_cm;
  }
}

/* Model update function */
void CPS_Eva_update(void)
{
  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    CPS_Eva_DW.UnitDelay_DSTATE = CPS_Eva_B.Sum1;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    CPS_Eva_DW.DiscreteTimeIntegrator_DSTATE =
      CPS_Eva_P.DiscreteTimeIntegrator_gainval * CPS_Eva_B.Saturation +
      CPS_Eva_B.DiscreteTimeIntegrator;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    CPS_Eva_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U;
    CPS_Eva_DW.DiscreteTimeIntegrator1_DSTATE =
      CPS_Eva_P.DiscreteTimeIntegrator1_gainval * CPS_Eva_B.Saturation1 +
      CPS_Eva_B.DiscreteTimeIntegrator1;
  }

  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    rt_ertODEUpdateContinuousStates(&CPS_Eva_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CPS_Eva_M->Timing.clockTick0)) {
    ++CPS_Eva_M->Timing.clockTickH0;
  }

  CPS_Eva_M->Timing.t[0] = rtsiGetSolverStopTime(&CPS_Eva_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++CPS_Eva_M->Timing.clockTick1)) {
      ++CPS_Eva_M->Timing.clockTickH1;
    }

    CPS_Eva_M->Timing.t[1] = CPS_Eva_M->Timing.clockTick1 *
      CPS_Eva_M->Timing.stepSize1 + CPS_Eva_M->Timing.clockTickH1 *
      CPS_Eva_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void CPS_Eva_derivatives(void)
{
  XDot_CPS_Eva_T *_rtXdot;
  uint32_T ri;
  _rtXdot = ((XDot_CPS_Eva_T *) CPS_Eva_M->derivs);

  /* Derivatives for StateSpace: '<Root>/Analog Filter Design' */
  _rtXdot->AnalogFilterDesign_CSTATE[0] = 0.0;
  _rtXdot->AnalogFilterDesign_CSTATE[1] = 0.0;
  _rtXdot->AnalogFilterDesign_CSTATE[2] = 0.0;
  _rtXdot->AnalogFilterDesign_CSTATE[3] = 0.0;
  for (ri = CPS_Eva_P.AnalogFilterDesign_A_jc[0U]; ri <
       CPS_Eva_P.AnalogFilterDesign_A_jc[1U]; ri++) {
    _rtXdot->AnalogFilterDesign_CSTATE[CPS_Eva_P.AnalogFilterDesign_A_ir[ri]] +=
      CPS_Eva_P.AnalogFilterDesign_A_pr[ri] *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[0U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_A_jc[1U]; ri <
       CPS_Eva_P.AnalogFilterDesign_A_jc[2U]; ri++) {
    _rtXdot->AnalogFilterDesign_CSTATE[CPS_Eva_P.AnalogFilterDesign_A_ir[ri]] +=
      CPS_Eva_P.AnalogFilterDesign_A_pr[ri] *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[1U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_A_jc[2U]; ri <
       CPS_Eva_P.AnalogFilterDesign_A_jc[3U]; ri++) {
    _rtXdot->AnalogFilterDesign_CSTATE[CPS_Eva_P.AnalogFilterDesign_A_ir[ri]] +=
      CPS_Eva_P.AnalogFilterDesign_A_pr[ri] *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[2U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_A_jc[3U]; ri <
       CPS_Eva_P.AnalogFilterDesign_A_jc[4U]; ri++) {
    _rtXdot->AnalogFilterDesign_CSTATE[CPS_Eva_P.AnalogFilterDesign_A_ir[ri]] +=
      CPS_Eva_P.AnalogFilterDesign_A_pr[ri] *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[3U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_B_jc[0U]; ri <
       CPS_Eva_P.AnalogFilterDesign_B_jc[1U]; ri++) {
    _rtXdot->AnalogFilterDesign_CSTATE[CPS_Eva_P.AnalogFilterDesign_B_ir] +=
      CPS_Eva_P.AnalogFilterDesign_B_pr * CPS_Eva_B.Gain5;
  }

  /* End of Derivatives for StateSpace: '<Root>/Analog Filter Design' */
}

/* Model initialize function */
void CPS_Eva_initialize(void)
{
  /* Start for FromWorkspace: '<S1>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.0005, 0.0005, 0.001, 0.001, 0.0015,
      0.0015, 0.002, 0.002, 0.0025, 0.0025, 0.003, 0.003, 0.0035, 0.0035, 0.004,
      0.004, 0.0045000000000000005, 0.0045000000000000005, 0.005, 0.005, 0.0055,
      0.0055, 0.006, 0.006, 0.0065000000000000006, 0.0065000000000000006, 0.007,
      0.007, 0.0075, 0.0075, 0.008, 0.008, 0.0085, 0.0085, 0.0090000000000000011,
      0.0090000000000000011, 0.0095, 0.0095, 0.01, 0.01, 0.0105, 0.0105, 0.011,
      0.011, 0.0115, 0.0115, 0.012, 0.012, 0.0125, 0.0125, 0.013000000000000001,
      0.013000000000000001, 0.0135, 0.0135, 0.014, 0.014, 0.0145, 0.0145, 0.015,
      0.015, 0.0155, 0.0155, 0.016, 0.016, 0.0165, 0.0165, 0.017, 0.017, 0.0175,
      0.0175, 0.018000000000000002, 0.018000000000000002, 0.0185, 0.0185, 0.019,
      0.019, 0.0195, 0.0195, 0.02, 0.02, 0.0205, 0.0205, 0.021, 0.021,
      0.021500000000000002, 0.021500000000000002, 0.022, 0.022, 0.0225, 0.0225,
      0.023, 0.023, 0.0235, 0.0235, 0.024, 0.024, 0.0245, 0.0245, 0.025, 0.025,
      0.025500000000000002, 0.025500000000000002, 0.026000000000000002,
      0.026000000000000002, 0.0265, 0.0265, 0.027, 0.027, 0.0275, 0.0275, 0.028,
      0.028, 0.0285, 0.0285, 0.029, 0.029, 0.029500000000000002,
      0.029500000000000002, 0.03, 0.03, 0.0305, 0.0305, 0.031, 0.031, 0.0315,
      0.0315, 0.032, 0.032, 0.0325, 0.0325, 0.033, 0.033, 0.0335, 0.0335, 0.034,
      0.034, 0.0345, 0.0345, 0.035, 0.035, 0.035500000000000004,
      0.035500000000000004, 0.036000000000000004, 0.036000000000000004, 0.0365,
      0.0365, 0.037, 0.037, 0.0375, 0.0375, 0.038, 0.038, 0.0385, 0.0385, 0.039,
      0.039, 0.0395, 0.0395, 0.04, 0.04, 0.0405, 0.0405, 0.041, 0.041, 0.0415,
      0.0415, 0.042, 0.042, 0.0425, 0.0425, 0.043000000000000003,
      0.043000000000000003, 0.043500000000000004, 0.043500000000000004, 0.044,
      0.044, 0.0445, 0.0445, 0.045, 0.045, 0.0455, 0.0455, 0.046, 0.046, 0.0465,
      0.0465, 0.047, 0.047, 0.0475, 0.0475, 0.048, 0.048, 0.0485, 0.0485, 0.049,
      0.049, 0.0495, 0.0495, 0.05, 0.05, 0.0505, 0.0505, 0.051000000000000004,
      0.051000000000000004, 0.051500000000000004, 0.051500000000000004,
      0.052000000000000005, 0.052000000000000005, 0.0525, 0.0525, 0.053, 0.053,
      0.0535, 0.0535, 0.054, 0.054, 0.0545, 0.0545, 0.055, 0.055, 0.0555, 0.0555,
      0.056, 0.056, 0.0565, 0.0565, 0.057, 0.057, 0.0575, 0.0575, 0.058, 0.058,
      0.0585, 0.0585, 0.059000000000000004, 0.059000000000000004,
      0.059500000000000004, 0.059500000000000004, 0.06, 0.06, 0.0605, 0.0605,
      0.061, 0.061, 0.0615, 0.0615, 0.062, 0.062, 0.0625, 0.0625, 0.063, 0.063,
      0.0635, 0.0635, 0.064, 0.064, 0.0645, 0.0645, 0.065, 0.065, 0.0655, 0.0655,
      0.066, 0.066, 0.0665, 0.0665, 0.067, 0.067, 0.0675, 0.0675, 0.068, 0.068,
      0.0685, 0.0685, 0.069, 0.069, 0.0695, 0.0695, 0.07, 0.07,
      0.070500000000000007, 0.070500000000000007, 0.071000000000000008,
      0.071000000000000008, 0.071500000000000008, 0.071500000000000008,
      0.072000000000000008, 0.072000000000000008, 0.0725, 0.0725, 0.073, 0.073,
      0.0735, 0.0735, 0.074, 0.074, 0.0745, 0.0745, 0.075, 0.075, 0.0755, 0.0755,
      0.076, 0.076, 0.0765, 0.0765, 0.077, 0.077, 0.0775, 0.0775, 0.078, 0.078,
      0.0785, 0.0785, 0.079, 0.079, 0.0795, 0.0795, 0.08, 0.08, 0.0805, 0.0805,
      0.081, 0.081, 0.0815, 0.0815, 0.082, 0.082, 0.0825, 0.0825, 0.083, 0.083,
      0.0835, 0.0835, 0.084, 0.084, 0.0845, 0.0845, 0.085, 0.085, 0.0855, 0.0855,
      0.086000000000000007, 0.086000000000000007, 0.086500000000000007,
      0.086500000000000007, 0.087000000000000008, 0.087000000000000008,
      0.087500000000000008, 0.087500000000000008, 0.088, 0.088, 0.0885, 0.0885,
      0.089, 0.089, 0.0895, 0.0895, 0.09, 0.09, 0.0905, 0.0905, 0.091, 0.091,
      0.0915, 0.0915, 0.092, 0.092, 0.0925, 0.0925, 0.093, 0.093, 0.0935, 0.0935,
      0.094, 0.094, 0.0945, 0.0945, 0.095, 0.095, 0.0955, 0.0955, 0.096, 0.096,
      0.0965, 0.0965, 0.097, 0.097, 0.0975, 0.0975, 0.098, 0.098, 0.0985, 0.0985,
      0.099, 0.099, 0.0995, 0.0995, 0.1, 0.1, 0.1005, 0.1005, 0.101, 0.101,
      0.1015, 0.1015, 0.10200000000000001, 0.10200000000000001,
      0.10250000000000001, 0.10250000000000001, 0.10300000000000001,
      0.10300000000000001, 0.10350000000000001, 0.10350000000000001,
      0.10400000000000001, 0.10400000000000001, 0.1045, 0.1045, 0.105, 0.105,
      0.1055, 0.1055, 0.106, 0.106, 0.1065, 0.1065, 0.107, 0.107, 0.1075, 0.1075,
      0.108, 0.108, 0.1085, 0.1085, 0.109, 0.109, 0.1095, 0.1095, 0.11, 0.11,
      0.1105, 0.1105, 0.111, 0.111, 0.1115, 0.1115, 0.112, 0.112, 0.1125, 0.1125,
      0.113, 0.113, 0.1135, 0.1135, 0.114, 0.114, 0.1145, 0.1145, 0.115, 0.115,
      0.1155, 0.1155, 0.116, 0.116, 0.1165, 0.1165, 0.117, 0.117,
      0.11750000000000001, 0.11750000000000001, 0.11800000000000001,
      0.11800000000000001, 0.11850000000000001, 0.11850000000000001,
      0.11900000000000001, 0.11900000000000001, 0.11950000000000001,
      0.11950000000000001, 0.12, 0.12, 0.1205, 0.1205, 0.121, 0.121, 0.1215,
      0.1215, 0.122, 0.122, 0.1225, 0.1225, 0.123, 0.123, 0.1235, 0.1235, 0.124,
      0.124, 0.1245, 0.1245, 0.125, 0.125, 0.1255, 0.1255, 0.126, 0.126, 0.1265,
      0.1265, 0.127, 0.127, 0.1275, 0.1275, 0.128, 0.128, 0.1285, 0.1285, 0.129,
      0.129, 0.1295, 0.1295, 0.13, 0.13, 0.1305, 0.1305, 0.131, 0.131, 0.1315,
      0.1315, 0.132, 0.132, 0.1325, 0.1325, 0.133, 0.133, 0.1335, 0.1335, 0.134,
      0.134, 0.1345, 0.1345, 0.135, 0.135, 0.1355, 0.1355, 0.136, 0.136, 0.1365,
      0.1365, 0.137, 0.137, 0.1375, 0.1375, 0.138, 0.138, 0.1385, 0.1385, 0.139,
      0.139, 0.1395, 0.1395, 0.14, 0.14, 0.1405, 0.1405, 0.14100000000000001,
      0.14100000000000001, 0.14150000000000001, 0.14150000000000001,
      0.14200000000000002, 0.14200000000000002, 0.14250000000000002,
      0.14250000000000002, 0.14300000000000002, 0.14300000000000002,
      0.14350000000000002, 0.14350000000000002, 0.14400000000000002,
      0.14400000000000002, 0.1445, 0.1445, 0.145, 0.145, 0.1455, 0.1455, 0.146,
      0.146, 0.1465, 0.1465, 0.147, 0.147, 0.1475, 0.1475, 0.148, 0.148, 0.1485,
      0.1485, 0.149, 0.149, 0.1495, 0.1495, 0.15, 0.15, 0.1505, 0.1505, 0.151,
      0.151, 0.1515, 0.1515, 0.152, 0.152, 0.1525, 0.1525, 0.153, 0.153, 0.1535,
      0.1535, 0.154, 0.154, 0.1545, 0.1545, 0.155, 0.155, 0.1555, 0.1555, 0.156,
      0.156, 0.1565, 0.1565, 0.157, 0.157, 0.1575, 0.1575, 0.158, 0.158, 0.1585,
      0.1585, 0.159, 0.159, 0.1595, 0.1595, 0.16, 0.16, 0.1605, 0.1605, 0.161,
      0.161, 0.1615, 0.1615, 0.162, 0.162, 0.1625, 0.1625, 0.163, 0.163, 0.1635,
      0.1635, 0.164, 0.164, 0.1645, 0.1645, 0.165, 0.165, 0.1655, 0.1655, 0.166,
      0.166, 0.1665, 0.1665, 0.167, 0.167, 0.1675, 0.1675, 0.168, 0.168, 0.1685,
      0.1685, 0.169, 0.169, 0.1695, 0.1695, 0.17, 0.17, 0.1705, 0.1705, 0.171,
      0.171, 0.1715, 0.1715, 0.17200000000000001, 0.17200000000000001,
      0.17250000000000001, 0.17250000000000001, 0.17300000000000001,
      0.17300000000000001, 0.17350000000000002, 0.17350000000000002,
      0.17400000000000002, 0.17400000000000002, 0.17450000000000002,
      0.17450000000000002, 0.17500000000000002, 0.17500000000000002,
      0.17550000000000002, 0.17550000000000002, 0.176, 0.176, 0.1765, 0.1765,
      0.177, 0.177, 0.1775, 0.1775, 0.178, 0.178, 0.1785, 0.1785, 0.179, 0.179,
      0.1795, 0.1795, 0.18, 0.18, 0.1805, 0.1805, 0.181, 0.181, 0.1815, 0.1815,
      0.182, 0.182, 0.1825, 0.1825, 0.183, 0.183, 0.1835, 0.1835, 0.184, 0.184,
      0.1845, 0.1845, 0.185, 0.185, 0.1855, 0.1855, 0.186, 0.186, 0.1865, 0.1865,
      0.187, 0.187, 0.1875, 0.1875, 0.188, 0.188, 0.1885, 0.1885, 0.189, 0.189,
      0.1895, 0.1895, 0.19, 0.19, 0.1905, 0.1905, 0.191, 0.191, 0.1915, 0.1915,
      0.192, 0.192, 0.1925, 0.1925, 0.193, 0.193, 0.1935, 0.1935, 0.194, 0.194,
      0.1945, 0.1945, 0.195, 0.195, 0.1955, 0.1955, 0.196, 0.196, 0.1965, 0.1965,
      0.197, 0.197, 0.1975, 0.1975, 0.198, 0.198, 0.1985, 0.1985, 0.199, 0.199,
      0.1995, 0.1995, 0.2, 0.2, 0.2005, 0.2005, 0.201, 0.201, 0.2015, 0.2015,
      0.202, 0.202, 0.2025, 0.2025, 0.203, 0.203, 0.20350000000000001,
      0.20350000000000001, 0.20400000000000001, 0.20400000000000001,
      0.20450000000000002, 0.20450000000000002, 0.20500000000000002,
      0.20500000000000002, 0.20550000000000002, 0.20550000000000002,
      0.20600000000000002, 0.20600000000000002, 0.20650000000000002,
      0.20650000000000002, 0.20700000000000002, 0.20700000000000002,
      0.20750000000000002, 0.20750000000000002, 0.20800000000000002,
      0.20800000000000002, 0.2085, 0.2085, 0.209, 0.209, 0.2095, 0.2095, 0.21,
      0.21, 0.2105, 0.2105, 0.211, 0.211, 0.2115, 0.2115, 0.212, 0.212, 0.2125,
      0.2125, 0.213, 0.213, 0.2135, 0.2135, 0.214, 0.214, 0.2145, 0.2145, 0.215,
      0.215, 0.2155, 0.2155, 0.216, 0.216, 0.2165, 0.2165, 0.217, 0.217, 0.2175,
      0.2175, 0.218, 0.218, 0.2185, 0.2185, 0.219, 0.219, 0.2195, 0.2195, 0.22,
      0.22, 0.2205, 0.2205, 0.221, 0.221, 0.2215, 0.2215, 0.222, 0.222, 0.2225,
      0.2225, 0.223, 0.223, 0.2235, 0.2235, 0.224, 0.224, 0.2245, 0.2245, 0.225,
      0.225, 0.2255, 0.2255, 0.226, 0.226, 0.2265, 0.2265, 0.227, 0.227, 0.2275,
      0.2275, 0.228, 0.228, 0.2285, 0.2285, 0.229, 0.229, 0.2295, 0.2295, 0.23,
      0.23, 0.2305, 0.2305, 0.231, 0.231, 0.2315, 0.2315, 0.232, 0.232, 0.2325,
      0.2325, 0.233, 0.233, 0.2335, 0.2335, 0.234, 0.234, 0.23450000000000001,
      0.23450000000000001, 0.23500000000000001, 0.23500000000000001,
      0.23550000000000001, 0.23550000000000001, 0.23600000000000002,
      0.23600000000000002, 0.23650000000000002, 0.23650000000000002,
      0.23700000000000002, 0.23700000000000002, 0.23750000000000002,
      0.23750000000000002, 0.23800000000000002, 0.23800000000000002,
      0.23850000000000002, 0.23850000000000002, 0.23900000000000002,
      0.23900000000000002, 0.23950000000000002, 0.23950000000000002, 0.24, 0.24,
      0.2405, 0.2405, 0.241, 0.241, 0.2415, 0.2415, 0.242, 0.242, 0.2425, 0.2425,
      0.243, 0.243, 0.2435, 0.2435, 0.244, 0.244, 0.2445, 0.2445, 0.245, 0.245,
      0.2455, 0.2455, 0.246, 0.246, 0.2465, 0.2465, 0.247, 0.247, 0.2475, 0.2475,
      0.248, 0.248, 0.2485, 0.2485, 0.249, 0.249, 0.2495, 0.2495, 0.25, 0.25,
      0.2505, 0.2505, 0.251, 0.251, 0.2515, 0.2515, 0.252, 0.252, 0.2525, 0.2525,
      0.253, 0.253, 0.2535, 0.2535, 0.254, 0.254, 0.2545, 0.2545, 0.255, 0.255,
      0.2555, 0.2555, 0.256, 0.256, 0.2565, 0.2565, 0.257, 0.257, 0.2575, 0.2575,
      0.258, 0.258, 0.2585, 0.2585, 0.259, 0.259, 0.2595, 0.2595, 0.26, 0.26,
      0.2605, 0.2605, 0.261, 0.261, 0.2615, 0.2615, 0.262, 0.262, 0.2625, 0.2625,
      0.263, 0.263, 0.2635, 0.2635, 0.264, 0.264, 0.2645, 0.2645, 0.265, 0.265,
      0.2655, 0.2655, 0.266, 0.266, 0.2665, 0.2665, 0.267, 0.267, 0.2675, 0.2675,
      0.268, 0.268, 0.2685, 0.2685, 0.269, 0.269, 0.2695, 0.2695, 0.27, 0.27,
      0.2705, 0.2705, 0.271, 0.271, 0.2715, 0.2715, 0.272, 0.272, 0.2725, 0.2725,
      0.273, 0.273, 0.2735, 0.2735, 0.274, 0.274, 0.2745, 0.2745, 0.275, 0.275,
      0.2755, 0.2755, 0.276, 0.276, 0.2765, 0.2765, 0.277, 0.277, 0.2775, 0.2775,
      0.278, 0.278, 0.2785, 0.2785, 0.279, 0.279, 0.2795, 0.2795, 0.28, 0.28,
      0.2805, 0.281, 0.28150000000000003, 0.28200000000000003,
      0.28250000000000003, 0.28300000000000003, 0.28350000000000003,
      0.28400000000000003, 0.28450000000000003, 0.28500000000000003,
      0.28550000000000003, 0.28600000000000003, 0.28650000000000003,
      0.28700000000000003, 0.28750000000000003, 0.28800000000000003,
      0.28800000000000003, 0.2885, 0.2885, 0.289, 0.2895, 0.29, 0.2905, 0.291,
      0.2915, 0.292, 0.2925, 0.293, 0.2935, 0.294, 0.2945, 0.295, 0.2955, 0.296,
      0.2965, 0.297, 0.2975, 0.298, 0.2985, 0.299, 0.2995, 0.3, 0.3005, 0.301,
      0.3015, 0.302, 0.302, 0.3025, 0.3025, 0.303, 0.3035, 0.304, 0.3045, 0.305,
      0.3055, 0.306, 0.3065, 0.307, 0.3075, 0.308, 0.3085, 0.309, 0.3095, 0.31,
      0.3105, 0.311, 0.3115, 0.312, 0.3125, 0.313, 0.3135, 0.314, 0.3145, 0.315,
      0.3155, 0.316, 0.3165, 0.317, 0.3175, 0.318, 0.3185, 0.319, 0.3195, 0.32,
      0.3205, 0.321, 0.3215, 0.322, 0.3225, 0.323, 0.3235, 0.324, 0.3245, 0.325,
      0.3255, 0.326, 0.3265, 0.327, 0.3275, 0.328, 0.3285, 0.329, 0.3295, 0.33,
      0.3305, 0.331, 0.3315, 0.332, 0.3325, 0.333, 0.3335, 0.334, 0.3345, 0.335,
      0.3355, 0.336, 0.3365, 0.337, 0.337, 0.3375, 0.3375, 0.338, 0.3385, 0.339,
      0.3395, 0.34, 0.3405, 0.341, 0.3415, 0.342, 0.3425, 0.343, 0.3435,
      0.34400000000000003, 0.34450000000000003, 0.34500000000000003,
      0.34550000000000003, 0.34600000000000003, 0.34650000000000003,
      0.34700000000000003, 0.34750000000000003, 0.34800000000000003,
      0.34850000000000003, 0.34900000000000003, 0.34950000000000003,
      0.35000000000000003, 0.35050000000000003, 0.35100000000000003,
      0.35150000000000003, 0.35150000000000003, 0.352, 0.352, 0.3525, 0.353,
      0.3535, 0.354, 0.3545, 0.355, 0.3555, 0.356, 0.3565, 0.357, 0.3575, 0.358,
      0.3585, 0.359, 0.3595, 0.36, 0.3605, 0.361, 0.3615, 0.362, 0.3625, 0.363,
      0.3635, 0.364, 0.3645, 0.365, 0.3655, 0.366, 0.3665, 0.367, 0.3675, 0.368,
      0.3685, 0.369, 0.3695, 0.37, 0.3705, 0.371, 0.3715, 0.372, 0.3725, 0.3725,
      0.373, 0.373, 0.3735, 0.374, 0.3745, 0.375, 0.3755, 0.376, 0.3765, 0.377,
      0.3775, 0.378, 0.3785, 0.379, 0.3795, 0.38, 0.3805, 0.381, 0.3815, 0.382,
      0.3825, 0.383, 0.3835, 0.384, 0.3845, 0.385, 0.3855, 0.386, 0.3865, 0.387,
      0.3875, 0.388, 0.3885, 0.389, 0.3895, 0.39, 0.3905, 0.391, 0.3915, 0.392,
      0.3925, 0.393, 0.3935, 0.394, 0.394, 0.3945, 0.3945, 0.395, 0.3955, 0.396,
      0.3965, 0.397, 0.3975, 0.398, 0.3985, 0.399, 0.3995, 0.4, 0.4005, 0.401,
      0.4015, 0.402, 0.4025, 0.403, 0.4035, 0.404, 0.4045, 0.405, 0.4055, 0.406,
      0.40650000000000003, 0.40700000000000003, 0.40750000000000003,
      0.40800000000000003, 0.40850000000000003, 0.40900000000000003,
      0.40950000000000003, 0.41000000000000003, 0.41050000000000003,
      0.41100000000000003, 0.41150000000000003, 0.41200000000000003,
      0.41250000000000003, 0.41300000000000003, 0.41350000000000003,
      0.41400000000000003, 0.41450000000000004, 0.41500000000000004,
      0.41550000000000004, 0.41600000000000004, 0.41600000000000004, 0.4165,
      0.4165, 0.417, 0.4175, 0.418, 0.4185, 0.419, 0.4195, 0.42, 0.4205, 0.421,
      0.4215, 0.422, 0.4225, 0.423, 0.4235, 0.424, 0.424, 0.4245, 0.4245, 0.425,
      0.4255, 0.426, 0.4265, 0.427, 0.4275, 0.428, 0.4285, 0.429, 0.4295, 0.43,
      0.4305, 0.431, 0.4315, 0.432, 0.4325, 0.433, 0.4335, 0.434, 0.4345, 0.435,
      0.4355, 0.436, 0.4365, 0.437, 0.4375, 0.438, 0.4385, 0.439, 0.4395, 0.44,
      0.4405, 0.441, 0.4415, 0.442, 0.4425, 0.443, 0.4435, 0.444, 0.4445, 0.445,
      0.4455, 0.446, 0.4465, 0.447, 0.4475, 0.448, 0.4485, 0.449, 0.4495, 0.45,
      0.4505, 0.451, 0.4515, 0.452, 0.4525, 0.453, 0.4535, 0.454, 0.4545, 0.455,
      0.4555, 0.456, 0.4565, 0.457, 0.4575, 0.458, 0.4585, 0.459, 0.4595, 0.46,
      0.4605, 0.461, 0.4615, 0.462, 0.4625, 0.463, 0.4635, 0.4635,
      0.46399999999999997, 0.46399999999999997, 0.46449999999999997,
      0.46499999999999997, 0.46499999999999997, 0.46549999999999997,
      0.46549999999999997, 0.46599999999999997, 0.46649999999999997,
      0.46699999999999997, 0.46749999999999997, 0.46799999999999997,
      0.46849999999999997, 0.469, 0.4695, 0.47, 0.4705, 0.471, 0.4715, 0.472,
      0.4725, 0.473, 0.4735, 0.474, 0.4745, 0.475, 0.4755, 0.476, 0.4765, 0.477,
      0.4775, 0.478, 0.4785, 0.479, 0.4795, 0.48, 0.4805, 0.481, 0.4815, 0.482,
      0.4825, 0.483, 0.4835, 0.484, 0.4845, 0.485, 0.4855, 0.486, 0.4865, 0.487,
      0.4875, 0.488, 0.4885, 0.489, 0.4895, 0.49, 0.4905, 0.491, 0.4915, 0.492,
      0.4925, 0.493, 0.4935, 0.494, 0.4945, 0.495, 0.4955, 0.496, 0.4965, 0.497,
      0.4975, 0.498, 0.4985, 0.499, 0.4995, 0.5, 0.5, 0.5005, 0.5005, 0.501,
      0.50150000000000006, 0.50150000000000006, 0.502, 0.5025, 0.5025, 0.503,
      0.50350000000000006, 0.50350000000000006, 0.504, 0.5045, 0.5045, 0.505,
      0.50550000000000006, 0.50550000000000006, 0.506, 0.506, 0.5065, 0.5065,
      0.507, 0.507, 0.50750000000000006, 0.50750000000000006, 0.508, 0.508,
      0.5085, 0.5085, 0.509, 0.509, 0.50950000000000006, 0.50950000000000006,
      0.51, 0.51, 0.5105, 0.5105, 0.511, 0.51150000000000007,
      0.51150000000000007, 0.512, 0.5125, 0.5125, 0.513, 0.51350000000000007,
      0.51350000000000007, 0.514, 0.5145, 0.5145, 0.515, 0.51550000000000007,
      0.51550000000000007, 0.516, 0.5165, 0.5165, 0.517, 0.51750000000000007,
      0.51750000000000007, 0.518, 0.5185, 0.5185, 0.519, 0.51950000000000007,
      0.51950000000000007, 0.52, 0.5205, 0.5205, 0.521, 0.52150000000000007,
      0.52150000000000007, 0.522, 0.5225, 0.5225, 0.523, 0.52350000000000008,
      0.52350000000000008, 0.524, 0.5245, 0.5245, 0.525, 0.52550000000000008,
      0.52550000000000008, 0.526, 0.5265, 0.5265, 0.527, 0.52750000000000008,
      0.52750000000000008, 0.528, 0.5285, 0.52899999999999991,
      0.52899999999999991, 0.5295, 0.53, 0.53, 0.5305, 0.53099999999999992,
      0.53099999999999992, 0.5315, 0.532, 0.532, 0.5325, 0.53299999999999992,
      0.53299999999999992, 0.5335, 0.534, 0.534, 0.5345, 0.53499999999999992,
      0.53499999999999992, 0.5355, 0.536, 0.536, 0.5365, 0.53699999999999992,
      0.53699999999999992, 0.5375, 0.538, 0.538, 0.5385, 0.53899999999999992,
      0.53899999999999992, 0.5395, 0.54, 0.54, 0.5405, 0.54099999999999993,
      0.54099999999999993, 0.5415, 0.542, 0.542, 0.5425, 0.54299999999999993,
      0.54299999999999993, 0.5435, 0.544, 0.544, 0.5445, 0.54499999999999993,
      0.54499999999999993, 0.5455, 0.546, 0.546, 0.5465, 0.54699999999999993,
      0.54699999999999993, 0.5475, 0.548, 0.548, 0.5485, 0.54899999999999993,
      0.54899999999999993, 0.5495, 0.55, 0.55, 0.5505, 0.55099999999999993,
      0.55099999999999993, 0.5515, 0.552, 0.552, 0.5525, 0.55299999999999994,
      0.55299999999999994, 0.5535, 0.554, 0.554, 0.5545, 0.55499999999999994,
      0.55499999999999994, 0.5555, 0.556, 0.556, 0.5565, 0.55699999999999994,
      0.55699999999999994, 0.5575, 0.558, 0.558, 0.5585, 0.55899999999999994,
      0.55899999999999994, 0.5595, 0.56, 0.56, 0.5605, 0.56099999999999994,
      0.56099999999999994, 0.5615, 0.562, 0.562, 0.5625, 0.563, 0.563, 0.5635,
      0.56400000000000006, 0.56400000000000006, 0.5645, 0.565, 0.565, 0.5655,
      0.56600000000000006, 0.56600000000000006, 0.5665, 0.567, 0.567, 0.5675,
      0.56800000000000006, 0.56800000000000006, 0.5685, 0.5685, 0.569, 0.569,
      0.5695, 0.5695, 0.57000000000000006, 0.57000000000000006, 0.5705, 0.5705,
      0.571, 0.571, 0.5715, 0.5715, 0.57200000000000006, 0.57200000000000006,
      0.5725, 0.5725, 0.573, 0.573, 0.5735, 0.57400000000000007,
      0.57400000000000007, 0.5745, 0.575, 0.575, 0.5755, 0.57600000000000007,
      0.57600000000000007, 0.5765, 0.577, 0.577, 0.5775, 0.57800000000000007,
      0.57800000000000007, 0.5785, 0.579, 0.579, 0.5795, 0.58000000000000007,
      0.58000000000000007, 0.5805, 0.581, 0.581, 0.5815, 0.58200000000000007,
      0.58200000000000007, 0.5825, 0.583, 0.583, 0.5835, 0.58400000000000007,
      0.58400000000000007, 0.5845, 0.585, 0.585, 0.5855, 0.58600000000000008,
      0.58600000000000008, 0.5865, 0.587, 0.587, 0.5875, 0.58800000000000008,
      0.58800000000000008, 0.5885, 0.589, 0.589, 0.5895, 0.59000000000000008,
      0.59000000000000008, 0.5905, 0.591, 0.591, 0.5915, 0.5915, 0.592, 0.592,
      0.5925, 0.5925, 0.593, 0.59349999999999992, 0.59349999999999992, 0.594,
      0.5945, 0.5945, 0.595, 0.59549999999999992, 0.59549999999999992, 0.596,
      0.5965, 0.5965, 0.597, 0.59749999999999992, 0.59749999999999992, 0.598,
      0.5985, 0.5985, 0.599, 0.59949999999999992, 0.59949999999999992, 0.6,
      0.6005, 0.6005, 0.601, 0.60149999999999992, 0.60149999999999992, 0.602,
      0.6025, 0.6025, 0.603, 0.60349999999999993, 0.60349999999999993, 0.604,
      0.6045, 0.6045, 0.605, 0.60549999999999993, 0.60549999999999993, 0.606,
      0.6065, 0.6065, 0.607, 0.60749999999999993, 0.60749999999999993, 0.608,
      0.6085, 0.6085, 0.609, 0.60949999999999993, 0.60949999999999993, 0.61,
      0.6105, 0.6105, 0.611, 0.61149999999999993, 0.61149999999999993, 0.612,
      0.6125, 0.6125, 0.613, 0.61349999999999993, 0.61349999999999993, 0.614,
      0.6145, 0.6145, 0.615, 0.61549999999999994, 0.61549999999999994, 0.616,
      0.6165, 0.6165, 0.617, 0.61749999999999994, 0.61749999999999994, 0.618,
      0.6185, 0.6185, 0.619, 0.61949999999999994, 0.61949999999999994, 0.62,
      0.62, 0.6205, 0.6205, 0.621, 0.621, 0.62149999999999994,
      0.62149999999999994, 0.622, 0.622, 0.6225, 0.6225, 0.623, 0.623,
      0.62349999999999994, 0.62349999999999994, 0.624, 0.624, 0.6245, 0.6245,
      0.625, 0.625, 0.6255, 0.6255, 0.626, 0.626, 0.62650000000000006,
      0.62650000000000006, 0.627, 0.627, 0.6275, 0.6275, 0.628, 0.628,
      0.62850000000000006, 0.62850000000000006, 0.629, 0.629, 0.6295, 0.6295,
      0.63, 0.63, 0.63050000000000006, 0.63050000000000006, 0.631, 0.631, 0.6315,
      0.6315, 0.632, 0.632, 0.63250000000000006, 0.63250000000000006, 0.633,
      0.633, 0.6335, 0.6335, 0.634, 0.634, 0.63450000000000006,
      0.63450000000000006, 0.635, 0.635, 0.6355, 0.6355, 0.636, 0.636,
      0.63650000000000007, 0.63650000000000007, 0.637, 0.637, 0.6375, 0.6375,
      0.638, 0.638, 0.63850000000000007, 0.63850000000000007, 0.639, 0.639,
      0.6395, 0.6395, 0.64, 0.64, 0.6405, 0.6405, 0.641, 0.641, 0.6415, 0.6415,
      0.642, 0.642, 0.6425, 0.6425, 0.643, 0.643, 0.6435, 0.6435, 0.644, 0.644,
      0.6445, 0.6445, 0.645, 0.645, 0.6455, 0.6455, 0.646, 0.646, 0.6465, 0.6465,
      0.647, 0.647, 0.6475, 0.6475, 0.648, 0.648, 0.6485, 0.6485, 0.649, 0.649,
      0.6495, 0.6495, 0.65, 0.65, 0.6505, 0.6505, 0.651, 0.651, 0.6515, 0.6515,
      0.652, 0.652, 0.6525, 0.6525, 0.653, 0.653, 0.6535, 0.6535, 0.654, 0.654,
      0.6545, 0.6545, 0.655, 0.655, 0.6555, 0.6555, 0.656, 0.656, 0.6565, 0.6565,
      0.657, 0.657, 0.6575, 0.6575, 0.658, 0.658, 0.6585, 0.6585, 0.659, 0.659,
      0.6595, 0.6595, 0.66, 0.66, 0.6605, 0.6605, 0.661, 0.661, 0.6615, 0.6615,
      0.662, 0.662, 0.6625, 0.6625, 0.663, 0.663, 0.6635, 0.6635, 0.664, 0.664,
      0.6645, 0.6645, 0.665, 0.665, 0.6655, 0.6655, 0.666, 0.666, 0.6665, 0.6665,
      0.667, 0.667, 0.6675, 0.6675, 0.668, 0.668, 0.6685, 0.6685, 0.669, 0.669,
      0.6695, 0.6695, 0.67, 0.67, 0.6705, 0.6705, 0.671, 0.671, 0.6715, 0.6715,
      0.67199999999999993, 0.67199999999999993, 0.6725, 0.6725, 0.673, 0.673,
      0.6735, 0.6735, 0.67399999999999993, 0.67399999999999993, 0.6745, 0.6745,
      0.675, 0.675, 0.6755, 0.6755, 0.67599999999999993, 0.67599999999999993,
      0.6765, 0.6765, 0.677, 0.677, 0.6775, 0.6775, 0.67799999999999994,
      0.67799999999999994, 0.6785, 0.6785, 0.679, 0.679, 0.6795, 0.6795,
      0.67999999999999994, 0.67999999999999994, 0.6805, 0.6805, 0.681, 0.681,
      0.6815, 0.6815, 0.68199999999999994, 0.68199999999999994, 0.6825, 0.6825,
      0.683, 0.683, 0.6835, 0.6835, 0.68399999999999994, 0.68399999999999994,
      0.6845, 0.6845, 0.685, 0.685, 0.6855, 0.6855, 0.68599999999999994,
      0.68599999999999994, 0.6865, 0.6865, 0.687, 0.687, 0.6875, 0.6875, 0.688,
      0.688, 0.6885, 0.6885, 0.68900000000000006, 0.68900000000000006, 0.6895,
      0.6895, 0.69, 0.69, 0.6905, 0.6905, 0.69100000000000006,
      0.69100000000000006, 0.6915, 0.6915, 0.692, 0.692, 0.6925, 0.6925,
      0.69300000000000006, 0.69300000000000006, 0.6935, 0.6935, 0.694, 0.694,
      0.6945, 0.6945, 0.69500000000000006, 0.69500000000000006, 0.6955, 0.6955,
      0.696, 0.696, 0.6965, 0.6965, 0.69700000000000006, 0.69700000000000006,
      0.6975, 0.6975, 0.698, 0.698, 0.6985, 0.6985, 0.69900000000000007,
      0.69900000000000007, 0.6995, 0.6995, 0.7, 0.7, 0.7005, 0.7005,
      0.70100000000000007, 0.70100000000000007, 0.7015, 0.7015, 0.702, 0.702,
      0.7025, 0.7025, 0.70300000000000007, 0.70300000000000007, 0.7035, 0.7035,
      0.704, 0.704, 0.7045, 0.7045, 0.705, 0.705, 0.7055, 0.7055, 0.706, 0.706,
      0.7065, 0.7065, 0.707, 0.707, 0.7075, 0.7075, 0.708, 0.708, 0.7085, 0.7085,
      0.709, 0.709, 0.7095, 0.7095, 0.71, 0.71, 0.7105, 0.7105, 0.711, 0.711,
      0.7115, 0.7115, 0.712, 0.712, 0.7125, 0.7125, 0.713, 0.713, 0.7135, 0.7135,
      0.714, 0.714, 0.7145, 0.7145, 0.715, 0.715, 0.7155, 0.7155, 0.716, 0.716,
      0.7165, 0.7165, 0.717, 0.717, 0.7175, 0.7175, 0.718, 0.718, 0.7185, 0.7185,
      0.719, 0.719, 0.7195, 0.7195, 0.72, 0.72, 0.7205, 0.7205, 0.721, 0.721,
      0.7215, 0.7215, 0.722, 0.722, 0.7225, 0.7225, 0.723, 0.723, 0.7235, 0.7235,
      0.724, 0.724, 0.7245, 0.7245, 0.725, 0.725, 0.7255, 0.7255, 0.726, 0.726,
      0.7265, 0.7265, 0.727, 0.727, 0.7275, 0.7275, 0.728, 0.728, 0.7285, 0.7285,
      0.729, 0.729, 0.7295, 0.7295, 0.73, 0.73, 0.7305, 0.7305, 0.731, 0.731,
      0.7315, 0.7315, 0.732, 0.732, 0.7325, 0.7325, 0.733, 0.733, 0.7335, 0.7335,
      0.734, 0.734, 0.7345, 0.7345, 0.735, 0.735, 0.7355, 0.7355, 0.736, 0.736,
      0.73649999999999993, 0.73649999999999993, 0.737, 0.737, 0.7375, 0.7375,
      0.738, 0.738, 0.73849999999999993, 0.73849999999999993, 0.739, 0.739,
      0.7395, 0.7395, 0.74, 0.74, 0.74049999999999994, 0.74049999999999994,
      0.741, 0.741, 0.7415, 0.7415, 0.742, 0.742, 0.74249999999999994,
      0.74249999999999994, 0.743, 0.743, 0.7435, 0.7435, 0.744, 0.744,
      0.74449999999999994, 0.74449999999999994, 0.745, 0.745, 0.7455, 0.7455,
      0.746, 0.746, 0.74649999999999994, 0.74649999999999994, 0.747, 0.747,
      0.7475, 0.7475, 0.748, 0.748, 0.74849999999999994, 0.74849999999999994,
      0.749, 0.749, 0.7495, 0.7495, 0.75, 0.75, 0.7505, 0.7505, 0.751, 0.751,
      0.75150000000000006, 0.75150000000000006, 0.752, 0.752, 0.7525, 0.7525,
      0.753, 0.753, 0.75350000000000006, 0.75350000000000006, 0.754, 0.754,
      0.7545, 0.7545, 0.755, 0.755, 0.75550000000000006, 0.75550000000000006,
      0.756, 0.756, 0.7565, 0.7565, 0.757, 0.757, 0.75750000000000006,
      0.75750000000000006, 0.758, 0.758, 0.7585, 0.7585, 0.759, 0.759,
      0.75950000000000006, 0.75950000000000006, 0.76, 0.76, 0.7605, 0.7605,
      0.761, 0.761, 0.7615, 0.7615, 0.762, 0.762, 0.7625, 0.7625, 0.763, 0.763,
      0.7635, 0.7635, 0.764, 0.764, 0.7645, 0.7645, 0.765, 0.765, 0.7655, 0.7655,
      0.766, 0.766, 0.7665, 0.7665, 0.767, 0.767, 0.7675, 0.7675, 0.768, 0.768,
      0.7685, 0.7685, 0.769, 0.769, 0.7695, 0.7695, 0.77, 0.77, 0.7705, 0.7705,
      0.771, 0.771, 0.7715, 0.7715, 0.772, 0.772, 0.7725, 0.7725, 0.773, 0.773,
      0.7735, 0.7735, 0.774, 0.774, 0.7745, 0.7745, 0.775, 0.775, 0.7755, 0.7755,
      0.776, 0.776, 0.7765, 0.7765, 0.777, 0.777, 0.7775, 0.7775, 0.778, 0.778,
      0.7785, 0.7785, 0.779, 0.779, 0.7795, 0.7795, 0.78, 0.78, 0.7805, 0.7805,
      0.781, 0.781, 0.7815, 0.7815, 0.782, 0.782, 0.7825, 0.7825, 0.783, 0.783,
      0.7835, 0.7835, 0.784, 0.784, 0.7845, 0.7845, 0.785, 0.785, 0.7855, 0.7855,
      0.786, 0.786, 0.7865, 0.7865, 0.787, 0.787, 0.7875, 0.7875, 0.788, 0.788,
      0.7885, 0.7885, 0.789, 0.789, 0.7895, 0.7895, 0.79, 0.79, 0.7905, 0.7905,
      0.791, 0.791, 0.7915, 0.7915, 0.792, 0.792, 0.7925, 0.7925, 0.793, 0.793,
      0.7935, 0.7935, 0.794, 0.794, 0.7945, 0.7945, 0.795, 0.795, 0.7955, 0.7955,
      0.796, 0.796, 0.7965, 0.7965, 0.797, 0.797, 0.7975, 0.7975, 0.798, 0.798,
      0.7985, 0.7985, 0.799, 0.799, 0.7995, 0.7995, 0.8, 0.8, 0.8005, 0.8005,
      0.801, 0.801, 0.8015, 0.8015, 0.802, 0.802, 0.8025, 0.8025, 0.803, 0.803,
      0.8035, 0.8035, 0.804, 0.804, 0.8045, 0.8045, 0.805, 0.805, 0.8055, 0.8055,
      0.806, 0.806, 0.8065, 0.8065, 0.807, 0.807, 0.8075, 0.8075, 0.808, 0.808,
      0.8085, 0.8085, 0.80899999999999994, 0.80899999999999994, 0.8095, 0.8095,
      0.81, 0.81, 0.8105, 0.8105, 0.81099999999999994, 0.81099999999999994,
      0.8115, 0.8115, 0.812, 0.812, 0.8125, 0.8125, 0.813, 0.813, 0.8135, 0.8135,
      0.81400000000000006, 0.81400000000000006, 0.8145, 0.8145, 0.815, 0.815,
      0.8155, 0.8155, 0.81600000000000006, 0.81600000000000006, 0.8165, 0.8165,
      0.817, 0.817, 0.8175, 0.8175, 0.81800000000000006, 0.81800000000000006,
      0.8185, 0.8185, 0.819, 0.819, 0.8195, 0.8195, 0.82000000000000006,
      0.82000000000000006, 0.8205, 0.8205, 0.821, 0.821, 0.8215, 0.8215, 0.822,
      0.822, 0.8225, 0.8225, 0.823, 0.823, 0.8235, 0.8235, 0.824, 0.824, 0.8245,
      0.8245, 0.825, 0.825, 0.8255, 0.8255, 0.826, 0.826, 0.8265, 0.8265, 0.827,
      0.827, 0.8275, 0.8275, 0.828, 0.828, 0.8285, 0.8285, 0.829, 0.829, 0.8295,
      0.8295, 0.83, 0.83, 0.8305, 0.8305, 0.831, 0.831, 0.8315, 0.8315, 0.832,
      0.832, 0.8325, 0.8325, 0.833, 0.833, 0.8335, 0.8335, 0.834, 0.834, 0.8345,
      0.8345, 0.835, 0.835, 0.8355, 0.8355, 0.836, 0.836, 0.8365, 0.8365, 0.837,
      0.837, 0.8375, 0.8375, 0.838, 0.838, 0.8385, 0.8385, 0.839, 0.839, 0.8395,
      0.8395, 0.84, 0.84, 0.8405, 0.8405, 0.841, 0.841, 0.8415, 0.8415, 0.842,
      0.842, 0.8425, 0.8425, 0.843, 0.843, 0.8435, 0.8435, 0.844, 0.844, 0.8445,
      0.8445, 0.845, 0.845, 0.8455, 0.8455, 0.846, 0.846, 0.8465, 0.8465, 0.847,
      0.847, 0.8475, 0.8475, 0.848, 0.848, 0.8485, 0.8485, 0.849, 0.849, 0.8495,
      0.8495, 0.85, 0.85, 0.8505, 0.8505, 0.851, 0.851, 0.8515, 0.8515, 0.852,
      0.852, 0.8525, 0.8525, 0.853, 0.853, 0.8535, 0.8535, 0.854, 0.854, 0.8545,
      0.8545, 0.855, 0.855, 0.8555, 0.8555, 0.856, 0.856, 0.8565, 0.8565, 0.857,
      0.857, 0.8575, 0.8575, 0.858, 0.858, 0.8585, 0.8585, 0.859, 0.859, 0.8595,
      0.8595, 0.86, 0.86, 0.8605, 0.8605, 0.861, 0.861, 0.8615, 0.8615, 0.862,
      0.862, 0.8625, 0.8625, 0.863, 0.863, 0.8635, 0.8635, 0.864, 0.864, 0.8645,
      0.8645, 0.865, 0.865, 0.8655, 0.8655, 0.866, 0.866, 0.8665, 0.8665, 0.867,
      0.867, 0.8675, 0.8675, 0.868, 0.868, 0.8685, 0.8685, 0.869, 0.869, 0.8695,
      0.8695, 0.87, 0.87, 0.8705, 0.8705, 0.871, 0.871, 0.8715, 0.8715, 0.872,
      0.872, 0.8725, 0.8725, 0.873, 0.873, 0.8735, 0.8735, 0.874, 0.874, 0.8745,
      0.8745, 0.875, 0.875, 0.87550000000000006, 0.87550000000000006, 0.876,
      0.876, 0.87650000000000006, 0.87650000000000006, 0.877, 0.877,
      0.87750000000000006, 0.87750000000000006, 0.878, 0.878,
      0.87850000000000006, 0.87850000000000006, 0.879, 0.879,
      0.87950000000000006, 0.87950000000000006, 0.88, 0.88, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 5.0813008130081307E-7,
      5.0813008130081307E-7, 2.0325203252032523E-6, 2.0325203252032523E-6,
      4.5731707317073177E-6, 4.5731707317073177E-6, 8.1300813008130091E-6,
      8.1300813008130091E-6, 1.2703252032520327E-5, 1.2703252032520327E-5,
      1.8292682926829271E-5, 1.8292682926829271E-5, 2.4898373983739841E-5,
      2.4898373983739841E-5, 3.2520325203252037E-5, 3.2520325203252037E-5,
      4.1158536585365863E-5, 4.1158536585365863E-5, 5.0813008130081308E-5,
      5.0813008130081308E-5, 6.148373983739837E-5, 6.148373983739837E-5,
      7.3170731707317084E-5, 7.3170731707317084E-5, 8.5873983739837416E-5,
      8.5873983739837416E-5, 9.9593495934959366E-5, 9.9593495934959366E-5,
      0.00011432926829268293, 0.00011432926829268293, 0.00013008130081300815,
      0.00013008130081300815, 0.000146849593495935, 0.000146849593495935,
      0.00016463414634146345, 0.00016463414634146345, 0.00018343495934959351,
      0.00018343495934959351, 0.00020325203252032523, 0.00020325203252032523,
      0.00022408536585365857, 0.00022408536585365857, 0.00024593495934959348,
      0.00024593495934959348, 0.00026880081300813009, 0.00026880081300813009,
      0.00029268292682926834, 0.00029268292682926834, 0.00031758130081300818,
      0.00031758130081300818, 0.00034349593495934966, 0.00034349593495934966,
      0.00037042682926829274, 0.00037042682926829274, 0.00039837398373983746,
      0.00039837398373983746, 0.00042733739837398383, 0.00042733739837398383,
      0.00045731707317073173, 0.00045731707317073173, 0.00048831300813008134,
      0.00048831300813008134, 0.00052032520325203258, 0.00052032520325203258,
      0.00055335365853658542, 0.00055335365853658542, 0.00058739837398374,
      0.00058739837398374, 0.00062245934959349609, 0.00062245934959349609,
      0.00065853658536585381, 0.00065853658536585381, 0.000695630081300813,
      0.000695630081300813, 0.000733739837398374, 0.000733739837398374,
      0.00077286585365853662, 0.00077286585365853662, 0.00081300813008130092,
      0.00081300813008130092, 0.00085416666666666681, 0.00085416666666666681,
      0.00089634146341463429, 0.00089634146341463429, 0.00093953252032520347,
      0.00093953252032520347, 0.000983739837398374, 0.000983739837398374,
      0.0010289634146341464, 0.0010289634146341464, 0.0010752032520325203,
      0.0010752032520325203, 0.001122459349593496, 0.001122459349593496,
      0.0011707317073170733, 0.0011707317073170733, 0.0012200203252032522,
      0.0012200203252032522, 0.0012703252032520327, 0.0012703252032520327,
      0.0013216463414634149, 0.0013216463414634149, 0.0013739837398373987,
      0.0013739837398373987, 0.0014273373983739836, 0.0014273373983739836,
      0.001481707317073171, 0.001481707317073171, 0.0015370934959349596,
      0.0015370934959349596, 0.0015934959349593499, 0.0015934959349593499,
      0.0016509146341463418, 0.0016509146341463418, 0.0017093495934959353,
      0.0017093495934959353, 0.0017688008130081305, 0.0017688008130081305,
      0.0018292682926829269, 0.0018292682926829269, 0.0018907520325203253,
      0.0018907520325203253, 0.0019532520325203253, 0.0019532520325203253,
      0.0020167682926829269, 0.0020167682926829269, 0.0020813008130081303,
      0.0020813008130081303, 0.0021468495934959353, 0.0021468495934959353,
      0.0022134146341463417, 0.0022134146341463417, 0.00228099593495935,
      0.00228099593495935, 0.00234959349593496, 0.00234959349593496,
      0.0024192073170731711, 0.0024192073170731711, 0.0024898373983739844,
      0.0024898373983739844, 0.0025614837398373995, 0.0025614837398373995,
      0.0026341463414634152, 0.0026341463414634152, 0.0027078252032520325,
      0.0027078252032520325, 0.002782520325203252, 0.002782520325203252,
      0.0028582317073170731, 0.0028582317073170731, 0.0029349593495934961,
      0.0029349593495934961, 0.0030127032520325205, 0.0030127032520325205,
      0.0030914634146341465, 0.0030914634146341465, 0.0031712398373983743,
      0.0031712398373983743, 0.0032520325203252037, 0.0032520325203252037,
      0.0033338414634146345, 0.0033338414634146345, 0.0034166666666666672,
      0.0034166666666666672, 0.0035005081300813015, 0.0035005081300813015,
      0.0035853658536585372, 0.0035853658536585372, 0.0036712398373983748,
      0.0036712398373983748, 0.0037581300813008139, 0.0037581300813008139,
      0.0038460365853658545, 0.0038460365853658545, 0.0039349593495934957,
      0.0039349593495934957, 0.00402489837398374, 0.00402489837398374,
      0.0041158536585365856, 0.0041158536585365856, 0.0042078252032520325,
      0.0042078252032520325, 0.0043008130081300814, 0.0043008130081300814,
      0.0043948170731707313, 0.0043948170731707313, 0.004489837398373984,
      0.004489837398373984, 0.0045858739837398377, 0.0045858739837398377,
      0.0046829268292682934, 0.0046829268292682934, 0.00478099593495935,
      0.00478099593495935, 0.0048800813008130087, 0.0048800813008130087,
      0.0049801829268292692, 0.0049801829268292692, 0.0050813008130081308,
      0.0050813008130081308, 0.0051834349593495943, 0.0051834349593495943,
      0.00528658536585366, 0.00528658536585366, 0.0053907520325203262,
      0.0053907520325203262, 0.0054959349593495946, 0.0054959349593495946,
      0.0056021341463414641, 0.0056021341463414641, 0.0057093495934959345,
      0.0057093495934959345, 0.0058175813008130087, 0.0058175813008130087,
      0.0059268292682926839, 0.0059268292682926839, 0.0060370934959349592,
      0.0060370934959349592, 0.0061483739837398382, 0.0061483739837398382,
      0.0062606707317073183, 0.0062606707317073183, 0.0063739837398373994,
      0.0063739837398373994, 0.0064883130081300824, 0.0064883130081300824,
      0.0066036585365853674, 0.0066036585365853674, 0.0067200203252032534,
      0.0067200203252032534, 0.0068373983739837413, 0.0068373983739837413,
      0.0069557926829268311, 0.0069557926829268311, 0.007075203252032522,
      0.007075203252032522, 0.0071956300813008148, 0.0071956300813008148,
      0.0073170731707317077, 0.0073170731707317077, 0.0074395325203252035,
      0.0074395325203252035, 0.0075630081300813012, 0.0075630081300813012,
      0.0076875, 0.0076875, 0.0078130081300813014, 0.0078130081300813014,
      0.0079395325203252039, 0.0079395325203252039, 0.0080670731707317075,
      0.0080670731707317075, 0.0081956300813008139, 0.0081956300813008139,
      0.0083252032520325214, 0.0083252032520325214, 0.00845579268292683,
      0.00845579268292683, 0.0085873983739837411, 0.0085873983739837411,
      0.0087200203252032534, 0.0087200203252032534, 0.0088536585365853668,
      0.0088536585365853668, 0.0089883130081300829, 0.0089883130081300829,
      0.0091239837398374, 0.0091239837398374, 0.0092606707317073184,
      0.0092606707317073184, 0.00939837398373984, 0.00939837398373984,
      0.0095370934959349615, 0.0095370934959349615, 0.0096768292682926846,
      0.0096768292682926846, 0.00981758130081301, 0.00981758130081301,
      0.0099593495934959374, 0.0099593495934959374, 0.010102134146341465,
      0.010102134146341465, 0.010245934959349598, 0.010245934959349598,
      0.010390752032520328, 0.010390752032520328, 0.010536585365853661,
      0.010536585365853661, 0.010683434959349593, 0.010683434959349593,
      0.01083130081300813, 0.01083130081300813, 0.010980182926829268,
      0.010980182926829268, 0.011130081300813008, 0.011130081300813008,
      0.01128099593495935, 0.01128099593495935, 0.011432926829268292,
      0.011432926829268292, 0.011585873983739838, 0.011585873983739838,
      0.011739837398373984, 0.011739837398373984, 0.011894817073170732,
      0.011894817073170732, 0.012050813008130082, 0.012050813008130082,
      0.012207825203252034, 0.012207825203252034, 0.012365853658536586,
      0.012365853658536586, 0.012524898373983741, 0.012524898373983741,
      0.012684959349593497, 0.012684959349593497, 0.012846036585365855,
      0.012846036585365855, 0.013008130081300815, 0.013008130081300815,
      0.013171239837398376, 0.013171239837398376, 0.013335365853658538,
      0.013335365853658538, 0.013500508130081303, 0.013500508130081303,
      0.013666666666666669, 0.013666666666666669, 0.013833841463414636,
      0.013833841463414636, 0.014002032520325206, 0.014002032520325206,
      0.014171239837398377, 0.014171239837398377, 0.014341463414634149,
      0.014341463414634149, 0.014512703252032523, 0.014512703252032523,
      0.0146849593495935, 0.0146849593495935, 0.014858231707317076,
      0.014858231707317076, 0.015032520325203256, 0.015032520325203256,
      0.015207825203252036, 0.015207825203252036, 0.015384146341463418,
      0.015384146341463418, 0.015561483739837402, 0.015561483739837402,
      0.015739837398373983, 0.015739837398373983, 0.015919207317073171,
      0.015919207317073171, 0.016099593495934959, 0.016099593495934959,
      0.016280995934959349, 0.016280995934959349, 0.016463414634146342,
      0.016463414634146342, 0.016646849593495935, 0.016646849593495935,
      0.01683130081300813, 0.01683130081300813, 0.017016768292682928,
      0.017016768292682928, 0.017203252032520325, 0.017203252032520325,
      0.017390752032520326, 0.017390752032520326, 0.017579268292682925,
      0.017579268292682925, 0.017768800813008131, 0.017768800813008131,
      0.017959349593495936, 0.017959349593495936, 0.018150914634146344,
      0.018150914634146344, 0.018343495934959351, 0.018343495934959351,
      0.018537093495934961, 0.018537093495934961, 0.018731707317073173,
      0.018731707317073173, 0.018927337398373986, 0.018927337398373986,
      0.0191239837398374, 0.0191239837398374, 0.019321646341463418,
      0.019321646341463418, 0.019520325203252035, 0.019520325203252035,
      0.019720020325203255, 0.019720020325203255, 0.019920731707317077,
      0.019920731707317077, 0.0201224593495935, 0.0201224593495935,
      0.020325203252032523, 0.020325203252032523, 0.020528963414634151,
      0.020528963414634151, 0.020733739837398377, 0.020733739837398377,
      0.020939532520325207, 0.020939532520325207, 0.021146341463414639,
      0.021146341463414639, 0.021354166666666671, 0.021354166666666671,
      0.021563008130081305, 0.021563008130081305, 0.021772865853658542,
      0.021772865853658542, 0.021983739837398378, 0.021983739837398378,
      0.022195630081300811, 0.022195630081300811, 0.022408536585365856,
      0.022408536585365856, 0.022622459349593498, 0.022622459349593498,
      0.022837398373983738, 0.022837398373983738, 0.023053353658536588,
      0.023053353658536588, 0.023270325203252035, 0.023270325203252035,
      0.02348831300813008, 0.02348831300813008, 0.023707317073170735,
      0.023707317073170735, 0.023927337398373986, 0.023927337398373986,
      0.024148373983739837, 0.024148373983739837, 0.024370426829268297,
      0.024370426829268297, 0.024593495934959349, 0.024593495934959349,
      0.024816565040650405, 0.024816565040650405, 0.025038617886178862,
      0.025038617886178862, 0.025259654471544716, 0.025259654471544716,
      0.025479674796747967, 0.025479674796747967, 0.025698678861788619,
      0.025698678861788619, 0.025916666666666668, 0.025916666666666668,
      0.026133638211382114, 0.026133638211382114, 0.026349593495934961,
      0.026349593495934961, 0.026564532520325205, 0.026564532520325205,
      0.026778455284552846, 0.026778455284552846, 0.026991361788617888,
      0.026991361788617888, 0.027203252032520327, 0.027203252032520327,
      0.027414126016260164, 0.027414126016260164, 0.0276239837398374,
      0.0276239837398374, 0.027832825203252035, 0.027832825203252035,
      0.028040650406504067, 0.028040650406504067, 0.0282474593495935,
      0.0282474593495935, 0.028453252032520329, 0.028453252032520329,
      0.028658028455284555, 0.028658028455284555, 0.028861788617886179,
      0.028861788617886179, 0.029064532520325204, 0.029064532520325204,
      0.029266260162601625, 0.029266260162601625, 0.029466971544715448,
      0.029466971544715448, 0.029666666666666668, 0.029666666666666668,
      0.029865345528455284, 0.029865345528455284, 0.030063008130081302,
      0.030063008130081302, 0.030259654471544717, 0.030259654471544717,
      0.030455284552845529, 0.030455284552845529, 0.030649898373983742,
      0.030649898373983742, 0.030843495934959352, 0.030843495934959352,
      0.031036077235772359, 0.031036077235772359, 0.031227642276422767,
      0.031227642276422767, 0.031418191056910572, 0.031418191056910572,
      0.031607723577235777, 0.031607723577235777, 0.031796239837398377,
      0.031796239837398377, 0.031983739837398377, 0.031983739837398377,
      0.032170223577235771, 0.032170223577235771, 0.032355691056910572,
      0.032355691056910572, 0.032540142276422768, 0.032540142276422768,
      0.032723577235772364, 0.032723577235772364, 0.032905995934959353,
      0.032905995934959353, 0.033087398373983744, 0.033087398373983744,
      0.033267784552845528, 0.033267784552845528, 0.03344715447154472,
      0.03344715447154472, 0.033625508130081305, 0.033625508130081305,
      0.033802845528455291, 0.033802845528455291, 0.033979166666666671,
      0.033979166666666671, 0.034154471544715452, 0.034154471544715452,
      0.034328760162601626, 0.034328760162601626, 0.034502032520325208,
      0.034502032520325208, 0.034674288617886184, 0.034674288617886184,
      0.034845528455284561, 0.034845528455284561, 0.035015752032520331,
      0.035015752032520331, 0.0351849593495935, 0.0351849593495935,
      0.035353150406504066, 0.035353150406504066, 0.035520325203252039,
      0.035520325203252039, 0.035686483739837405, 0.035686483739837405,
      0.035851626016260171, 0.035851626016260171, 0.036015752032520332,
      0.036015752032520332, 0.036178861788617893, 0.036178861788617893,
      0.036340955284552848, 0.036340955284552848, 0.03650203252032521,
      0.03650203252032521, 0.036662093495934966, 0.036662093495934966,
      0.036821138211382123, 0.036821138211382123, 0.036979166666666674,
      0.036979166666666674, 0.037136178861788625, 0.037136178861788625,
      0.037292174796747971, 0.037292174796747971, 0.037447154471544723,
      0.037447154471544723, 0.037601117886178856, 0.037601117886178856,
      0.0377540650406504, 0.0377540650406504, 0.037905995934959344,
      0.037905995934959344, 0.038056910569105692, 0.038056910569105692,
      0.038206808943089428, 0.038206808943089428, 0.038355691056910571,
      0.038355691056910571, 0.0385035569105691, 0.0385035569105691,
      0.038650406504065038, 0.038650406504065038, 0.038796239837398369,
      0.038796239837398369, 0.038941056910569108, 0.038941056910569108,
      0.039084857723577233, 0.039084857723577233, 0.039227642276422767,
      0.039227642276422767, 0.039369410569105687, 0.039369410569105687,
      0.039510162601626014, 0.039510162601626014, 0.039649898373983736,
      0.039649898373983736, 0.039788617886178865, 0.039788617886178865,
      0.039926321138211388, 0.039926321138211388, 0.040063008130081304,
      0.040063008130081304, 0.040198678861788614, 0.040198678861788614,
      0.040333333333333332, 0.040333333333333332, 0.040466971544715444,
      0.040466971544715444, 0.040599593495934963, 0.040599593495934963,
      0.040731199186991876, 0.040731199186991876, 0.040861788617886183,
      0.040861788617886183, 0.040991361788617883, 0.040991361788617883,
      0.041119918699186991, 0.041119918699186991, 0.041247459349593493,
      0.041247459349593493, 0.0413739837398374, 0.0413739837398374,
      0.041499491869918706, 0.041499491869918706, 0.0416239837398374,
      0.0416239837398374, 0.041747459349593494, 0.041747459349593494,
      0.041869918699186992, 0.041869918699186992, 0.041991361788617884,
      0.041991361788617884, 0.042111788617886184, 0.042111788617886184,
      0.042231199186991877, 0.042231199186991877, 0.042349593495934965,
      0.042349593495934965, 0.042466971544715446, 0.042466971544715446,
      0.042583333333333334, 0.042583333333333334, 0.042698678861788616,
      0.042698678861788616, 0.042813008130081306, 0.042813008130081306,
      0.04292632113821139, 0.04292632113821139, 0.043038617886178868,
      0.043038617886178868, 0.043149898373983739, 0.043149898373983739,
      0.043260162601626018, 0.043260162601626018, 0.04336941056910569,
      0.04336941056910569, 0.04347764227642277, 0.04347764227642277,
      0.043584857723577244, 0.043584857723577244, 0.043691056910569112,
      0.043691056910569112, 0.043796239837398374, 0.043796239837398374,
      0.043900406504065043, 0.043900406504065043, 0.044003556910569105,
      0.044003556910569105, 0.044105691056910576, 0.044105691056910576,
      0.04420680894308944, 0.04420680894308944, 0.0443069105691057,
      0.0443069105691057, 0.04440599593495935, 0.04440599593495935,
      0.044504065040650409, 0.044504065040650409, 0.044601117886178862,
      0.044601117886178862, 0.044697154471544723, 0.044697154471544723,
      0.044792174796747977, 0.044792174796747977, 0.044886178861788625,
      0.044886178861788625, 0.044979166666666667, 0.044979166666666667,
      0.045071138211382117, 0.045071138211382117, 0.04516209349593496,
      0.04516209349593496, 0.045252032520325211, 0.045252032520325211,
      0.045340955284552842, 0.045340955284552842, 0.045428861788617887,
      0.045428861788617887, 0.045515752032520326, 0.045515752032520326,
      0.045601626016260159, 0.045601626016260159, 0.0456864837398374,
      0.0456864837398374, 0.045770325203252041, 0.045770325203252041,
      0.045853150406504062, 0.045853150406504062, 0.0459349593495935,
      0.0459349593495935, 0.046015752032520327, 0.046015752032520327,
      0.04609552845528455, 0.04609552845528455, 0.046174288617886181,
      0.046174288617886181, 0.046252032520325212, 0.046252032520325212,
      0.046328760162601623, 0.046328760162601623, 0.046404471544715449,
      0.046404471544715449, 0.046479166666666669, 0.046479166666666669,
      0.046552845528455282, 0.046552845528455282, 0.0466255081300813,
      0.0466255081300813, 0.046697154471544725, 0.046697154471544725,
      0.046767784552845526, 0.046767784552845526, 0.046837398373983742,
      0.046837398373983742, 0.046905995934959352, 0.046905995934959352,
      0.046973577235772362, 0.046973577235772362, 0.047040142276422767,
      0.047040142276422767, 0.047105691056910579, 0.047105691056910579,
      0.04717022357723577, 0.04717022357723577, 0.047233739837398377,
      0.047233739837398377, 0.047296239837398377, 0.047296239837398377,
      0.04735772357723577, 0.04735772357723577, 0.047418191056910572,
      0.047418191056910572, 0.047477642276422774, 0.047477642276422774,
      0.047536077235772356, 0.047536077235772356, 0.047593495934959353,
      0.047593495934959353, 0.047649898373983743, 0.047649898373983743,
      0.047705284552845527, 0.047705284552845527, 0.047759654471544719,
      0.047759654471544719, 0.047813008130081311, 0.047813008130081311,
      0.047865345528455283, 0.047865345528455283, 0.04791666666666667,
      0.04791666666666667, 0.04796697154471545, 0.04796697154471545,
      0.048016260162601625, 0.048016260162601625, 0.048064532520325207,
      0.048064532520325207, 0.048111788617886189, 0.048111788617886189,
      0.048158028455284552, 0.048158028455284552, 0.048203252032520329,
      0.048203252032520329, 0.0482474593495935, 0.0482474593495935,
      0.048290650406504064, 0.048290650406504064, 0.048332825203252036,
      0.048332825203252036, 0.048373983739837409, 0.048373983739837409,
      0.048414126016260162, 0.048414126016260162, 0.048453252032520329,
      0.048453252032520329, 0.04849136178861789, 0.04849136178861789,
      0.048528455284552845, 0.048528455284552845, 0.048564532520325207,
      0.048564532520325207, 0.048599593495934963, 0.048599593495934963,
      0.048633638211382113, 0.048633638211382113, 0.048666666666666671,
      0.048666666666666671, 0.048698678861788622, 0.048698678861788622,
      0.048729674796747967, 0.048729674796747967, 0.048759654471544719,
      0.048759654471544719, 0.048788617886178859, 0.048788617886178859,
      0.048816565040650406, 0.048816565040650406, 0.048843495934959354,
      0.048843495934959354, 0.048869410569105695, 0.048869410569105695,
      0.048894308943089437, 0.048894308943089437, 0.048918191056910573,
      0.048918191056910573, 0.0489410569105691, 0.0489410569105691,
      0.04896290650406504, 0.04896290650406504, 0.048983739837398378,
      0.048983739837398378, 0.04900355691056911, 0.04900355691056911,
      0.049022357723577242, 0.049022357723577242, 0.049040142276422768,
      0.049040142276422768, 0.049056910569105688, 0.049056910569105688,
      0.049072662601626016, 0.049072662601626016, 0.049087398373983744,
      0.049087398373983744, 0.049101117886178866, 0.049101117886178866,
      0.049113821138211389, 0.049113821138211389, 0.049125508130081305,
      0.049125508130081305, 0.049136178861788615, 0.049136178861788615,
      0.049145833333333333, 0.049145833333333333, 0.049154471544715451,
      0.049154471544715451, 0.049162093495934964, 0.049162093495934964,
      0.049168699186991877, 0.049168699186991877, 0.049174288617886183,
      0.049174288617886183, 0.049178861788617884, 0.049178861788617884,
      0.049182418699186992, 0.049182418699186992, 0.0491849593495935,
      0.0491849593495935, 0.0491864837398374, 0.0491864837398374,
      0.049186991869918706, 0.049186991869918706, 0.0491864837398374,
      0.0491864837398374, 0.049184959349593493, 0.049184959349593493,
      0.049182418699186992, 0.049182418699186992, 0.049178861788617891,
      0.049178861788617891, 0.049174288617886183, 0.049174288617886183,
      0.049168699186991877, 0.049168699186991877, 0.049162093495934964,
      0.049162093495934964, 0.049154471544715445, 0.049154471544715445,
      0.049145833333333333, 0.049145833333333333, 0.049136178861788622,
      0.049136178861788622, 0.049125508130081305, 0.049125508130081305,
      0.049113821138211389, 0.049113821138211389, 0.049101117886178866,
      0.049101117886178866, 0.049087398373983737, 0.049087398373983737,
      0.049072662601626016, 0.049072662601626016, 0.049056910569105695,
      0.049056910569105695, 0.049040142276422768, 0.049040142276422768,
      0.049022357723577242, 0.049022357723577242, 0.04900355691056911,
      0.04900355691056911, 0.048983739837398371, 0.048983739837398371,
      0.04896290650406504, 0.04896290650406504, 0.04894105691056911,
      0.04894105691056911, 0.048918191056910573, 0.048918191056910573,
      0.048894308943089437, 0.048894308943089437, 0.048869410569105695,
      0.048869410569105695, 0.048843495934959347, 0.048843495934959347,
      0.048816565040650406, 0.048816565040650406, 0.048788617886178866,
      0.048788617886178866, 0.048759654471544719, 0.048759654471544719,
      0.048729674796747974, 0.048729674796747974, 0.048698678861788622,
      0.048698678861788622, 0.048666666666666671, 0.048666666666666671,
      0.048633638211382113, 0.048633638211382113, 0.048599593495934956,
      0.048599593495934956, 0.048564532520325207, 0.048564532520325207,
      0.048528455284552852, 0.048528455284552852, 0.04849136178861789,
      0.04849136178861789, 0.048453252032520329, 0.048453252032520329,
      0.048414126016260162, 0.048414126016260162, 0.048373983739837395,
      0.048373983739837395, 0.048332825203252036, 0.048332825203252036,
      0.048290650406504071, 0.048290650406504071, 0.0482474593495935,
      0.0482474593495935, 0.048203252032520329, 0.048203252032520329,
      0.048158028455284552, 0.048158028455284552, 0.048111788617886175,
      0.048111788617886175, 0.048064532520325207, 0.048064532520325207,
      0.048016260162601632, 0.048016260162601632, 0.04796697154471545,
      0.04796697154471545, 0.04791666666666667, 0.04791666666666667,
      0.047865345528455283, 0.047865345528455283, 0.0478130081300813,
      0.0478130081300813, 0.047759654471544719, 0.047759654471544719,
      0.047705284552845534, 0.047705284552845534, 0.047649898373983743,
      0.047649898373983743, 0.047593495934959353, 0.047593495934959353,
      0.047536077235772356, 0.047536077235772356, 0.04747764227642276,
      0.04747764227642276, 0.047418191056910572, 0.047418191056910572,
      0.047357723577235777, 0.047357723577235777, 0.047296239837398377,
      0.047296239837398377, 0.047233739837398377, 0.047233739837398377,
      0.04717022357723577, 0.04717022357723577, 0.047105691056910565,
      0.047105691056910565, 0.047040142276422767, 0.047040142276422767,
      0.046973577235772362, 0.046973577235772362, 0.046905995934959352,
      0.046905995934959352, 0.046837398373983742, 0.046837398373983742,
      0.046767784552845526, 0.046767784552845526, 0.046697154471544711,
      0.046697154471544711, 0.0466255081300813, 0.0466255081300813,
      0.046552845528455289, 0.046552845528455289, 0.046479166666666669,
      0.046479166666666669, 0.046404471544715449, 0.046404471544715449,
      0.046328760162601623, 0.046328760162601623, 0.0462520325203252,
      0.0462520325203252, 0.046174288617886181, 0.046174288617886181,
      0.046095528455284557, 0.046095528455284557, 0.046015752032520327,
      0.046015752032520327, 0.0459349593495935, 0.0459349593495935,
      0.045853150406504062, 0.045853150406504062, 0.045770325203252027,
      0.045770325203252027, 0.0456864837398374, 0.0456864837398374,
      0.045601626016260166, 0.045601626016260166, 0.045515752032520326,
      0.045515752032520326, 0.045428861788617887, 0.045428861788617887,
      0.045340955284552842, 0.045340955284552842, 0.0452520325203252,
      0.0452520325203252, 0.04516209349593496, 0.04516209349593496,
      0.045071138211382117, 0.045071138211382117, 0.044979166666666667,
      0.044979166666666667, 0.044886178861788618, 0.044886178861788618,
      0.044792174796747963, 0.044792174796747963, 0.044697154471544709,
      0.044697154471544709, 0.044601117886178862, 0.044601117886178862,
      0.044504065040650409, 0.044504065040650409, 0.044405995934959343,
      0.044405995934959343, 0.044306910569105691, 0.044306910569105691,
      0.044206808943089426, 0.044206808943089426, 0.044105691056910562,
      0.044105691056910562, 0.044003556910569105, 0.044003556910569105,
      0.043900406504065043, 0.043900406504065043, 0.043796239837398367,
      0.043796239837398367, 0.043691056910569105, 0.043691056910569105,
      0.043584857723577231, 0.043584857723577231, 0.043477642276422757,
      0.043477642276422757, 0.04336941056910569, 0.04336941056910569,
      0.043260162601626011, 0.043260162601626011, 0.043149898373983732,
      0.043149898373983732, 0.043038617886178861, 0.043038617886178861,
      0.042926321138211376, 0.042926321138211376, 0.042813008130081293,
      0.042813008130081293, 0.042698678861788616, 0.042698678861788616,
      0.042583333333333327, 0.042583333333333327, 0.042466971544715439,
      0.042466971544715439, 0.042349593495934958, 0.042349593495934958,
      0.042231199186991863, 0.042231199186991863, 0.04211178861788617,
      0.04211178861788617, 0.041991361788617884, 0.041991361788617884,
      0.041869918699186992, 0.041869918699186992, 0.0417479674796748,
      0.0416260162601626, 0.041504065040650406, 0.041382113821138211,
      0.041260162601626016, 0.041138211382113821, 0.041016260162601625,
      0.04089430894308943, 0.040772357723577235, 0.04065040650406504,
      0.040528455284552845, 0.040406504065040649, 0.040284552845528454,
      0.040162601626016259, 0.040040650406504064, 0.039918699186991868,
      0.039918699186991868, 0.039796747967479687, 0.039796747967479687,
      0.039674796747967492, 0.0395528455284553, 0.0394308943089431,
      0.039308943089430906, 0.039186991869918711, 0.039065040650406516,
      0.03894308943089432, 0.038821138211382125, 0.03869918699186993,
      0.038577235772357735, 0.038455284552845539, 0.038333333333333344,
      0.038211382113821149, 0.038089430894308954, 0.037967479674796759,
      0.037845528455284563, 0.037723577235772368, 0.037601626016260173,
      0.037479674796747978, 0.037357723577235782, 0.037235772357723587,
      0.037113821138211392, 0.0369918699186992, 0.036869918699187,
      0.036747967479674806, 0.036626016260162611, 0.036504065040650416,
      0.036504065040650416, 0.036382113821138214, 0.036382113821138214,
      0.036260162601626018, 0.036138211382113823, 0.036016260162601628,
      0.035894308943089433, 0.035772357723577237, 0.035650406504065042,
      0.035528455284552847, 0.035406504065040652, 0.035284552845528457,
      0.035162601626016261, 0.035040650406504066, 0.034918699186991871,
      0.034796747967479676, 0.03467479674796748, 0.034552845528455285,
      0.03443089430894309, 0.034308943089430895, 0.0341869918699187,
      0.034065040650406504, 0.033943089430894309, 0.033821138211382114,
      0.033699186991869919, 0.033577235772357723, 0.033455284552845528,
      0.033333333333333333, 0.033211382113821138, 0.033089430894308942,
      0.032967479674796747, 0.032845528455284552, 0.032723577235772357,
      0.032601626016260161, 0.032479674796747966, 0.032357723577235771,
      0.032235772357723576, 0.032113821138211381, 0.031991869918699185,
      0.03186991869918699, 0.031747967479674795, 0.0316260162601626,
      0.031504065040650404, 0.031382113821138209, 0.031260162601626014,
      0.031138211382113819, 0.031016260162601623, 0.030894308943089428,
      0.030772357723577233, 0.030650406504065038, 0.030528455284552843,
      0.030406504065040647, 0.030284552845528452, 0.030162601626016257,
      0.030040650406504062, 0.029918699186991866, 0.029796747967479671,
      0.029674796747967476, 0.029552845528455281, 0.029430894308943086,
      0.02930894308943089, 0.029186991869918695, 0.0290650406504065,
      0.028943089430894305, 0.028821138211382109, 0.028699186991869914,
      0.028577235772357719, 0.028455284552845524, 0.028333333333333328,
      0.028211382113821133, 0.028089430894308938, 0.027967479674796743,
      0.027967479674796743, 0.027845528455284544, 0.027845528455284544,
      0.027723577235772349, 0.027601626016260154, 0.027479674796747958,
      0.027357723577235763, 0.027235772357723568, 0.027113821138211373,
      0.026991869918699177, 0.026869918699186982, 0.026747967479674787,
      0.026626016260162592, 0.026504065040650397, 0.0263821138211382,
      0.026260162601626006, 0.026138211382113811, 0.026016260162601616,
      0.02589430894308942, 0.025772357723577225, 0.02565040650406503,
      0.025528455284552835, 0.025406504065040639, 0.025284552845528444,
      0.025162601626016249, 0.025040650406504054, 0.024918699186991859,
      0.024796747967479663, 0.024674796747967468, 0.024552845528455273,
      0.024430894308943078, 0.024430894308943078, 0.024308943089430893,
      0.024308943089430893, 0.024186991869918698, 0.024065040650406502,
      0.023943089430894307, 0.023821138211382112, 0.023699186991869917,
      0.023577235772357721, 0.023455284552845526, 0.023333333333333331,
      0.023211382113821136, 0.02308943089430894, 0.022967479674796745,
      0.02284552845528455, 0.022723577235772355, 0.02260162601626016,
      0.022479674796747964, 0.022357723577235769, 0.022235772357723574,
      0.022113821138211379, 0.021991869918699183, 0.021869918699186988,
      0.021747967479674793, 0.021626016260162598, 0.021504065040650402,
      0.021382113821138207, 0.021260162601626012, 0.021138211382113817,
      0.021016260162601622, 0.020894308943089426, 0.020772357723577231,
      0.020650406504065036, 0.020528455284552841, 0.020406504065040645,
      0.02028455284552845, 0.020162601626016255, 0.02004065040650406,
      0.019918699186991864, 0.019796747967479669, 0.019674796747967474,
      0.019552845528455279, 0.019430894308943084, 0.019308943089430888,
      0.019308943089430888, 0.01918699186991869, 0.01918699186991869,
      0.019065040650406494, 0.0189430894308943, 0.018821138211382104,
      0.018699186991869909, 0.018577235772357713, 0.018455284552845518,
      0.018333333333333323, 0.018211382113821128, 0.018089430894308933,
      0.017967479674796737, 0.017845528455284542, 0.017723577235772347,
      0.017601626016260152, 0.017479674796747956, 0.017357723577235761,
      0.017235772357723566, 0.017113821138211371, 0.016991869918699175,
      0.01686991869918698, 0.016747967479674785, 0.01662601626016259,
      0.016504065040650395, 0.0163821138211382, 0.016260162601626004,
      0.016138211382113809, 0.016016260162601614, 0.015894308943089418,
      0.015772357723577223, 0.015650406504065028, 0.015528455284552833,
      0.015406504065040637, 0.015284552845528442, 0.015162601626016247,
      0.015040650406504052, 0.014918699186991857, 0.014796747967479661,
      0.014674796747967466, 0.014552845528455271, 0.014430894308943076,
      0.01430894308943088, 0.014186991869918685, 0.01406504065040649,
      0.01406504065040649, 0.013943089430894291, 0.013943089430894291,
      0.013821138211382096, 0.0136991869918699, 0.013577235772357706,
      0.01345528455284551, 0.013333333333333315, 0.01321138211382112,
      0.013089430894308925, 0.012967479674796729, 0.012845528455284534,
      0.012723577235772339, 0.012601626016260144, 0.012479674796747948,
      0.012357723577235753, 0.012235772357723558, 0.012113821138211363,
      0.011991869918699168, 0.011869918699186972, 0.011747967479674777,
      0.011626016260162582, 0.011504065040650387, 0.011382113821138191,
      0.011260162601625996, 0.011138211382113801, 0.011016260162601606,
      0.010894308943089411, 0.010772357723577215, 0.01065040650406502,
      0.010528455284552825, 0.01040650406504063, 0.010284552845528434,
      0.010162601626016239, 0.010040650406504044, 0.0099186991869918487,
      0.0097967479674796534, 0.0096747967479674582, 0.009552845528455263,
      0.0094308943089430677, 0.0093089430894308725, 0.0091869918699186773,
      0.009065040650406482, 0.0089430894308942868, 0.0088211382113820916,
      0.0086991869918698964, 0.0086991869918698964, 0.008577235772357715,
      0.008577235772357715, 0.00845528455284552, 0.0083333333333333245,
      0.00821138211382113, 0.0080894308943089341, 0.0079674796747967389,
      0.0078455284552845436, 0.0077235772357723484, 0.0076016260162601532,
      0.0074796747967479579, 0.0073577235772357627, 0.0072357723577235675,
      0.0071138211382113722, 0.006991869918699177, 0.0068699186991869818,
      0.0067479674796747866, 0.0067479674796747866, 0.0066260162601625844,
      0.0066260162601625844, 0.0065040650406503892, 0.0063821138211381939,
      0.0062601626016259987, 0.0061382113821138035, 0.0060162601626016082,
      0.005894308943089413, 0.0057723577235772178, 0.0056504065040650225,
      0.0055284552845528273, 0.0054065040650406321, 0.0052845528455284368,
      0.0051626016260162416, 0.0050406504065040464, 0.0049186991869918512,
      0.0047967479674796559, 0.0046747967479674607, 0.0045528455284552655,
      0.00443089430894307, 0.004308943089430875, 0.00418699186991868,
      0.0040650406504064845, 0.0039430894308942893, 0.0038211382113820941,
      0.0036991869918698989, 0.0035772357723577036, 0.0034552845528455084,
      0.0033333333333333132, 0.0032113821138211179, 0.0030894308943089227,
      0.0029674796747967275, 0.0028455284552845322, 0.002723577235772337,
      0.0026016260162601418, 0.0024796747967479466, 0.0023577235772357513,
      0.0022357723577235561, 0.0021138211382113609, 0.0019918699186991656,
      0.0018699186991869704, 0.0017479674796747752, 0.00162601626016258,
      0.0015040650406503847, 0.0013821138211381895, 0.0012601626016259942,
      0.001138211382113799, 0.0010162601626016038, 0.00089430894308940856,
      0.00077235772357721333, 0.0006504065040650181, 0.00052845528455282287,
      0.00040650406504062764, 0.00028455284552843241, 0.00016260162601623718,
      4.0650406504041947E-5, -8.1300813008153283E-5, -0.00020325203252034851,
      -0.00032520325203254374, -0.000447154471544739, -0.0005691056910569342,
      -0.00069105691056912943, -0.00081300813008132466, -0.0009349593495935199,
      -0.0010569105691057151, -0.0011788617886179104, -0.0013008130081301056,
      -0.0014227642276423008, -0.001544715447154496, -0.0016666666666666913,
      -0.0017886178861788865, -0.0019105691056910817, -0.002032520325203277,
      -0.0021544715447154722, -0.0022764227642276674, -0.0023983739837398627,
      -0.0025203252032520579, -0.0026422764227642531, -0.0027642276422764483,
      -0.0028861788617886436, -0.0028861788617886436, -0.0030081300813008249,
      -0.0030081300813008249, -0.00313008130081302, -0.0032520325203252154,
      -0.0032520325203252154, -0.0033739837398374176, -0.0033739837398374176,
      -0.0034959349593496128, -0.003617886178861808, -0.0037398373983740033,
      -0.0038617886178861985, -0.0039837398373983937, -0.0041056910569105889,
      -0.0042276422764227842, -0.0043495934959349794, -0.0044715447154471746,
      -0.00459349593495937, -0.0047154471544715651, -0.00483739837398376,
      -0.0049593495934959556, -0.0050813008130081508, -0.005203252032520346,
      -0.0053252032520325412, -0.0054471544715447365, -0.0055691056910569317,
      -0.0056910569105691269, -0.0058130081300813222, -0.0059349593495935174,
      -0.0060569105691057126, -0.0061788617886179079, -0.0063008130081301031,
      -0.0064227642276422983, -0.0065447154471544935, -0.0066666666666666888,
      -0.006788617886178884, -0.0069105691056910792, -0.0070325203252032745,
      -0.00715447154471547, -0.0072764227642276649, -0.00739837398373986,
      -0.0075203252032520554, -0.0076422764227642506, -0.0077642276422764459,
      -0.0078861788617886411, -0.0080081300813008363, -0.0081300813008130315,
      -0.0082520325203252268, -0.008373983739837422, -0.0084959349593496172,
      -0.0086178861788618125, -0.0087398373983740077, -0.0088617886178862029,
      -0.0089837398373983982, -0.0091056910569105934, -0.0092276422764227886,
      -0.0093495934959349838, -0.0094715447154471791, -0.0095934959349593743,
      -0.00971544715447157, -0.0098373983739837648, -0.00995934959349596,
      -0.010081300813008155, -0.01020325203252035, -0.010325203252032546,
      -0.010447154471544741, -0.010569105691056936, -0.010691056910569131,
      -0.010813008130081327, -0.010934959349593522, -0.011056910569105717,
      -0.011178861788617912, -0.011300813008130108, -0.011422764227642303,
      -0.011544715447154498, -0.011666666666666693, -0.011788617886178888,
      -0.011788617886178888, -0.01191056910569107, -0.01191056910569107,
      -0.012032520325203279, -0.012154471544715488, -0.012154471544715488,
      -0.012276422764227669, -0.012398373983739851, -0.012398373983739851,
      -0.01252032520325206, -0.012642276422764269, -0.012642276422764269,
      -0.01276422764227645, -0.012886178861788632, -0.012886178861788632,
      -0.013008130081300841, -0.01313008130081305, -0.01313008130081305,
      -0.013252032520325231, -0.013252032520325231, -0.01337398373983742,
      -0.01337398373983742, -0.013495934959349622, -0.013495934959349622,
      -0.013617886178861831, -0.013617886178861831, -0.013739837398374012,
      -0.013739837398374012, -0.0138617886178862, -0.0138617886178862,
      -0.01398373983739841, -0.01398373983739841, -0.014105691056910612,
      -0.014105691056910612, -0.0142276422764228, -0.0142276422764228,
      -0.014349593495934981, -0.014349593495934981, -0.01447154471544719,
      -0.0145934959349594, -0.0145934959349594, -0.014715447154471581,
      -0.014837398373983762, -0.014837398373983762, -0.014959349593495971,
      -0.01508130081300818, -0.01508130081300818, -0.015203252032520362,
      -0.015325203252032543, -0.015325203252032543, -0.015447154471544752,
      -0.015569105691056961, -0.015569105691056961, -0.015691056910569143,
      -0.015813008130081324, -0.015813008130081324, -0.015934959349593533,
      -0.016056910569105742, -0.016056910569105742, -0.016178861788617924,
      -0.016300813008130105, -0.016300813008130105, -0.016422764227642314,
      -0.016544715447154523, -0.016544715447154523, -0.016666666666666705,
      -0.016788617886178886, -0.016788617886178886, -0.016910569105691095,
      -0.017032520325203304, -0.017032520325203304, -0.017154471544715486,
      -0.017276422764227667, -0.017276422764227667, -0.017398373983739876,
      -0.017520325203252085, -0.017520325203252085, -0.017642276422764266,
      -0.017764227642276448, -0.017764227642276448, -0.017886178861788657,
      -0.018008130081300866, -0.018008130081300866, -0.018130081300813047,
      -0.018252032520325229, -0.018252032520325229, -0.018373983739837438,
      -0.018495934959349647, -0.018495934959349647, -0.018617886178861828,
      -0.01873983739837401, -0.018861788617886191, -0.018861788617886191,
      -0.0189837398373984, -0.019105691056910609, -0.019105691056910609,
      -0.019227642276422791, -0.019349593495934972, -0.019349593495934972,
      -0.019471544715447181, -0.01959349593495939, -0.01959349593495939,
      -0.019715447154471571, -0.019837398373983753, -0.019837398373983753,
      -0.019959349593495962, -0.020081300813008171, -0.020081300813008171,
      -0.020203252032520352, -0.020325203252032534, -0.020325203252032534,
      -0.020447154471544743, -0.020569105691056952, -0.020569105691056952,
      -0.020691056910569133, -0.020813008130081315, -0.020813008130081315,
      -0.020934959349593524, -0.021056910569105733, -0.021056910569105733,
      -0.021178861788617914, -0.021300813008130096, -0.021300813008130096,
      -0.021422764227642305, -0.021544715447154514, -0.021544715447154514,
      -0.021666666666666695, -0.021788617886178877, -0.021788617886178877,
      -0.021910569105691086, -0.022032520325203295, -0.022032520325203295,
      -0.022154471544715476, -0.022276422764227657, -0.022276422764227657,
      -0.022398373983739867, -0.022520325203252076, -0.022520325203252076,
      -0.022642276422764257, -0.022764227642276438, -0.022764227642276438,
      -0.022886178861788647, -0.023008130081300857, -0.023008130081300857,
      -0.023130081300813038, -0.023252032520325219, -0.023252032520325219,
      -0.023373983739837428, -0.023495934959349637, -0.023495934959349637,
      -0.023617886178861819, -0.023739837398374, -0.023739837398374,
      -0.023861788617886209, -0.023983739837398418, -0.023983739837398418,
      -0.0241056910569106, -0.024227642276422781, -0.024227642276422781,
      -0.02434959349593499, -0.0244715447154472, -0.0244715447154472,
      -0.024593495934959381, -0.024715447154471562, -0.024715447154471562,
      -0.024837398373983771, -0.02495934959349598, -0.02495934959349598,
      -0.025081300813008162, -0.025203252032520343, -0.025203252032520343,
      -0.025325203252032552, -0.025447154471544761, -0.025447154471544761,
      -0.025569105691056943, -0.025691056910569124, -0.025691056910569124,
      -0.025813008130081333, -0.025934959349593542, -0.025934959349593542,
      -0.026056910569105723, -0.026178861788617905, -0.026178861788617905,
      -0.026300813008130114, -0.026422764227642323, -0.026422764227642323,
      -0.026544715447154504, -0.026666666666666686, -0.026666666666666686,
      -0.026788617886178895, -0.026910569105691104, -0.026910569105691104,
      -0.027032520325203285, -0.027154471544715467, -0.027154471544715467,
      -0.027276422764227676, -0.027398373983739885, -0.027398373983739885,
      -0.027520325203252066, -0.027642276422764248, -0.027642276422764248,
      -0.027764227642276457, -0.027886178861788666, -0.027886178861788666,
      -0.028008130081300847, -0.028130081300813028, -0.028130081300813028,
      -0.028252032520325238, -0.028373983739837447, -0.028373983739837447,
      -0.028495934959349628, -0.028495934959349628, -0.028617886178861823,
      -0.028617886178861823, -0.028739837398374019, -0.028739837398374019,
      -0.028861788617886228, -0.028861788617886228, -0.028983739837398409,
      -0.028983739837398409, -0.029105691056910604, -0.029105691056910604,
      -0.029227642276422813, -0.029227642276422813, -0.029349593495935009,
      -0.029349593495935009, -0.029471544715447204, -0.029471544715447204,
      -0.029593495934959385, -0.029593495934959385, -0.029715447154471594,
      -0.029837398373983803, -0.029837398373983803, -0.029959349593495985,
      -0.030081300813008166, -0.030081300813008166, -0.030203252032520375,
      -0.030325203252032584, -0.030325203252032584, -0.030447154471544766,
      -0.030569105691056947, -0.030569105691056947, -0.030691056910569156,
      -0.030813008130081365, -0.030813008130081365, -0.030934959349593547,
      -0.031056910569105728, -0.031056910569105728, -0.031178861788617937,
      -0.031300813008130146, -0.031300813008130146, -0.031422764227642327,
      -0.031544715447154509, -0.031544715447154509, -0.031666666666666718,
      -0.031788617886178927, -0.031788617886178927, -0.031910569105691108,
      -0.03203252032520329, -0.03203252032520329, -0.0321544715447155,
      -0.032276422764227708, -0.032276422764227708, -0.032398373983739889,
      -0.032520325203252071, -0.032520325203252071, -0.03264227642276428,
      -0.032764227642276489, -0.032764227642276489, -0.03288617886178867,
      -0.033008130081300852, -0.033008130081300852, -0.033130081300813061,
      -0.03325203252032527, -0.03325203252032527, -0.033373983739837451,
      -0.033495934959349632, -0.033495934959349632, -0.033617886178861842,
      -0.033739837398374051, -0.033739837398374051, -0.033861788617886232,
      -0.033983739837398413, -0.033983739837398413, -0.034105691056910623,
      -0.034105691056910623, -0.034227642276422804, -0.034227642276422804,
      -0.034349593495935013, -0.034349593495935013, -0.034471544715447194,
      -0.034593495934959376, -0.034593495934959376, -0.034715447154471585,
      -0.034837398373983794, -0.034837398373983794, -0.034959349593495975,
      -0.035081300813008157, -0.035081300813008157, -0.035203252032520366,
      -0.035325203252032575, -0.035325203252032575, -0.035447154471544756,
      -0.035569105691056938, -0.035569105691056938, -0.035691056910569147,
      -0.035813008130081356, -0.035813008130081356, -0.035934959349593537,
      -0.036056910569105718, -0.036056910569105718, -0.036178861788617928,
      -0.036300813008130137, -0.036300813008130137, -0.036422764227642318,
      -0.0365447154471545, -0.0365447154471545, -0.036666666666666708,
      -0.036788617886178918, -0.036788617886178918, -0.0369105691056911,
      -0.03703252032520328, -0.03703252032520328, -0.037154471544715489,
      -0.0372764227642277, -0.0372764227642277, -0.03739837398373988,
      -0.037520325203252061, -0.037520325203252061, -0.03764227642276427,
      -0.037764227642276479, -0.037764227642276479, -0.037886178861788661,
      -0.038008130081300842, -0.038008130081300842, -0.038130081300813051,
      -0.03825203252032526, -0.03825203252032526, -0.038373983739837442,
      -0.038495934959349623, -0.038495934959349623, -0.038617886178861832,
      -0.038739837398374041, -0.038739837398374041, -0.038861788617886223,
      -0.038983739837398404, -0.038983739837398404, -0.039105691056910613,
      -0.039227642276422822, -0.039227642276422822, -0.039349593495935004,
      -0.039471544715447185, -0.039471544715447185, -0.039593495934959394,
      -0.0397154471544716, -0.0397154471544716, -0.039837398373983784,
      -0.039959349593495966, -0.039959349593495966, -0.040081300813008175,
      -0.040203252032520384, -0.040203252032520384, -0.040325203252032565,
      -0.040447154471544747, -0.040447154471544747, -0.040569105691056956,
      -0.040691056910569165, -0.040691056910569165, -0.040813008130081346,
      -0.040934959349593528, -0.040934959349593528, -0.041056910569105737,
      -0.041056910569105737, -0.041178353658536643, -0.041178353658536643,
      -0.041298780487804922, -0.041298780487804922, -0.0414181910569106,
      -0.0414181910569106, -0.0415365853658537, -0.0415365853658537,
      -0.041653963414634204, -0.041653963414634204, -0.041770325203252079,
      -0.041770325203252079, -0.041885670731707354, -0.041885670731707354,
      -0.042000000000000044, -0.042000000000000044, -0.042113313008130142,
      -0.042113313008130142, -0.042225609756097605, -0.042225609756097605,
      -0.042336890243902477, -0.042336890243902477, -0.042447154471544762,
      -0.042447154471544762, -0.042556402439024449, -0.042556402439024449,
      -0.042664634146341508, -0.042664634146341508, -0.042771849593495968,
      -0.042771849593495968, -0.042878048780487857, -0.042878048780487857,
      -0.042983231707317132, -0.042983231707317132, -0.043087398373983787,
      -0.043087398373983787, -0.043190548780487843, -0.043190548780487843,
      -0.043292682926829321, -0.043292682926829321, -0.043393800813008192,
      -0.043393800813008192, -0.043493902439024443, -0.043493902439024443,
      -0.043592987804878087, -0.043592987804878087, -0.043691056910569154,
      -0.043691056910569154, -0.043788109756097621, -0.043788109756097621,
      -0.043884146341463467, -0.043884146341463467, -0.043979166666666708,
      -0.043979166666666708, -0.04407317073170737, -0.04407317073170737,
      -0.044166158536585426, -0.044166158536585426, -0.044258130081300862,
      -0.044258130081300862, -0.0443490853658537, -0.0443490853658537,
      -0.044439024390243956, -0.044439024390243956, -0.044527947154471607,
      -0.044527947154471607, -0.044615853658536639, -0.044615853658536639,
      -0.044702743902439064, -0.044702743902439064, -0.044788617886178911,
      -0.044788617886178911, -0.044873475609756158, -0.044873475609756158,
      -0.044957317073170786, -0.044957317073170786, -0.045040142276422807,
      -0.045040142276422807, -0.045121951219512249, -0.045121951219512249,
      -0.045202743902439065, -0.045202743902439065, -0.0452825203252033,
      -0.0452825203252033, -0.045361280487804918, -0.045361280487804918,
      -0.045439024390243957, -0.045439024390243957, -0.045515752032520368,
      -0.045515752032520368, -0.0455914634146342, -0.0455914634146342,
      -0.045666158536585413, -0.045666158536585413, -0.045739837398374034,
      -0.045739837398374034, -0.045812500000000048, -0.045812500000000048,
      -0.045884146341463469, -0.045884146341463469, -0.045954776422764271,
      -0.045954776422764271, -0.046024390243902494, -0.046024390243902494,
      -0.0460929878048781, -0.0460929878048781, -0.046160569105691107,
      -0.046160569105691107, -0.046227134146341511, -0.046227134146341511,
      -0.046292682926829323, -0.046292682926829323, -0.046357215447154515,
      -0.046357215447154515, -0.046420731707317128, -0.046420731707317128,
      -0.046483231707317121, -0.046483231707317121, -0.046544715447154522,
      -0.046544715447154522, -0.046605182926829317, -0.046605182926829317,
      -0.046664634146341519, -0.046664634146341519, -0.0467230691056911,
      -0.0467230691056911, -0.046780487804878104, -0.046780487804878104,
      -0.046836890243902488, -0.046836890243902488, -0.046892276422764279,
      -0.046892276422764279, -0.046946646341463463, -0.046946646341463463,
      -0.047000000000000056, -0.047000000000000056, -0.047052337398374035,
      -0.047052337398374035, -0.047103658536585422, -0.047103658536585422,
      -0.047153963414634195, -0.047153963414634195, -0.047203252032520376,
      -0.047203252032520376, -0.047251524390243951, -0.047251524390243951,
      -0.047298780487804934, -0.047298780487804934, -0.0473450203252033,
      -0.0473450203252033, -0.04739024390243908, -0.04739024390243908,
      -0.047434451219512244, -0.047434451219512244, -0.047477642276422816,
      -0.047477642276422816, -0.047519817073170781, -0.047519817073170781,
      -0.047560975609756154, -0.047560975609756154, -0.047601117886178913,
      -0.047601117886178913, -0.047640243902439081, -0.047640243902439081,
      -0.047678353658536635, -0.047678353658536635, -0.047715447154471596,
      -0.047715447154471596, -0.047751524390243952, -0.047751524390243952,
      -0.047786585365853715, -0.047786585365853715, -0.047820630081300865,
      -0.047820630081300865, -0.047853658536585422, -0.047853658536585422,
      -0.047885670731707367, -0.047885670731707367, -0.047916666666666718,
      -0.047916666666666718, -0.047946646341463464, -0.047946646341463464,
      -0.047975609756097617, -0.047975609756097617, -0.048003556910569158,
      -0.048003556910569158, -0.048030487804878105, -0.048030487804878105,
      -0.04805640243902444, -0.04805640243902444, -0.048081300813008182,
      -0.048081300813008182, -0.048105182926829318, -0.048105182926829318,
      -0.048128048780487862, -0.048128048780487862, -0.048149898373983792,
      -0.048149898373983792, -0.04817073170731713, -0.04817073170731713,
      -0.048190548780487855, -0.048190548780487855, -0.048209349593495987,
      -0.048209349593495987, -0.048227134146341513, -0.048227134146341513,
      -0.04824390243902444, -0.04824390243902444, -0.048259654471544768,
      -0.048259654471544768, -0.048274390243902496, -0.048274390243902496,
      -0.048288109756097611, -0.048288109756097611, -0.048300813008130133,
      -0.048300813008130133, -0.04831250000000005, -0.04831250000000005,
      -0.048323170731707374, -0.048323170731707374, -0.048332825203252085,
      -0.048332825203252085, -0.048341463414634196, -0.048341463414634196,
      -0.048349085365853715, -0.048349085365853715, -0.048355691056910621,
      -0.048355691056910621, -0.048361280487804928, -0.048361280487804928,
      -0.048365853658536642, -0.048365853658536642, -0.048369410569105743,
      -0.048369410569105743, -0.048371951219512252, -0.048371951219512252,
      -0.048373475609756154, -0.048373475609756154, -0.048373983739837451,
      -0.048373983739837451, -0.048373475609756154, -0.048373475609756154,
      -0.048371951219512252, -0.048371951219512252, -0.04836941056910575,
      -0.04836941056910575, -0.048365853658536642, -0.048365853658536642,
      -0.048361280487804935, -0.048361280487804935, -0.048355691056910621,
      -0.048355691056910621, -0.048349085365853715, -0.048349085365853715,
      -0.0483414634146342, -0.0483414634146342, -0.048332825203252092,
      -0.048332825203252092, -0.048323170731707374, -0.048323170731707374,
      -0.048312500000000057, -0.048312500000000057, -0.04830081300813014,
      -0.04830081300813014, -0.048288109756097618, -0.048288109756097618,
      -0.048274390243902496, -0.048274390243902496, -0.048259654471544775,
      -0.048259654471544775, -0.048243902439024447, -0.048243902439024447,
      -0.04822713414634152, -0.04822713414634152, -0.048209349593495987,
      -0.048209349593495987, -0.048190548780487862, -0.048190548780487862,
      -0.04817073170731713, -0.04817073170731713, -0.0481498983739838,
      -0.0481498983739838, -0.048128048780487862, -0.048128048780487862,
      -0.048105182926829325, -0.048105182926829325, -0.048081300813008189,
      -0.048081300813008189, -0.048056402439024447, -0.048056402439024447,
      -0.048030487804878105, -0.048030487804878105, -0.048003556910569165,
      -0.048003556910569165, -0.047975609756097617, -0.047975609756097617,
      -0.047946646341463471, -0.047946646341463471, -0.047916666666666718,
      -0.047916666666666718, -0.047885670731707373, -0.047885670731707373,
      -0.047853658536585422, -0.047853658536585422, -0.047820630081300872,
      -0.047820630081300872, -0.047786585365853708, -0.047786585365853708,
      -0.047751524390243959, -0.047751524390243959, -0.0477154471544716,
      -0.0477154471544716, -0.047678353658536642, -0.047678353658536642,
      -0.047640243902439081, -0.047640243902439081, -0.04760111788617892,
      -0.04760111788617892, -0.047560975609756161, -0.047560975609756161,
      -0.047519817073170788, -0.047519817073170788, -0.047477642276422816,
      -0.047477642276422816, -0.047434451219512251, -0.047434451219512251,
      -0.047390243902439087, -0.047390243902439087, -0.04734502032520331,
      -0.04734502032520331, -0.047298780487804927, -0.047298780487804927,
      -0.047251524390243958, -0.047251524390243958, -0.04720325203252039,
      -0.04720325203252039, -0.0471539634146342, -0.0471539634146342,
      -0.047103658536585429, -0.047103658536585429, -0.047052337398374042,
      -0.047052337398374042, -0.047000000000000063, -0.047000000000000063,
      -0.04694664634146347, -0.04694664634146347, -0.046892276422764292,
      -0.046892276422764292, -0.046836890243902495, -0.046836890243902495,
      -0.046780487804878111, -0.046780487804878111, -0.046723069105691115,
      -0.046723069105691115, -0.046664634146341526, -0.046664634146341526,
      -0.046605182926829324, -0.046605182926829324, -0.046544715447154536,
      -0.046544715447154536, -0.046483231707317128, -0.046483231707317128,
      -0.046420731707317135, -0.046420731707317135, -0.046357215447154529,
      -0.046357215447154529, -0.04629268292682933, -0.04629268292682933,
      -0.046227134146341518, -0.046227134146341518, -0.046160569105691121,
      -0.046160569105691121, -0.046092987804878104, -0.046092987804878104,
      -0.0460243902439025, -0.0460243902439025, -0.045954776422764285,
      -0.045954776422764285, -0.045884146341463476, -0.045884146341463476,
      -0.045812500000000055, -0.045812500000000055, -0.045739837398374047,
      -0.045739837398374047, -0.04566615853658542, -0.04566615853658542,
      -0.045591463414634208, -0.045591463414634208, -0.045515752032520382,
      -0.045515752032520382, -0.045439024390243964, -0.045439024390243964,
      -0.045361280487804932, -0.045361280487804932, -0.045282520325203315,
      -0.045282520325203315, -0.045202743902439078, -0.045202743902439078,
      -0.045121951219512263, -0.045121951219512263, -0.04504014227642282,
      -0.04504014227642282, -0.044957317073170792, -0.044957317073170792,
      -0.044873475609756151, -0.044873475609756151, -0.044788617886178925,
      -0.044788617886178925, -0.044702743902439078, -0.044702743902439078,
      -0.044615853658536653, -0.044615853658536653, -0.0445279471544716,
      -0.0445279471544716, -0.044439024390243963, -0.044439024390243963,
      -0.044349085365853712, -0.044349085365853712, -0.044258130081300875,
      -0.044258130081300875, -0.044166158536585419, -0.044166158536585419,
      -0.044073170731707384, -0.044073170731707384, -0.043979166666666722,
      -0.043979166666666722, -0.043884146341463481, -0.043884146341463481,
      -0.043788109756097614, -0.043788109756097614, -0.043691056910569168,
      -0.043691056910569168, -0.0435929878048781, -0.0435929878048781,
      -0.043493902439024457, -0.043493902439024457, -0.043393800813008185,
      -0.043393800813008185, -0.043292682926829334, -0.043292682926829334,
      -0.043190548780487857, -0.043190548780487857, -0.0430873983739838,
      -0.0430873983739838, -0.042983231707317125, -0.042983231707317125,
      -0.042878048780487871, -0.042878048780487871, -0.042771849593495989,
      -0.042771849593495989, -0.042664634146341529, -0.042664634146341529,
      -0.042556402439024442, -0.042556402439024442, -0.042447154471544776,
      -0.042447154471544776, -0.042336890243902491, -0.042336890243902491,
      -0.042225609756097626, -0.042225609756097626, -0.042113313008130135,
      -0.042113313008130135, -0.042000000000000065, -0.042000000000000065,
      -0.041885670731707396, -0.041885670731707396, -0.041770325203252093,
      -0.041770325203252093, -0.0416539634146342, -0.0416539634146342,
      -0.041536585365853723, -0.041536585365853723, -0.041418191056910643,
      -0.041418191056910643, -0.041298780487804942, -0.041298780487804942,
      -0.041178353658536636, -0.041178353658536636, -0.041056910569105751,
      -0.041056910569105751, -0.040934451219512273, -0.040934451219512273,
      -0.040810975609756162, -0.040810975609756162, -0.040686483739837444,
      -0.040686483739837444, -0.040560975609756161, -0.040560975609756161,
      -0.040434451219512273, -0.040434451219512273, -0.040306910569105757,
      -0.040306910569105757, -0.040178353658536635, -0.040178353658536635,
      -0.040048780487804941, -0.040048780487804941, -0.039918191056910649,
      -0.039918191056910649, -0.039786585365853722, -0.039786585365853722,
      -0.039653963414634195, -0.039653963414634195, -0.0395203252032521,
      -0.0395203252032521, -0.039385670731707394, -0.039385670731707394,
      -0.039250000000000063, -0.039250000000000063, -0.039113313008130132,
      -0.039113313008130132, -0.038975609756097623, -0.038975609756097623,
      -0.038836890243902515, -0.038836890243902515, -0.03869715447154478,
      -0.03869715447154478, -0.038556402439024438, -0.038556402439024438,
      -0.038414634146341525, -0.038414634146341525, -0.038271849593496013,
      -0.038271849593496013, -0.038128048780487866, -0.038128048780487866,
      -0.037983231707317114, -0.037983231707317114, -0.037837398373983804,
      -0.037837398373983804, -0.03769054878048788, -0.03769054878048788,
      -0.037542682926829329, -0.037542682926829329, -0.037393800813008179,
      -0.037393800813008179, -0.037243902439024451, -0.037243902439024451,
      -0.037092987804878123, -0.037092987804878123, -0.036941056910569169,
      -0.036941056910569169, -0.036788109756097608, -0.036788109756097608,
      -0.036634146341463475, -0.036634146341463475, -0.03647916666666675,
      -0.03647916666666675, -0.036323170731707377, -0.036323170731707377,
      -0.036166158536585405, -0.036166158536585405, -0.036008130081300875,
      -0.036008130081300875, -0.035849085365853739, -0.035849085365853739,
      -0.035689024390243962, -0.035689024390243962, -0.035527947154471592,
      -0.035527947154471592, -0.035365853658536645, -0.035365853658536645,
      -0.035202743902439104, -0.035202743902439104, -0.035038617886178923,
      -0.035038617886178923, -0.034873475609756177, -0.034873475609756177,
      -0.03470731707317079, -0.03470731707317079, -0.034540142276422846,
      -0.034540142276422846, -0.034371951219512253, -0.034371951219512253,
      -0.0342027439024391, -0.0342027439024391, -0.034032520325203312,
      -0.034032520325203312, -0.033861280487804957, -0.033861280487804957,
      -0.03368902439024396, -0.03368902439024396, -0.033515752032520406,
      -0.033515752032520406, -0.033341463414634204, -0.033341463414634204,
      -0.033166158536585444, -0.033166158536585444, -0.032989837398374043,
      -0.032989837398374043, -0.032812500000000078, -0.032812500000000078,
      -0.032634146341463471, -0.032634146341463471, -0.032454776422764307,
      -0.032454776422764307, -0.032274390243902495, -0.032274390243902495,
      -0.032092987804878126, -0.032092987804878126, -0.031910569105691122,
      -0.031910569105691122, -0.03172713414634154, -0.03172713414634154,
      -0.031542682926829324, -0.031542682926829324, -0.03135721544715455,
      -0.03135721544715455, -0.031170731707317129, -0.031170731707317129,
      -0.030983231707317149, -0.030983231707317149, -0.030794715447154532,
      -0.030794715447154532, -0.030605182926829344, -0.030605182926829344,
      -0.030414634146341518, -0.030414634146341518, -0.030223069105691138,
      -0.030223069105691138, -0.030030487804878103, -0.030030487804878103,
      -0.029836890243902514, -0.029836890243902514, -0.029642276422764288,
      -0.029642276422764288, -0.029446646341463493, -0.029446646341463493,
      -0.029250000000000054, -0.029250000000000054, -0.029052337398374064,
      -0.029052337398374064, -0.028853658536585423, -0.028853658536585423,
      -0.02865396341463422, -0.02865396341463422, -0.028453252032520384,
      -0.028453252032520384, -0.02825152439024398, -0.02825152439024398,
      -0.028048780487804931, -0.028048780487804931, -0.027845020325203335,
      -0.027845020325203335, -0.02764024390243908, -0.02764024390243908,
      -0.027434451219512268, -0.027434451219512268, -0.027227642276422822,
      -0.027227642276422822, -0.027019817073170811, -0.027019817073170811,
      -0.026810975609756149, -0.026810975609756149, -0.026601117886178943,
      -0.026601117886178943, -0.026390243902439079, -0.026390243902439079,
      -0.026178353658536657, -0.026178353658536657, -0.0259654471544716,
      -0.0259654471544716, -0.025751524390243981, -0.025751524390243981,
      -0.025536585365853709, -0.025536585365853709, -0.025320630081300893,
      -0.025320630081300893, -0.025103658536585419, -0.025103658536585419,
      -0.024885670731707391, -0.024885670731707391, -0.024666666666666722,
      -0.024666666666666722, -0.024446646341463492, -0.024446646341463492,
      -0.02422560975609761, -0.02422560975609761, -0.024003556910569185,
      -0.024003556910569185, -0.023780487804878098, -0.023780487804878098,
      -0.023557418699187066, -0.023557418699187066, -0.023335365853658585,
      -0.023335365853658585, -0.023114329268292755, -0.023114329268292755,
      -0.02289430894308948, -0.02289430894308948, -0.022675304878048853,
      -0.022675304878048853, -0.022457317073170779, -0.022457317073170779,
      -0.022240345528455358, -0.022240345528455358, -0.022024390243902486,
      -0.022024390243902486, -0.021809451219512267, -0.021809451219512267,
      -0.0215955284552846, -0.0215955284552846, -0.021382621951219583,
      -0.021382621951219583, -0.02117073170731712, -0.02117073170731712,
      -0.020959857723577304, -0.020959857723577304, -0.020750000000000046,
      -0.020750000000000046, -0.020541158536585436, -0.020541158536585436,
      -0.02033333333333338, -0.02033333333333338, -0.020126524390243969,
      -0.020126524390243969, -0.019920731707317119, -0.019920731707317119,
      -0.019715955284552913, -0.019715955284552913, -0.019512195121951265,
      -0.019512195121951265, -0.019309451219512261, -0.019309451219512261,
      -0.019107723577235818, -0.019107723577235818, -0.018907012195122017,
      -0.018907012195122017, -0.018707317073170776, -0.018707317073170776,
      -0.01850863821138218, -0.01850863821138218, -0.018310975609756142,
      -0.018310975609756142, -0.018114329268292748, -0.018114329268292748,
      -0.017918699186991915, -0.017918699186991915, -0.017724085365853723,
      -0.017724085365853723, -0.017530487804878092, -0.017530487804878092,
      -0.017337906504065106, -0.017337906504065106, -0.017146341463414677,
      -0.017146341463414677, -0.016955792682926893, -0.016955792682926893,
      -0.01676626016260167, -0.01676626016260167, -0.016577743902439088,
      -0.016577743902439088, -0.016390243902439067, -0.016390243902439067,
      -0.01620376016260169, -0.01620376016260169, -0.016018292682926913,
      -0.016018292682926913, -0.015833841463414697, -0.015833841463414697,
      -0.01565040650406508, -0.01565040650406508, -0.015467987804878109,
      -0.015467987804878109, -0.01528658536585374, -0.01528658536585374,
      -0.015106199186991931, -0.015106199186991931, -0.014926829268292724,
      -0.014926829268292724, -0.014748475609756157, -0.014748475609756157,
      -0.014571138211382194, -0.014571138211382194, -0.014394817073170791,
      -0.014394817073170791, -0.014219512195121992, -0.014219512195121992,
      -0.014045223577235833, -0.014045223577235833, -0.013871951219512273,
      -0.013871951219512273, -0.013699695121951279, -0.013699695121951279,
      -0.013528455284552886, -0.013528455284552886, -0.013358231707317132,
      -0.013358231707317132, -0.01318902439024398, -0.01318902439024398,
      -0.013020833333333391, -0.013020833333333391, -0.012853658536585405,
      -0.012853658536585405, -0.012687500000000058, -0.012687500000000058,
      -0.012522357723577312, -0.012522357723577312, -0.012358231707317129,
      -0.012358231707317129, -0.012195121951219551, -0.012195121951219551,
      -0.01203302845528461, -0.01203302845528461, -0.011871951219512268,
      -0.011871951219512268, -0.011711890243902495, -0.011711890243902495,
      -0.011552845528455358, -0.011552845528455358, -0.011394817073170787,
      -0.011394817073170787, -0.011237804878048853, -0.011237804878048853,
      -0.011081808943089487, -0.011081808943089487, -0.010926829268292755,
      -0.010926829268292755, -0.010772865853658591, -0.010772865853658591,
      -0.010619918699187065, -0.010619918699187065, -0.010467987804878103,
      -0.010467987804878103, -0.010317073170731779, -0.010317073170731779,
      -0.010167174796748023, -0.010167174796748023, -0.010018292682926899,
      -0.010018292682926899, -0.0098704268292683466, -0.0098704268292683466,
      -0.0097235772357724282, -0.0097235772357724282, -0.0095777439024390763,
      -0.0095777439024390763, -0.0094329268292683618, -0.0094329268292683618,
      -0.0092891260162602171, -0.0092891260162602171, -0.0091463414634147013,
      -0.0091463414634147013, -0.00900457317073176, -0.00900457317073176,
      -0.00886382113821145, -0.00886382113821145, -0.00872408536585371,
      -0.00872408536585371, -0.0085853658536586049, -0.0085853658536586049,
      -0.0084476626016260683, -0.0084476626016260683, -0.0083109756097561639,
      -0.0083109756097561639, -0.0081753048780488329, -0.0081753048780488329,
      -0.0080406504065041323, -0.0080406504065041323, -0.007907012195122,
      -0.007907012195122, -0.0077743902439025049, -0.0077743902439025049,
      -0.0076427845528455815, -0.0076427845528455815, -0.0075121951219512852,
      -0.0075121951219512852, -0.0073826219512195639, -0.0073826219512195639,
      -0.0072540650406504731, -0.0072540650406504731, -0.00712652439024395,
      -0.00712652439024395, -0.0070000000000000652, -0.0070000000000000652,
      -0.0068744918699187516, -0.0068744918699187516, -0.0067500000000000615,
      -0.0067500000000000615, -0.0066265243902439534, -0.0066265243902439534,
      -0.0065040650406504689, -0.0065040650406504689, -0.0063826219512195595,
      -0.0063826219512195595, -0.0062621951219512806, -0.0062621951219512806,
      -0.0061427845528455767, -0.0061427845528455767, -0.0060243902439025,
      -0.0060243902439025, -0.0059070121951220016, -0.0059070121951220016,
      -0.0057906504065041269, -0.0057906504065041269, -0.0056753048780488272,
      -0.0056753048780488272, -0.005560975609756158, -0.005560975609756158,
      -0.0054476626016260639, -0.0054476626016260639, -0.0053353658536585968,
      -0.0053353658536585968, -0.0052240853658537048, -0.0052240853658537048,
      -0.0051138211382114433, -0.0051138211382114433, -0.0050045731707317534,
      -0.0050045731707317534, -0.004896341463414694, -0.004896341463414694,
      -0.00478912601626021, -0.00478912601626021, -0.0046829268292683524,
      -0.0046829268292683524, -0.00457774390243907, -0.00457774390243907,
      -0.0044735772357724184, -0.0044735772357724184, -0.0043704268292683382,
      -0.0043704268292683382, -0.0042682926829268886, -0.0042682926829268886,
      -0.004167174796748014, -0.004167174796748014, -0.004067073170731763,
      -0.004067073170731763, -0.0039679878048780939, -0.0039679878048780939,
      -0.0038699186991870485, -0.0038699186991870485, -0.0037728658536585816,
      -0.0037728658536585816, -0.0036768292682927382, -0.0036768292682927382,
      -0.0035818089430894769, -0.0035818089430894769, -0.0034878048780488356,
      -0.0034878048780488356, -0.0033948170731707764, -0.0033948170731707764,
      -0.0033028455284553407, -0.0033028455284553407, -0.0032118902439024835,
      -0.0032118902439024835, -0.00312195121951225, -0.00312195121951225,
      -0.0030330284552845983, -0.0030330284552845983, -0.0029451219512195669,
      -0.0029451219512195669, -0.0028582317073171173, -0.0028582317073171173,
      -0.0027723577235772914, -0.0027723577235772914, -0.002687500000000044,
      -0.002687500000000044, -0.00260365853658542, -0.00260365853658542,
      -0.0025208333333333784, -0.0025208333333333784, -0.0024390243902439566,
      -0.0024390243902439566, -0.0023582317073171169, -0.0023582317073171169,
      -0.0022784552845529008, -0.0022784552845529008, -0.0021996951219512631,
      -0.0021996951219512631, -0.002121951219512249, -0.002121951219512249,
      -0.002045223577235817, -0.002045223577235817, -0.0019695121951220015,
      -0.0019695121951220015, -0.001894817073170775, -0.001894817073170775,
      -0.0018211382113821686, -0.0018211382113821686, -0.0017484756097561407,
      -0.0017484756097561407, -0.0016768292682927365, -0.0016768292682927365,
      -0.0016061991869919141, -0.0016061991869919141, -0.0015365853658537085,
      -0.0015365853658537085, -0.0014679878048780917, -0.0014679878048780917,
      -0.0014004065040650951, -0.0014004065040650951, -0.001333841463414677,
      -0.001333841463414677, -0.001268292682926879, -0.001268292682926879,
      -0.0012037601626016699, -0.0012037601626016699, -0.001140243902439074,
      -0.001140243902439074, -0.001077743902439067, -0.001077743902439067,
      -0.0010162601626016766, -0.0010162601626016766, -0.00095579268292687175,
      -0.00095579268292687175, -0.00089634146341468351, -0.00089634146341468351,
      -0.00083790650406508418, -0.00083790650406508418, -0.000780487804878098,
      -0.000780487804878098, -0.00072408536585370081, -0.00072408536585370081,
      -0.00066869918699192024, -0.00066869918699192024, -0.00061432926829272511,
      -0.00061432926829272511, -0.00056097560975614663, -0.00056097560975614663,
      -0.00050863821138215706, -0.00050863821138215706, -0.00045731707317078069,
      -0.00045731707317078069, -0.00040701219512199321, -0.00040701219512199321,
      -0.0003577235772358224, -0.0003577235772358224, -0.00030945121951223703,
      -0.00030945121951223703, -0.00026219512195126832, -0.00026219512195126832,
      -0.00021595528455288851, -0.00021595528455288851, -0.00017073170731711843,
      -0.00017073170731711843, -0.00012652439024394418, -0.00012652439024394418,
      -8.3333333333383136E-5, -8.3333333333383136E-5, -4.1158536585407524E-5,
      -4.1158536585407524E-5, -4.85722573273506E-17, -4.85722573273506E-17,
      -4.85722573273506E-17 } ;

    CPS_Eva_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    CPS_Eva_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    CPS_Eva_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */

  /* no initial value should be set */

  /* Start for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */

  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  CPS_Eva_DW.UnitDelay_DSTATE = CPS_Eva_P.start_position_cm * CPS_Eva_P.k /
    100.0;

  /* InitializeConditions for StateSpace: '<Root>/Analog Filter Design' */
  CPS_Eva_X.AnalogFilterDesign_CSTATE[0] =
    CPS_Eva_P.AnalogFilterDesign_InitialCondition;
  CPS_Eva_X.AnalogFilterDesign_CSTATE[1] =
    CPS_Eva_P.AnalogFilterDesign_InitialCondition;
  CPS_Eva_X.AnalogFilterDesign_CSTATE[2] =
    CPS_Eva_P.AnalogFilterDesign_InitialCondition;
  CPS_Eva_X.AnalogFilterDesign_CSTATE[3] =
    CPS_Eva_P.AnalogFilterDesign_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  CPS_Eva_DW.DiscreteTimeIntegrator_DSTATE = CPS_Eva_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  CPS_Eva_DW.DiscreteTimeIntegrator1_DSTATE = CPS_Eva_P.start_position_cm /
    100.0;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = CPS_Eva_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &CPS_Eva_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* Enable for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  CPS_Eva_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE = 1U;
}

/* Model terminate function */
void CPS_Eva_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */

  /* no final value should be set */

  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  CPS_Eva_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CPS_Eva_update();
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
  CPS_Eva_initialize();
}

void MdlTerminate(void)
{
  CPS_Eva_terminate();
}

/* Registration function */
RT_MODEL_CPS_Eva_T *CPS_Eva(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  CPS_Eva_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)CPS_Eva_M, 0,
                sizeof(RT_MODEL_CPS_Eva_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CPS_Eva_M->solverInfo, &CPS_Eva_M->Timing.simTimeStep);
    rtsiSetTPtr(&CPS_Eva_M->solverInfo, &rtmGetTPtr(CPS_Eva_M));
    rtsiSetStepSizePtr(&CPS_Eva_M->solverInfo, &CPS_Eva_M->Timing.stepSize0);
    rtsiSetdXPtr(&CPS_Eva_M->solverInfo, &CPS_Eva_M->derivs);
    rtsiSetContStatesPtr(&CPS_Eva_M->solverInfo, (real_T **)
                         &CPS_Eva_M->contStates);
    rtsiSetNumContStatesPtr(&CPS_Eva_M->solverInfo,
      &CPS_Eva_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CPS_Eva_M->solverInfo,
      &CPS_Eva_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CPS_Eva_M->solverInfo,
      &CPS_Eva_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CPS_Eva_M->solverInfo,
      &CPS_Eva_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&CPS_Eva_M->solverInfo, (&rtmGetErrorStatus(CPS_Eva_M)));
    rtsiSetRTModelPtr(&CPS_Eva_M->solverInfo, CPS_Eva_M);
  }

  rtsiSetSimTimeStep(&CPS_Eva_M->solverInfo, MAJOR_TIME_STEP);
  CPS_Eva_M->intgData.y = CPS_Eva_M->odeY;
  CPS_Eva_M->intgData.f[0] = CPS_Eva_M->odeF[0];
  CPS_Eva_M->intgData.f[1] = CPS_Eva_M->odeF[1];
  CPS_Eva_M->intgData.f[2] = CPS_Eva_M->odeF[2];
  CPS_Eva_M->intgData.f[3] = CPS_Eva_M->odeF[3];
  CPS_Eva_M->intgData.f[4] = CPS_Eva_M->odeF[4];
  CPS_Eva_M->intgData.f[5] = CPS_Eva_M->odeF[5];
  CPS_Eva_M->contStates = ((real_T *) &CPS_Eva_X);
  rtsiSetSolverData(&CPS_Eva_M->solverInfo, (void *)&CPS_Eva_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&CPS_Eva_M->solverInfo, false);
  rtsiSetSolverName(&CPS_Eva_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CPS_Eva_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "CPS_Eva_M points to
       static memory which is guaranteed to be non-NULL" */
    CPS_Eva_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CPS_Eva_M->Timing.sampleTimes = (&CPS_Eva_M->Timing.sampleTimesArray[0]);
    CPS_Eva_M->Timing.offsetTimes = (&CPS_Eva_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CPS_Eva_M->Timing.sampleTimes[0] = (0.0);
    CPS_Eva_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    CPS_Eva_M->Timing.offsetTimes[0] = (0.0);
    CPS_Eva_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(CPS_Eva_M, &CPS_Eva_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CPS_Eva_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    CPS_Eva_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CPS_Eva_M, 10.0);
  CPS_Eva_M->Timing.stepSize0 = 0.001;
  CPS_Eva_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  CPS_Eva_M->Sizes.checksums[0] = (1543919336U);
  CPS_Eva_M->Sizes.checksums[1] = (3857435886U);
  CPS_Eva_M->Sizes.checksums[2] = (3412776513U);
  CPS_Eva_M->Sizes.checksums[3] = (1096289326U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    CPS_Eva_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CPS_Eva_M->extModeInfo,
      &CPS_Eva_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CPS_Eva_M->extModeInfo, CPS_Eva_M->Sizes.checksums);
    rteiSetTPtr(CPS_Eva_M->extModeInfo, rtmGetTPtr(CPS_Eva_M));
  }

  CPS_Eva_M->solverInfoPtr = (&CPS_Eva_M->solverInfo);
  CPS_Eva_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CPS_Eva_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CPS_Eva_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CPS_Eva_M->blockIO = ((void *) &CPS_Eva_B);
  (void) memset(((void *) &CPS_Eva_B), 0,
                sizeof(B_CPS_Eva_T));

  /* parameters */
  CPS_Eva_M->defaultParam = ((real_T *)&CPS_Eva_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &CPS_Eva_X;
    CPS_Eva_M->contStates = (x);
    (void) memset((void *)&CPS_Eva_X, 0,
                  sizeof(X_CPS_Eva_T));
  }

  /* states (dwork) */
  CPS_Eva_M->dwork = ((void *) &CPS_Eva_DW);
  (void) memset((void *)&CPS_Eva_DW, 0,
                sizeof(DW_CPS_Eva_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    CPS_Eva_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  CPS_Eva_M->Sizes.numContStates = (4);/* Number of continuous states */
  CPS_Eva_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  CPS_Eva_M->Sizes.numY = (0);         /* Number of model outputs */
  CPS_Eva_M->Sizes.numU = (0);         /* Number of model inputs */
  CPS_Eva_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CPS_Eva_M->Sizes.numSampTimes = (2); /* Number of sample times */
  CPS_Eva_M->Sizes.numBlocks = (51);   /* Number of blocks */
  CPS_Eva_M->Sizes.numBlockIO = (16);  /* Number of block outputs */
  CPS_Eva_M->Sizes.numBlockPrms = (144);/* Sum of parameter "widths" */
  return CPS_Eva_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
