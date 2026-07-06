// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaGlooed
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaGlooed.h
class ArkTraumaGlooed : public ArkTraumaBase
{ // Size=464 (0x1D0)
public:
	ArkEntityPointerEffect m_screenParticle;

	ArkTraumaGlooed();
	virtual void Update(float _frameTime);
	virtual void Accumulate(float _damage);
	virtual void Activate(const int _level);
	virtual void ReduceAccumulation(float _amount, bool _bImmediate);
	virtual void PostSerialize();
	virtual bool IsEnabled() const;
	virtual void CleanUp(bool _bSilent);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);

#if 0
	void UpdateEffectStrength();
#endif

	static inline auto FArkTraumaGlooedOv2 = PreyFunction<void(ArkTraumaGlooed* const _this)>(0x13C9BF0);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaGlooed* const _this, float _frameTime)>(0x13C9EE0);
	static inline auto FAccumulate = PreyFunction<void(ArkTraumaGlooed* const _this, float _damage)>(0x13C9CB0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaGlooed* const _this, const int _level)>(0x13C9CF0);
	static inline auto FReduceAccumulation = PreyFunction<void(ArkTraumaGlooed* const _this, float _amount, bool _bImmediate)>(0x13C9E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaGlooed* const _this)>(0x13C9E40);
	static inline auto FIsEnabled = PreyFunction<bool(const ArkTraumaGlooed* const _this)>(0x13C9DD0);
	static inline auto FCleanUp = PreyFunction<void(ArkTraumaGlooed* const _this, bool _bSilent)>(0x13C9DA0);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaGlooed* const _this, bool _bImmediate, bool _bFromSerialize)>(0x13C9F60);
};
#endif // MOONCRASH
