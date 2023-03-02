/* Copyright 1997-2016 The MathWorks, Inc. */

#ifndef _debugger_codegen_interface_h
#define _debugger_codegen_interface_h

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#if defined(S_FUNCTION_NAME)
#include "mwmathutil.h"
#endif

#include "sf_runtime/sf_runtime_spec.h"
#ifndef _SIMSTRUCT
#  define _SIMSTRUCT
typedef struct SimStruct_tag SimStruct;
#endif

LIBMWSF_RUNTIME_API void* sfListenerInitializeUsingSimStruct(SimStruct* S);
LIBMWSF_RUNTIME_API void* sfListenerInitializeUsingBlockPath(char* blkPath);

LIBMWSF_RUNTIME_API void sfListenerTerminate(void* rt);
LIBMWSF_RUNTIME_API void sfListenerInitializeRuntimeVars(void* rt, int* areListenersActive, bool isJitCompliantDebuggerOn, bool isSequenceViewerVisible, int* numFcnVars, char** dataNames[],void** dataPtrs[], char** marshallingOutFcns[], char** marshallingInFcns[],  int* statuses[], int* lineNumber);

LIBMWSF_RUNTIME_API void sfListenerReportScriptName(void* rt, char* aScriptName);

LIBMWSF_RUNTIME_API void sfListenerReportStartingSection(void* rt, unsigned int aSSIDNumber, int aSectionId);
LIBMWSF_RUNTIME_API void sfListenerReportEndingSection(void* rt, unsigned int aSSIDNumber, int aSectionId);

LIBMWSF_RUNTIME_API void sfListenerPushScope(void* rt, unsigned int aSSIDNumber, unsigned int N, char* aVarNames[], void* aDataPtr[], char* aMarchallingOutFunctions[], char* aMarshallingInFunctions[], int aStatus[]);
LIBMWSF_RUNTIME_API void sfListenerPopScope(void* rt, unsigned int aSSIDNumber);

LIBMWSF_RUNTIME_API void sfListenerPushScopeForChart(void* rt, unsigned int aSSIDNumber, unsigned int N, char* aVarNames[], void* aDataPtr[], char* aMarshallingOutFunctions[], char* aMarshallingInFunctions[], int aStatus[]);
LIBMWSF_RUNTIME_API void sfListenerPopScopeForChart(void* rt, unsigned int aSSIDNumber);

LIBMWSF_RUNTIME_API void sfListenerReportStartingEventBroadcast(void* rt, unsigned int aEventSSIDNumber, int aSectionId);
LIBMWSF_RUNTIME_API void sfListenerReportEndingEventBroadcast(void* rt, unsigned int aEventSSIDNumber, int aSectionId);
LIBMWSF_RUNTIME_API void sfListenerReportLineNumber(void* rt, unsigned int aSSIDNumber,int aLineNumber);

LIBMWSF_RUNTIME_API void sfListenerReportScriptName(void* rt, char* scriptName);

#endif
