#include "../Common/ChairLoader/pch.h"
#if 0
class PlayerManager {
public:
    void draw() {};
    void drawMenuBar() {};
    void update() {};
};
#endif

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

	PlayerManager() {}

    void draw();
	void drawMenuBar();

	void update();
private:
	void drawPositionTab();
	void drawHealthTab();
	void drawAbilitiesTab();
	void drawInventoryTab();

	void loadPosition(int saveSlot);
	void savePosition(int saveSlot, Vec3_tpl<float> pos);

	bool enablePosHotKeys = false;
	std::vector<Vec3_tpl<float>> positions = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };


	bool godMode;
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
