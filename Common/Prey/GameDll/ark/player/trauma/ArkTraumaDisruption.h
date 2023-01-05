// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaDisruption
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaDisruption.h
class ArkTraumaDisruption : public ArkTraumaBase
{ // Size=296 (0x128)
public:
	ArkTraumaDisruption();
	virtual void Activate(int _level);
	virtual void ReevaluatePhase(bool _bImmediate);
	virtual void PostSerialize();
	virtual void Suspend();
	virtual void Resume();
	virtual bool IsMedical() const;
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	void SetUIStatic(bool _bStatic) const { FSetUIStatic(this, _bStatic); }

	static inline auto FArkTraumaDisruptionOv2 = PreyFunction<void(ArkTraumaDisruption* const _this)>(0x13334A0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaDisruption* const _this, int _level)>(0x13334E0);
	static inline auto FReevaluatePhase = PreyFunction<void(ArkTraumaDisruption* const _this, bool _bImmediate)>(0x13335C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaDisruption* const _this)>(0x1333580);
	static inline auto FSuspend = PreyFunction<void(ArkTraumaDisruption* const _this)>(0x13338C0);
	static inline auto FResume = PreyFunction<void(ArkTraumaDisruption* const _this)>(0x1333680);
	static inline auto FIsMedical = PreyFunction<bool(const ArkTraumaDisruption* const _this)>(0xDD23F0);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaDisruption* const _this, bool _bImmediate, bool _bFromSerialize)>(0x13338F0);
	static inline auto FSetUIStatic = PreyFunction<void(const ArkTraumaDisruption* const _this, bool _bStatic)>(0x13336B0);
};

