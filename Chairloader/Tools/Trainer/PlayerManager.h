#pragma once
#include <Prey/GameDll/ArkInventory.h>
#include "EntityUtils.h"
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <../Common/ChairLoader/ChairloaderEnv.h>
#include <ChairLoader/IChairloaderGui.h>
//#include "GUIUtils.h"
//#include "OverlayLog.h"
class PlayerManager
{
public:
	struct abilityEntry {
	public:
		uint64_t id;
		std::string name;
		bool acquired = false;
	};
	static bool AbilityEntrySortByName(const abilityEntry& lhs, const abilityEntry& rhs) {
		return lhs.name < rhs.name;
	}

	PlayerManager();

    void draw();
	void drawMenuBar();

	void update();
    void InitGame();
private:
	void drawPositionTab();
	void drawHealthTab();
	void drawAbilitiesTab();
	void drawInventoryTab();

	void loadPosition(int saveSlot);
	void savePosition(int saveSlot, Vec3_tpl<float> pos, Quat rot = Quat(ZERO));

    void checkHotKeys();

	int enablePosHotKeys = false;
    int m_bRestoreRotation = false;
    std::array<ImGuiKey, 5> m_HotKey = { ImGuiKey_Keypad1, ImGuiKey_Keypad2, ImGuiKey_Keypad3, ImGuiKey_Keypad4, ImGuiKey_Keypad5 };
	std::array<Vec3, 5> positions = { Vec3(ZERO), Vec3(ZERO), Vec3(ZERO), Vec3(ZERO), Vec3(ZERO) };
    std::array<Quat, 5> m_rotations = { Quat(ZERO), Quat(ZERO), Quat(ZERO), Quat(ZERO), Quat(ZERO) };


	bool godMode = false;
	const std::string modName = "PlayerManager";
	bool AbilityListInitialized, refreshAbilityList;

    bool showPlayerManager = false;

	std::vector<abilityEntry> abilityDisplayList;
//	std::queue<uint64_t> abilityRequestQueue;
//	std::queue<Vec3_tpl<float>> positionRequestQueue;
	std::map<uint32_t, ArkInventory::StorageCell> inventoryItems;


    //TODO: remove handlers
	// Handlers
//	void checkAbilities(ChairloaderGUILog* log);
//	void abilityRequestHandler(ChairloaderGUILog* log);
};
