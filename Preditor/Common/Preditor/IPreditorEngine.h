#pragma once

struct IGameStartup;
struct ITexture;
struct IChairToPreditor;
struct IGameViewport;

struct IPreditorEngine
{
	using ProgressCallback = std::function<void(const char* sProgressMsg)>;

	struct InitParams
	{
		//! Called when loading stage changes.
		ProgressCallback progressCallback;

		//! Path to the engine root
		fs::path enginePath;

		//! Path to the game binaries directory.
		fs::path engineBinariesPath;

		//! Optional path to the GameSDK directory to use.
		fs::path gameSdkPath;

		//! Optional path to a mod directory. If set, files from here will override GameSDK files.
		fs::path modDirPath;

		//! Path to the user directory to store user-specific files.
		fs::path userPath;

		//! Path to the directory to store Chairloader configs.
		fs::path chairloaderConfigPath;

		//! Initialize bare minimum to get ICryPak.
		bool minimal = false;

		//! Load PAKs from the original GameSDK. Only use if GameSDK path is different.
		bool loadGamePaks = false;
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

	//! Enables/disable keyboard and mouse input to the game.
	virtual void SetGameInputEnabled(bool state) = 0;

	//! Sets the bounds of the game viewport in screen coordinates.
	//! @returns whether they were changed.
	virtual bool SetGameViewportRect(ImGuiID viewportId, Vec2i min, Vec2i max) = 0;

	//! Sets the IGameViewport instance pointer.
	virtual void SetGameViewport(IGameViewport* pVP) = 0;
};
