#include "pch.h"
#include "preyDllObjects.h"
staticObjectPointers::staticObjectPointers(uintptr_t moduleBase) {
	gEnvPtr = (_gEnv*)(moduleBase + 0x22418c0);
	gEnv = *gEnvPtr;
	// g_pGame = *(_g_pGame*)(moduleBase + 0x2c09010);
}
