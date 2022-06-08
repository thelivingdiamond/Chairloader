#pragma once
#include <Prey/CryThreading/IJobManager.h>
#include "ChairloaderUtils.h"

namespace CryProfile {
class CScopedProfileMarker {
public:
	CScopedProfileMarker(const char *name) {
		chairloader->preyEnvironmentPointers->pJobManager->PushProfilingMarker(name);
	}

	~CScopedProfileMarker() {
		chairloader->preyEnvironmentPointers->pJobManager->PopProfilingMarker();
	}
};
}

#define CRYPROF_CAT_(a, b) a ## b
#define CRYPROF_CAT(a, b)  CRYPROF_CAT_(a, b)
#define CRY_PROFILE_MARKER(name) CryProfile::CScopedProfileMarker CRYPROF_CAT(profMarker, __LINE__)(name)
