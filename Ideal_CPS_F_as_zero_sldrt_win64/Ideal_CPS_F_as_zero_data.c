/*
 * Ideal_CPS_F_as_zero_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ideal_CPS_F_as_zero".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb 24 16:08:20 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ideal_CPS_F_as_zero.h"

/* Block parameters (default storage) */
P_Ideal_CPS_F_as_zero_T Ideal_CPS_F_as_zero_P = {
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

  /* Variable: start_position_cm
   * Referenced by:
   *   '<Root>/Discrete-Time Integrator1'
   *   '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
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

  /* Expression: 100
   * Referenced by: '<Root>/Gain7'
   */
  100.0
};
