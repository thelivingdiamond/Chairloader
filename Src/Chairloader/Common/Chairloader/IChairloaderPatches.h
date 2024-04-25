#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct IChairloaderPatches : public IChairloaderModule
{
	static std::unique_ptr<IChairloaderPatches> CreateInstance();
	virtual ~IChairloaderPatches() {}

	//! System initialization
	virtual void InitSystem() = 0;

	//! Game initialization.
	virtual void InitGame() = 0;
};

} // namespace Internal
