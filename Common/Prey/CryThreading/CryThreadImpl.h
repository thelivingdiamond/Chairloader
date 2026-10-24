// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <Prey/CryThreading/CryThread.h>

// Include architecture specific code.
#if CRY_PLATFORM_WINAPI
	#include <Prey/CryThreading/CryAtomics_impl_win32.h>
	#include <Prey/CryThreading/CryThreadImpl_win32.h>
#elif CRY_PLATFORM_ORBIS
	#include <CryThreading/CryThreadImpl_sce.h>
#elif CRY_PLATFORM_POSIX
	#include <CryThreading/CryThreadImpl_posix.h>
#else
// Put other platform specific includes here!
#endif

#include "IThreadTask.h"

void CryThreadSetName(threadID dwThreadId, const char* sThreadName)
{
	//ScopedSwitchToGlobalHeap useGlobalHeap;
	if (gEnv && gEnv->pSystem && gEnv->pSystem->GetIThreadTaskManager())
		gEnv->pSystem->GetIThreadTaskManager()->SetThreadName(dwThreadId, sThreadName);
}

const char* CryThreadGetName(threadID dwThreadId)
{
	if (gEnv && gEnv->pSystem && gEnv->pSystem->GetIThreadTaskManager())
		return gEnv->pSystem->GetIThreadTaskManager()->GetThreadName(dwThreadId);
	return "";
}

// vim:ts=2
