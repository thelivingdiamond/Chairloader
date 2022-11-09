#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct SToolsInitParams
{
	bool bEnableEditor = false;
	bool bEnableTrainer = false;
};

struct IChairloaderTools : public IChairloaderModule
{
	static std::unique_ptr<IChairloaderTools> CreateInstance();
	virtual ~IChairloaderTools() {}

	//! System initialization
	virtual void InitSystem(const SToolsInitParams& params) = 0;

	//! Game initialization.
	virtual void InitGame() = 0;
};

} // namespace Internal
