#pragma once
#include <Chairloader/IChairloaderCore.h>

class LuaModManager;
class ModDllManager;
class ChairloaderConfigManager;
class ChairloaderGui;

class ChairloaderCore : public Internal::IChairloaderCore
{
public:
	static ChairloaderCore* Get();

	//-------------------------------------------
	// System initialization
	//-------------------------------------------
	void InitSystem() override;
	void ShutdownSystem() override;
	void RegisterMods() override;

	//-------------------------------------------
	// Game initialization
	//-------------------------------------------
	void PreInitGame() override;
	void InitGame() override;
	void PreShutdown() override;
	void ShutdownGame() override;

	//-------------------------------------------
	// Game update
	//-------------------------------------------
	void UpdateBeforeSystem(unsigned updateFlags) override;
	bool HandleKeyPress(const SInputEvent& event) override;

	Internal::ILogManager* GetLogManager() override;
	Internal::IModDllManager* GetDllManager() override;
	ChairloaderConfigManager* GetConfigManager() { return m_pConfigManager.get(); }

    IChairVarManager *GetCVarManager() override;

	bool IsModInstalled(const std::string& modName) override;
    std::unique_ptr<IChairLogger> CreateLogger() override;

	const std::string& GetKeyStrHideGui();
	const std::string& GetKeyStrToggleFreecam();

	//! Toggles the built-in freecam mode when in dev mode.
	void ToggleFreecam();
	bool IsFreecamEnabled();

    EKeyId LoadConfigKey(const std::string& paramName, EKeyId defaultKey = eKI_Unknown) override;
private:
	std::unique_ptr<ChairloaderConfigManager> m_pConfigManager;
	std::unique_ptr<ModDllManager> m_pModDllManager;
	std::unique_ptr<LuaModManager> m_pLuaModManager;
	std::unique_ptr<ChairloaderGui> m_pGui;
    std::unique_ptr<IChairVarManager> m_pCVarManager;
	std::set<std::string> m_InstalledMods; //!< Set of installed and enabled mods.

	// Keymap
	EKeyId m_KeyHideGui = eKI_Unknown;
	EKeyId m_KeyToggleFreecam = eKI_Unknown;

	void LoadConfig();
	void SkipIntroMovies();
};
