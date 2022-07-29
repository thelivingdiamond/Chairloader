// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/ArkPsiScanningComponent.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerComponent.h>

class CCryName;

// Header: FromCpp
// Prey/GameDll/ark/player/arkpsicomponent.h
class CArkPsiComponent : private IArkStatsListener // Id=8016E65 Size=1040
{
public:
	ArkPsiPowerComponent m_powerComponent;
	ArkPsiScanningComponent m_scanningComponent;
	float m_points;
	float m_unreducedMaxPoints;
	float m_maxPoints;
	float m_errorMessageDuration;
	
	CArkPsiComponent();
	virtual ~CArkPsiComponent();
	ArkPsiPowerComponent &GetPowerComponent() { return FGetPowerComponentOv1(this); }
	ArkPsiPowerComponent const &GetPowerComponent() const { return FGetPowerComponentOv0(this); }
	ArkPsiScanningComponent &GetScanningComponent() { return FGetScanningComponentOv1(this); }
	ArkPsiScanningComponent const &GetScanningComponent() const { return FGetScanningComponentOv0(this); }
	void SetPoints(const float _points) { FSetPoints(this,_points); }
	void IncrementPoints(const float _points) { FIncrementPoints(this,_points); }
	void ConsumePoints(const float _value) { FConsumePoints(this,_value); }
	bool ConsumePointsOrHealth(const float _value) { return FConsumePointsOrHealth(this,_value); }
	float GetPoints() const { return FGetPoints(this); }
	float GetMaxPoints() const { return FGetMaxPoints(this); }
	float GetUnreducedMaxPoints() const { return FGetUnreducedMaxPoints(this); }
	bool IsPsiMeterVisible() const { return FIsPsiMeterVisible(this); }
	void InitStats() { FInitStats(this); }
	void Update(const float _fDeltaTime) { FUpdate(this,_fDeltaTime); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void Reset() { FReset(this); }
	void Stop() { FStop(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	void PostSerialize() { FPostSerialize(this); }
	void UpdateMeter(int _previewCost) const { FUpdateMeter(this,_previewCost); }
	bool CanConsumePsi() const { return FCanConsumePsi(this); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	
#if 0
	void DisplayError(const char *arg0);
#endif
	
	static inline auto FGetPowerComponentOv1 = PreyFunction<ArkPsiPowerComponent &(CArkPsiComponent *const _this)>(0x5EE7A0);
	static inline auto FGetPowerComponentOv0 = PreyFunction<ArkPsiPowerComponent const &(CArkPsiComponent const *const _this)>(0x5EE7A0);
	static inline auto FGetScanningComponentOv1 = PreyFunction<ArkPsiScanningComponent &(CArkPsiComponent *const _this)>(0x157FF80);
	static inline auto FGetScanningComponentOv0 = PreyFunction<ArkPsiScanningComponent const &(CArkPsiComponent const *const _this)>(0x157FF80);
	static inline auto FSetPoints = PreyFunction<void(CArkPsiComponent *const _this, const float _points)>(0x1580510);
	static inline auto FIncrementPoints = PreyFunction<void(CArkPsiComponent *const _this, const float _points)>(0x157FFD0);
	static inline auto FConsumePoints = PreyFunction<void(CArkPsiComponent *const _this, const float _value)>(0x157FE30);
	static inline auto FConsumePointsOrHealth = PreyFunction<bool(CArkPsiComponent *const _this, const float _value)>(0x157FE50);
	static inline auto FGetPoints = PreyFunction<float(CArkPsiComponent const *const _this)>(0x157FF40);
	static inline auto FGetMaxPoints = PreyFunction<float(CArkPsiComponent const *const _this)>(0x157FF00);
	static inline auto FGetUnreducedMaxPoints = PreyFunction<float(CArkPsiComponent const *const _this)>(0x157FF90);
	static inline auto FIsPsiMeterVisible = PreyFunction<bool(CArkPsiComponent const *const _this)>(0x1580070);
	static inline auto FInitStats = PreyFunction<void(CArkPsiComponent *const _this)>(0x157FFE0);
	static inline auto FUpdate = PreyFunction<void(CArkPsiComponent *const _this, const float _fDeltaTime)>(0x1580610);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(CArkPsiComponent *const _this)>(0x15806F0);
	static inline auto FReset = PreyFunction<void(CArkPsiComponent *const _this)>(0x1580410);
	static inline auto FStop = PreyFunction<void(CArkPsiComponent *const _this)>(0x1580600);
	static inline auto FSerialize = PreyFunction<void(CArkPsiComponent *const _this, TSerialize ser)>(0x1580490);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiComponent *const _this)>(0x1580370);
	static inline auto FUpdateMeter = PreyFunction<void(CArkPsiComponent const *const _this, int _previewCost)>(0x1580720);
	static inline auto FCanConsumePsi = PreyFunction<bool(CArkPsiComponent const *const _this)>(0x157FE00);
	static inline auto FOnStatChange = PreyFunction<void(CArkPsiComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x1580120);
};

