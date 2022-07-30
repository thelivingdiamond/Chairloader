#pragma once
#include <ChairLoader/ModSDK/ChairloaderModBase.h>

class ModMain : public ChairloaderModBase
{
	using BaseClass = ChairloaderModBase;

	//! @returns the name of the mod
	virtual std::string GetModName();

	//! Initializes function hooks before they are installed.
	virtual void InitHooks();

	//! Called during CSystem::Init, before any engine modules.
	//! Call order: TODO
	virtual void InitSystem(ISystem* pSystem, uintptr_t moduleBase);

	//! Called after CGame::Init
	//! Call order: TODO
	virtual void InitGame(IGameFramework* pFramework, IChairloader* chairloader);

	//! Called before CGame::Update to handle any GUI elements
	virtual void Draw(ImGuiContext*);

	//! Before CGame::Update and before any entity updates
	//! Call order: TODO
	virtual void PreUpdate();

	//! After CGame::Update, after entities have been updated and after rendering
	//! commands have been issued. 
	//! Call order: TODO
	virtual void PostUpdate();

	//! Called before CGame::Shutdown.
	//! Call order: TODO
	virtual void ShutdownGame();

	//! Called before CSystem::Shutdown.
	//! Call order: TODO
	virtual void ShutdownSystem();
};

extern ModMain* gMod;
