// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityScanData.h>

class ArkResearchTopicData;

// ArkAbilityData
// Header:  Prey/GameDll/ark/player/ability/ArkAbilityData.h
class ArkAbilityData
{ // Size=112 (0x70)
public:
	using Modifiers = std::vector<unsigned int>;
	using Abilities = std::vector<ArkAbilityData*>;
	using ResearchTopics = std::vector<ArkResearchTopicData*>;

	std::vector<ArkAbilityData*> m_prereqs;
	std::vector<ArkAbilityData*> m_children;
	std::vector<ArkResearchTopicData*> m_researchTopicData;
	std::vector<unsigned int> m_modifiers;
	uint64_t m_id;
	bool m_bSeen;
	bool m_bAcquired;

	bool HasAcquiredPrereqs() const { return FHasAcquiredPrereqs(this); }
	void AddPrereq(ArkAbilityData* _pAbility) { FAddPrereq(this, _pAbility); }
	void AddResearchTopic(ArkResearchTopicData* _pResearchTopic) { FAddResearchTopic(this, _pResearchTopic); }
	float GetResearchFraction() const { return FGetResearchFraction(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	ArkAbilityData();
	ArkAbilityData(const uint64_t _arg0_);
	uint64_t GetId() const;
	bool GetIsSeen() const;
	bool GetIsAcquired() const;
	void SetIsSeen(const bool _arg0_);
	void SetIsAcquired(const bool _arg0_);
	void AddModifer(const unsigned _arg0_);
	const std::vector<unsigned int>& GetModifiers() const;
	const std::vector<ArkAbilityData*>& GetPrereqs() const;
	const std::vector<ArkAbilityData*>& GetChildren() const;
	const std::vector<ArkResearchTopicData*>& GetResearchTopics() const;
#endif

	static inline auto FHasAcquiredPrereqs = PreyFunction<bool(const ArkAbilityData* const _this)>(0x145B7F0);
	static inline auto FAddPrereq = PreyFunction<void(ArkAbilityData* const _this, ArkAbilityData* _pAbility)>(0x145B680);
	static inline auto FAddResearchTopic = PreyFunction<void(ArkAbilityData* const _this, ArkResearchTopicData* _pResearchTopic)>(0x145B700);
	static inline auto FGetResearchFraction = PreyFunction<float(const ArkAbilityData* const _this)>(0x145B750);
	static inline auto FSerialize = PreyFunction<void(ArkAbilityData* const _this, TSerialize _ser)>(0x145B840);
};

// ArkResearchTopicData
// Header:  Prey/GameDll/ark/player/ability/ArkAbilityData.h
class ArkResearchTopicData
{ // Size=40 (0x28)
public:
	using AbilityScanData = std::vector<ArkAbilityScanData>;

	std::vector<ArkAbilityScanData> m_abilityScanData;
	uint64_t m_id;
	int m_scanCount;
	int m_loreScansRequired;

	void IncrementScanCount(const int _scanCount) { FIncrementScanCount(this, _scanCount); }
	void AddAbilityScanData(ArkAbilityData* _pAbilityData, const int _requiredScanCount) { FAddAbilityScanData(this, _pAbilityData, _requiredScanCount); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	ArkResearchTopicData();
	ArkResearchTopicData(const uint64_t _arg0_, const int _arg1_);
	uint64_t GetId() const;
	int GetScanCount() const;
	float GetScanRatio(uint64_t _arg0_) const;
	bool IsLoreUnlocked() const;
	const std::vector<ArkAbilityScanData>& GetAbilityScanData() const;
#endif

	static inline auto FIncrementScanCount = PreyFunction<void(ArkResearchTopicData* const _this, const int _scanCount)>(0x145B820);
	static inline auto FAddAbilityScanData = PreyFunction<void(ArkResearchTopicData* const _this, ArkAbilityData* _pAbilityData, const int _requiredScanCount)>(0x145B650);
	static inline auto FSerialize = PreyFunction<void(ArkResearchTopicData* const _this, TSerialize _ser)>(0x145BA00);
};

