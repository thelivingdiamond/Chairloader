// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>
#include <_unknown/TProceduralClip.h>

struct SArkRagdollClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkRagdollProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arkragdollclipevent.h
class CArkRagdollProceduralClipEvent : public TProceduralClip<SArkRagdollClipEventParams>
{ // Size=80 (0x50)
public:
	float m_randomTriggerTime;
	float m_totalTimePassed;
	bool m_bRagdollKickedOff;

	virtual void OnEnter(float _blendTime, float duration, const SArkRagdollClipEventParams& _params);
	virtual void OnExit(float blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkRagdollProceduralClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkRagdollProceduralClipEvent* const _this, float _blendTime, float duration, const SArkRagdollClipEventParams& _params)>(0x127AA20);
	static inline auto FOnExit = PreyFunction<void(CArkRagdollProceduralClipEvent* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkRagdollProceduralClipEvent* const _this, float _timePassed)>(0x127AA60);
};

// SArkRagdollClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arkragdollclipevent.h
struct SArkRagdollClipEventParams : public IProceduralParams
{ // Size=24 (0x18)
	float m_minTimeInRagdoll;
	float m_maxTimeInRagdoll;
	bool m_bStopCurrentFragment;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkRagdollClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkRagdollClipEventParams* const _this, Serialization::IArchive& ar)>(0x127ACE0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkRagdollClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
