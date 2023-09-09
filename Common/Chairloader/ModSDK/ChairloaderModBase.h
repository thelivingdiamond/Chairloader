#pragma once
#ifdef CHAIRLOADER_MOD_SDK
#include <Chairloader/IChairloader.h>
#include <Chairloader/IChairloaderMod.h>
#include <Chairloader/ChairloaderEnv.h>

class ChairloaderModBase : public IChairloaderMod
{
public:
	struct ModDllInfoEx : ModDllInfo
	{
		//! Name of the mod without author for the logger.
		const char* logTag = nullptr;
	};

	//! @returns base address of PreyDll.dll
	uintptr_t GetModuleBase() { return m_ModuleBase; }

	//! @returns the path to the directory in "Mods"
	const fs::path& GetModDirectory() { return m_ModDirPath; }

	//! @returns the path to the mod's DLL.
	const fs::path& GetModDLLPath() { return m_ModDllPath; }

	//! Fills in the DLL info during initialization.
	virtual void FillModInfo(ModDllInfoEx& info) = 0;

	//! Initializes function hooks before they are installed.
	virtual void InitHooks() = 0;

	// IChairloaderMod overrides
	virtual void GetModSdkVersion(SemanticVersion &version) override;
	virtual void InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo) override;
	virtual void InitGame(bool isHotReloading) override;
	virtual void ShutdownGame(bool isHotUnloading) override;
	virtual void ShutdownSystem(bool isHotUnloading) override;


private:
	uintptr_t m_ModuleBase = 0;
	fs::path m_ModDirPath;
	fs::path m_ModDllPath;

	void InitImGui();
	void ShutdownImGui();
};

#endif
