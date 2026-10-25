// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>

struct IAttachment;
struct SArkNpcPushObstaclesClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SArkNpcPushObstaclesClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcpushobstaclesclipevent.h
struct SArkNpcPushObstaclesClipEventParams : public IProceduralParams
{ // Size=40 (0x28)
	string m_attachmentName;
	float m_impulse;
	float m_reattemptImpulseAdd;
	float m_radius;
	float m_reattemptRadiusAdd;
	float m_falloff;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcPushObstaclesClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SArkNpcPushObstaclesClipEventParams* const _this, Serialization::IArchive& ar)>(0x11EDAE0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcPushObstaclesClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(SArkNpcPushObstaclesClipEventParams* const _this, Serialization::IArchive& ar)>(0x1279A30);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcPushObstaclesClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

// CArkNpcPushObstaclesProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcpushobstaclesclipevent.h
class CArkNpcPushObstaclesProceduralClipEvent : public TProceduralClip<SArkNpcPushObstaclesClipEventParams>
{ // Size=96 (0x60)
public:
	_smart_ptr<IAttachment> m_pPushAttachment;
	int m_numReattempts;

	virtual void OnEnter(float blendTime, float duration, const SArkNpcPushObstaclesClipEventParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);

#if 0
	CArkNpcPushObstaclesProceduralClipEvent();
	void PushObstacles();
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcPushObstaclesClipEventParams& params)>(0x11ED9D0);
	static inline auto FUpdate = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float timePassed)>(0x11EDBC0);
	static inline auto FOnExit = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float blendTime)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcPushObstaclesClipEventParams& params)>(0x1279920);
	static inline auto FUpdate = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float timePassed)>(0x1279B10);
	static inline auto FOnExit = PreyFunction<void(CArkNpcPushObstaclesProceduralClipEvent* const _this, float blendTime)>(0x1333E90);
#endif
};

