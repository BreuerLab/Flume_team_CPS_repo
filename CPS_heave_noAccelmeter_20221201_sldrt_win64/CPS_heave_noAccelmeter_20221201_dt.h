/*
 * CPS_heave_noAccelmeter_20221201_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CPS_heave_noAccelmeter_20221201".
 *
 * Model version              : 12.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Jan 25 15:46:41 2023
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
  { (char_T *)(&CPS_heave_noAccelmeter_20221201_B.Virtualdampingkgs), 0, 0, 33 }
  ,

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_DW.UnitDelay_DSTATE), 0, 0, 3 },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_DW._PWORK.LoggedData), 11, 0, 15
  },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_DW.FromWs_IWORK.PrevIndex), 10,
    0, 1 },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_DW.Integrator_SYSTEM_ENABLE), 3,
    0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&CPS_heave_noAccelmeter_20221201_P.M), 0, 0, 51 },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_P.AnalogOutput1_Channels), 6, 0,
    24 },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_P.torad_Gain), 0, 0, 39 },

  { (char_T *)(&CPS_heave_noAccelmeter_20221201_P.AnalogFilterDesign_A_ir[0]), 7,
    0, 21 },

  { (char_T *)
    (&CPS_heave_noAccelmeter_20221201_P.sineorcustomtraj_CurrentSetting), 3, 0,
    4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] CPS_heave_noAccelmeter_20221201_dt.h */