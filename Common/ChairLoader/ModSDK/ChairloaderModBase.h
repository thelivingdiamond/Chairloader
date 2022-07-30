#pragma once
#ifdef CHAIRLOADER_MOD_SDK
#include <ChairLoader/IChairloader.h>
#include <ChairLoader/IChairloaderMod.h>
#include <ChairLoader/ChairloaderEnv.h>

class ChairloaderModBase : public IChairloaderMod
{
public:
	//! @returns base address of PreyDll.dll
	inline uintptr_t GetModuleBase() { return m_ModuleBase; }

	//! Initializes function hooks before they are installed.
	virtual void InitHooks() = 0;

	// IChairloaderMod overrides
	virtual void InitSystem(ISystem* pSystem, uintptr_t moduleBase) override;
	virtual void InitGame(IGameFramework* pFramework, IChairloader* chairloader) override;
	virtual void ShutdownGame() override;
	virtual void ShutdownSystem() override;

private:
	uintptr_t m_ModuleBase = 0;
};

extern ChairloaderGlobalEnvironment* gCL;

#endif
