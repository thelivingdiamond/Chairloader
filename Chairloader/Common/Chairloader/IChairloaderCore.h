#pragma once
#include <Chairloader/IChairloaderModule.h>

struct IChairLogger;
struct IChairVarManager;

namespace Internal
{

struct ILogManager;
struct IModDllManager;

struct IChairloaderCore : public IChairloaderModule
{
	static std::unique_ptr<IChairloaderCore> CreateInstance();
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

	//! @returns whether the mod is installed and enabled.
	virtual bool IsModInstalled(const std::string& modName) = 0;

	//! Creates a new IChairLogger instance.
	virtual std::unique_ptr<IChairLogger> CreateLogger() = 0;

    virtual EKeyId LoadConfigKey(const std::string& paramName, EKeyId defaultKey = eKI_Unknown) = 0;
};

} // namespace Internal
