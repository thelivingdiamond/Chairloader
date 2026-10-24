// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SArkNpcPsiAttackClipEventParams;
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SArkNpcPsiAttackClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcpsiattackclipevent.h
struct SArkNpcPsiAttackClipEventParams : public IProceduralParams
{ // Size=16 (0x10)
	string archetype_projectile;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcPsiAttackClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SArkNpcPsiAttackClipEventParams* const _this, Serialization::IArchive& ar)>(0x11ED620);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcPsiAttackClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(SArkNpcPsiAttackClipEventParams* const _this, Serialization::IArchive& ar)>(0x1279570);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcPsiAttackClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

// CArkNpcPsiAttackProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcpsiattackclipevent.h
class CArkNpcPsiAttackProceduralClipEvent : public TProceduralClip<SArkNpcPsiAttackClipEventParams>
{ // Size=56 (0x38)
public:
	static unsigned GetStartCRC() { return FGetStartCRC(); }
	virtual void OnEnter(float blendTime, float duration, const SArkNpcPsiAttackClipEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CArkNpcPsiAttackProceduralClipEvent();
	static unsigned GetStopCRC();
#endif

#ifndef MOONCRASH
	static inline auto FGetStartCRC = PreyFunction<unsigned()>(0x11ED350);
	static inline auto FOnEnter = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcPsiAttackClipEventParams& params)>(0x11ED460);
	static inline auto FOnExit = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float blendTime)>(0x11ED550);
	static inline auto FUpdate = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FGetStartCRC = PreyFunction<unsigned()>(0x12792F0);
	static inline auto FOnEnter = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcPsiAttackClipEventParams& params)>(0x12793B0);
	static inline auto FOnExit = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float blendTime)>(0x12794A0);
	static inline auto FUpdate = PreyFunction<void(CArkNpcPsiAttackProceduralClipEvent* const _this, float timePassed)>(0x1333E90);
#endif
};

