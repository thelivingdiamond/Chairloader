#pragma once
#include "pch.h"

#include <Prey/ArkBasicTypes.h>
#include "EntityUtils.h"
#include "preyDllObjects.h"
#include <Prey/ArkEntityArchetypeLibrary.h>
#include "GUIUtils.h"
#include "OverlayLog.h"
class ChairloaderGUIPlayerManager
{
public:
	struct abilityEntry {
	public:
		uint64_t id;
		std::string name;
		bool acquired{ false };
	};
	static bool AbilityEntrySortByName(const abilityEntry& lhs, const abilityEntry& rhs) {
		return lhs.name < rhs.name;
	}
	ChairloaderGUIPlayerManager() = default;
	void draw(bool* bshow);
	void drawMenuBar(bool* control);

	void update(ChairloaderGUILog* log);
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
	std::vector<abilityEntry> abilityDisplayList;
	std::queue<uint64_t> abilityRequestQueue;
	std::queue<Vec3_tpl<float>> positionRequestQueue;
	std::map<uint32_t, ArkInventory::StorageCell> inventoryItems;

	// Handlers
	void checkAbilities(ChairloaderGUILog* log);
	void abilityRequestHandler(ChairloaderGUILog* log);
};