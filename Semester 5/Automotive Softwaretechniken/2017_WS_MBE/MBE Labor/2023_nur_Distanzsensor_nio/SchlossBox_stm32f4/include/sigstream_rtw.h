#ifdef SUPPORTS_PRAGMA_ONCE
# pragma once
#endif
#ifndef sl_sigstream_rtw_h
#define sl_sigstream_rtw_h
/*
 *
 * Copyright 2008-2016 The MathWorks, Inc.
 *
 * This header is the interface to the sigstream module. It is used by the
 * RTW-RSim and Rapid Accelerator targets.
 *
 * 
 *
 */

#ifdef __cplusplus
extern "C" {
#endif


extern void rtwOSigstreamManagerSaveDatasetsToMatFile(
    void *pOpaqueOSigstreamManager,
    const char *fileName
    );

extern void rtwISigstreamManagerSetDestinationBase(
    void *pOpaqueISigstreamManager,
    const size_t destinationId,
    void *pDestinationBase
    );

extern void rtwISigstreamManagerCreateInstance(void **outpISigstreamManager);

extern void rtwISigstreamManagerDestroyInstance(void *pOpaqueISigstreamManager);

extern void rtwISigstreamManagerGetDatasetInputFromMatFile(
    void *pOpaqueISigstreamManager,
    const char *fileName
    );

extern void rtwISigstreamManagerGetInputIsInDatasetFormat(
    void *pOpaqueISigstreamManager,
    bool *outInputIsInDatasetFormat
    );

extern const char * rtwISigstreamManagerInjectDataMultiRate(
    void *pOpaqueISigstreamManager,
    const size_t destinationId,
    const double time,
    int errorXMLMode,
    const char *block,
    const char *var
    );

extern const char * rtwISigstreamManagerInjectDataSingleRate(
    void *pOpaqueISigstreamManager,
    const double time,
    int errorXMLMode,
    const char *block,
    const char *var
    );

extern const char *rtwOSigstreamManagerCreateInstance(
    const char *settingsFileName,
    void * r2,
    void **outpOSigstreamManager
    );

extern void rtwOSigstreamManagerDestroyInstance(void *pOpaqueOSigstreamManager);

extern void rtwLoggingIntervalCreateInstance(void **outpLoggingInterval);
extern void rtwLoggingIntervalDestroyInstance(void *pOpaqueLoggingInterval);
extern bool rtwLoggingIntervalConstructIntervalTree(
    void *pOpaqueLoggingInterval, 
    void *pOpaqueIntervals);

extern bool rtwTimeInLoggingInterval(void *pOpaqueLoggingInterval, 
                                     const time_T time);


#ifdef __cplusplus
}
#endif

#endif /* sl_sigstream_rtw_h */

/* LocalWords:  RSim
 */
