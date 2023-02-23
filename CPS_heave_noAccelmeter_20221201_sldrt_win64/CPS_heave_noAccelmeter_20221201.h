/*
 * CPS_heave_noAccelmeter_20221201.h
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

#ifndef RTW_HEADER_CPS_heave_noAccelmeter_20221201_h_
#define RTW_HEADER_CPS_heave_noAccelmeter_20221201_h_
#ifndef CPS_heave_noAccelmeter_20221201_COMMON_INCLUDES_
#define CPS_heave_noAccelmeter_20221201_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                    /* CPS_heave_noAccelmeter_20221201_COMMON_INCLUDES_ */

#include "CPS_heave_noAccelmeter_20221201_types.h"
#include <math.h>
#include "rtGetInf.h"
#include <stddef.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define CPS_heave_noAccelmeter_20221201_rtModel RT_MODEL_CPS_heave_noAccelmeter_20221201_T

/* Block signals (default storage) */
typedef struct {
  real_T Virtualdampingkgs;            /* '<Root>/Virtual damping (kg//s)' */
  real_T VirtualspringNm;              /* '<Root>/Virtual spring (N//m)' */
  real_T LateralforcefilteredN;        /* '<Root>/Analog Filter Design' */
  real_T UnitDelay;                    /* '<Root>/Unit  Delay' */
  real_T inversemass1kg;               /* '<Root>/inverse  mass (1//kg) ' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Integrator2;                  /* '<Root>/Integrator 2' */
  real_T positionoutmtoV;              /* '<Root>/position out  m to V' */
  real_T Pitchzeroorconstant;          /* '<Root>/Pitch zero or constant' */
  real_T conversionmatrix[6];          /* '<Root>/conversion  matrix' */
  real_T InertialloadN;                /* '<Root>/load mass' */
  real_T TmpSignalConversionAtForcesInport1[5];
  real_T Zeroforce;                    /* '<Root>/Zero force' */
  real_T Prescribedheavecm;            /* '<Root>/cm//m' */
  real_T Encodermeasuredheavecm;       /* '<Root>/initial position' */
  real_T Pitchmeasuredrad;             /* '<Root>/Pitch V to rad' */
  real_T dampingspeed;                 /* '<Root>/damping*speed' */
  real_T stiffnessdisplacement;        /* '<Root>/stiffness*displacement' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T conversion1[4];               /* '<Root>/conversion1' */
} B_CPS_heave_noAccelmeter_20221201_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit  Delay' */
  real_T Integrator_DSTATE;            /* '<Root>/Integrator' */
  real_T Integrator2_DSTATE;           /* '<Root>/Integrator 2' */
  struct {
    void *LoggedData;
  } _PWORK;                            /* '<Root>/ ' */

  struct {
    void *LoggedData;
  } _PWORK_g;                          /* '<Root>/  ' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S1>/FromWs' */

  void *AnalogOutput1_PWORK;           /* '<Root>/Analog Output1' */
  void *AnalogOutput2_PWORK;           /* '<Root>/Analog Output2' */
  void *AnalogInput1_PWORK;            /* '<Root>/Analog Input1' */
  void *EncoderInput_PWORK;            /* '<Root>/Encoder Input' */
  void *AnalogInput2_PWORK;            /* '<Root>/Analog Input2' */
  struct {
    void *LoggedData;
  } Forces_PWORK;                      /* '<Root>/Forces' */

  struct {
    void *LoggedData;
  } Lateralforce_PWORK;                /* '<Root>/Lateral force' */

  struct {
    void *LoggedData;
  } end_voltage_PWORK;                 /* '<Root>/end_voltage' */

  struct {
    void *LoggedData;
  } heave_PWORK;                       /* '<Root>/heave' */

  struct {
    void *LoggedData;
  } pitch_PWORK;                       /* '<Root>/pitch' */

  struct {
    void *LoggedData;
  } torquez_PWORK;                     /* '<Root>/torque z' */

  struct {
    void *LoggedData;
  } velocity_PWORK;                    /* '<Root>/velocity' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S1>/FromWs' */

  uint8_T Integrator_SYSTEM_ENABLE;    /* '<Root>/Integrator' */
  uint8_T Integrator2_SYSTEM_ENABLE;   /* '<Root>/Integrator 2' */
} DW_CPS_heave_noAccelmeter_20221201_T;

/* Continuous states (default storage) */
typedef struct {
  real_T AnalogFilterDesign_CSTATE[4]; /* '<Root>/Analog Filter Design' */
} X_CPS_heave_noAccelmeter_20221201_T;

/* State derivatives (default storage) */
typedef struct {
  real_T AnalogFilterDesign_CSTATE[4]; /* '<Root>/Analog Filter Design' */
} XDot_CPS_heave_noAccelmeter_20221201_T;

/* State disabled  */
typedef struct {
  boolean_T AnalogFilterDesign_CSTATE[4];/* '<Root>/Analog Filter Design' */
} XDis_CPS_heave_noAccelmeter_20221201_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            CPS_heave_noAccelmeter_20221201_B
#define BlockIO                        B_CPS_heave_noAccelmeter_20221201_T
#define rtX                            CPS_heave_noAccelmeter_20221201_X
#define ContinuousStates               X_CPS_heave_noAccelmeter_20221201_T
#define rtXdot                         CPS_heave_noAccelmeter_20221201_XDot
#define StateDerivatives               XDot_CPS_heave_noAccelmeter_20221201_T
#define tXdis                          CPS_heave_noAccelmeter_20221201_XDis
#define StateDisabled                  XDis_CPS_heave_noAccelmeter_20221201_T
#define rtP                            CPS_heave_noAccelmeter_20221201_P
#define Parameters                     P_CPS_heave_noAccelmeter_20221201_T
#define rtDWork                        CPS_heave_noAccelmeter_20221201_DW
#define D_Work                         DW_CPS_heave_noAccelmeter_20221201_T

/* Parameters (default storage) */
struct P_CPS_heave_noAccelmeter_20221201_T_ {
  real_T M;                            /* Variable: M
                                        * Referenced by:
                                        *   '<Root>/inverse  mass (1//kg) '
                                        *   '<Root>/Unit  Delay'
                                        */
  real_T Wallace_Cal_tranp[36];        /* Variable: Wallace_Cal_tranp
                                        * Referenced by: '<Root>/conversion  matrix'
                                        */
  real_T c;                            /* Variable: c
                                        * Referenced by: '<Root>/Virtual damping (kg//s)'
                                        */
  real_T k;                            /* Variable: k
                                        * Referenced by:
                                        *   '<Root>/Virtual spring (N//m)'
                                        *   '<Root>/Unit  Delay'
                                        */
  real_T start_position_meters;        /* Variable: start_position_meters
                                        * Referenced by:
                                        *   '<Root>/initial position'
                                        *   '<Root>/Integrator 2'
                                        *   '<Root>/Unit  Delay'
                                        */
  real_T EncoderInput_InputFilter;   /* Mask Parameter: EncoderInput_InputFilter
                                      * Referenced by: '<Root>/Encoder Input'
                                      */
  real_T AnalogOutput1_MaxMissedTicks;
                                 /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                  * Referenced by: '<Root>/Analog Output1'
                                  */
  real_T AnalogOutput2_MaxMissedTicks;
                                 /* Mask Parameter: AnalogOutput2_MaxMissedTicks
                                  * Referenced by: '<Root>/Analog Output2'
                                  */
  real_T AnalogInput1_MaxMissedTicks;
                                  /* Mask Parameter: AnalogInput1_MaxMissedTicks
                                   * Referenced by: '<Root>/Analog Input1'
                                   */
  real_T EncoderInput_MaxMissedTicks;
                                  /* Mask Parameter: EncoderInput_MaxMissedTicks
                                   * Referenced by: '<Root>/Encoder Input'
                                   */
  real_T AnalogInput2_MaxMissedTicks;
                                  /* Mask Parameter: AnalogInput2_MaxMissedTicks
                                   * Referenced by: '<Root>/Analog Input2'
                                   */
  real_T AnalogOutput1_YieldWhenWaiting;
                               /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                * Referenced by: '<Root>/Analog Output1'
                                */
  real_T AnalogOutput2_YieldWhenWaiting;
                               /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
                                * Referenced by: '<Root>/Analog Output2'
                                */
  real_T AnalogInput1_YieldWhenWaiting;
                                /* Mask Parameter: AnalogInput1_YieldWhenWaiting
                                 * Referenced by: '<Root>/Analog Input1'
                                 */
  real_T EncoderInput_YieldWhenWaiting;
                                /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                 * Referenced by: '<Root>/Encoder Input'
                                 */
  real_T AnalogInput2_YieldWhenWaiting;
                                /* Mask Parameter: AnalogInput2_YieldWhenWaiting
                                 * Referenced by: '<Root>/Analog Input2'
                                 */
  int32_T AnalogOutput1_Channels;      /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<Root>/Analog Output1'
                                        */
  int32_T AnalogOutput2_Channels;      /* Mask Parameter: AnalogOutput2_Channels
                                        * Referenced by: '<Root>/Analog Output2'
                                        */
  int32_T AnalogInput1_Channels[9];    /* Mask Parameter: AnalogInput1_Channels
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T EncoderInput_Channels;       /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<Root>/Encoder Input'
                                        */
  int32_T AnalogInput2_Channels[4];    /* Mask Parameter: AnalogInput2_Channels
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  int32_T AnalogOutput1_RangeMode;    /* Mask Parameter: AnalogOutput1_RangeMode
                                       * Referenced by: '<Root>/Analog Output1'
                                       */
  int32_T AnalogOutput2_RangeMode;    /* Mask Parameter: AnalogOutput2_RangeMode
                                       * Referenced by: '<Root>/Analog Output2'
                                       */
  int32_T AnalogInput1_RangeMode;      /* Mask Parameter: AnalogInput1_RangeMode
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T AnalogInput2_RangeMode;      /* Mask Parameter: AnalogInput2_RangeMode
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  int32_T AnalogOutput1_VoltRange;    /* Mask Parameter: AnalogOutput1_VoltRange
                                       * Referenced by: '<Root>/Analog Output1'
                                       */
  int32_T AnalogOutput2_VoltRange;    /* Mask Parameter: AnalogOutput2_VoltRange
                                       * Referenced by: '<Root>/Analog Output2'
                                       */
  int32_T AnalogInput1_VoltRange;      /* Mask Parameter: AnalogInput1_VoltRange
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T AnalogInput2_VoltRange;      /* Mask Parameter: AnalogInput2_VoltRange
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T torad_Gain;                   /* Expression: 1/180*pi
                                        * Referenced by: '<Root>/to rad'
                                        */
  real_T AnalogFilterDesign_A_pr[7];
                                  /* Computed Parameter: AnalogFilterDesign_A_pr
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  real_T AnalogFilterDesign_B_pr; /* Computed Parameter: AnalogFilterDesign_B_pr
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  real_T AnalogFilterDesign_C_pr; /* Computed Parameter: AnalogFilterDesign_C_pr
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  real_T AnalogFilterDesign_InitialCondition;/* Expression: 0
                                              * Referenced by: '<Root>/Analog Filter Design'
                                              */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator2_gainval;         /* Computed Parameter: Integrator2_gainval
                                       * Referenced by: '<Root>/Integrator 2'
                                       */
  real_T SineWave_Amp;                 /* Expression: 0.05
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*3.14*1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Zero'
                                        */
  real_T positionoutmtoV_Gain;         /* Expression: 1/0.03
                                        * Referenced by: '<Root>/position out  m to V'
                                        */
  real_T offsetdeg_Value;              /* Expression: 0.5
                                        * Referenced by: '<Root>/offset(deg)'
                                        */
  real_T angleoutdeg1_Gain;    /* Expression: -5.*10/30000*12800/360*1.00*180/pi
                                * Referenced by: '<Root>/angle out deg1'
                                */
  real_T forcebias_Bias[6];         /* Expression: -tare.signals.values(end,1:6)
                                     * Referenced by: '<Root>/force bias'
                                     */
  real_T accelbiasV_Bias;             /* Expression: -tare.signals.values(end,7)
                                       * Referenced by: '<Root>/accel bias (V)'
                                       */
  real_T accelVtoms2_Gain;             /* Expression: -9.81
                                        * Referenced by: '<Root>/accel V to m//s2'
                                        */
  real_T loadmass_Gain;                /* Expression: 0.6+0.306
                                        * Referenced by: '<Root>/load mass'
                                        */
  real_T Zeroforce_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Zero force'
                                        */
  real_T cmm_Gain;                     /* Expression: 100
                                        * Referenced by: '<Root>/cm//m'
                                        */
  real_T countstocm_Gain;              /* Expression: -1*(1/(4*2000))*2.54
                                        * Referenced by: '<Root>/counts to cm'
                                        */
  real_T PitchVtorad_Gain;             /* Expression: -1/3.83
                                        * Referenced by: '<Root>/Pitch V to rad'
                                        */
  real_T Heaveoffset_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Heave offset'
                                        */
  real_T virtualmasskg_Gain;           /* Expression: 0
                                        * Referenced by: '<Root>/virtual mass (kg)'
                                        */
  real_T Bias_Bias;                    /* Expression: -2.5
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T conversion1_Gain;             /* Expression: 0.4
                                        * Referenced by: '<Root>/conversion1'
                                        */
  uint32_T AnalogFilterDesign_A_ir[7];
                                  /* Computed Parameter: AnalogFilterDesign_A_ir
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint32_T AnalogFilterDesign_A_jc[5];
                                  /* Computed Parameter: AnalogFilterDesign_A_jc
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint32_T AnalogFilterDesign_B_ir;
                                  /* Computed Parameter: AnalogFilterDesign_B_ir
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint32_T AnalogFilterDesign_B_jc[2];
                                  /* Computed Parameter: AnalogFilterDesign_B_jc
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint32_T AnalogFilterDesign_C_ir;
                                  /* Computed Parameter: AnalogFilterDesign_C_ir
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint32_T AnalogFilterDesign_C_jc[5];
                                  /* Computed Parameter: AnalogFilterDesign_C_jc
                                   * Referenced by: '<Root>/Analog Filter Design'
                                   */
  uint8_T sineorcustomtraj_CurrentSetting;
                          /* Computed Parameter: sineorcustomtraj_CurrentSetting
                           * Referenced by: '<Root>/sine or custom traj.'
                           */
  uint8_T signalorzero_CurrentSetting;
                              /* Computed Parameter: signalorzero_CurrentSetting
                               * Referenced by: '<Root>/signal or zero'
                               */
  uint8_T CPSorreference_CurrentSetting;
                            /* Computed Parameter: CPSorreference_CurrentSetting
                             * Referenced by: '<Root>/CPS or  reference'
                             */
  uint8_T Pitchzeroorconstant_CurrentSetting;
                       /* Computed Parameter: Pitchzeroorconstant_CurrentSetting
                        * Referenced by: '<Root>/Pitch zero or constant'
                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CPS_heave_noAccelmeter_20221201_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[4][4];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_CPS_heave_noAccelmeter_20221201_T CPS_heave_noAccelmeter_20221201_P;

/* Block signals (default storage) */
extern B_CPS_heave_noAccelmeter_20221201_T CPS_heave_noAccelmeter_20221201_B;

/* Continuous states (default storage) */
extern X_CPS_heave_noAccelmeter_20221201_T CPS_heave_noAccelmeter_20221201_X;

/* Block states (default storage) */
extern DW_CPS_heave_noAccelmeter_20221201_T CPS_heave_noAccelmeter_20221201_DW;

/* Model entry point functions */
extern void CPS_heave_noAccelmeter_20221201_initialize(void);
extern void CPS_heave_noAccelmeter_20221201_output(void);
extern void CPS_heave_noAccelmeter_20221201_update(void);
extern void CPS_heave_noAccelmeter_20221201_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern CPS_heave_noAccelmeter_20221201_rtModel *CPS_heave_noAccelmeter_20221201
  (void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_CPS_heave_noAccelmeter_20221201_T *const
  CPS_heave_noAccelmeter_20221201_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CPS_heave_noAccelmeter_20221201'
 * '<S1>'   : 'CPS_heave_noAccelmeter_20221201/trajectory custom'
 */
#endif                       /* RTW_HEADER_CPS_heave_noAccelmeter_20221201_h_ */
