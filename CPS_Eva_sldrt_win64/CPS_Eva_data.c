/*
 * CPS_Eva_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_Eva".
 *
 * Model version              : 1.34
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sun Mar  5 21:46:33 2023
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
  { -0.02196001634, 0.004190267995, -0.186118155718, -17.483510971069,
    1.224225640297, 16.644166946411, 0.965337395668, 19.793544769287,
    -0.233169600368, -10.133704185486, -0.765193104744, -9.669131278992,
    29.811275482178, 0.075847007334, 30.349569320679, 0.450678527355,
    29.886123657227, 0.42908602953, 0.018749127164, 0.455327808857,
    -1.043430089951, -0.245171427727, 1.023705482483, -0.20924256742,
    1.182301402092, -0.00139987655, -0.586799740791, 0.394854426384,
    -0.641057908535, -0.38928997516, -0.028681563213, -0.63898229599,
    -0.011541210115, -0.659547865391, -0.044132679701, -0.627585828304 },

  /* Variable: M
   * Referenced by: '<Root>/Gain3'
   */
  7.0,

  /* Variable: c
   * Referenced by: '<Root>/Constant1'
   */
  2.1991148575128552,

  /* Variable: k
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<Root>/Unit Delay'
   */
  69.0872308076255,

  /* Variable: start_position_cm
   * Referenced by:
   *   '<Root>/Bias3'
   *   '<Root>/Discrete-Time Integrator1'
   *   '<Root>/Unit Delay'
   */
  4.9463325000000005,

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
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },

  /* Mask Parameter: AnalogInput2_Channels
   * Referenced by: '<Root>/Analog Input2'
   */
  24,

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

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0005,

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
  { -0.025034403783908275, -0.36925366483936445, 0.34875933901429484,
    -0.89025216839758192, -0.28899229762062351, 0.23183906276259175 },

  /* Expression: -1
   * Referenced by: '<Root>/Gain5'
   */
  -1.0,

  /* Expression: -tare.signals.values(end,7)
   * Referenced by: '<Root>/Bias1'
   */
  -1.6735710779694031,

  /* Expression: 9.81
   * Referenced by: '<Root>/Gain1'
   */
  9.81,

  /* Expression: 0.6+0.302
   * Referenced by: '<Root>/Gain2'
   */
  0.90199999999999991,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain7'
   */
  100.0,

  /* Expression: 1*(1/(4*2000))*2.54
   * Referenced by: '<Root>/Gain8'
   */
  0.0003175,

  /* Expression: -1
   * Referenced by: '<Root>/Gain11'
   */
  -1.0,

  /* Expression: 2.5
   * Referenced by: '<Root>/Bias2'
   */
  2.5,

  /* Expression: 0.4
   * Referenced by: '<Root>/Gain4'
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
  1U,

  /* Computed Parameter: zeropitchorconstant_CurrentSetting
   * Referenced by: '<Root>/zero pitch or constant'
   */
  1U
};
