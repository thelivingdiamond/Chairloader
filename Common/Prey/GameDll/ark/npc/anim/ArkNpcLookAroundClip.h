// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <_unknown/IProceduralParams.h>

struct SArkNpcLookAroundParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkNpcLookAroundClip
// Header:  Prey/GameDll/ark/npc/anim/ArkNpcLookAroundClip.h
class CArkNpcLookAroundClip : public TProceduralClip<SArkNpcLookAroundParams>
{ // Size=464 (0x1D0)
public:
	float m_timer;
	int m_numLooks;
	float m_yaw;
	float m_pitch;
	bool m_bPickedRight;
	Vec3 m_avgDir;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcLookDesire::LookPoseParam m_resetBlendInTime;
	ArkNpcLookDesire::LookPoseParam m_resetSmoothTime;
	ArkNpcLookDesire::LookPoseParam m_resetBlendOutTime;
	ArkNpcLookDesire::LookPoseParam m_resetMaxYaw;
	ArkNpcLookDesire::LookPoseParam m_resetMaxPitch;

	virtual void OnEnter(float blendTime, float duration, const SArkNpcLookAroundParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	void UpdateLookTarget(bool _bReset) { FUpdateLookTarget(this, _bReset); }

#if 0
	CArkNpcLookAroundClip();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkNpcLookAroundClip* const _this, float blendTime, float duration, const SArkNpcLookAroundParams& params)>(0x1273190);
	static inline auto FOnExit = PreyFunction<void(CArkNpcLookAroundClip* const _this, float blendTime)>(0x12732E0);
	static inline auto FUpdate = PreyFunction<void(CArkNpcLookAroundClip* const _this, float timePassed)>(0x1273430);
	static inline auto FUpdateLookTarget = PreyFunction<void(CArkNpcLookAroundClip* const _this, bool _bReset)>(0x1274280);
};

// SArkNpcLookAroundParams
// Header:  Prey/GameDll/ark/npc/anim/ArkNpcLookAroundClip.h
struct SArkNpcLookAroundParams : public IProceduralParams
{ // Size=88 (0x58)
	float smoothTimeTorsoMin;
	float smoothTimeTorsoMax;
	float smoothTimeHeadMin;
	float smoothTimeHeadMax;
	float yawMinDegrees;
	float yawMaxDegrees;
	float torsoYawMaxDegrees;
	float pitchMinDegrees;
	float pitchMaxDegrees;
	float torsoPitchMaxDegrees;
	float holdTimeMin;
	float holdTimeMax;
	int numTurnsMin;
	int numTurnsMax;
	float timeBetweenLooksMin;
	float timeBetweenLooksMax;
	CCryName debugDisplayName;
	EArkNpcLookDesirePriority priority;

	SArkNpcLookAroundParams();
	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

	static inline auto FSArkNpcLookAroundParamsOv2 = PreyFunction<void(SArkNpcLookAroundParams* const _this)>(0x1274100);
	static inline auto FSerialize = PreyFunction<void(SArkNpcLookAroundParams* const _this, Serialization::IArchive& ar)>(0x12734F0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcLookAroundParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
