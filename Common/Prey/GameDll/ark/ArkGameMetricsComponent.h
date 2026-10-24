// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/Ark/arkgamemetrics.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkGameMetricsComponent.h
#ifdef MOONCRASH
class ArkGameMetricProperties;
#endif
class ArkGameMetricsComponent // Id=801721E Size=64
{
public:
	struct ArkGameMetricValue // Id=801721F Size=24
	{
		ArkGameMetricProperties const *m_pProperties;
		float m_value;
#ifdef MOONCRASH
		float m_snapshotValue;
#endif
		uint64_t m_id;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
#ifdef MOONCRASH
		float GetCryptoTotalSinceSnapshot() const { return FGetCryptoTotalSinceSnapshot(this); }
		void UpdateValue(float _newValue, bool _bShowOnHUD) { FUpdateValue(this, _newValue, _bShowOnHUD); }
#endif
#ifdef MOONCRASH
		static inline auto FGetCryptoTotalSinceSnapshot = PreyFunction<float(const ArkGameMetricsComponent::ArkGameMetricValue* const _this)>(0x11EB980);
		static inline auto FUpdateValue = PreyFunction<void(ArkGameMetricsComponent::ArkGameMetricValue* const _this, float _newValue, bool _bShowOnHUD)>(0x11EC500);
#endif
	};

	std::unordered_map<unsigned __int64,ArkGameMetricsComponent::ArkGameMetricValue> m_gameMetricValues;
	
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
#ifndef MOONCRASH
	void SetValue(const uint64_t _id, const float _value) { FSetValueOv1(this,_id,_value); }
	void IncrementValue(const uint64_t _id, const float _value) { FIncrementValueOv0(this,_id,_value); }
	void UpdateMaxValue(const uint64_t _id, const float _value) { FUpdateMaxValue(this,_id,_value); }
	std::vector<ArkGameMetricsComponent::ArkGameMetricValue> GetMetrics() const { return FGetMetrics(this); }
	boost::optional<ArkGameMetricProperties const &> GetProperties(const uint64_t _id) const { return FGetProperties(this,_id); }
#else
	void IncrementValue(const uint64_t _id, const float _value, const bool _bShowOnHUD) { FIncrementValueOv0(this, _id, _value, _bShowOnHUD); }
	void UpdateMaxValue(const uint64_t _id, const float _value) { FUpdateMaxValueOv1(this, _id, _value); }
	std::vector<ArkGameMetricsComponent::ArkGameMetricValue> GetMetrics() const { alignas(std::vector<ArkGameMetricsComponent::ArkGameMetricValue>) std::byte _return_buf_[sizeof(std::vector<ArkGameMetricsComponent::ArkGameMetricValue>)]; return *FGetMetrics(this, reinterpret_cast<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>*>(_return_buf_)); }
#endif
	
#if 0
	void SetValue(const uint64_t arg0, const int arg1);
	void IncrementValue(const uint64_t arg0);
#endif
	
#ifdef MOONCRASH
	void ResetSimulation() { FResetSimulation(this); }
	void TakeSnapshot() { FTakeSnapshot(this); }
	float GetCryptoTotalSinceSnapshot() const { return FGetCryptoTotalSinceSnapshot(this); }
#endif
#ifndef MOONCRASH
	static inline auto FReset = PreyFunction<void(ArkGameMetricsComponent *const _this)>(0x1172210);
	static inline auto FSerialize = PreyFunction<void(ArkGameMetricsComponent *const _this, TSerialize _ser)>(0x11723B0);
	static inline auto FSetValueOv1 = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x1172410);
	static inline auto FIncrementValueOv0 = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x1172160);
	static inline auto FUpdateMaxValue = PreyFunction<void(ArkGameMetricsComponent *const _this, const uint64_t _id, const float _value)>(0x11724D0);
	static inline auto FGetMetrics = PreyFunction<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>(ArkGameMetricsComponent const *const _this)>(0x1171FA0);
	static inline auto FGetProperties = PreyFunction<boost::optional<ArkGameMetricProperties const &>(ArkGameMetricsComponent const *const _this, const uint64_t _id)>(0x1172100);
#else
	static inline auto FReset = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC050);
	static inline auto FResetSimulation = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC330);
	static inline auto FSerialize = PreyFunction<void(ArkGameMetricsComponent* const _this, TSerialize _ser)>(0x11EC3B0);
	static inline auto FIncrementValueOv0 = PreyFunction<void(ArkGameMetricsComponent* const _this, const uint64_t _id, const float _value, const bool _bShowOnHUD)>(0x11EBFB0);
	static inline auto FUpdateMaxValueOv1 = PreyFunction<void(ArkGameMetricsComponent* const _this, const uint64_t _id, const float _value)>(0x11EC480);
	static inline auto FGetMetrics = PreyFunction<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>*(const ArkGameMetricsComponent* const _this, std::vector<ArkGameMetricsComponent::ArkGameMetricValue>* _return_value_)>(0x11EBA50);
	static inline auto FTakeSnapshot = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC460);
	static inline auto FGetCryptoTotalSinceSnapshot = PreyFunction<float(const ArkGameMetricsComponent* const _this)>(0x11EB9D0);
#endif
};
