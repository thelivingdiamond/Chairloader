#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkEncounter.h>
#include <ctime>

class XmlNodeRef;

// ArkEncounterProfile
// Header:  Prey/GameDll/ark/npc/ArkEncounterProfile.h
struct ArkEncounterProfile
{ // Size=96 (0x60)
	bool m_bIsActive;
	bool m_bHasEverBeenActivated;
	bool m_bWantsRepopulation;
	bool m_bHasSetRepopTimestamp;
	tm m_TimeWhenRepopulationValid;
	string m_ProfileName;
	std::vector<ArkEncounter> m_Encounters;
	int m_RequestedSpawnCount;
	int m_InitPopulationTarget;
	int m_RepopulationTarget;
	int m_RepopulationThreshold;
	float m_TimeBeforeRepopulation;
	EncounterRepopStrategy m_RepopStrategy;

	ArkEncounterProfile();
	ArkEncounterProfile(const string& name);
	void Load(const XmlNodeRef& _node) { FLoad(this, _node); }
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void Activate() { FActivate(this); }
	void Deactivate() { FDeactivate(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void AddNewEncounter(const string& encounter_name) { FAddNewEncounter(this, encounter_name); }
	ArkEncounter* GetEncounter(const string& encounter_name) { return FGetEncounter(this, encounter_name); }
	void NotifyPopulationChange(int population_count) { FNotifyPopulationChange(this, population_count); }
	void RepopulateToTarget() { FRepopulateToTarget(this); }
	bool IsTimeValidForRepopulation() const { return FIsTimeValidForRepopulation(this); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }
	bool Populate() { return FPopulate(this); }

#if 0
	void SetInitPopulationTarget(int _arg0_);
	int GetInitPopulationTarget() const;
	void SetRepopulationTarget(int _arg0_);
	int GetRepopulationTarget() const;
	void SetRepopulationThreshold(int _arg0_);
	int GetRepopulationThreshold() const;
	int GetRequestedSpawnCount() const;
	bool WantsRepopulation() const;
	bool HasSetRepopTimestamp() const;
	float GetTimeBeforeRepopulation() const;
	const tm& GetTimeOfNextRepopulation() const;
	int64_t TimeRemainingBeforeRepopulation() const;
	bool CanRepopulate() const;
	const string& GetName() const;
	EncounterRepopStrategy GetRepopStrategy() const;
	void DebugPrint() const;
	bool ShouldContinuePopulating(int _arg0_) const;
#endif

	static inline auto FArkEncounterProfileOv3 = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1387060);
	static inline auto FArkEncounterProfileOv2 = PreyFunction<void(ArkEncounterProfile* const _this, const string& name)>(0x1387000);
	static inline auto FLoad = PreyFunction<void(ArkEncounterProfile* const _this, const XmlNodeRef& _node)>(0x1387630);
	static inline auto FSerialize = PreyFunction<void(ArkEncounterProfile* const _this, TSerialize& _serialize)>(0x1387BB0);
	static inline auto FActivate = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1387110);
	static inline auto FDeactivate = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1387510);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkEncounterProfile* const _this)>(0x13877B0);
	static inline auto FAddNewEncounter = PreyFunction<void(ArkEncounterProfile* const _this, const string& encounter_name)>(0x1387490);
	static inline auto FGetEncounter = PreyFunction<ArkEncounter* (ArkEncounterProfile* const _this, const string& encounter_name)>(0x1387550);
	static inline auto FNotifyPopulationChange = PreyFunction<void(ArkEncounterProfile* const _this, int population_count)>(0x1387790);
	static inline auto FRepopulateToTarget = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1387B90);
	static inline auto FIsTimeValidForRepopulation = PreyFunction<bool(const ArkEncounterProfile* const _this)>(0x13875A0);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounterProfile* const _this, unsigned spawner_id, bool bActive)>(0x1387F60);
	static inline auto FPopulate = PreyFunction<bool(ArkEncounterProfile* const _this)>(0x1387810);
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkEncounter.h>

class XmlNodeRef;

// ArkEncounterProfile
// Header:  Prey/GameDll/ark/npc/ArkEncounterProfile.h
struct ArkEncounterProfile
{ // Size=48 (0x30)
	bool m_bIsActive;
	bool m_bHasEverBeenActivated;
	string m_ProfileName;
	std::vector<ArkEncounter> m_Encounters;
	int m_RequestedSpawnCount;
	int m_InitPopulationTarget;

	ArkEncounterProfile();
	ArkEncounterProfile(const string& name);
	void Load(const XmlNodeRef& _node) { FLoad(this, _node); }
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void Activate() { FActivate(this); }
	void Deactivate() { FDeactivate(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void AddNewEncounter(const string& encounter_name) { FAddNewEncounter(this, encounter_name); }
	ArkEncounter* GetEncounter(const string& encounter_name) { return FGetEncounter(this, encounter_name); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }

#if 0
	void SetInitPopulationTarget(int _arg0_);
	int GetInitPopulationTarget() const;
	int GetRequestedSpawnCount() const;
	const string& GetName() const;
	void DebugPrint() const;
	bool Populate();
	bool ShouldContinuePopulating(int _arg0_) const;
#endif

	static inline auto FArkEncounterProfileOv3 = PreyFunction<void(ArkEncounterProfile* const _this)>(0x14851A0);
	static inline auto FArkEncounterProfileOv2 = PreyFunction<void(ArkEncounterProfile* const _this, const string& name)>(0x1485160);
	static inline auto FLoad = PreyFunction<void(ArkEncounterProfile* const _this, const XmlNodeRef& _node)>(0x1485660);
	static inline auto FSerialize = PreyFunction<void(ArkEncounterProfile* const _this, TSerialize& _serialize)>(0x1485760);
	static inline auto FActivate = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1485230);
	static inline auto FDeactivate = PreyFunction<void(ArkEncounterProfile* const _this)>(0x14855D0);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkEncounterProfile* const _this)>(0x1333E90);
	static inline auto FAddNewEncounter = PreyFunction<void(ArkEncounterProfile* const _this, const string& encounter_name)>(0x1485540);
	static inline auto FGetEncounter = PreyFunction<ArkEncounter* (ArkEncounterProfile* const _this, const string& encounter_name)>(0x1485610);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounterProfile* const _this, unsigned spawner_id, bool bActive)>(0x14859D0);
};

#endif // !MOONCRASH
