// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <CryEngine/cryentitysystem/entityclass.h>
#include <CryEngine/crymovie/animsequence.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/weaponlookoffset.h>
#include <Prey/GameDll/weaponrecoiloffset.h>
#include <_unknown/SStaticBumpParams.h>
#include <_unknown/SStaticWeaponPoseParams.h>
#include <_unknown/SStaticWiggleParams.h>
#include <_unknown/TProceduralContextualClip_CProceduralWeaponAnimationContext,SWeaponProceduralClipParams_SStaticBumpParams_ _.h>
#include <_unknown/TProceduralContextualClip_CProceduralWeaponAnimationContext,SWeaponProceduralClipParams_SStaticWiggleParams_ _.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
template <typename T>
struct SWeaponProceduralClipParams : public IProceduralParams // Id=801D530 Size=40
{
	T m_offsetParams;

#if 0
	virtual void Serialize(Serialization::IArchive& ar);
#endif
};

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
class CWeaponPoseOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponPoseParams> > // Id=801D52D Size=96
{
public:
	int m_offsetId;
	SStaticWeaponPoseParams::EPoseType m_poseType;
	
	virtual void OnEnter(float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponPoseParams> const &staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
	static inline auto FOnEnter = PreyFunction<void(CWeaponPoseOffset *const _this, float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponPoseParams> const &staticParams)>(0x17D3B10);
	static inline auto FOnExit = PreyFunction<void(CWeaponPoseOffset *const _this, float blendTime)>(0x17D3CD0);
	static inline auto FUpdate = PreyFunction<void(CWeaponPoseOffset *const _this, float timePassed)>(0x17D3D10);
};

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
class CWeaponSwayOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponSwayParams> > // Id=801D531 Size=280
{
public:
	SStaticWeaponSwayParams m_lastSwayParams;
	
	virtual void OnEnter(float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponSwayParams> const &staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
	static inline auto FOnEnter = PreyFunction<void(CWeaponSwayOffset *const _this, float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponSwayParams> const &staticParams)>(0x17D3FA0);
	static inline auto FOnExit = PreyFunction<void(CWeaponSwayOffset *const _this, float blendTime)>(0x17D4160);
	static inline auto FUpdate = PreyFunction<void(CWeaponSwayOffset *const _this, float timePassed)>(0x17D41C0);
};

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
class CWeaponRecoilOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponRecoilParams> > // Id=801D535 Size=80
{
public:
	virtual void OnEnter(float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponRecoilParams> const &staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
	static inline auto FOnEnter = PreyFunction<void(CWeaponRecoilOffset *const _this, float blendTime, float duration, SWeaponProceduralClipParams<SStaticWeaponRecoilParams> const &staticParams)>(0x17D3410);
	static inline auto FOnExit = PreyFunction<void(CWeaponRecoilOffset *const _this, float blendTime)>(0x17D3460);
	static inline auto FUpdate = PreyFunction<void(CWeaponRecoilOffset *const _this, float timePassed)>(0x17D3470);
};

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
class CWeaponBumpOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticBumpParams> > // Id=801D53A Size=72
{
public:
	virtual void OnEnter(float blendTime, float duration, SWeaponProceduralClipParams<SStaticBumpParams> const &staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
	static inline auto FOnEnter = PreyFunction<void(CWeaponBumpOffset *const _this, float blendTime, float duration, SWeaponProceduralClipParams<SStaticBumpParams> const &staticParams)>(0x17D36E0);
	static inline auto FOnExit = PreyFunction<void(CWeaponBumpOffset *const _this, float blendTime)>(0x17D3840);
	static inline auto FUpdate = PreyFunction<void(CWeaponBumpOffset *const _this, float timePassed)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/proceduralweaponclip.h
class CWeaponWiggleOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWiggleParams> > // Id=801D53F Size=80
{
public:
	float m_blendTime;
	float m_timePassed;
	bool m_blendingIn;
	
	virtual void OnEnter(float blendTime, float duration, SWeaponProceduralClipParams<SStaticWiggleParams> const &staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
#if 0
	float BlendIntensity() const;
#endif
	
	static inline auto FOnEnter = PreyFunction<void(CWeaponWiggleOffset *const _this, float blendTime, float duration, SWeaponProceduralClipParams<SStaticWiggleParams> const &staticParams)>(0x17D3940);
	static inline auto FOnExit = PreyFunction<void(CWeaponWiggleOffset *const _this, float blendTime)>(0x17D3980);
	static inline auto FUpdate = PreyFunction<void(CWeaponWiggleOffset *const _this, float timePassed)>(0x17D39C0);
};

