// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkStatusWellFed
// Header:  Prey/GameDll/ark/player/trauma/ArkStatusWellFed.h
class ArkStatusWellFed : public ArkTraumaBase
{ // Size=296 (0x128)
public:
	ArkStatusWellFed();
	virtual void Update(float _frametime);
	virtual bool IsHarmful() const;
	virtual void RepeatEffect();

	static inline auto FArkStatusWellFedOv2 = PreyFunction<void(ArkStatusWellFed* const _this)>(0x1327EE0);
	static inline auto FUpdate = PreyFunction<void(ArkStatusWellFed* const _this, float _frametime)>(0x1327F60);
	static inline auto FIsHarmful = PreyFunction<bool(const ArkStatusWellFed* const _this)>(0xDD23F0);
	static inline auto FRepeatEffect = PreyFunction<void(ArkStatusWellFed* const _this)>(0x1327F20);
};

