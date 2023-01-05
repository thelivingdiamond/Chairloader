// Header file automatically created from a PDB.
#pragma once

// IArkPsiScanningComponentListener
// Header:  Prey/GameDll/ark/player/IArkPsiScanningComponentListener.h
class IArkPsiScanningComponentListener
{ // Size=8 (0x8)
public:
	virtual ~IArkPsiScanningComponentListener();
	virtual void OnLockTargetReticle(const unsigned _id);
	virtual void OnUnlockTargetReticle(const unsigned _id);
	virtual void OnUpdateTargetReticle(const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime);

	static inline auto FOnLockTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener* const _this, const unsigned _id)>(0xA13080);
	static inline auto FOnUnlockTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener* const _this, const unsigned _id)>(0xA13080);
	static inline auto FOnUpdateTargetReticle = PreyFunction<void(IArkPsiScanningComponentListener* const _this, const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime)>(0xA13080);
};

