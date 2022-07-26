#pragma once
#include <EntityUtils.h>

#include "IChairloaderEnv.h"
#include "IChairloaderConfigManager.h"
#include "IChairloaderGui.h"

struct IChairloader {
	// TODO: figure out what goes here!!!
	virtual IChairloaderGlobalEnvironment* getChairloaderEnvironment() = 0;
};

