// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaSuitIntegrity
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaSuitIntegrity.h
class ArkTraumaSuitIntegrity : public ArkTraumaBase
{ // Size=304 (0x130)
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

#if 0
	float GetDamage() const;
#endif

	static inline auto FArkTraumaSuitIntegrityOv2 = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x1333950);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _frameTime)>(0x1333CB0);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _damage)>(0x13339D0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, int _level)>(0x1333A30);
	static inline auto FReduceAccumulation = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _amount, bool _bImmediate)>(0x1333C60);
	static inline auto FReset = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x1333C90);
	static inline auto FIsMedical = PreyFunction<bool(const ArkTraumaSuitIntegrity* const _this)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x1333C40);
	static inline auto FUpdateGlobalFact = PreyFunction<void(const ArkTraumaSuitIntegrity* const _this)>(0x1333CF0);
	static inline auto FUpdateUI = PreyFunction<void(const ArkTraumaSuitIntegrity* const _this)>(0x1333D60);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

class CCryName;

// ArkTraumaSuitIntegrity
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaSuitIntegrity.h
class ArkTraumaSuitIntegrity : public ArkTraumaBase, public IArkStatsListener
{ // Size=344 (0x158)
public:
	float m_prevAccumulation;

	ArkTraumaSuitIntegrity();
	virtual ~ArkTraumaSuitIntegrity();
	virtual void Update(float _frameTime);
	virtual void Accumulate(float _damage);
	virtual void Activate(int _level);
	virtual void ReduceAccumulation(float _amount, bool _bImmediate);
	virtual void Reset();
	virtual bool IsMedical() const;
	virtual void PostSerialize();
	void UpdateGlobalFact() const { FUpdateGlobalFact(this); }
	void UpdateUI() const { FUpdateUI(this); }
	virtual float GetThresholdForLevel(const int _level) const;
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);

#if 0
	float GetDamage() const;
#endif

	static inline auto FArkTraumaSuitIntegrityOv1 = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x140F210);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _frameTime)>(0x140F6B0);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _damage)>(0x140F300);
	static inline auto FActivate = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, int _level)>(0x140F360);
	static inline auto FReduceAccumulation = PreyFunction<void(ArkTraumaSuitIntegrity* const _this, float _amount, bool _bImmediate)>(0x140F660);
	static inline auto FReset = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x140F690);
	static inline auto FIsMedical = PreyFunction<bool(const ArkTraumaSuitIntegrity* const _this)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaSuitIntegrity* const _this)>(0x140F640);
	static inline auto FUpdateGlobalFact = PreyFunction<void(const ArkTraumaSuitIntegrity* const _this)>(0x140F6F0);
	static inline auto FUpdateUI = PreyFunction<void(const ArkTraumaSuitIntegrity* const _this)>(0x140F760);
	static inline auto FGetThresholdForLevel = PreyFunction<float(const ArkTraumaSuitIntegrity* const _this, const int _level)>(0x140F570);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x140F5C0);
};
#endif // !MOONCRASH
