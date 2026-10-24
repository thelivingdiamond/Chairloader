// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SArkNpcMeleeFacingClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SArkNpcMeleeFacingClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/ArkNpcMeleeFacingClipEvent.h
struct SArkNpcMeleeFacingClipEventParams : public IProceduralParams
{ // Size=24 (0x18)
	EArkNpcSpeedType m_speed;
	float m_overrideDegreesPerSecond;
	float m_relativeDesiredDegrees;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcMeleeFacingClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SArkNpcMeleeFacingClipEventParams* const _this, Serialization::IArchive& ar)>(0x11EC430);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcMeleeFacingClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(SArkNpcMeleeFacingClipEventParams* const _this, Serialization::IArchive& ar)>(0x12784C0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcMeleeFacingClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

// CArkNpcMeleeFacingClipEvent
// Header:  Prey/GameDll/ark/npc/anim/ArkNpcMeleeFacingClipEvent.h
class CArkNpcMeleeFacingClipEvent : public TProceduralClip<SArkNpcMeleeFacingClipEventParams>
{ // Size=328 (0x148)
public:
	ArkNpcSpeedDesire m_speedDesire;
	ArkNpcFacingDesire m_facingDesire;
	float m_relativeDesiredDegrees;

	virtual void OnEnter(float blendTime, float duration, const SArkNpcMeleeFacingClipEventParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);
	Vec3 CalculateRelativeDesiredTargetLoc() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FCalculateRelativeDesiredTargetLoc(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	CArkNpcMeleeFacingClipEvent();
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float blendTime, float duration, const SArkNpcMeleeFacingClipEventParams& params)>(0x11EC0C0);
	static inline auto FUpdate = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float timePassed)>(0x11EC4B0);
	static inline auto FOnExit = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float blendTime)>(0x11EC350);
	static inline auto FCalculateRelativeDesiredTargetLoc = PreyFunction<Vec3*(const CArkNpcMeleeFacingClipEvent* const _this, Vec3* _return_value_)>(0x11EBE60);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float blendTime, float duration, const SArkNpcMeleeFacingClipEventParams& params)>(0x1278110);
	static inline auto FUpdate = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float timePassed)>(0x1278540);
	static inline auto FOnExit = PreyFunction<void(CArkNpcMeleeFacingClipEvent* const _this, float blendTime)>(0x12783E0);
	static inline auto FCalculateRelativeDesiredTargetLoc = PreyFunction<Vec3*(const CArkNpcMeleeFacingClipEvent* const _this, Vec3* _return_value_)>(0x1277E40);
#endif
};

