#pragma once
#include <Prey/CryThreading/IJobManager.h>
#include "ChairLoader.h"

namespace CryProfile {
class CScopedProfileMarker {
public:
	CScopedProfileMarker(const char *name) {
		gEnv->pJobManager->PushProfilingMarker(name);
	}

	~CScopedProfileMarker() {
		gEnv->pJobManager->PopProfilingMarker();
	}
};
}

#define CRYPROF_CAT_(a, b) a ## b
#define CRYPROF_CAT(a, b)  CRYPROF_CAT_(a, b)
#define CRY_PROFILE_MARKER(name) CryProfile::CScopedProfileMarker CRYPROF_CAT(profMarker, __LINE__)(name)
