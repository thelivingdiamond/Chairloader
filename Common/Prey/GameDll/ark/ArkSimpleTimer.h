// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Override
// Prey/GameDll/ark/ArkSimpleTimer.h
class ArkTimeRemaining // Id=80134C3 Size=4
{
public:
	float m_timeRemaining = 0.0f;
	
	ArkTimeRemaining() {}
	ArkTimeRemaining(float _duration) { m_timeRemaining = _duration; }
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuration(float _duration) { FSetDuration(this,_duration); }
	void SetElapsed() { FSetElapsed(this); }
	bool HasElapsed() const { return FHasElapsed(this); }
	bool IsValid() const { return FIsValid(this); }
	void Invalidate() { FInvalidate(this); }
	float GetTimeRemaining() const { return FGetTimeRemaining(this); }
	ArkTimeRemaining &operator*=(float _scalar) { return FoperatorMultEq(this,_scalar); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkTimeRemaining *const _this, float _frameTime)>(0x12589B0);
	static inline auto FSerialize = PreyFunction<void(ArkTimeRemaining *const _this, TSerialize _ser)>(0x12587A0);
	static inline auto FSetDuration = PreyFunction<void(ArkTimeRemaining *const _this, float _duration)>(0x10BE310);
	static inline auto FSetElapsed = PreyFunction<void(ArkTimeRemaining *const _this)>(0x1B216D0);
	static inline auto FHasElapsed = PreyFunction<bool(ArkTimeRemaining const *const _this)>(0x12585F0);
	static inline auto FIsValid = PreyFunction<bool(ArkTimeRemaining const *const _this)>(0x1258620);
	static inline auto FInvalidate = PreyFunction<void(ArkTimeRemaining *const _this)>(0x1258600);
	static inline auto FGetTimeRemaining = PreyFunction<float(ArkTimeRemaining const *const _this)>(0x10BDAB0);
	static inline auto FoperatorMultEq = PreyFunction<ArkTimeRemaining &(ArkTimeRemaining *const _this, float _scalar)>(0x1258590);
};

// Header: Override
// Prey/GameDll/ark/ArkSimpleTimer.h
class ArkSimpleTimer : public ArkTimeRemaining // Id=80134C2 Size=8
{
public:
	float m_duration = 0.0f;
	
	ArkSimpleTimer() : ArkSimpleTimer(0, false) {}

	ArkSimpleTimer(float _duration, bool _bResetTimer) : ArkTimeRemaining(_duration)
	{
		if (!_bResetTimer)
			_duration = std::min(_duration, 0.0f);

		m_duration = _duration;
	}

	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuration(float _duration, bool _bResetTimer = false) { FSetDuration(this,_duration,_bResetTimer); }
	float GetDuration() const { return FGetDuration(this); }
	void ResetTimer() { FResetTimer(this); }
	bool IsTimerReset() const { return FIsTimerReset(this); }
	float GetTimeElapsed() const { return FGetTimeElapsed(this); }
	void SetTimeElapsed(float _elapsed) { FSetTimeElapsed(this,_elapsed); }
	float GetTimeElapsedRatio() const { return FGetTimeElapsedRatio(this); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkSimpleTimer *const _this, float _frameTime)>(0x1258970);
	static inline auto FSerialize = PreyFunction<void(ArkSimpleTimer *const _this, TSerialize _ser)>(0x1258730);
	static inline auto FSetDuration = PreyFunction<void(ArkSimpleTimer *const _this, float _duration, bool _bResetTimer)>(0x1258850);
	static inline auto FGetDuration = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x10BDAA0);
	static inline auto FResetTimer = PreyFunction<void(ArkSimpleTimer *const _this)>(0x1258690);
	static inline auto FIsTimerReset = PreyFunction<bool(ArkSimpleTimer const *const _this)>(0x1258610);
	static inline auto FGetTimeElapsed = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x12585A0);
	static inline auto FSetTimeElapsed = PreyFunction<void(ArkSimpleTimer *const _this, float _elapsed)>(0x1258870);
	static inline auto FGetTimeElapsedRatio = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x12585C0);
};

// Header: FromCpp
// Prey/GameDll/ark/arksimpletimer.h
class ArkAutoResetTimer : public ArkSimpleTimer // Id=80138D6 Size=8
{
public:
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkAutoResetTimer *const _this, float _frameTime)>(0x1258880);
};

// Header: FromCpp
// Prey/GameDll/ark/arksimpletimer.h
class ArkRandomizedTimer : public ArkSimpleTimer // Id=80138D7 Size=12
{
public:
	float m_variation;
	
	ArkRandomizedTimer(const float _duration, const float _variation, const bool _bResetTimer);
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuration(float _duration, bool _bResetTimer) { FSetDuration(this,_duration,_bResetTimer); }
	void ResetTimer() { FResetTimer(this); }
	void SetVariation(float _variation) { FSetVariation(this,_variation); }
	
#if 0
	float GetVariation() const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(ArkRandomizedTimer *const _this, TSerialize _ser)>(0x12586A0);
	static inline auto FSetDuration = PreyFunction<void(ArkRandomizedTimer *const _this, float _duration, bool _bResetTimer)>(0x12587C0);
	static inline auto FResetTimer = PreyFunction<void(ArkRandomizedTimer *const _this)>(0x1258630);
	static inline auto FSetVariation = PreyFunction<void(ArkRandomizedTimer *const _this, float _variation)>(0x12E3170);
};

// Header: FromCpp
// Prey/GameDll/ark/arksimpletimer.h
class ArkRandomizedAutoResetTimer : public ArkRandomizedTimer // Id=80138D8 Size=12
{
public:
	ArkRandomizedAutoResetTimer(const float _duration, const float _variation, const bool _bResetTimer);
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkRandomizedAutoResetTimer *const _this, float _frameTime)>(0x12588D0);
};

// Header: FromCpp
// Prey/GameDll/ark/arksimpletimer.h
struct ArkComplexVisionInput // Id=80195E7 Size=8
{
	unsigned m_entityId;
	float m_magnitude;
	
	ArkComplexVisionInput();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkTimeRemaining
// Header:  Prey/GameDll/ark/ArkSimpleTimer.h
class ArkTimeRemaining
{ // Size=4 (0x4)
public:
	float m_timeRemaining;

	ArkTimeRemaining();
	ArkTimeRemaining(float _duration);
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SetDuration(float _duration) { FSetDuration(this, _duration); }
	void SetElapsed() { FSetElapsed(this); }
	bool HasElapsed() const { return FHasElapsed(this); }
	bool IsValid() const { return FIsValid(this); }
	void Invalidate() { FInvalidate(this); }
	float GetTimeRemaining() const { return FGetTimeRemaining(this); }
	ArkTimeRemaining& operator*=(float _scalar) { return FoperatorMultEq(this, _scalar); }

	static inline auto FArkTimeRemainingOv1 = PreyFunction<void(ArkTimeRemaining* const _this)>(0x1643FB0);
	static inline auto FArkTimeRemainingOv0 = PreyFunction<void(ArkTimeRemaining* const _this, float _duration)>(0x1646AB0);
	static inline auto FUpdate = PreyFunction<bool(ArkTimeRemaining* const _this, float _frameTime)>(0x12FCB30);
	static inline auto FSerialize = PreyFunction<void(ArkTimeRemaining* const _this, TSerialize _ser)>(0x12FC910);
	static inline auto FSetDuration = PreyFunction<void(ArkTimeRemaining* const _this, float _duration)>(0x12FC9E0);
	static inline auto FSetElapsed = PreyFunction<void(ArkTimeRemaining* const _this)>(0x1283CB0);
	static inline auto FHasElapsed = PreyFunction<bool(const ArkTimeRemaining* const _this)>(0x12FC760);
	static inline auto FIsValid = PreyFunction<bool(const ArkTimeRemaining* const _this)>(0x12FC790);
	static inline auto FInvalidate = PreyFunction<void(ArkTimeRemaining* const _this)>(0x12FC770);
	static inline auto FGetTimeRemaining = PreyFunction<float(const ArkTimeRemaining* const _this)>(0x12FC750);
	static inline auto FoperatorMultEq = PreyFunction<ArkTimeRemaining& (ArkTimeRemaining* const _this, float _scalar)>(0x12FC6F0);
};

// ArkSimpleTimer
// Header:  Prey/GameDll/ark/ArkSimpleTimer.h
class ArkSimpleTimer : public ArkTimeRemaining
{ // Size=8 (0x8)
public:
	float m_duration;

	ArkSimpleTimer();
	ArkSimpleTimer(float _duration, bool _bResetTimer);
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SetDuration(float _duration, bool _bResetTimer) { FSetDuration(this, _duration, _bResetTimer); }
	float GetDuration() const { return FGetDuration(this); }
	void ResetTimer() { FResetTimer(this); }
	bool IsTimerReset() const { return FIsTimerReset(this); }
	float GetTimeElapsed() const { return FGetTimeElapsed(this); }
	void SetTimeElapsed(float _elapsed) { FSetTimeElapsed(this, _elapsed); }
	float GetTimeElapsedRatio() const { return FGetTimeElapsedRatio(this); }

	static inline auto FArkSimpleTimerOv1 = PreyFunction<void(ArkSimpleTimer* const _this)>(0x1500AE0);
	static inline auto FArkSimpleTimerOv0 = PreyFunction<void(ArkSimpleTimer* const _this, float _duration, bool _bResetTimer)>(0x12FC6D0);
	static inline auto FUpdate = PreyFunction<bool(ArkSimpleTimer* const _this, float _frameTime)>(0x12FCAF0);
	static inline auto FSerialize = PreyFunction<void(ArkSimpleTimer* const _this, TSerialize _ser)>(0x12FC8A0);
	static inline auto FSetDuration = PreyFunction<void(ArkSimpleTimer* const _this, float _duration, bool _bResetTimer)>(0x12FC9C0);
	static inline auto FGetDuration = PreyFunction<float(const ArkSimpleTimer* const _this)>(0x10ED4E0);
	static inline auto FResetTimer = PreyFunction<void(ArkSimpleTimer* const _this)>(0x12FC800);
	static inline auto FIsTimerReset = PreyFunction<bool(const ArkSimpleTimer* const _this)>(0x12FC780);
	static inline auto FGetTimeElapsed = PreyFunction<float(const ArkSimpleTimer* const _this)>(0x12FC700);
	static inline auto FSetTimeElapsed = PreyFunction<void(ArkSimpleTimer* const _this, float _elapsed)>(0x12FC9F0);
	static inline auto FGetTimeElapsedRatio = PreyFunction<float(const ArkSimpleTimer* const _this)>(0x12FC720);
};

// ArkRandomizedTimer
// Header:  Prey/GameDll/ark/ArkSimpleTimer.h
class ArkRandomizedTimer : public ArkSimpleTimer
{ // Size=12 (0xC)
public:
	float m_variation;

	ArkRandomizedTimer(const float _duration, const float _variation, const bool _bResetTimer);
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SetDuration(float _duration, bool _bResetTimer) { FSetDuration(this, _duration, _bResetTimer); }
	void ResetTimer() { FResetTimer(this); }
	void SetVariation(float _variation) { FSetVariation(this, _variation); }

#if 0
	ArkRandomizedTimer();
	float GetVariation() const;
#endif

	static inline auto FArkRandomizedTimerOv0 = PreyFunction<void(ArkRandomizedTimer* const _this, const float _duration, const float _variation, const bool _bResetTimer)>(0x12FC650);
	static inline auto FSerialize = PreyFunction<void(ArkRandomizedTimer* const _this, TSerialize _ser)>(0x12FC810);
	static inline auto FSetDuration = PreyFunction<void(ArkRandomizedTimer* const _this, float _duration, bool _bResetTimer)>(0x12FC930);
	static inline auto FResetTimer = PreyFunction<void(ArkRandomizedTimer* const _this)>(0x12FC7A0);
	static inline auto FSetVariation = PreyFunction<void(ArkRandomizedTimer* const _this, float _variation)>(0x1396E40);
};

// ArkAutoResetTimer
// Header:  Prey/GameDll/ark/ArkSimpleTimer.h
class ArkAutoResetTimer : public ArkSimpleTimer
{ // Size=8 (0x8)
public:
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	ArkAutoResetTimer();
	ArkAutoResetTimer(const float _arg0_, const bool _arg1_);
#endif

	static inline auto FUpdate = PreyFunction<bool(ArkAutoResetTimer* const _this, float _frameTime)>(0x12FCA00);
};

// ArkRandomizedAutoResetTimer
// Header:  Prey/GameDll/ark/ArkSimpleTimer.h
class ArkRandomizedAutoResetTimer : public ArkRandomizedTimer
{ // Size=12 (0xC)
public:
	ArkRandomizedAutoResetTimer(const float _duration, const float _variation, const bool _bResetTimer);
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	ArkRandomizedAutoResetTimer();
#endif

	static inline auto FArkRandomizedAutoResetTimerOv0 = PreyFunction<void(ArkRandomizedAutoResetTimer* const _this, const float _duration, const float _variation, const bool _bResetTimer)>(0x12FC650);
	static inline auto FUpdate = PreyFunction<bool(ArkRandomizedAutoResetTimer* const _this, float _frameTime)>(0x12FCA50);
};
#endif // !MOONCRASH
