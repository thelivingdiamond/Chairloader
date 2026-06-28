// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralClip.h>

struct ArkNpcStartGibDeathProcClipParams;

// ArkNpcStartFatalityDeathProcClip
// Header:  Prey/GameDll/ark/npc/ArkNpcStartFatalityDeathProcClip.h
class ArkNpcStartFatalityDeathProcClip : public TProceduralClip<ArkNpcStartGibDeathProcClipParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float blendTime, float duration, const ArkNpcStartGibDeathProcClipParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	ArkNpcStartFatalityDeathProcClip();
#endif

	static inline auto FOnEnter = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime, float duration, const ArkNpcStartGibDeathProcClipParams& params)>(0x1299960);
	static inline auto FOnExit = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float timePassed)>(0x1333E90);
};
#endif // MOONCRASH
