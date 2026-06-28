// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
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
#endif // MOONCRASH
