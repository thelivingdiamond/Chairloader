// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/arksimplecharge.h
class ArkChargeAmount // Id=80160C2 Size=8
{
public:
	float m_amount;
	float m_maxAmount;
	
	ArkChargeAmount(float _maxAmount, bool _bCharged);
	bool Charge(float _amount) { return FCharge(this,_amount); }
	bool Adjust(float _amount) { return FAdjust(this,_amount); }
	void SetMaxAmount(float _maxAmount, bool _bMaintainRatio) { FSetMaxAmount(this,_maxAmount,_bMaintainRatio); }
	float GetChargedRatio() const { return FGetChargedRatio(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	bool Drain(float arg0);
	float GetAmount() const;
	float GetAmountMissing() const;
	float GetMaxAmount() const;
	bool IsDrained() const;
	bool IsCharged() const;
	bool IsValid() const;
	void Invalidate();
	void SetDrained();
	void SetCharged();
#endif
	
	static inline auto FCharge = PreyFunction<bool(ArkChargeAmount *const _this, float _amount)>(0x11AF410);
	static inline auto FAdjust = PreyFunction<bool(ArkChargeAmount *const _this, float _amount)>(0x11AF3D0);
	static inline auto FSetMaxAmount = PreyFunction<void(ArkChargeAmount *const _this, float _maxAmount, bool _bMaintainRatio)>(0x11AF560);
	static inline auto FGetChargedRatio = PreyFunction<float(ArkChargeAmount const *const _this)>(0x11AF430);
	static inline auto FSerialize = PreyFunction<void(ArkChargeAmount *const _this, TSerialize _ser)>(0x11AF460);
};

// Header: FromCpp
// Prey/GameDll/ark/ArkSimpleCharge.h
class ArkSimpleCharge : public ArkChargeAmount // Id=80160C1 Size=20
{
public:
	bool m_bCharging;
	float m_chargeRate;
	float m_drainRate;
	
	ArkSimpleCharge(float _maxAmount, bool _bCharged, float _chargeRate, float _drainRate);
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	void SetCharging(bool arg0);
	void SetChargeRate(float arg0);
	void SetDrainRate(float arg0);
	bool IsCharging() const;
	float GetChargeRate() const;
	float GetDrainRate() const;
#endif
	
	static inline auto FUpdate = PreyFunction<bool(ArkSimpleCharge *const _this, float _frameTime)>(0x11AF5B0);
	static inline auto FSerialize = PreyFunction<void(ArkSimpleCharge *const _this, TSerialize _ser)>(0x11AF4B0);
};

