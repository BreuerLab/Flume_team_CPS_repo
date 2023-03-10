/*
 * CPS_Eva_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_Eva".
 *
 * Model version              : 1.34
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Mar  7 09:54:22 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&CPS_Eva_B.UnitDelay), 0, 0, 28 }
  ,

  { (char_T *)(&CPS_Eva_DW.UnitDelay_DSTATE), 0, 0, 3 },

  { (char_T *)(&CPS_Eva_DW.AnalogOutput_PWORK), 11, 0, 11 },

  { (char_T *)(&CPS_Eva_DW.DiscreteTimeIntegrator1_SYSTEM_ENABLE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&CPS_Eva_P.Gromit_Cal_tranp[0]), 0, 0, 51 },

  { (char_T *)(&CPS_Eva_P.AnalogOutput_Channels), 6, 0, 22 },

  { (char_T *)(&CPS_Eva_P.Gain9_Gain), 0, 0, 34 },

  { (char_T *)(&CPS_Eva_P.AnalogFilterDesign_A_ir[0]), 7, 0, 21 },

  { (char_T *)(&CPS_Eva_P.Sineorcustomtrajectory_CurrentSetting), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] CPS_Eva_dt.h */
