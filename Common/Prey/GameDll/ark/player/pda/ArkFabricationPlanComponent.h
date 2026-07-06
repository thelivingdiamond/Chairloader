// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkFabricationPlanComponent
// Header:  Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h
class ArkFabricationPlanComponent
{ // Size=24 (0x18)
public:
	// ArkFabricationPlanComponent::Data
	// Header:  Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h
	struct Data
	{ // Size=40 (0x28)
		uint64_t m_id;
		bool m_bNew;
		int m_count;
		bool m_bErrorSet;
		string m_errorHeading;
		string m_errorBody;

	#if 0
		Data();
		Data(const uint64_t _arg0_, const int _arg1_);
		bool operator==(const uint64_t _arg0_) const;
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::vector<ArkFabricationPlanComponent::Data> m_plans;

	bool UsePlan(const uint64_t _id) { return FUsePlan(this, _id); }
	bool MarkAsSeen(const uint64_t _id) { return FMarkAsSeen(this, _id); }
	const ArkFabricationPlanComponent::Data* GetPlan(const uint64_t _id) const { return FGetPlan(this, _id); }
	void IncrementPlanCount(const uint64_t _id, const int _count, const bool _bUnlimited) { FIncrementPlanCount(this, _id, _count, _bUnlimited); }
	void SetError(const uint64_t _id, const string& _heading, const string& _body) { FSetError(this, _id, _heading, _body); }
	void ClearError(const uint64_t _id) { FClearError(this, _id); }

#if 0
	void Reset();
	void CollectAll();
	const std::vector<ArkFabricationPlanComponent::Data>& GetPlans() const;
	void Serialize(TSerialize _arg0_);
#endif

	static inline auto FUsePlan = PreyFunction<bool(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x15B4360);
	static inline auto FMarkAsSeen = PreyFunction<bool(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x15B4230);
	static inline auto FGetPlan = PreyFunction<const ArkFabricationPlanComponent::Data* (const ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x15B4060);
	static inline auto FIncrementPlanCount = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id, const int _count, const bool _bUnlimited)>(0x15B4090);
	static inline auto FSetError = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id, const string& _heading, const string& _body)>(0x15B4270);
	static inline auto FClearError = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x15B3FB0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class ArkFabricationPlan;

// ArkFabricationPlanComponent
// Header:  Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h
class ArkFabricationPlanComponent
{ // Size=40 (0x28)
public:
	// ArkFabricationPlanComponent::Data
	// Header:  Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h
	struct Data
	{ // Size=40 (0x28)
		uint64_t m_id;
		bool m_bNew;
		bool m_bReadyRoomNew;
		int m_timesFabricated;
		bool m_bErrorSet;
		string m_errorHeading;
		string m_errorBody;

	#if 0
		Data();
		Data(const uint64_t _arg0_);
		bool operator==(const uint64_t _arg0_) const;
		void Serialize(TSerialize _arg0_);
	#endif
	};

	uint64_t m_reverseEngineeredPlan;
	int m_timesReverseEngineeredPlanFabricated;
	bool m_bReverseEngineeredPlanReadyRoomNew;
	std::vector<ArkFabricationPlanComponent::Data> m_plans;

	void Reset() { FReset(this); }
	bool UsePlan(const uint64_t _id) { return FUsePlan(this, _id); }
	bool MarkAsSeen(const uint64_t _id) { return FMarkAsSeen(this, _id); }
	void MarkPlanAsSeenInReadyRoom(const uint64_t _id) { FMarkPlanAsSeenInReadyRoom(this, _id); }
	const ArkFabricationPlanComponent::Data* GetPlan(const uint64_t _id) const { return FGetPlan(this, _id); }
	void CollectPlan(const uint64_t _id, bool _bSilent) { FCollectPlan(this, _id, _bSilent); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetError(const uint64_t _id, const string& _heading, const string& _body) { FSetError(this, _id, _heading, _body); }
	void ClearError(const uint64_t _id) { FClearError(this, _id); }
	void GrantReverseEngineeredPlan(const uint64_t _id) { FGrantReverseEngineeredPlan(this, _id); }
	bool HasPlan(const uint64_t _id) const { return FHasPlan(this, _id); }
	static uint64_t FindMatchingFabPlan(uint64_t _archetype, IArkItem::EArkQualityTier _quality) { return FFindMatchingFabPlan(_archetype, _quality); }
	static wstring GetLabelWithQuality(const ArkFabricationPlan* _pPlanData) { return FGetLabelWithQuality(_pPlanData); }

#if 0
	ArkFabricationPlanComponent();
	void CollectAll();
	const std::vector<ArkFabricationPlanComponent::Data>& GetPlans() const;
	uint64_t GetReverseEngineeredPlan() const;
	int GetTimesReverseEngineeredPlanFabricated() const;
	bool IsReverseEngineeredPlanReadyRoomNew() const;
#endif

	static inline auto FReset = PreyFunction<void(ArkFabricationPlanComponent* const _this)>(0x16D9670);
	static inline auto FUsePlan = PreyFunction<bool(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D9AC0);
	static inline auto FMarkAsSeen = PreyFunction<bool(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D9580);
	static inline auto FMarkPlanAsSeenInReadyRoom = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D95C0);
	static inline auto FGetPlan = PreyFunction<const ArkFabricationPlanComponent::Data* (const ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D9470);
	static inline auto FCollectPlan = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id, bool _bSilent)>(0x16D9100);
	static inline auto FSerialize = PreyFunction<void(ArkFabricationPlanComponent* const _this, TSerialize _ser)>(0x16D9950);
	static inline auto FPostSerialize = PreyFunction<void(ArkFabricationPlanComponent* const _this)>(0x16D9600);
	static inline auto FSetError = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id, const string& _heading, const string& _body)>(0x16D99C0);
	static inline auto FClearError = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D9050);
	static inline auto FGrantReverseEngineeredPlan = PreyFunction<void(ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D94A0);
	static inline auto FHasPlan = PreyFunction<bool(const ArkFabricationPlanComponent* const _this, const uint64_t _id)>(0x16D9540);
	static inline auto FFindMatchingFabPlan = PreyFunction<uint64_t(uint64_t _archetype, IArkItem::EArkQualityTier _quality)>(0x16D9300);
	static inline auto FGetLabelWithQuality = PreyFunction<wstring(const ArkFabricationPlan* _pPlanData)>(0x16D9390);
};
#endif // !MOONCRASH
