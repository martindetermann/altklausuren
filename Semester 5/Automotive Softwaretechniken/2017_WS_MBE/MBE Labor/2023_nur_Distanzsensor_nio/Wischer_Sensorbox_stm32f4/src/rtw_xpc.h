#ifndef RTW_XPC_H
#define RTW_XPC_H

/*
 * Copyright 2011 The MathWorks, Inc.
 *
 * File: rtw_xpc.h
 *
 * Abstract:
 *  Function prototypes and defines xPC target mutex/semaphores
 */
#include "xpcimports.h"

#define rtw_xpc_mutex_create( mutexDW ) \
    *(mutexDW) = TBCreateSpin();   

#define rtw_xpc_mutex_take( mutexDW )   \
    TBTakeSpinFast(mutexDW);

#define rtw_xpc_mutex_give( mutexDW )   \
    TBGiveSpinFast(mutexDW);

#define rtw_xpc_mutex_delete( mutexDW ) \
    TBDeleteSpin(mutexDW); 


#define rtw_xpc_sem_create( semaphoreDW, initVal ) \
    *semaphoreDW = xpceCreateSemaphore(2, initVal, "xPCSema");  \

#define rtw_xpc_sem_wait( semaphoreDW ) \
    xpceWaitSemaphore(semaphoreDW);

#define rtw_xpc_sem_signal( semaphoreDW ) \
    xpceSignalSemaphore(semaphoreDW);

#define rtw_xpc_sem_delete( semaphoreDW ) \
	xpceSignalSemaphore(semaphoreDW);     \
    xpceDeleteSemaphore(semaphoreDW);     


#endif /* RTW_LINUX_H */

