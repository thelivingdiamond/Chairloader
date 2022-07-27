// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkGameMetricsComponent.h
class ArkGameMetricsComponent // Id=801721E Size=64
{
public:
	struct ArkGameMetricValue // Id=801721F Size=24
	{
		ArkGameMetricProperties const *m_pProperties;
		float m_value;
		uint64_t m_id;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::unordered_map<unsigned __int64,ArkGameMetricsComponent::ArkGameMetricValue> m_gameMetricValues;
	
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetValue(const uint64_t _id, const float _value) { FSetValueOv1(this,_id,_value); }
	void IncrementValue(const uint64_t _id, const float _value) { FIncrementValueOv0(this,_id,_value); }
	void UpdateMaxValue(const uint64_t _id, const float _value) { FUpdateMaxValue(this,_id,_value); }
	std::vector<ArkGameMetricsComponent::ArkGameMetricValue> GetMetrics() const { return FGetMetrics(this); }
	boost::optional<ArkGameMetricProperties const &> GetProperties(const uint64_t _id) const { return FGetProperties(this,_id); }
	
#if 0
	void SetValue(const uint64_t arg0, const int arg1);
	void IncrementValue(const uint64_t arg0);
#endif
	
	static inline auto FReset = PreyFunction<void(ArkGameMetricsComponent *const _this)>(0x1172210);
	static inline auto FSerialize = PreyFunction<void(ArkGameMetricsComponent *const _this, TSerialize _ser)>(0x11723B0);
	static inline auto FSetValueOv1 = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x1172410);
	static inline auto FIncrementValueOv0 = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x1172160);
	static inline auto FUpdateMaxValue = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x11724D0);
	static inline auto FGetMetrics = PreyFunction<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>(ArkGameMetricsComponent const *const _this)>(0x1171FA0);
	static inline auto FGetProperties = PreyFunction<boost::optional<ArkGameMetricProperties const &>(ArkGameMetricsComponent const *const _this, const uint64_t _id)>(0x1172100);
};

