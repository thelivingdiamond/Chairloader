#include "pch.h"
#include <Prey/CrySystem/ILog.h>
#include <Logging.h>
#include <preyDllObjects.h>

extern SSystemGlobalEnvironment *gEnv;

void CryLog(const char *format, ...) {
	va_list args;
	va_start(args, format);
	gEnv->pLog->LogV(ILog::eAlways, format, args);
	va_end(args);
}

void CryWarning(const char *format, ...) {
	va_list args;
	va_start(args, format);
	gEnv->pLog->LogV(ILog::eWarningAlways, format, args);
	va_end(args);
}

void CryError(const char *format, ...) {
	va_list args;
	va_start(args, format);
	gEnv->pLog->LogV(ILog::eErrorAlways, format, args);
	va_end(args);
}

void CryFatalError(const char *format, ...) {
	va_list ArgList;
	char szBuffer[1024];
	va_start(ArgList, format);
	vsnprintf(szBuffer, sizeof(szBuffer), format, ArgList);
	va_end(ArgList);

	gEnv->pSystem->FatalError("%s", szBuffer);
}
