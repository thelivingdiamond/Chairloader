// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralContextLook.h>

struct SNoProceduralParams;

// CProceduralClipLooking
// Header:  Prey/GameDll/ProceduralClipLooking.h
class CProceduralClipLooking : public TProceduralContextualClip<CProceduralContextLook,SNoProceduralParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float blendTime, float duration, const SNoProceduralParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x17CCFF0);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime)>(0x17CD020);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipLooking* const _this, float timePassed)>(0x17CD050);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x18F3E60);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipLooking* const _this, float blendTime)>(0x18F3E90);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipLooking* const _this, float timePassed)>(0x18F3EC0);
#endif
};

