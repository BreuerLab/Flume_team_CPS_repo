/*
 * CPS_Eva_data.c
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

/* Block parameters (default storage) */
P_CPS_Eva_T CPS_Eva_P = {
  /* Variable: Gromit_Cal_tranp
   * Referenced by: '<Root>/Gain'
   */
  { -0.14949, 0.21629, -0.44045, -69.17754, 5.14209, 66.58631, 3.76511, 79.12451,
    -0.93703, -39.93894, -3.18235, -38.82968, 119.69008, 0.20742, 121.4034,
    1.86132, 119.48767, 1.72429, 0.07852, 1.83351, -4.16898, -0.97465, 4.0923,
    -0.84436, 4.74524, -0.0018, -2.34562, 1.56487, -2.56572, -1.56743, -0.11223,
    -2.5581, -0.04961, -2.57527, -0.18672, -2.5188 },

  /* Variable: M
   * Referenced by: '<Root>/Gain3'
   */
  10.0,

  /* Variable: c
   * Referenced by: '<Root>/Constant1'
   */
  12.566370614359174,

  /* Variable: k
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<Root>/Unit Delay'
   */
  394.78417604357435,

  /* Variable: mass_of_cylinder
   * Referenced by: '<Root>/Gain2'
   */
  0.306,

  /* Variable: start_position_cm
   * Referenced by:
   *   '<Root>/Bias3'
   *   '<Root>/Discrete-Time Integrator1'
   *   '<Root>/Unit Delay'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput2_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input2'
   */
  10.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput2_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  1,

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<Root>/Analog Output1'
   */
  2,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 0, 1, 2, 3, 4, 5 },

  /* Mask Parameter: AnalogInput2_Channels
   * Referenced by: '<Root>/Analog Input2'
   */
  24,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<Root>/Analog Input1'
   */
  { 6, 7, 8, 9 },

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput2_RangeMode
   * Referenced by: '<Root>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput2_VoltRange
   * Referenced by: '<Root>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Expression: 1/180*pi
   * Referenced by: '<Root>/Gain9'
   */
  0.017453292519943295,

  /* Computed Parameter: AnalogFilterDesign_A_pr
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { -116.03926928341762, 62.800000000000004, -62.800000000000004,
    62.800000000000004, -48.06503910505527, 62.800000000000004,
    -62.800000000000004 },

  /* Computed Parameter: AnalogFilterDesign_B_pr
   * Referenced by: '<Root>/Analog Filter Design'
   */
  62.800000000000004,

  /* Computed Parameter: AnalogFilterDesign_C_pr
   * Referenced by: '<Root>/Analog Filter Design'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Analog Filter Design'
   */
  0.0,

  /* Expression: 3.5
   * Referenced by: '<Root>/Saturation'
   */
  3.5,

  /* Expression: -3.5
   * Referenced by: '<Root>/Saturation'
   */
  -3.5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Saturation1'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<Root>/Saturation1'
   */
  -0.5,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0005,

  /* Expression: 0.13
   * Referenced by: '<Root>/Saturation2'
   */
  0.13,

  /* Expression: -0.13
   * Referenced by: '<Root>/Saturation2'
   */
  -0.13,

  /* Expression: 0.05
   * Referenced by: '<Root>/Sine Wave'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2*3.14*1
   * Referenced by: '<Root>/Sine Wave'
   */
  6.28,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: -1/0.03
   * Referenced by: '<Root>/Gain6'
   */
  -33.333333333333336,

  /* Expression: 0.5
   * Referenced by: '<Root>/Constant4'
   */
  0.5,

  /* Expression: -5.*10/30000*12800/360*1.00*180/pi
   * Referenced by: '<Root>/Gain10'
   */
  -3.3953054526271012,

  /* Expression: -tare.signals.values(end,1:6)
   * Referenced by: '<Root>/Bias'
   */
  { -0.13440581576921984, -0.49988255529297776, 0.23643479852789648,
    -1.0090033593452041, -0.40437552831277918, 0.085773947807643178 },

  /* Expression: -1
   * Referenced by: '<Root>/Gain11'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain5'
   */
  -1.0,

  /* Expression: -tare.signals.values(end,7)
   * Referenced by: '<Root>/Bias1'
   */
  1.6355703180127437,

  /* Expression: -9.81
   * Referenced by: '<Root>/Gain1'
   */
  -9.81,

  /* Expression: 2.5
   * Referenced by: '<Root>/Bias2'
   */
  2.5,

  /* Expression: 0.4
   * Referenced by: '<Root>/Gain4'
   */
  0.4,

  /* Expression: 1*(1/(4*2000))*2.54
   * Referenced by: '<Root>/Gain8'
   */
  0.0003175,

  /* Computed Parameter: AnalogFilterDesign_A_ir
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { 0U, 1U, 0U, 2U, 2U, 3U, 2U },

  /* Computed Parameter: AnalogFilterDesign_A_jc
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { 0U, 2U, 4U, 6U, 7U },

  /* Computed Parameter: AnalogFilterDesign_B_ir
   * Referenced by: '<Root>/Analog Filter Design'
   */
  0U,

  /* Computed Parameter: AnalogFilterDesign_B_jc
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { 0U, 1U },

  /* Computed Parameter: AnalogFilterDesign_C_ir
   * Referenced by: '<Root>/Analog Filter Design'
   */
  0U,

  /* Computed Parameter: AnalogFilterDesign_C_jc
   * Referenced by: '<Root>/Analog Filter Design'
   */
  { 0U, 0U, 0U, 0U, 1U },

  /* Computed Parameter: Sineorcustomtrajectory_CurrentSetting
   * Referenced by: '<Root>/Sine or custom trajectory'
   */
  0U,

  /* Computed Parameter: Signalorzero_CurrentSetting
   * Referenced by: '<Root>/Signal or zero'
   */
  0U,

  /* Computed Parameter: CPSorReference_CurrentSetting
   * Referenced by: '<Root>/CPS or Reference'
   */
  0U,

  /* Computed Parameter: zeropitchorconstant_CurrentSetting
   * Referenced by: '<Root>/zero pitch or constant'
   */
  1U
};
