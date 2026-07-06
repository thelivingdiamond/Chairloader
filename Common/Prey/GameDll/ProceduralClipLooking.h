// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralContextualClip.h>

struct SNoProceduralParams;

// CProceduralClipLooking
// Header:  Prey/GameDll/ProceduralClipLooking.h
class CProceduralClipLooking : public TProceduralContextualClip<CProceduralContextLook,SNoProceduralParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float blendTime, float duration, const SNoProceduralParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x18F3E60);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime)>(0x18F3E90);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipLooking* const _this, float timePassed)>(0x18F3EC0);
};
#endif // MOONCRASH
