// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>
#include <_unknown/TProceduralClip.h>

struct IAttachment;
struct SArkNpcBreakGlassClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkNpcBreakGlassProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcbreakglassclipevent.h
class CArkNpcBreakGlassProceduralClipEvent : public TProceduralClip<SArkNpcBreakGlassClipEventParams>
{ // Size=80 (0x50)
public:
	unsigned m_glassBreakerEntityId;
	_smart_ptr<IAttachment> m_pDamageAttachment;

	virtual void OnEnter(float blendTime, float duration, const SArkNpcBreakGlassClipEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	void StartGlassBreaking(const SArkNpcBreakGlassClipEventParams& params) { FStartGlassBreaking(this, params); }

#if 0
	CArkNpcBreakGlassProceduralClipEvent();
	void StopGlassBreaking();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkNpcBreakGlassProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcBreakGlassClipEventParams& params)>(0x1271870);
	static inline auto FOnExit = PreyFunction<void(CArkNpcBreakGlassProceduralClipEvent* const _this, float blendTime)>(0x1271920);
	static inline auto FUpdate = PreyFunction<void(CArkNpcBreakGlassProceduralClipEvent* const _this, float timePassed)>(0x1333E90);
	static inline auto FStartGlassBreaking = PreyFunction<void(CArkNpcBreakGlassProceduralClipEvent* const _this, const SArkNpcBreakGlassClipEventParams& params)>(0x12719E0);
};

// SArkNpcBreakGlassClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcbreakglassclipevent.h
struct SArkNpcBreakGlassClipEventParams : public IProceduralParams
{ // Size=24 (0x18)
	string m_attachmentName;
	float m_hitCheckRadius;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcBreakGlassClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkNpcBreakGlassClipEventParams* const _this, Serialization::IArchive& ar)>(0x1271970);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcBreakGlassClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
