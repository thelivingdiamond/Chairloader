// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct ArkNpcStartGibDeathProcClipParams;

// ArkNpcStartGibDeathProcClipParams
// Header:  _unknown/ArkNpcStartGibDeathProcClipParams.h
struct ArkNpcStartGibDeathProcClipParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(ArkNpcStartGibDeathProcClipParams* const _this, Serialization::IArchive& ar)>(0xA13080);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const ArkNpcStartGibDeathProcClipParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(ArkNpcStartGibDeathProcClipParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const ArkNpcStartGibDeathProcClipParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

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

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime, float duration, const ArkNpcStartGibDeathProcClipParams& params)>(0x120A8E0);
	static inline auto FOnExit = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime, float duration, const ArkNpcStartGibDeathProcClipParams& params)>(0x1299960);
	static inline auto FOnExit = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(ArkNpcStartFatalityDeathProcClip* const _this, float timePassed)>(0x1333E90);
#endif
};

