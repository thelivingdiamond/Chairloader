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

