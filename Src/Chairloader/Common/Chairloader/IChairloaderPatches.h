#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct IChairloaderPatches : public IChairloaderModule, IChairService<IChairloaderPatches>
{

	static const char* NameImpl() { return "IChairloaderPatches"; }

	virtual ~IChairloaderPatches() {}

	//! System initialization
	virtual void InitSystem() = 0;

	//! Game initialization.
	virtual void InitGame() = 0;
};

} // namespace Internal
