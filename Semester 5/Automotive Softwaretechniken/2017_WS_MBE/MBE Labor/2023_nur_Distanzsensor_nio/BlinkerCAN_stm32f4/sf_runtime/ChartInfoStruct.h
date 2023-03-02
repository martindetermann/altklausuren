/* Copyright 2013 The MathWorks, Inc. */

#ifndef _sf_runtime_ChartInfoStruct_h_
#define _sf_runtime_ChartInfoStruct_h_

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif
struct SfDebugInstanceStruct;
struct CovrtStateflowInstance;
typedef struct
{
    unsigned int isEMLChart;
    void *chartInstance;
    char sFunctionName[mxMAXNAM];
    unsigned int chartInitialized;
    void (*sFunctionGateway)(void* chartInstance);
    void (*extModeExec)(void* chartInstance);
    void (*restoreLastMajorStepConfiguration)(void* chartInstance);
    void (*restoreBeforeLastMajorStepConfiguration)(void* chartInstance);
    void (*storeCurrentConfiguration)(void* chartInstance);
    void (*initializeChart)(void* chartInstance);
    void (*terminateChart)(void* chartInstance);
    void (*enableChart)(void* chartInstance);
    void (*disableChart)(void* chartInstance);
    const mxArray* (*getSimState)(SimStruct* S);
    const mxArray* (*getSimStateInfo)(void);
    void (*setSimState)(SimStruct* S, const mxArray *st);
    void (*zeroCrossings)(void *chartInstance);
    void (*outputs)(void *chartInstance);
    void (*derivatives)(void *chartInstance);
    void (*mdlRTW)(SimStruct *S);
    void (*mdlSetWorkWidths)(SimStruct *S);
    void (*mdlStart)(SimStruct *S);
    void (*callAtomicSubchartUserFcn)(SimStruct* S, int fcnSSID, void *args);
    void (*callAtomicSubchartAutoFcn)(SimStruct* S, int fcnEnum, void *args);
    const mxArray* (*callGetHoverDataForMsg)(void* chartInstance, int msgSSID);
    struct SfDebugInstanceStruct* debugInstance;
} ChartInfoStruct;

LIBMWSF_RUNTIME_API void sf_init_ChartRunTimeInfo(SimStruct* S, void * instanceInfo, bool isJITEnabled, bool hasSeparateUpdateOutputs);
LIBMWSF_RUNTIME_API void sf_free_ChartRunTimeInfo(SimStruct* S);

LIBMWSF_RUNTIME_API ChartInfoStruct* getChartInfoStruct(SimStruct* S); 
LIBMWSF_RUNTIME_API void* sfrtGetEmlrtCtx(SimStruct *S);
LIBMWSF_RUNTIME_API CovrtStateflowInstance * sfrtGetCovrtInstance(SimStruct *S);
LIBMWSF_RUNTIME_API ChartInfoStruct* sf_get_ChartInfoStruct_CodeGen(SimStruct *S);
LIBMWSF_RUNTIME_API void* sf_get_chart_instance_ptr(SimStruct* S);
LIBMWSF_RUNTIME_API bool sf_get_hasSeparateUpdateOutputs(SimStruct* S);
LIBMWSF_RUNTIME_API void sf_set_compiledInfo(SimStruct* S, void *compiledInfo);
LIBMWSF_RUNTIME_API void sf_create_emlctx(SimStruct* S, void* aRootTLS, void* aContext);

#endif
