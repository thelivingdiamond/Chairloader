// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/player/IArkPsiScanningComponentListener.h
class IArkPsiScanningComponentListener // Id=8016E67 Size=8
{
public:
	virtual void OnLockTargetReticle(const unsigned _id);
	virtual void OnUnlockTargetReticle(const unsigned _id);
	virtual void OnUpdateTargetReticle(const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime);
	
	static inline auto FOnLockTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener *const _this, const unsigned _id)>(0xA13080);
	static inline auto FOnUnlockTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener *const _this, const unsigned _id)>(0xA13080);
	static inline auto FOnUpdateTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener *const _this, const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime)>(0xA13080);
};

