#pragma once
#include <Manager/GamePath.h>

struct IGameStartup;
struct ITexture;
struct IChairToPreditor;

namespace Engine
{
struct ISimulationController;
} // namespace Engine

struct IPreditorEngine
{
	using ProgressCallback = std::function<void(const char* sProgressMsg)>;

	struct InitParams
	{
		//! Called when loading stage changes.
		ProgressCallback progressCallback;

		//! Path to the game engine.
		GamePath enginePath;

		//! Optional path to the GameSDK directory to use.
		fs::path gameSdkPath;

		//! Optional paths to mod directories. If set, files from there will override GameSDK files.
		std::vector<fs::path> modDirPaths;

		//! Path to the user directory to store user-specific files.
		fs::path userPath;

		//! Initialize bare minimum to get ICryPak.
		bool minimal = false;

		//! Load PAKs from the original GameSDK. Only use if GameSDK path is different.
		bool loadGamePaks = false;

		//! Load pak files with original file case.
		//! WARNING: Will break file opening by name from paks.
		bool caseSensitivePaks = false;

		//! Skip loading of patch_chariloader.pak.
		bool skipChairloaderPatch = false;
	};

	//! @returns the singleton instance.
	static IPreditorEngine* Get();

	virtual ~IPreditorEngine() {}

	//! Loads the engine DLLs. Throws on error.
	virtual void Load(const InitParams& params) = 0;

	//! Initializes the engine. Can only ever be called once.
	//! @returns whether it was loaded successfully or not.
	virtual bool Start(const InitParams& params) = 0;

	//! Unloads the engine.
	//! Once it was unloaded, it can't be reloaded back until the EXE is restarted.
	virtual void Shutdown() = 0;

	//! Switches current app ImGui instance to the one running in the engine.
	virtual void SetAppImGui() = 0;

	//! Runs an iteration of the main loop.
	//! @returns whether to continue running, exit on false.
	virtual bool Update() = 0;

	//! @returns the texture of viewport backbuffer.
	virtual ITexture* GetViewportTexture() = 0;

	//! @returns IChairToPreditor instance.
	virtual IChairToPreditor* GetIChairToPreditor() = 0;

	//! @returns ISimulationController instance.
	virtual Engine::ISimulationController* GetSimController() = 0;

	//! Enables/disable keyboard and mouse input to the game.
	virtual void SetGameInputEnabled(bool state) = 0;
	virtual bool IsGameInputEnabled() = 0;

	//! Sets the bounds of the game viewport in screen coordinates.
	//! @returns whether they were changed.
	virtual bool SetGameViewportRect(ImGuiID viewportId, Vec2i min, Vec2i max) = 0;
};
