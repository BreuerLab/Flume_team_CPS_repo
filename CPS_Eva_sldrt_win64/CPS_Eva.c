/*
 * CPS_Eva.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_Eva".
 *
 * Model version              : 1.27
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb 24 16:36:40 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CPS_Eva.h"
#include "rtwtypes.h"
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
  real_T rtb_AnalogInput[10];
  real_T rtb_AnalogInput_0[6];
  real_T rtb_AnalogInput2;
  real_T rtb_EncoderInput;
  real_T rtb_Saturation2;
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
  CPS_Eva_B.Fy_plus_ma_filtered = 0.0;

  /* StateSpace: '<Root>/Analog Filter Design' */
  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[0U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[1U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.Fy_plus_ma_filtered += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[0U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[1U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[2U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.Fy_plus_ma_filtered += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[1U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[2U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[3U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.Fy_plus_ma_filtered += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[2U];
  }

  for (ri = CPS_Eva_P.AnalogFilterDesign_C_jc[3U]; ri <
       CPS_Eva_P.AnalogFilterDesign_C_jc[4U]; ri++) {
    /* StateSpace: '<Root>/Analog Filter Design' */
    CPS_Eva_B.Fy_plus_ma_filtered += CPS_Eva_P.AnalogFilterDesign_C_pr *
      CPS_Eva_X.AnalogFilterDesign_CSTATE[3U];
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_Saturation2 = 1.0 / CPS_Eva_P.M * (CPS_Eva_B.Fy_plus_ma_filtered -
    CPS_Eva_B.UnitDelay);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation2 > CPS_Eva_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = CPS_Eva_P.Saturation_UpperSat;
  } else if (rtb_Saturation2 < CPS_Eva_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = CPS_Eva_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    CPS_Eva_B.Saturation = rtb_Saturation2;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(CPS_Eva_M)) {
    real_T rtb_CPSorReference;

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
      rtb_Saturation2 = CPS_Eva_P.Saturation2_UpperSat;
    } else if (CPS_Eva_B.DiscreteTimeIntegrator1 <
               CPS_Eva_P.Saturation2_LowerSat) {
      rtb_Saturation2 = CPS_Eva_P.Saturation2_LowerSat;
    } else {
      rtb_Saturation2 = CPS_Eva_B.DiscreteTimeIntegrator1;
    }

    /* End of Saturate: '<Root>/Saturation2' */

    /* ManualSwitch: '<Root>/CPS or Reference' incorporates:
     *  ManualSwitch: '<Root>/Signal or zero'
     */
    if (CPS_Eva_P.CPSorReference_CurrentSetting == 1) {
      rtb_CPSorReference = rtb_Saturation2;
    } else if (CPS_Eva_P.Signalorzero_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Signal or zero' incorporates:
       *  ManualSwitch: '<Root>/Sine or custom trajectory'
       */
      rtb_CPSorReference = 0.0;
    } else {
      /* ManualSwitch: '<Root>/Signal or zero' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_CPSorReference = CPS_Eva_P.Constant3_Value;
    }

    /* End of ManualSwitch: '<Root>/CPS or Reference' */

    /* Gain: '<Root>/Gain6' */
    rtb_EncoderInput = CPS_Eva_P.Gain6_Gain * rtb_CPSorReference;

    /* ManualSwitch: '<Root>/zero pitch or constant' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Constant: '<Root>/Constant4'
     *  Gain: '<Root>/Gain9'
     */
    if (CPS_Eva_P.zeropitchorconstant_CurrentSetting == 1) {
      rtb_AnalogInput2 = CPS_Eva_P.Constant3_Value;
    } else {
      rtb_AnalogInput2 = CPS_Eva_P.Gain9_Gain * CPS_Eva_P.Constant4_Value;
    }

    /* End of ManualSwitch: '<Root>/zero pitch or constant' */

    /* Gain: '<Root>/Gain10' */
    rtb_AnalogInput2 *= CPS_Eva_P.Gain10_Gain;

    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) CPS_Eva_P.AnalogOutput_RangeMode;
        parm.rangeidx = CPS_Eva_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &CPS_Eva_P.AnalogOutput_Channels, ((real_T*)
          (&rtb_EncoderInput)), &parm);
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
          (&rtb_AnalogInput2)), &parm);
      }
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) CPS_Eva_P.AnalogInput_RangeMode;
      parm.rangeidx = CPS_Eva_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(1, ANALOGINPUT, IOREAD, 10, CPS_Eva_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input2' */
    /* S-Function Block: <Root>/Analog Input2 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) CPS_Eva_P.AnalogInput2_RangeMode;
      parm.rangeidx = CPS_Eva_P.AnalogInput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &CPS_Eva_P.AnalogInput2_Channels,
                     &rtb_AnalogInput2, &parm);
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
      __m128d tmp;

      /* Bias: '<Root>/Bias' */
      tmp = _mm_loadu_pd(&rtb_AnalogInput[i]);
      _mm_storeu_pd(&rtb_AnalogInput_0[i], _mm_add_pd(tmp, _mm_loadu_pd
        (&CPS_Eva_P.Bias_Bias[i])));
    }

    for (i = 0; i < 6; i++) {
      /* Gain: '<Root>/Gain' */
      CPS_Eva_B.Gain[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        CPS_Eva_B.Gain[i] += CPS_Eva_P.Gromit_Cal_tranp[6 * i + i_0] *
          rtb_AnalogInput_0[i_0];
      }

      /* End of Gain: '<Root>/Gain' */
    }

    /* Gain: '<Root>/Gain5' */
    CPS_Eva_B.Fy = CPS_Eva_P.Gain5_Gain * CPS_Eva_B.Gain[1];

    /* Gain: '<Root>/Gain2' incorporates:
     *  Bias: '<Root>/Bias1'
     *  Gain: '<Root>/Gain1'
     */
    CPS_Eva_B.ma = (rtb_AnalogInput2 + CPS_Eva_P.Bias1_Bias) *
      CPS_Eva_P.Gain1_Gain * CPS_Eva_P.Gain2_Gain;

    /* Constant: '<Root>/Constant' */
    CPS_Eva_B.Constant = CPS_Eva_P.Constant_Value;

    /* Gain: '<Root>/Gain7' */
    CPS_Eva_B.CommandedPosition = CPS_Eva_P.Gain7_Gain * rtb_CPSorReference;

    /* Bias: '<Root>/Bias3' incorporates:
     *  Gain: '<Root>/Gain8'
     */
    CPS_Eva_B.MeasuredPosition = CPS_Eva_P.Gain8_Gain * rtb_EncoderInput +
      CPS_Eva_P.start_position_cm;

    /* Gain: '<Root>/Gain11' */
    CPS_Eva_B.torque_z = CPS_Eva_P.Gain11_Gain * CPS_Eva_B.Gain[5];

    /* SignalConversion generated from: '<Root>/To Workspace1' */
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[0] = CPS_Eva_B.Fy;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[1] = CPS_Eva_B.Gain[0];
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[2] = CPS_Eva_B.ma;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[3] =
      CPS_Eva_B.Fy_plus_ma_filtered;
    CPS_Eva_B.TmpSignalConversionAtToWorkspace1Inport1[4] = CPS_Eva_B.torque_z;

    /* Gain: '<Root>/Gain4' incorporates:
     *  Bias: '<Root>/Bias2'
     */
    CPS_Eva_B.Gain4[0] = (rtb_AnalogInput[6] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[1] = (rtb_AnalogInput[7] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[2] = (rtb_AnalogInput[8] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;
    CPS_Eva_B.Gain4[3] = (rtb_AnalogInput[9] + CPS_Eva_P.Bias2_Bias) *
      CPS_Eva_P.Gain4_Gain;

    /* Sum: '<Root>/Add' */
    CPS_Eva_B.Add = CPS_Eva_B.Fy + CPS_Eva_B.ma;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product1'
     */
    CPS_Eva_B.Sum1 = CPS_Eva_P.k * rtb_Saturation2 + CPS_Eva_P.c *
      CPS_Eva_B.Saturation1;
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
      CPS_Eva_P.AnalogFilterDesign_B_pr * CPS_Eva_B.Add;
  }

  /* End of Derivatives for StateSpace: '<Root>/Analog Filter Design' */
}

/* Model initialize function */
void CPS_Eva_initialize(void)
{
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
  CPS_Eva_M->Sizes.checksums[0] = (3237297469U);
  CPS_Eva_M->Sizes.checksums[1] = (4223103760U);
  CPS_Eva_M->Sizes.checksums[2] = (2513661975U);
  CPS_Eva_M->Sizes.checksums[3] = (2261803999U);

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
  CPS_Eva_M->Sizes.numBlocks = (52);   /* Number of blocks */
  CPS_Eva_M->Sizes.numBlockIO = (17);  /* Number of block outputs */
  CPS_Eva_M->Sizes.numBlockPrms = (138);/* Sum of parameter "widths" */
  return CPS_Eva_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
