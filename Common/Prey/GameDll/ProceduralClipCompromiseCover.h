// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>

class CAIAnimationComponent;
class CPlayer;
enum class EStance;
struct SNoProceduralParams;

// CProceduralClipCompromiseCover
// Header:  Prey/GameDll/ProceduralClipCompromiseCover.h
class CProceduralClipCompromiseCover : public TProceduralClip<SNoProceduralParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float blendTime, float duration, const SNoProceduralParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);

#if 0
	void DoExplicitStanceChange(CPlayer& _arg0_, CAIAnimationComponent& _arg1_, EStance _arg2_);
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x17CC180);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float timePassed)>(0xA13080);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float blendTime)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x18F3040);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float timePassed)>(0x1333E90);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipCompromiseCover* const _this, float blendTime)>(0x1333E90);
#endif
};

