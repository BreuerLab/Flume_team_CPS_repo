/*
 * CPS_heave_noAccelmeter_20221201_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_heave_noAccelmeter_20221201".
 *
 * Model version              : 12.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jan 20 16:37:45 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CPS_heave_noAccelmeter_20221201.h"

/* Block parameters (default storage) */
P_CPS_heave_noAccelmeter_20221201_T CPS_heave_noAccelmeter_20221201_P = {
  /* Variable: M
   * Referenced by:
   *   '<Root>/inverse  mass (1//kg) '
   *   '<Root>/Unit  Delay'
   */
  10.0,

  /* Variable: Wallace_Cal_tranp
   * Referenced by: '<Root>/conversion  matrix'
   */
  { -0.02196001634, 0.004190267995, -0.186118155718, -17.483510971069,
    1.224225640297, 16.644166946411, 0.965337395668, 19.793544769287,
    -0.233169600368, -10.133704185486, -0.765193104744, -9.669131278992,
    29.811275482178, 0.075847007334, 30.349569320679, 0.450678527355,
    29.886123657227, 0.42908602953, 0.018749127164, 0.455327808857,
    -1.043430089951, -0.245171427727, 1.023705482483, -0.20924256742,
    1.182301402092, -0.00139987655, -0.586799740791, 0.394854426384,
    -0.641057908535, -0.38928997516, -0.028681563213, -0.63898229599,
    -0.011541210115, -0.659547865391, -0.044132679701, -0.627585828304 },

  /* Variable: c
   * Referenced by: '<Root>/Virtual damping (kg//s)'
   */
  12.566370614359174,

  /* Variable: input_heave_meters
   * Referenced by: '<Root>/Unit  Delay'
   */
  0.0,

  /* Variable: k
   * Referenced by:
   *   '<Root>/Virtual spring (N//m)'
   *   '<Root>/Unit  Delay'
   */
  394.78417604357435,

  /* Variable: start_position_meters
   * Referenced by:
   *   '<Root>/initial position'
   *   '<Root>/Integrator 2'
   */
  0.01,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput2_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output2'
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

  /* Mask Parameter: AnalogInput2_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input2'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output2'
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

  /* Mask Parameter: AnalogInput2_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<Root>/Analog Output1'
   */
  1,

  /* Mask Parameter: AnalogOutput2_Channels
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<Root>/Analog Input1'
   */
  { 0, 1, 2, 3, 4, 5, 22, 23, 24 },

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput2_Channels
   * Referenced by: '<Root>/Analog Input2'
   */
  { 6, 7, 8, 9 },

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_RangeMode
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_RangeMode
   * Referenced by: '<Root>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_VoltRange
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_VoltRange
   * Referenced by: '<Root>/Analog Input2'
   */
  0,

  /* Expression: 1/180*pi
   * Referenced by: '<Root>/to rad'
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

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<Root>/Integrator'
   */
  0.0005,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Computed Parameter: Integrator2_gainval
   * Referenced by: '<Root>/Integrator 2'
   */
  0.0005,

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
   * Referenced by: '<Root>/Zero'
   */
  0.0,

  /* Expression: 1/0.03
   * Referenced by: '<Root>/position out  m to V'
   */
  33.333333333333336,

  /* Expression: 0.5
   * Referenced by: '<Root>/offset(deg)'
   */
  0.5,

  /* Expression: -5.*10/30000*12800/360*1.00*180/pi
   * Referenced by: '<Root>/angle out deg1'
   */
  -3.3953054526271012,

  /* Expression: -tare.signals.values(end,1:6)
   * Referenced by: '<Root>/force bias'
   */
  { -0.13996043845563935, -0.052632095017874227, -0.23431397027923911,
    -0.39105580587974403, -0.35250661899364588, 0.27139356764953021 },

  /* Expression: -tare.signals.values(end,7)
   * Referenced by: '<Root>/accel bias (V)'
   */
  0.10128981589349095,

  /* Expression: -9.81
   * Referenced by: '<Root>/accel V to m//s2'
   */
  -9.81,

  /* Expression: 0.6+0.306
   * Referenced by: '<Root>/load mass'
   */
  0.90599999999999992,

  /* Expression: 0
   * Referenced by: '<Root>/Zero force'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/cm//m'
   */
  100.0,

  /* Expression: -1*(1/(4*2000))*2.54
   * Referenced by: '<Root>/counts to cm'
   */
  -0.0003175,

  /* Expression: -1/3.83
   * Referenced by: '<Root>/Pitch V to rad'
   */
  -0.2610966057441253,

  /* Expression: 0
   * Referenced by: '<Root>/Heave offset'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/virtual mass (kg)'
   */
  0.0,

  /* Expression: -2.5
   * Referenced by: '<Root>/Bias'
   */
  -2.5,

  /* Expression: 0.4
   * Referenced by: '<Root>/conversion1'
   */
  0.4,

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

  /* Computed Parameter: sineorcustomtraj_CurrentSetting
   * Referenced by: '<Root>/sine or custom traj.'
   */
  0U,

  /* Computed Parameter: signalorzero_CurrentSetting
   * Referenced by: '<Root>/signal or zero'
   */
  0U,

  /* Computed Parameter: CPSorreference_CurrentSetting
   * Referenced by: '<Root>/CPS or  reference'
   */
  1U,

  /* Computed Parameter: Pitchzeroorconstant_CurrentSetting
   * Referenced by: '<Root>/Pitch zero or constant'
   */
  1U
};
