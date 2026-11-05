#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/EncounterInfo.h>

struct IEntity;
class XmlNodeRef;

// ArkEncounter
// Header:  Prey/GameDll/ark/npc/ArkEncounter.h
struct ArkEncounter
{ // Size=56 (0x38)
	uint64_t m_EncounterID;
	string m_EncounterName;
	std::vector<EncounterInfo> m_EncounterTable;
	bool m_bIsHighPriority;
	bool m_bActivatedTableEntry;
	int m_LastRequestedSpawnCount;
	bool m_bManagedByActiveProfile;

	ArkEncounter();
	ArkEncounter(const string& encounter_name);
	void Load(const XmlNodeRef& _node) { FLoad(this, _node); }
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void AddEncounterInfoForSpawner(unsigned spawner_id, bool bSpawnFirst, int SpawnChanceWeight, bool bCanRespawn) { FAddEncounterInfoForSpawner(this, spawner_id, bSpawnFirst, SpawnChanceWeight, bCanRespawn); }
	int ActivateRandomSelection(bool bIsInitPopSpawn) { return FActivateRandomSelection(this, bIsInitPopSpawn); }
	void NotifySpawnCountRequested(int spawn_count) { FNotifySpawnCountRequested(this, spawn_count); }
	void NotifyProfileActivated() { FNotifyProfileActivated(this); }
	void NotifyProfileDeactivated() { FNotifyProfileDeactivated(this); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }
	int ActivateEncounterTableEntry(EncounterInfo& table_entry) { return FActivateEncounterTableEntry(this, table_entry); }

#if 0
	void SetEncounterName(const string& _arg0_);
	const string& GetEncounterName() const;
	const std::vector<EncounterInfo>& GetEncounterTable() const;
	const bool GetIsHighPriority() const;
	int ActivateSpawnFirst();
	bool IsEntryValidForSpawning(EncounterInfo& _arg0_, bool _arg1_);
	void SendEncounterEvent(IEntity* _arg0_, const char* _arg1_);
	bool ValidateAndMarkSpawnerID(unsigned _arg0_);
	void RemoveMarkFromSpawner(unsigned _arg0_);
#endif

	static inline auto FArkEncounterOv3 = PreyFunction<void(ArkEncounter* const _this)>(0x13820D0);
	static inline auto FArkEncounterOv2 = PreyFunction<void(ArkEncounter* const _this, const string& encounter_name)>(0x1382090);
	static inline auto FLoad = PreyFunction<void(ArkEncounter* const _this, const XmlNodeRef& _node)>(0x13824E0);
	static inline auto FSerialize = PreyFunction<void(ArkEncounter* const _this, TSerialize& _serialize)>(0x1382840);
	static inline auto FAddEncounterInfoForSpawner = PreyFunction<void(ArkEncounter* const _this, unsigned spawner_id, bool bSpawnFirst, int SpawnChanceWeight, bool bCanRespawn)>(0x13824A0);
	static inline auto FActivateRandomSelection = PreyFunction<int(ArkEncounter* const _this, bool bIsInitPopSpawn)>(0x13823C0);
	static inline auto FNotifySpawnCountRequested = PreyFunction<void(ArkEncounter* const _this, int spawn_count)>(0x1382830);
	static inline auto FNotifyProfileActivated = PreyFunction<void(ArkEncounter* const _this)>(0x1382650);
	static inline auto FNotifyProfileDeactivated = PreyFunction<void(ArkEncounter* const _this)>(0x1382720);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounter* const _this, unsigned spawner_id, bool bActive)>(0x1382B40);
	static inline auto FActivateEncounterTableEntry = PreyFunction<int(ArkEncounter* const _this, EncounterInfo& table_entry)>(0x1382280);
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/EncounterInfo.h>

struct IEntity;
class XmlNodeRef;

// ArkEncounter
// Header:  Prey/GameDll/ark/npc/ArkEncounter.h
struct ArkEncounter
{ // Size=64 (0x40)
	string m_EncounterName;
	string m_ProfileName;
	std::vector<EncounterInfo> m_EncounterTable;
	bool m_bIsHighPriority;
	int m_LastRequestedSpawnCount;
	int m_ActiveSpawnTrack;
	unsigned m_AreaContainerId;
	bool m_bFirstSpawn;
	bool m_bManagedByActiveProfile;

	ArkEncounter();
	ArkEncounter(const string& profile_name, const string& encounter_name);
	void Load(const XmlNodeRef& _node) { FLoad(this, _node); }
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void AddEncounterInfoForSpawner(unsigned spawner_id, int spawn_track, int doomclock_level, int SpawnChanceWeight) { FAddEncounterInfoForSpawner(this, spawner_id, spawn_track, doomclock_level, SpawnChanceWeight); }
	int ActivateRandomSelection() { return FActivateRandomSelection(this); }
	void NotifySpawnCountRequested(int spawn_count) { FNotifySpawnCountRequested(this, spawn_count); }
	void NotifyProfileActivated() { FNotifyProfileActivated(this); }
	void NotifyProfileDeactivated() { FNotifyProfileDeactivated(this); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }
	bool IsPlayerInAreaContainer() const { return FIsPlayerInAreaContainer(this); }
	void RemoveMarkFromSpawner(unsigned spawner_id) { FRemoveMarkFromSpawner(this, spawner_id); }

#if 0
	const string& GetEncounterName() const;
	const string& GetProfileName() const;
	const std::vector<EncounterInfo>& GetEncounterTable() const;
	const bool GetIsHighPriority() const;
	const unsigned GetAreaContainerId() const;
	int ActivateEncounterTableEntry(EncounterInfo& _arg0_);
	bool IsEntryValidForSpawning(EncounterInfo& _arg0_);
	void SendEncounterEvent(IEntity* _arg0_, const char* _arg1_);
	bool ValidateAndMarkSpawnerID(const string& _arg0_, unsigned _arg1_);
#endif

	static inline auto FArkEncounterOv3 = PreyFunction<void(ArkEncounter* const _this)>(0x147F9E0);
	static inline auto FArkEncounterOv2 = PreyFunction<void(ArkEncounter* const _this, const string& profile_name, const string& encounter_name)>(0x147F980);
	static inline auto FLoad = PreyFunction<void(ArkEncounter* const _this, const XmlNodeRef& _node)>(0x147FF90);
	static inline auto FSerialize = PreyFunction<void(ArkEncounter* const _this, TSerialize& _serialize)>(0x14807B0);
	static inline auto FAddEncounterInfoForSpawner = PreyFunction<void(ArkEncounter* const _this, unsigned spawner_id, int spawn_track, int doomclock_level, int SpawnChanceWeight)>(0x147FEB0);
	static inline auto FActivateRandomSelection = PreyFunction<int(ArkEncounter* const _this)>(0x147FBC0);
	static inline auto FNotifySpawnCountRequested = PreyFunction<void(ArkEncounter* const _this, int spawn_count)>(0x14802C0);
	static inline auto FNotifyProfileActivated = PreyFunction<void(ArkEncounter* const _this)>(0x1480150);
	static inline auto FNotifyProfileDeactivated = PreyFunction<void(ArkEncounter* const _this)>(0x1480260);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounter* const _this, unsigned spawner_id, bool bActive)>(0x1480BF0);
	static inline auto FIsPlayerInAreaContainer = PreyFunction<bool(const ArkEncounter* const _this)>(0x147FEF0);
	static inline auto FRemoveMarkFromSpawner = PreyFunction<void(ArkEncounter* const _this, unsigned spawner_id)>(0x14802D0);
};

#endif // !MOONCRASH
