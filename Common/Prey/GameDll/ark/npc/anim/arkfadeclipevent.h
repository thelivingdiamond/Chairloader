// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>
#include <_unknown/TProceduralClip.h>

struct SArkFadeClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkFadeProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arkfadeclipevent.h
class CArkFadeProceduralClipEvent : public TProceduralClip<SArkFadeClipEventParams>
{ // Size=72 (0x48)
public:
	float m_fadeTimer;

	virtual void OnEnter(float blendTime, float duration, const SArkFadeClipEventParams& _params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CArkFadeProceduralClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkFadeProceduralClipEvent* const _this, float blendTime, float duration, const SArkFadeClipEventParams& _params)>(0x126D600);
	static inline auto FOnExit = PreyFunction<void(CArkFadeProceduralClipEvent* const _this, float blendTime)>(0x126D640);
	static inline auto FUpdate = PreyFunction<void(CArkFadeProceduralClipEvent* const _this, float timePassed)>(0x126D670);
};

// SArkFadeClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arkfadeclipevent.h
struct SArkFadeClipEventParams : public IProceduralParams
{ // Size=24 (0x18)
	int m_fadeSlot;
	float m_fadeDuration;
	bool m_bFadeOut;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkFadeClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkFadeClipEventParams* const _this, Serialization::IArchive& ar)>(0x126D8C0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkFadeClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
