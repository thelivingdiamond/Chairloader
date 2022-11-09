#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct IModDllManager;

struct IChairloaderCore : public IChairloaderModule
{
	static std::unique_ptr<IChairloaderCore> CreateInstance();
	virtual ~IChairloaderCore() {}

	virtual IModDllManager* GetDllManager() = 0;

	//! System initialization
	virtual void InitSystem() = 0;

	//! Registers all mods from the config with the DLL Manager. Checks if editor is enabled or not.
	virtual void RegisterMods() = 0;

	//! Game initialization.
	virtual void InitGame() = 0;
};

} // namespace Internal
