// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h
class ArkFabricationPlanComponent // Id=8017149 Size=24
{
public:
	struct Data // Id=801714A Size=40
	{
		uint64_t m_id;
		bool m_bNew;
		int m_count;
		bool m_bErrorSet;
		string m_errorHeading;
		string m_errorBody;
		
#if 0
		bool operator==(const uint64_t arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkFabricationPlanComponent::Data> m_plans;
	
	bool UsePlan(const uint64_t _id) { return FUsePlan(this,_id); }
	bool MarkAsSeen(const uint64_t _id) { return FMarkAsSeen(this,_id); }
	ArkFabricationPlanComponent::Data const *GetPlan(const uint64_t _id) const { return FGetPlan(this,_id); }
	void IncrementPlanCount(const uint64_t _id, const int _count, const bool _bUnlimited) { FIncrementPlanCount(this,_id,_count,_bUnlimited); }
	void SetError(const uint64_t _id, string const &_heading, string const &_body) { FSetError(this,_id,_heading,_body); }
	void ClearError(const uint64_t _id) { FClearError(this,_id); }
	
#if 0
	void Reset();
	void CollectAll();
	std::vector<ArkFabricationPlanComponent::Data> const &GetPlans() const;
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FUsePlan = PreyFunction<bool(ArkFabricationPlanComponent *const _this, const uint64_t _id)>(0x15B4360);
	static inline auto FMarkAsSeen = PreyFunction<bool(ArkFabricationPlanComponent *const _this, const uint64_t _id)>(0x15B4230);
	static inline auto FGetPlan = PreyFunction<ArkFabricationPlanComponent::Data const *(ArkFabricationPlanComponent const *const _this, const uint64_t _id)>(0x15B4060);
	static inline auto FIncrementPlanCount = PreyFunction<void(ArkFabricationPlanComponent *const _this, const uint64_t _id, const int _count, const bool _bUnlimited)>(0x15B4090);
	static inline auto FSetError = PreyFunction<void(ArkFabricationPlanComponent *const _this, const uint64_t _id, string const &_heading, string const &_body)>(0x15B4270);
	static inline auto FClearError = PreyFunction<void(ArkFabricationPlanComponent *const _this, const uint64_t _id)>(0x15B3FB0);
};

