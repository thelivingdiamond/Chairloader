#pragma once
#include <Prey/CryCore/Platform/CryWindows.h>
#include <pugixml.hpp>
#include <ChairLoader/IChairloaderMod.h>

//! This class manages DLL loading in call dispatch for mods.
//! Note:
//!     "mod" is short for "modification". It's a directory in Mods with ModInfo.xml.
//!     "module" is a DLL. One mod (in the future) may have multiple DLLs: some hot-reloadable, some not.
class ModDllManager
{
public:
	//! Adds the mod DLL for a mod as defined in the config.
	//! Loads the mod's config.
	void RegisterModFromXML(pugi::xml_node xmlNode);

	//! Loads the mod DLLs.
	void LoadModules();

	//! Unloads all mod DLLs.
	void UnloadModules();

	//! Calls a function for each mod in the load order or reverse order.
	//! @{
	void CallInitSystem();
	void CallInitGame();
	void CallPreUpdate();
	void CallDraw();
	void CallPostUpdate();
	void CallShutdownGame();
	void CallShutdownSystem();
	//! @}

private:
	struct ModuleInfo
	{
		//! Unique mod name.
		std::string modName;

		//! The load order.
		int loadOrder;

		//! Path to the mod's directory.
		fs::path modDirPath;

		//! Path to the mod's DLL.
		fs::path sourceDllPath;
	};

	struct Module : ModuleInfo
	{
		Module(const ModuleInfo& info) : ModuleInfo(info) {}

		//! Handle of the loaded DLL.
		HMODULE hModule = nullptr;

		//! Functions exported by the DLL.
		//! @{
		IChairloaderMod::ProcInitialize* pfnInit = nullptr;
		IChairloaderMod::ProcShutdown* pfnShutdown = nullptr;
		//! @}
		
		//! The mod interface.
		IChairloaderMod* pModIface = nullptr;

		//! Info returned by the DLL
		IChairloaderMod::ModDllInfo dllInfo;
	};

	//! List of registered mods sorted by load order.
	std::map<int, std::vector<ModuleInfo>> m_RegisteredMods;

	//! List of modules.
	std::vector<Module> m_Modules;

	//! Loads the DLL and gets all functions. Errors in the process will cause a fatal error.
	void LoadModule(Module& mod);

	//! Calls Shutdown and unloads the DLL.
	void UnloadModule(Module& mod);
};