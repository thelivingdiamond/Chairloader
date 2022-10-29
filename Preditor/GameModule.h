#pragma once

struct GameModule : NoCopy
{
	using ProgressCallback = std::function<void(const char* sProgressMsg)>;

	GameModule();
	~GameModule();

	void* hModule = nullptr;
	IGameStartup* pGameStartup = nullptr;

	//! Loads and patches the game DLL.
	void LoadDll();

	//! Initializes the game engine.
	void InitGame(const ProgressCallback& progressCallback);

	//! Shuts down the engine and unloads the DLL.
	void Shutdown();
};
