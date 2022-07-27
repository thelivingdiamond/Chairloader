// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaSuitIntegrity.h
class ArkTraumaSuitIntegrity : public ArkTraumaBase // Id=801B89D Size=304
{
public:
	float m_prevAccumulation;
	
	ArkTraumaSuitIntegrity();
	virtual void Update(float _frameTime);
	virtual void Accumulate(float _damage);
	virtual void Activate(int _level);
	virtual void ReduceAccumulation(float _amount, bool _bImmediate);
	virtual void Reset();
	virtual bool IsMedical() const;
	virtual void PostSerialize();
	void UpdateGlobalFact() const { FUpdateGlobalFact(this); }
	void UpdateUI() const { FUpdateUI(this); }
	virtual ~ArkTraumaSuitIntegrity();
	
#if 0
	float GetDamage() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkTraumaSuitIntegrity *const _this, float _frameTime)>(0x1333CB0);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaSuitIntegrity *const _this, float _damage)>(0x13339D0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaSuitIntegrity *const _this, int _level)>(0x1333A30);
	static inline auto FReduceAccumulation = PreyFunction<void(ArkTraumaSuitIntegrity *const _this, float _amount, bool _bImmediate)>(0x1333C60);
	static inline auto FReset = PreyFunction<void(ArkTraumaSuitIntegrity *const _this)>(0x1333C90);
	static inline auto FIsMedical = PreyFunction<bool(ArkTraumaSuitIntegrity const *const _this)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaSuitIntegrity *const _this)>(0x1333C40);
	static inline auto FUpdateGlobalFact = PreyFunction<void(ArkTraumaSuitIntegrity const *const _this)>(0x1333CF0);
	static inline auto FUpdateUI = PreyFunction<void(ArkTraumaSuitIntegrity const *const _this)>(0x1333D60);
};

