// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>

struct CArkPsiPowerSmokeFormClipEventParams;
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
struct CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams;
#endif
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkPsiPowerSmokeFormClipEventParams
// Header:  _unknown/CArkPsiPowerSmokeFormClipEventParams.h
struct CArkPsiPowerSmokeFormClipEventParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);

#if 0
	CArkPsiPowerSmokeFormClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeFormClipEventParams* const _this, Serialization::IArchive& ar)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeFormClipEventParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormEnterClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=8019537 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeFormEnterClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADBD0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B230);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _timePassed)>(0x1333E90);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormExitClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=8019539 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeFormExitClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADC20);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B280);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _timePassed)>(0x1333E90);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
struct CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams : public IProceduralParams // Id=801953A Size=16
{
	CCryName m_effectName;
	
	virtual void Serialize(Serialization::IArchive &_ar);
	virtual ~CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams();
	
#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams *const _this, Serialization::IArchive &_ar)>(0x11ADC70);
#else
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams* const _this, Serialization::IArchive& _ar)>(0x122B2D0);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStartActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams> // Id=801953B Size=56
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeStartActiveParticleEffectClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams const &_params)>(0x11ADCB0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams& _params)>(0x122B390);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStopActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=801953D Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeStopActiveParticleEffectClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADD50);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B3F0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
#endif
};
