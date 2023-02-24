/*
 * set_heave_Eva_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "set_heave_Eva".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb 24 14:16:59 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "set_heave_Eva.h"

/* Block parameters (default storage) */
P_set_heave_Eva_T set_heave_Eva_P = {
  /* Variable: start_position_cm
   * Referenced by:
   *   '<Root>/Bias'
   *   '<Root>/Bias3'
   *   '<Root>/Constant2'
   */
  -0.0047625000000000028,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
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

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  1,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: -1
   * Referenced by: '<Root>/Sine Wave1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 2*3.14*(1/(2*10))
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.31400000000000006,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.00031399999484014275,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.99999995070200043,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.99999995070200043,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.00031399999484012936,

  /* Expression: 5
   * Referenced by: '<Root>/Constant1'
   */
  5.0,

  /* Expression: -1/(2*3)
   * Referenced by: '<Root>/Gain1'
   */
  -0.16666666666666666,

  /* Expression: 1*(1/(4*2000))*2.54
   * Referenced by: '<Root>/Gain8'
   */
  0.0003175,

  /* Expression: -3
   * Referenced by: '<Root>/Gain7'
   */
  -3.0
};
