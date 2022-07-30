#pragma once
#include "IChairloader.h"

struct ISystem;
struct IGameFramework;
struct ImGuiContext;

struct IChairloaderMod {
	static constexpr char PROC_INITIALIZE[] = "ClMod_Instantiate";

	~IChairloaderMod() {}

	//! Called during CSystem::Init, before any engine modules.
	virtual void InitSystem(ISystem* pSystem, uintptr_t moduleBase) = 0;
	
	//! Called after CGame::Init
	virtual void InitGame(IGameFramework* pFramework, IChairloader* chairloader) = 0;

	//! Called before CGame::Update to handle any GUI elements
	virtual void Draw(ImGuiContext*) = 0;

	//! Before CGame::Update
	virtual void PreUpdate() = 0;

	//! After CGame::Update
	virtual void PostUpdate() = 0;

	//! Called before CGame::Shutdown.
	virtual void ShutdownGame() = 0;

	//! Called before CSystem::Shutdown.
	virtual void ShutdownSystem() = 0;

	virtual std::string GetModName() = 0;

};


// define this function in the cpp file for your mod
// EXTERN_C DLL_EXPORT IChairloaderMod* ClMod_Instantiate();