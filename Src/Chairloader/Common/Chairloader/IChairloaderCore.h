#pragma once
#include <Chairloader/IChairloaderModule.h>

struct IChairLogger;
struct IChairVarManager;

namespace Internal
{

struct ILogManager;
struct IModDllManager;

struct IChairloaderCore : public IChairloaderModule, IChairService<IChairloaderCore>
{
	static const char* NameImpl() { return "IChairloaderCore"; }

	virtual ~IChairloaderCore() {}

	virtual ILogManager* GetLogManager() = 0;
	virtual IModDllManager* GetDllManager() = 0;
    virtual IChairVarManager* GetCVarManager() = 0;

	//! System initialization
	virtual void InitSystem() = 0;

	//! Registers all mods from the config with the DLL Manager. Checks if editor is enabled or not.
	virtual void RegisterMods() = 0;

	//! Called before InitGame.
	virtual void PreInitGame() = 0;

	//! Game initialization.
	virtual void InitGame() = 0;

	//! Called before any other module or mod is shut down.
	virtual void PreShutdown() = 0;

	//! @returns whether the mod is installed and enabled.
	virtual bool IsModInstalled(const std::string& modName) = 0;

    virtual EKeyId LoadConfigKey(const std::string& paramName, EKeyId defaultKey = eKI_Unknown) = 0;
};

} // namespace Internal
