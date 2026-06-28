// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityData.h>

enum class ArkAbilityUpgradeState;
enum class ArkTyphonStatus;
class XmlNodeRef;

// ArkAbilityComponent
// Header:  Prey/GameDll/ark/player/ability/ArkAbilityComponent.h
class ArkAbilityComponent : public IArkPDAListener
{ // Size=72 (0x48)
public:
	std::vector<ArkAbilityData> m_abilities;
	std::vector<ArkResearchTopicData> m_researchTopics;
	uint64_t m_lastResearchedAbility;
	int m_partialTyphonThreshold;
	int m_fullTyphonThreshold;

	static uint64_t GetCurrencyArchetypeId() { return FGetCurrencyArchetypeId(); }
	ArkAbilityComponent();
	virtual ~ArkAbilityComponent();
	void LoadConfig(XmlNodeRef _node) { FLoadConfig(this, _node); }
	bool HasAbility(uint64_t _id) const { return FHasAbility(this, _id); }
	int GetResearchTopicScanCount(const uint64_t _researchTopicId) const { return FGetResearchTopicScanCount(this, _researchTopicId); }
	int IncrementResearchTopicScanCount(uint64_t _researchId, const int _scanCount, uint64_t& _unlockedAbility, const unsigned _targetEntityId) { return FIncrementResearchTopicScanCountOv1(this, _researchId, _scanCount, _unlockedAbility, _targetEntityId); }
	ArkAbilityUpgradeState GetAbilityState(uint64_t _id) const { return FGetAbilityState(this, _id); }
	bool PurchaseAbility(uint64_t _id) { return FPurchaseAbility(this, _id); }
	bool IsAbilityVisible(uint64_t _id) const { return FIsAbilityVisible(this, _id); }
	bool IsAbilityNameRevealed(uint64_t _id) const { return FIsAbilityNameRevealedOv1(this, _id); }
	bool IsAbilityNameRevealed(const ArkAbilityData& _abilityData) const { return FIsAbilityNameRevealedOv0(this, _abilityData); }
	bool IsAbilityResearched(uint64_t _id) const { return FIsAbilityResearched(this, _id); }
	bool IsAbilityNew(uint64_t _abilityID) const { return FIsAbilityNew(this, _abilityID); }
	int GetNumNeuromodsUsed() const { return FGetNumNeuromodsUsed(this); }
	ArkTyphonStatus GetTyphonStatus() const { return FGetTyphonStatus(this); }
	bool MarkAbilitySeen(uint64_t _abilityID) { return FMarkAbilitySeen(this, _abilityID); }
	float GetPlayerResearchFraction(uint64_t _id) const { return FGetPlayerResearchFraction(this, _id); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ShowLastResearchedAbility() { FShowLastResearchedAbility(this); }
	void OnGrantAbilityCheat(const uint64_t _id, bool _bGrantResearch) { FOnGrantAbilityCheat(this, _id, _bGrantResearch); }
	std::vector<const ArkAbilityData*> GetAcquiredAbilities() const { alignas(std::vector<const ArkAbilityData*>) std::byte _return_buf_[sizeof(std::vector<const ArkAbilityData*>)]; return *FGetAcquiredAbilities(this, reinterpret_cast<std::vector<const ArkAbilityData*>*>(_return_buf_)); }
	virtual void OnPDAOpenComplete();
	void UpdatePlayerMetrics() const { FUpdatePlayerMetrics(this); }
	void GrantAbility(const uint64_t _id) { FGrantAbility(this, _id); }
	void InitAbilityResearchTopicData() { FInitAbilityResearchTopicData(this); }

#if 0
	bool IsValidAbility(uint64_t _arg0_) const;
	int IncrementResearchTopicScanCount(const char* _arg0_, const int _arg1_, const unsigned _arg2_);
	int GetNumAlienAbilitiesAcquired() const;
	int GetAbilityCostToPurchase(const uint64_t _arg0_) const;
	void OnRevokeAllAbilitiesCheat();
	void UpdatePlayerPhysicsLeverageLevel(const uint64_t _arg0_) const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
	boost::optional<ArkAbilityData &> GetAbility(const uint64_t _arg0_);
	boost::optional<ArkAbilityData const &> GetAbility(const uint64_t _arg0_) const;
#endif

	static inline auto FGetCurrencyArchetypeId = PreyFunction<uint64_t()>(0x153A640);
	static inline auto FArkAbilityComponentOv1 = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153A390);
	static inline auto FBitNotArkAbilityComponent = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153A410);
	static inline auto FLoadConfig = PreyFunction<void(ArkAbilityComponent* const _this, XmlNodeRef _node)>(0x153B5D0);
	static inline auto FHasAbility = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153AD80);
	static inline auto FGetResearchTopicScanCount = PreyFunction<int(const ArkAbilityComponent* const _this, const uint64_t _researchTopicId)>(0x153A780);
	static inline auto FIncrementResearchTopicScanCountOv1 = PreyFunction<int(ArkAbilityComponent* const _this, uint64_t _researchId, const int _scanCount, uint64_t& _unlockedAbility, const unsigned _targetEntityId)>(0x153ADC0);
	static inline auto FGetAbilityState = PreyFunction<ArkAbilityUpgradeState(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153A480);
	static inline auto FPurchaseAbility = PreyFunction<bool(ArkAbilityComponent* const _this, uint64_t _id)>(0x153BA80);
	static inline auto FIsAbilityVisible = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153B560);
	static inline auto FIsAbilityNameRevealedOv1 = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153B430);
	static inline auto FIsAbilityNameRevealedOv0 = PreyFunction<bool(const ArkAbilityComponent* const _this, const ArkAbilityData& _abilityData)>(0x153B360);
	static inline auto FIsAbilityResearched = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153B4D0);
	static inline auto FIsAbilityNew = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _abilityID)>(0x153B480);
	static inline auto FGetNumNeuromodsUsed = PreyFunction<int(const ArkAbilityComponent* const _this)>(0x153A6C0);
	static inline auto FGetTyphonStatus = PreyFunction<ArkTyphonStatus(const ArkAbilityComponent* const _this)>(0x153A7B0);
	static inline auto FMarkAbilitySeen = PreyFunction<bool(ArkAbilityComponent* const _this, uint64_t _abilityID)>(0x153B630);
	static inline auto FGetPlayerResearchFraction = PreyFunction<float(const ArkAbilityComponent* const _this, uint64_t _id)>(0x153A740);
	static inline auto FReset = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153BD00);
	static inline auto FSerialize = PreyFunction<void(ArkAbilityComponent* const _this, TSerialize _ser)>(0x153C2D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153B9B0);
	static inline auto FShowLastResearchedAbility = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153C340);
	static inline auto FOnGrantAbilityCheat = PreyFunction<void(ArkAbilityComponent* const _this, const uint64_t _id, bool _bGrantResearch)>(0x153B670);
	static inline auto FGetAcquiredAbilities = PreyFunction<std::vector<const ArkAbilityData*>*(const ArkAbilityComponent* const _this, std::vector<const ArkAbilityData*>* _return_value_)>(0x153A5D0);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153B960);
	static inline auto FUpdatePlayerMetrics = PreyFunction<void(const ArkAbilityComponent* const _this)>(0x153C3B0);
	static inline auto FGrantAbility = PreyFunction<void(ArkAbilityComponent* const _this, const uint64_t _id)>(0x153A800);
	static inline auto FInitAbilityResearchTopicData = PreyFunction<void(ArkAbilityComponent* const _this)>(0x153B110);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityData.h>

class ArkAbility;
enum class ArkAbilityUpgradeState;
enum class ArkTyphonStatus;
class XmlNodeRef;

// ArkAbilityComponent
// Header:  Prey/GameDll/ark/player/ability/ArkAbilityComponent.h
class ArkAbilityComponent : public IArkPDAListener
{ // Size=96 (0x60)
public:
	std::vector<ArkAbilityData> m_abilities;
	std::vector<ArkResearchTopicData> m_researchTopics;
	std::vector<uint64_t> m_hiddenAbilities;
	uint64_t m_lastResearchedAbility;
	int m_partialTyphonThreshold;
	int m_fullTyphonThreshold;

	static uint64_t GetCurrencyArchetypeId() { return FGetCurrencyArchetypeId(); }
	ArkAbilityComponent();
	virtual ~ArkAbilityComponent();
	void LoadConfig(XmlNodeRef _node) { FLoadConfig(this, _node); }
	bool HasAbility(uint64_t _id) const { return FHasAbility(this, _id); }
	int GetResearchTopicScanCount(const uint64_t _researchTopicId) const { return FGetResearchTopicScanCount(this, _researchTopicId); }
	int IncrementResearchTopicScanCount(uint64_t _researchId, const int _scanCount, uint64_t& _unlockedAbility, const unsigned _targetEntityId) { return FIncrementResearchTopicScanCountOv1(this, _researchId, _scanCount, _unlockedAbility, _targetEntityId); }
	ArkAbilityUpgradeState GetAbilityState(uint64_t _id) const { return FGetAbilityState(this, _id); }
	bool PurchaseAbility(uint64_t _id) { return FPurchaseAbility(this, _id); }
	bool IsAbilityVisible(uint64_t _id) const { return FIsAbilityVisible(this, _id); }
	bool IsAbilityNameRevealed(uint64_t _id) const { return FIsAbilityNameRevealedOv1(this, _id); }
	bool IsAbilityNameRevealed(const ArkAbilityData& _abilityData) const { return FIsAbilityNameRevealedOv0(this, _abilityData); }
	bool IsAbilityResearched(uint64_t _id) const { return FIsAbilityResearched(this, _id); }
	bool IsAbilityNew(uint64_t _abilityID) const { return FIsAbilityNew(this, _abilityID); }
	int GetNumNeuromodsUsed() const { return FGetNumNeuromodsUsed(this); }
	ArkTyphonStatus GetTyphonStatus() const { return FGetTyphonStatus(this); }
	bool MarkAbilitySeen(uint64_t _abilityID) { return FMarkAbilitySeen(this, _abilityID); }
	float GetPlayerResearchFraction(uint64_t _id) const { return FGetPlayerResearchFraction(this, _id); }
	void Reset(bool _bResetResearch) { FReset(this, _bResetResearch); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ShowLastResearchedAbility() { FShowLastResearchedAbility(this); }
	void GrantPetSummonAbilities() { FGrantPetSummonAbilities(this); }
	void OnGrantAbilityCheat(const uint64_t _id, bool _bGrantResearch) { FOnGrantAbilityCheat(this, _id, _bGrantResearch); }
	std::vector<const ArkAbilityData*> GetAcquiredAbilities() const { alignas(std::vector<const ArkAbilityData*>) std::byte _return_buf_[sizeof(std::vector<const ArkAbilityData*>)]; return *FGetAcquiredAbilities(this, reinterpret_cast<std::vector<const ArkAbilityData*>*>(_return_buf_)); }
	void UnhideAbility(uint64_t _abilityId, bool _bHighlight) { FUnhideAbility(this, _abilityId, _bHighlight); }
	static wstring GetFormattedAbilityDescription(const ArkAbility& _ability, const char* _szDescription) { return FGetFormattedAbilityDescription(_ability, _szDescription); }
	static bool ArePetSummonAbilitiesUnlocked() { return FArePetSummonAbilitiesUnlocked(); }
	virtual void OnPDAOpenComplete();
	void UpdatePlayerMetrics() const { FUpdatePlayerMetrics(this); }
	void GrantAbility(const uint64_t _id) { FGrantAbility(this, _id); }
	void InitAbilityResearchTopicData() { FInitAbilityResearchTopicData(this); }

#if 0
	bool IsValidAbility(uint64_t _arg0_) const;
	int IncrementResearchTopicScanCount(const char* _arg0_, const int _arg1_, const unsigned _arg2_);
	int GetNumAlienAbilitiesAcquired() const;
	int GetAbilityCostToPurchase(const uint64_t _arg0_) const;
	void OnRevokeAbility(const uint64_t _arg0_);
	void OnRevokeAllAbilitiesCheat();
	void UpdatePlayerPhysicsLeverageLevel(const uint64_t _arg0_) const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
	boost::optional<ArkAbilityData &> GetAbility(const uint64_t _arg0_);
	boost::optional<ArkAbilityData const &> GetAbility(const uint64_t _arg0_) const;
#endif

	static inline auto FGetCurrencyArchetypeId = PreyFunction<uint64_t()>(0x165AC10);
	static inline auto FArkAbilityComponentOv1 = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165A430);
	static inline auto FBitNotArkAbilityComponent = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165A590);
	static inline auto FLoadConfig = PreyFunction<void(ArkAbilityComponent* const _this, XmlNodeRef _node)>(0x165C920);
	static inline auto FHasAbility = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165C000);
	static inline auto FGetResearchTopicScanCount = PreyFunction<int(const ArkAbilityComponent* const _this, const uint64_t _researchTopicId)>(0x165B360);
	static inline auto FIncrementResearchTopicScanCountOv1 = PreyFunction<int(ArkAbilityComponent* const _this, uint64_t _researchId, const int _scanCount, uint64_t& _unlockedAbility, const unsigned _targetEntityId)>(0x165C040);
	static inline auto FGetAbilityState = PreyFunction<ArkAbilityUpgradeState(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165AA60);
	static inline auto FPurchaseAbility = PreyFunction<bool(ArkAbilityComponent* const _this, uint64_t _id)>(0x165CE00);
	static inline auto FIsAbilityVisible = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165C880);
	static inline auto FIsAbilityNameRevealedOv1 = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165C750);
	static inline auto FIsAbilityNameRevealedOv0 = PreyFunction<bool(const ArkAbilityComponent* const _this, const ArkAbilityData& _abilityData)>(0x165C650);
	static inline auto FIsAbilityResearched = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165C7F0);
	static inline auto FIsAbilityNew = PreyFunction<bool(const ArkAbilityComponent* const _this, uint64_t _abilityID)>(0x165C7A0);
	static inline auto FGetNumNeuromodsUsed = PreyFunction<int(const ArkAbilityComponent* const _this)>(0x165B1E0);
	static inline auto FGetTyphonStatus = PreyFunction<ArkTyphonStatus(const ArkAbilityComponent* const _this)>(0x165B390);
	static inline auto FMarkAbilitySeen = PreyFunction<bool(ArkAbilityComponent* const _this, uint64_t _abilityID)>(0x165CA90);
	static inline auto FGetPlayerResearchFraction = PreyFunction<float(const ArkAbilityComponent* const _this, uint64_t _id)>(0x165B320);
	static inline auto FReset = PreyFunction<void(ArkAbilityComponent* const _this, bool _bResetResearch)>(0x165D080);
	static inline auto FSerialize = PreyFunction<void(ArkAbilityComponent* const _this, TSerialize _ser)>(0x165D6D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165CD30);
	static inline auto FShowLastResearchedAbility = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165D880);
	static inline auto FGrantPetSummonAbilities = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165B9E0);
	static inline auto FOnGrantAbilityCheat = PreyFunction<void(ArkAbilityComponent* const _this, const uint64_t _id, bool _bGrantResearch)>(0x165CAD0);
	static inline auto FGetAcquiredAbilities = PreyFunction<std::vector<const ArkAbilityData*>*(const ArkAbilityComponent* const _this, std::vector<const ArkAbilityData*>* _return_value_)>(0x165ABA0);
	static inline auto FUnhideAbility = PreyFunction<void(ArkAbilityComponent* const _this, uint64_t _abilityId, bool _bHighlight)>(0x165D8F0);
	static inline auto FGetFormattedAbilityDescription = PreyFunction<wstring(const ArkAbility& _ability, const char* _szDescription)>(0x165AC90);
	static inline auto FArePetSummonAbilitiesUnlocked = PreyFunction<bool()>(0x165A920);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165CCE0);
	static inline auto FUpdatePlayerMetrics = PreyFunction<void(const ArkAbilityComponent* const _this)>(0x165D960);
	static inline auto FGrantAbility = PreyFunction<void(ArkAbilityComponent* const _this, const uint64_t _id)>(0x165B3E0);
	static inline auto FInitAbilityResearchTopicData = PreyFunction<void(ArkAbilityComponent* const _this)>(0x165C400);
};
#endif // !MOONCRASH
