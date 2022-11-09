#pragma once
#include <Chairloader/IChairloader.h>

namespace Internal
{

struct IChairloaderCore;
struct IChairloaderCryRender;

struct IChairloaderDll : public IChairloader
{
	virtual ~IChairloaderDll() {}
	virtual IChairloaderCore* GetCore() = 0;
	virtual IChairloaderCryRender* GetCryRender() = 0;

	//! @returns whether it was handled and shouldn't be passed over to the game.
	virtual bool HandleKeyPress(const SInputEvent& event) = 0;
};

}

extern Internal::IChairloaderDll* gChair;
