#pragma once
#include <Chairloader/IChairloaderCore.h>


class ChairImGui;
class LuaModManager;
class ModDllManager;
class ChairloaderConfigManager;
class ChairloaderGui;

class ChairloaderCore : public Internal::IChairloaderCore
{
public:
	ChairloaderCore(std::shared_ptr<IChairloaderConfigManager> configManager,
		std::shared_ptr<Internal::IModDllManager> modDllManager,
		std::shared_ptr<IChairVarManager> cvarManager,
		std::shared_ptr<IChairloaderGui> gui,
		std::shared_ptr<LuaModManager> luaModManager,
		std::shared_ptr<IChairloaderImGui> imgui);

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

	const std::string& GetKeyStrHideGui();
	const std::string& GetKeyStrToggleFreecam();

	//! Toggles the built-in freecam mode when in dev mode.
	void ToggleFreecam();
	bool IsFreecamEnabled();

    EKeyId LoadConfigKey(const std::string& paramName, EKeyId defaultKey = eKI_Unknown) override;
private:
	std::shared_ptr<ChairloaderConfigManager> m_pConfigManager;
	std::shared_ptr<ModDllManager> m_pModDllManager;
    std::shared_ptr<IChairVarManager> m_pCVarManager;
	std::shared_ptr<ChairloaderGui> m_pGui;
	std::shared_ptr<LuaModManager> m_pLuaModManager;
	std::shared_ptr<ChairImGui> m_pImGui;
	std::set<std::string> m_InstalledMods; //!< Set of installed and enabled mods.

	// Keymap
	EKeyId m_KeyHideGui = eKI_Unknown;
	EKeyId m_KeyToggleFreecam = eKI_Unknown;

	void LoadConfig();
	void SkipIntroMovies();
};
