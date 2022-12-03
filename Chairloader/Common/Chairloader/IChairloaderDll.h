#pragma once
#include <Chairloader/IChairloader.h>

namespace Internal
{

struct IChairloaderCore;
struct IChairloaderCryRender;
struct IChairloaderTools;

struct IChairloaderDll : public IChairloader
{
	virtual ~IChairloaderDll() {}
	virtual IChairloaderCore* GetCore() = 0;
	virtual IChairloaderCryRender* GetCryRender() = 0;
	virtual IChairloaderTools* GetTools() = 0;

	//! @returns whether it was handled and shouldn't be passed over to the game.
	virtual bool HandleKeyPress(const SInputEvent& event) = 0;

	//! Reloads all mod DLLs that support hot-reloading.
	//! Can only be called with specific conditions in mind.
	virtual void ReloadModDLLs() = 0;
};

}

extern Internal::IChairloaderDll* gChair;
