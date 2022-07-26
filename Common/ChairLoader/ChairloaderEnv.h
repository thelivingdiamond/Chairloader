#pragma once
#include "IChairloader.h"
#include "IChairloaderEnv.h"

struct ChairloaderGlobalEnvironment : IChairloaderGlobalEnvironment {
	IChairloader* cl;
	IChairloaderGui* gui;
	IChairloaderConfigManager* conf;
	PreyFunctions* funcs;
	EntityUtils* entUtils;
};

// extern ChairloaderGlobalEnvironment* gCLEnv;