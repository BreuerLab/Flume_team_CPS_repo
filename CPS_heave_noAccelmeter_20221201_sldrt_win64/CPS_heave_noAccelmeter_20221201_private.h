/*
 * CPS_heave_noAccelmeter_20221201_private.h
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

#ifndef RTW_HEADER_CPS_heave_noAccelmeter_20221201_private_h_
#define RTW_HEADER_CPS_heave_noAccelmeter_20221201_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "CPS_heave_noAccelmeter_20221201_types.h"

/* Used by FromWorkspace Block: '<S1>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* private model entry point functions */
extern void CPS_heave_noAccelmeter_20221201_derivatives(void);

#endif               /* RTW_HEADER_CPS_heave_noAccelmeter_20221201_private_h_ */
