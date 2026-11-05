// Header file automatically created from a PDB.
#pragma once

struct ArkAttentionLevelChange;

// ArkAttentionLevelsChangedListener
// Header:  _unknown/ArkAttentionLevelsChangedListener.h
class ArkAttentionLevelsChangedListener
{ // Size=8 (0x8)
public:
	void OnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange) { FOnAttentionLevelsChanged(this, _pFirstChange, _pLastChange); }
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange) = 0;

#ifndef MOONCRASH
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkAttentionLevelsChangedListener* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x13B26F0);
#else
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkAttentionLevelsChangedListener* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x14BE950);
#endif
};

