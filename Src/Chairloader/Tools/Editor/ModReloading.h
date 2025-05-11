#pragma once

namespace Internal
{
struct IModDllManager;
}

class ModReloading
{
public:
	ModReloading(std::shared_ptr<Internal::IModDllManager> pModDllManager);

	//! Pre-system update. Mods are being reloaded in here.
	void UpdateBeforeSystem();

	//! Checks if any DLLs changed. If they did, schedules a reload.
	void CheckModulesForChanges();

	//! Schedules a mod reload next frame.
	void ReloadMods();

	//! Reloads the level with saveload right now.
	//! @returns whether it was loaded successfully.
	bool ReloadLevel();

private:
	static constexpr char SAVE_NAME[] = "chaireditor_save";

	std::shared_ptr<Internal::IModDllManager> m_pDllManager = nullptr;
	bool m_bPendingReload = false; //!< Need to reload next frame.

	//! Saves the game, unloads level, reloads mods and reloads save.
	//! @returns whether mods and save reloaded andsuccessfully.
	bool PerformReload();

	bool SaveAndUnloadLevel();
	bool RestoreSavedLevel();
};
