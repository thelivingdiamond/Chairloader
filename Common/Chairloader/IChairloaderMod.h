#pragma once
#include "IChairloader.h"

struct ISystem;
struct IGameFramework;
struct ImGuiContext;

//! This is the version of the Mod SDK. It defines compatibility of mods with Chairloader.
//! It must follow Semantic Versioning 2.0.0 spec.
constexpr int MOD_SDK_VERSION_MAJOR = 0; //!< Increment when breaking API/ABI.
constexpr int MOD_SDK_VERSION_MINOR = 1; //!< Increment when adding something new to the API.
constexpr int MOD_SDK_VERSION_PATCH = 0; //!< Increment on a bug-fix with no API/ABI changes.

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
		bool isHotReloading = false; //!< Whether the mod is being hot-reloaded.
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

	//! Gets the Mod SDK version used to build the DLL.
	virtual void GetModSdkVersion(int& major, int& minor, int& patch) = 0;

	//! Called during CSystem::Init, before any engine modules.
	virtual void InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo) = 0;
	
	//! Called after CGame::Init
	virtual void InitGame(bool isHotReloading) = 0;

	//! Called before CGame::Shutdown.
	virtual void ShutdownGame(bool isHotUnloading) = 0;

	//! Called before CSystem::Shutdown.
	virtual void ShutdownSystem(bool isHotUnloading) = 0;

	//! Called just before MainUpdate to draw GUI. Only called when GUI is visible.
	virtual void Draw() {}

	//! Earliest point of update in a frame, before CGame::Update. The timer still tracks time for the previous frame.
	virtual void UpdateBeforeSystem(unsigned updateFlags) {}

	//! Called before physics is updated for the new frame, best point for queuing physics jobs.
	//! This is like FixedUpdate() in Unity (but not FPS-independent). Use gEnv->pTimer->GetFrameTime() for time delta.
	virtual void UpdateBeforePhysics(unsigned updateFlags) {}

	//! Called after entities have been updated but before FlowSystem and FlashUI.
	//! This is the main update where most game logic is expected to occur.
	//! Should be preferred if you don't need any special behavior.
	virtual void MainUpdate(unsigned updateFlags) {}

	//! Called after most of game logic has been updated, before CCryAction::PostUpdate.
	virtual void LateUpdate(unsigned updateFlags) {}
};
