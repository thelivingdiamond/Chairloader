// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/weapons/IArkGlooEffectObserver.h
struct IArkGlooEffectObserver // Id=8014232 Size=8
{
	virtual void OnGlooStart();
	virtual void OnGlooStop();
	virtual void OnGlooFrozen();
	virtual void OnGlooBroken();
	virtual void OnGlooHardenStart();
	
	static inline auto FOnGlooStart = PreyFunction<void(IArkGlooEffectObserver *const _this)>(0xA13080);
	static inline auto FOnGlooStop = PreyFunction<void(IArkGlooEffectObserver *const _this)>(0xA13080);
	static inline auto FOnGlooFrozen = PreyFunction<void(IArkGlooEffectObserver *const _this)>(0xA13080);
	static inline auto FOnGlooBroken = PreyFunction<void(IArkGlooEffectObserver *const _this)>(0xA13080);
	static inline auto FOnGlooHardenStart = PreyFunction<void(IArkGlooEffectObserver *const _this)>(0xA13080);
};

