// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SNoProceduralParams;

// CPlayerJump
// Header:  Prey/GameDll/movementaction.h
class CPlayerJump : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	virtual const char* GetName() const;
	virtual void DoDelete();

#if 0
	CPlayerJump(int _arg0_, int _arg1_);
	void TriggerExit();
#endif

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CPlayerJump* const _this)>(0x17BC610);
	static inline auto FDoDelete = PreyFunction<void(CPlayerJump* const _this)>(0xA97D40);
#else
	static inline auto FGetName = PreyFunction<const char* (const CPlayerJump* const _this)>(0x18E36E0);
	static inline auto FDoDelete = PreyFunction<void(CPlayerJump* const _this)>(0x3E3960);
#endif
};

// CProceduralClipSwapHand
// Header:  Prey/GameDll/movementaction.h
class CProceduralClipSwapHand : public TProceduralClip<SNoProceduralParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float blendTime, float duration, const SNoProceduralParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipSwapHand* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x176EC90);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipSwapHand* const _this, float blendTime)>(0x176ED90);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipSwapHand* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipSwapHand* const _this, float blendTime, float duration, const SNoProceduralParams& params)>(0x18957B0);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipSwapHand* const _this, float blendTime)>(0x18958B0);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipSwapHand* const _this, float timePassed)>(0x1333E90);
#endif
};

