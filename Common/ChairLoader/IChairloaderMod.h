#pragma once
#include "IChairloader.h"

struct ISystem;
struct IGameFramework;
struct ImGuiContext;

struct IChairloaderMod {
	static constexpr char PROC_INITIALIZE[] = "ClMod_Initialize";
	static constexpr char PROC_SHUTDOWN[] = "ClMod_Shutdown";
	using ProcInitialize = IChairloaderMod* ();
	using ProcShutdown = void ();

	//! Data needed to initialize mods.
	struct ModInitInfo
	{
		ISystem* pSystem = nullptr;
		IChairloader* pChair = nullptr;
		fs::path modDirPath; //!< Path to the mod directory in "Mods"
		fs::path modDllPath; //!< Path to the loaded DLL
	};

	//! Mod info that depends on the DLL.
	struct ModDllInfo
	{
		//! The size of this struct. Used for versioning.
		size_t thisStructSize = 0;

		//! Full name of the mod. Must match the name in the XML. Must be valid for
		//! the whole duration the mod is loaded.
		const char* modName = nullptr;

		//! Whether the mod supports hot-reloading. Check the wiki for details.
		bool supportsHotReload = false;
	};

	~IChairloaderMod() {}

	//! Called during CSystem::Init, before any engine modules.
	virtual void InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo) = 0;
	
	//! Called after CGame::Init
	virtual void InitGame() = 0;

	//! Called before CGame::Update to handle any GUI elements
	virtual void Draw() = 0;

	//! Before CGame::Update
	virtual void PreUpdate() = 0;

	//! After CGame::Update
	virtual void PostUpdate() = 0;

	//! Called before CGame::Shutdown.
	virtual void ShutdownGame() = 0;

	//! Called before CSystem::Shutdown.
	virtual void ShutdownSystem() = 0;
};


// define this function in the cpp file for your mod
// EXTERN_C DLL_EXPORT IChairloaderMod* ClMod_Instantiate();