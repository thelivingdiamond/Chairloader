// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/Ark/arkgamemetrics.h>

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkGameMetricProperties;

// ArkGameMetricsComponent
// Header:  Prey/GameDll/ark/ArkGameMetricsComponent.h
class ArkGameMetricsComponent
{ // Size=64 (0x40)
public:
	// ArkGameMetricsComponent::ArkGameMetricValue
	// Header:  Prey/GameDll/ark/ArkGameMetricsComponent.h
	struct ArkGameMetricValue
	{ // Size=24 (0x18)
		const ArkGameMetricProperties* m_pProperties;
		float m_value;
		float m_snapshotValue;
		uint64_t m_id;

		float GetCryptoTotalSinceSnapshot() const { return FGetCryptoTotalSinceSnapshot(this); }
		void UpdateValue(float _newValue, bool _bShowOnHUD) { FUpdateValue(this, _newValue, _bShowOnHUD); }

	#if 0
		ArkGameMetricValue();
		ArkGameMetricValue(const ArkGameMetricProperties& _arg0_);
		void Serialize(TSerialize _arg0_);
		void Snapshot();
		float GetSnapshotValue() const;
		bool ResetSimulation();
	#endif

		static inline auto FGetCryptoTotalSinceSnapshot = PreyFunction<float(const ArkGameMetricsComponent::ArkGameMetricValue* const _this)>(0x11EB980);
		static inline auto FUpdateValue = PreyFunction<void(ArkGameMetricsComponent::ArkGameMetricValue* const _this, float _newValue, bool _bShowOnHUD)>(0x11EC500);
	};

	std::unordered_map<uint64_t, ArkGameMetricsComponent::ArkGameMetricValue> m_gameMetricValues;

	void Reset() { FReset(this); }
	void ResetSimulation() { FResetSimulation(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void IncrementValue(const uint64_t _id, const float _value, const bool _bShowOnHUD) { FIncrementValueOv0(this, _id, _value, _bShowOnHUD); }
	void UpdateMaxValue(const uint64_t _id, const float _value) { FUpdateMaxValueOv1(this, _id, _value); }
	std::vector<ArkGameMetricsComponent::ArkGameMetricValue> GetMetrics() const { alignas(std::vector<ArkGameMetricsComponent::ArkGameMetricValue>) std::byte _return_buf_[sizeof(std::vector<ArkGameMetricsComponent::ArkGameMetricValue>)]; return *FGetMetrics(this, reinterpret_cast<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>*>(_return_buf_)); }
	void TakeSnapshot() { FTakeSnapshot(this); }
	float GetCryptoTotalSinceSnapshot() const { return FGetCryptoTotalSinceSnapshot(this); }

#if 0
	void SetValue(const uint64_t _arg0_, const float _arg1_);
	void SetValue(const uint64_t _arg0_, const int _arg1_);
	void IncrementValue(const uint64_t _arg0_);
	void UpdateMaxValue(const uint64_t _arg0_, const int _arg1_);
	boost::optional<ArkGameMetricProperties const &> GetProperties(const uint64_t _arg0_) const;
#endif

	static inline auto FReset = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC050);
	static inline auto FResetSimulation = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC330);
	static inline auto FSerialize = PreyFunction<void(ArkGameMetricsComponent* const _this, TSerialize _ser)>(0x11EC3B0);
	static inline auto FIncrementValueOv0 = PreyFunction<void(ArkGameMetricsComponent* const _this, const uint64_t _id, const float _value, const bool _bShowOnHUD)>(0x11EBFB0);
	static inline auto FUpdateMaxValueOv1 = PreyFunction<void(ArkGameMetricsComponent* const _this, const uint64_t _id, const float _value)>(0x11EC480);
	static inline auto FGetMetrics = PreyFunction<std::vector<ArkGameMetricsComponent::ArkGameMetricValue>*(const ArkGameMetricsComponent* const _this, std::vector<ArkGameMetricsComponent::ArkGameMetricValue>* _return_value_)>(0x11EBA50);
	static inline auto FTakeSnapshot = PreyFunction<void(ArkGameMetricsComponent* const _this)>(0x11EC460);
	static inline auto FGetCryptoTotalSinceSnapshot = PreyFunction<float(const ArkGameMetricsComponent* const _this)>(0x11EB9D0);
};
#endif // !MOONCRASH
