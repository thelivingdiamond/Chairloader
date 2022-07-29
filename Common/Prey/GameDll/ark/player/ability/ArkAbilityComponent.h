// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityData.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>

class ArkAbilityData;

// Header: FromCpp
// Prey/GameDll/ark/player/ability/ArkAbilityComponent.h
class ArkAbilityComponent : public IArkPDAListener // Id=8016EA0 Size=72
{
public:
	std::vector<ArkAbilityData> m_abilities;
	std::vector<ArkResearchTopicData> m_researchTopics;
	uint64_t m_lastResearchedAbility;
	int m_partialTyphonThreshold;
	int m_fullTyphonThreshold;
	
	static uint64_t GetCurrencyArchetypeId() { return FGetCurrencyArchetypeId(); }
	ArkAbilityComponent();
	virtual ~ArkAbilityComponent();
	void LoadConfig(XmlNodeRef _node) { FLoadConfig(this,_node); }
	bool HasAbility(uint64_t _id) const { return FHasAbility(this,_id); }
	int GetResearchTopicScanCount(const uint64_t _researchTopicId) const { return FGetResearchTopicScanCount(this,_researchTopicId); }
	int IncrementResearchTopicScanCount(uint64_t _researchId, const int _scanCount, uint64_t &_unlockedAbility, const unsigned _targetEntityId) { return FIncrementResearchTopicScanCountOv1(this,_researchId,_scanCount,_unlockedAbility,_targetEntityId); }
	ArkAbilityUpgradeState GetAbilityState(uint64_t _id) const { return FGetAbilityState(this,_id); }
	bool PurchaseAbility(uint64_t _id) { return FPurchaseAbility(this,_id); }
	bool IsAbilityVisible(uint64_t _id) const { return FIsAbilityVisible(this,_id); }
	bool IsAbilityNameRevealed(uint64_t _id) const { return FIsAbilityNameRevealedOv1(this,_id); }
	bool IsAbilityNameRevealed(ArkAbilityData const &_abilityData) const { return FIsAbilityNameRevealedOv0(this,_abilityData); }
	bool IsAbilityResearched(uint64_t _id) const { return FIsAbilityResearched(this,_id); }
	bool IsAbilityNew(uint64_t _abilityID) const { return FIsAbilityNew(this,_abilityID); }
	int GetNumNeuromodsUsed() const { return FGetNumNeuromodsUsed(this); }
	ArkTyphonStatus GetTyphonStatus() const { return FGetTyphonStatus(this); }
	bool MarkAbilitySeen(uint64_t _abilityID) { return FMarkAbilitySeen(this,_abilityID); }
	float GetPlayerResearchFraction(uint64_t _id) const { return FGetPlayerResearchFraction(this,_id); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ShowLastResearchedAbility() { FShowLastResearchedAbility(this); }
	void OnGrantAbilityCheat(const uint64_t _id, bool _bGrantResearch) { FOnGrantAbilityCheat(this,_id,_bGrantResearch); }
	std::vector<ArkAbilityData const *> GetAcquiredAbilities() const { return FGetAcquiredAbilities(this); }
	virtual void OnPDAOpenComplete();
	void UpdatePlayerMetrics() const { FUpdatePlayerMetrics(this); }
	void GrantAbility(const uint64_t _id) { FGrantAbility(this,_id); }
	void InitAbilityResearchTopicData() { FInitAbilityResearchTopicData(this); }
	
#if 0
	bool IsValidAbility(uint64_t arg0) const;
	int IncrementResearchTopicScanCount(const char *arg0, const int arg1, const unsigned arg2);
	int GetNumAlienAbilitiesAcquired() const;
	int GetAbilityCostToPurchase(const uint64_t arg0) const;
	void OnRevokeAllAbilitiesCheat();
	void UpdatePlayerPhysicsLeverageLevel(const uint64_t arg0) const;
	void DoMetricsSnapshot(XmlNodeRef const &arg0) const;
	boost::optional<ArkAbilityData &> GetAbility(const uint64_t arg0);
	boost::optional<ArkAbilityData const &> GetAbility(const uint64_t arg0) const;
#endif
	
	static inline auto FGetCurrencyArchetypeId = PreyFunction<uint64_t()>(0x153A640);
	static inline auto FBitNotArkAbilityComponent = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153A410);
	static inline auto FLoadConfig = PreyFunction<void(ArkAbilityComponent *const _this, XmlNodeRef _node)>(0x153B5D0);
	static inline auto FHasAbility = PreyFunction<bool(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153AD80);
	static inline auto FGetResearchTopicScanCount = PreyFunction<int(ArkAbilityComponent const *const _this, const uint64_t _researchTopicId)>(0x153A780);
	static inline auto FIncrementResearchTopicScanCountOv1 = PreyFunction<int(ArkAbilityComponent *const _this, uint64_t _researchId, const int _scanCount, uint64_t &_unlockedAbility, const unsigned _targetEntityId)>(0x153ADC0);
	static inline auto FGetAbilityState = PreyFunction<ArkAbilityUpgradeState(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153A480);
	static inline auto FPurchaseAbility = PreyFunction<bool(ArkAbilityComponent *const _this, uint64_t _id)>(0x153BA80);
	static inline auto FIsAbilityVisible = PreyFunction<bool(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153B560);
	static inline auto FIsAbilityNameRevealedOv1 = PreyFunction<bool(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153B430);
	static inline auto FIsAbilityNameRevealedOv0 = PreyFunction<bool(ArkAbilityComponent const *const _this, ArkAbilityData const &_abilityData)>(0x153B360);
	static inline auto FIsAbilityResearched = PreyFunction<bool(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153B4D0);
	static inline auto FIsAbilityNew = PreyFunction<bool(ArkAbilityComponent const *const _this, uint64_t _abilityID)>(0x153B480);
	static inline auto FGetNumNeuromodsUsed = PreyFunction<int(ArkAbilityComponent const *const _this)>(0x153A6C0);
	static inline auto FGetTyphonStatus = PreyFunction<ArkTyphonStatus(ArkAbilityComponent const *const _this)>(0x153A7B0);
	static inline auto FMarkAbilitySeen = PreyFunction<bool(ArkAbilityComponent *const _this, uint64_t _abilityID)>(0x153B630);
	static inline auto FGetPlayerResearchFraction = PreyFunction<float(ArkAbilityComponent const *const _this, uint64_t _id)>(0x153A740);
	static inline auto FReset = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153BD00);
	static inline auto FSerialize = PreyFunction<void(ArkAbilityComponent *const _this, TSerialize _ser)>(0x153C2D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153B9B0);
	static inline auto FShowLastResearchedAbility = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153C340);
	static inline auto FOnGrantAbilityCheat = PreyFunction<void(ArkAbilityComponent *const _this, const uint64_t _id, bool _bGrantResearch)>(0x153B670);
	static inline auto FGetAcquiredAbilities = PreyFunction<std::vector<ArkAbilityData const *>(ArkAbilityComponent const *const _this)>(0x153A5D0);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153B960);
	static inline auto FUpdatePlayerMetrics = PreyFunction<void(ArkAbilityComponent const *const _this)>(0x153C3B0);
	static inline auto FGrantAbility = PreyFunction<void(ArkAbilityComponent *const _this, const uint64_t _id)>(0x153A800);
	static inline auto FInitAbilityResearchTopicData = PreyFunction<void(ArkAbilityComponent *const _this)>(0x153B110);
};

