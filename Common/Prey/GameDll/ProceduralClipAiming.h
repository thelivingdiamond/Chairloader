// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralContextualClip.h>

struct SNoProceduralParams;

// CProceduralClipAiming
// Header:  Prey/GameDll/ProceduralClipAiming.h
class CProceduralClipAiming : public TProceduralContextualClip<CProceduralContextAim,SNoProceduralParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float blendTime, float duration, const SNoProceduralParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipAiming* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x18F2640);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipAiming* const _this, float blendTime)>(0x18F2670);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipAiming* const _this, float timePassed)>(0x18F26A0);
};
#endif // MOONCRASH
