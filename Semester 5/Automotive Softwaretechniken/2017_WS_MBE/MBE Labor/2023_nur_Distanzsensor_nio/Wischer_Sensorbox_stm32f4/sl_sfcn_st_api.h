/* Copyright 2016 The MathWorks, Inc. */

/*
 * File:
 *
 * Abstract:
 */

#ifndef SL_SFCN_ST_API_H
#define SL_SFCN_ST_API_H

/* Guard against early inclusions */
#ifndef _SIMSTRUCT
# error "This file should be included from simstruc.h"
#endif

typedef int_T slstRateID;

# ifdef BUILDING_LIBMWSIMULINK
#  include "package.h"
#  define SLST_SFCN_API_EXPORT_EXTERN_C extern "C" DLL_EXPORT_SYM
# else
#  if defined(__cplusplus)
#   define SLST_SFCN_API_EXPORT_EXTERN_C extern "C"
#  else 
#   define SLST_SFCN_API_EXPORT_EXTERN_C extern
#  endif
# endif

SLST_SFCN_API_EXPORT_EXTERN_C void slstEnableSTAPI(SimStruct* S);

SLST_SFCN_API_EXPORT_EXTERN_C boolean_T slstIsPeriodicDiscreteRate(
    SimStruct* S,
    real_T period,
    real_T offset);

SLST_SFCN_API_EXPORT_EXTERN_C boolean_T slstIsVariableDiscreteRate(
    SimStruct* S,
    real_T period,
    real_T offset);
    
SLST_SFCN_API_EXPORT_EXTERN_C slstRateID slstRegisterVariableDiscreteRate(
        SimStruct* S,
        real_T period,
        const char* id);

SLST_SFCN_API_EXPORT_EXTERN_C slstRateID slstRegisterPeriodicDiscreteRate(
        SimStruct* S,
        real_T period);

SLST_SFCN_API_EXPORT_EXTERN_C void slstSetBlockRateID(
        SimStruct* S,
        slstRateID rateID);

SLST_SFCN_API_EXPORT_EXTERN_C slstRateID slstGetBlockRateID(
        SimStruct* S);

SLST_SFCN_API_EXPORT_EXTERN_C void slstSetInputPortRateID(
        SimStruct* S,
        int_T ip,
        slstRateID rateID);

SLST_SFCN_API_EXPORT_EXTERN_C slstRateID slstGetInputPortRateID(
        SimStruct* S,
        int_T ip);

SLST_SFCN_API_EXPORT_EXTERN_C void slstAcceptPropagatedInputPortRate(
        SimStruct* S,
        int_T ip);

SLST_SFCN_API_EXPORT_EXTERN_C void slstSetOutputPortRateID(
        SimStruct* S,
        int_T op,
        slstRateID rateID);

SLST_SFCN_API_EXPORT_EXTERN_C slstRateID slstGetOutputPortRateID(
        SimStruct* S,
        int_T op);

SLST_SFCN_API_EXPORT_EXTERN_C void slstAcceptPropagatedOutputPortRate(
        SimStruct* S,
        int_T op);

#define slstIsRateControlledByThisBlock(S, sti)                         \
     ( _ssGetBlkInfo2STInfo2Ptr(S)->isControlledByThisBlock[sti] )

#define slstSetNumTicksToNextSampleHitForVariableDiscreteRate(S, sti, nTicks) \
    slexecSetNumTicksToNextSampleHitForVariableDiscreteRate(            \
        ssGetRootSS(S),                                                 \
        _ssGetBlkInfo2STInfo2Ptr(S)->vdrInstanceIndex[sti],             \
        nTicks)


#define slstGetNumTicksToNextSampleHitForVariableDiscreteRate(S, sti)   \
    slexecGetNumTicksToNextSampleHitForVariableDiscreteRate(            \
        ssGetRootSS(S),                                                 \
        _ssGetBlkInfo2STInfo2Ptr(S)->vdrInstanceIndex[sti])


#define slstHasSampleHit(                       \
    S,                                          \
    rateID,                                     \
    tid)                                        \
    ssIsSampleHit(S, ((int_T)rateID), tid)


#endif /* SL_SFCN_ST_API_H */
