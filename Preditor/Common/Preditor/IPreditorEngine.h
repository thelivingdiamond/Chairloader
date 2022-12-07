#pragma once

struct IGameStartup;

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

		//! Path to the GameSDK directory to use. May be different from the game's directory.
		fs::path gameSdkPath;

		//! Path to the user directory to store user-specific files.
		fs::path userPath;

		//! Path to the directory to store Chairloader configs.
		fs::path chairloaderConfigPath;

		//! Initialize bare minimum to get ICryPak.
		bool minimal = false;

		//! Load PAKs from the original GameSDK.
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
};
