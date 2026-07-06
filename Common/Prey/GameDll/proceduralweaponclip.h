// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <CryEngine/cryentitysystem/entityclass.h>
#include <CryEngine/crymovie/animsequence.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/weaponlookoffset.h>
#include <Prey/GameDll/weaponrecoiloffset.h>
#include <Prey/GameDll/ark/weapons/SStaticBumpParams.h>
#include <Prey/GameDll/ark/weapons/SStaticWeaponPoseParams.h>
#include <Prey/GameDll/ark/weapons/SStaticWiggleParams.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ark/weapons/SStaticBumpParams.h>
#include <Prey/GameDll/ark/weapons/SStaticWeaponPoseParams.h>
#include <Prey/GameDll/ark/weapons/SStaticWiggleParams.h>
#include <Prey/GameDll/weaponlookoffset.h>
#include <Prey/GameDll/weaponrecoiloffset.h>
#include <_unknown/TProceduralContextualClip.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// SWeaponProceduralClipParams<SStaticBumpParams>
// Header:  Prey/GameDll/proceduralweaponclip.h
struct SWeaponProceduralClipParams<SStaticBumpParams> : public IProceduralParams
{ // Size=24 (0x18)
	SStaticBumpParams m_offsetParams;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SWeaponProceduralClipParams<SStaticBumpParams>* const _this, Serialization::IArchive& ar)>(0x18FACB0);
};

// CWeaponBumpOffset
// Header:  Prey/GameDll/proceduralweaponclip.h
class CWeaponBumpOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticBumpParams> >
{ // Size=72 (0x48)
public:
	virtual void OnEnter(float blendTime, float duration, const SWeaponProceduralClipParams<SStaticBumpParams>& staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(CWeaponBumpOffset* const _this, float blendTime, float duration, const SWeaponProceduralClipParams<SStaticBumpParams>& staticParams)>(0x18FAD20);
	static inline auto FOnExit = PreyFunction<void(CWeaponBumpOffset* const _this, float blendTime)>(0x18FAE80);
	static inline auto FUpdate = PreyFunction<void(CWeaponBumpOffset* const _this, float timePassed)>(0x1333E90);
};

// SWeaponProceduralClipParams<SStaticWeaponPoseParams>
// Header:  Prey/GameDll/proceduralweaponclip.h
struct SWeaponProceduralClipParams<SStaticWeaponPoseParams> : public IProceduralParams
{ // Size=40 (0x28)
	SStaticWeaponPoseParams m_offsetParams;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SWeaponProceduralClipParams<SStaticWeaponPoseParams>* const _this, Serialization::IArchive& ar)>(0x18FA180);
};

// CWeaponPoseOffset
// Header:  Prey/GameDll/proceduralweaponclip.h
class CWeaponPoseOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponPoseParams> >
{ // Size=96 (0x60)
public:
	int m_offsetId;
	SStaticWeaponPoseParams::EPoseType m_poseType;

	virtual void OnEnter(float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponPoseParams>& staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CWeaponPoseOffset();
#endif

	static inline auto FOnEnter = PreyFunction<void(CWeaponPoseOffset* const _this, float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponPoseParams>& staticParams)>(0x18FA210);
	static inline auto FOnExit = PreyFunction<void(CWeaponPoseOffset* const _this, float blendTime)>(0x18FA3D0);
	static inline auto FUpdate = PreyFunction<void(CWeaponPoseOffset* const _this, float timePassed)>(0x18FA410);
};

// SWeaponProceduralClipParams<SStaticWeaponRecoilParams>
// Header:  Prey/GameDll/proceduralweaponclip.h
struct SWeaponProceduralClipParams<SStaticWeaponRecoilParams> : public IProceduralParams
{ // Size=32 (0x20)
	SStaticWeaponRecoilParams m_offsetParams;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SWeaponProceduralClipParams<SStaticWeaponRecoilParams>* const _this, Serialization::IArchive& ar)>(0x18FAAA0);
};

// CWeaponRecoilOffset
// Header:  Prey/GameDll/proceduralweaponclip.h
class CWeaponRecoilOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponRecoilParams> >
{ // Size=80 (0x50)
public:
	virtual void OnEnter(float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponRecoilParams>& staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(CWeaponRecoilOffset* const _this, float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponRecoilParams>& staticParams)>(0x18FAAC0);
	static inline auto FOnExit = PreyFunction<void(CWeaponRecoilOffset* const _this, float blendTime)>(0x18FAB10);
	static inline auto FUpdate = PreyFunction<void(CWeaponRecoilOffset* const _this, float timePassed)>(0x18FAB20);
};

// SWeaponProceduralClipParams<SStaticWeaponSwayParams>
// Header:  Prey/GameDll/proceduralweaponclip.h
struct SWeaponProceduralClipParams<SStaticWeaponSwayParams> : public IProceduralParams
{ // Size=120 (0x78)
	SStaticWeaponSwayParams m_offsetParams;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SWeaponProceduralClipParams<SStaticWeaponSwayParams>* const _this, Serialization::IArchive& ar)>(0x18FA660);
};

// CWeaponSwayOffset
// Header:  Prey/GameDll/proceduralweaponclip.h
class CWeaponSwayOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWeaponSwayParams> >
{ // Size=280 (0x118)
public:
	SStaticWeaponSwayParams m_lastSwayParams;

	virtual void OnEnter(float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponSwayParams>& staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(CWeaponSwayOffset* const _this, float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWeaponSwayParams>& staticParams)>(0x18FA6A0);
	static inline auto FOnExit = PreyFunction<void(CWeaponSwayOffset* const _this, float blendTime)>(0x18FA860);
	static inline auto FUpdate = PreyFunction<void(CWeaponSwayOffset* const _this, float timePassed)>(0x18FA8C0);
};

// SWeaponProceduralClipParams<SStaticWiggleParams>
// Header:  Prey/GameDll/proceduralweaponclip.h
struct SWeaponProceduralClipParams<SStaticWiggleParams> : public IProceduralParams
{ // Size=16 (0x10)
	SStaticWiggleParams m_offsetParams;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SWeaponProceduralClipParams<SStaticWiggleParams>* const _this, Serialization::IArchive& ar)>(0x18FAF50);
};

// CWeaponWiggleOffset
// Header:  Prey/GameDll/proceduralweaponclip.h
class CWeaponWiggleOffset : public TProceduralContextualClip<CProceduralWeaponAnimationContext,SWeaponProceduralClipParams<SStaticWiggleParams> >
{ // Size=80 (0x50)
public:
	float m_blendTime;
	float m_timePassed;
	bool m_blendingIn;

	virtual void OnEnter(float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWiggleParams>& staticParams);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CWeaponWiggleOffset();
	float BlendIntensity() const;
#endif

	static inline auto FOnEnter = PreyFunction<void(CWeaponWiggleOffset* const _this, float blendTime, float duration, const SWeaponProceduralClipParams<SStaticWiggleParams>& staticParams)>(0x18FAFB0);
	static inline auto FOnExit = PreyFunction<void(CWeaponWiggleOffset* const _this, float blendTime)>(0x18FAFF0);
	static inline auto FUpdate = PreyFunction<void(CWeaponWiggleOffset* const _this, float timePassed)>(0x18FB030);
};
#endif // !MOONCRASH
