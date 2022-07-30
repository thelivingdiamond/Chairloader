#pragma once
#include <EntityUtils.h>

#include "ChairloaderEnv.h"
#include "IChairloaderConfigManager.h"
#include "IChairloaderGui.h"

struct IChairloader {
	//! @returns Pointers to interfaces provided by Chairloader to be used by mods.
	virtual ChairloaderGlobalEnvironment* GetChairloaderEnvironment() = 0;
};
